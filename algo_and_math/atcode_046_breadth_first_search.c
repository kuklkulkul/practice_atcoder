#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_R (50)
#define MAX_C (50)
#define WALL ('#')
#define ROAD ('.')
#define QUE_SIZE (MAX_R * MAX_C)

enum {NO_CHK, CHKD};
enum {FAIL_ENQUE = -1, SUCS_ENQUE, FAIL_DEQUE, SUCS_DEQUE};
enum {UP, DOWN, RIGHT, LEFT};

typedef struct point_coordinate_data{
    uint16_t r_;
    uint16_t c_;
}point_c;

typedef struct point_data{
    int diff;
    char area;
}point_d;

typedef struct queue_data{
    uint16_t start;         /*0 ~ (QUE_SIZE - 1)*/
    uint16_t num_of_data;   /*0 ~ QUE_SIZE*/
    point_c point[QUE_SIZE];
}queue;

int enqueue(queue *que, point_c add_data);
int dequeue(queue *que, point_c *ret_data);

queue chk_point;
point_d map_data[(MAX_R + 1)][(MAX_C + 1)];

int main(void)
{
    unsigned int i, j;
    char tmp_chr;
    uint16_t inpt_R, inpt_C;
    uint16_t tmp_r, tmp_c;
    point_c strt_pnt, goal_pnt, tmp_pnt;

    /* get input */
    (void)scanf("%hu%hu\n", &inpt_R, &inpt_C);
    (void)scanf("%hu%hu\n", &tmp_r, &tmp_c);
    strt_pnt.r_ = tmp_r;
    strt_pnt.c_ = tmp_c;
    (void)scanf("%hu%hu\n", &tmp_r, &tmp_c);
    goal_pnt.r_ = tmp_r;
    goal_pnt.c_ = tmp_c;

    for (i = 1U; i <= inpt_R; i++)
    {
        for (j = 1U; j <= inpt_C; j++)
        {
            (void)scanf("%c", &tmp_chr);
            map_data[i][j].area = tmp_chr;
            map_data[i][j].diff = -1;
        }
        (void)scanf("\n");
    }

    map_data[strt_pnt.r_][strt_pnt.c_].diff = 0;
    tmp_pnt.r_ = strt_pnt.r_;
    tmp_pnt.c_ = strt_pnt.c_;

    while ((tmp_pnt.r_ != goal_pnt.r_)||(tmp_pnt.c_ != goal_pnt.c_))
    {
        chk_around(UP, tmp_pnt.r_, tmp_pnt.c_, inpt_R, inpt_C);
        chk_around(DOWN, tmp_pnt.r_, tmp_pnt.c_, inpt_R, inpt_C);
        chk_around(RIGHT, tmp_pnt.r_, tmp_pnt.c_, inpt_R, inpt_C);
        chk_around(LEFT, tmp_pnt.r_, tmp_pnt.c_, inpt_R, inpt_C);
    
        if(FAIL_ENQUE == dequeue(&chk_point, &tmp_pnt)){return 1;}       
    }

    printf("%d\n", map_data[goal_pnt.r_][goal_pnt.c_].diff);

    return 0;
}

void chk_around(int chk, uint16_t now_r, uint16_t now_c, uint16_t max_r, uint16_t max_c)
{
    point_c tmp_pc;
    switch (chk)
    {
    case UP:
        if ((now_r > 1U)&&(map_data[(now_r - 1U)][now_c].area == ROAD)&&(map_data[(now_r - 1U)][now_c].diff == -1))
        {
            tmp_pc.r_ = (now_r - 1U);
            tmp_pc.c_ = now_c;
            map_data[(now_r - 1U)][now_c].diff = map_data[now_r][now_c].diff + 1;
            enqueue(&chk_point, tmp_pc);
        }
        else{/*nothing*/}
        break;
    case DOWN:
        if ((now_r < max_r)&&(map_data[(now_r + 1U)][now_c].area == ROAD)&&(map_data[(now_r + 1U)][now_c].diff == -1))
        {
            tmp_pc.r_ = (now_r + 1U);
            tmp_pc.c_ = now_c;
            map_data[(now_r + 1U)][now_c].diff = map_data[now_r][now_c].diff + 1;
            enqueue(&chk_point, tmp_pc);
        }
        else{/*nothing*/}
        break;
    case RIGHT:
        if ((now_c < max_c)&&(map_data[now_r][(now_c + 1U)].area == ROAD)&&(map_data[now_r][(now_c + 1U)].diff == -1))
        {
            tmp_pc.r_ = now_r;
            tmp_pc.c_ = (now_c + 1U);
            map_data[now_r][(now_c + 1U)].diff = map_data[now_r][now_c].diff + 1;
            enqueue(&chk_point, tmp_pc);
        }
        else{/*nothing*/}
        break;
    case LEFT:
        if ((now_c > 1U)&&(map_data[now_r][(now_c - 1U)].area == ROAD)&&(map_data[now_r][(now_c - 1U)].diff == -1))
        {
            tmp_pc.r_ = now_r;
            tmp_pc.c_ = (now_c - 1U);
            map_data[now_r][(now_c - 1U)].diff = map_data[now_r][now_c].diff + 1;
            enqueue(&chk_point, tmp_pc);
        }
        else{/*nothing*/}
        break;
    default:
        /*nothing*/
        break;
    }

    return;
}

int enqueue(queue *que, point_c add_data)
{
    unsigned int add_data_pstn;

    if (que->num_of_data >= QUE_SIZE)
    {
        return FAIL_ENQUE;
    }
    else{/*nothing*/}

    add_data_pstn = (que->start + que->num_of_data) % QUE_SIZE;
    que->point[add_data_pstn].r_ = add_data.r_;
    que->point[add_data_pstn].c_ = add_data.c_;

    que->num_of_data++;

    return ;
}

int dequeue(queue *que, point_c *ret_data)
{
    unsigned int strt_pstn = que->start;

    if (que->num_of_data == 0U)
    {
        return FAIL_DEQUE;
    }
    else{/*nothing*/}

    ret_data->r_ = que->point[strt_pstn].r_;
    ret_data->c_ = que->point[strt_pstn].c_;
    strt_pstn++;
    strt_pstn %= QUE_SIZE;
    que->start = strt_pstn;
    que->num_of_data--;

    return SUCS_DEQUE;
}

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_N (100000)
#define QUE_SIZE (MAX_N)
#define DE_QUE_FAIL ((uint32_t)(-1))

enum {NO_CHK, CHKD};
enum {FAIL_ENQUE = -1, SUCS_ENQUE};

typedef struct cnctd_point_stack{
    uint32_t cnctd_pint;
    struct cnctd_point_stack *p_next_data;
}point_stack;

typedef struct graph_cnctd_data{
    uint32_t num_of_cnctd_pnt;
    int chckd;
    int diff_frm_i;
    struct cnctd_point_stack *p_cncted_data;
}graph_cnctd;

typedef struct queue_data{
    uint32_t start;         /*0 ~ (QUE_SIZE - 1)*/
    uint32_t num_of_data;   /*0 ~ QUE_SIZE*/
    uint32_t data[QUE_SIZE];
}queue;

void cal_maxdif_frm_i(int strt, graph_cnctd *trr_arr, int *ret_diff, uint32_t *ret_point);
int push_stack(graph_cnctd *pnt, uint32_t push_data);
int enqueue(queue *que, uint32_t add_data);
uint32_t dequeue(queue *que);

queue que_chk;

int main(void)
{
    uint32_t i, j, k;
    uint32_t inpt_N;
    uint32_t inpt_A, inpt_B;
    const size_t size_of_graph_cnctd = sizeof(graph_cnctd);
    graph_cnctd *inpt_arr;

    int diff_1, diff_i;
    uint32_t point_i;
    
    /* get input */
    (void)scanf("%u\n", &inpt_N);

    inpt_arr = (graph_cnctd*)malloc((size_of_graph_cnctd * (inpt_N + 1U)));
    if (NULL == inpt_arr){return 1;}

    /* 確保した配列初期化 */
    for (i = 0U; i <= inpt_N; i++)
    {
        inpt_arr[i].chckd = NO_CHK;
        inpt_arr[i].diff_frm_i = -1;
        inpt_arr[i].num_of_cnctd_pnt = 0;
        inpt_arr[i].p_cncted_data = (point_stack *)NULL;
    }

    for (j = 1U; j <= inpt_N; j++)
    {
        (void)scanf("%u%u", &inpt_A, &inpt_B);
        
        if (1 == push_stack(&inpt_arr[inpt_A], inpt_B)){return 1;}
        if (1 == push_stack(&inpt_arr[inpt_B], inpt_A)){return 1;}
    }

    cal_maxdif_frm_i(1, &inpt_arr[0], &diff_1, &point_i);

    for (k = 0U; k <= inpt_N; k++)
    {
        inpt_arr[k].chckd = NO_CHK;
        inpt_arr[k].diff_frm_i = -1;
    }

    cal_maxdif_frm_i(point_i, &inpt_arr[0], &diff_i, &point_i);

    printf("%d\n", (diff_i + 1));

    return 0;
}

void cal_maxdif_frm_i(int strt, graph_cnctd *trr_arr, int *ret_diff, uint32_t *ret_point)    /* 1 <= strt <= inpt_N */
{
    int tmp_diff = -1;
    uint32_t tmp_point;
    uint32_t chk_pnt, next_pnt;
    uint32_t chk_num = 0U;
    point_stack *tmp_p;

    trr_arr[strt].chckd = CHKD;
    trr_arr[strt].diff_frm_i = 0;
    enqueue(&que_chk, strt);
    chk_num = que_chk.num_of_data;

    while (1)
    {
        while (chk_num != 0U)
        {
            chk_pnt = dequeue(&que_chk);

            tmp_p = trr_arr[chk_pnt].p_cncted_data;

            while (tmp_p != NULL)
            {
                if (trr_arr[tmp_p->cnctd_pint].chckd != CHKD)
                {
                    trr_arr[tmp_p->cnctd_pint].chckd = CHKD;
                    trr_arr[tmp_p->cnctd_pint].diff_frm_i = trr_arr[chk_pnt].diff_frm_i + 1U;

                    if (trr_arr[tmp_p->cnctd_pint].diff_frm_i > tmp_diff)
                    {
                        tmp_diff = trr_arr[tmp_p->cnctd_pint].diff_frm_i;
                        tmp_point = tmp_p->cnctd_pint;
                    }
                    else{/*nothing*/}

                    enqueue(&que_chk, tmp_p->cnctd_pint );
                }
                else if (trr_arr[tmp_p->cnctd_pint].diff_frm_i > (trr_arr[chk_pnt].diff_frm_i + 1U))
                {
                    trr_arr[tmp_p->cnctd_pint].diff_frm_i = trr_arr[chk_pnt].diff_frm_i + 1U;

                    if (trr_arr[tmp_p->cnctd_pint].diff_frm_i > tmp_diff)
                    {
                        tmp_diff = trr_arr[tmp_p->cnctd_pint].diff_frm_i;
                        tmp_point = tmp_p->cnctd_pint;
                    }
                    else{/*nothing*/}
                }
                else if ((trr_arr[tmp_p->cnctd_pint].diff_frm_i + 1U) < trr_arr[chk_pnt].diff_frm_i)
                {
                    trr_arr[chk_pnt].diff_frm_i = trr_arr[tmp_p->cnctd_pint].diff_frm_i + 1U;

                    if (trr_arr[chk_pnt].diff_frm_i > tmp_diff)
                    {
                        tmp_diff = trr_arr[chk_pnt].diff_frm_i;
                        tmp_point = chk_pnt;
                    }
                    else{/*nothing*/}
                }
                else{/*nothing*/}
                
                tmp_p = tmp_p->p_next_data;
            }

            chk_num--;
        }

        if (que_chk.num_of_data > 0U)
        {
            chk_num = que_chk.num_of_data;
        }
        else
        {
            break;
        }
        
    }

    *ret_diff = tmp_diff;
    *ret_point = tmp_point;

    return;
}

int push_stack(graph_cnctd *pnt, uint32_t push_data)
{
    point_stack *p_push;
    
    p_push = (point_stack *)malloc(sizeof(point_stack));

    if (p_push == (point_stack *)NULL){return 1;}

    p_push->p_next_data = pnt->p_cncted_data;
    p_push->cnctd_pint = push_data;

    pnt->num_of_cnctd_pnt++;
    pnt->p_cncted_data = p_push;
    
    return 0;
}

int enqueue(queue *que, uint32_t add_data)
{
    uint32_t add_data_pstn;

    if (que->num_of_data >= QUE_SIZE)
    {
        return FAIL_ENQUE;
    }
    else{/*nothing*/}

    add_data_pstn = (que->start + que->num_of_data) % QUE_SIZE;
    que->data[add_data_pstn] = add_data;

    que->num_of_data++;

    return SUCS_ENQUE;
}

uint32_t dequeue(queue *que)
{
    uint32_t ret = DE_QUE_FAIL;
    uint32_t strt_pstn = que->start;

    if (que->num_of_data == 0U)
    {
        return ret;
    }
    else{/*nothing*/}

    ret = que->data[strt_pstn];
    strt_pstn++;
    strt_pstn %= QUE_SIZE;
    que->start = strt_pstn;
    que->num_of_data--;

    return ret;
}

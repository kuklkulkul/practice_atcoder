#include <stdio.h>
#include <stdint.h>
#include <math.h>

enum bool_type {FALSE, TRUE} bool;
enum coord_type {X_, Y_, C_} coord;

typedef struct coordinate_data
{
    unsigned int x_c;
    unsigned int y_c;
    uint64_t dis_o_sq;
}coordinate;


#define MAX_N (2000)

static unsigned int inpt_N;
static coordinate inpt_P[MAX_N];

/* 例外入力への対応は省略 */
int main(void)
{
    unsigned int i;
    unsigned int j;
    unsigned int inpt_buff_x, inpt_buff_y;
    uint64_t tmp_cal;
    uint64_t tmp_min = (uint64_t)-1;
    double ans;

    /* get input */
    (void)scanf("%u", &inpt_N);
    (void)scanf("%u%u", &inpt_buff_x, &inpt_buff_y);
    inpt_P[0].x_c = inpt_buff_x;
    inpt_P[0].y_c = inpt_buff_y;
    inpt_P[0].dis_o_sq = (uint64_t)inpt_buff_x * (uint64_t)inpt_buff_x + (uint64_t)inpt_buff_y * (uint64_t)inpt_buff_y;


    for (i = 1U; i < inpt_N; i++)
    {
        (void)scanf("%u%u", &inpt_buff_x, &inpt_buff_y);
        inpt_P[i].x_c = inpt_buff_x;
        inpt_P[i].y_c = inpt_buff_y;
        inpt_P[i].dis_o_sq = (uint64_t)inpt_buff_x * (uint64_t)inpt_buff_x + (uint64_t)inpt_buff_y * (uint64_t)inpt_buff_y;

        for (j = 0U; j < i; j++)
        {
            tmp_cal = inpt_P[j].dis_o_sq + inpt_P[i].dis_o_sq - 2UL * ((uint64_t)inpt_P[j].x_c * (uint64_t)inpt_buff_x + (uint64_t)inpt_P[j].y_c * (uint64_t)inpt_buff_y);

            if (tmp_cal < tmp_min)
            {
                tmp_min = tmp_cal;
            }
            else{/*nothing*/}
        }
    }

    ans = sqrt((double)tmp_min);

    printf("%.*lf\n", 10, ans);

    return 0;
}


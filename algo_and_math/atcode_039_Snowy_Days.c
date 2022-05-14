#include <stdio.h>
#include <stdint.h>

#define MAX_N (100000)

static int64_t mem_snow_diff_R[(MAX_N + 1)];

/* 例外入力への対応は省略 */
int main(void)
{
    unsigned int i, j, k;
    unsigned int inpt_N, inpt_Q;
    unsigned int inpt_buff_L, inpt_buff_R;
    int inpt_buff_X;

    /* get input */
    (void)scanf("%u%u", &inpt_N, &inpt_Q);

    for (i = 0U; i < inpt_Q; i++)
    {
        (void)scanf("%u%u%d", &inpt_buff_L, &inpt_buff_R, &inpt_buff_X);
        
        mem_snow_diff_R[(inpt_buff_L - 1U)] += (int64_t)inpt_buff_X;
        mem_snow_diff_R[inpt_buff_R] -= (int64_t)inpt_buff_X;
    }

    for (k = 1U; k < inpt_N; k++)
    {
        if (mem_snow_diff_R[k] > 0L)
        {
            printf("<");
        }
        else if (mem_snow_diff_R[k] < 0L)
        {
            printf(">");
        }
        else
        {
            printf("=");
        }
    }

    printf("\n");

    return 0;
}

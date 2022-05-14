#include <stdio.h>
#include <stdint.h>

#define MAX_N (200000)
#define MAX_M (200000)

static uint64_t mem_sum_A[MAX_N];

/* 例外入力への対応は省略 */
int main(void)
{
    unsigned int i, j;
    unsigned int inpt_N, inpt_M;
    unsigned int inpt_buff_B, inpt_buff_B_old;
    uint64_t inpt_A;
    uint64_t ans = 0UL;

    /* get input */
    (void)scanf("%u", &inpt_N);

    for (i = 1U; i < inpt_N; i++)
    {
        (void)scanf("%Lu", &inpt_A);
        mem_sum_A[i] = mem_sum_A[(i - 1U)] + inpt_A;
    }

    (void)scanf("%u", &inpt_M);
    (void)scanf("%u", &inpt_buff_B_old);    /* read B_1 */

    for (j = 1U; j < inpt_M; j++)
    {
        (void)scanf("%u", &inpt_buff_B);

        if (inpt_buff_B > inpt_buff_B_old)
        {
            ans += (mem_sum_A[(inpt_buff_B - 1U)] - mem_sum_A[(inpt_buff_B_old - 1U)]);
        }
        else
        {
            ans += (mem_sum_A[(inpt_buff_B_old - 1U)] - mem_sum_A[(inpt_buff_B - 1U)]);
        }

        inpt_buff_B_old = inpt_buff_B;
        
    }

    printf("%Lu\n", ans);

    return 0;
}

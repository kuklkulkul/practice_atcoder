#include <stdio.h>
#include <stdint.h>

#define MAX_N (100000)

static uint64_t mem_sum[(MAX_N + 1)];
static unsigned int arry_A[(MAX_N + 1)];

/* 例外入力への対応は省略 */
int main(void)
{
    unsigned int i, j;
    unsigned int inpt_N, inpt_Q;
    unsigned int inpt_buff_L, inpt_buff_R;
    uint64_t tmp_ans;

    /* get input */
    (void)scanf("%u%u", &inpt_N, &inpt_Q);

    for (i = 1U; i <= inpt_N; i++)
    {
        (void)scanf("%u", &arry_A[i]);
        mem_sum[i] = mem_sum[(i - 1U)] + (uint64_t)arry_A[i];
    }

    for (j = 0U; j < inpt_Q; j++)
    {
        (void)scanf("%u%u", &inpt_buff_L, &inpt_buff_R);

        tmp_ans = mem_sum[inpt_buff_R] - mem_sum[(inpt_buff_L - 1U)];

        printf("%Lu\n", tmp_ans);
    }

    return 0;
}

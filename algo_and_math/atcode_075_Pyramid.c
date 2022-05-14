#include <stdio.h>
#include <stdint.h>

#define MAX_N   (200000)
#define MAX_A   (1000000000)
#define MOD_NUM (1000000007UL)

uint64_t A_arr[MAX_N];

int main(void)
{
    uint32_t i, j, k;
    uint32_t inpt_N;

    uint64_t *inpt_A = &A_arr[0];

    /* get input */
    (void)scanf("%u\n", &inpt_N);

    for (i = 0U; i < inpt_N; i++)
    {
        (void)scanf("%lu", inpt_A);
        inpt_A++;
    }

    for (j = (inpt_N - 1U); j > 0U; j--)
    {
        for (k = 0U; k < j; k++)
        {
            A_arr[k] += A_arr[(k + 1U)];
            A_arr[k] %= MOD_NUM;
        }
    }

    printf("%u\n", (uint32_t)A_arr[0]);

    return 0;
}

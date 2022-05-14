#include <stdio.h>
#include <stdint.h>

#define MAX_N (10000000)

unsigned int mem_arr[(MAX_N + 1U)];

int main(void)
{
    unsigned int i, j;
    unsigned int inpt_N;
    uint64_t ans = 0UL;

    /* get input */
    (void)scanf("%u", &inpt_N);

    for (i = 1U; i <= inpt_N; i++)
    {
        mem_arr[i] = 1U;
    }

    for (i = 2U; i <= inpt_N; i++)
    {
        for (j = 1U; j * i <= inpt_N; j++)
        {
            mem_arr[(j * i)]++;
        }
    }

    for (i = 1U; i <= inpt_N; i++)
    {
        ans += (uint64_t)i * (uint64_t)mem_arr[i];
    }

    printf("%Lu\n", ans);

    return 0;
}



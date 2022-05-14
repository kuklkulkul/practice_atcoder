#include <stdio.h>
#include <stdint.h>

#define MAX_N (200000U)

static unsigned int A_arr[(MAX_N + 1)];
static unsigned int mem_A_arr[(MAX_N + 1)];

int main(void)
{
    unsigned int i, j, k;
    unsigned int tmp_s = 0U, tmp_e;
    unsigned int inpt_N;
    unsigned int *p_arr = A_arr;
    unsigned int *p_mem_arr = mem_A_arr;
    unsigned int town = 1U;
    uint64_t inpt_K;

    /* get input */
    (void)scanf("%u%lu\n", &inpt_N, &inpt_K);

    for (i = 0U; i < inpt_N; i++)
    {
        p_arr++;
        p_mem_arr++;
        (void)scanf("%u", p_arr);
        *p_mem_arr = (unsigned int)(-1);
    }

    mem_A_arr[town] = 0U;

    for(j = 1U; j <= inpt_N; j++)
    {
        town = A_arr[town];

        if (mem_A_arr[town] == (unsigned int)(-1))
        {
            mem_A_arr[town] = j;
        }
        else
        {
            tmp_e = j;
            tmp_s = mem_A_arr[town];
        }
    }

    if (inpt_N == (1UL << msb))
    {
        y = 1U;
    }
    else
    {
        y = 0U;
    }

    if(ans_arry[x][y] == First)
    {
        printf("First\n");
    }
    else
    {
        printf("Second\n");
    }

    return 0;
}

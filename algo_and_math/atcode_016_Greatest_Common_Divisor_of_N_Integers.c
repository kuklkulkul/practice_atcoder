#include <stdio.h>
#include <stdint.h>

uint64_t Euclidean_Algo(uint64_t inpt_1, uint64_t inpt_2);

int main(void)
{
    uint64_t ans;
    uint64_t inpt_N;
    uint64_t arry[100000];
    uint64_t i;

    /* get input */
    scanf("%Lu", &inpt_N);

    for (i = 0UL; i < inpt_N; i++)
    {
        scanf("%Lu", &arry[i]);
    }

    ans = arry[0];

    for (i = 1UL; i < inpt_N; i++)
    {
        ans = Euclidean_Algo(arry[i], ans);
    }

    printf("%Lu\n", ans);

    return 0;
}

uint64_t Euclidean_Algo(uint64_t inpt_1, uint64_t inpt_2)
{
    uint64_t ret;
    uint64_t num_1 = inpt_1;
    uint64_t num_2 = inpt_2;
    uint64_t tmp_rsd;

    if (num_1 < num_2)
    {
        num_1 += num_2;
        num_2 = num_1 - num_2;
        num_1 -= num_2;
    }
    else
    {
        /* nothing */
    }

    do
    {
        tmp_rsd = num_1 % num_2;
        num_1 = num_2;
        num_2 = tmp_rsd;

    } while (tmp_rsd != 0UL);
    
    ret = num_1;

    return ret;
}

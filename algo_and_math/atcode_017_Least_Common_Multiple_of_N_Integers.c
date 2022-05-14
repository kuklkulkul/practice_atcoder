#include <stdio.h>
#include <stdint.h>

uint64_t Euclidean_Algo_lmted(uint64_t inpt_1, uint64_t inpt_2);
uint64_t Least_Common_Mult(uint64_t inpt_1, uint64_t inpt_2);

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
        ans = Least_Common_Mult(arry[i], ans);
    }

    printf("%Lu\n", ans);

    return 0;
}

uint64_t Least_Common_Mult(uint64_t inpt_1, uint64_t inpt_2)
{
    uint64_t ret;
    uint64_t tmp_max_div;
    uint64_t tmp;
    uint64_t tmp_big;
    uint64_t tmp_sml;

    if (inpt_1 < inpt_2)
    {
        tmp_big = inpt_2;
        tmp_sml = inpt_1;
    }
    else if (inpt_1 > inpt_2)
    {
        tmp_big = inpt_1;
        tmp_sml = inpt_2;
    }
    else
    {
        ret = inpt_1;
        return ret;
    }

    tmp_max_div = Euclidean_Algo_lmted(tmp_big, tmp_sml);

    tmp = tmp_sml / tmp_max_div;

    ret = tmp * tmp_big;

    return ret;
}

/* inpt_1 > inpt_2 前提 */
uint64_t Euclidean_Algo_lmted(uint64_t inpt_1, uint64_t inpt_2)
{
    uint64_t ret;
    uint64_t num_1 = inpt_1;
    uint64_t num_2 = inpt_2;
    uint64_t tmp_rsd;

    do
    {
        tmp_rsd = num_1 % num_2;
        num_1 = num_2;
        num_2 = tmp_rsd;

    } while (tmp_rsd != 0UL);
    
    ret = num_1;

    return ret;
}

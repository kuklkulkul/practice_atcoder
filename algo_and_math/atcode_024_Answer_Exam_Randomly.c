#include <stdio.h>
#include <stdint.h>

#define MAX_VALUE   (50)
#define MIN_P   (2)
#define MAX_P   (9)

uint64_t Euclidean_Algo_lmted(uint64_t inpt_1, uint64_t inpt_2);
uint64_t Least_Common_Mult(uint64_t inpt_1, uint64_t inpt_2);

/* 例外入力への対応は省略 */
int main(void)
{
    uint64_t inpt_N;
    uint64_t l_mult_p = 1UL;
    uint64_t i, j, k;
    unsigned int arry_valu_p[(MAX_P + 1)] = {0};
    uint64_t sum = 0UL;
    double ans;
    uint64_t arry_P[MAX_VALUE] = {0UL};
    uint64_t arry_Q[MAX_VALUE] = {0UL};

    /* get input */
    scanf("%Lu", &inpt_N);

    for (i = 0UL; i < inpt_N; i++)
    {
        scanf("%Lu%Lu", &arry_P[i], &arry_Q[i]);
        arry_valu_p[arry_P[i]] |= 1U;
    }

    for (j = MIN_P; j <= MAX_P; j++)
    {
        if (arry_valu_p[j] != 0U)
        {
            l_mult_p = Least_Common_Mult(j, l_mult_p);
        }
        else
        {
            /* nothing */
        }
    }

    for (k = 0UL; k < inpt_N; k++)
    {
        sum += arry_Q[k] * l_mult_p / arry_P[k];
    }

    ans = (double)sum / (double)l_mult_p;

    printf("%lf\n", ans);

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

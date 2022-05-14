#include <stdio.h>
#include <stdint.h>

#define MAX_INPUT (1000000000000000000UL)
#define MAX_DIGIT (19U)

uint64_t Euclidean_Algo_lmted(uint64_t inpt_1, uint64_t inpt_2);
uint64_t Least_Common_Mult(uint64_t inpt_1, uint64_t inpt_2, uint32_t max_digit);
uint32_t chk_digit(uint64_t num);

int main(void)
{
    uint64_t ans;
    uint64_t inpt_A, inpt_B;
    uint64_t i;

    /* get input */
    scanf("%lu%lu\n", &inpt_A, &inpt_B);

    ans = Least_Common_Mult(inpt_A, inpt_B, MAX_DIGIT);

    printf("%Lu\n", ans);

    return 0;
}

uint64_t Least_Common_Mult(uint64_t inpt_1, uint64_t inpt_2, uint32_t max_digit)
{
    uint64_t ret;
    uint64_t tmp_max_div;
    uint64_t tmp;
    uint64_t tmp_big;
    uint64_t tmp_sml;
    uint32_t tmp_dgt_1, tmp_dgt_2;

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

    tmp_dgt_1 = chk_digit(tmp);
    tmp_dgt_2 = chk_digit(tmp_big);

    if (tmp_dgt_1 + )

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

uint32_t chk_digit(uint64_t num)
{
    uint32_t ret = 0U;
    uint64_t tmp = num;

    do
    {
        tmp /= 10UL;
        ret++;
    } while (tmp != 0UL);
    
    return ret;
}

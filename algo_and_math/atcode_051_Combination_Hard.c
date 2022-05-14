#include <stdio.h>
#include <stdint.h>

#define MOD_NUM (1000000007UL)
static const unsigned int pow_2_arr[31] = {  0x00000001U, 0x00000002U, 0x00000004U, 0x00000008U, 0x00000010U, 0x00000020U, 0x00000040U, 0x00000080U,
                                0x00000100U, 0x00000200U, 0x00000400U, 0x00000800U, 0x00001000U, 0x00002000U, 0x00004000U, 0x00008000U,
                                0x00010000U, 0x00020000U, 0x00040000U, 0x00080000U, 0x00100000U, 0x00200000U, 0x00400000U, 0x00800000U,
                                0x01000000U, 0x02000000U, 0x04000000U, 0x08000000U, 0x10000000U, 0x20000000U, 0x40000000U};

unsigned int mem_pnt_arr[30];
uint64_t mem_clc_arr[30];

unsigned int combination_mod(uint64_t inpt_n, uint64_t inpt_r, uint64_t mod_num);
unsigned int power(unsigned int btm, unsigned int pow);

int main(void)
{
    unsigned int ans;
    unsigned int inpt_X;
    unsigned int inpt_Y;

    /* get input */
    (void)scanf("%u%u\n", &inpt_X, &inpt_Y);

    if (inpt_X >= inpt_Y)
    {
        ans = combination_mod((uint64_t)(inpt_X + inpt_Y), (uint64_t)inpt_Y, MOD_NUM);
    }
    else
    {
        ans = combination_mod((uint64_t)(inpt_X + inpt_Y), (uint64_t)inpt_X, MOD_NUM);
    }

    printf("%u\n", ans);

    return 0;
}

unsigned int combination_mod(uint64_t inpt_n, uint64_t inpt_r, uint64_t mod_num)
{
    unsigned int ret = 0U;
    unsigned int tmp_calc_1;
    uint64_t tmp_n = inpt_n;
    uint64_t tmp_r = inpt_r;
    uint64_t tmp_nmr = 1UL;
    uint64_t tmp_dnm = 1UL;

    while (tmp_r > 0UL)
    {
        tmp_nmr *= tmp_n;
        tmp_dnm *= tmp_r;

        tmp_nmr %= mod_num;
        tmp_dnm %= mod_num;

        tmp_n--;
        tmp_r--;
    }
    
    tmp_calc_1 = power((unsigned int)tmp_dnm, (unsigned int)(MOD_NUM - 2UL));
    tmp_nmr *= tmp_calc_1;
    tmp_nmr %= mod_num;
    ret = (unsigned int)tmp_nmr;

    return ret;
}

unsigned int power(unsigned int btm, unsigned int pow)
{
    int i = 0;
    int j, k;
    unsigned int ret;
    uint64_t tmp = 1UL;

    mem_clc_arr[0] = btm;

    while (pow >= pow_2_arr[i])
    {
        mem_pnt_arr[i] = (unsigned int)(pow & pow_2_arr[i]);
        i++;
    }

    for (j = 1; j < i; j++)
    {
        mem_clc_arr[j] = (mem_clc_arr[(j - 1)] * mem_clc_arr[(j - 1)]) % MOD_NUM;
    }

    for (k = 0; k < i; k++)
    {
        if (mem_pnt_arr[k] != 0U)
        {
            tmp *= mem_clc_arr[k];
            tmp %= MOD_NUM;
        }
        else{/*nothing*/}
    }

    ret = (unsigned int)tmp;

    return ret;
}


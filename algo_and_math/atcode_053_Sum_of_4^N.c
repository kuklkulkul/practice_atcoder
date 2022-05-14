#include <stdio.h>
#include <stdint.h>

#define MOD_NUM (1000000007UL)
#define MAX_N   (0x0DE0B6B3A7640000UL)  /* 10^18 */
#define POW_3_MOD_NUM   (333333336UL)    /* 3^1000000005 (MOD 1000000007) */

static const unsigned int pow_2_arr[31] = {  0x00000001U, 0x00000002U, 0x00000004U, 0x00000008U, 0x00000010U, 0x00000020U, 0x00000040U, 0x00000080U,
                                0x00000100U, 0x00000200U, 0x00000400U, 0x00000800U, 0x00001000U, 0x00002000U, 0x00004000U, 0x00008000U,
                                0x00010000U, 0x00020000U, 0x00040000U, 0x00080000U, 0x00100000U, 0x00200000U, 0x00400000U, 0x00800000U,
                                0x01000000U, 0x02000000U, 0x04000000U, 0x08000000U, 0x10000000U, 0x20000000U, 0x40000000U};

unsigned int mem_pnt_arr[30];
uint64_t mem_clc_arr[30];

unsigned int power(unsigned int btm, unsigned int pow);

int main(void)
{
    unsigned int ans;
    uint64_t tmp;
    uint64_t inpt_N;

    /* get input */
    (void)scanf("%lu\n", &inpt_N);

    inpt_N++;
    inpt_N %= (MOD_NUM - 1UL);

    tmp = (uint64_t)power(4U, (unsigned int)inpt_N);

    if (tmp != 0UL)
    {
        tmp--;
    }
    else
    {
        tmp = MOD_NUM - 1UL;
    }

    tmp *= POW_3_MOD_NUM;

    ans = (unsigned int)(tmp % MOD_NUM);

    printf("%u\n", ans);

    return 0;
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


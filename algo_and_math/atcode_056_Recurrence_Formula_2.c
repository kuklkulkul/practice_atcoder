#include <stdio.h>
#include <stdint.h>

#define MOD_NUM (1000000007UL)
#define MAX_N   (0x0DE0B6B3A7640000UL)  /* 10^18 */

#define BIT01_64    (0x0000000000000001UL)
#define BIT02_64    (0x0000000000000002UL)
#define BIT03_64    (0x0000000000000004UL)
#define BIT04_64    (0x0000000000000008UL)
#define BIT05_64    (0x0000000000000010UL)
#define BIT06_64    (0x0000000000000020UL)
#define BIT07_64    (0x0000000000000040UL)
#define BIT08_64    (0x0000000000000080UL)
#define BIT09_64    (0x0000000000000100UL)
#define BIT10_64    (0x0000000000000200UL)
#define BIT11_64    (0x0000000000000400UL)
#define BIT12_64    (0x0000000000000800UL)
#define BIT13_64    (0x0000000000001000UL)
#define BIT14_64    (0x0000000000002000UL)
#define BIT15_64    (0x0000000000004000UL)
#define BIT16_64    (0x0000000000008000UL)
#define BIT17_64    (0x0000000000010000UL)
#define BIT18_64    (0x0000000000020000UL)
#define BIT19_64    (0x0000000000040000UL)
#define BIT20_64    (0x0000000000080000UL)
#define BIT21_64    (0x0000000000100000UL)
#define BIT22_64    (0x0000000000200000UL)
#define BIT23_64    (0x0000000000400000UL)
#define BIT24_64    (0x0000000000800000UL)
#define BIT25_64    (0x0000000001000000UL)
#define BIT26_64    (0x0000000002000000UL)
#define BIT27_64    (0x0000000004000000UL)
#define BIT28_64    (0x0000000008000000UL)
#define BIT29_64    (0x0000000010000000UL)
#define BIT30_64    (0x0000000020000000UL)
#define BIT31_64    (0x0000000040000000UL)
#define BIT32_64    (0x0000000080000000UL)
#define BIT33_64    (0x0000000100000000UL)
#define BIT34_64    (0x0000000200000000UL)
#define BIT35_64    (0x0000000400000000UL)
#define BIT36_64    (0x0000000800000000UL)
#define BIT37_64    (0x0000001000000000UL)
#define BIT38_64    (0x0000002000000000UL)
#define BIT39_64    (0x0000004000000000UL)
#define BIT40_64    (0x0000008000000000UL)
#define BIT41_64    (0x0000010000000000UL)
#define BIT42_64    (0x0000020000000000UL)
#define BIT43_64    (0x0000040000000000UL)
#define BIT44_64    (0x0000080000000000UL)
#define BIT45_64    (0x0000100000000000UL)
#define BIT46_64    (0x0000200000000000UL)
#define BIT47_64    (0x0000400000000000UL)
#define BIT48_64    (0x0000800000000000UL)
#define BIT49_64    (0x0001000000000000UL)
#define BIT50_64    (0x0002000000000000UL)
#define BIT51_64    (0x0004000000000000UL)
#define BIT52_64    (0x0008000000000000UL)
#define BIT53_64    (0x0010000000000000UL)
#define BIT54_64    (0x0020000000000000UL)
#define BIT55_64    (0x0040000000000000UL)
#define BIT56_64    (0x0080000000000000UL)
#define BIT57_64    (0x0100000000000000UL)
#define BIT58_64    (0x0200000000000000UL)
#define BIT59_64    (0x0400000000000000UL)
#define BIT60_64    (0x0800000000000000UL)
#define BIT61_64    (0x1000000000000000UL)
#define BIT62_64    (0x2000000000000000UL)
#define BIT63_64    (0x4000000000000000UL)
#define BIT64_64    (0x8000000000000000UL)


static const uint64_t pow_2_arr[64] = { BIT01_64, BIT02_64, BIT03_64, BIT04_64, BIT05_64, BIT06_64, BIT07_64, BIT08_64, BIT09_64, BIT10_64, BIT11_64, BIT12_64, BIT13_64, BIT14_64, BIT15_64, BIT16_64,
                                        BIT17_64, BIT18_64, BIT19_64, BIT20_64, BIT21_64, BIT22_64, BIT23_64, BIT24_64, BIT25_64, BIT26_64, BIT27_64, BIT28_64, BIT29_64, BIT30_64, BIT31_64, BIT32_64,
                                        BIT33_64, BIT34_64, BIT35_64, BIT36_64, BIT37_64, BIT38_64, BIT39_64, BIT40_64, BIT41_64, BIT42_64, BIT43_64, BIT44_64, BIT45_64, BIT46_64, BIT47_64, BIT48_64,
                                        BIT49_64, BIT50_64, BIT51_64, BIT52_64, BIT53_64, BIT54_64, BIT55_64, BIT56_64, BIT57_64, BIT58_64, BIT59_64, BIT60_64, BIT61_64, BIT62_64, BIT63_64, BIT64_64
};
static uint64_t rcrrnc_mem_Arr[64][3][3] = {{{1UL, 1UL, 0UL}, {1UL, 0UL, 1UL}, {1UL, 0UL, 0UL}},};

unsigned int rcrrnc_N_mod_10_9_p7 (uint64_t inpt_N);
void clc_rcrrnc_mem_Arr(void);
void pow2_arry3_3 (uint64_t out_arr[][3], uint64_t inpt_arr[][3], uint64_t mod_num);
void innr_prd_arry3_3 (uint64_t out_arr[][3], uint64_t inpt_arr_A[][3], uint64_t inpt_arr_B[][3], uint64_t mod_num);

int main(void)
{
    unsigned int ans;
    uint64_t inpt_N;

    clc_rcrrnc_mem_Arr();

    /* get input */
    (void)scanf("%lu\n", &inpt_N);

    ans = rcrrnc_N_mod_10_9_p7(inpt_N - 2UL);

    printf("%u\n", ans);

    return 0;
}

unsigned int rcrrnc_N_mod_10_9_p7 (uint64_t inpt_N)
{
    int i;
    unsigned int ret;
    uint64_t out_arr[3][3];
    uint64_t tmp_arr[3][3] = {{2UL, 1UL, 1UL}, {0UL, 0UL, 0UL}, {0UL, 0UL, 0UL}};

    for(i = 0; (pow_2_arr[i] <= inpt_N) && (i < 64); i++)
    {
        if ((pow_2_arr[i] & inpt_N) != 0UL)
        {
            innr_prd_arry3_3(out_arr, tmp_arr, rcrrnc_mem_Arr[i], MOD_NUM);
            tmp_arr[0][0] = out_arr[0][0];
            tmp_arr[0][1] = out_arr[0][1];
            tmp_arr[0][2] = out_arr[0][2];
            tmp_arr[1][0] = out_arr[1][0];
            tmp_arr[1][1] = out_arr[1][1];
            tmp_arr[1][2] = out_arr[1][2];
            tmp_arr[2][0] = out_arr[2][0];
            tmp_arr[2][1] = out_arr[2][1];
            tmp_arr[2][2] = out_arr[2][2];
        }
        else{/*nothing*/}
    }

    ret = (unsigned int)out_arr[0][1];

    return ret;
}

void clc_rcrrnc_mem_Arr(void)
{
    int i;

    for (i = 0; i < 63; i++)
    {
        pow2_arry3_3(rcrrnc_mem_Arr[(i + 1)], rcrrnc_mem_Arr[i], MOD_NUM);
    }

    return;
}

void pow2_arry3_3 (uint64_t out_arr[][3], uint64_t inpt_arr[][3], uint64_t mod_num) /*3×3行列の2乗を計算し、mod_numで割った余りを出力する*/
{
    out_arr[0][0] = (inpt_arr[0][0] * inpt_arr[0][0]) + (inpt_arr[0][1] * inpt_arr[1][0]) + (inpt_arr[0][2] * inpt_arr[2][0]);
    out_arr[0][1] = (inpt_arr[0][0] * inpt_arr[0][1]) + (inpt_arr[0][1] * inpt_arr[1][1]) + (inpt_arr[0][2] * inpt_arr[2][1]);
    out_arr[0][2] = (inpt_arr[0][0] * inpt_arr[0][2]) + (inpt_arr[0][1] * inpt_arr[1][2]) + (inpt_arr[0][2] * inpt_arr[2][2]);
    out_arr[1][0] = (inpt_arr[1][0] * inpt_arr[0][0]) + (inpt_arr[1][1] * inpt_arr[1][0]) + (inpt_arr[1][2] * inpt_arr[2][0]);
    out_arr[1][1] = (inpt_arr[1][0] * inpt_arr[0][1]) + (inpt_arr[1][1] * inpt_arr[1][1]) + (inpt_arr[1][2] * inpt_arr[2][1]);
    out_arr[1][2] = (inpt_arr[1][0] * inpt_arr[0][2]) + (inpt_arr[1][1] * inpt_arr[1][2]) + (inpt_arr[1][2] * inpt_arr[2][2]);
    out_arr[2][0] = (inpt_arr[2][0] * inpt_arr[0][0]) + (inpt_arr[2][1] * inpt_arr[1][0]) + (inpt_arr[2][2] * inpt_arr[2][0]);
    out_arr[2][1] = (inpt_arr[2][0] * inpt_arr[0][1]) + (inpt_arr[2][1] * inpt_arr[1][1]) + (inpt_arr[2][2] * inpt_arr[2][1]);
    out_arr[2][2] = (inpt_arr[2][0] * inpt_arr[0][2]) + (inpt_arr[2][1] * inpt_arr[1][2]) + (inpt_arr[2][2] * inpt_arr[2][2]);

    out_arr[0][0] %= mod_num;
    out_arr[0][1] %= mod_num;
    out_arr[0][2] %= mod_num;
    out_arr[1][0] %= mod_num;
    out_arr[1][1] %= mod_num;
    out_arr[1][2] %= mod_num;
    out_arr[2][0] %= mod_num;
    out_arr[2][1] %= mod_num;
    out_arr[2][2] %= mod_num;

    return;
}

void innr_prd_arry3_3 (uint64_t out_arr[][3], uint64_t inpt_arr_A[][3], uint64_t inpt_arr_B[][3], uint64_t mod_num) /*3×3行列の内積ABを計算し、mod_numで割った余りを出力する*/
{
    out_arr[0][0] = (inpt_arr_A[0][0] * inpt_arr_B[0][0]) + (inpt_arr_A[0][1] * inpt_arr_B[1][0]) + (inpt_arr_A[0][2] * inpt_arr_B[2][0]);
    out_arr[0][1] = (inpt_arr_A[0][0] * inpt_arr_B[0][1]) + (inpt_arr_A[0][1] * inpt_arr_B[1][1]) + (inpt_arr_A[0][2] * inpt_arr_B[2][1]);
    out_arr[0][2] = (inpt_arr_A[0][0] * inpt_arr_B[0][2]) + (inpt_arr_A[0][1] * inpt_arr_B[1][2]) + (inpt_arr_A[0][2] * inpt_arr_B[2][2]);
    out_arr[1][0] = (inpt_arr_A[1][0] * inpt_arr_B[0][0]) + (inpt_arr_A[1][1] * inpt_arr_B[1][0]) + (inpt_arr_A[1][2] * inpt_arr_B[2][0]);
    out_arr[1][1] = (inpt_arr_A[1][0] * inpt_arr_B[0][1]) + (inpt_arr_A[1][1] * inpt_arr_B[1][1]) + (inpt_arr_A[1][2] * inpt_arr_B[2][1]);
    out_arr[1][2] = (inpt_arr_A[1][0] * inpt_arr_B[0][2]) + (inpt_arr_A[1][1] * inpt_arr_B[1][2]) + (inpt_arr_A[1][2] * inpt_arr_B[2][2]);
    out_arr[2][0] = (inpt_arr_A[2][0] * inpt_arr_B[0][0]) + (inpt_arr_A[2][1] * inpt_arr_B[1][0]) + (inpt_arr_A[2][2] * inpt_arr_B[2][0]);
    out_arr[2][1] = (inpt_arr_A[2][0] * inpt_arr_B[0][1]) + (inpt_arr_A[2][1] * inpt_arr_B[1][1]) + (inpt_arr_A[2][2] * inpt_arr_B[2][1]);
    out_arr[2][2] = (inpt_arr_A[2][0] * inpt_arr_B[0][2]) + (inpt_arr_A[2][1] * inpt_arr_B[1][2]) + (inpt_arr_A[2][2] * inpt_arr_B[2][2]);

    out_arr[0][0] %= mod_num;
    out_arr[0][1] %= mod_num;
    out_arr[0][2] %= mod_num;
    out_arr[1][0] %= mod_num;
    out_arr[1][1] %= mod_num;
    out_arr[1][2] %= mod_num;
    out_arr[2][0] %= mod_num;
    out_arr[2][1] %= mod_num;
    out_arr[2][2] %= mod_num;

    return;
}


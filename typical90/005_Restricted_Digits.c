#include <stdio.h>
#include <stdint.h>

#define MOD_NUM (1000000007U)
#define MAX_N (1000000000000000000UL)
#define MAX_B (1000)

uint32_t mod_arr[MAX_B];
uint32_t tmp_arr[MAX_B];
uint32_t cffcnt_arr[MAX_B];
uint32_t base_arr[60][MAX_B];
uint32_t mem_arr[60][MAX_B];

void calc_next(uint32_t *cal_arr, uint32_t *cff_arr, uint32_t *out_arr, uint32_t B);
uint32_t get_msb_u64(uint64_t inpt);
void calc_base_arr(uint32_t len_r, uint32_t len_c);
void calc_mem_arr(uint32_t len_r, uint32_t len_c);
void arr_clr_u32(uint32_t *arr, uint32_t len);

int main(void)
{
    uint32_t i, j;
    uint64_t k;
    uint64_t inpt_N;
    uint32_t inpt_B, inpt_K, inpt_C;
    uint32_t msb_inptB;
    
    int32_t bit = 0;
    int32_t old_bit = -1;

    /* get input */
    (void)scanf("%lu%u%u\n", &inpt_N, &inpt_B, &inpt_K);

    for (i = 0U; i < inpt_K; i++)
    {
        (void)scanf("%u", &inpt_C);
        inpt_C %= inpt_B;
        mem_arr[0][inpt_C]++;
    }
    (void)scanf("\n");

    for (i = 0U; i < inpt_B; i++)
    {
        base_arr[0][i] = (i * 10U) % inpt_B;
    }

    msb_inptB = get_msb_u64(inpt_N);

    calc_base_arr(msb_inptB, inpt_B);
    calc_mem_arr(msb_inptB, inpt_B);
    

    for (k = 1UL; k <= inpt_N; k <<= 1)
    {
        if ((inpt_N & k) != 0UL)
        {
            if (old_bit >= 0L)
            {
                for(i = 0U; i < inpt_B; i++)
                {
                    cffcnt_arr[base_arr[bit][i]] += mem_arr[bit][i];
                    tmp_arr[i] = mod_arr[i];
                }
                calc_next(tmp_arr, cffcnt_arr, mod_arr, inpt_B);
            }
            else
            {
                for(i = 0U; i < inpt_B; i++)
                {
                    mod_arr[i] = mem_arr[bit][i];
                }
            }
            old_bit = bit;
        }
        else{/*nothing*/}

        arr_clr_u32(cffcnt_arr, inpt_B);
        bit++;
    }

    printf("%u\n", mod_arr[0]);

    return 0;
}


void calc_next(uint32_t *cal_arr, uint32_t *cff_arr, uint32_t *out_arr, uint32_t len)
{
    uint32_t i, j, k;
    uint32_t *p_tmp_cal;
    uint32_t *p_tmp_out = out_arr;

    for (i = 0U; i < len; i++)
    {
        p_tmp_cal = cal_arr;

        for (j = 0U; j < len; j++)
        {
            k = (len + j);
            *p_tmp_out += ((*p_tmp_cal) * cff_arr[(k % len)]) % MOD_NUM;
            p_tmp_cal++;
            k--;
        }

        p_tmp_out++;
    }

    return;
}

uint32_t get_msb_u64(uint64_t inpt)
{
    uint32_t ret;
    uint32_t i;
    uint64_t bit = 1UL;

    for (i = 0U; (bit < MAX_N); i++)
    {
        if ((inpt & bit) != 0UL)
        {
            ret = i;
        }
        else{/*nothing*/}

        bit <<= 1;
    }

    return ret;
}

void calc_base_arr(uint32_t len_r, uint32_t len_c)
{
    uint32_t i, j;
    uint32_t pow_deci = 10UL;
    uint32_t *p_tmp = &base_arr[0][0];
    uint32_t *p_tmp_old;

    for (i = 1U; i <= len_r; i++)
    {
        p_tmp_old = p_tmp;
        p_tmp = &base_arr[i][0];

        for (j = 0U; j < len_c; j++)
        {
            *p_tmp = ((*p_tmp_old) * pow_deci) % len_c;
            
            p_tmp++;
            p_tmp_old++;
        }

        pow_deci = ((pow_deci * pow_deci) % len_c);
    }

    return;
}

void calc_mem_arr(uint32_t len_r, uint32_t len_c)
{
    uint32_t i, j;
    uint32_t *p_tmp_mem = &mem_arr[0][0];
    uint32_t *p_tmp_mem_old;
    uint32_t *p_tmp_base;

    for (i = 1U; i <= len_r; i++)
    {
        p_tmp_mem_old = p_tmp_mem;
        p_tmp_mem = &mem_arr[i][0];
        p_tmp_base = &base_arr[(i - 1)][0];

        for (j = 0U; j < len_c; j++)
        {
            cffcnt_arr[*p_tmp_base] += *p_tmp_mem_old;     
        }

        calc_next(p_tmp_mem_old, cffcnt_arr, p_tmp_mem, len_c);
        arr_clr_u32(cffcnt_arr, len_c);

    }

    return;
}

void arr_clr_u32(uint32_t *arr, uint32_t len)
{
    uint32_t i;
    uint32_t *p_arr = arr;

    for (i = 0U; i < len; i++)
    {
        *p_arr = 0U;
        p_arr++;
    }
    
    return;
}

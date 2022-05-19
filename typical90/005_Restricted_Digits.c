#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MOD_NUM (1000000007U)
#define MAX_N (1000000000000000000UL)

int main(void)
{
    uint32_t i, j;
    uint64_t k;
    uint64_t inpt_N;
    uint32_t inpt_B, inpt_K, inpt_C;
    uint32_t mod_10_B;
    uint32_t tmp_mod, tmp_cal;
    uint32_t *mod_arr;
    uint32_t *tmp_mod_arr;
    uint32_t *mod_base_arr;
    uint32_t *tmp_mod_base_arr;
    size_t size_uint32_t = sizeof(uint32_t);

    /* get input */
    (void)scanf("%lu%u%u\n", &inpt_N, &inpt_B, &inpt_K);

    mod_10_B = 10U % inpt_B;

    mod_arr = (uint32_t *)malloc(size_uint32_t * (size_t)inpt_B);
    mod_base_arr = (uint32_t *)malloc(size_uint32_t * (size_t)inpt_B);
    tmp_mod_arr = (uint32_t *)malloc(size_uint32_t * (size_t)inpt_B);
    tmp_mod_base_arr = (uint32_t *)malloc(size_uint32_t * (size_t)inpt_B);

    for (i = 0U; i < inpt_B; i++)
    {
        mod_arr[i] = 0U;
        mod_base_arr[i] = 0U;
        tmp_mod_arr[i] = 0U;
        tmp_mod_base_arr[i] = 0U;
    }

    for (i = 0U; i < inpt_K; i++)
    {
        (void)scanf("%u", &inpt_C);
        inpt_C %= inpt_B;
        mod_arr[inpt_C]++;
        mod_base_arr[inpt_C]++;
    }
    (void)scanf("\n");

    for (k = 1UL; k < inpt_N; k++)
    {
        /* 次の桁のMODを求める */
        for (i = 0U; i < inpt_B; i++)
        {
            if (mod_base_arr[i])
            {
                tmp_mod = (i * mod_10_B) % inpt_B;
                tmp_mod_base_arr[tmp_mod] = mod_base_arr[i];
            }
            else{/*nothing*/}
        }
        
        for (i = 0U; i < inpt_B; i++)
        {
            mod_base_arr[i] = tmp_mod_base_arr[i];
            tmp_mod_base_arr[i] = 0U;
        }

        /* 次の桁のMODを求める */
        for (i = 0U; i < inpt_B; i++)
        {
            if (mod_base_arr[i])
            {
                for (j = 0U; j < inpt_B; j++)
                {
                    if (mod_arr[j])
                    {
                        tmp_cal = (i + j) % inpt_B;
                        tmp_mod_arr[tmp_cal] += mod_arr[j];
                        tmp_mod_arr[tmp_cal] %= MOD_NUM;
                    }
                    else{/*nothing*/}
                }
            }
            else{/*nothing*/}
        }

        for (i = 0U; i < inpt_B; i++)
        {
            mod_arr[i] = tmp_mod_arr[i];
            tmp_mod_arr[i] = 0U;
        }
    }

    printf("%u\n", mod_arr[0]);

    return 0;
}

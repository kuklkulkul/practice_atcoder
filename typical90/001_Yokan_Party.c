#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_N   (100000U)
#define MAX_INPT    (1000000000U)

typedef struct mem_maxmin_data{
    uint32_t slct_num;
    uint32_t maxmin;
    struct mem_maxmin_data *next;
}mem_data;

uint32_t A_arr[(MAX_N + 2U)];
uint32_t mem_maxmin;
uint32_t uppr;
mem_data memory[(MAX_N + 1)];
size_t mem_size = sizeof(mem_data);

uint32_t calc_min(uint32_t strt, uint32_t slct_num, uint32_t max_n, uint32_t max_min);

int main(void)
{
    uint32_t i;
    uint32_t tmp_ret;
    uint32_t inpt_N, inpt_K;
    uint32_t *p_tmp_Aarr = &A_arr[0];
    

    /* get input */
    (void)scanf("%u", &inpt_N);
    (void)scanf("%u\n", &A_arr[(inpt_N + 1U)]);
    (void)scanf("%u\n", &inpt_K);

    for (i = 0U; i < inpt_N; i++)
    {
        p_tmp_Aarr++;
        (void)scanf("%u", p_tmp_Aarr);
    }

    uppr = A_arr[(inpt_N + 1U)] / (inpt_K + 1U);

    tmp_ret = calc_min(0U, inpt_K, inpt_N, 0U);

    printf("%u\n", tmp_ret);

    return 0;
}

uint32_t calc_min(uint32_t strt, uint32_t slct_num, uint32_t max_n, uint32_t max_min)
{
    uint32_t i;
    uint32_t tmp_l = 0U, tmp_r = 0U;
    uint32_t tmp_maxmin = max_min;
    mem_data *chk = &memory[strt];

    if (tmp_maxmin >= uppr){return tmp_maxmin;}

    while (chk->next != (mem_data *)NULL)
    {
        if ((chk->slct_num == slct_num))
        {
            return (chk->maxmin);
        }
        else
        {
            chk = chk->next;
        }
    }

    
    if (slct_num > 1U)
    {
        
    }
    else
    {
        for (i = (strt + 1U); i <= max_n; i++)
        {
            tmp_l = A_arr[i] - A_arr[strt];
            tmp_r = A_arr[(max_n + 1U)] - A_arr[i];

            if (tmp_l >= tmp_r)
            {
                if (tmp_r > tmp_maxmin){tmp_maxmin = tmp_r;}
                break;
            }
            else
            {
                if (tmp_l > tmp_maxmin){tmp_maxmin = tmp_l;}
            }
        }
    }

    chk->slct_num = slct_num;
    chk->maxmin = tmp_maxmin;
    chk->next = (mem_data *)malloc(mem_size);
    chk->next->next = (mem_data *)NULL;

    return tmp_maxmin;
}

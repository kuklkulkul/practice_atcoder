#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_N   (20)
#define MAE     ('(')
#define TOJI    (')')
#define NUL_MJ  ('\0')

typedef struct kakko_retsu{
    uint32_t data;
    struct kakko_retsu *next;
}kakko;

kakko *mem_arr[(MAX_N / 2) + 1];

uint32_t get_ss(uint32_t h_N, size_t size_k);
void calc_num(uint32_t n);
void merge_asc(uint32_t* arry, uint32_t* arry_buff, uint32_t left, uint32_t mid, uint32_t right);
void sort_mrg_asc(uint32_t *arry, uint32_t *arry_buff, uint32_t left, uint32_t right);

int main(void)
{
    uint32_t i, j;
    uint32_t tmp;
    uint32_t old = 0U;
    uint32_t inpt_N;
    uint32_t half_N;
    uint32_t *arr;
    uint32_t *arr_tmp;
    kakko *p_tmp;
    size_t size_kakko = sizeof(kakko);
    size_t size_u32t = sizeof(uint32_t);

    /* get input */
    (void)scanf("%u\n", &inpt_N);

    if ((inpt_N & 1U) == 1U){return 0;}

    half_N = inpt_N >> 1;

    tmp = get_ss(half_N, size_kakko);

    arr = (uint32_t *)malloc(tmp * size_u32t);
    arr_tmp = (uint32_t *)malloc(tmp * size_u32t);
    p_tmp = mem_arr[half_N];

    for (i = 0U; i < tmp; i++)
    {
        arr[i] = p_tmp->data;
        p_tmp = p_tmp->next;
    }
  
    sort_mrg_asc(arr, arr_tmp, 0, tmp);

    for (i = 0U; i < tmp; i++)
    {
        if (old != arr[i])
        {
            for(j = inpt_N; j > 0; j--)
            {
                printf("%c", (char)(((arr[i] >> (j - 1U)) & 1U) + MAE));
            }
            printf("\n");

            old = arr[i];
        }
        else{/*nothing*/}
    }

    return 0;
}

uint32_t get_ss(uint32_t h_N, size_t size_k)
{
    uint32_t i;
    uint32_t ret = 0U;
    kakko *p_tmp;
    kakko *p_tmp_tmp;
    kakko *p_tmp_b;
    kakko *p_tmp_l;
    kakko *p_tmp_r;

    if (h_N == 1U)
    {
        mem_arr[h_N] = (kakko *)malloc(size_k);
        mem_arr[h_N]->data = 0x00000001U;
        mem_arr[h_N]->next = (kakko *)NULL;
        ret = 1U;
    }
    else
    {
        get_ss((h_N - 1U), size_k);

        mem_arr[h_N] = (kakko *)malloc(size_k);
        p_tmp = mem_arr[h_N];

        p_tmp_b = mem_arr[(h_N - 1U)];

        /* ( +S+ ) */
        while (p_tmp_b != (kakko *)NULL)
        {
            p_tmp->data = (p_tmp_b->data) << 1;
            p_tmp->data |= 1U;
            
            ret++;

            p_tmp_b = p_tmp_b->next;

            p_tmp->next = (kakko *)malloc(size_k);
            p_tmp = p_tmp->next;
        }
        
        /* S + T */
        for (i = 1; i < h_N; i++)
        {
            p_tmp_l = mem_arr[(h_N - i)];

            while (p_tmp_l  != (kakko *)NULL)
            {
                p_tmp_r = mem_arr[i];

                while (p_tmp_r  != (kakko *)NULL)
                {
                    p_tmp->data = p_tmp_l->data;
                    p_tmp->data = p_tmp->data << (2 * i);
                    p_tmp->data |= p_tmp_r->data;

                    ret++;

                    p_tmp_r = p_tmp_r->next;

                    p_tmp->next = (kakko *)malloc(size_k);
                    p_tmp_tmp = p_tmp;
                    p_tmp = p_tmp->next;
                }
                
                p_tmp_l = p_tmp_l->next;
            }
        }

        p_tmp_tmp->next = (kakko *)NULL;
    }

    return ret;
}

void merge_asc(uint32_t* arry, uint32_t* arry_buff, uint32_t left, uint32_t mid, uint32_t right)
{    
    uint32_t i, j, k, l;

    for (i = left, j = mid, k = 0UL; (i < mid) && (j < right); k++)
    {
        if (arry[i] <= arry[j])
        {
            arry_buff[k] = arry[i];
            i++;
        }
        else
        {
            arry_buff[k] = arry[j];
            j++;
        }
    }

    if (i == mid)
    {
        while (j < right)
        {
            arry_buff[k] = arry[j];
            j++;
            i++;
        }

    }
    else
    {
        while (i < mid)
        {
            arry_buff[k] = arry[i];
            i++;
            k++;
        }
    }

    for (l = 0UL; l < k; l++)
    {
        arry[left + l] = arry_buff[l];
    }

    return;
}

void sort_mrg_asc(uint32_t *arry, uint32_t *arry_buff, uint32_t left, uint32_t right)
{
    if (right - left > 1)
    {
        uint32_t mid = (left + right) / 2UL;

        sort_mrg_asc(arry, arry_buff, left, mid);
        sort_mrg_asc(arry, arry_buff, mid, right);
        merge_asc(arry, arry_buff, left, mid, right);
    }
    else
    {
        /* nothing */
    }

    return;
}

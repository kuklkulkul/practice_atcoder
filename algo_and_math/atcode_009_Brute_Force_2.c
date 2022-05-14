#include <stdio.h>
#include <stdint.h>

enum { NO = 0, YES };

int brute_force(uint16_t *arr, uint16_t arr_len, uint16_t srch_sum);

static uint8_t mem[10000];

int main(void)
{
    int output = NO;
    uint16_t i;
    uint16_t inpt_N;
    uint16_t inpt_S;
    uint16_t arr_A[60];

    /* get input */
    scanf("%hu%hu", &inpt_N, &inpt_S);

    for (i = 0U; i < inpt_N; i++)
    {
        scanf("%hu", &arr_A[i]);
    }

    output = brute_force(arr_A, inpt_N, inpt_S);

    if (output == NO)
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }

    return 0;
}

int brute_force(uint16_t *arr, uint16_t arr_len, uint16_t srch_sum)
{
    int ret = NO;
    uint16_t i = 0U, j, k;
    uint16_t temp_num;
    uint8_t temp_mem[10000] = {0U};

    while (i < arr_len)
    {
        if (arr[i] == srch_sum)
        {
            ret = YES;
            return ret;
        }
        else if (arr[i] < srch_sum)
        {
            for (j = 0U; j < srch_sum; j++)
            {
                if (mem[j] == 1U)
                {
                    temp_num = arr[i] + (j + 1U);

                    if (temp_num == srch_sum)
                    {
                        ret = YES;
                        return ret;
                    }
                    else if (temp_num < srch_sum)
                    {
                        temp_mem[(temp_num - 1U)] |= 0x01U;
                    }
                    else
                    {
                        /* nothing */
                    }
                }
                else
                {
                    /* nothing */
                }
            }

            temp_mem[(arr[i] - 1U)] |= 0x01U;

            for (k = 0U; k < srch_sum; k++)
            {
                mem[k] |= temp_mem[k];
                temp_mem[k] = 0U;
            }
        }
        else
        {
            /* nothing */
        }

        i++;
    }

    return ret;
}

#if 0
/* 構造体 */
typedef struct  str_mem {
    uint16_t num_of_mem;
    uint16_t mem_num[10000];
}   str_mem;


static str_mem mem;

int main(void)
{
    int output = NO;
    uint16_t i;
    uint16_t inpt_N;
    uint16_t inpt_S;
    uint16_t arr_A[60];

    /* get input */
    scanf("%hu%hu", &inpt_N, &inpt_S);

    for (i = 0U; i < inpt_N; i++)
    {
        scanf("%hu", &arr_A[i]);
    }

    output = brute_force(arr_A, inpt_N, inpt_S);

    if (output == NO)
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }

    return 0;
}

int brute_force(uint16_t *arr, uint16_t arr_len, uint16_t srch_sum)
{
    int ret = NO;
    uint16_t i = 0U, j, k;
    uint16_t temp_num;
    str_mem buff_mem;


    if (arr[i] == srch_sum)
    {
        ret = YES;
        return ret;
    }
    else if (arr[i] < srch_sum)
    {
        mem.mem_num[i] = arr[i];
        mem.num_of_mem++;
    }
    else
    {
        /* nothing */
    }

    i++;

    while (i < arr_len)
    {
        if (arr[i] == srch_sum)
        {
            ret = YES;
            return ret;
        }
        else if (arr[i] < srch_sum)
        {
            for (j = 0U, buff_mem.num_of_mem = 0U; j < mem.num_of_mem; j++)
            {
                temp_num = arr[i] + mem.mem_num[j];

                if (temp_num == srch_sum)
                {
                    ret = YES;
                    return ret;
                }
                else if (temp_num < srch_sum)
                {
                    buff_mem.mem_num[buff_mem.num_of_mem] = temp_num;
                    buff_mem.num_of_mem++;
                }
                else
                {
                    /* nothing */
                }
            }

            for (; 0U < buff_mem.num_of_mem; buff_mem.num_of_mem--)
            {
                for (k = 0U; k < j; k++)
                {
                    if (buff_mem.mem_num[(buff_mem.num_of_mem - 1U)] == mem.mem_num[k])
                    {
                        break;
                    }
                }

                if (k == j)
                {
                    mem.mem_num[j + (buff_mem.num_of_mem - 1U)] = buff_mem.mem_num[(buff_mem.num_of_mem - 1U)];
                    mem.num_of_mem++;
                }
            }
            
        }
        else
        {
            /* nothing */
        }

        i++;
    }

    return ret;
}

#endif

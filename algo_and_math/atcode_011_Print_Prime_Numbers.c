#include <stdio.h>
#include <stdint.h>

int chk_prmnum(int inpt);

int main(void)
{
    int inpt_a;
  	int output;

    // 整数の入力 2<=入力<=3000
    (void)scanf("%d", &inpt_a);

    if (inpt_a > 2)
    {
        printf("2 ");

        for (output = 3; output <= inpt_a; output += 2)
        {
            if (chk_prmnum(output))
            {
                printf("%d ", output);
            }
            else
            {
                // nothing
            }
        }
        printf("\n");
    }
    else
    {
        printf("2\n");
    }

    return 0;
}

int chk_prmnum(int inpt)
{
    int ret = 1;
    int uint64_factor   = 3;
    int uint64_temp_q   = inpt;
    int uint64_temp_r;
    const int rtrn_arry[3] = {0, 0, 1};

    if (inpt >= 3)
    {
        if ((unsigned int)uint64_temp_q & 1U)
        {
          for( ; uint64_factor < uint64_temp_q; uint64_factor += 2)
          {
            uint64_temp_r = inpt % uint64_factor;
            if(uint64_temp_r == 0)
            {
                ret = 0;
                break;
            }
            else
            {
                uint64_temp_q = inpt / uint64_factor;
            }
          }
        }
        else
        {
          ret = 0;
        }
    }
    else
    {
      ret = rtrn_arry[inpt];
    }

    return (ret);
}


#if 0
//inpt_num 以下の素数を算出する　引数の配列数は2以上！
int cal_prm_num(int inpt_num, int *output_arry, int arry_len)
{
    int i;
    int j;
    int k;
        
    output_arry[0U] = 2U;
    output_arry[1U] = 3U;

    for (i = 1U; i < (arry_len - 1U); i++)
    {
        for ( j = (output_arry[i] + 2UL); output_arry[i] < j; j += 2)
        {
            for (k = 0U; k <= i; k++)
            {
                if ((j % output_arry[k]) == 0U)
                {
                    break;
                }
                else
                {
                    // nothing
                }
            }

            if (k > i)
            {
                output_arry[(i + 1)] = j;
                if (j > inpt_num)
                {
                    return (i + 1);
                }
                else
                {
                    break;
                } 
            }
            else
            {
                // nothing
            }
        }
        
    }

    return 2;
}

void print_ans_uint_one_arry(int arry_len, int *print_arry)
{
    int i;

    for (i = 0U; i < (arry_len - 1); i++)
    {
        printf("%d ", print_arry[i]);
    }

    printf("%d\n", print_arry[(arry_len - 1)]);

    return;
}


int cal_prm_num(int inpt_num, int *output_arry)
{
    int i;
    int j;
    int k;
        
    output_arry[0U] = 2U;
    output_arry[1U] = 3U;

    for (i = 1U; i < (inpt_num - 1U); i++)
    {
        for ( j = (output_arry[i] + 2UL); output_arry[i] < j; j += 2UL)
        {
            for (k = 0U; k <= i; k++)
            {
                if ((j % output_arry[k]) == 0U)
                {
                    break;
                }
                else
                {
                    // nothing
                }
            }

            if (k > i)
            {
                output_arry[(i + 1)] = j;
                break;
            }
            else
            {
                // nothing
            }
        }
    }

    return 1;
}



#endif

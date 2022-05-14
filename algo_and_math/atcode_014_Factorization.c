#include <stdio.h>
#include <stdint.h>

int chk_prmnum(uint64_t inpt);

int main(void)
{
    uint64_t inpt_N;
    uint64_t div_rslt;
    uint64_t i = 2UL;
    // 整数の入力
    scanf("%Lu", &inpt_N);

    div_rslt = inpt_N;

    while ((div_rslt % i) == 0UL)
    {
        div_rslt /= i;
        printf("%Lu ", i);
    }

    if (chk_prmnum(div_rslt) == 1)
    {
        printf("%Lu\n", div_rslt);
        return 0;
    }
    else
    {
        /* nothing */
    }

    for (i = 3UL; i <= div_rslt;)
    {
        if (i == div_rslt)
        {
            printf("%Lu\n", i);
            break;
        }
        else
        {
            /* nothing */
        }

        if (chk_prmnum(i) == 1)
        {
            if ((div_rslt % i) == 0UL)
            {
                div_rslt /= i;
                printf("%Lu ", i);
                if (chk_prmnum(div_rslt) == 1)
                {
                    printf("%Lu\n", div_rslt);
                    break;
                }
                else
                {
                    /* nothing */
                }
            }
            else
            {
                i += 2UL;
            }
        }
        else
        {
            i += 2UL;
        }
    }

    return 0;
}

int chk_prmnum(uint64_t inpt)
{
    int ret = 1;
    uint64_t uint64_factor   = 3UL;
    uint64_t uint64_temp_q   = inpt;
    uint64_t uint64_temp_r;
    const int rtrn_arry[3] = {0, 0, 1};

    if (inpt >= 3UL)
    {
        if (uint64_temp_q & 1UL)
        {
          for( ; uint64_factor < uint64_temp_q; uint64_factor += 2UL)
          {
            uint64_temp_r = inpt % uint64_factor;
            if(uint64_temp_r == 0UL)
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

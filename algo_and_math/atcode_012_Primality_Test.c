#include <stdio.h>
#include <stdint.h>

int chk_prmnum(uint64_t inpt);

int main(void)
{
    unsigned long long a;
  	int chk_rslt;
    // 整数の入力
    scanf("%Lu", &a);
  
  	chk_rslt = chk_prmnum((uint64_t)a);
    
  	if (chk_rslt == 1)
    {
    	printf("Yes\n");
    }
  	else
    {
      	printf("No\n");
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

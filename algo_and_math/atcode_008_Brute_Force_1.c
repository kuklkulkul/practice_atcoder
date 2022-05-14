#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t inpt_N;
    uint32_t inpt_S;
    uint32_t ans = 0U;
    uint32_t i;

    // 整数の入力
    scanf("%u%u", &inpt_N, &inpt_S);

    if (inpt_N < inpt_S)
    {
        if (inpt_N <= (inpt_S - inpt_N))
        {
            ans = inpt_N * inpt_N;
        }
        else
        {
            for (i = 1U; (i < inpt_S) && (i <= inpt_N); i++)
            {
                if ((inpt_S - i) >= inpt_N)
                {
                    ans += inpt_N;
                }
                else
                {
                    ans += (inpt_S - i);
                }
            }
        }
    }
    else
    {
        for (i = 1U; i < inpt_S; i++)
        {
            ans += (inpt_S - i);
        }
    }

    printf("%u\n", ans);

    return 0;
}

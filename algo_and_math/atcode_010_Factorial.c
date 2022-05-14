#include <stdio.h>
#include <stdint.h>

#define INPUT_MAX (20U)

uint64_t factorial(uint64_t inpt_num);

int main(void)
{
    uint64_t inpt_N;
    uint64_t ans;

    // 整数の入力
    scanf("%Lu", &inpt_N);

    if (inpt_N > INPUT_MAX)
    {
        return 1;
    }
    else
    {
        // nothing
    }

    ans = factorial(inpt_N);

    printf("%Lu ", ans);

    return 0;

}

uint64_t factorial(uint64_t inpt_num)
{
    uint64_t ret = 1UL;
    uint64_t i;

    for (i = 2UL; i <= inpt_num; i++)
    {
        ret *= i;
    }

    return ret;
}

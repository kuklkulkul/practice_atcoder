#include <stdio.h>
#include <stdint.h>

#define MAX_N   (300000)
#define MAX_A   (1000000000)
#define MOD_NUM (1000000007UL)

int main(void)
{
    uint32_t i;
    uint32_t inpt_N;
    uint32_t inpt_A;
    uint32_t ans;
    uint64_t tmp, tmp_pow = 1UL;
    uint64_t tmp_ans = 0UL;

    /* get input */
    (void)scanf("%u\n", &inpt_N);

    for (i = 0U; i < inpt_N; i++)
    {
        (void)scanf("%u", &inpt_A);
        tmp = ((uint64_t)inpt_A) * tmp_pow;
        tmp_ans += tmp;
        tmp_ans %= MOD_NUM;
        tmp_pow *= 2UL;
        tmp_pow %= MOD_NUM;
    }

    ans = (uint32_t)tmp_ans;

    printf("%u\n", ans);

    return 0;
}

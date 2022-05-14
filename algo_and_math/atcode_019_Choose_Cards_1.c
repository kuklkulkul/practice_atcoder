#include <stdio.h>
#include <stdint.h>

uint64_t combination(uint64_t inpt_n, uint64_t inpt_r);

int main(void)
{
    uint64_t ans;
    uint64_t inpt_N;
    uint64_t i;
    int arry[3] = {0};
    int inpt_A;

    /* get input */
    scanf("%Lu", &inpt_N);

    for (i = 0UL; i < inpt_N; i++)
    {
        scanf("%d", &inpt_A);

        arry[(inpt_A - 1)]++;
    }

    ans = combination(arry[0], 2UL);
    ans += combination(arry[1], 2UL);
    ans += combination(arry[2], 2UL);

    printf("%Lu\n", ans);

    return 0;
}

uint64_t combination(uint64_t inpt_n, uint64_t inpt_r)
{
    uint64_t ret = 0UL;
    uint64_t tmp_n = inpt_n;
    uint64_t tmp_r = inpt_r;
    uint64_t tmp_nmr = 1UL;
    uint64_t tmp_dnm = 1UL;
    int i;

    if (inpt_n < inpt_r)
    {
        return ret;
    }
    else
    {
        /* nothing */
    }

    for (i = 0; i < inpt_r; i++)
    {
        tmp_nmr *= tmp_n;
        tmp_dnm *= tmp_r;
        tmp_n--;
        tmp_r--;
    }

    ret = tmp_nmr / tmp_dnm;

    return ret;
}

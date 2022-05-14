#include <stdio.h>
#include <stdint.h>

uint64_t combination(uint64_t inpt_n, uint64_t inpt_r);

int main(void)
{
    uint64_t ans;
    int inpt_N, inpt_R;

    /* get input */
    (void)scanf("%d%d", &inpt_N, &inpt_R);

    ans = combination((uint64_t)inpt_N, (uint64_t)inpt_R);

    (void)printf("%Lu\n", ans);

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
        tmp_nmr *= inpt_n;
        tmp_dnm *= tmp_r;
        inpt_n--;
        tmp_r--;
    }

    ret = tmp_nmr / tmp_dnm;

    return ret;
}

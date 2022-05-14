#include <stdio.h>
#include <stdint.h>

#define VALUE_OF_SUM    (100000)
#define MAX_INPUT       (200000)

uint64_t combination(uint64_t inpt_n, uint64_t inpt_r);

uint64_t ans = 0UL;

/* 例外入力への対応は省略 */
int main(void)
{
    int i, j;
    int inpt_N;
    int num_harf = 0;
    int buff;
    int arry_small[(VALUE_OF_SUM/2)] = {0};
    int arry_big[(VALUE_OF_SUM/2)] = {0};

    /* get input */
    scanf("%d", &inpt_N);

    for (i = 0; i < inpt_N; i++)
    {
        scanf("%d", &buff);
        if (buff == (VALUE_OF_SUM / 2))  /* VALUE_OF_SUMは偶数ってことで */
        {
            num_harf++;
        }
        else if (buff < (VALUE_OF_SUM / 2))
        {
            arry_small[(buff - 1)]++;
        }
        else
        {
            arry_big[(VALUE_OF_SUM - buff - 1)]++;
        }
    }

    if (num_harf >= 2)
    {
        ans = combination((uint64_t)num_harf, 2UL);
    }
    else
    {
        /* nothing */
    }

    for (i = 0; (i < (VALUE_OF_SUM / 2)); i++)
    {
        ans += (arry_small[i] * arry_big[i]);
    }

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
    uint64_t i;

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

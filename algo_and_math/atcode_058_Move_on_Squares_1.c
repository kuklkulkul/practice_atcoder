#include <stdio.h>

int main(void)
{
    int inpt_N, inpt_X, inpt_Y;
    int tmp_sum, tmp_1, tmp_2;
    int up, dn, rt, lt;

    /* get input */
    (void)scanf("%d%d%d\n", &inpt_N, &inpt_X, &inpt_Y);

    tmp_sum = inpt_X + inpt_Y;

    if ((inpt_N < tmp_sum) || ((0 - inpt_N) > tmp_sum))
    {
        printf("No\n");
        return 0;
    }

    tmp_1 = inpt_N + tmp_sum;
    tmp_2 = inpt_N - tmp_sum;

    if ((tmp_1 % 2) == 0 )    /* tmp_1 ≡ 0 (mod)2 <-> tmp_2 ≡ 0 (mod)2 */
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdint.h>

#define MAX_N       (100000)
#define MAX_h       (10000)

unsigned int calc_cost(unsigned int h_i, unsigned int h_j);

/* 例外入力への対応は省略 */
int main(void)
{
    unsigned int inpt_N;
    unsigned int arry_h[MAX_N] = {0};
    unsigned int arry_c[MAX_N] = {0};   /* スタート位置からのコストの最小値 */
    unsigned int cal_buff_1, cal_buff_2;
    unsigned int ans;
    unsigned int i, j;


    /* get input */
    scanf("%u", &inpt_N);

    for (i = 0UL; i < inpt_N; i++)
    {
        scanf("%u", &arry_h[i]);
    }

    arry_c[1] = calc_cost(arry_h[0], arry_h[1]);

    for (j = 2U; j < inpt_N; j++)
    {
        cal_buff_1 = calc_cost(arry_h[(j - 2U)], arry_h[j]);
        cal_buff_1 += arry_c[(j - 2U)];
        cal_buff_2 = calc_cost(arry_h[(j - 1U)], arry_h[j]);
        cal_buff_2 += arry_c[(j - 1U)];

        if (cal_buff_1 <= cal_buff_2)
        {
            arry_c[j] = cal_buff_1;
        }
        else
        {
            arry_c[j] = cal_buff_2;
        }
    }

    ans = arry_c[(inpt_N - 1U)];

    printf("%u\n", ans);

    return 0;
}



unsigned int calc_cost(unsigned int h_i, unsigned int h_j)
{
    unsigned int ret = 0U;

    if (h_i >= h_j)
    {
        ret = h_i - h_j;
    }
    else
    {
        ret = h_j - h_i;
    }

    return ret;
}

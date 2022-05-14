#include <stdio.h>
#include <stdint.h>

#define MAX_VALUE   (100)
#define MAX_INPUT   (100000)

uint64_t sum;

/* 例外入力への対応は省略 */
int main(void)
{
    uint64_t inpt_N;
    uint64_t i, j, k;
    uint64_t calc_buff;
    int inpt_buff;
    double ans;
    uint64_t arry_B[(MAX_VALUE + 1)] = {0UL};
    uint64_t arry_R[(MAX_VALUE + 1)] = {0UL};

    /* get input */
    scanf("%Lu", &inpt_N);

    for (i = 0UL; i < inpt_N; i++)
    {
        scanf("%d", &inpt_buff);
        arry_B[inpt_buff]++;
    }

    for (i = 0UL; i < inpt_N; i++)
    {
        scanf("%d", &inpt_buff);
        arry_R[inpt_buff]++;
    }

    for (j = 0; j <= MAX_VALUE; j++)
    {
        for (k = 0; k <= MAX_VALUE; k++)
        {
            calc_buff =arry_B[j] * arry_R[k];
            sum += (j + k) * calc_buff;
        }
    }

    ans = (double)sum / (double)(inpt_N * inpt_N);

    printf("%lf\n", ans);

    return 0;
}

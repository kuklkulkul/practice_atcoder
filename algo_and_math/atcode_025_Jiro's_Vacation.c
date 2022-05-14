#include <stdio.h>
#include <stdint.h>

#define MAX_N       (200000)

/* 例外入力への対応は省略 */
int main(void)
{
    uint64_t inpt_N;
    uint64_t i, j;
    uint64_t sum = 0UL;
    uint64_t A_buff, B_buff;
    double ans;


    /* get input */
    scanf("%Lu", &inpt_N);

    for (i = 0UL; i < inpt_N; i++)
    {
        scanf("%Lu", &A_buff);
        sum += A_buff;
    }

    for (j = 0UL; j < inpt_N; j++)
    {
        scanf("%Lu", &B_buff);
        sum += (2UL * B_buff);
    }


    ans = (double)sum / (double)3;

    printf("%lf\n", ans);

    return 0;
}

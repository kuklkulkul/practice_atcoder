#include <stdio.h>
#include <stdint.h>

/* 例外入力への対応は省略 */
int main(void)
{
    uint64_t inpt_N;
    uint64_t i;
    double cal_buff = 0.0;
    double ans;


    /* get input */
    scanf("%Lu", &inpt_N);

    for (i = 1; i <= inpt_N; i++)
    {
        cal_buff += (double)1/(double)i;
    }


    ans = cal_buff * (double)inpt_N;

    printf("%lf\n", ans);

    return 0;
}

#include <stdio.h>
#include <stdint.h>

#define MAX_N       (45)

/* 例外入力への対応は省略 */
int main(void)
{
    unsigned int inpt_N;
    unsigned int arry[(MAX_N + 1)] = {0};
    unsigned int cal_buff;
    unsigned int ans;
    unsigned int i;


    /* get input */
    scanf("%u", &inpt_N);

    arry[0] = 1U;
    arry[1] = 1U;

    for (i = 2U; i <= inpt_N; i++)
    {
        arry[i] = arry[(i - 1U)] + arry[(i - 2U)];
    }

    ans = arry[inpt_N];

    printf("%u\n", ans);

    return 0;
}

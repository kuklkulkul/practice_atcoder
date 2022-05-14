#include <stdio.h>
#include <stdint.h>

int main(void)
{
    const int price[4] = {100, 200, 300, 400};
    uint64_t ans;
    uint64_t inpt_N;
    uint64_t i;
    int arry[4] = {0};
    int inpt_A;

    /* get input */
    scanf("%Lu", &inpt_N);

    for (i = 0UL; i < inpt_N; i++)
    {
        scanf("%d", &inpt_A);

        switch(inpt_A)
        {
            case 100:
            arry[0]++;
            break;

            case 200:
            arry[1]++;
            break;

            case 300:
            arry[2]++;
            break;

            case 400:
            arry[3]++;
            break;

            default:
            break;
            /* nothing */
        }
    }

    ans = arry[0] * arry[3];
    ans += (arry[1] * arry[2]);

    printf("%Lu\n", ans);

    return 0;
}

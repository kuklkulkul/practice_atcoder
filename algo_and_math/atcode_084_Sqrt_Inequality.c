#include <stdio.h>
#include <stdint.h>

#define MAX_INPUT (1000000000)

int main(void)
{
    int64_t tmp_d, tmp_n;
    int32_t inpt_A, inpt_B, inpt_C;

    /* get input */
    (void)scanf("%d%d%d\n", &inpt_A, &inpt_B, &inpt_C);

    tmp_d = (int64_t)4 * (int64_t)inpt_A * (int64_t)inpt_B;
    tmp_n = (int64_t)inpt_A + (int64_t)inpt_B - (int64_t)inpt_C;
    tmp_n *= tmp_n;

    if (tmp_d >= tmp_n)
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }

    return 0;
}

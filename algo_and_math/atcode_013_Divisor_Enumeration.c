#include <stdio.h>
#include <stdint.h>


int main(void)
{
    uint64_t inpt_N;
    uint64_t i;
    uint64_t tmp_max;

    /* get input */
    scanf("%Lu", &inpt_N);

    tmp_max = inpt_N;

    for (i = 1UL; i <= tmp_max; i++)
    {
        tmp_max = (inpt_N / i);

        if ((inpt_N % i == 0U) && (i <= tmp_max))
        {
            if (i != tmp_max)
            {
                printf("%Lu\n", i);
                printf("%Lu\n", tmp_max);
            }
            else
            {
                printf("%Lu\n", i);
            }
        }
        else
        {
            /* nothing */
        }
    }

    return 0;
}

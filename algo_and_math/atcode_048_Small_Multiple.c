#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define UINT64_MAX ((uint64_t)-1)

const uint64_t per[20] = {  1UL, 10UL, 100UL, 1000UL, 10000UL, 100000UL,
                            1000000UL, 10000000UL, 100000000UL, 1000000000UL, 10000000000UL,
                            100000000000UL, 1000000000000UL, 10000000000000UL, 100000000000000UL, 1000000000000000UL,
                            10000000000000000UL, 100000000000000000UL, 1000000000000000000UL, 10000000000000000000UL
                        };



int main(void)
{
    uint64_t i, j;
    uint64_t inpt_K;
    unsigned int tmp_ans;

    /* get input */
    (void)scanf("%lu\n", &inpt_K);

    return 0;
}

unsigned int calc_sum_each_num(uint64_t num)
{
    unsigned int i;
    uint64_t ret = 0U;

    for (i = 1U; i < 20U; i++)
    {
        ret = ret + ((num % per[i])/per[(i - 1U)]);

        if (num < per[i])
        {
            break;
        }
        else
        {
            /*nothing*/
        }
    }

    return (unsigned int)ret;
}
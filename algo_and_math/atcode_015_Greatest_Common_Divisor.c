#include <stdio.h>
#include <stdint.h>

uint64_t Euclidean_Algo(uint64_t inpt_1, uint64_t inpt_2);

int main(void)
{
    uint64_t inpt_A, inpt_B;

    /* get input */
    scanf("%Lu%Lu", &inpt_A, &inpt_B);
    
    printf("%Lu\n", Euclidean_Algo(inpt_A, inpt_B));

    return 0;
}

uint64_t Euclidean_Algo(uint64_t inpt_1, uint64_t inpt_2)
{
    uint64_t ret;
    uint64_t num_1 = inpt_1;
    uint64_t num_2 = inpt_2;
    uint64_t tmp_rsd;

    if (num_1 < num_2)
    {
        num_1 += num_2;
        num_2 = num_1 - num_2;
        num_1 -= num_2;
    }
    else
    {
        /* nothing */
    }

    do
    {
        tmp_rsd = num_1 % num_2;
        num_1 = num_2;
        num_2 = tmp_rsd;

    } while (tmp_rsd != 0UL);
    
    ret = num_1;

    return ret;
}

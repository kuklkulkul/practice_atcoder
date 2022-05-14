#include <stdio.h>
#include <stdint.h>

#define CYCLE_2_MOD (4UL)

static const unsigned int mod2_arr[CYCLE_2_MOD] = {6, 2, 4, 8};

int main(void)
{
    uint64_t inpt_N;
    uint64_t mod_cycle;
    
    /* get input */
    (void)scanf("%lu\n", &inpt_N);

    mod_cycle = inpt_N & 3UL;

    printf("%u\n", mod2_arr[mod_cycle]);

    return 0;
}

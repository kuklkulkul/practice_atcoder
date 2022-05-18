#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_N (1000000000000000000UL)
#define MAX_N (1000)
#define DE_QUE_FAIL ((uint32_t)(-1))

enum {NO_CHK, CHKD};
enum {FAIL_ENQUE = -1, SUCS_ENQUE};

int main(void)
{
    uint32_t i;
    uint64_t inpt_N;
    uint32_t inpt_B, inpt_K;
    uint32_t *c_arr;
    size_t size_uint32_t = sizeof(uint32_t);

    /* get input */
    (void)scanf("%lu%u%u\n", &inpt_N, &inpt_B, &inpt_K);

    c_arr = (uint32_t *)malloc(size_uint32_t * (size_t)(inpt_K + 1U));

    for (i = 1U; i <= inpt_K; i++)
    {
        (void)scanf("%u", &c_arr[i]);
    }
    (void)scanf("\n");

    return 0;
}
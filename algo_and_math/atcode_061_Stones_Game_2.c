#include <stdio.h>
#include <stdint.h>

typedef enum {First, Second} winner_;

static const winner_ ans_arry[2][2] = {{First, Second}, {Second, First}};

unsigned int srch_msb(uint64_t N);

int main(void)
{
    unsigned int msb;
    unsigned int x, y;
    uint64_t inpt_N;

    /* get input */
    (void)scanf("%lu\n", &inpt_N);

    msb = srch_msb(inpt_N);

    x = msb % 2U;

    if (inpt_N == (1UL << msb))
    {
        y = 1U;
    }
    else
    {
        y = 0U;
    }
printf("msb: %u, x: %u, y: %u\n", msb, x, y);
    if(ans_arry[x][y] == First)
    {
        printf("First\n");
    }
    else
    {
        printf("Second\n");
    }

    return 0;
}

/* MSB (0 ~ 63) */
unsigned int srch_msb(uint64_t N)    /* must N > 0 */
{
    unsigned int i = 0U;
    unsigned int bit;

    if (N > (uint64_t)UINT32_MAX)
    {
        bit = 63U;
    }
    else
    {
        bit = 31U;
    }

    while ((i < 32U) && ((N & (1UL << (bit - i))) == 0UL))
    {
        i++;
    }

    return (bit - i);
}

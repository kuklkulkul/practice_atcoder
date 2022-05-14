#include <stdio.h>

#define MOD_NUM (1000000007U)

static unsigned int fib_mem[2] = {1U, 1U};

int main(void)
{
    unsigned int i = 3U;
    unsigned int j = 0U;
    unsigned int inpt_N;
    unsigned int ans;
    

    /* get input */
    (void)scanf("%u\n", &inpt_N);

    while (i <= inpt_N)
    {
        fib_mem[j] = fib_mem[0] + fib_mem[1];
        fib_mem[j] = fib_mem[j] % MOD_NUM;

        i++;
        j ^= 1U;
    }

    j ^= 1U;

    ans = fib_mem[j];

    printf("%u\n", ans);

    return 0;
}

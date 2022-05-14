#include <stdio.h>
#include <stdint.h>

#define MAX_N       (500000)

static unsigned int inpt_A_arr[MAX_N];
static uint64_t mem[MAX_N];

/* 例外入力への対応は省略 */
int main(void)
{  
    unsigned int i, j;
    unsigned int inpt_N;
    unsigned int inpt_a;
    uint64_t ans;

    /* get input */
    (void)scanf("%u", &inpt_N);

    for (i = 0U; i < inpt_N; i++)
    {
        (void)scanf("%u", &inpt_a);
        inpt_A_arr[i] = inpt_a;
    }

    mem[0] = (uint64_t)inpt_A_arr[0];
    mem[1] = (uint64_t)inpt_A_arr[1];
    mem[2] = mem[0] + (uint64_t)inpt_A_arr[2];

    if (mem[1] > mem[2])
    {
        ans = mem[1];
    }
    else
    {
        ans = mem[2];
    }

    for (j = 3U; j < inpt_N; j++)
    {
        if (mem[(j - 2U)] > mem[(j - 3U)])
        {
            mem[j] = (uint64_t)inpt_A_arr[j] + mem[(j - 2U)];
        }
        else
        {
            mem[j] = (uint64_t)inpt_A_arr[j] + mem[(j - 3U)];
        }
        
        if (ans < mem[j])
        {
            ans = mem[j];
        }
        else{/* nothing */}
    }

    printf("%Lu\n", ans);

    return 0;
}

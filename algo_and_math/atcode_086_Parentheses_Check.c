#include <stdio.h>
#include <stdint.h>

#define MAX_N   (500000)
#define START   ('(')
#define END     (')')

static char SS[(MAX_N + 1)];

int main(void)
{
    int32_t i;
    int32_t count;
    uint32_t inpt_N;
    char *ss = &SS[0];

    /* get input */
    (void)scanf("%u\n", &inpt_N);
    (void)scanf("%s", SS);

    for (i = 0; i < inpt_N; i++, ss++)
    {
        if (*ss == START)
        {
            count++;
        }
        else
        {
            count--;
        }

        if (count < 0)
        {
            printf("No\n");
            return 0;
        }
    }

    if (count != 0)
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }

    return 0;
}

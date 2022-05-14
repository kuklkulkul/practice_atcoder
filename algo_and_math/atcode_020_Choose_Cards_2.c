#include <stdio.h>
#include <stdint.h>

#define NUM_OF_SELECT   (5)
#define VALUE_OF_SUM    (1000)
#define MAX_INPUT       (100)

void srch_sum(int choice_num, int chk_val, int* arry, int left, int right);

uint64_t ans = 0UL;

/* 例外入力への対応は省略 */
int main(void)
{
    int inpt_N;
    int i, j, k;
    int sum = 0;
    int chk_max;
    int arry[MAX_INPUT] = {0};

    /* get input */
    scanf("%d", &inpt_N);

    for (i = 0; i < inpt_N; i++)
    {
        scanf("%d", &arry[i]);
    }

    srch_sum(NUM_OF_SELECT, VALUE_OF_SUM, arry, 0, inpt_N);

    printf("%Lu\n", ans);

    return 0;
}

void srch_sum(int choice_num, int chk_val, int* arry, int left, int right)
{
    int i;

    if (choice_num != 1)
    {
        for (i = left; i <= (right - choice_num); i++)
        {
            srch_sum((choice_num - 1), (chk_val - arry[i]), arry, (i + 1), right);
        }
    }
    else
    {
        for (i = left; i < right; i++)
        {
            if (arry[i] == chk_val)
            {
                ans++;
            }
            else
            {
                /* nothing */
            }
        }
    }

    return;
}

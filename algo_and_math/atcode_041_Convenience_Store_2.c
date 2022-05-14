#include <stdio.h>

#define MAX_T (500000)

static int mem_staff_diff[(MAX_T + 1)];

/* 例外入力への対応は省略 */
int main(void)
{
    int staff_num;
    unsigned int i, j;
    unsigned int inpt_T, inpt_N;
    unsigned int inpt_buff_L, inpt_buff_R;


    /* get input */
    (void)scanf("%u", &inpt_T);
    (void)scanf("%u", &inpt_N);

    for (i = 0U; i < inpt_N; i++)
    {
        (void)scanf("%u%u", &inpt_buff_L, &inpt_buff_R);
        
        mem_staff_diff[inpt_buff_L]++;
        mem_staff_diff[inpt_buff_R]--;
    }

    staff_num = mem_staff_diff[0];
    printf("%d\n", staff_num);

    for (j = 1U; j < inpt_T; j++)
    {
        staff_num += mem_staff_diff[j];
        printf("%d\n", staff_num);
    }

    return 0;
}

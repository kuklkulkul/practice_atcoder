#include <stdio.h>
#include <stdint.h>
#include <float.h>

#define MAX_N (500)
#define MAX_VALUE (1000000000)



int main(void)
{
    int32_t i, j;
    uint32_t inpt_N;
    double inpt_a, inpt_b, inpt_c;
    double tmp;
    double ans = DBL_MAX;

    /* get input */
    (void)scanf("%u\n", &inpt_N);

    for (i = 1; i <= inpt_N; i++)
    {
        (void)scanf("%lf%lf%lf\n", &inpt_a, &inpt_b, &inpt_c);

        if (inpt_a >= inpt_b)
        {
            tmp = inpt_c / inpt_b;
        }
        else
        {
            tmp = inpt_c / inpt_a;
        }

        if (ans > tmp)
        {
            ans = tmp;
        }
        else{/*nothing*/}
    }

    printf("%.*lf\n", 6, ans);

    return 0;
}

#include <stdio.h>
#include <stdint.h>
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>

#define UPPR_M (60.0)
#define UPPR_H (12.0)

static double inpt_A, inpt_B, inpt_H, inpt_M;

/* 例外入力への対応は省略 */
int main(void)
{
    double min_from_0;
    double angle_h, angle_m;
    double angle_diff, AbyB;
    double ans_ex2;
    double ans;

    /* get input */
    (void)scanf("%lf%lf%lf%lf", &inpt_A, &inpt_B, &inpt_H, &inpt_M);

    AbyB = inpt_A * inpt_B;

    min_from_0 = inpt_H * UPPR_M + inpt_M;
    angle_m = 2.0 * inpt_M / UPPR_M;
    angle_h = 2.0 * min_from_0 / (UPPR_M * UPPR_H);

    angle_diff = (angle_m - angle_h) * M_PI;

    ans_ex2 = (inpt_A * inpt_A) + (inpt_B * inpt_B) - 2.0 * AbyB * cos(angle_diff);
    ans = sqrt(ans_ex2);

    printf("%.*lf\n", 10, ans);

    return 0;
}


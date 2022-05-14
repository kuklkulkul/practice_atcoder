#include <stdio.h>
#include <stdint.h>
#include <math.h>

typedef enum pint_posi_type {NEGA_ = -1, EQUA_, POSI_} pint_posi;

typedef struct coordinate_data
{
    int x_c;
    int y_c;
}coordinate;


static coordinate inpt_P1, inpt_P2, inpt_P3, inpt_P4;

/* 例外入力への対応は省略 */
int main(void)
{
    int inpt_buff_x, inpt_buff_y;
    int max_x1, max_x2, min_x1, min_x2, max_y1, max_y2, min_y1, min_y2;
    int64_t tmp_A, tmp_B, tmp_C, tmp_D, tmp_X, tmp_Y, tmp_dnm;
    double s, t;
    /* get input */
    (void)scanf("%d%d", &inpt_buff_x, &inpt_buff_y);
    inpt_P1.x_c = inpt_buff_x;
    inpt_P1.y_c = inpt_buff_y;
    max_x1 = inpt_buff_x;
    max_y1 = inpt_buff_y;

    (void)scanf("%d%d", &inpt_buff_x, &inpt_buff_y);
    inpt_P2.x_c = inpt_buff_x;
    inpt_P2.y_c = inpt_buff_y;
    if (inpt_buff_x >= max_x1)
    {
        min_x1 = max_x1;
        max_x1 = inpt_buff_x;
    }
    else
    {
        min_x1 = inpt_buff_x;
    }

    if (inpt_buff_y >= max_y1)
    {
        min_y1 = max_y1;
        max_y1 = inpt_buff_y;
    }
    else
    {
        min_y1 = inpt_buff_y;
    }

    (void)scanf("%d%d", &inpt_buff_x, &inpt_buff_y);
    inpt_P3.x_c = inpt_buff_x;
    inpt_P3.y_c = inpt_buff_y;
    max_x2 = inpt_buff_x;
    max_y2 = inpt_buff_y;

    (void)scanf("%d%d", &inpt_buff_x, &inpt_buff_y);
    inpt_P4.x_c = inpt_buff_x;
    inpt_P4.y_c = inpt_buff_y;
    if (inpt_buff_x >= max_x2)
    {
        min_x2 = max_x2;
        max_x2 = inpt_buff_x;
    }
    else
    {
        min_x2 = inpt_buff_x;
    }

    if (inpt_buff_y >= max_y2)
    {
        min_y2 = max_y2;
        max_y2 = inpt_buff_y;
    }
    else
    {
        min_y2 = inpt_buff_y;
    }

    tmp_A = (int64_t)(inpt_P1.x_c - inpt_P2.x_c);
    tmp_B = (int64_t)(inpt_P4.x_c - inpt_P3.x_c);
    tmp_C = (int64_t)(inpt_P1.y_c - inpt_P2.y_c);
    tmp_D = (int64_t)(inpt_P4.y_c - inpt_P3.y_c);
    tmp_X = (int64_t)(inpt_P2.x_c - inpt_P4.x_c);
    tmp_Y = (int64_t)(inpt_P2.y_c - inpt_P4.y_c);
    tmp_dnm = tmp_A * tmp_D - tmp_B * tmp_C;

    if((tmp_A == 0L) && (tmp_B != 0L) && (tmp_C != 0L))
    {
        t = -1.0 * (double)tmp_X / (double)tmp_B;
        s = -1.0 * (t * (double)tmp_D + (double)tmp_Y) / (double)tmp_C;
    }
    else if((tmp_B == 0L) && (tmp_A != 0L) && (tmp_D != 0L))
    {
        s = -1.0 * (double)tmp_X / (double)tmp_A;
        t = -1.0 * (s * (double)tmp_C + (double)tmp_Y) / (double)tmp_D;
    }
    else if ((tmp_C == 0L) && (tmp_A != 0L) && (tmp_D != 0L))
    {
        t = -1.0 * (double)tmp_Y / (double)tmp_D;
        s = -1.0 * (t * (double)tmp_B + (double)tmp_X) / (double)tmp_A;
    }
    else if ((tmp_D == 0L) && (tmp_B != 0L) && (tmp_C != 0L))
    {
        s = -1.0 * (double)tmp_Y / (double)tmp_C;
        t = -1.0 * (s * (double)tmp_A + (double)tmp_X) / (double)tmp_B;
    }
    else if (tmp_dnm != 0L)
    {
        s = (double)(tmp_B * tmp_Y - tmp_D * tmp_X) / (double)tmp_dnm;
        t = (double)(tmp_C * tmp_X - tmp_A * tmp_Y) / (double)tmp_dnm;
    }
    else
    {
        if (((tmp_D * tmp_X) == (tmp_B * tmp_Y)) || ((tmp_C * tmp_X) == (tmp_A * tmp_Y)))
        {
            if ((max_x1 < min_x2) || (max_x2 < min_x1) || (max_y1 < min_y2) || (max_y2 < min_y1))
            {
                printf("No\n");
            }
            else
            {
                printf("Yes\n");
            }
        }
        else
        {
            printf("No\n");
        }
        return 0;
    }


    if ((s >= 0.0) && (s <= 1.0) && (t >= 0.0) && (s <= 1.0))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}

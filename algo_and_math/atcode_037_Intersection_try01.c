#include <stdio.h>
#include <stdint.h>
#include <math.h>

typedef enum pint_posi_type {NEGA_ = -1, EQUA_, POSI_} pint_posi;

typedef struct coordinate_data
{
    int x_c;
    int y_c;
}coordinate;

typedef struct linerline_data
{
    int A_x;
    int B_y;
    int64_t C_c;
}linerline;

static coordinate inpt_P1, inpt_P2, inpt_P3, inpt_P4;

linerline calc_line_prm (coordinate p_1, coordinate p_2);
pint_posi chk_position (linerline prm, coordinate pnt);

/* 例外入力への対応は省略 */
int main(void)
{
    int inpt_buff_x, inpt_buff_y;
    linerline P12, P34;
    pint_posi P1_posi, P2_posi, P3_posi, P4_posi;

    /* get input */
    (void)scanf("%d%d", &inpt_buff_x, &inpt_buff_y);
    inpt_P1.x_c = inpt_buff_x;
    inpt_P1.y_c = inpt_buff_y;

    (void)scanf("%d%d", &inpt_buff_x, &inpt_buff_y);
    inpt_P2.x_c = inpt_buff_x;
    inpt_P2.y_c = inpt_buff_y;

    (void)scanf("%d%d", &inpt_buff_x, &inpt_buff_y);
    inpt_P3.x_c = inpt_buff_x;
    inpt_P3.y_c = inpt_buff_y;

    (void)scanf("%d%d", &inpt_buff_x, &inpt_buff_y);
    inpt_P4.x_c = inpt_buff_x;
    inpt_P4.y_c = inpt_buff_y;

    P12 = calc_line_prm(inpt_P1, inpt_P2);
    P34 = calc_line_prm(inpt_P3, inpt_P4);

    P1_posi = chk_position (P34, inpt_P1);
    P2_posi = chk_position (P34, inpt_P2);
    P3_posi = chk_position (P12, inpt_P3);
    P4_posi = chk_position (P12, inpt_P4);

    if (   (P1_posi == EQUA_)
        && (P2_posi == EQUA_)
        && (P3_posi == EQUA_)
        && (P4_posi == EQUA_))
    {
        int tmp_max_x1, tmp_max_x2, tmp_min_x1, tmp_min_x2, tmp_max_y1, tmp_max_y2, tmp_min_y1, tmp_min_y2;

        if (inpt_P1.x_c >= inpt_P2.x_c)
        {
            tmp_max_x1 = inpt_P1.x_c;
            tmp_min_x1 = inpt_P2.x_c;
        }
        else
        {
            tmp_min_x1 = inpt_P1.x_c;
            tmp_max_x1 = inpt_P2.x_c;
        }

        if (inpt_P3.x_c >= inpt_P4.x_c)
        {
            tmp_max_x2 = inpt_P3.x_c;
            tmp_min_x2 = inpt_P4.x_c;
        }
        else
        {
            tmp_min_x2 = inpt_P3.x_c;
            tmp_max_x2 = inpt_P4.x_c;
        }

        if (inpt_P1.y_c >= inpt_P2.y_c)
        {
            tmp_max_y1 = inpt_P1.y_c;
            tmp_min_y1 = inpt_P2.y_c;
        }
        else
        {
            tmp_min_y1 = inpt_P1.y_c;
            tmp_max_y1 = inpt_P2.y_c;
        }

        if (inpt_P3.y_c >= inpt_P4.y_c)
        {
            tmp_max_y2 = inpt_P3.y_c;
            tmp_min_y2 = inpt_P4.y_c;
        }
        else
        {
            tmp_min_y2 = inpt_P3.y_c;
            tmp_max_y2 = inpt_P4.y_c;
        }


        if ((tmp_max_x1 < tmp_min_x2) || (tmp_max_x2 < tmp_min_x1) || (tmp_max_y1 < tmp_min_y2) || (tmp_max_y2 < tmp_min_y1))
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
    else if (((P1_posi * P2_posi) <= 0) && ((P3_posi * P4_posi) <= 0))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n"); 
    }

    

    return 0;
}

linerline calc_line_prm (coordinate p_1, coordinate p_2)
{
    linerline ret;

    ret.A_x = p_1.y_c - p_2.y_c;
    ret.B_y = p_2.x_c - p_1.x_c;

    ret.C_c = -1 * (int64_t)p_1.x_c * (int64_t)ret.A_x - (int64_t)p_1.y_c * (int64_t)ret.B_y;

    return ret;
}

pint_posi chk_position (linerline prm, coordinate pnt)
{
    pint_posi ret;
    int64_t tmp;

    tmp = (int64_t)prm.A_x * (int64_t)pnt.x_c + (int64_t)prm.B_y * (int64_t)pnt.y_c + prm.C_c;

    if (tmp > 0)
    {
        ret = POSI_;
    }
    else if (tmp < 0)
    {
        ret = NEGA_;
    }
    else
    {
        ret = EQUA_;
    }

    return ret;
}

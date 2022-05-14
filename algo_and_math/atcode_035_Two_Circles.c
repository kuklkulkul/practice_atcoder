#include <stdio.h>
#include <stdint.h>

typedef struct circle_data
{
    uint64_t x_c;
    uint64_t y_c;
    uint64_t rad;
}circle;

static circle inpt_Crcl[2];

/* 例外入力への対応は省略 */
int main(void)
{
    uint64_t inpt_buff_x, inpt_buff_y, inpt_buff_r;
    uint64_t tmp_cl_1, tmp_cl_2, tmp_cl_3, tmp_cl_4;
    uint64_t dst_bw_cntrs_ex;

    /* get input */
    (void)scanf("%Lu%Lu%Lu", &inpt_buff_x, &inpt_buff_y, &inpt_buff_r);
    inpt_Crcl[0].x_c = inpt_buff_x;
    inpt_Crcl[0].y_c = inpt_buff_y;
    inpt_Crcl[0].rad = inpt_buff_r;
    tmp_cl_1 = inpt_buff_x * inpt_buff_x + inpt_buff_y * inpt_buff_y;
    tmp_cl_3 = inpt_buff_r;

    (void)scanf("%Lu%Lu%Lu", &inpt_buff_x, &inpt_buff_y, &inpt_buff_r);
    inpt_Crcl[1].x_c = inpt_buff_x;
    inpt_Crcl[1].y_c = inpt_buff_y;
    inpt_Crcl[1].rad = inpt_buff_r;
    tmp_cl_2 = inpt_buff_x * inpt_buff_x + inpt_buff_y * inpt_buff_y;
    tmp_cl_3 += inpt_buff_r;
    tmp_cl_3 *= tmp_cl_3;

    dst_bw_cntrs_ex = tmp_cl_1 + tmp_cl_2 - 2UL * (inpt_Crcl[0].x_c * inpt_buff_x + inpt_Crcl[0].y_c * inpt_buff_y);

    if (dst_bw_cntrs_ex > tmp_cl_3)
    {
        printf("5\n");
        return 0;
    }
    else if (dst_bw_cntrs_ex == tmp_cl_3)
    {
        printf("4\n");
        return 0;
    }
    else{/*nothing*/}

    if (inpt_Crcl[0].rad >= inpt_Crcl[1].rad)
    {
        tmp_cl_4 = inpt_Crcl[0].rad;
        tmp_cl_4 -= inpt_Crcl[1].rad;
    }
    else
    {
        tmp_cl_4 = inpt_Crcl[1].rad;
        tmp_cl_4 -= inpt_Crcl[0].rad;
    }

    tmp_cl_4 *= tmp_cl_4;

    if (tmp_cl_4 > dst_bw_cntrs_ex)
    {
        printf("1\n");
        return 0;
    }
    else if (tmp_cl_4 == dst_bw_cntrs_ex)
    {
        printf("2\n");
        return 0;
    }
    else{/*nothing*/}
    

    printf("3\n");

    return 0;
}


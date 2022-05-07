#include <stdio.h>
#include <stdint.h>

#define MAX_N   (100000)
#define MAX_INPT    (1000000000)

int32_t A_arr[(MAX_N + 2U)];


int32_t calc_min(int32_t slct_num, int32_t max_n, int32_t uppr);
int32_t part_cal(int32_t strt, int32_t slct_num, int32_t max_n, int32_t lower);

int main(void)
{
    int32_t i;
    int32_t tmp_ret;
    int32_t inpt_N, inpt_K;
    int32_t upper;
    int32_t *p_tmp_Aarr = &A_arr[0];
    

    /* get input */
    (void)scanf("%d", &inpt_N);
    (void)scanf("%d\n", &A_arr[(inpt_N + 1)]);
    (void)scanf("%d\n", &inpt_K);

    for (i = 0; i < inpt_N; i++)
    {
        p_tmp_Aarr++;
        (void)scanf("%d", p_tmp_Aarr);
    }

    upper = A_arr[(inpt_N + 1)] / (inpt_K + 1);

    tmp_ret = calc_min(inpt_K, inpt_N, upper);

    printf("%d\n", tmp_ret);

    return 0;
}


int32_t calc_min(int32_t slct_num, int32_t max_n, int32_t uppr)
{
    int32_t ret;
    int32_t i, j;
    int32_t srch_val_l = 1;
    int32_t srch_val_u = uppr;
    int32_t srch_val_m = uppr / 2;
    int32_t tmp_u, tmp_l, tmp_m;

    ret = part_cal(0, slct_num, max_n, srch_val_l);

    while (srch_val_l != srch_val_u)
    {
        tmp_u = part_cal(0, slct_num, max_n, srch_val_u);
        
        
        if (tmp_u != -1)
        {
            ret = tmp_u;
            break;
        }
        else
        {
            tmp_m = part_cal(0, slct_num, max_n, srch_val_m);

            if (tmp_m != -1)
            {
                srch_val_l = srch_val_m;
                srch_val_u = (srch_val_l + srch_val_u) / 2;
            }
            else
            {
                srch_val_u = srch_val_m - 1;
            }
        }

    }

    return ret;
}

int32_t part_cal(int32_t strt, int32_t slct_num, int32_t max_n, int32_t lower)
{
    int32_t ret = -1;
    int32_t i;
    int32_t tmp;

    if (slct_num == 1)
    {
        for(i = (strt + 1); i <= max_n; i++)
        {
            tmp = A_arr[i] - A_arr[strt];
            if (tmp >= lower)
            {
                int32_t tmp_l = A_arr[(max_n + 1)] - A_arr[i];

                if (tmp_l >= lower)
                {
                    if (tmp > tmp_l)
                    {
                        ret = tmp_l;
                    }
                    else
                    {
                        ret = tmp;
                    }
                }
                break;
            }
            else{/*nothing*/}
        }
    }
    else
    {
        for(i = (strt + 1); i <= (max_n - slct_num + 1); i++)
        {
            tmp = A_arr[i] - A_arr[strt];

            if (tmp >= lower)
            {
                ret = tmp;
                tmp = part_cal(i, (slct_num - 1), max_n, lower);

                if (tmp == -1)
                {
                    ret = -1;
                }
                else if (ret > tmp)
                {
                    ret = tmp;
                }
                else
                {
                    /* nothing */
                }

                break;
            }
            else{/*nothing*/}
        }
    }


    return ret;
}


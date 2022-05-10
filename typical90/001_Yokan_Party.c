#include <stdio.h>
#include <stdint.h>

#define MAX_N   (100000)
#define MAX_INPT    (1000000000)

typedef enum {
    false_,
    true_,
} Bool_;

int32_t A_arr[(MAX_N + 2U)];

int32_t calc_min(int32_t slct_num, int32_t max_n, int32_t uppr);
Bool_ part_cal(int32_t slct_num, int32_t max_n, int32_t lower);

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
    int32_t srch_val_l = 1;
    int32_t srch_val_u = uppr;
    int32_t srch_val_m = (srch_val_l + srch_val_u + 1) / 2;
    Bool_ tmp_m;

    while ((srch_val_l < srch_val_m) && (srch_val_m < srch_val_u))
    {
        tmp_m = part_cal(slct_num, max_n, srch_val_m);
        
        if (tmp_m == false_)
        {
            srch_val_u = srch_val_m;      
        }
        else
        {
            srch_val_l = srch_val_m;
        }
        
        srch_val_m = (srch_val_l + srch_val_u + 1) / 2;
    } 

    tmp_m = part_cal(slct_num, max_n, srch_val_u);

    if (tmp_m == false_)
    {
        ret = srch_val_l;
    }
    else
    {
        ret = srch_val_u;
    }

    return ret;
}

Bool_ part_cal(int32_t slct_num, int32_t max_n, int32_t lower)
{
    Bool_ ret = false_;
    int32_t i = max_n;
    int32_t tmp;
    int32_t start = A_arr[0];
    int32_t end = A_arr[(max_n + 1)];
    int32_t *p_slct = &A_arr[1];
    int32_t slct = slct_num;

    while (i >= 1)
    {
        if (lower <= (*p_slct - start))
        {
            start = *p_slct;
            slct--;

            if (slct <= 0)
            {
                break;
            }else{/*nothing*/}
        }
        else{/*nothing*/}

        p_slct++;
        i--;
    }

    if ((slct <= 0))
    {
        if (lower <= (end - *p_slct))
        {
            ret = true_;
        }
        else{/*nothing*/}
    }
    else{/*nothing*/}

    return ret;
}


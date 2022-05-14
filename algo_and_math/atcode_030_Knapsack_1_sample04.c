#include <stdio.h>
#include <stdint.h>

#define MAX_N       (100)
#define MAX_W       (100000)


typedef struct load_data{
    unsigned int weight;
    uint64_t value;
    double vpw;
}load;

static load inpt_load[MAX_N];
static load load_buff[MAX_N];

/* 例外入力への対応は省略 */
int main(void)
{
    
    unsigned int i, j, k, l, m;
    unsigned int inpt_N, inpt_W;
    unsigned int inpt_w, inpt_v;
    unsigned int sum_w_all = 0U;
    unsigned int sum_w_max = 0U;
    unsigned int sum_w_tmp = 0U;
    
    
    uint64_t sum_v_all = 0UL;
    uint64_t sum_v_max = 0UL;
    uint64_t sum_v_tmp = 0UL;
    uint64_t ans;


    /* get input */
    (void)scanf("%u%u", &inpt_N, &inpt_W);

    for (i = 0U; i < inpt_N; i++)
    {
        (void)scanf("%u%u", &inpt_w, &inpt_v);
        inpt_load[i].weight = inpt_w;
        inpt_load[i].value = inpt_v;
        inpt_load[i].vpw = (double)inpt_v / (double)inpt_w;
        sum_w_all += inpt_w;
        sum_v_all += inpt_v;
    }

    sort_mrg_dsc(inpt_load, load_buff, 0U, inpt_N);

    for (j = 0U; j < inpt_N; j++)
    {
        sum_w_tmp += inpt_load[j].weight;
        sum_v_tmp += inpt_load[j].value;

        if (sum_w_tmp > inpt_W)
        {
            break;
        }
        else
        {
            sum_w_max = sum_w_tmp;
            sum_v_max = sum_v_tmp;
        }
    }

    if ((j >= inpt_N)
        || (inpt_load[j - 1U].value >= (sum_v_all - sum_v_max)))
    {
        ans = sum_v_max;
        printf("%Lu\n", ans);
        return 0;
    }
    else{/*nothing*/}

    sum_w_tmp = sum_w_max;
    sum_v_tmp = sum_v_max;

    ans = sum_v;

    printf("%Lu\n", ans);

    return 0;
}

load srch_ans(load *arry, unsigned int uppr_w, )
{
    load ret;

    return ret;
}


void merge_dsc(load* arry, load* arry_buff, unsigned int left, unsigned int mid, unsigned int right)
{    
    unsigned int i, j, k, l;

    for (i = left, j = mid, k = 0U; (i < mid) && (j < right); k++)
    {
        if (arry[i].vpw >= arry[j].vpw)
        {
            arry_buff[k] = arry[i];
            i++;
        }
        else
        {
            arry_buff[k] = arry[j];
            j++;
        }
    }

    if (i == mid)
    {
        while (j < right)
        {
            arry_buff[k] = arry[j];
            j++;
            i++;
        }

    }
    else
    {
        while (i < mid)
        {
            arry_buff[k] = arry[i];
            i++;
            k++;
        }
    }

    for (l = 0U; l < k; l++)
    {
        arry[left + l] = arry_buff[l];
    }

    return;
}

void sort_mrg_dsc(load *arry, load *arry_buff, unsigned int left, unsigned int right)
{
    if (right - left > 1U)
    {
        unsigned int mid = (left + right) / 2UL;

        sort_mrg_dsc(arry, arry_buff, left, mid);
        sort_mrg_dsc(arry, arry_buff, mid, right);
        merge_dsc(arry, arry_buff, left, mid, right);
    }
    else
    {
        /* nothing */
    }

    return;
}


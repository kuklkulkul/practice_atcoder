#include <stdio.h>
#include <stdint.h>

#define MAX_N       (100)
#define MAX_W       (100000)

typedef struct load_data{
    unsigned int weight;
    uint64_t value;
} load;

load srch_vmax(unsigned int N, load *load_data, unsigned int start, unsigned int num, unsigned int w_uppr, uint64_t sum_val, unsigned int sum_wt);
void merge_dsc(load* arry, load* arry_buff, unsigned int left, unsigned int mid, unsigned int right);
void sort_mrg_dsc(load *arry, load *arry_buff, unsigned int left, unsigned int right);

static load mem[MAX_N][MAX_N];
static uint64_t sum_v;

/* 例外入力への対応は省略 */
int main(void)
{
    
    unsigned int i, j, k;
    unsigned int inpt_N, inpt_W;
    unsigned int inpt_w, inpt_v;

    load inpt_load[MAX_N];
    load load_buff[MAX_N];
    load load_tmp;

    unsigned int sum_w = 0U;
    
    uint64_t ans;


    /* get input */
    (void)scanf("%u%u", &inpt_N, &inpt_W);

    for (i = 0U; i < inpt_N; i++)
    {
        (void)scanf("%u%u", &inpt_w, &inpt_v);
        inpt_load[i].weight = inpt_w;
        inpt_load[i].value = (uint64_t)inpt_v;
    }

    sort_mrg_dsc(inpt_load, load_buff, 0U, inpt_N);

    for (j = 1U; j <= inpt_N; j++)
    {
        for (k = 0U; k <= (inpt_N - j); k++)
        {
            load_tmp = srch_vmax(inpt_N, inpt_load, k, j, inpt_W, 0UL, 0U);
            mem[(j - 1U)][k] = load_tmp;

            //printf("mem[%u][%u] = {%Lu, %u}\n", (j - 1U), k, mem[(j - 1U)][k].value, mem[(j - 1U)][k].weight);
    
            if (sum_v < load_tmp.value)
            {
                sum_v = load_tmp.value;
            }
            else{/*nothing*/}
        }
    }

    ans = sum_v;

    printf("%Lu\n", ans);

    return 0;
}

load srch_vmax(unsigned int N, load *load_data, unsigned int start, unsigned int num, unsigned int w_uppr, uint64_t sum_val, unsigned int sum_wt)
{
    unsigned int i;
    unsigned int tmp_wt;
    unsigned int old_val = 0U;
    uint64_t tmp_val;
    load ret_tmp;
    load ret;

    if (((mem[(num - 1U)][start].value != 0UL) || (mem[(num - 1U)][start].weight != 0U))
        && (mem[(num - 1U)][start].weight <= w_uppr))
    {
        ret.value = sum_val + mem[(num - 1U)][start].value;
        ret.weight = sum_wt + mem[(num - 1U)][start].weight;
        return ret;
    }
    else{/*nothing*/}

    ret.value = sum_val;
    ret.weight = sum_wt;

    if (num == 1U)
    {
        for (i = start; i < N; i++)
        {
            if ((load_data[i].weight <= w_uppr) && (load_data[i].value >= old_val))
            {
                tmp_val = sum_val + load_data[i].value;
                tmp_wt = sum_wt + load_data[i].weight;

                if (tmp_val > ret.value)
                {
                    ret.value = tmp_val;
                    ret.weight = tmp_wt;
                }
                else {/* nothing */}

                old_val = load_data[i].value;
            }
            else if (load_data[i].value < old_val)
            {
                break;
            }
            else
            {/* nothing */}
        }
    }
    else
    {
        for (i = start; i <= (N - num); i++)
        {
            if (load_data[i].weight <= w_uppr)
            {
                ret_tmp = srch_vmax(N, load_data, (i + 1U), (num - 1U), (w_uppr - load_data[i].weight), (sum_val + load_data[i].value), (sum_wt + load_data[i].weight));

                if (ret_tmp.value > ret.value)
                {
                    ret = ret_tmp;
                }
                else{/*nothing*/}
            }
            else
            {
                /* nothing */
            }
        }
    }

    

    return ret;
}

void merge_dsc(load* arry, load* arry_buff, unsigned int left, unsigned int mid, unsigned int right)
{    
    unsigned int i, j, k, l;

    for (i = left, j = mid, k = 0U; (i < mid) && (j < right); k++)
    {
        if (arry[i].value >= arry[j].value)
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


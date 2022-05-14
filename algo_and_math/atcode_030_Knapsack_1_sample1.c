#include <stdio.h>
#include <stdint.h>

#define MAX_N       (100)
#define MAX_W       (100000)

struct load_prm {
    unsigned int weight;
    unsigned int value;
    double vpw;
};

struct load_prm buff;


void merge_asc(struct load_prm* arry, struct load_prm* arry_buff, unsigned int left, unsigned int mid, unsigned int right);
void sort_mrg_asc(struct load_prm *arry, struct load_prm *arry_buff, unsigned int left, unsigned int right);

/* 例外入力への対応は省略 */
int main(void)
{
    unsigned int inpt_N, inpt_W, inpt_w, inpt_v;
    unsigned int i, j, k;
    unsigned int mem_arr[MAX_N];
    uint64_t sum_w = 0UL;
    uint64_t sum_v = 0UL;
    uint64_t ans;

    struct load_prm load[MAX_N];
    struct load_prm buff[MAX_N];

    /* get input */
    (void)scanf("%u%u", &inpt_N, &inpt_W);

    for (i = 0U; i < inpt_N; i++)
    {
        (void)scanf("%u%u", &inpt_w, &inpt_v);
        load[i].weight = inpt_w;
        sum_w += inpt_w;
        load[i].value = inpt_v;
        sum_v += inpt_v;
        load[i].vpw = (double)load[i].value / (double)load[i].weight;
    }

    if (sum_w <= inpt_W)
    {
        printf("%Lu\n", sum_v);
        return 0;
    }
    else
    {/* nothing */}

    sort_mrg_asc(load, buff, 0U, inpt_N);



    printf("%Lu\n", ans);

    return 0;
}

void merge_asc(struct load_prm* arry, struct load_prm* arry_buff, unsigned int left, unsigned int mid, unsigned int right)
{    
    unsigned int i, j, k, l;

    for (i = left, j = mid, k = 0U; (i < mid) && (j < right); k++)
    {
        if (arry[i].vpw <= arry[j].vpw)
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

void sort_mrg_asc(struct load_prm *arry, struct load_prm *arry_buff, unsigned int left, unsigned int right)
{
    if (right - left > 1)
    {
        unsigned int mid = (left + right) / 2U;

        sort_mrg_asc(arry, arry_buff, left, mid);
        sort_mrg_asc(arry, arry_buff, mid, right);
        merge_asc(arry, arry_buff, left, mid, right);
    }
    else
    {
        /* nothing */
    }

    return;
}

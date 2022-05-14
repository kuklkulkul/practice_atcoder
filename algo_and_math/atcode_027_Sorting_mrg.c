#include <stdio.h>
#include <stdint.h>

#define MAX_ARRY    (200000)

enum {
    ascending,  /* 昇順 */
    descending  /* 降順 */
};

void sort_mrg(uint64_t *arry, uint64_t *arry_buff, uint64_t len, unsigned int type);
void sort_mrg_asc(uint64_t *arry, uint64_t *arry_buff, uint64_t left, uint64_t right);
void mrg_asc(uint64_t *arry_1, uint64_t *arry_2, uint64_t left, uint64_t mid, uint64_t right);
void merge_dsc(uint64_t* arry, uint64_t* arry_buff, uint64_t left, uint64_t mid, uint64_t right);
void sort_mrg_dsc(uint64_t *arry, uint64_t *arry_buff, uint64_t left, uint64_t right);

/* 例外入力への対応は省略 */
int main(void)
{
    uint64_t ans;
    int inpt_N;
    int i;
    uint64_t arry[MAX_ARRY] = {0};
    uint64_t arry_buff[MAX_ARRY] = {0};


    /* get input */
    scanf("%d", &inpt_N);

    for (i = 0; i < inpt_N; i++)
    {
        scanf("%d", &arry[i]);
    }

    sort_mrg(arry, arry_buff, inpt_N, ascending);

    for (i = 0; i < inpt_N; i++)
    {
        printf("%Lu ", arry[i]);
    }

    printf("\n");

    return 0;
}

void sort_mrg(uint64_t *arry, uint64_t *arry_buff, uint64_t len, unsigned int type)
{
    switch (type)
    {
        case ascending:
        sort_mrg_asc(arry, arry_buff, 0UL, len);
        break;

        case descending:
        sort_mrg_dsc(arry, arry_buff, 0UL, len);
        break;

        default:
        break;
    }

    return;
}

void merge_asc(uint64_t* arry, uint64_t* arry_buff, uint64_t left, uint64_t mid, uint64_t right)
{    
    uint64_t i, j, k, l;

    for (i = left, j = mid, k = 0UL; (i < mid) && (j < right); k++)
    {
        if (arry[i] <= arry[j])
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

    for (l = 0UL; l < k; l++)
    {
        arry[left + l] = arry_buff[l];
    }

    return;
}

void sort_mrg_asc(uint64_t *arry, uint64_t *arry_buff, uint64_t left, uint64_t right)
{
    if (right - left > 1)
    {
        uint64_t mid = (left + right) / 2UL;

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

void merge_dsc(uint64_t* arry, uint64_t* arry_buff, uint64_t left, uint64_t mid, uint64_t right)
{    
    uint64_t i, j, k, l;

    for (i = left, j = mid, k = 0UL; (i < mid) && (j < right); k++)
    {
        if (arry[i] >= arry[j])
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

    for (l = 0UL; l < k; l++)
    {
        arry[left + l] = arry_buff[l];
    }

    return;
}

void sort_mrg_dsc(uint64_t *arry, uint64_t *arry_buff, uint64_t left, uint64_t right)
{
    if (right - left > 1)
    {
        uint64_t mid = (left + right) / 2UL;

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


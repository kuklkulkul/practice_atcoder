#include <stdio.h>
#include <stdint.h>

#define MAX_N       (100000)

enum bool_type {FALSE, TRUE} bool;


int srch_min(unsigned int left, unsigned int right);
void merge_asc(unsigned int left, unsigned int mid, unsigned int right);
void sort_mrg_asc(unsigned int left, unsigned int right);

static unsigned int inpt_X;
static unsigned int inpt_A_arr[MAX_N];
static unsigned int buff_A_arr[MAX_N];

/* 例外入力への対応は省略 */
int main(void)
{  
    unsigned int i, j;
    unsigned int inpt_N;
    unsigned int inpt_a;
    unsigned int ans;

    /* get input */
    (void)scanf("%u%u", &inpt_N, &inpt_X);

    for (i = 0U; i < inpt_N; i++)
    {
        (void)scanf("%u", &inpt_a);
        inpt_A_arr[i] = inpt_a;
    }

    sort_mrg_asc(0U, inpt_N);

    ans = srch_min(0, inpt_N);

    if (ans == TRUE)
    {
        printf("Yes\n", ans);
    }
    else
    {
        printf("No\n", ans);
    }

    return 0;
}

int srch_min(unsigned int left, unsigned int right)
{
    int ret = FALSE;
    unsigned int i;
    unsigned int mid = (right + left) / 2U;

    if (inpt_A_arr[mid] == inpt_X)
    {
        ret = TRUE;
    }
    else if (inpt_A_arr[mid] > inpt_X)
    {
        if ((mid - left) < 128U)
        {
            for (i = left; i < mid; i++)
            {
                if (inpt_A_arr[i] == inpt_X)
                {
                    ret = TRUE;
                    break;
                }
                else{/* nothing */}
            }
        }
        else
        {
            ret = srch_min(left, mid);
        }
    }
    else
    {
        if ((right - mid) < 128U)
        {
            for (i = mid; i < right; i++)
            {
                if (inpt_A_arr[i] == inpt_X)
                {
                    ret = TRUE;
                    break;
                }
                else{/* nothing */}
            }
        }
        else
        {
            ret = srch_min(mid, right);
        }
    }

    return ret;
}


void merge_asc(unsigned int left, unsigned int mid, unsigned int right)
{    
    unsigned int i, j, k, l;

    for (i = left, j = mid, k = 0U; (i < mid) && (j < right); k++)
    {
        if (inpt_A_arr[i] <= inpt_A_arr[j])
        {
            buff_A_arr[k] = inpt_A_arr[i];
            i++;
        }
        else
        {
            buff_A_arr[k] = inpt_A_arr[j];
            j++;
        }
    }

    if (i == mid)
    {
        while (j < right)
        {
            buff_A_arr[k] = inpt_A_arr[j];
            j++;
            i++;
        }

    }
    else
    {
        while (i < mid)
        {
            buff_A_arr[k] = inpt_A_arr[i];
            i++;
            k++;
        }
    }

    for (l = 0U; l < k; l++)
    {
        inpt_A_arr[left + l] = buff_A_arr[l];
    }

    return;
}

void sort_mrg_asc(unsigned int left, unsigned int right)
{
    if (right - left > 1U)
    {
        unsigned int mid = (left + right) / 2U;

        sort_mrg_asc(left, mid);
        sort_mrg_asc(mid, right);
        merge_asc(left, mid, right);
    }
    else
    {
        /* nothing */
    }

    return;
}

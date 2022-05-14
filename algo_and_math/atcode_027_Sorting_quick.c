#include <stdio.h>
#include <stdint.h>

#define MAX_ARRY    (200000)

enum {
    ascending,  /* 昇順 */
    descending  /* 降順 */
};

int sort_qck(uint64_t *arr, uint64_t arr_len, int order);
void sort_qck_asc(uint64_t *arr, uint64_t ul_lft_0, uint64_t ul_rght_0);
void sort_qck_des(uint64_t *arr, uint64_t ul_lft_0, uint64_t ul_rght_0);

/* 例外入力への対応は省略 */
int main(void)
{
    uint64_t ans;
    int inpt_N;
    int i;
    uint64_t arry[MAX_ARRY] = {0};


    /* get input */
    (void)scanf("%d", &inpt_N);

    for (i = 0; i < inpt_N; i++)
    {
        (void)scanf("%d", &arry[i]);
    }

    (void)sort_qck(arry, inpt_N, ascending);

    for (i = 0; i < inpt_N; i++)
    {
        (void)printf("%Lu ", arry[i]);
    }

    (void)printf("\n");

    return 0;
}

int sort_qck(uint64_t *arr, uint64_t arr_len, int order)
{
    int ret = 0;

    switch (order)
    {
        case ascending:
        sort_qck_asc(arr, 0UL, (arr_len - 1UL));
        break;
        
        case descending:
        sort_qck_des(arr, 0UL, (arr_len - 1UL));
        break;

        default:
        ret = 1;
    }
    
    return ret;
}

void sort_qck_asc(uint64_t *arr, uint64_t ul_lft_0, uint64_t ul_rght_0)
{
    /* 再帰の有無を判定 */
    if (ul_lft_0 < ul_rght_0){

        uint64_t   ul_lft  = ul_lft_0;
        uint64_t   ul_rght = ul_rght_0;
        uint64_t   ul_ppt;
        uint64_t   ppt;

        /* ピポットを算出 */
        ul_ppt  = ((ul_lft_0 + ul_rght_0) / 2UL) + 1UL; /* ここの計算はラップアラウンドに注意 */
        ppt     = arr[ul_ppt];

        while (   (ul_lft < ul_rght)
               || (arr[ul_lft] < ppt)   /* 分割位置確定条件 */
               || (arr[ul_rght] > ppt)  /* 同上 */
            ){

            if ( (arr[ul_lft] >= ppt) && (arr[ul_rght] <= ppt) ){

                /* 右と左の要素を交換 */
                arr[ul_lft] += arr[ul_rght];
                arr[ul_rght] = arr[ul_lft] - arr[ul_rght];
                arr[ul_lft] -= arr[ul_rght];

                ul_lft++;   /* 探索位置左を右に移動 */
                ul_rght--;  /* 探索位置右を左に移動 */
            }
            else {  /* 交換する要素の探索 */
                ul_lft  = ul_lft + (uint64_t)(arr[ul_lft] < ppt);
                ul_rght = ul_rght - (uint64_t)(arr[ul_rght] > ppt);
            }

        }

        sort_qck_asc(arr, ul_lft_0, (ul_lft - 1UL));    /*分割した左を再帰ソート*/
        sort_qck_asc(arr, ul_lft, ul_rght_0);           /*分割した右を再帰ソート*/

    }
    else {
        /* nothing */
    }

    return;
}

void sort_qck_des(uint64_t *arr, uint64_t ul_lft_0, uint64_t ul_rght_0)
{
    /* 再帰の有無を判定 */
    if (ul_lft_0 < ul_rght_0){

        uint64_t   ul_lft  = ul_lft_0;
        uint64_t   ul_rght = ul_rght_0;
        uint64_t   ul_ppt;
        uint64_t   ppt;

        /* ピポットを算出 */
        ul_ppt  = ((ul_lft_0 + ul_rght_0) / 2UL) + 1UL; /* ここの計算はラップアラウンドに注意 */
        ppt     = arr[ul_ppt];

        while (   (ul_lft < ul_rght)
               || (arr[ul_lft] > ppt)   /* 分割位置確定条件 */
               || (arr[ul_rght] < ppt)  /* 同上 */
            ){

            if ( (arr[ul_lft] <= ppt) && (arr[ul_rght] >= ppt) ){

                /* 右と左の要素を交換 */
                arr[ul_lft] += arr[ul_rght];
                arr[ul_rght] = arr[ul_lft] - arr[ul_rght];
                arr[ul_lft] -= arr[ul_rght];

                ul_lft++;   /* 探索位置左を右に移動 */
                ul_rght--;  /* 探索位置右を左に移動 */
            }
            else {  /* 交換する要素の探索 */
                ul_lft  = ul_lft + (uint64_t)(arr[ul_lft] > ppt);
                ul_rght = ul_rght - (uint64_t)(arr[ul_rght] < ppt);
            }

        }

        sort_qck_des(arr, ul_lft_0, (ul_lft - 1UL));    /*分割した左を再帰ソート*/
        sort_qck_des(arr, ul_lft, ul_rght_0);           /*分割した右を再帰ソート*/

    }
    else {
        /* nothing */
    }

    return;
}

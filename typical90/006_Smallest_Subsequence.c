#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_N (100000)

typedef enum
{
    e_End_,
    e_Cont_
}e_Chk_Loop_End;

char inpt_SS[(MAX_N + 1)];
char otpt_SS[(MAX_N + 1)];

e_Chk_Loop_End srch_small_Char(char *inpt_ss, char *otpt_ss, uint32_t *strt, uint32_t *rest_num, uint32_t *otpt_pnt,uint32_t len_ss);

int main(void)
{
    uint32_t inpt_ss_p = 0U;
    uint32_t otpt_ss_p = 0U;
    uint32_t inpt_N;
    uint32_t inpt_K;

    char *out_ss;
    
    /* get input */
    (void)scanf("%u%u\n", &inpt_N, &inpt_K);
    (void)scanf("%s\n", inpt_SS);

    while (e_End_ != srch_small_Char(inpt_SS, otpt_SS, &inpt_ss_p, &inpt_K, &otpt_ss_p, inpt_N)){;}

    printf("%s\n", otpt_SS);

    return 0;
}

e_Chk_Loop_End srch_small_Char(char *inpt_ss, char *otpt_ss, uint32_t *strt, uint32_t *rest_num, uint32_t *otpt_pnt,uint32_t len_ss)
{
    e_Chk_Loop_End ret = e_Cont_;
    char tmp_small = '{';
    uint32_t i;
    uint32_t tmp_pnt;
    uint32_t tmp_end = len_ss - *rest_num;

    for (i = *strt; i <= tmp_end; i++)
    {
        if (tmp_small > inpt_ss[i])
        {
            tmp_small = inpt_ss[i];
            tmp_pnt = i;
        }
        else{/*nothing*/}
    }

    otpt_ss[*otpt_pnt] = tmp_small;
    *otpt_pnt += 1U;
    *strt = (tmp_pnt + 1U);
    *rest_num -= 1U;

    if (*rest_num == 0U){ret = e_End_;}

    return ret;
}

#include <stdio.h>
#include <stdint.h>


#define MAX_N       (100)
#define MAX_W       (100000)


typedef struct load_data{
    unsigned int weight;
    unsigned int value;
}load;

static load inpt_load[MAX_N];
static uint64_t mem_val[2][MAX_W];

uint64_t srch_ans(unsigned int uppr_w, unsigned int max_N);

/* 例外入力への対応は省略 */
int main(void)
{
    
    unsigned int i;
    unsigned int inpt_N, inpt_W;
    unsigned int inpt_w, inpt_v;
    uint64_t ans;

    /* get input */
    (void)scanf("%u%u", &inpt_N, &inpt_W);

    for (i = 0U; i < inpt_N; i++)
    {
        (void)scanf("%u%u", &inpt_w, &inpt_v);
        inpt_load[i].weight = inpt_w;
        inpt_load[i].value = inpt_v;
    }

    ans = srch_ans(inpt_W, inpt_N);

    printf("%Lu\n", ans);

    return 0;
}

uint64_t srch_ans(unsigned int max_W, unsigned int max_N)
{
    uint64_t ret = 0UL;
    unsigned int wght;
    unsigned int vl;
    unsigned int i, j;
    unsigned int slct = 0U;
    unsigned int slct_old = 1U;

    for (i = 0U; i < max_N; i++)
    {
        wght = inpt_load[i].weight;
        vl = inpt_load[i].value;

        for (j = 0U; j < max_W; j++)
        {
            if (mem_val[slct_old][j] != 0UL)
            {
                if (mem_val[slct_old][j] > mem_val[slct][j])
                {
                    mem_val[slct][j] = mem_val[slct_old][j];
                }
                else{/*nothing*/}

                if ((j + wght) < max_W)
                {
                    if (mem_val[slct][(j + wght)] < (mem_val[slct_old][j] + (uint64_t)vl))
                    {
                        mem_val[slct][(j + wght)] = (mem_val[slct_old][j] + (uint64_t)vl);

                        if (mem_val[slct][(j + wght)] > ret)
                        {
                            ret = mem_val[slct][(j + wght)];
                        }
                        else{/*nothing*/}
                    }
                    else{/*nothing*/}
                }
                else{/*nothing*/}
            }
            else{/*nothing*/}

        }

        if (mem_val[slct][(wght - 1U)] < (uint64_t)vl)
        {
            mem_val[slct][(wght - 1U)] = (uint64_t)vl;

            if (vl > ret)
            {
                ret = vl;
            }
            else{/*nothing*/}
        }
        else{/*nothing*/}

        slct_old = slct;
        slct ^= 1U;
    }
    
    return ret;
}

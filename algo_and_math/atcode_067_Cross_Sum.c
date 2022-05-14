#include <stdio.h>
#include <stdint.h>

#define MAX_H (2000)
#define MAX_W (2000)

uint8_t mem_Mtrx[(MAX_H + 1)][(MAX_W + 1)];
uint32_t mem_Sum_H[(MAX_H + 1)];
uint32_t mem_Sum_W[(MAX_W + 1)];

int main(void)
{
    int32_t i, j;
    uint32_t inpt_H, inpt_W, inpt_A;
    uint32_t otpt_B;
    uint8_t *p_tmp_mem;
    uint32_t *p_tmp_H = &mem_Sum_H[0];
    uint32_t *p_tmp_W;

    /* get input */
    (void)scanf("%u%u\n", &inpt_H, &inpt_W);

    for (i = 1; i <= inpt_H; i++)
    {
        p_tmp_mem = &mem_Mtrx[i][0];
        p_tmp_H++;
        p_tmp_W = &mem_Sum_W[0];

        for (j = 1; j <= inpt_W; j++)
        {
            p_tmp_mem++;
            p_tmp_W++;
            (void)scanf("%u", &inpt_A);
            *p_tmp_mem = (uint8_t)inpt_A;
            *p_tmp_H += inpt_A;
            *p_tmp_W += inpt_A;
        }
        
        (void)scanf("\n");
    }

    for (i = 1, p_tmp_H = &mem_Sum_H[0]; i <= inpt_H; i++)
    {
        p_tmp_mem = &mem_Mtrx[i][0];
        p_tmp_H++;
        p_tmp_W = &mem_Sum_W[0];

        for (j = 1; j <= inpt_W; j++)
        {
            p_tmp_mem++;
            p_tmp_W++;
            otpt_B = *p_tmp_H + *p_tmp_W;
            otpt_B -= (uint32_t)(*p_tmp_mem);
            printf("%u ", otpt_B);
        }
        printf("\n");
    }

    return 0;
}

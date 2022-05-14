#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_N (100000)

typedef struct cnctd_point_stack{
    unsigned int cnctd_pint;
    struct cnctd_point_stack *p_next_data;
}point_stack;

typedef struct graph_cnctd_data{
    unsigned int num_of_cnctd_pnt;
    struct cnctd_point_stack *p_cncted_data;
}graph_cnctd;

graph_cnctd inpt_arr[(MAX_N + 1)];
unsigned int mem_arr[2][(MAX_N + 1)];
unsigned int chk_arr[(MAX_N + 1)];

int push_stack(graph_cnctd *pnt, unsigned int push_data);

int main(void)
{
    unsigned int i, j, k;
    unsigned int inpt_M, inpt_N;
    unsigned int inpt_A, inpt_B;
    unsigned int slct = 0U, anthr = 1U;
    unsigned int *p_mem_slct, *p_mem_nxt;
    point_stack *p_tmp;

    /* get input */
    (void)scanf("%u%u", &inpt_N, &inpt_M);

    for (i = 0U; i < inpt_M; i++)
    {
        (void)scanf("%u%u", &inpt_A, &inpt_B);
        
        if (1 == push_stack(&inpt_arr[inpt_A], inpt_B)){return 1;}
        if (1 == push_stack(&inpt_arr[inpt_B], inpt_A)){return 1;}
    }

    mem_arr[0][1] = 1U;
    chk_arr[1] = 1U;

    for (j = 1U; j < inpt_N; j++)
    {
        p_mem_slct = &mem_arr[slct][0];
        p_mem_nxt = &mem_arr[anthr][0];

        for (k = 1U; k <= inpt_N; k++)
        {
            if (p_mem_slct[k] == 1U)
            {
                p_tmp = inpt_arr[k].p_cncted_data;

                while (p_tmp != NULL)
                {
                    p_mem_nxt[p_tmp->cnctd_pint] = 1U;
                    chk_arr[p_tmp->cnctd_pint] |= 1U;
                    p_tmp = p_tmp->p_next_data;
                }

                p_mem_slct[k] = 0U;
            }
            else{/*nothing*/}
        }

        anthr = slct;
        slct ^= 1U;
    }

    for (i = 1U; i <= inpt_N; i++)
    {
        if (chk_arr[i] == 0U)
        {
            printf("The graph is not connected.\n");
            return 0;
        }
    }

    printf("The graph is connected.\n");
    return 0;
}

int push_stack(graph_cnctd *pnt, unsigned int push_data)
{
    point_stack *p_push;
    
    p_push = (point_stack *)malloc(sizeof(point_stack));

    if (p_push == (point_stack *)NULL)
    {
        return 1;
    }
    else{/* nothing */}

    p_push->p_next_data = pnt->p_cncted_data;
    p_push->cnctd_pint = push_data;

    pnt->num_of_cnctd_pnt++;
    pnt->p_cncted_data = p_push;
    
    return 0;
}


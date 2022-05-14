#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_N (100000)
#define AREA_1 (1U)

typedef struct cnctd_point_stack{
    unsigned int cnctd_pint;
    struct cnctd_point_stack *p_next_data;
}point_stack;

typedef struct graph_cnctd_data{
    unsigned int num_of_cnctd_pnt;
    unsigned int *p_area;
    struct cnctd_point_stack *p_cncted_data;
}graph_cnctd;

graph_cnctd inpt_arr[(MAX_N + 1)];

int push_stack(graph_cnctd *pnt, unsigned int push_data);

int main(void)
{
    unsigned int i, j, k;
    unsigned int inpt_M, inpt_N;
    unsigned int inpt_A, inpt_B;
    unsigned int max_A = 0U;
    const size_t uint_size = sizeof(unsigned int);
    point_stack *p_tmp;

    /* get input */
    (void)scanf("%u%u", &inpt_N, &inpt_M);

    for (i = 0U; i < inpt_M; i++)
    {
        (void)scanf("%u%u", &inpt_A, &inpt_B);
        
        max_A = (inpt_A > max_A) ? inpt_A: max_A;
        
        if (1 == push_stack(&inpt_arr[inpt_A], inpt_B)){return 1;}
        if (1 == push_stack(&inpt_arr[inpt_B], inpt_A)){return 1;}
    }

    for (j = 1U; j <= inpt_N; j++)
    {
        if ((inpt_arr[j].p_area == NULL)&&(inpt_arr[j].num_of_cnctd_pnt > 0U))
        {
            inpt_arr[j].p_area = (unsigned int*)malloc(uint_size);
            if (inpt_arr[j].p_area == NULL){return 1;}

            *inpt_arr[j].p_area = j;
        }
        else{/*nothing*/}

        p_tmp = inpt_arr[j].p_cncted_data;

        while(1)
        {
            if (p_tmp == NULL)
            {
                break;
            }
            else if (inpt_arr[p_tmp->cnctd_pint].p_area == NULL)
            {
                inpt_arr[p_tmp->cnctd_pint].p_area = inpt_arr[j].p_area;
            }
            else if (inpt_arr[p_tmp->cnctd_pint].p_area != inpt_arr[j].p_area)
            {
                if ((*inpt_arr[p_tmp->cnctd_pint].p_area == AREA_1)&&(*inpt_arr[j].p_area != AREA_1))
                {
                    *inpt_arr[j].p_area = AREA_1;
                }
                else if ((*inpt_arr[p_tmp->cnctd_pint].p_area != AREA_1)&&(*inpt_arr[j].p_area == AREA_1))
                {
                    *inpt_arr[p_tmp->cnctd_pint].p_area = AREA_1;
                }
                else if (*inpt_arr[p_tmp->cnctd_pint].p_area ){}
            }
            else
            {
                /*nothing*/
            }

            p_tmp = p_tmp->p_next_data;
        }
    }

    for (k = 1U; k <= inpt_N; k++)
    {
        if ((inpt_arr[k].p_area == NULL) || (*inpt_arr[k].p_area != AREA_1))
        {
            printf("The graph is not connected.\n");
            return 0;
        }
        else{/*nothing*/}
    }

    printf("The graph is connected.\n");
    return 0;
}

int push_stack(graph_cnctd *pnt, unsigned int push_data)
{
    point_stack *p_push;
    
    p_push = (point_stack *)malloc(sizeof(point_stack));

    if (p_push == (point_stack *)NULL){return 1;}

    p_push->p_next_data = pnt->p_cncted_data;
    p_push->cnctd_pint = push_data;

    pnt->num_of_cnctd_pnt++;
    pnt->p_cncted_data = p_push;
    
    return 0;
}

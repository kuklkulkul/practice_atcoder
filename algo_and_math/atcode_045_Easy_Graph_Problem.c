#include <stdio.h>
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

int push_stack(graph_cnctd *pnt, unsigned int push_data);

int main(void)
{
    unsigned int i, j, k;
    unsigned int ans = 0U;
    unsigned int inpt_M, inpt_N;
    unsigned int inpt_A, inpt_B;
    const size_t size_of_graph_cnctd = sizeof(graph_cnctd);
    graph_cnctd *inpt_arr;
    point_stack *p_tmp;

    /* get input */
    (void)scanf("%u%u", &inpt_N, &inpt_M);

    inpt_arr = (graph_cnctd*)malloc((size_of_graph_cnctd * (inpt_N + 1U)));
    if (NULL == inpt_arr){return 1;}

    for (i = 0U; i < inpt_M; i++)
    {
        (void)scanf("%u%u", &inpt_A, &inpt_B);
        
        if (1 == push_stack(&inpt_arr[inpt_A], inpt_B)){return 1;}
        if (1 == push_stack(&inpt_arr[inpt_B], inpt_A)){return 1;}
    }

    for (j = 1U; j <= inpt_N; j++)
    {
        p_tmp = inpt_arr[j].p_cncted_data;

        for (k = 0U; p_tmp != (point_stack *)NULL; p_tmp = p_tmp->p_next_data)
        {
            if (j > p_tmp->cnctd_pint)
            {
                k++;
            }
            else{/*nothing*/}
        }

        if (k == 1U)
        {
            ans++;
        }
        else{/*nothing*/}
    }

    printf("%u\n", ans);

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


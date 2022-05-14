#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_N (100000)
#define QUE_SIZE (MAX_N)
#define DE_QUE_FAIL ((unsigned int)(-1))

enum {NO_CHK, CHKD};
enum {FAIL_ENQUE = -1, SUCS_ENQUE};

typedef struct cnctd_point_stack{
    unsigned int cnctd_pint;
    struct cnctd_point_stack *p_next_data;
}point_stack;

typedef struct graph_cnctd_data{
    unsigned int num_of_cnctd_pnt;
    int chckd;
    int diff_frm_1;
    struct cnctd_point_stack *p_cncted_data;
}graph_cnctd;

typedef struct queue_data{
    unsigned int start;         /*0 ~ (QUE_SIZE - 1)*/
    unsigned int num_of_data;   /*0 ~ QUE_SIZE*/
    unsigned int data[QUE_SIZE];
}queue;

int push_stack(graph_cnctd *pnt, unsigned int push_data);
int enqueue(queue *que, unsigned int add_data);
unsigned int dequeue(queue *que);

queue que_chk;

int main(void)
{
    unsigned int i, j, k;
    unsigned int inpt_M, inpt_N;
    unsigned int inpt_A, inpt_B;
    unsigned int chk_pnt, next_pnt;
    unsigned int chk_num = 0U;
    const size_t size_of_graph_cnctd = sizeof(graph_cnctd);
    graph_cnctd *inpt_arr;
    point_stack *tmp_p;

    /* get input */
    (void)scanf("%u%u", &inpt_N, &inpt_M);

    inpt_arr = (graph_cnctd*)malloc((size_of_graph_cnctd * (inpt_N + 1U)));
    if (NULL == inpt_arr){return 1;}

    for (i = 0U; i <= inpt_N; i++)
    {
        inpt_arr[i].chckd = NO_CHK;
        inpt_arr[i].diff_frm_1 = -1;
        inpt_arr[i].num_of_cnctd_pnt = 0;
        inpt_arr[i].p_cncted_data = (point_stack *)NULL;
    }

    for (j = 0U; j < inpt_M; j++)
    {
        (void)scanf("%u%u", &inpt_A, &inpt_B);
        
        if (1 == push_stack(&inpt_arr[inpt_A], inpt_B)){return 1;}
        if (1 == push_stack(&inpt_arr[inpt_B], inpt_A)){return 1;}
    }

    inpt_arr[1].chckd = CHKD;
    inpt_arr[1].diff_frm_1 = 0;
    if (FAIL_ENQUE == enqueue(&que_chk, 1U)){return 1;}
    chk_num = que_chk.num_of_data;

    while (1)
    {
        while (chk_num != 0U)
        {
            chk_pnt = dequeue(&que_chk);
            if(chk_pnt == DE_QUE_FAIL){return 1;}

            tmp_p = inpt_arr[chk_pnt].p_cncted_data;

            while (tmp_p != NULL)
            {
                if (inpt_arr[tmp_p->cnctd_pint].chckd != CHKD)
                {
                    inpt_arr[tmp_p->cnctd_pint].chckd = CHKD;
                    inpt_arr[tmp_p->cnctd_pint].diff_frm_1 = inpt_arr[chk_pnt].diff_frm_1 + 1U;
                    if (FAIL_ENQUE == enqueue(&que_chk, tmp_p->cnctd_pint )){return 1;}
                }
                else if (inpt_arr[tmp_p->cnctd_pint].diff_frm_1 > (inpt_arr[chk_pnt].diff_frm_1 + 1U))
                {
                    inpt_arr[tmp_p->cnctd_pint].diff_frm_1 = inpt_arr[chk_pnt].diff_frm_1 + 1U;
                }
                else if ((inpt_arr[tmp_p->cnctd_pint].diff_frm_1 + 1U) < inpt_arr[chk_pnt].diff_frm_1)
                {
                    inpt_arr[chk_pnt].diff_frm_1 = inpt_arr[tmp_p->cnctd_pint].diff_frm_1 + 1U;
                }
                else{/*nothing*/}
                
                tmp_p = tmp_p->p_next_data;
            }

            chk_num--;
        }

        if (que_chk.num_of_data > 0U)
        {
            chk_num = que_chk.num_of_data;
        }
        else
        {
            break;
        }
        
    }

    for (k = 1U; k <= inpt_N; k++)
    {
        printf("%d\n", inpt_arr[k].diff_frm_1);
    }

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

int enqueue(queue *que, unsigned int add_data)
{
    unsigned int add_data_pstn;

    if (que->num_of_data >= QUE_SIZE)
    {
        return FAIL_ENQUE;
    }
    else{/*nothing*/}

    add_data_pstn = (que->start + que->num_of_data) % QUE_SIZE;
    que->data[add_data_pstn] = add_data;

    que->num_of_data++;

    return SUCS_ENQUE;
}

unsigned int dequeue(queue *que)
{
    unsigned int ret = DE_QUE_FAIL;
    unsigned int strt_pstn = que->start;

    if (que->num_of_data == 0U)
    {
        return ret;
    }
    else{/*nothing*/}

    ret = que->data[strt_pstn];
    strt_pstn++;
    strt_pstn %= QUE_SIZE;
    que->start = strt_pstn;
    que->num_of_data--;

    return ret;
}

#include <stdio.h>
#include <stdint.h>
#include <math.h>

enum bool_type {FALSE, TRUE} bool;
enum coord_type {X_, Y_, C_} coord;


static double inpt_A[C_];
static double inpt_B[C_];
static double inpt_C[C_];
static double vctr_BA[C_];
static double vctr_BC[C_];
static double vctr_CA[C_];

/* 例外入力への対応は省略 */
int main(void)
{  
    double ans;
    double vt_pd_nrm;
    double vt_id_BA_BC;
    double vt_id_CA_CB;
    double vt_BC_nrm;

    /* get input */
    (void)scanf("%lf%lf", &inpt_A[X_], &inpt_A[Y_]);
    (void)scanf("%lf%lf", &inpt_B[X_], &inpt_B[Y_]);
    (void)scanf("%lf%lf", &inpt_C[X_], &inpt_C[Y_]);

    vctr_BA[X_] = (inpt_A[X_] - inpt_B[X_]);
    vctr_BA[Y_] = (inpt_A[Y_] - inpt_B[Y_]);

    vctr_BC[X_] = (inpt_C[X_] - inpt_B[X_]);
    vctr_BC[Y_] = (inpt_C[Y_] - inpt_B[Y_]);

    vctr_CA[X_] = (inpt_A[X_] - inpt_C[X_]);
    vctr_CA[Y_] = (inpt_A[Y_] - inpt_C[Y_]);

    

    vt_id_BA_BC = (vctr_BA[X_] * vctr_BC[X_]) + (vctr_BA[Y_] * vctr_BC[Y_]);
    vt_id_CA_CB = - (vctr_CA[X_] * vctr_BC[X_]) - (vctr_CA[Y_] * vctr_BC[Y_]);
    
    if (vt_id_BA_BC <= 0.0)
    {
        ans = sqrt((vctr_BA[X_] * vctr_BA[X_]) + (vctr_BA[Y_] * vctr_BA[Y_]));
    }
    else if (vt_id_CA_CB <= 0.0)
    {
        ans = sqrt((vctr_CA[X_] * vctr_CA[X_]) + (vctr_CA[Y_] * vctr_CA[Y_]));
    }
    else
    {
        vt_pd_nrm = (vctr_BA[X_] * vctr_BC[Y_]) - (vctr_BA[Y_] * vctr_BC[X_]);
        
        if (vt_pd_nrm < 0.0)
        {
            vt_pd_nrm = -vt_pd_nrm;
        }
        else {/*nothing*/}
        
        vt_BC_nrm = sqrt((vctr_BC[X_] * vctr_BC[X_]) + (vctr_BC[Y_] * vctr_BC[Y_]));
        ans = vt_pd_nrm / vt_BC_nrm;
    }

    printf("%lf\n", ans);

    return 0;
}


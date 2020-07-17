#include <stdio.h>
#include <math.h>

float arb_func(float );
void rf(float*x, float x0, float x1, float fx0, float fx1, int*itr);

int main(void){

    int itr, maxitr;
    float x0, x1, x_curr, x_next, error;


    FILE * outp;
    outp = fopen("rf.txt", "w");

    printf("Enter interval values [x0, x1], allowed error and number of iterations:");
    scanf("%f %f %f %d", &x0, &x1, &error, &maxitr);

    rf(&x_curr, x0, x1, arb_func(x0), arb_func(x1), &itr);

    do {

        if(x0*x_curr<0){
            x1 = x_curr;
        }
        else {
            x0 = x_curr;
        }
        rf(&x_next, x0, x1, arb_func(x0), arb_func(x1), &itr);


        if(fabs(x_next-x_curr)<error){
            //outp = fopen("rf.txt", "w");
            printf("After %d iterations, root is %.5f ", itr, x_curr);
            //printf("After %d iterations, root is %f ", maxitr, arb_func(x_curr));
            return 0;
        } else {

            x_next = x_curr;

        }

    ++itr;

    } while(itr < maxitr);


    printf("Solution does not converge or iterations not sufficient");
    fclose(outp);

    return 1;

}


float arb_func(float x){

    x = x * log10(x) - 1.2;
    return x;
}

void rf(float*x, float x0, float x1, float fx0, float fx1, int*itr){

    *x = ((x0*fx1)-(x1*fx0))/(fx1-fx0);
    ++*itr;
    printf("Iteration %d: %.5f\n", *itr, *x);
    FILE *outp;
    outp = fopen("rf.txt", "w");
    fprintf(outp, "Iteration %.3d: %.5f\n", *itr, *x);


}

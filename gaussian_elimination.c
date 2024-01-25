#include <stdio.h>
int main(){
    // define the counter n for size of matrix, pivot for number of pivot
    int n, pivot = 0;
    // define variable temp1 for swap row, temp 2 for divisor of gaussian elimination
    double temp1, temp2;
    // input size of matrix
    printf("Enter size of equation : ");
    scanf("%d", &n);
    // define the matrix
    double a[n][n+1];
    // define the answer array
    double x[n];

    // input coefficient and constant of the matrix
    for (int i = 0; i < n; i++){
        printf("Equation %i\n", i+1);
        for (int j = 0; j < n+1; j++){
            if (j != n){
                printf("Coefficient %i : ", j+1);
            }
            else{
                printf("Constant : ");
            }
            scanf("%lf", &a[i][j]);
        }
    }
    
    // print input matrix
    printf("Input Matrix\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n+1; j++){
            printf("%.3lf ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < n; i++){
        // make value at pivot position not be negative in order to find 0 value
        if (a[i][i] < 0){
            for (int j = 0; j < n+1; j++){
                a[i][j] = -1 * a[i][j];
            }
        }

        for (int k = i+1; k < n; k++){
            // make value below the pivot position not be negative in order to find 0 value
            if (a[k][i] < 0){
                for (int j = 0; j < n+1; j++){
                    a[k][j] = -1 * a[k][j];
                }       
            }

            // try to put value 0 down by compare the value of pivot position and below value and bring down the lesser
            if (a[i][i] < a[k][i]){
                for (int j = 0; j < n+1; j++){
                    temp1 = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp1;
                }
            }
        }
            // show matrix in process
            for (int row = 0; row < n; row++) {
                for (int j = 0; j < n+1; j++) {
                    printf("%.3lf ", a[row][j]);
                }
                printf("\n");
            }
            printf("\n");
        // if the value pivot position is not zero we  begin gaussian elimination and count it as a pivot
        if (a[i][i] != 0){
            for (int m = 0; m < n ; m++){
                // make value in pivot position [i][i] be 1
                if (m == i){
                    double temp2 = a[i][i];
                    for (int j = 0; j < n+1; j++){
                        a[m][j] = a[m][j] / temp2;
                    }
                }
                // for other position in column i try to make it 0
                else{
                    // find ratio of other row in column i
                    double ratio = a[m][i] / a[i][i];
                    for (int j = 0; j < n+1; j++){
                        // multiple row i with that ratio and delete from other row
                        a[m][j] = a[m][j] - (ratio * a[i][j]);
                    }
                }
            }
        pivot = pivot + 1;
        }
    }
    // print output matrix
    printf("Output Matrix\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n+1; j++){
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    if (pivot == n){
        // assign value to solution array 
        for (int i = 0; i < n; i++){
            x[i]=a[i][n];
            printf("x%i is %.3lf\n", i+1, x[i]);
        }
    }

    else{
        // check the last constant
        // 0==0 have infinite solution
        if (a[n-1][n] != 0){
            printf("no solution");
        }
        else {
            printf("infinite solution");
        }
    }

    return 0;
}
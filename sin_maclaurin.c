#include <stdio.h>
#define pi 3.14159265358979323846

double maclaurin_sin_zero(int n, double rad_x){
    int sign = 1;
    double sum = 0, up = rad_x, down = 1;
    for (int i = 0; i < n+1; i++){
        sum = sum + sign * up / down;
        up = up * rad_x * rad_x;
        down = down * (2 * (i + 1)) * (2 * (i + 1) + 1);
        sign = -1 * sign;
    }
    return sum;
}

double deg_to_rad(double x){
    return x * pi / 180;
}

int main(){
    int x = 30;
    double sin_30_deg = 0.5;
    double rad_x = deg_to_rad(x);
    printf("%lf \n", rad_x);
    printf("Comparison of maclaurin series and real value \n");
    for (int i = 1; i < 10+1; i++){
        printf("for n = %i the different is %lf \n", i, maclaurin_sin_zero(i, rad_x) - sin_30_deg);
    }
}
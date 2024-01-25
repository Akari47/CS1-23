#include <stdio.h>
int main(){
    long double epsilon, sum, newthing = 1, fac;
    int counter = 1;
    printf("enter epsilon value : ");
    scanf("%Lf", &epsilon);
    if(epsilon >= 1){
        sum = 1;
        printf("epsilon > 1, e = %Lf", sum);
    }
    else if(epsilon < 1){
        fac = 1;
        sum = 1;
        while(newthing > epsilon){
            fac = counter*fac;
            newthing = 1/fac;
            sum = sum + newthing;
            counter = counter+1;
        }
        printf("e = %Lf", sum);
    }
    return 0;
}
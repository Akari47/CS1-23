#include <stdio.h>
int main(){
    printf("Leibniz formula for Pi\n");
    // formula name
    int i = 1, sign = 1, n;
    // name the int variable i is number of iteration, sign is the positive or negative value of each term, and n is number of iteration
    long double sum = 0, temp = 0, pi = 3.141592653589793238462643383279502884197;
    // name the float variable sum is for summation the series, temp is value of each ter, and pi is for compare to actual value
    printf("Enter number of iteration : ");
    // tell user to input iteration number
    scanf("%i", &n);
    // set value of iteration number
    while (i-1<n){
        // repeat for n time
        temp = sign * (1.0/(2*i-1));
        // calculate the new term
        sum = sum + temp;
        // add new term to the sum
        sign = -sign;
        // change sign of term
        i = i+1;
        // go to next term
    }
    sum = sum*4;
    // make the answer
    printf("Approximate number of Pi is : %.20Lf\n", sum);
    // print the calculate value to 20 decimal place
    printf("Different to actual pi is : %Lf", sum-pi);
    // print different to actual value
    return 0;
}
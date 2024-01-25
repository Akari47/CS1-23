#include <stdio.h>

int gcd(int m, int n){
    if (m == 0){
        return n;
    }
    if (m < n){
        n = n - m;
    }
    else {
        m = m - n;
    }
    gcd(m, n);
}

int main(){
    int a, b;
    printf("greatest common divisor\nplease enter two number : ");
    scanf("%d%d", &a, &b);
    printf("the answer is %i", gcd(a, b));
}
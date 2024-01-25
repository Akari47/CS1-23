#include <stdio.h>

int main(){
    int frequency[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int temp;
    int a = 1;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n%a != n){
        a *= 10;
    }
    a /= 10;
    while (a >= 1){
        temp = n / a;
        for (int i = 0; i < 10; i++){
            if (temp == digits[i]){
                frequency[i] += 1;
            }
        }
        n %= a;
        a /= 10;
    }

    for (int i = 0; i < 10; i++){
        printf("number %d appear %d times \n", digits[i], frequency[i]);
    }
}
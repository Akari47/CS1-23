#include <stdio.h>

int main() {
    char n, name;
    printf("Enter a first and last name: ");
    scanf(" %c", &name);
    while ((n = getchar()) != ' ');
    while ((n = getchar()) == ' ');
    do{
        putchar(n);
    } while ((n = getchar()) != ' ' && n != '\n');
    printf(", %c.", name);
    return 0;
}
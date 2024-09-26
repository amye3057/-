#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char a[27];
int main() {
    char* b = "abcdefghijklmnopqrstuvwxyz";
    int num = 0;

    scanf_s("%d", &num);

    if (num > 26)
        memcpy(a, b, 27);
    else
        memcpy(a, b, num+1);
    printf("%s\n", a);
    return 0;
}

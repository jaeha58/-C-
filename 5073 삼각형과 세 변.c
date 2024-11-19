#include <stdio.h>

int main() {
    int n1, n2, n3;

    while (1) {
        scanf("%d %d %d", &n1, &n2, &n3);
        if (n1 == 0 && n2 == 0 && n3 == 0) {
            break;
        }

        if (n1 == n2 && n2 == n3) {
            printf("Equilateral\n");
        }
        else if (n1 >= n2 + n3 || n2 >= n1 + n3 || n3 >= n1 + n2) {
            printf("Invalid\n");
        }
        else if (n1 == n2 || n2 == n3 || n1 == n3) {
            printf("Isosceles\n");
        }
        else {
            printf("Scalene\n");
        }

    }


    return 0;
}
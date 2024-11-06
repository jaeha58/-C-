#include<stdio.h>
int main(void) {
    int i, j, l_i, l_j;
    int max = 0;
    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= 9;j++) {
            int input;
            scanf_s("%d", &input);
            if (input > max) {
                max = input;
                l_i = i;
                l_j = j;
            }
        }
    }
    printf("%d\n%d %d", max, l_i, l_j);
}
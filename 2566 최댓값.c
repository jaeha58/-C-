#include<stdio.h>
int main(void) {
	int a[9][9];
	int i, j, max = 0, max_i, max_j;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			scanf("%d", &a[i][j]);

			if (a[i][j] >= max) {
				max = a[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}
	printf("%d\n%d %d", max, max_i + 1, max_j + 1);
	return 0;
}
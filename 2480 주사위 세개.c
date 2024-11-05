#include<stdio.h>
int main(void) {
	int A, B, C;
	scanf_s("%d %d %d", &A, &B, &C);

	if (A == B && B == C)
		printf("%d\n", 10000 + A * 1000);
	else if (A == B)
		printf("%d\n", 1000 + A * 100);
	else if (B == C)
		printf("%d\n", 1000 + B * 100);
	else if (C == A)
		printf("%d\n", 1000 + C * 100);
	else if (A > B && A > C)
		printf("%d\n", A * 100);
	else if (B > C)
		printf("%d\n", B * 100);
	else
		printf("%d\n", C * 100);
	return 0;
}
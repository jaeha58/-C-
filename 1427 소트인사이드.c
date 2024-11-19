#include<stdio.h>
#include<string.h>
int main(void) {
	char a[10];
	scanf("%s", a);
	int len = strlen(a);

	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (a[i] < a[j]) {
				int result = a[i];
				a[i] = a[j];
				a[j] = result;
			}
		}
	}
	printf("%s", a);
	return 0;
}
#include<stdio.h>
#include<string.h>
int main(void) {
	char s[1000000];
	int n[123] = { 0 };
	scanf("%s", &s);

	int i = 0;
	while (s[i] != '\0') {
		if (s[i] >= 97) n[s[i] - 32]++;
		else n[s[i]]++;
		i++;
	}
	int maxj = 0;
	int max = 0;

	for (int j = 65; j <= 90; j++) {
		if (n[j] > max) {
			max = n[j];
			maxj = j;
		}
		else if (n[j] == max) {
			maxj = 100;
		}
	}
	if (maxj == 100)printf("?");
	else printf("%c", maxj);
	return 0;
}
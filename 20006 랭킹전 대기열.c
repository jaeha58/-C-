#include<stdio.h> // �÷��̾��p, ����m, ����l, �г���n
#include<string.h>

int main() {
	int p, m; // �÷��̾��, ����
	int level[300];
	char name[300][17];
	int room[300][300];
	int room_size[300] = { 0 }; // �÷��̾� �� �迭
	int room_count = 0; // ���� ���� �迭

	scanf("%d %d", &p, &m); // �Է¹ޱ�
	for (int i = 0; i < p; i++) {
		scanf("%d %s", &level[i], name[i]);
	}
	for (int i = 0; i < p; i++) { // �÷��̾� ����
		int placed = 0;
		// �̹� ������ �濡 �÷��̾� ��ġ�� �� �ִ��� Ȯ��
		for (int j = 0; j < room_count; j++) {
			if (room_size[j] < m && level[room[j][0]] - 10 <= level[i] && level[i] <= level[room[j][0]] + 10) {
				room[j][room_size[j]++] = i;
				placed = 1;
				break;
			}
		}
		// ��� �濡 ���� ��� �۾� ����
		if (!placed) {
			room[room_count][0] = i;
			room_size[room_count++] = 1;
		}
	}
	for (int i = 0; i < room_count; i++) {
		if (room_size[i] == m) {
			printf("Started!\n");
		}
		else {
			printf("Waiting!\n");
		}
		// �ش� �濡 �ִ� �÷���� �г��� �������� ������ ����(���� ����)
		for (int j = 1; j < room_size[i]; j++) {
			for (int k = j; k > 0; k--) {
				if (strcmp(name[room[i][k - 1]], name[room[i][k]]) > 0) {
					int temp = room[i][k];
					room[i][k] = room[i][k - 1];
					room[i][k - 1] = temp;
				}
			}
		}
		// ���ĵ� ���� �÷��̾� ������ ���
		for (int j = 0; j < room_size[i]; j++) {
			printf("%d %s\n", level[room[i][j]], name[room[i][j]]);
		}
	}
	return 0;
}
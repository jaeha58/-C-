#include<stdio.h> // 플레이어수p, 정원m, 레벨l, 닉네임n
#include<string.h>

int main() {
	int p, m; // 플레이어수, 정원
	int level[300];
	char name[300][17];
	int room[300][300];
	int room_size[300] = { 0 }; // 플레이어 수 배열
	int room_count = 0; // 방의 개수 배열

	scanf("%d %d", &p, &m); // 입력받기
	for (int i = 0; i < p; i++) {
		scanf("%d %s", &level[i], name[i]);
	}
	for (int i = 0; i < p; i++) { // 플레이어 입장
		int placed = 0;
		// 이미 생성된 방에 플레이어 배치할 수 있는지 확인
		for (int j = 0; j < room_count; j++) {
			if (room_size[j] < m && level[room[j][0]] - 10 <= level[i] && level[i] <= level[room[j][0]] + 10) {
				room[j][room_size[j]++] = i;
				placed = 1;
				break;
			}
		}
		// 모든 방에 대해 출력 작업 수행
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
		// 해당 방에 있는 플레리어를 닉네임 기준으로 사전순 정렬(버블 정렬)
		for (int j = 1; j < room_size[i]; j++) {
			for (int k = j; k > 0; k--) {
				if (strcmp(name[room[i][k - 1]], name[room[i][k]]) > 0) {
					int temp = room[i][k];
					room[i][k] = room[i][k - 1];
					room[i][k - 1] = temp;
				}
			}
		}
		// 정렬된 방의 플레이어 정보를 출력
		for (int j = 0; j < room_size[i]; j++) {
			printf("%d %s\n", level[room[i][j]], name[room[i][j]]);
		}
	}
	return 0;
}
#include <stdio.h>
#include <string.h>
#include "room.h"

// 방에 플레이어를 배정하는 함수
int assign_rooms(int p, int m, int level[], int room[][300], int room_size[]) {
    int room_count = 0;

    for (int i = 0; i < p; i++) {
        int placed = 0;

        // 이미 생성된 방에 배정 가능한지 확인
        for (int j = 0; j < room_count; j++) {
            if (room_size[j] < m && level[room[j][0]] - 10 <= level[i] && level[i] <= level[room[j][0]] + 10) {
                room[j][room_size[j]++] = i;
                placed = 1;
                break;
            }
        }

        // 새로운 방 생성
        if (!placed) {
            room[room_count][0] = i;
            room_size[room_count++] = 1;
        }
    }
    return room_count;
}

// 방 정보를 출력하는 함수
void print_rooms(int room_count, int m, int level[], char name[][17], int room[][300], int room_size[]) {
    for (int i = 0; i < room_count; i++) {
        if (room_size[i] == m) {
            printf("Started!\n");
        }
        else {
            printf("Waiting!\n");
        }

        // 방 내 플레이어를 닉네임 기준으로 정렬
        for (int j = 1; j < room_size[i]; j++) {
            for (int k = j; k > 0; k--) {
                if (strcmp(name[room[i][k - 1]], name[room[i][k]]) > 0) {
                    int temp = room[i][k];
                    room[i][k] = room[i][k - 1];
                    room[i][k - 1] = temp;
                }
            }
        }

        // 방 내 플레이어 정보 출력
        for (int j = 0; j < room_size[i]; j++) {
            printf("%d %s\n", level[room[i][j]], name[room[i][j]]);
        }
    }
}

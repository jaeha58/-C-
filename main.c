#include <stdio.h>
#include "player.h"
#include "room.h"

int main() {
    int p, m;
    int level[300];
    char name[300][17];
    int room[300][300];
    int room_size[300] = { 0 };

    scanf("%d %d", &p, &m);

    // 플레이어 정보 입력
    input_players(p, level, name);

    // 방에 플레이어 배정
    int room_count = assign_rooms(p, m, level, room, room_size);

    // 방 정보 출력
    print_rooms(room_count, m, level, name, room, room_size);

    return 0;
}

#include <stdio.h>
#include "player.h"

// 플레이어 정보를 입력받는 함수
void input_players(int p, int level[], char name[][17]) {
    for (int i = 0; i < p; i++) {
        scanf("%d %s", &level[i], name[i]);
    }
}

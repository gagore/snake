#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#include "item.h"
#include "config.h"

#ifndef COLLISION_H
#define COLLISION_H

void collisionFood() {
    snakeSize ++;
    gamePoint ++;
    spawnItem();
}

void collisionWalls() {
    gmaePlay = 0;
}

// 충돌 결과 보고
int collisionCheck(int x, int y) {
    // printf("%d", gameBox[y][x].object);
    if (gameBox[y][x].object == NULL || gameBox[y][x].object == 0) {
        return 0;
    } else if (gameBox[y][x].object == 1) {
        collisionWalls();
        return 1;
    } else if (gameBox[y][x].object == 2) {
        collisionFood();
        return 0;
    } else if (gameBox[y][x].object == 20 || gameBox[y][x].object == 21) {
        return 0;
    } else {
        collisionWalls();
        return -1;
    }
    return 0;
}


#endif
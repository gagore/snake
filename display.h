#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "config.h"

#ifndef DISPLAY_H
#define DISPLAY_H

// extern boxData gameBox[GAME_BORDER_HEIGHT][GAME_BORDER_WIDTH];

void gotoxy(int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

const char* getColor(int color) {
    switch (color) {
    case 1: return "\x1b[31m";  // 빨간색
    case 2: return "\x1b[32m";  // 녹색
    case 3: return "\x1b[33m";  // 노란색
    case 4: return "\x1b[34m";  // 파란색
    case 5: return "\x1b[35m";  // 자주색
    case 6: return "\x1b[36m";  // 청록색
    case 7: return "\x1b[37m";  // 밝은 회색
    default: return "\x1b[0m";  // 색상 리셋
    }
}

const char* getObject(int type) {
    static char buffer[30];  // 정적 버퍼 선언
    switch (type) {
    case 1:
        snprintf(buffer, sizeof(buffer), "%s■%s", getColor(1), getColor(0));
        return buffer;
    case 2:
        snprintf(buffer, sizeof(buffer), "%s◈%s", getColor(3), getColor(0));
        return buffer;
    case 3:
        snprintf(buffer, sizeof(buffer), "%s●%s", getColor(2), getColor(0));
        return buffer;
    case 4:
        snprintf(buffer, sizeof(buffer), "%s▲%s", getColor(2), getColor(0));
        return buffer;
    case 5:
        snprintf(buffer, sizeof(buffer), "%s▼%s", getColor(2), getColor(0));
        return buffer;
    case 6:
        snprintf(buffer, sizeof(buffer), "%s▶%s", getColor(2), getColor(0));
        return buffer;
    case 7:
        snprintf(buffer, sizeof(buffer), "%s◀%s", getColor(2), getColor(0));
        return buffer;    
    case 8:
        snprintf(buffer, sizeof(buffer), "%s?%s", getColor(2), getColor(0));
        return buffer;    
        // △ ▲ ▽ ▼ ◁ ◀ ▷ ▶
    case 20:
        snprintf(buffer, sizeof(buffer), "%s■%s", getColor(7), getColor(0));
        return buffer;    
    case 21:
        snprintf(buffer, sizeof(buffer), "%s■%s", getColor(6), getColor(0));
        return buffer;    
    case 30:
        snprintf(buffer, sizeof(buffer), "%s■%s", getColor(1), getColor(0));
        return buffer;   
    default:
        return " ";
    }
    
}

void display_update_border(int forceUpdate) {
    boxData *p = &gameBox[0][0];
    for (int i = 0; i < GAME_BORDER_HEIGHT * GAME_BORDER_WIDTH; i++) {
        
        if (forceUpdate || p->update) {
            gotoxy(p->x, p->y);
            printf("%s", getObject(p->object));
            if (p->update != NULL) {
                p->update = 0;
            }
        }
        p ++;   
        
    }
}

void display_update_scoreBoard(int forceUpdate) {
    
    gotoxy(GAME_BORDER_WIDTH,0);
    printf("점수: %d/%d 진행시간: %.1f초            ", gamePoint, maxScore, (tick * 0.2));
    // printf("%d,%d,%d            ", snakeBody[0].x, snakeBody[0].y, tick);

}
void display_update_debug(int line, int input) {
    
    gotoxy(GAME_BORDER_WIDTH, line);
    printf("%d            ", input);
    // printf("%d,%d,%d            ", snakeBody[0].x, snakeBody[0].y, tick);

}
void boxSetup(int x, int y, int type) {
    gameBox[y][x].x = x;
    gameBox[y][x].y = y;
    gameBox[y][x].object = type;
    gameBox[y][x].update = 0;

}

void boxUpdate(int x, int y, int type) {
    gameBox[y][x].x = x;
    gameBox[y][x].y = y;
    gameBox[y][x].object = type;
    gameBox[y][x].update = 1;

}


void display_update(int forceUpdate) {
    display_update_border(forceUpdate);
    display_update_scoreBoard(forceUpdate);
    fflush(stdout);
    gotoxy(0,GAME_BORDER_HEIGHT);
}


#endif
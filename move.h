#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "config.h"
#include "collision.h"

#ifndef MOVE_H
#define MOVE_H

void Input() {
    if (kbhit()) {
        switch (getch()) {
            case 'a':
                if (moving != RIGHT) dir = LEFT;
                break;
            case 'd':
                if (moving != LEFT) dir = RIGHT;
                break;
            case 'w':
                if (moving != DOWN) dir = UP;
                break;
            case 's':
                if (moving != UP) dir = DOWN;
                break;
            case 'x':
                dir = STOP; // �Ͻ� ����
                break;
        }
    }
} 

void setSnakeHead(int x, int y, int face) {
    collisionCheck(x, y);
    // printf("%d", collisionCheck(x, y));
    snakeBody[0].x = x;
    snakeBody[0].y = y;
    boxUpdate(x, y, face);
}

void removeSnakeHead(int x, int y) {
    boxUpdate(x, y, 0);
}
int move() {
    if (dir != STOP) {
        moving = dir;
        removeSnakeHead(snakeBody[snakeSize].x, snakeBody[snakeSize].y);
        
        for (int i = snakeSize; i > 0; i--) {            
            snakeBody[i] = snakeBody[i - 1];
        }

        if (dir == UP) {
            setSnakeHead(snakeBody[1].x, snakeBody[1].y - 1, 4);
        } else if (dir == DOWN){
            setSnakeHead(snakeBody[1].x, snakeBody[1].y + 1, 5);
        } else if (dir == RIGHT){
            setSnakeHead(snakeBody[1].x + 1, snakeBody[1].y, 6);
        } else if (dir == LEFT){
            setSnakeHead(snakeBody[1].x - 1, snakeBody[1].y, 7);
        } else {
            setSnakeHead(snakeBody[1].x, snakeBody[1].y, 8);
        }
       
    }
    return 0;


}

#endif
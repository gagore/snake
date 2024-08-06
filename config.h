#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#ifndef CONFIG_H
#define CONFIG_H

#define GAME_BORDER_WIDTH 60
#define GAME_BORDER_HEIGHT 26

#define GAME_MAX_SIZE 50

typedef struct boxData {
    int x;
    int y;
    bool update;
    int object;
    
} boxData;

typedef struct snake {
    int x;
    int y;
    
} snake;

static int tick = 0;
// 게임 플레이중 변수
static int gmaePlay = 1;
static int maxScore = 5;

// 최초 길이
static int snakeSize = 5;



static snake snakeBody[GAME_MAX_SIZE];

static boxData gameBox[GAME_BORDER_HEIGHT][GAME_BORDER_WIDTH];

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
enum eDirection dir;

static enum eDirection moving = STOP;

static int gamePoint = 0;
#endif
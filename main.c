#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "display.h"
#include "config.h"
#include "item.h"
#include "move.h"

int x, y, fruitX, fruitY, score, input;
int end = 0;

void Setup() {
    // �ʱ� ����
    for (int y = 1; y < GAME_BORDER_HEIGHT - 1; y++) {
        boxSetup(GAME_BORDER_WIDTH - 1, y, 1);
        boxSetup(0, y, 1);
    }
    for (int x = 0; x < GAME_BORDER_WIDTH; x++) {
        boxSetup(x, GAME_BORDER_HEIGHT - 1, 1);
        boxSetup(x, 0, 1);
    }

    setSnakeHead(GAME_BORDER_WIDTH / 2, GAME_BORDER_HEIGHT / 2, 8);
}


int main() {
    system("cls");

    while (1) {
        printf("Enter Difficulty \n 1: Easy 2: Medium 3: Difficult\n");
        scanf("%d", &input);

        if (input == 1) {
            maxScore = 5;
            break;
        } else if (input == 2) {
            maxScore = 10;
            break;
        } else if (input == 3) {
            maxScore = 15;
            break;
        }

    }
    
    system("cls");
    Setup();
    spawnItem();
    spawnItem();
    spawnItem();
    display_update(1);
    
    while (gmaePlay) {

        if (dir != STOP) tick ++;

        Sleep(200);

        Input();
        if ((tick % (50 / (maxScore / 5))) == 1) {
            objectSpawn();
        };
        objectBuffer();

        display_update(0);        
        move();

        if (maxScore == gamePoint) {
            printf("Win!\nPress Enter to exit...");
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            getchar();
            return 0;
        }
    }
    printf("Game Over!\nPress Enter to exit...");
    getchar();
    return 0;
}


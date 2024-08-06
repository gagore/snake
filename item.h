#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "config.h"
#include "display.h"
#include <time.h>

#ifndef ITEM_H
#define ITEM_H

bool randomLoc(int *xValue, int * yValue) {
    
    int x = (rand() % (GAME_BORDER_WIDTH - 1)) + 1;
    int y = (rand() % (GAME_BORDER_HEIGHT - 1)) + 1;
    if (gameBox[y][x].object == NULL || gameBox[y][x].object == 0) {
        *xValue = x;
        *yValue = y;
        return 0;
    } else {
        return 1;
    }
    
}
typedef struct object {
    int x;
    int y;
    int value;

} object;

object tempObjects[50];

int objectBreanch(int value) {
    if (value % 2) return value + 1;
    return value - 1;
}

void objectUpdate(int x, int y, int value) {

    if (value == 1) {
        boxUpdate(x, y, 30);
    } else {
        boxUpdate(x, y, 20 + (value % 2));
    }
    
}

void objectSpawn() {
    srand(time(NULL));

    for (int i = 0; i < 10; i++ ) {
        if (tempObjects[i].value == NULL) {
            while(randomLoc(&tempObjects[i].x, &tempObjects[i].y));
            tempObjects[i].value = 20;
            return;
        };
    }
}

void objectBuffer() {
    for (int i = 0; i < 10; i++ ) {
        if (tempObjects[i].value != NULL) {

            objectUpdate(tempObjects[i].x, tempObjects[i].y, tempObjects[i].value);
            objectUpdate(objectBreanch(tempObjects[i].x), tempObjects[i].y, tempObjects[i].value);
            objectUpdate(tempObjects[i].x, objectBreanch(tempObjects[i].y), tempObjects[i].value);
        
            tempObjects[i].value --;
                        
            if (tempObjects[i].value == 0) {

                tempObjects[i].value = NULL;
            }

        };
    }

}




void spawnItem() {
    srand(time(NULL));
    int x, y;
    while(randomLoc(&x, &y));
    boxUpdate(x, y, 2);
}

#endif
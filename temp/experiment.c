#include <stdio.h>
#include <stdlib.h>
#include "temp.h"

char** gamefield;

int createGameField(){ 
    gamefield = malloc(30 * sizeof(char*));
    for (int i = 0; i < 30; i++) {
        gamefield[i] = malloc(30 * sizeof(char*));
    }

    gamefield[10][5] = '*';
    gamefield[23][1] = '#';

    return 0;
}

void main() {
    createGameField();
    // int a = substruct(2, 3);
    // printf("%i", a);
}
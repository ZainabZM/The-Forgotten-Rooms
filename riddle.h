#include "game.h"

#ifndef RIDDLE_H
#define RIDDLE_H

typedef struct
{
    char text[256];
    char answer[256];
    const char *reward;
} Riddle;

extern Riddle riddles[ROOM_COUNT];
void solve_riddle(int room_number);

#endif
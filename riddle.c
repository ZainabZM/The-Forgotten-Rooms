#include "riddle.h"
#include "game.h"
#include <stdio.h>
#include <string.h>

Riddle riddles[ROOM_COUNT] = {
    {"What has keys but can't open locks?", "piano", "Key of C"},
    {"I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?", "echo", "Whispering Wind"},
    {"What has many teeth but cannot bite?", "comb", "Grooming Tool"},
    {"I’m tall when I’m young, and I’m short when I’m old. What am I?", "candle", "Light Source"},
    {"What begins with T, ends with T, and has T in it?", "teapot", "Brewing Kit"},
    {"What has to be broken before you can use it?", "egg", "Breakfast Item"},
    {"The more you take, the more you leave behind. What am I?", "footsteps", "Tracker's Badge"},
};

void solve_riddle(int room_number) // Change to room_number for clarity
{
    Riddle riddle = riddles[room_number];
    printf("%s\n", riddle.text);

    char player_answer[256];

    fgets(player_answer, sizeof(player_answer), stdin);
    player_answer[strcspn(player_answer, "\n")] = 0;

    if (strcmp(player_answer, riddle.answer) == 0)
    {
        printf("Holy shit, you're a genius! You got it right!\n");
        pick_up_item(riddle.reward);
    }
    else
    {
        printf("Lol, nice try, but you're not as smart as you think you are.\n");
    }
}

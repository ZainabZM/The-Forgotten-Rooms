#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fight.h"

int villain_defeated = 0;

void fight_villain()
{
    if (villain_defeated)
    {
        printf("You've already wiped the floor with the villain. Nothing left to fight here.\n");
        return;
    }

    int player_health = 100;
    int villain_health = 100;
    int round = 1;
    char action[10];

    srand(time(NULL)); // Seed the random number generator

    printf("You've entered the fight arena. It's time to throw some punches, MOTHERFUCKER!\n");

    while (player_health > 0 && villain_health > 0)
    {
        printf("\n--- Round %d ---\n", round++);
        printf("Choose your action: (attack, defend, special): ");
        scanf("%s", action);

        int player_action = 0;
        int villain_action = random_action();

        // Determine player's action
        if (strcmp(action, "attack") == 0)
        {
            player_action = 1;
            printf("You go for a wild punch. Let's see if your aim's as good as your ego.\n");
        }
        else if (strcmp(action, "defend") == 0)
        {
            player_action = 2;
            printf("Playing it safe, huh? I guess cowardice is a strategy...\n");
        }
        else if (strcmp(action, "special") == 0)
        {
            player_action = 3;
            printf("Special move? Oh, here we go... Show me something impressive!\n");
        }
        else
        {
            printf("Invalid action! You stand there like an idiot. The villain laughs.\n");
        }

        // Fight logic
        if (player_action == 1 && villain_action == 1)
        {
            printf("Both of you attack simultaneously! Fists fly, insults are exchanged!\n");
            player_health -= 15;
            villain_health -= 15;
            print_narrator_comment("Ouch! That looked like it hurt... for both of you!");
        }
        else if (player_action == 1 && villain_action == 2)
        {
            printf("You attack, but the villain blocks! Ha, what did you expect?\n");
            print_narrator_comment("Come on! You hit like a toddler.");
        }
        else if (player_action == 1 && villain_action == 3)
        {
            printf("You attack, but the villain pulls a crazy move! You get hit hard!\n");
            player_health -= 25;
            villain_health -= 10;
            print_narrator_comment("Damn, you just got REKT.");
        }
        else if (player_action == 2 && villain_action == 1)
        {
            printf("You defend while the villain attacks. Smart move... for once.\n");
            player_health -= 5;
            print_narrator_comment("Better to be a chicken than a dead chicken, I guess.");
        }
        else if (player_action == 3 && villain_action == 1)
        {
            printf("You unleash your special move! The villain is caught off guard!\n");
            villain_health -= 30;
            print_narrator_comment("FINALLY! A hit worth bragging about.");
        }
        else if (player_action == 3 && villain_action == 2)
        {
            printf("You try a special move, but the villain defends. What a waste.\n");
            print_narrator_comment("Nice try, but the villain saw that coming a mile away.");
        }

        // Display health
        printf("Your health: %d | Villain's health: %d\n", player_health, villain_health);

        // End of round narrator sass
        if (player_health > 0 && villain_health > 0)
        {
            print_narrator_comment("Still alive? You might actually stand a chance... or maybe not.");
        }
    }

    // Determine outcome
    if (player_health <= 0)
    {
        printf("\nThe villain wins! You fought valiantly, but let's face it, you suck.\n");
    }
    else if (villain_health <= 0)
    {
        printf("\nYou win! The villain crumbles before your mighty fists. Congrats, badass.\n");
        villain_defeated = 1; // Mark the villain as defeated
    }
}

// Generate a random action for the villain (1 = attack, 2 = defend, 3 = special)
int random_action()
{
    return rand() % 3 + 1;
}

// Print a random sassy narrator comment
void print_narrator_comment(const char *message)
{
    printf("Narrator: %s\n", message);
}
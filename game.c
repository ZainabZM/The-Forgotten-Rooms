#include "game.h"
#include "fight.h"
#include "navigation.h"
#include "riddle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *current_room;
int treasure_found = 0;
int hidden_passage_found = 0;
int door_locked = 1;

void start_game(void)
{
    current_room = ROOM_ENTRANCE_HALL;
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        inventory[i] = NULL;
    }
    printf("Welcome to The Forgotten Rooms MOTHERFUCKER! \n");
    navigate_rooms();
    search_room();
    show_inventory();
}

void show_map(void)
{
    printf("OK MAP do your thaangggg:\n");

    printf("1. Entrance Hall\n");
    printf("   - Leads to: Library, Dining Room, Secret Chamber, Garden\n");

    printf("2. Library\n");
    printf("   - Leads to: Entrance Hall\n");
    printf("   - Description: A dusty room filled with bookshelves, a desk, and a mysterious box.\n");

    printf("3. Dining Room\n");
    printf("   - Leads to: Entrance Hall\n");
    printf("   - Description: A grand room with a large table, a cabinet, and a chandelier hanging from the ceiling.\n");

    printf("4. Secret Chamber\n");
    printf("   - Leads to: Entrance Hall\n");
    printf("   - Description: A hidden room with an old chest, an eerie painting, and a pile of bones.\n");

    printf("5. Garden\n");
    printf("   - Leads to: Entrance Hall\n");
    printf("   - Description: An overgrown garden with a bush, a fountain, and a beautiful tree.\n");

    if (hidden_passage_found)
    {
        printf("6. Mysterious Chamber\n");
        printf("   - Leads to: Secret Chamber\n");
    }
}

void pick_up_item(const char *item)
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = strdup(item);
            printf("You picked up: %s\n :)", item);

            if (strcmp(item, ITEM_BOOK) == 0)
                printf("It's an old, dusty book filled with mysterious writings.\n");
            else if (strcmp(item, ITEM_KEY) == 0)
            {
                printf("This key might unlock the Mysterious Chamber.\n");
                door_locked = 0;
            }
            else if (strcmp(item, ITEM_SWORD) == 0)
                printf("Jeez what a rusty sword...but it might still be sharp enough.\n");
            else if (strcmp(item, ITEM_POTION) == 0)
                printf("This is the Phantom Potion. It will make you invisible to the naked eye for 2 hours.\n");
            else if (strcmp(item, ITEM_TREASURE) == 0)
            {
                printf("Dammmnnn you've found a treasure! It's filled with old coins and jewels! %d more items to collect.\n", --treasure_found);
                if (treasure_found <= 0)
                {
                    printf("YOU WIN! You've collected all the treasures in the Forgotten Rooms!\n");
                    exit(0); // ENDGAME
                }
            }
            return;
        }
    }
    printf("Your inventory is full. Can't pick up more items :(\n");
}

void drop_item(void)
{
    int empty = 1;
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (inventory[i] != NULL)
        {
            empty = 0;
            break;
        }
    }

    if (empty)
    {
        printf("You ain't got shit to drop.\n");
        return;
    }

    char item_name[20];

    printf("What do you want to drop? ");
    fgets(item_name, sizeof(item_name), stdin);
    item_name[strcspn(item_name, "\n")] = 0;

    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (inventory[i] != NULL && strcmp(inventory[i], item_name) == 0)
        {
            printf("BYe BYeeee stupid %s.\n", item_name);
            inventory[i] = NULL;
            return;
        }
    }
    printf("WTF is that?\n");
}

void solve_mysterious_chamber_puzzle(void)
{
    char answer[50];

    printf("Oh great, just what we needed... A chest with a lock. Of course it's locked.\n");
    printf("Oh God there's a riddle inscribed on it:\n");
    printf("\"I speak without a mouth and hear without ears. I have no body, but I come alive with wind. What am I?\"\n");
    printf("That's something even my dog could solve... ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;

    if (strcmp(answer, "echo") == 0)
    {
        printf("Bingo! You're quite a smartass aren't you?\n");
        pick_up_item(ITEM_TREASURE);
    }
    else
    {
        printf("I don't even know what to say bro...\n");
        printf("Loud AND WRONG...\n");
    }
}

void solve_sword_puzzle(void)
{
    char answer[50];

    printf("\"What has to be broken before you can use it?\"\n");
    printf("Solve this and you will get the reward!\n");
    printf("Your answer: ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;

    if (strcmp(answer, "egg") == 0)
    {
        printf("Correct! The chest opens and inside... A GODDAMN SWORD!\n");
        pick_up_item(ITEM_SWORD);
    }
    else
    {
        printf("Wrong answer! The chest remains locked bouhouhhouuu YOU FAILURE\n");
    }
}

void enter_ancient_altar(void)
{

    printf("You find yourself in front of the Ancient Altar. The atmosphere is eerie, the whispers are almost deafening, and it’s basically a magical hotspot.\n");
    printf("A mysterious voice echoes: 'To leave this place, you must solve the riddle of the altar or defeat the guardian. Only then will the path be revealed.'\n");

    solve_ancient_altar_quest();

    // After quest, altar inaccessible
    strcpy(current_room, "");
}

void solve_ancient_altar_quest(void)
{
    int attempts = 0;
    const int max_attempts = 3;
    // Riddle time, baby!
    printf("A riddle appears on the altar: 'What has keys but can't open locks?'\n");

    while (attempts < max_attempts)
    {
        char answer[50];
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = 0;

        if (strcmp(answer, "piano") == 0)
        {
            printf("Ding ding ding! You got it right! The altar’s power fades, and a secret passage opens...\n");
            defeat_guardian();
            return;
        }
        else
        {
            attempts++;
            if (attempts < max_attempts)
            {
                printf("Nope, wrong answer. You’ve got %d attempts left, genius. Maybe try using your brain this time?\n", max_attempts - attempts);
            }
            else
            {
                printf("And... you’re out of tries. The altar stays stubborn, and you’re stuck looking like a fool. \n");
            }
        }
    }
}

void defeat_guardian(void)
{
    printf("Oh snap! A massive stone guardian just popped out of nowhere! Baby it's about to get naaaaasty...\n");

    printf("The guardian roars like it’s mad at you for some reason. Better get ready to rumble...\n");

    int player_action;
    printf("Alright, brave soul, make your move! Choose your action: 1. Attack  2. Defend\n");
    scanf("%d", &player_action);
    getchar(); // Clear the buffer because we’re neat freaks here

    if (player_action == 1)
    {
        printf("You go in for the attack, swinging like you’re auditioning for a sword-fighting movie!\n");
        printf("The guardian lets out one last dramatic roar and collapses. Victory is yours, and the way is clear!\n");
        strcpy(current_room, ROOM_ENTRANCE_HALL); // Back to the Entrance Hall, baby
    }
    else
    {
        printf("You decide to defend, which is cute. But guess what? The guardian isn’t impressed and keeps coming at you...\n");
        printf("Looks like you need to put on your big kid pants and fight harder! Try again or face the wrath...\n");
        defeat_guardian(); // Round two! You got this.
    }
}

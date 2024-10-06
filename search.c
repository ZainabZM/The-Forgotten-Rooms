#include "search.h"
#include "game.h"
#include <stdio.h>
#include <string.h>

void search_room(void)
{
    char object[20];

    if (strcmp(current_room, ROOM_ENTRANCE_HALL) == 0)
    {
        printf("You see a dusty old drawer, a coat rack, and a small table. What do you want to search MOTHERFUCKER? ");
        fgets(object, sizeof(object), stdin);
        object[strcspn(object, "\n")] = 0;

        if (strcmp(object, "drawer") == 0)
        {
            printf("OH! A flipping map! If there's a place you got to go I'm the one you need to know I'm the Map!!! \n");
            pick_up_item(ITEM_MAP);
            return;
        }
        else if (strcmp(object, "coat rack") == 0)
        {
            printf("Nothing to see here captain prick.\n");
            return;
        }
        else if (strcmp(object, "table") == 0)
        {
            printf("Hot diggity dog!\n");
            printf("NOthing!\n");
            return;
        }
        else
        {
            printf("Nothing nothing nothing nothing nothing nothing nothingnohtzzsfdzzerror404notfound........\n");
            return;
        }
    }

    if (strcmp(current_room, ROOM_LIBRARY) == 0)
    {
        printf("You see a bookshelf, a desk, and a box. What do you want to search MOTHERFUCKER? \n");
        fgets(object, sizeof(object), stdin);
        object[strcspn(object, "\n")] = 0; // Remove newline

        if (strcmp(object, "bookshelf") == 0)
        {
            printf("Oh Dear God...Do you see this wonderful totally not creepy old Book sitting there? Suits you well.\n");
            pick_up_item(ITEM_BOOK);
            return;
        }
        else if (strcmp(object, "desk") == 0)
        {
            printf("Bingo!!! You got nothing MOTHERFUCKER!\n");
            return;
        }
        else if (strcmp(object, "box") == 0)
        {
            printf("Newsflash MOTHERFUCKER! The box is...\n");
            printf("...");
            printf("...");
            printf("emptyyyyyyy GOTCHA! \n");
            return;
        }
        else
        {
            printf("The fuck you talking about?\n");
            return;
        }
    }
    else if (strcmp(current_room, ROOM_DINING_ROOM) == 0)
    {
        printf("Ok MOTHERFUCKER, we got a grand table, a cabinet, and a chandelier. Tell me? ");
        fgets(object, sizeof(object), stdin);
        object[strcspn(object, "\n")] = 0;

        if (strcmp(object, "table") == 0)
        {
            printf("I spy with my little eye....\n");
            printf("A bloody key behind the vase! LETSGOOO MOTHERFUCKER!\n");
            pick_up_item(ITEM_KEY);
            return;
        }
        else if (strcmp(object, "cabinet") == 0)
        {
            printf("I knew your intuition was bad the second you showed up..\n");
            return;
        }
        else if (strcmp(object, "chandelier") == 0)
        {
            printf("First of all, can't you see you can't reach the chandelier???\n");
            return;
        }
        else
        {
            printf("Bla bla bla call me when you get your drivers license.\n");
            return;
        }
    }
    else if (strcmp(current_room, ROOM_SECRET_CHAMBER) == 0)
    {
        printf("So we have an old chest, an ugly painting, and a pile of bones. What do you want to eat? ");
        fgets(object, sizeof(object), stdin);
        object[strcspn(object, "\n")] = 0;

        if (strcmp(object, "chest") == 0)
        {
            printf("Oh God the chest is locked! SoLvE tHiS puZzLE tO uNlOcK iT:\n");
            solve_sword_puzzle();
            return;
        }
        else if (strcmp(object, "painting") == 0)
        {
            if (!hidden_passage_found)
            {
                printf("Ain't no way! A hidden passage?! Hell nah I'm not going. Please tell me we're not going :(\n");
                hidden_passage_found = 1;
                printf("The painting slides away to reveal a secret passage! You may now explore the Mysterious Chamber.\n");
            }
            else
            {
                printf("You've already found this hidden passage. It leads to a mysterious new area...\n");
            }
        }
        else if (strcmp(object, "bones") == 0)
        {
            printf("Bones, bones and...\n");
            printf(" BONES MOTHERFUCKER!\n");
            return;
        }
        else
        {
            printf("Here we go again...with the bullshit\n");
            return;
        }
    }
    else if (strcmp(current_room, ROOM_GARDEN) == 0)
    {
        printf("Hear ye Hear ye !\n");
        printf(" We are in the presence of a holy overgrown bush, a fountain, and a beautiful tree. What do you wish to search? ");
        fgets(object, sizeof(object), stdin);
        object[strcspn(object, "\n")] = 0;

        if (strcmp(object, "bush") == 0)
        {
            printf("Welp! You found an ugly looking weird green potion hidden beneath it!\n");
            pick_up_item(ITEM_POTION);
            return;
        }
        else if (strcmp(object, "fountain") == 0)
        {
            printf("You searched the fountain but found nothing of value, kinda like you.\n");
            return;
        }
        else if (strcmp(object, "tree") == 0)
        {
            printf("Nothing to see here ma boi.\n");
            return;
        }
        else
        {
            printf("Alright this ain't funny anymore\n");
            return;
        }
    }
    else if (strcmp(current_room, ROOM_MYSTERIOUS_CHAMBER) == 0)
    {
        printf("Welcome to the Mysterious Chamber, you adventurous little rascal! It’s dark, damp, and has a vibe that’s basically saying, 'BOOOOH.'\n");
        printf("In this spooky spot, you see an old pedestal, a crumbling wall, and a strange glowing stone in the center. What do you want to mess with? ");

        fgets(object, sizeof(object), stdin);
        object[strcspn(object, "\n")] = 0;

        if (strcmp(object, "pedestal") == 0)
        {
            printf("Lookie here! On the pedestal is a dusty old scroll. Unroll it, you brave soul...\n");
            printf("Holy crap, it's a powerful incantation! Someone's been up to some magical shenanigans. You’d better take this with you!\n");
            pick_up_item(ITEM_SCROLL);
            return;
        }
        else if (strcmp(object, "wall") == 0)
        {
            printf("You give the wall a good push and—BAAAAM-a secret compartment pops open.\n");
            printf("Holy moly! A glittering gem just sitting there, like it’s waiting for you to take it. Grab it before someone else does!\n");
            pick_up_item(ITEM_GEM);
            return;
        }
        else if (strcmp(object, "stone") == 0)
        {
            printf("The stone starts glowing brighter than your future. It hums with some ancient mojo. Feeling brave, are we?\n");
            printf("Do you dare touch the glowing stone, or are you a little sissy? (yes/no): ");

            char decision[10];
            fgets(decision, sizeof(decision), stdin);
            decision[strcspn(decision, "\n")] = 0;

            if (strcmp(decision, "yes") == 0)
            {
                printf("You reach out and touch the stone. Suddenly, everything goes dark...\n");
                printf("You’re being pulled through some kind of space-time warp...\n");
                printf("And boom! You find yourself in a completely different place!\n");

                enter_ancient_altar();
            }
            else
            {
                printf("Smart move, you decide not to touch the stone. Who knows what that thing could’ve done huh?\n");
            }
            return;
        }
        else
        {
            printf("Nothing of interest here. Maybe focus on the cool stuff instead of being a lazy bum.\n");
            return;
        }
    }
    else
    {
        printf("So... basically... THERE is nothing interesting.\n");
    }
}
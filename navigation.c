#include "game.h"
#include "navigation.h"
#include "fight.h"
#include <stdio.h>
#include <string.h>

void navigate_rooms(void)
{
    char direction[20];
    int show_room_description = 1;

    while (1)
    {
        if (show_room_description)
        {
            printf("You find yourself in the %s.\n", current_room);
            show_room_description = 0;
        }

        printf("What are we doing MOTHERFUCKER? (move, inventory, drop, search, fight): ");

        fgets(direction, sizeof(direction), stdin); // User input
        direction[strcspn(direction, "\n")] = 0;    // Remove newline

        if (strcmp(direction, "Library") == 0) // Handle input
        {
            current_room = ROOM_LIBRARY;
            printf("You move into the Library.\n");
            show_room_description = 1;
        }
        else if (strcmp(direction, "Dining Room") == 0)
        {
            current_room = ROOM_DINING_ROOM;
            printf("You move into the Dining Room.\n");
            show_room_description = 1;
        }
        else if (strcmp(direction, "Secret Chamber") == 0)
        {
            current_room = ROOM_SECRET_CHAMBER;
            printf("You move into the Secret Chamber.\n");
            show_room_description = 1;
        }
        else if (strcmp(direction, "Garden") == 0)
        {
            current_room = ROOM_GARDEN;
            printf("You move into the Garden.\n");
            show_room_description = 1;
        }
        else if (strcmp(direction, "Mysterious Chamber") == 0)
        {
            if (hidden_passage_found && !door_locked)
            {
                current_room = ROOM_MYSTERIOUS_CHAMBER;
                printf("What the hell is this Mysterious Chamber? It's filled with ancient artifacts and strange symbols...\n");
                show_room_description = 1;
            }
            else
            {
                printf("The entrance to the Mysterious Chamber is blocked. You need a freaking key...\n");
                printf("GO FETCH MOTHERFUCKER");
            }
        }
        else if (strcmp(direction, "inventory") == 0)
        {
            show_inventory();
        }
        else if (strcmp(direction, "drop") == 0)
        {
            drop_item();
        }
        else if (strcmp(direction, "search") == 0)
        {
            search_room();
        }
        else if (strcmp(direction, "fight") == 0)
        {
            fight_villain();
        }
        else if (strcmp(direction, "Bye") == 0)
        {
            printf("Leaving already? Goodbye MOTHERFUCKER!\n");
            break;
        }
        else
            printf("You can't go that way MOTHERFUCKER.\n");
    }
}
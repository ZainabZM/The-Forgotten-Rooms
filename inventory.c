#include "inventory.h"
#include "game.h"
#include <stdio.h>
#include <string.h>

char *inventory[INVENTORY_SIZE];

void show_inventory(void)
{
    int empty = 1;
    printf("Inventory: \n");
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (inventory[i] != NULL)
        {
            printf("%s\n", inventory[i]);
            empty = 0;
            if (strcmp(inventory[i], ITEM_MAP) == 0)
            {
                show_map();
            }
        }
    }
    if (empty)
    {
        printf("You ain't got shit here.\n");
    }
}
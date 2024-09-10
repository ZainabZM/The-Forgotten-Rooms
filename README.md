# The-Forgotten-Rooms
Adventure Game :)

Project Name: text_adventure
Directory Name: text_adventure/

Files to Submit:
 - main.c
 - game.c
 - game.h

Mandatory Functions:
 - void start_game(void);
 - void navigate_rooms(void);
 - void show_inventory(void);
 - void pick_up_item(const char *item);

Objective:
You will create a simple text-based adventure game. The player will navigate between rooms, pick up items, and use an inventory system. The game will display room descriptions, available items, and possible exits.

Detailed Instructions:
1. start_game
 - Prototype: void start_game(void);
 - Description:
   This function will initialize the game and start the game loop. It should display an introduction, the starting room, and call navigate_rooms to allow the 
   player to begin moving between rooms.
2. navigate_rooms
 - Prototype: void navigate_rooms(void);
 - Description:
   This function will handle player movement between rooms. The player should be able to move in at least 4 directions (north, south, east, west).
3. show_inventory
 - Prototype: void show_inventory(void);
 - Description:
   This function will display the player’s current inventory (the items they have picked up so far).
4. pick_up_item
 - Prototype: void pick_up_item(const char *item);
 - Description:
   This function allows the player to pick up an item if it’s available in the current room. The item should be added to their inventory.
   
Additional Requirements:
You should have at least 4 rooms connected in some way (e.g., Living Room, Kitchen, Bedroom, Garden). Each room should have a unique description and possible exits. Each room should optionally have items that the player can pick up. The player should be able to move between rooms using simple commands (e.g., 'go north', 'go west').

Bonus Ideas:
Winning Condition: Add a goal or objective for the player, such as finding a hidden treasure or unlocking a specific door with an item.
Inventory Limit: Limit the number of items the player can carry at one time.
Enemies/Obstacles: Add simple challenges or enemies that block the player from moving freely.
Suggested Commands:
Movement: 'go north', 'go south', 'go east', 'go west'
Picking up items: 'pick up [item]'
Inventory: 'inventory'
Quitting: 'exit' or 'quit'


#ifndef GAME_H
#define GAME_H
// Constants
#define ROOM_COUNT 7
#define INVENTORY_SIZE 10
// Rooms
#define ROOM_ENTRANCE_HALL "Entrance Hall"
#define ROOM_LIBRARY "Library"
#define ROOM_DINING_ROOM "Dining Room"
#define ROOM_SECRET_CHAMBER "Secret Chamber"
#define ROOM_GARDEN "Garden"
#define ROOM_MYSTERIOUS_CHAMBER "Mysterious Chamber"
#define ROOM_ANCIENT_ALTAR "Ancient Altar"
// Items
#define ITEM_KEY "Key"
#define ITEM_BOOK "Book"
#define ITEM_SWORD "Sword"
#define ITEM_POTION "Potion"
#define ITEM_MAP "Map"
#define ITEM_TREASURE "Treasure"
#define ITEM_SCROLL "Scroll"
#define ITEM_GEM "Gem"
#define ITEM_MAGIC_SWORD "Magic Sword"
// Function prototypes
void start_game(void);
void navigate_rooms(void);
void show_inventory(void);
void pick_up_item(const char *item);
void drop_item(void);
void search_room(void);
void show_map(void);
void solve_mysterious_chamber_puzzle(void);
void solve_sword_puzzle(void);
void enter_ancient_altar(void);
void solve_ancient_altar_quest(void);
void defeat_guardian(void);
// Global variables
extern char *current_room;
extern char *inventory[INVENTORY_SIZE];
extern int hidden_passage_found;
extern int villain_defeated;
extern int door_locked;

#endif
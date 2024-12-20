#ifndef PLAYER_H
#define PLAYER_H
#include "enemy.h"
#include "projectile.h"


typedef struct Player {
    int x, y; // player position
    int health; // player health
    int score; // player score
} Player;

Player init_player(); // to initiate or create a player
void handle_player_input(Player *player, int ch, Projectile projectiles[]); // to handle player input
void update_player(Player *player, Enemy enemies[]); // to handle update based on player input
void render_player(const Player *player); // to render player based on current state

#endif
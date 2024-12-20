#ifndef ENEMY_H
#define ENEMY_H
#include <ncurses.h>
#include <stdlib.h>

typedef struct Enemy {
    int x, y; // position of the enemy
    int health; // health of the enemy
    int is_alive; // enemy status
} Enemy;

void init_enemies(Enemy enemies[]);
void update_enemies(Enemy enemies[]);
void render_enemies(const Enemy enemies[]);

#endif
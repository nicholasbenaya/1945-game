#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "enemy.h"

typedef struct Player Player;

typedef struct Projectile {
    int x,y; // position of the projectile
    int is_active; // status of the projectile
} Projectile;

void init_projectiles(Projectile projectiles[]); // projectile initialization or creation
void spawn_projectiles(Projectile projectiles[], int x, int y); // spawn projectile based on its x,y coordinate
void update_projectiles(Projectile projectiles[], Enemy enemies[], Player *player); // update projectile based on its user
void render_projectiles(const Projectile projectiles[]); // render each projectile

#endif
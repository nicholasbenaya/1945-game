#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <enemy.h>
#include <player.h>

typedef struct Projectile {
    int x,y; // position of the projectile
    int is_active; // status of the projectile
} Projectile;

void init_projectile(Projectile projectiles[]); // projectile initialization or creation
void spawn_projectile(Projectile projectiles[], int x, int y); // spawn projectile based on its x,y coordinate
void update_projectile(Projectile projectiles[], Enemy enemies[], Player *player); // update projectile based on its user
void render_projectile(const Projectile projectile); // render each projectile

#endif
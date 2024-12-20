#include "include/projectile.h"
#include "include/player.h"
#include "include/enemy.h"
#include "include/game.h"

void init_projectiles(Projectile projectiles[]) {
    for(int i = 0; i < MAX_PROJECTILES; i++) {
        projectiles[i] = (Projectile) {
            .x = 0,
            .y = 0,
            .is_active = 0
        };
    }
}

void spawn_projectile(Projectile projectiles[], int x, int y) {
    for(int i = 0; i < MAX_PROJECTILES; i++) {
        if(!projectiles->is_active) {
            projectiles[i] = (Projectile) {
                .x = x,
                .y = y,
                .is_active = 1
            };
            break;
        }
    }
}

void update_projectiles(Projectile projectiles[], Enemy enemies[], Player *player) {
    for(int i = 0; i < MAX_PROJECTILES; i++) {
        if(!projectiles[i].is_active) continue;
        if(--projectiles[i].y < 0) projectiles[i].is_active = 0;
        // still need to add collision logic here
    }
}

void render_projectiles(const Projectile projectiles[]) {
    for(int i = 0; i < MAX_PROJECTILES; i++) {
        if(projectiles[i].is_active) mvprintw(projectiles[i].y, projectiles[i].x, "|");
    }
}
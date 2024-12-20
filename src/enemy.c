#include "include/enemy.h"
#include "include/game.h"

void init_enemies(Enemy enemies[]) {
    for(int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i] = (Enemy) {
            .x = rand() % COLS,
            .y = rand() % (LINES / 2),
            .health = 1,
            .is_alive = 1
        };
    }
}

void update_enemies(Enemy enemies[]) {
    for(int i = 0; i < MAX_ENEMIES; i++) {
        if(!enemies[i].is_alive) continue;
        if(++enemies[i].y >= LINES) {
            enemies[i].y = 0;
            enemies[i].x = rand() % COLS;
        }
    }
}

void render_enemies(const Enemy enemies[]) {
    for(int i = 0; i < MAX_ENEMIES; i++) {
        if(enemies[i].is_alive) mvprintw(enemies[i].y, enemies[i].x, "E");
    }
}
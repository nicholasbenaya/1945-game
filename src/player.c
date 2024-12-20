#include "include/player.h"
#include "include/projectile.h"
#include "include/game.h"
#include "include/enemy.h"

Player init_player() {
    return (Player) {
        .x = 10,
        .y = 20,
        .health = 3,
        .score = 0
    };
    
}

void handle_player_input(Player *player, int ch, Projectile projectiles[]) {
    switch (ch) {
        case KEY_UP: 
            if(player -> y > 0) player-> y--; 
            break;
        case KEY_DOWN:
            if(player -> y < LINES - 1) player -> y++;
            break;
        case KEY_LEFT:
            if(player -> x > 0) player -> x--;
            break;
        case KEY_RIGHT:
            if(player -> x < COLS - 1) player -> x++;
            break;
        case ' ': // shooting logic
            spawn_projectile(projectiles, player->x, player->y-1);
            break;
    }
}

void update_player(Player *player, Enemy enemies[]) {
    // logic for ending the game
    if(player -> health <= 0) {
        mvprintw(LINES / 2, COLS / 2 - 10, "GAME OVER! Press 'q' to exit the game!");
    }

    // logic for player-to-enemy collision
    for(int i = 0; i < MAX_ENEMIES; i++) {
        if(enemies[i].is_alive && enemies[i].x == player->x && enemies[i].y == player->y){
            player-> health--;
            enemies[i].is_alive = 0; // Instant death of the enemy
        }
    }

}

void render_player(const Player *player) {
    mvprintw(player->y, player->x, "A");
}
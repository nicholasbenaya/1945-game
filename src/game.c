#include "include/game.h"
#include "include/player.h"
#include "include/enemy.h"
#include "include/projectile.h"
#include "include/util.h"

void start_game() {
    int ch;
    Player player = init_player();
    Enemy enemies[MAX_ENEMIES];
    Projectile projectiles[MAX_PROJECTILES];

    init_enemies(enemies);
    init_projectiles(projectiles);

    while(1) {
        
        clear();
        ch = getch();
        if(ch == 'q') break;
        handle_player_input(&player, ch, projectiles);

        update_player(&player, enemies);
        update_enemies(enemies);
        update_projectiles(projectiles, enemies, &player);

        render_player(&player);
        render_enemies(enemies);
        render_projectiles(projectiles);
        render_ui(player.health, player.score);

        refresh();
        usleep(50000);
    }
}
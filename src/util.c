#include "include/util.h"

void render_ui(int health, int score) {
    mvprintw(0, 0, "Health: %d", health);
    mvprintw(0, 20, "Score: %d", score);
}
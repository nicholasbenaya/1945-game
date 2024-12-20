#include <stdio.h>
#include <ncurses.h>

#include "include/game.h"

int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);

    start_game();

    endwin();

    return 0;
}
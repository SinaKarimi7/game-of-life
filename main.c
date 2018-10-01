/*
 * gol.c - a dead simple C implementation of Conway's game of life,
 * using ncurses.
 *
 * ncurses snippet source:
 *
 https://stackoverflow.com/questions/18458064/how-to-refresh-the-screen-continuously-and-update-it-in-real-time
 * ----------------------------------------------------------------------
 * Statement (of the problem)
 *
 * Conway's Game of Life has four rules:
 * 1) Any live cell with fewer than two live neighbors dies, as if by under
 * population.
 * 2) Any live cell with two or three live neighbors lives on to the next
 * generation.
 * 3) Any live cell with more than three live neighbors dies, as if by
 * overpopulation.
 * 4) Any dead cell with exactly three live neighbors becomes a live cell, as if
 * by reproduction.
 * ----------------------------------------------------------------------
 * Understand / Plan
 * ----------------------------------------------------------------------
 * Execute
 *
 * See below.
 * ----------------------------------------------------------------------
 * Review
 *
 * Forthcoming
 */

#include <ncurses.h>
#include <unistd.h>

#include "gol.h"

char current_gen[GRID_Y][GRID_X] = {{0}};
char next_gen[GRID_Y][GRID_X] = {{0}};

int main(int argc, char** argv) {
  useconds_t sleep_time;
  if ((sleep_time = parse_input(argc, argv)) == 0) {
    return 0;
  }

  // Init ncurses mode, hide cursor
  initscr();
  curs_set(0);

  while (1) {
    update_grid();
    print_grid();
    refresh();
    usleep(sleep_time);
  }

  // End ncurses mode and quit; this never
  // gets accessed, pragma shuts compiler up
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunreachable-code"
  endwin();
  return 0;
#pragma clang diagnostic pop
}

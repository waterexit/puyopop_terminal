#include "draw_engine.h"
#include "game/game.h"
#include <ncurses.h>
#include <time.h>

const int FLAME_RATE = 60;
const int DISPRAY_RATE = 10;

int main() {
  initscr();
  noecho();
  curs_set(0);
  cbreak();
  draw_engine draw_engine;
  mvprintw(12, 12, "hello");
  int ch = getch();
  clear();
  int i = 0;
  // int frame_clock = clock();
  clock_t display_clock = clock();
  clock_t game_clock = clock();
  game game;
  int frame;
  timeout(10);
  while (true) {
    // draw check
    clock_t current = clock();
    // mvprintw(12, 12, "clock disp:%d current:%d t/f:%lf",static_cast<int>(display_clock),static_cast<int>(current),static_cast<double>(current - display_clock) / CLOCKS_PER_SEC );
    if (static_cast<double>(current - display_clock) / CLOCKS_PER_SEC >
        (1.0 / DISPRAY_RATE)) {
      draw_engine.draw_field(game.stage);
      display_clock = clock();
    }

    if (static_cast<double>(current - game_clock) / CLOCKS_PER_SEC >
        (1.0 / FLAME_RATE)) {
      frame++;
      char c = getch();
      game.check(c, frame);
      if (c == 'q') {
        endwin();
        break;
      }
      game_clock = clock();
    }
  }
  getch();
  endwin();
}

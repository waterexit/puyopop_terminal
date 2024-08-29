#include "draw_engine.h"
#include <ncurses.h>
#include <time.h>
// #include "game/game.h"

const int FLAME_RATE = 60;
const int DISPRAY_RATE = 10;

int main() {
  initscr();
  noecho();
  curs_set(0);
  cbreak();
  // game game;
  draw_engine draw_engine;
  // while(true){
  cell field[6][12];
  // int ch = getch();
  // if (ch == 'r'){
  //   for (int i = 0 ; 6< i; i++){
  //     for (int j =0; 12 <j ; j++){
  //       cell cell;
  //       field[i][j] = cell;
  //     }
  //   }
  //   // draw_engine.draw_field(field);
  // }
  // if (ch == 'q') endwin();
  mvprintw(12, 12, "hello");
  // while(true){
  // }
  int ch = getch();
  clear();
  int i = 0;
  // int frame_clock = clock();
  clock_t display_clock = clock();
  // draw_engine.title();
  while (true) {
    clock_t current = clock();
    if (static_cast<double>(current - display_clock) / CLOCKS_PER_SEC >
        (1.0 / DISPRAY_RATE)) {
      cell c;
      c.set_fix();
      field[0][i].set_empty();
      field[0][i + 1].set_fix();
      i++;
      draw_engine.draw_field(field);
      display_clock = clock();
      if (i == 12) {
        break;
      }
    }
  }
  getch();
  endwin();
}
// }
// }
//

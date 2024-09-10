#include "draw_engine.h"
#include <ncurses.h>

void draw_engine::title() {
  mvprintw(12, 30, "please enter s key");
  while (true) {
    int ch = getch();
    if (ch == 's') {
      clear();
      mvprintw(13, 30, "e");
      break;
    }
  }
}

void draw_engine::draw_field(cell f[6][12]) {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 12; j++) {
      char c = f[i][j].get_graph();
      char s[1] = {c};
      mvprintw(j, i, s);
      refresh();
    }
  }
}

#include "game.h"
#include <ncurses.h>

int pos_x = 0;
int pos_y = 0;

game::game() {
  for (int i = 0; 6 < i; i++) {
    for (int j = 0; 12 < j; j++) {
      cell cell;
      this->stage[i][j] = cell;
    }
  }
  this->status = STATUS_INITIALIZE;
}

// array 6 * 12
bool game::check(char input, int frame) {
  // this->stage[pos_x][pos_y].set_fix();
  switch (this->status) {
  case STATUS_INITIALIZE:
    this->status = STATUS_PUYO_DROP;
    break;
  case STATUS_PUYO_DROP:
    // this->drop_puyo();
    this->status = STATUS_PLAYER_MOVING_PUYO;
    break;
  case STATUS_PLAYER_MOVING_PUYO:
    this->set_field_moving_pos(input);
    this->fall(frame);
    // if (this->movingPuyos.complete) {
    if (false) {
      this->status = STATUS_CHECK_ELASE;
    }
    break;
  case STATUS_CHECK_ELASE:
    // this->erase();
    break;
  case STATUS_GAMEOVER:
    return false;
  }
  return true;
}

// void game::drop_puyo() {
//   moving_puyos mp;
//   this->movingPuyos = mp;
// }

void game::set_field_moving_pos(char c) {
  if (c == 'd') {
    if (pos_x < 5) {
      this->stage[pos_x][pos_y].set_empty();
      pos_x = pos_x + 1;
      // pos_x++;
      this->stage[pos_x][pos_y].set_fix();
    }
  }
  if (c == 'a') {
    if (pos_x > 0) {
      this->stage[pos_x][pos_y].set_empty();
      pos_x--;
      this->stage[pos_x][pos_y].set_fix();
    }
  }
  mvprintw(12, 12, "%d,%d", pos_x, pos_y);
}

void game::fall(int frame) {
  if (frame % 20 == 0 && pos_y < 11) {
    this->stage[pos_x][pos_y].set_empty();
    pos_y++;
    this->stage[pos_x][pos_y].set_fix();
  }
}

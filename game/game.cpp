#include "game.h"

game::game(){
  for (int i = 0 ; 6< i; i++){
    for (int j =0; 12 <j ; j++){
      cell cell;
      this -> stage[i][j] = cell;
    }
  }
}

// array 6 * 12
bool game::check() {
  this->status = STATUS_INITIALIZE;
    switch (this -> status) {
      case STATUS_INITIALIZE:
        this -> status = STATUS_PUYO_DROP;
        break;
      case STATUS_PUYO_DROP:
        this -> drop_puyo();
        this -> status = STATUS_PLAYER_MOVING_PUYO;
        break;
      case STATUS_PLAYER_MOVING_PUYO:
        this -> set_field_moving_pos();
        this -> fall();
        if(this->movingPuyos.complete) {
          this->status = STATUS_CHECK_ELASE; 
        }
        break;
      case STATUS_CHECK_ELASE:
        this -> fall();
        break;
      case STATUS_GAMEOVER:
        return false;
  }

void game::drop_puyo() {
  moving_puyos mp;
  this->movingPuyos = mp;
}

void game::set_field_moving_pos() {
  
}

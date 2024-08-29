#include "falling_puyos.h"
#include "cell.h"

const int STATUS_INITIALIZE = 0;
const int STATUS_PUYO_DROP = 1;
const int STATUS_PLAYER_MOVING_PUYO = 2;
const int STATUS_CHECK_ELASE = 3;
const int STATUS_GAMEOVER = 99;
class game {
  private:
    void drop_puyo();
    void fall();
    void set_field_moving_pos();
  public:
    game();
    moving_puyos movingPuyos;
    int status;
    bool check();
    cell stage[6][12];
};

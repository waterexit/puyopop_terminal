#include "draw_engine.h"

int main(){
  draw_engine d;
  cell field[6][12];
  for (int i = 0 ; 6< i; i++){
    for (int j =0; 12 <j ; j++){
      cell cell;
      field[i][j] = cell;
    }
  }
  d.draw_field(field);
}

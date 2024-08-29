class moving_puyos {
 public:
  moving_puyos();
  int fixed_puyo_x_index;
  int fixed_puyo_y_index;
  // 'l'(-1, 0) ,'u'(0, +1), 'd'(0, -1) , 'r'(+1, 0) 
  char rotated_puyo_position;
  char fixed_puyo_color;
  char rotated_puyo_color; 
  bool complete;
  void move_x(int);
  void rotate(int);
  void set_complete_move(bool);
};

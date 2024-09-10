#ifndef cell_h
#define cell_h
class cell {
    char graph;
    char color;
  public:
    cell();
    void set_empty();
    void set_moving();
    void set_fix();
    char get_graph();
};
#endif

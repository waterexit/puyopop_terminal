#include "cell.h"

cell::cell() {
  this -> set_empty();
}

void cell::set_empty() {
  this -> graph = '.';
}

void cell::set_moving() {
  this -> graph = '[';
}

void cell::set_fix() {
  this -> graph = 'O';
}

char cell::get_graph() {
  return this -> graph;
}

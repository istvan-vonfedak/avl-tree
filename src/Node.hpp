#ifndef NODE_HPP
#define NODE_HPP
#include "Person.hpp"

struct Node {
  Node * right, * left;
  Person * person;
  int height;
  Node(Person * person);
  ~Node();
};

#endif /* NODE_HPP */

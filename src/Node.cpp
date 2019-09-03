#include "Node.hpp"

Node::Node(Person * person)
{ this->height = 1;
  this->right = NULL;
  this->left = NULL;
  this->person = person; }

// default distructor
Node::~Node()
{ this->height = 1;
  delete this->person;
  delete this->right;
  delete this->left; }


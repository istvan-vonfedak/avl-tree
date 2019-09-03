#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "Person.hpp"
#include "Node.hpp"
#include <iostream>

struct AVLTree {
  Node * root;
  AVLTree();
  ~AVLTree();
  int height(Node * node);
  int height();
  int size(Node * node);
  int size();
  Person * find(Node * node, std::string firstName, std::string lastName);
  Person * find(std::string firstName, std::string lastName);  
  int getBalance(Node * node);
  
  Node * leftRotation(Node * node);
  Node * rightRotation(Node * node);
  Node * leftDoubleRotation(Node * node);
  Node * rightDoubleRotation(Node * node);
  Node * rebalance(Node * node, Person * person);
  Node * insert(Node * node, Person * person);
  void add(Person * person);
  bool verify(Node * node);
  bool verify();

//  int calculateHeight(Node * node);
//  Node * replace(Node * node);
//  Node * remove(Node * node, std::string firstName, std::string lastName);
//  void remove(std::string firstName, std::string lastName);

};

// get the maximum number 
int max(int a, int b);

#endif /* AVLTREE_HPP */

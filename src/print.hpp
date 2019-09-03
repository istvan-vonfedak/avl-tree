#ifndef PRINT_HPP
#define PRINT_HPP
#include <iostream>
#include <iomanip>
#include "Person.hpp"
#include "Node.hpp"
#include "AVLTree.hpp"

// spaces for the separation
const int space = 4;
  
// prints a person
void printPerson(Person * person);

// print balance
void printBalance(Node * node);

// print the height of the tree
void printHeight(Node * node);

// print nodes of tree
void printNode(Node * node);

// print tree
void printAVLTree(AVLTree * tree);

// print the options for the shell
void printOptions();

#endif /* PRINT_HPP */

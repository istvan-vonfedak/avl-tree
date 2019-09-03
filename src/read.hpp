#ifndef READ_HPP
#define READ_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Person.hpp"
#include "AVLTree.hpp"

// this function will read a person from the ifstream
// and create it in the heap
// make sure to delete all persons read
Person * readPerson(std::ifstream & fin);

// read the AVL tree
AVLTree * readAVLTree(std::string fileName);

// split a line read into sub strings and construct a state
void readUserInput(std::vector<std::string> & tokens);

#endif /* READ_HPP */

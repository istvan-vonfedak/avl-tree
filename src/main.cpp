#include <string>
#include <iostream>
#include "print.hpp"
#include "AVLTree.hpp"
#include "read.hpp"
#include "shell.hpp"

const std::string fileName = "database.txt";

int main()
{ AVLTree * tree = readAVLTree(fileName);
  shell(tree); 
  return 0; }

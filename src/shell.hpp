#ifndef SHELL_HPP
#define SHELL_HPP
#include <iostream>
#include <vector>
#include "Person.hpp"
#include "AVLTree.hpp"
#include "read.hpp"
#include "print.hpp"

// makes sure that the input is correct
void doCommands(AVLTree * tree, const std::vector<std::string> & tokens);


// main shell that runs all the program
void shell(AVLTree * tree);

#endif /* SHELL_HPP */

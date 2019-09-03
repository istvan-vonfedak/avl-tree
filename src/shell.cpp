#include "shell.hpp"

// makes sure that the input is correct
void doCommands(AVLTree * tree, const std::vector<std::string> & tokens)
{ // if no tokens return
  if(tokens.size() < 1)
    return;

  // find a person in the tree
  else if(tokens[0] == "find" && tokens.size() == 3)
  { Person * found = tree->find(tokens[1], tokens[2]);
    printPerson(found); }

  // verify that the tree is balanced
  else if(tokens[0] == "verify")
  { if(tree->verify())
      std::cout<<"Successful verification\n";
    else
      std::cout<<"Unsuccessful Verification\n";
    std::cout<<"Height = "<<tree->height()<<"\n"; }

  // prints the size of the tree
  else if(tokens[0] == "size")
    std::cout<<"Size = "<<tree->size()<<"\n";

  else if(tokens[0] == "print")
    printAVLTree(tree);

  // exit the program
  else if(tokens[0] == "exit")
  { delete tree;
    exit(0); }

  // print user options
  else
    printOptions(); }

// main shell that runs all the program
void shell(AVLTree * tree)
{ // if tree is null return
  if(tree == NULL)
    return;
  // print the shell options
  printOptions();

  std::vector<std::string> tokens;
  while(true)
  { std::cout<<"> ";
    readUserInput(tokens);
    doCommands(tree, tokens); } }


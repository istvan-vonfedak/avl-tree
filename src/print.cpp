#include "print.hpp"

// prints a person
void printPerson(Person * person)
{ if(person != NULL)
  { std::cout<<person->socialSecurity<<" "<<person->day<<" "<<person->month<<" ";
    std::cout<<person->year<<" "<<person->firstName<<" "<<person->lastName<<" ";
    std::cout<<person->bankBalance<<std::endl; } }

// print balance
void printBalance(Node * node)
{ if(node == NULL)
    return;
  else if(node->left == NULL && node->right == NULL)
    std::cout<<std::setw(space)<<0<<" ";
  else if(node->left == NULL)
    std::cout<<std::setw(space)<<0 - node->right->height<<" ";
  else if(node->right == NULL)
    std::cout<<std::setw(space)<<node->left->height<<" ";
  else
  { int balance = node->left->height - node->right->height;
    std::cout<<std::setw(space)<<balance<<" "; } }

// print the height of the tree
void printHeight(Node * node)
{ if(node != NULL)
  { std::cout<<std::setw(space)<<node->height<<" "<<std::setw(space); } }

// print nodes of tree
void printNode(Node * node)
{ if(node != NULL)
  { std::cout<<std::right;
    printBalance(node);
    printHeight(node);
    printPerson(node->person);
    printNode(node->right);
    printNode(node->left); } }

// print tree
void printAVLTree(AVLTree * tree)
{ printNode(tree->root); }

// print the options for the shell
void printOptions()
{ std::cout<<"Shell command list:\n";
  std::cout<<"  find <first-name> <last-name>\n";
  std::cout<<"  verify\n";
  std::cout<<"  size\n";
  std::cout<<"  print\n";
  std::cout<<"  exit\n"; }


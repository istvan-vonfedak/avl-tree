#include "AVLTree.hpp"

// get the maximum number
int max(int a, int b)
{ return (a > b)? a: b; }

AVLTree::AVLTree()
{ this->root = NULL; }

// default destructor
AVLTree::~AVLTree()
{ delete root; }

// gets the height of the tree
int AVLTree::height(Node * node)
{ if(node == NULL)
    return 0;
  if(node->left == NULL && node->right == NULL)
    return 1;
  if(node->left == NULL)
    return 1 + node->right->height;
  if(node->right == NULL)
    return 1 + node->left->height;
  return 1 + max(node->left->height, node->right->height); }

// gets the height of the tree
int AVLTree::height()
{ return height(root); }

// gets the size of the tree
int AVLTree::size(Node * node)
{ if(node == NULL)
    return 0;
  return 1 + size(node->left) + size(node->right); }

// gets the size of the entire tree
int AVLTree::size()
{ return size(root); }

// recursively find a person in the tree
Person * AVLTree::find(Node * node, std::string firstName, std::string lastName)
{ if(node == NULL)
    return NULL;
  int comparison = compare(node->person, firstName, lastName);
  if(comparison == 0)
    return node->person;
  else if(comparison > 0)
    return find(node->left, firstName, lastName);
  else
    return find(node->right, firstName, lastName); }

// find a person in the tree
Person * AVLTree::find(std::string firstName, std::string lastName)
{ return find(root, firstName, lastName); }

// get the balance of the node
int AVLTree::getBalance(Node * node)
{ if(node == NULL)
    return 0;
  return height(node->left) - height(node->right); }

// single left rotation
Node * AVLTree::leftRotation(Node * node)
{ if(node == NULL)
    return NULL;
  if(node->right == NULL)
    return node;

  // actually move the nodes arround
  Node * newRoot = node->right;
  node->right = newRoot->left;
  newRoot->left = node;

  // update the height of both nodes
  node->height = height(node);
  newRoot->height = height(newRoot);

  return newRoot; }

// single right rotation
Node * AVLTree::rightRotation(Node * node)
{ if(node == NULL)
    return NULL;
  if(node->left == NULL)
    return node;

  // actually move the nodes arround
  Node * newRoot = node->left;
  node->left = newRoot->right;
  newRoot->right = node;

  // update the height of both nodes
  node->height = height(node);
  newRoot->height = height(newRoot);

  return newRoot; }

// double left rotation
Node * AVLTree::leftDoubleRotation(Node * node)
{ if(node == NULL)
    return NULL;
  if(node->right == NULL)
    return node;
  if(node->right->left == NULL)
    return node;
  // rotate right
  node->right = rightRotation(node->right);
  // rotate left
  node = leftRotation(node);
  return node; }

// double right rotation
Node * AVLTree::rightDoubleRotation(Node * node)
{ if(node == NULL)
    return NULL;
  if(node->left == NULL)
    return node;
  if(node->left->right == NULL)
    return node;

  // rotate left
  node->left = leftRotation(node->left);
  // rotate right
  node = rightRotation(node);
  return node; }

// this function reblances the tree if unbalanced
Node * AVLTree::rebalance(Node * node, Person * person)
{ int balance = getBalance(node);

  // no need to balance if already balanced
  if(balance > -2 && balance < 2)
    return node;

  // if inserted in node->left->right
  else if(balance == 2 && node->left->person->compare(person) < 0)
    return rightDoubleRotation(node);

  // if inserted in node->left->left
  else if(balance == 2 && node->left->person->compare(person) > 0)
    return rightRotation(node);

  // if inserted in node->right->right
  else if(balance == -2 && node->right->person->compare(person) < 0)
    return leftRotation(node);

  // if inserted in node->right->left
  else if(balance == -2 && node->right->person->compare(person) > 0)
    return leftDoubleRotation(node);

  // this condition should never be reached
  else
  { std::cout<<"Error:: rebalance::imposible condition reached\n";
    std::cout<<person->firstName<<" "<<person->lastName<<"\n";
    std::cout<<node->person->firstName<<" "<<node->person->lastName<<"\n";
    std::cout<<"balance = "<<balance<<"\n";
    std::cout<<"compare = "<<node->left->person->compare(person)<<"\n";
    delete root;
    exit(-1); } }

// inserts a person into a node
Node * AVLTree::insert(Node * node, Person * person)
{ // if tree is empty add to root
  if(node == NULL)
    return new Node(person);

  int comparison = node->person->compare(person);

  // compare the two people, if smaller add to left
  if(comparison > 0)
    node->left = insert(node->left, person);

  // if larger add to right
  else if (comparison < 0)
    node->right = insert(node->right, person);

  // you should never reach this condition
  else
  { std::cout<<"Error adding the following repeated person:\n";
    std::cout<<person->firstName<<" "<<person->lastName<<"\n";
    delete root;
    exit(-1); }

  // after insertion update height
  node->height = height(node);

  // if node is unbalanced, rebalance the node
  return rebalance(node, person); }

void AVLTree::add(Person * person)
{ root = insert(root, person); }

// verify that the tree is balanced
bool AVLTree::verify(Node * node)
{ if(node == NULL)
    return true;
  bool left = verify(node->left);
  bool right = verify(node->right);
  if(left == false || right == false)
    return false;
  int balance = getBalance(node);
  if(balance == 2 || balance == -2)
    return false;
  return true; }

// verify that the tree is perfectly balanced
bool AVLTree::verify()
{ return verify(root); }

/*
// THIS IS ALL THE NORMAL BINARY TREE DELETE CODE

// mainly used when deleting a node
// TODO make it so that I don't have to call this fucntion
//       remove should simply update the height of itself

int AVLTree::calculateHeight(Node * node)
{ if(node == NULL)
    return 0;
  int left = calculateHeight(node->left);
  int right = calculateHeight(node->right);
  node->height = 1 + max(left, right);
  return node->height; }

// this function returns a replacement for the given node
Node * AVLTree::replace(Node * node)
{ if(node == NULL)
    return NULL;
  // if left is NULL return right node
  if(node->left == NULL)
    return node->right;
  // if right node is null return left node
  if(node->right == NULL)
    return node->left;
  // if they are both equal

  // check if node->right->left == NULL
  if(node->right->left == NULL)
  { node->right->left = node->left;
    return node->right; }

  Node * parent = node->right;
  Node * newNode = node->right->left;
  while(newNode->left != NULL)
  { parent = newNode;
    newNode = newNode->left; }

  // remove the new node from parent
  parent->left = newNode->right;

  // set the newNode to have same children as node
  newNode->left = node->left;
  newNode->right = node->right;
  return newNode; }

// removes a node from the tree
Node * AVLTree::remove(Node * node, std::string firstName, std::string lastName)
{ if(node == NULL)
  { std::cout<<"Error:: remove:: "<<firstName<<" "<<lastName<<" not found.\n";
    return NULL; }
  int result = compare(node->person, firstName, lastName);
  if(result < 0)
    node->left = remove(node->left, firstName, lastName);
  else if(result > 0)
    node->right = remove(node->right, firstName, lastName);
  else
  { // find the replacement for the node
    Node * newNode = replace(node);
    // set node to null so they don't get deleted by destructor
    node->left = NULL;
    node->right = NULL;
    delete node;
    calculateHeight(newNode);
    return newNode; }
  node->height = height(node);
  return node; }

// remove item from tree
void AVLTree::remove(std::string firstName, std::string lastName)
{ root = remove(root, firstName, lastName); }

*/







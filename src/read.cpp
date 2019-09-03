#include "read.hpp"

// this function will read a person from the ifstream
// and create it in the heap
// make sure to delete all persons read
Person * readPerson(std::ifstream & fin)
{ int socialSecurity, day, month, year;
  std::string firstName, lastName;
  double bankBalance;
  fin>>socialSecurity>>day>>month>>year;
  fin>>firstName>>lastName>>bankBalance;
  if(fin.fail()) return NULL;
  return new Person(socialSecurity, day, month, year, firstName, lastName, bankBalance); }

// read the AVL tree
AVLTree * readAVLTree(std::string fileName)
{ std::ifstream fin(fileName.c_str());
  // check if file opened
  if(fin.fail())
  { std::cout<<"Error:: printReadFile:: can't open file "<<fileName<<std::endl;
    return NULL; }

  // create the tree in the heap
  AVLTree * tree = new AVLTree();

  while(true)
  { // read person
    Person * person = readPerson(fin);
    // check if person was read
    if(fin.fail() || person == NULL)
      break;

    // add it to the tree
    tree->add(person); }

  // close the file
  fin.close(); 

  // return the AVLTree
  return tree; }

// split a line read into sub strings and construct a state
void readUserInput(std::vector<std::string> & tokens)
{ // clear tokens
  tokens.clear();

  // have a temp string for input
  std::string str;

  // get the line from the user
  getline(std::cin, str);

  // prepare string stream to make tokens
  std::stringstream sline(str);

  // extract all the tokens from string
  while ( sline >> str )
    tokens.push_back(str); }


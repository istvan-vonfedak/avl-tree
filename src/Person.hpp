#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>

//struct that holds all of the information for a person
struct Person {
  int socialSecurity;
  int day, month, year;
  std::string firstName, lastName;
  double bankBalance;
  Person(int socialSecurity, int day, int month, int year,
         std::string firstName, std::string lastName, double bankBalance);

  // compares last name, then first name, then SSN
  int compare(Person * person);
};

// integer comparison
int intCompare(int a, int b);

// compare function if you just want to use the first and last names
int compare(Person * person, std::string firstName, std::string lastName);

#endif /*PERSON_HPP */

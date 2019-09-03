#include "Person.hpp"

// simple constructor
Person::Person(int socialSecurity, int day, int month, int year,
               std::string firstName, std::string lastName, double bankBalance)
{ this->socialSecurity = socialSecurity;
  this->day = day;
  this->month = month;
  this->year = year;
  this->firstName = firstName;
  this->lastName = lastName;
  this->bankBalance = bankBalance; }

// integer comparison
int intCompare(int a, int b)
{ if(a < b) return -1;
  if(a > b) return 1;
  else return 0; }

// compares last name, then first name, then SSN
int Person::compare(Person * person)
{ int result = this->lastName.compare(person->lastName);
  if(result != 0) return result;
  result = this->firstName.compare(person->firstName);
  if(result != 0) return result;
  return intCompare(this->socialSecurity, person->socialSecurity); }

// compare function if you just want to use the first and last names
int compare(Person * person, std::string firstName, std::string lastName)
{ int result = person->lastName.compare(lastName);
  if(result != 0) return result;
  else return person->firstName.compare(firstName); }

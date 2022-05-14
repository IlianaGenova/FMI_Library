#include "author.hpp"

// constructors
Author::Author(){};
Author::Author(string name, string surname)
{
  this->name = name;
  this->surname = surname;
}

// getter functions
string Author::getEntireName()
{
  return this->name + " " + this->surname;
}

string Author::getName()
{
  return this->name;
}

string Author::getSurname()
{
  return this->surname;
}



// setter functions
void Author::setName(string name)
{
  this->name = name;
}

void Author::setSurname(string surname)
{
  this->surname = surname;
}



// destructors
Author::~Author(){};

#ifndef __AUTHOR_HPP__
#define __AUTHOR_HPP__

#include "libraries.h"

class Author
{
  string name;
  string surname;

public:
Author::Author(string name, string surname)
{
  this->name = name;
  this->surname = surname;
}

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

void Author::setName(string name)
{
  this->name = name;
}

void Author::setSurname(string surname)
{
  this->surname = surname;
}
};
#endif
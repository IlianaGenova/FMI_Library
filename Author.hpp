#ifndef __AUTHOR_HPP__
#define __AUTHOR_HPP__

#include "libraries.h"

class Author
{
  string name;
  string surname;

public:
Author();
Author(string name, string surname);

string getEntireName();
string getName();
string getSurname();

void setName(string name);
void setSurname(string surname);

~Author();
};
#endif
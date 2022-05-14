#ifndef __BOOK_HPP__
#define __BOOK_HPP__

#include "libraries.h"
#include "Author.hpp"

class Book
{
  Author* author;
  string title;
  string filename;
  string description;
  float rating;
  string ISBN;

public:
// constructors
Book();
Book(string name, string surname, string title, string filename, string description, float rating, string ISBN);

Author* getAuthor();
string getTitle();
string getFilename();
string getDescription();
float getRating();
string getISBN();

void setAuthor(string name, string surname);
void setTitle(string title);
void setFilename(string filename);
void setDescription(string descriptions);
void setRating(float rating);
void setISBN(string ISBN);

~Book();
};


#endif
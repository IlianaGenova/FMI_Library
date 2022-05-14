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
  short rating;
  string ISBN;

public:
// constructors
Book::Book(){};
Book::Book(Author* author, string title, string filename, string description, short rating, string ISBN)
{
  this->author = author;
  this->title = title;
  this->filename = filename;
  this->description = description;
  this->rating = rating;
  this->ISBN = ISBN;
}



// getter functions
Author* Book::getAuthor()
{
  return this->author;
}

string Book::getTitle()
{
  return this->title;
}

string Book::getFilename()
{
  return this->filename;
}

string Book::getDescription()
{
  return this->description;
}

short Book::getRating()
{
  return this->rating;
}

string Book::getISBN()
{
  return this->ISBN;
}



// setter functions
void Book::setAuthor(Author* author)
{
  this->author = author;
}

void Book::setTitle(string title)
{
  this->title = title;
}

void Book::setFilename(string filename)
{
  this->filename = filename;
}

void Book::setDescription(string descriptions)
{
  this->description = description;
}

void Book::setRating(short rating)
{
  this->rating = rating;
}

void Book::setISBN(string ISBN)
{
   this->ISBN = ISBN;
}



// destructors
Book::~Book()
{

}
};


#endif
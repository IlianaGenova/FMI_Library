#include "Book.hpp"

// constructors
Book::Book(){};
Book::Book(string name, string surname, string title, string filename, string description, float rating, string ISBN)
{
  this->author = new Author(name, surname);
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

float Book::getRating()
{
  return this->rating;
}

string Book::getISBN()
{
  return this->ISBN;
}



// setter functions
void Book::setAuthor(string name, string surname)
{
  this->author = new Author(name, surname);
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

void Book::setRating(float rating)
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
  delete this->author;
}
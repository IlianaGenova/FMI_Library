#include "Book.hpp"

string Book::toString()
{
  ostringstream bookInfo;

  bookInfo << this->getTitle() << "\t" << this->getAuthor()->getEntireName() << "\t"
            << this->getISBN() << "\t" << this -> getRating() << "\t" << this->getDescription() << "\t" 
            << this->getFilename() << "\r\n";

  return bookInfo.str();
}

bool Book::createBook(string databaseFilename, bool willEnterBookContents)
{
  fstream file;
  file.open(databaseFilename, ios::in | ios::out | ios::app);
  
  if (!file.fail()) 
  {
    file << this->toString();
    this->createBookFile(willEnterBookContents);
    file.close();

    return true;
  }
  
  return false;
}

bool Book::deleteBook(bool shouldDeleteFile)
{
  this->~Book();

  if (shouldDeleteFile)
  {
    return this->deleteBookFile();
  }

  return true;
}



// constructors
Book::Book(){};
Book::Book(string name, string surname, string title, string filename, string description, float rating, string ISBN, string databaseFilename, bool willEnterBookContents)
{
  this->author = new Author(name, surname);
  this->title = title;
  this->filename = filename;
  this->description = description;
  this->rating = rating;
  this->ISBN = ISBN;

  this->createBook(databaseFilename, willEnterBookContents);
}



// getter functions
Author* Book::getAuthor()
{
  return this->author;
}

string Book::getAuthorName()
{
  Author* author = this->getAuthor();
  return author->getEntireName();
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
  delete this;
}


// private class functions
bool Book::createBookFile(bool hasContents)
{
  fstream file;
  file.open(this->filename, ios::in | ios::out | ios::app);
  
  if (!file.fail()) 
  {
    if (hasContents)
    {
      string line;
      cout << "You may now enter the book text. You would type type type untill you type: new line, 'exit'. Happy typing!" << endl; 
      
      do
      {
        cin >> line;
        file << line;
      } while (line != "exit");
    }

    file.close();
    return true;
  }

  return false;
}

bool Book::deleteBookFile()
{
  fstream file;
  file.open(this->filename, ios::in | ios::out | ios::trunc);
  
  if (file.good())
  {
    file.close();
    return true;
  }

  return false;
}
#ifndef __LIBRARY_HPP__
#define __LIBRARY_HPP__

#include "libraries.h"
#include "secret.h"

#include "Book.hpp"

#define DEFAULT_ROWS_TO_PRINT 10

enum PropertyType
{
  P_TITLE = 0,
  P_AUTHOR,
  P_ISBN,
  P_DESCRIPTION
};

class Library
{
  vector<Book*> books;
  int rowNumberToPrint;

  vector<Book*> sortLibraryByMethod(bool isAscending, string (Book::*method)(void));
  vector<Book*> findBooksBy(string searchString, bool isStrict, string (Book::*method)(void));

public:
  // constructor
  Library();
  // destructor
  ~Library();
  // setter and getter
  int getRowNumberToPrint();
  vector<Book*> getBooks();
  void setNumberOfRowsToPrint(int rows);
  
  bool isReaderAuthorized(string password);
  
  void Library::addBookToLibrary(string name, string surname, string title, string filename, 
        string description, float rating, string ISBN, string databaseFilename, bool willEnterBookContents);
  void removeBookFromLibrary(Book* book);

  void readBook(Book* book, bool sentenceBySentence);
  
  vector<Book*> sortLibrary(bool isAscending, PropertyType property);

  vector<Book*> findBooks(PropertyType propertyType, string property);
};

#endif
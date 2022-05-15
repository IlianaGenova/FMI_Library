#ifndef __LIBRARY_HPP__
#define __LIBRARY_HPP__

#include "libraries.h"
#include "secret.h"

#include "Book.hpp"

#define DEFAULT_ROWS_TO_PRINT 10

class Library
{
  vector<Book*> books;
  int rowNumberToPrint;

public:
  // constructor
  Library();
  // destructor
  ~Library();
  // setter and getter
  int getRowNumberToPrint();
  void setNumberOfRowsToPrint(int rows);
  
  bool isReaderAuthorized(string password);
  
  void addBookToLibrary(Book* book);
  void removeBookFromLibrary(Book* book);

  void readBook(Book* book, bool sentenceBySentence);
  
  vector<Book*> sortLibrary(bool isAscending, short property);
  vector<Book*> sortLibraryByMethod(bool isAscending, string (Book::*method)(void));

  vector<Book*> findBooks(short propertyType, string property);
  vector<Book*> findBooksBy(string searchString, bool isStrict, string (Book::*method)(void));
};

#endif
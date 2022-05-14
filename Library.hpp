#ifndef __LIBRARY_HPP__
#define __LIBRARY_HPP__

#include "libraries.h"
#include "secret.h"

#include "Book.hpp"

#define INITIAL_MAX_BOOK_COUNT 10

class Library
{
  Book* books;
  long bookCount;
  long maxBookCount;

public:
  Library()
  {
    this->bookCount = 0;
    this->maxBookCount = INITIAL_MAX_BOOK_COUNT;
    this->books = new Book[this->maxBookCount];
  };

  ~Library()
  {
    delete[] this->books;
    delete this->books;
  }
  
  bool isUserAuthorized(string password)
  {
    if (password == masterPassword)
    {
      return true;
    }

    return false;
  }


};

#endif
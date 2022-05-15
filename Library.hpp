#ifndef __LIBRARY_HPP__
#define __LIBRARY_HPP__

#include "libraries.h"
#include "secret.h"

#include "Book.hpp"

class Library
{
  vector<Book*> books;

public:
  Library(){};

  ~Library()
  {
    delete this;
  }
  
  bool addBookToLibrary(Book* book)
  {
    this->books.push_back(book);
  }

  bool isUserAuthorized(string password)
  {
    if (password == masterPassword)
    {
      return true;
    }

    return false;
  }

  vector<Book*> sortLibraryByMethod(bool isAscending, string (Book::*method)(void))
  {
    vector <Book*> sortedBooks;
    Book* temporaryBookContainer;
    
    if (this->books.size() > 0)
    {
      copy(this->books.begin(), this->books.end(), sortedBooks.begin());
      
      for (int j = 0; j < sortedBooks.size(); j++)
      {
        for (int i = 1; i < sortedBooks.size(); i++)
        {
          if ((isAscending && ((sortedBooks[j]->*method)() < (sortedBooks[j]->*method)())) ||
              (!isAscending && (sortedBooks[j]->*method)() > (sortedBooks[j]->*method)()))
          {
            temporaryBookContainer = sortedBooks[i];
            sortedBooks[i] = sortedBooks[j];
            sortedBooks[j] = sortedBooks[i];
          }
        }
        cout << sortedBooks[0]->getAuthor()->getEntireName() << endl;
      }

      return sortedBooks;
    }
  };
  
  vector<Book*> sortLibrary(bool isAscending, short property)
  {
    switch (property)
    {
      case 1:
        return sortLibraryByMethod(isAscending, &Book::getTitle);
      case 2:
        return sortLibraryByMethod(isAscending, &Book::getAuthorName);
      case 3:
        return sortLibraryByMethod(isAscending, &Book::getISBN);
      default:
        cout << "Could not find argument '" << property <<"'. \r\n Valid arguments are title, author, rating." << endl;
        break;
    }

    vector <Book*> sortedBooks;
    return sortedBooks;
  }
};

#endif
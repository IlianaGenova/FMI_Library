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
  Library(){
    this->rowNumberToPrint = DEFAULT_ROWS_TO_PRINT;
  };

  ~Library()
  {
    delete this;
  }

  int getRowNumberToPrint()
  {
    return this->rowNumberToPrint;
  }
  
  void setNumberOfRowsToPrint(int rows)
  {
    this->rowNumberToPrint = rows;
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

  void readBook(Book* book, bool sentenceBySentence)
  {
    fstream file = fstream(book->getFilename(), ios::out);
    int rowsToOutput = this->getRowNumberToPrint();
    string input, output;

    if (file.good() && file.is_open())
    {
      if (sentenceBySentence)
      {
        char character;
        
        do
        {
          do
          {
            file >> character;
            cout << character;
          } while (character != '?' && character != '.' && character!= '!');
          
          cin >> input;
        } while (input != "exit");  
      }
      else
      {
        do
        {
          for (int i = 0; i < rowsToOutput; i++)
          {
            getline(file, output);
            cout << output;
          }
          
          cin >> input;
        } while (input != "exit");     
      }
    }

    file.close();
  }

  vector<Book*> findBooksBy(string searchString, bool isStrict, string (Book::*method)(void))
  {
    vector<Book*> searchResults;

    for (int i = 0; i < this->books.size(); i++)
    {
      if (isStrict)
      {
        if((this->books[i]->*method)() == searchString)
        {
          searchResults.push_back(this->books[i]);
        }
      }
      else
      {
        if ((this->books[i]->*method)().find(searchString) != string::npos) 
        {
          searchResults.push_back(this->books[i]);
        }
      }
    }  

    return searchResults;
  }

  vector<Book*> findBooks(short propertyType, string property)
  {
    switch (propertyType)
    {
      case 1:
        return findBooksBy(property, false, &Book::getTitle);
      case 2:
        return findBooksBy(property, false, &Book::getAuthorName);
      case 3:
        return findBooksBy(property, false, &Book::getISBN);
      case 4:
        return findBooksBy(property, true, &Book::getDescription);
      default:
        cout << "Could not find book by '" << property <<"'. \r\n Valid arguments are title, author, rating, description." << endl;
        break;
    }

    vector <Book*> foundBooks;
    return foundBooks;
  }
};

#endif
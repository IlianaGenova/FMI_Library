#include "Library.hpp"

int main()
{
  Library* library = new Library();

  Book *book = new Book("Sonia", "Andreeva", "Wearing out", "WearingOut.txt", "A really great book", 4.6, "978-3-16-148410-0");
  cout << "This is it for now \r\n" << endl;
  cout << book->toString() << endl;

  book->createBook(libraryFilename, true);
}
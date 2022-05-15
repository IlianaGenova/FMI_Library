#include "Library.hpp"

int main()
{
  Library* library = new Library();
  string title, description, filename, firstName, lastName, ISBN, password;
  string stringInput;
  char charInput;
  long rating; 

  vector<Book*> books;

  cout << "Hi! Welcome to The Library? How may we help you today?" << endl;

  do
  {
    cout << "Here you can: \r\n - Read a book, by pressing R; \r\n - Find books, by pressing F \r\n - Sort books, by pressing S" << endl;
    cout << "If you have admin rights, you can also: \r\n - Add a book, by pressing A; \r\n - Delete a book, by pressing D" << endl;
    cout << "Enter your choice here: ";
    cin >> charInput;

    switch (charInput)
    {
      
      case 'A':
        cout << "Nice! We are contributing to the library! But first, we need to make sure you are authorized to do so. Enter the master password: ";
        cin >> password;

        if (library->isReaderAuthorized(password))
        {
          cout <<"Okay then - We are going to need a title: ";
          cin >> title;
          cout << "Great! And who has written it?: ";
          cin >> firstName >> lastName;
          cout << "Okay. Care to provide a short description?: ";
          cin >> description;
          cout << "Nice. We are also going to need the ISBN:";
          cin >> ISBN;
          cout << "A rating would be useful to other readers: " << endl;
          cin >> rating;
          cout << "And lastly, we are going to need a sample filename for the book to be kep under: ";
          cin >> filename;
          cout << "Great! Give me a second to write those down..." << endl;
          cout << "...Oh, and by the way, will you be providing a text for the file of the book right now, or are we creating an empty file? If empty, press E, otherwise, press W" << endl;
          
          cin >> charInput;
          cout << "Okay. I am creating the record now." << endl;
          switch (charInput)
          {
            case 'W':
              library->addBookToLibrary(firstName, lastName, title, filename, description, rating, ISBN, libraryFilename, true);
              break;
            default:
              library->addBookToLibrary(firstName, lastName, title, filename, description, rating, ISBN, libraryFilename, false);
              break;
          }

          cout << "We are ready here!";

        }
        else
        {
          cout << "What a bummer! This is not the password. You can try again the next time, in case you forgot it." << endl;
        }

        cout << endl;
        break;

      case 'R':
        break;
      case 'D':
        cout<< "Now this is sad. We are losing a book! Can we just make sure you are an admin first? Type the master password in here: ";
        cin >> password;

        if (library->isReaderAuthorized(password))
        {
          cout << "Well, I guess you really have to delete the book then. How is it called? You can only remove a book by it's complete and full title: ";
          cin >> title;
          cout << "Okay, let's see if we can find it." << endl;
          books = library->findBooks(TITLE, title);

          if (books.size() == 0)
          {
            cout << "We could not find the book. Sorry!" << endl;
            break;
          }
          else if (books.size() > 1)
          {
            cout << "We found several books with the name. We will remove one of them, considering they are the same title and ISBN" << endl;
          }
          else if (books.size() == 1)
          {
            cout << "We found the one! We will be deleting it now...We will also delete the file";
          }

          library->removeBookFromLibrary(books[0]);
        }
        else
        {
          cout << "Looks like this is not the admin password. Better luck next time!" << endl;
        }

        cout << endl;
        break;
      case 'S':
        break;
      case 'F':
        break;
      defaut:
        break;
    }
      


  } while (input != "quit");

  cout << "Well then, toodles!" << endl;
  

  Book *book = new Book("Sonia", "Andreeva", "Wearing out", "WearingOut.txt", "A really great book", 4.6, "978-3-16-148410-0", libraryFilename, false);
  cout << "This is it for now \r\n" << endl;
  cout << book->toString() << endl;

  book->createBook(libraryFilename, true);
}

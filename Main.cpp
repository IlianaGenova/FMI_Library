#include "Library.hpp"

int main()
{
  Library* library = new Library();
  stringstream sstream;
  string title, description, filename, firstName, lastName, ISBN, password;
  string stringInput;
  bool isAscending;
  char charInput;
  long rating; 
  int rows;

  vector<Book*> books;

  cout << "Hi! Welcome to The Library? How may we help you today?" << endl;

  do
  {
    cout << "Here you can: \r\n - Read a book, by pressing R; \r\n - Find books, by pressing F \r\n - Sort books, by pressing S" << endl;
    cout << "If you have admin rights, you can also: \r\n - Add a book, by pressing A; \r\n - Delete a book, by pressing D" << endl;
    cout << "You can now also leave the library, by typing 'quit'" << endl;
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

      case 'D':
        cout<< "Now this is sad. We are losing a book! Can we just make sure you are an admin first? Type the master password in here: ";
        cin >> password;

        if (library->isReaderAuthorized(password))
        {
          cout << "Well, I guess you really have to delete the book then. How is it called? You can only remove a book by it's complete and full title: ";
          cin >> title;
          cout << "Okay, let's see if we can find it." << endl;
          books = library->findBooks(P_TITLE, title);

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

      case 'R':
        cout << "Okay, we are reading a book. Type the title here: " << endl;
        cin >> title;
        cout << "Okay, let's see if we can find it." << endl;
        books = library->findBooks(P_TITLE, title);

        if (books.size() == 0)
          {
            cout << "We could not find the book. Sorry!" << endl;
            break;
          }
          else if (books.size() > 1)
          {
            cout << "We found several books with the name. We will let you read one of them, considering they are the same title and ISBN" << endl;
          }
          else if (books.size() == 1)
          {
            cout << "We found the one!";
          }

          cout << "Just to keep in mind - do you want to read it sentence by sentence or page by page? If you like sentences better, type S; otherwse, type in P: ";
          cin >> charInput;
          switch (charInput)
          {
            case 'P':
              cout << "Just a little something - the default rule of the library is to display " << DEFAULT_ROWS_TO_PRINT << " lines at once. Would you like to change it? Y/N ";
              cin >> charInput;
              switch (charInput)
              {
                case 'Y':
                  cout << "Okay. We are changing it to: ";
                  cin >> rows;
                  library->setNumberOfRowsToPrint(rows);
                  cout << "Happy reading!" <<endl;
                  break;
                case 'N':
                  cout << "Happy reading!" <<endl;
                  break;
              }

              library->readBook(books[0], false);
              break;
            case 'S':
              cout << "Okay then - happy reading!" << endl;
              library->readBook(books[0], true);
              break;
          }

        cout << endl;
        break;

      case 'S':
        cout << "Okay, we are sorting the books. (A)scending or (D)escending?";
        cin >> charInput;

        (charInput == 'A') ? isAscending = true : isAscending = false;

        cout << "By (T)itle, by (A)uthor, by part of (D)escription or by (I)SBN? : ";
        cin >> charInput;
        cout << "Lets begin the sort.";

        switch (charInput)
        {
          case 'T':
            books = library->sortLibrary(isAscending, P_TITLE);
            break;
          case 'A':
            books = library->sortLibrary(isAscending, P_AUTHOR);
            break;
          case 'I':
            books = library->sortLibrary(isAscending, P_ISBN);
            break;
        }

        cout << "Here are the results of the conducted sorting: " << endl;

        for (int i = 0; i < books.size(); i++)
        {
          cout << books[i]->toString();
        }

        break;

      case 'F':
        cout << "Okay, we are searching for a book. By (T)itle, by (A)uthor, by part of (D)escription or by (I)SBN? : ";
        
        cin >> charInput;
        cout << "Lets begin the search.";

        switch (charInput)
        {
          case 'T':
            cout << "Enter title: ";
            cin >> title;
            books = library->findBooks(P_TITLE, title);
            break;
          case 'A':
            cout << "Enter author: ";
            cin >> firstName >> lastName;
            sstream.clear();
            sstream << firstName << " " << lastName;
            books = library->findBooks(P_AUTHOR, sstream.str());
            break;
          case 'D':
            cout << "Enter part of description: ";
            cin >> description;
            books = library->findBooks(P_DESCRIPTION, description);
            break;
          case 'I':
            cout << "Enter ISBN: ";
            cin >> ISBN;
            books = library->findBooks(P_ISBN, ISBN);
            break;
        }

        cout << "Here are the results of the conducted search: " << endl;

        for (int i = 0; i < books.size(); i++)
        {
          cout << books[i]->toString();
        }

        cout << endl;
        break;

      defaut:
        break;
    }
  } while (stringInput != "quit");

  cout << "Well then, toodles!" << endl;
}

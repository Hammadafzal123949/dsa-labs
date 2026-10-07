#include <iostream>
#include <string>
using namespace std;
class Item {
public:
    virtual void display() = 0;    
    virtual string getName() = 0;
};

class Book : public Item {
    string title, author;
    int pages;
public:
    Book() {}
    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }
    string getName() {
        return title;
    }
    int getPages() {
        return pages;
    }
    void display() {
        cout << "Book: " << title
            << ", Author: " << author
            << ", Pages: " << pages << endl;
    }
};
class Newspaper : public Item {
    string name, date, edition;
public:
    Newspaper() {}
    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }
    string getName() {
        return name;
    }
    string getEdition() {
        return edition;
    }
    void display() {
        cout << "Newspaper: " << name
            << ", Date: " << date
            << ", Edition: " << edition << endl;
    }
};
template <class T>
T* linearSearch(T arr[], int size, string key) {
    for (int i = 0; i < size; i++)
        if (arr[i].getName() == key)
            return &arr[i];
    return NULL;
}
template <class T>
T* binarySearch(T arr[], int size, string key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].getName() == key)
            return &arr[mid];
        if (arr[mid].getName() < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return NULL;
}
class Library {
    Book books[10];
    Newspaper newspapers[10];
    int bookCount = 0;
    int newspaperCount = 0;
public:
    void addBook(Book b) {
        books[bookCount++] = b;
    }
    void addNewspaper(Newspaper n) {
        newspapers[newspaperCount++] = n;
    }
    void displayCollection() {
        cout << "\nBooks:\n";
        for (int i = 0; i < bookCount; i++)
            books[i].display();
        cout << "\nNewspapers:\n";
        for (int i = 0; i < newspaperCount; i++)
            newspapers[i].display();
    }
    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++)
            for (int j = 0; j < bookCount - i - 1; j++)
                if (books[j].getPages() > books[j + 1].getPages()) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
    }
    void sortNewspapers() {
        for (int i = 0; i < newspaperCount - 1; i++)
            for (int j = 0; j < newspaperCount - i - 1; j++)
                if (newspapers[j].getName() > newspapers[j + 1].getName()) {
                    Newspaper temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }
    }
    Book* searchBookByTitle(string title) {
        return linearSearch(books, bookCount, title);
    }
    Newspaper* searchNewspaperByName(string name) {
        sortNewspapers();
        return binarySearch(newspapers, newspaperCount, name);
    }
};
int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);
    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");
    Library library;
    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);
    cout << "Before Sorting:\n";
    library.displayCollection();
    library.sortBooksByPages();
    cout << "\nAfter Sorting:\n";
    library.displayCollection();
    Book* b = library.searchBookByTitle("The Catcher in the Rye");
    if (b) {
        cout << "\nBook Found:\n";
        b->display();
    }
    Newspaper* n = library.searchNewspaperByName("The Times");
    if (n) {
        cout << "\nNewspaper Found:\n";
        n->display();
    }
    return 0;
}

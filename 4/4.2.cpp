#include <iostream>
#include <cmath>
#include <string>
#define n 5

using namespace std;

struct Author{
    string Name = "Unknown";
    string Surname = "Unknown";
};

struct Book{
    string name = "Unknown";
    struct Author author;
    int year = 0;
    int pages = 0;
    void display_book(){
        cout << "Name: " << name << "\n"; 
        cout << "Author name: " << author.Name << " " << author.Surname << "\n"; 
        cout << "Year of writing: " << year << "\n"; 
        cout << "Number of pages: " << pages << "\n"; 
    }
};

struct Book create_book(){
    string bname, Name, Surname;
    int year, pages;
    cout << "Enter the book name: ";
    cin >> bname;
    cout << "\n Enter author's name and surname: ";
    cin >> Name >> Surname;
    cout << "\n Enter the year of writing: ";
    cin >> year;
    cout << "\n Enter the number of pages: ";
    cin >> pages;
    struct Book b1 = {bname, Name, Surname, year, pages};
    return b1;
}

int main(){
    //struct Book k={"m", "AS", "PUSHKIN", 12, 133};
    //cout << k.author.Surname;
    //struct Book book1 = create_book();
    //book1.display_book();
    //k.display_book();
    struct Book books[3];
    books[0]={"m", "AS", "PUSHKIN", 12, 133};
    books[1] = create_book();
    for (int i=0; i<3; i++){
        cout << "Book "<< i+1 << "\n" ;
        books[i].display_book();
    }
}
#include <iostream>
#include <string>

using namespace std;

struct Author{
    string Name = "Unknown";
    string Surname = "Unknown";
};

struct Book{
    string bookname = "Unknown";
    struct Author author;
    int date = 0;
    int pages = 0;
};

int main(){
    struct Book 1;
cout << Book.author;
}

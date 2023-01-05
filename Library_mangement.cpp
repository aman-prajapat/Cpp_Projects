#include <iostream>
using namespace std;
#define MAX 10
#include <iomanip>
class Book
{

    int id;
    int price;          //friend,classes,goto,preprocessor,object arry
    string name;
    string author;
    int pages;
    friend int search(int, Book[], int);
    friend void ShowBooks(Book[], int);

public:
    void entry()
    {
        cin.clear();
        cin.ignore(1000,'\n');

        cout << "Enter Name of the book : ";
        getline(cin,name);
        
        cout << "\nEnter Author Name of the book : ";
        cin >> author;
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "\nEnter ID of the book : ";
        cin >> id;
        cout << "\nEnter Pages of the book : ";
        cin >> pages;
        cout << "\nEnter Price of the book : ";
        cin >> price;
    }

    void copy(Book obj)
    {
        name = obj.name;
        id = obj.id;
        pages = obj.pages;
        price = obj.price;
        author = obj.author;
    }

    void Display()
    {
        cout << "\n Name of the book : " << name;
        cout << "\n Author Name of the book : " << author;
        cout << "\n ID of the book : " << id;
        cout << "\n Pages of the book : " << pages;
        cout << "\n Price of the book : " << price;
    }
};

void del(int idD, int count, Book obj[])
{
    while (idD != count)
    {
        obj[idD].copy(obj[idD + 1]);
        idD++;
    }

    cout << "****Book Deleted****" << endl;
}

int search(int idD, Book obj[], int count)
{
    while (count--)
    {
        if (obj[count].id == idD)
            return count;
    }
    cout << "No book with this Id found!" << endl;
    return -1;
}

void ShowBooks(Book obj[], int count)
{
    cout << "\n**************************************************" << endl;
    cout<<"Name\t\t\t\t" << "ID" << endl;
    int i = 0;
    while (i != count)
    {
        cout << obj[i].name << "\t\t\t" <<obj[i].id << endl;
        i++;
    }
}
int main()
{
    int count = 0, input;

    Book lib[MAX];

lable:
    cout << "\n**************************************************" << endl;
    cout << "******************BOOK LIBRARY********************\n\n"
         << endl;
    cout << "\t\t=> 1. for Book Entry" << endl;
    cout << "\t\t=> 2. for Book Delete" << endl;
    cout << "\t\t=> 3. for Book Search" << endl;
    cout << "\t\t=> 4. to show all Books" << endl;
    cout << "\t\t=> 5. to teminate" << endl;
    cout << "\n**************************************************" << endl;
    cin >> input;

    switch (input)
    {
    case 1:
        if (count == MAX)
        {
            cout << "No space to ADD" << endl;
            break;
        }
        lib[count].entry();
        count++;
        cout << "Book successfully addded\n\n"
             << endl;
        break;
    case 2:
        int idD;
        cout << "Enter Id of the book" << endl;
        cin >> idD;

        idD = search(idD, lib, count);
        if (idD != -1)
        {
            del(idD, count, lib);
            count--;
        }

        break;
    case 3:
        int iDS;
        cout << "Enter ID of Book to be search" << endl;
        cin >> iDS;

        iDS = search(iDS, lib, count);
        if (iDS != -1)
        {
            lib[iDS].Display();
        }

        break;
    case 4:

        ShowBooks(lib, count);

        break;

    default:
        if(input != 5)
        cout << "Input is invalid" << endl;
        break;
    }

    if (input != 5)
        goto lable;

    return 0;
}
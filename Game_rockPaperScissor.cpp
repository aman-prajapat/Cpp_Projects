#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

int random()
{
    srand(time(NULL));
    return ((rand() % 3) + 1);
}

void game(int pc, int player, char name[])
{
    switch (player)
    {
    case 1:
        if (pc == 1)
        {
            cout << "Draw" << endl;
        }
        else if (pc == 2)
        {
            cout << "YOU LOSS" << endl;
        }
        else
        {
            cout << name << " win!!!" << endl;
        }
        break;
    case 2:
        if (pc == 2)
        {
            cout << "Draw" << endl;
        }
        else if (pc == 3)
        {
            cout << "YOU LOSS" << endl;
        }
        else
        {
            cout << name << " win!!!" << endl;
        }
        break;
    case 3:
        if (pc == 3)
        {
            cout << "Draw" << endl;
        }
        else if (pc == 1)
        {
            cout << "YOU LOSS" << endl;
        }
        else
        {
            cout << name << " win!!!" << endl;
        }
        break;
    }
}

int main()
{
    int a;
    char name[20];
    cout << "Enter your name : ";
    gets(name);
    cout << "Enter : \n 1 for Rock \n 2 for paper \n 3 for scissors\n";
    cin >> a;
    int ran = random();

    game(ran, a, name);

    return 0;
}

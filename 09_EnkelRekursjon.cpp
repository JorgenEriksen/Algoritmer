

#include <iostream>
using namespace std;

const int MAXCALL = 5;

void display1(int n)
{
    cout << n << ' ';
    if (n < MAXCALL)
        display1(n + 1);
}

void display2a(int n)
{
    cout << n << ' ';
    cout << n + 100 << ' ';
    if (n < MAXCALL)
        display2a(n + 1);
}

void display2b(int n)
{
    cout << n << ' ';
    if (n < MAXCALL)
        display2b(n + 1);
    cout << n + 100 << ' ';
}

void display3(int n)
{
    if (n <= MAXCALL * 2)
    {
        char ch;
        cin >> ch;
        display3(n + 1);
        cout << ch << ' ';
    }
    else
        cout << "\n\n";
}

void display4(int n)
{
    cout << n << ' ';
    display4(n + 1);
}

int main()
{
    char tegn;

    cout << "\nskriv og deretter REKURSJON:\n\t";
    display1(1);
    cin >> tegn;

    cout << "\nskriv, skriv og deretter REKURSJON:\n\t";
    display2a(1);
    cin >> tegn;

    cout << "\nskriv, REKURSJON og deretter skriv:\n\t";
    display2b(1);
    cin >> tegn;

    cout << "\nSkriv inn " << MAXCALL * 2 << " tegn "
         << "(lese tegn og skrive dem baklengs ut igjen):\n\t";
    display3(1);
    cin >> tegn;

    cout << "\nREKURSJON uten stoppbetingelse:\n";
    display4(1);

    cout << "\n\n";
    return 0;
}

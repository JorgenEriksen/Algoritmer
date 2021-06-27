

#include <iostream>
#include <string>
using namespace std;

int fakultet(int n)
{
    if (n <= 1)
        return 1;
    return n * fakultet(n - 1);
}

int fibonacci(int n)
{
    if (n <= 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void reverser(string &s, const int left, const int right)
{
    if (left < right)
    {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        reverser(s, left + 1, right - 1);
    }
}

int main()
{

    string tekst = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    cout << "\n\nTeksten:         " << tekst << '\n';
    reverser(tekst, 0, tekst.length() - 1);
    cout << "Snudd baklengs:  " << tekst << '\n';

    cout << "\n\n5! er:     " << fakultet(5) << '\n';

    cout << "\n\nFibonacci-tall nr.4 er:     " << fibonacci(4) << "\n\n\n";

    return 0;
}

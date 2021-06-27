

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

int snuOppNedA(int n)
{
    int siffer,
        tall = 0;

    while (n > 0)
    {
        siffer = n % 10;
        n = n / 10;
        if (siffer == 6)
            siffer = 9;
        else if (siffer == 9)
            siffer = 6;

        else if (siffer != 0 && siffer != 1 && siffer != 8)
            return 0;
        tall = tall * 10 + siffer;
    }
    return tall;
}

int snuOppNedB(const int n)
{
    char tekst[7];
    int i,
        len,
        tall = 0;

    itoa(n, tekst, 10);
    len = strlen(tekst);
    for (i = 0; i < len; i++)
        if (tekst[i] == '6')
            tekst[i] = '9';
        else if (tekst[i] == '9')
            tekst[i] = '6';
        else if (tekst[i] != '0' && tekst[i] != '1' && tekst[i] != '8')
            return 0;

    for (i = len - 1; i >= 0; i--)
        tall = (tall * 10) + (tekst[i] - '0');

    return (tall);
}

int main()
{
    int i,
        snudd,
        antall = 0;

    for (i = 1; i <= 100000; i++)

        if ((snudd = snuOppNedA(i)) && (i == snudd))
            cout << '\t' << ++antall << ":" << setw(8) << snudd << '\n';

    cout << "\nAntall like opp/ned mellom 1 og 100000:  " << antall
         << "\n\n\n";

    antall = 0;
    for (i = 1; i <= 100000; i++)

        if ((snudd = snuOppNedB(i)) && (i == snudd))
            cout << '\t' << ++antall << ":" << setw(8) << snudd << '\n';

    cout << "\nAntall like opp/ned mellom 1 og 100000:  " << antall
         << "\n\n\n";

    return 0;
}

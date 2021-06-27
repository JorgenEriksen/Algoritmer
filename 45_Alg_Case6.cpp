

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAXTALL = 1000;

int gTall[MAXTALL + 1];

bool inneholder7(const int n)
{
    char t[10];
    itoa(n, t, 10);
    return (strstr(t, "7"));
}

int main()
{
    int i,
        c = 0;

    for (i = 1; i <= MAXTALL; i++)
        gTall[i] = (i % 7 == 0 || inneholder7(i)) ? gTall[++c] : i;

    for (i = 1; i <= MAXTALL; i++)
        cout << "  " << gTall[i];

    c = 0;
    cout << "\n\n\nDet samme, bare at spesialtilfellene "
         << "(fet og understreket) skrives p� egne linjer:\n";

    for (i = 1; i <= MAXTALL; i++)
    {
        if (i % 7 == 0 || inneholder7(i))
        {
            gTall[i] = gTall[++c];
            cout << '\n'
                 << gTall[i] << '\n';
        }
        else
        {
            gTall[i] = i;
            cout << "  " << gTall[i];
        }
    }

    cout << "\n\n";
    return 0;
}

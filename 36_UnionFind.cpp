

#include <iostream>
#include <iomanip>
using namespace std;

const int ANTNODER = 10;
const int ANTKANTER = 14;

int gForeldre[ANTNODER + 1];

char gKanter[ANTKANTER][3] = {"AB", "CG", "JI", "AJ", "BD", "HB", "DC",
                              "DE", "GE", "FE", "CH", "IH", "BJ", "BC"};

void skriv();
bool unionerOgFinn(int nr1, int nr2, const bool unioner);

int main()
{
    int nr1 = 0, nr2 = 0;
    char tegn = ' ';

    for (int i = 0; i < ANTKANTER; i++)
    {
        nr1 = static_cast<int>(gKanter[i][0] - 'A' + 1);
        nr2 = static_cast<int>(gKanter[i][1] - 'A' + 1);

        unionerOgFinn(nr1, nr2, true);

        cout << '\n'
             << gKanter[i][0] << ' ' << gKanter[i][1] << ':';
        skriv();
        cout << "\t\t'D' og 'H' er "
             << (!unionerOgFinn(4, 8, false) ? "IKKE " : "")
             << "i samme komponent";
        cin >> tegn;
    }

    cout << "\n\n";
    return 0;
}

void skriv()
{
    cout << '\t';
    for (int i = 1; i <= ANTNODER; i++)
        cout << "  " << static_cast<char>(i + 'A' - 1);
    cout << "\n\t";
    for (int i = 1; i <= ANTNODER; i++)
        if (gForeldre[i] > 0)
            cout << "  " << static_cast<char>(gForeldre[i] + 'A' - 1);
        else if (gForeldre[i] == 0)
            cout << "  -";
        else
            cout << setw(3) << (-gForeldre[i]);
}

bool unionerOgFinn(int nr1, int nr2, const bool unioner)
{
    int i = nr1, j = nr2;

    while (gForeldre[i] > 0)
        i = gForeldre[i];

    while (gForeldre[j] > 0)
        j = gForeldre[j];

    if (unioner && (i != j))
        gForeldre[j] = i;

    return (i == j);
}

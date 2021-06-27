

#include <iostream>
using namespace std;

const int MAX = 8;

bool gBrett[MAX][MAX];

int gAntallLosninger = 0;

void skrivBrettet()
{
    int i, j;
    char tegn;

    cout << "\n\n\nL�sning nr." << ++gAntallLosninger << ":\n\t";
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
            cout << gBrett[i][j] << "  ";
        cout << "\n\t";
    }
    cout << "\t\t\tSkriv ett tegn .....";
    cin >> tegn;
}

bool lovligPosisjon(int linje, int kolonne)
{
    int i;

    for (i = 0; i < kolonne; i++)
        if (gBrett[linje][i])
            return false;

    for (i = kolonne - 1; i >= 0; i--)
    {
        if (linje - (kolonne - i) >= 0)
            if (gBrett[linje - (kolonne - i)][i])
                return false;
        if (linje + (kolonne - i) < MAX)
            if (gBrett[linje + (kolonne - i)][i])
                return false;
    }
    return true;
}

void settDronning(int j)
{
    int i;
    if (j == MAX)
        skrivBrettet();
    else
        for (i = 0; i < MAX; i++)

            if (j == 0 || lovligPosisjon(i, j))
            {
                gBrett[i][j] = true;
                settDronning(j + 1);
                gBrett[i][j] = false;
            }
}

int main()
{

    settDronning(0);

    if (gAntallLosninger == 0)
        cout << "\n\nINGEN L��SNINGER !";

    cout << "\n\n";
    return 0;
}

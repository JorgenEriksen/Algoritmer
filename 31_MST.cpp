

#include <iostream>
#include <iomanip>
#include "fringe.h"
using namespace std;

const int ANTNODER = 8;
const int USETT = -999;

void finnMST(int nr);
void skriv();

int gNaboMatrise[ANTNODER + 1][ANTNODER + 1] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                {0, 0, 3, 2, 0, 0, 0, 1, 0},
                                                {0, 3, 0, 0, 0, 0, 2, 0, 0},
                                                {0, 2, 0, 0, 0, 1, 0, 3, 0},
                                                {0, 0, 0, 0, 0, 2, 0, 3, 1},
                                                {0, 0, 0, 1, 2, 0, 0, 1, 0},
                                                {0, 0, 2, 0, 0, 0, 0, 2, 3},
                                                {0, 1, 0, 3, 3, 1, 2, 0, 2},
                                                {0, 0, 0, 0, 1, 0, 3, 2, 0}};

Fringe gFringe;
int gKantVekt[ANTNODER + 1];
int gTilknytning[ANTNODER + 1];

int main()
{

    for (int i = 1; i <= ANTNODER; i++)
        gKantVekt[i] = USETT;

    finnMST(1);

    cout << "\n\n";
    return 0;
}

void finnMST(int nr)
{
    int j,
        vekt;

    if (gFringe.update(nr, -USETT))
        gTilknytning[nr] = 0;

    while (!gFringe.empty())
    {
        cout << "\n\nOPPSTART:";
        skriv();
        nr = gFringe.remove();
        gKantVekt[nr] = -gKantVekt[nr];
        cout << "\nNr.1 (" << char('A' + nr - 1)
             << ") fjernet:";
        skriv();

        if (gKantVekt[nr] == -USETT)
            gKantVekt[nr] = 0;

        for (j = 1; j <= ANTNODER; j++)
        {
            vekt = gNaboMatrise[nr][j];
            if (vekt > 0 &&
                gKantVekt[j] < 0)
            {

                if (gFringe.update(j, vekt))
                {
                    gKantVekt[j] = -vekt;
                    gTilknytning[j] = nr;
                    cout << "\nOppdatering:";
                    skriv();
                }
            }
        }
    }
}

void skriv()
{
    gFringe.display(Bokstav);

    cout << "\n\t\t\t";
    for (int i = 1; i <= ANTNODER; i++)
        cout << setw(5) << char('A' + i - 1) << ':';
    cout << "\n\tgKantVekt:     ";
    for (int i = 1; i <= ANTNODER; i++)
        cout << setw(6) << gKantVekt[i];
    cout << "\n\tgTilknytning:  ";
    for (int i = 1; i <= ANTNODER; i++)
        cout << setw(6) << ((gTilknytning[i] > 0) ? char('A' + gTilknytning[i] - 1) : '0');
    char ch;
    cin >> ch;
}

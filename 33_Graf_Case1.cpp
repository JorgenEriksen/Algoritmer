

#include <iostream>
using namespace std;

const int ANTKRYSS = 12;

int gGatenett[ANTKRYSS][ANTKRYSS] =
    {{0, 40, 0, 0, 45, 0, 0, 0, 0, 0, 0, 0},
     {40, 0, 35, 0, 0, 45, 0, 0, 0, 0, 0, 0},
     {0, 35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 45, 0, 0, 0, 0, 40, 0, 0, 0, 0},
     {45, 0, 0, 0, 0, 0, 0, 0, 35, 0, 0, 0},
     {0, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 45, 0, 45, 0, 0, 0, 0},
     {0, 0, 0, 40, 0, 0, 45, 0, 0, 0, 0, 40},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0},
     {0, 0, 0, 0, 0, 40, 0, 0, 40, 0, 35, 0},
     {0, 0, 0, 0, 0, 0, 45, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 35, 0}};

bool gKryssSett[ANTKRYSS];

bool muligVei(const int fra, const int til, const int hoyde)
{
    int i;
    bool funnetFrem = false;

    gKryssSett[fra] = true;

    if (fra != til)
    {
        for (i = 0; i < ANTKRYSS; i++)
        {
            if (i != fra &&
                gGatenett[fra][i] != 0 &&
                (!gKryssSett[i]) &&
                hoyde <= gGatenett[fra][i])

                funnetFrem = muligVei(i, til, hoyde);

            if (funnetFrem)
                break;
        }
    }
    else
        funnetFrem = true;

    if (funnetFrem)
        cout << fra << "  ";

    return funnetFrem;
}

int main()
{

    cout << "\n\n";

    if (!muligVei(2, 3, 35))
        cout << "Ikke mulig � finne en kj�rbar vei!";

    cout << "\n\n";
    return 0;
}

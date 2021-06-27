

#include <iostream>
using namespace std;

void skrivStjerner(int antStjerner, int antBlanke)
{
    int i;

    if (antStjerner >= 1)
    {

        skrivStjerner(antStjerner / 2, antBlanke);

        for (i = 1; i <= antBlanke; i++)
            cout << "  ";

        for (i = 1; i <= antStjerner; i++)
            cout << "* ";
        cout << '\n';

        skrivStjerner(antStjerner / 2,
                      antBlanke + (antStjerner / 2));
    }
}

int main()
{

    skrivStjerner(8, 0);

    cout << '\n';
    return 0;
}

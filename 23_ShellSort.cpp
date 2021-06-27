

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int N = 20;

void display(const char arr[], const int n);
void shellSort(char arr[], const int n);
void skriv(const string &tekst, const char arr[],
           const int i, const int j, const int h, const char verdi);

int main()
{
    char array[N + 1];

    srand(0);

    array[0] = ' ';

    for (int i = 1; i <= N; i++)
        array[i] = static_cast<char>('A' + (rand() % 26));

    cout << "\n\nArrayen F�R sortering:\n\t";
    display(array, N + 1);

    shellSort(array, N + 1);

    cout << "\n\nArrayen ETTER SHELLSORT sortering:\n\t";
    display(array, N + 1);

    cout << "\n\n";
    return 0;
}

void display(const char arr[], const int n)
{
    for (int i = 1; i < n; i++)
        cout << arr[i];
    cout << '\n';
}

void shellSort(char arr[], const int n)
{
    int i, j, h;
    char verdi;

    for (h = 1; h <= n / 9; h = (3 * h) + 1)
        ;

    while (h > 0)
    {

        for (i = h + 1; i < n; i++)
        {
            verdi = arr[i];
            j = i;

            while (j > h && arr[j - h] > verdi)
            {

                arr[j] = arr[j - h];
                j -= h;
            }
            arr[j] = verdi;
        }

        h /= 3;
    }
}

void skriv(const string &tekst, const char arr[],
           const int i, const int j, const int h, const char verdi)
{
    char tegn;

    cout << '\n'
         << tekst << ":\t";

    if (tekst == "Etter")
    {
        cout << "Sammenligning utf�rt,";
        if (j <= h)
            cout << "\tJ <= H\t\t";
        else
            cout << "\t'" << arr[j - h] << "' <= '" << verdi << "'\t";
        display(arr, N + 1);
    }
    else
    {
        if (tekst == "F�r")
            cout << '\t';
        cout << "H: " << h
             << "\tI: " << i << "\tJ: " << j
             << "\tJ-H: " << j - h;
        if (tekst == "Inni - slutt")
        {
            cout << "  ";
            display(arr, N + 1);
        }
        else
        {
            cout << "\t\tarr[" << j - h << "]: '" << arr[j - h]
                 << "'  >  verdi: '" << verdi << "'";
            if (tekst == "F�r")
                cout << "   ?";
            else
                cout << "   !!!";
        }
    }
    cin >> tegn;
}

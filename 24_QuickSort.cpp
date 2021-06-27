

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int N = 20;

void bytt(char &tegn1, char &tegn2);
void display(const string &tekst, const char arr[],
             const int venstre, const int hoyre);
int partisjoner(char arr[], const int venstre, const int hoyre);
void quickSort(char arr[], const int venstre, const int hoyre);

int main()
{
    char array[N + 1];

    srand(0);

    array[0] = ' ';

    for (int i = 1; i <= N; i++)
        array[i] = static_cast<char>('A' + (rand() % 26));

    display("\n\nArrayen F�R sortering:\n", array, 1, N);

    quickSort(array, 1, N);

    display("\n\nArrayen ETTER QUICKSORT sortering:\n", array, 1, N);

    cout << "\n\n";
    return 0;
}

void bytt(char &tegn1, char &tegn2)
{
    char temp = tegn1;
    tegn1 = tegn2;
    tegn2 = temp;
}

void display(const string &tekst, const char arr[],
             const int venstre, const int hoyre)
{
    char tegn;
    cout << tekst << "\t";
    for (int i = venstre; i <= hoyre; i++)
        cout << arr[i];
    cin >> tegn;
}

int partisjoner(char arr[], const int venstre, const int hoyre)
{
    if (hoyre > venstre)
    {
        int i, j;
        char partisjonsElement;

        partisjonsElement = arr[hoyre];
        i = venstre - 1;
        j = hoyre;

        while (true)
        {

            while (arr[++i] < partisjonsElement)
                ;

            while (arr[--j] > partisjonsElement)
                ;

            if (i >= j)
                break;
            bytt(arr[i], arr[j]);
        }

        bytt(arr[i], arr[hoyre]);

        return i;
    }
    return 0;
}

void quickSort(char arr[], const int venstre, const int hoyre)
{
    if (hoyre > venstre)
    {
        int indeks = partisjoner(arr, venstre, hoyre);
        quickSort(arr, venstre, indeks - 1);
        quickSort(arr, indeks + 1, hoyre);
    }
}

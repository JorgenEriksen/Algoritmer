

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int N = 20;

void display(const int arr[], const int n);
int sokBinert(const int arr[], const int verdi, const int n);
int sokSekvensielt(const int arr[], const int verdi, const int n);

int main()
{
    int array[N + 1];

    srand(0);

    for (int i = 1; i <= N; i++)
        array[i] = (rand() % 100) + 1;

    cout << "\n\nArrayen m/indekser:\n";
    display(array, N);

    cout << "\n54 har indeks nr." << sokSekvensielt(array, 54, N) << '\n';
    cout << "\n56 har indeks nr." << sokSekvensielt(array, 56, N) << '\n';
    cout << "\n39 har indeks nr." << sokSekvensielt(array, 39, N) << '\n';
    cout << "\n17 har indeks nr." << sokSekvensielt(array, 17, N) << '\n';
    cout << "\n 4 har indeks nr." << sokSekvensielt(array, 4, N) << '\n';

    for (int i = 1; i <= N; i++)
        array[i] = i * 2;

    cout << "\n\n\nSORTERT arrayen m/partall:\n";
    display(array, N);

    cout << "\n24 har indeks nr." << sokBinert(array, 24, N) << '\n';
    cout << "\n 8 har indeks nr." << sokBinert(array, 8, N) << '\n';
    cout << "\n 7 har indeks nr." << sokBinert(array, 7, N) << '\n';
    cout << "\n98 har indeks nr." << sokBinert(array, 98, N) << '\n';

    cout << "\n\n";
    return 0;
}

void display(const int arr[], const int n)
{
    cout << ' ';
    for (int i = 1; i <= n; i++)
        cout << setw(3) << i << ':';
    cout << '\n';
    for (int i = 1; i <= n; i++)
        cout << setw(4) << arr[i];
    cout << '\n';
}

int sokBinert(const int arr[], const int verdi, const int n)
{
    int venstre = 1,
        hoyre = n,
        midten;

    while (venstre <= hoyre)
    {
        midten = (venstre + hoyre) / 2;

        if (verdi == arr[midten])
            return midten;

        if (verdi < arr[midten])
            hoyre = midten - 1;
        else
            venstre = midten + 1;
    }
    return 0;
}

int sokSekvensielt(const int arr[], const int verdi, int n)
{
    int indeks = n + 1;

    while (indeks > 0 && verdi != arr[--indeks])
        ;
    return (indeks);
}

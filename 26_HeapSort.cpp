

#include <iostream>
#include <cstdlib>
#include "eks_25_Heap.h"
using namespace std;

const int N = 20;

template <typename T>
void bytt(T &verdi1, T &verdi2);

void display(const unsigned char arr[], const int n);
void heapSort(unsigned char arr[], int n);

Heap<unsigned char> gHeap;

int main()
{
    unsigned char array[N + 1];

    srand(0);

    for (int i = 1; i <= N; i++)
        array[i] = static_cast<unsigned char>('a' + (rand() % 26));

    cout << "\n\nArrayen F�R sortering:\n";
    display(array, N);

    heapSort(array, N);

    cout << "\n\nArrayen ETTER HEAPSORT sortering:\n";
    display(array, N);

    cout << "\n\n";
    return 0;
}

template <typename T>
void bytt(T &tegn1, T &tegn2)
{
    T temp = tegn1;
    tegn1 = tegn2;
    tegn2 = temp;
}

void display(const unsigned char arr[], const int n)
{
    char tegn;
    cout << '\t';
    for (int i = 1; i <= n; i++)
        cout << arr[i];
    cin >> tegn;
}

void heapSort(unsigned char arr[], int n)
{
    for (int keyNr = n / 2; keyNr >= 1; keyNr--)
        gHeap.downHeap(arr, n, keyNr);

    while (n > 1)
    {
        bytt<unsigned char>(arr[1], arr[n]);
        gHeap.downHeap(arr, --n, 1);
    }
}

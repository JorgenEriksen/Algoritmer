

#include <iostream>
#include <cstdlib>
using namespace std;

const int N = 20;

void display(const int arr[], const int n);
void insertionSort(int arr[], const int n);

int main()
{
    int array[N + 1];

    srand(0);

    array[0] = -1;

    for (int i = 1; i <= N; i++)
        array[i] = (rand() % 100) + 1;

    cout << "\n\nArrayen F�R sortering:\n\t";
    display(array, N + 1);

    insertionSort(array, N + 1);

    cout << "\n\nArrayen ETTER INSERTION sortering:\n\t";
    display(array, N + 1);

    cout << "\n\n";
    return 0;
}

void display(const int arr[], const int n)
{
    for (int i = 1; i < n; i++)
        cout << ' ' << arr[i];
    cout << '\n';
}

void insertionSort(int arr[], const int n)
{
    int i, j,
        verdi;

    for (i = 2; i < n; i++)
    {
        verdi = arr[i];
        j = i;
        while (arr[j - 1] > verdi)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = verdi;
    }
}

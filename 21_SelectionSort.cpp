

#include <iostream>
#include <cstdlib>
using namespace std;

const int N = 20;

void bytt(int &tall1, int &tall2);
void display(const int arr[], const int n);
void selectionSort(int arr[], const int n);

int main()
{
    int array[N];

    srand(0);

    for (int i = 0; i < N; i++)
        array[i] = (rand() % 100) + 1;

    cout << "\n\nArrayen F�R sortering:\n\t";
    display(array, N);

    selectionSort(array, N);

    cout << "\n\nArrayen ETTER SELECTION sortering:\n\t";
    display(array, N);

    cout << "\n\n";
    return 0;
}

void bytt(int &tall1, int &tall2)
{
    int temp = tall1;
    tall1 = tall2;
    tall2 = temp;
}

void display(const int arr[], const int n)
{
    for (int i = 0; i < n; i++)
        cout << ' ' << arr[i];
    cout << '\n';
}

void selectionSort(int arr[], const int n)
{
    int i, j,
        minIndeks;

    for (i = 0; i < n - 1; i++)
    {
        minIndeks = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndeks])
                minIndeks = j;
        bytt(arr[minIndeks], arr[i]);
    }
}

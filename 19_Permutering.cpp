

#include <iostream>
using namespace std;

const int N = 4;

void bytt(int &tall1, int &tall2);
void display(const int arr[], const int n);
void permuter(int arr[], const int i, const int n);
void roterVenstre(int arr[], const int i, const int n);

int main()
{
    int array[N];

    for (int i = 0; i < N; i++)
        array[i] = i + 1;

    permuter(array, 0, N);

    cout << '\n';
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

void permuter(int arr[], const int i, const int n)
{
    if (i == n - 1)
        display(arr, n);
    else
    {
        permuter(arr, i + 1, n);

        for (int t = i + 1; t < n; t++)
        {
            bytt(arr[i], arr[t]);

            permuter(arr, i + 1, n);
        }
        roterVenstre(arr, i, n);
    }
}

void roterVenstre(int arr[], const int i, const int n)
{
    int venstreVerdi = arr[i];
    for (int k = i + 1; k < n; k++)
        arr[k - 1] = arr[k];
    arr[n - 1] = venstreVerdi;
}

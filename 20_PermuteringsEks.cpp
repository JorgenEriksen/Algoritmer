

#include <iostream>
#include <iomanip>
using namespace std;

const int N = 16;

int gAntallLosninger;

void bytt(int &tall1, int &tall2);
void display(const int arr[], const int n);
void permuter(int arr[], const int i, const int n);
bool rettSum(int arr[], int n);
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
    cout << "\nL�sning nr." << ++gAntallLosninger << ":";
    for (int i = 0; i < N; i++)
    {
        if (i % 4 == 0)
            cout << '\n';
        cout << setw(5) << arr[i];
    }
    cout << '\n';
}

void permuter(int arr[], const int i, const int n)
{
    if (i == n - 1 && rettSum(arr, i))
        display(arr, n);
    else
    {

        if ((i + 1) % 4 != 0 || rettSum(arr, i))
            permuter(arr, i + 1, n);

        for (int t = i + 1; t < n; t++)
        {
            bytt(arr[i], arr[t]);

            if ((i + 1) % 4 != 0 || rettSum(arr, i))
                permuter(arr, i + 1, n);
        }
        roterVenstre(arr, i, n);
    }
}

bool rettSum(int arr[], int n)
{
    if (arr[n - 3] + arr[n - 2] + arr[n - 1] + arr[n] != 34)
        return false;
    if (n == N - 1)
    {
        for (int i = 0; i < 4; i++)
            if (arr[0 + i] + arr[4 + i] + arr[8 + i] + arr[12 + i] != 34)
                return false;
        if (arr[0] + arr[5] + arr[10] + arr[15] != 34)
            return false;
        if (arr[3] + arr[6] + arr[9] + arr[12] != 34)
            return false;
    }
    return true;
}

void roterVenstre(int arr[], const int i, const int n)
{
    int venstreVerdi = arr[i];
    for (int k = i + 1; k < n; k++)
        arr[k - 1] = arr[k];
    arr[n - 1] = venstreVerdi;
}



#include <iostream>
#include <iomanip>
using namespace std;

const int ANTNODER = 10;

int gNM1[ANTNODER][ANTNODER] =

    {{0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
     {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
     {0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
     {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
     {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}};

int gNM2[ANTNODER][ANTNODER] =

    {{0, 1, 0, 0, 2, 0, 0, 0, 0, 0},
     {0, 0, 2, 0, 0, 0, 0, 0, 0, 0},
     {0, 2, 0, 4, 0, 3, 0, 0, 0, 3},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 3, 0, 0, 0, 1, 0, 0, 0, 0},
     {0, 0, 3, 0, 1, 0, 0, 3, 0, 0},
     {2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 3, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
     {0, 0, 3, 0, 0, 0, 0, 0, 0, 0}};

void display(const int a[][ANTNODER], const int n)
{
  int i, j;
  cout << "\n\t";
  for (i = 0; i < n; i++)
    cout << setw(3) << char('A' + i);
  cout << '\n';
  for (i = 0; i < n; i++)
  {
    cout << "\n      " << char('A' + i) << ' ';
    for (j = 0; j < n; j++)
      cout << setw(3) << a[i][j];
  }
}

int main()
{
  int j, x, y;
  char ch;

  for (y = 0; y < ANTNODER; y++)
    for (x = 0; x < ANTNODER; x++)
      if (gNM1[x][y])
        for (j = 0; j < ANTNODER; j++)
        {
          if (gNM1[y][j] && !gNM1[x][j])
          {

            gNM1[x][j] = 1;
          }
        }

  display(gNM1, ANTNODER);
  cout << "\n\n\nFerdig med � finne 'Transitive Closure'.\n\n";
  cin >> ch;

  for (y = 0; y < ANTNODER; y++)
    for (x = 0; x < ANTNODER; x++)
      if (gNM2[x][y])
        for (j = 0; j < ANTNODER; j++)
        {
          if (gNM2[y][j] > 0)
            if (!gNM2[x][j] ||

                (gNM2[x][y] + gNM2[y][j] < gNM2[x][j]))
            {
              gNM2[x][j] = gNM2[x][y] + gNM2[y][j];
            }
        }

  display(gNM2, ANTNODER);
  cout << "\n\n\nFerdig med � finne 'Alle korteste stier'.\n\n";

  return 0;
}

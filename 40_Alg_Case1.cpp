

#include <fstream>
#include <iostream>
using namespace std;

const int ANTX = 9, ANTY = 9,
          N = ANTX * ANTY,
          STRLEN = 80;

int gBrett[ANTX][ANTY];

void finnLosning(const int n);
void lesFraFil();
void skrivLosning();

int main()
{

  lesFraFil();

  finnLosning(0);

  return 0;
}

void finnLosning(const int n)
{
  bool brukt[ANTX + 1] = {false, false, false, false, false, false,
                          false, false, false, false};

  int i = n / ANTX, j = n % ANTY;
  int ii, jj, k,
      tall,
      dx1, dx2, dy1, dy2;

  if (n == N)
    skrivLosning();

  else if (gBrett[i][j] == 0)
  {

    for (jj = 0; jj < ANTY; jj++)
    {
      tall = gBrett[i][jj];
      if (tall && !brukt[tall])
        brukt[tall] = true;
    }

    for (ii = 0; ii < ANTX; ii++)
    {
      tall = gBrett[ii][j];
      if (tall && !brukt[tall])
        brukt[tall] = true;
    }

    ii = i % 3;
    jj = j % 3;
    switch (ii)
    {
    case 0:
      dx1 = 1;
      dx2 = 2;
      break;
    case 1:
      dx1 = -1;
      dx2 = 1;
      break;
    case 2:
      dx1 = -2;
      dx2 = -1;
      break;
    }
    switch (jj)
    {
    case 0:
      dy1 = 1;
      dy2 = 2;
      break;
    case 1:
      dy1 = -1;
      dy2 = 1;
      break;
    case 2:
      dy1 = -2;
      dy2 = -1;
      break;
    }

    for (k = 1; k <= ANTX; k++)
    {
      switch (k)
      {
      case 1:
        ii = i;
        jj = j;
        break;
      case 2:
        ii = i + dx1;
        jj = j;
        break;
      case 3:
        ii = i + dx2;
        jj = j;
        break;
      case 4:
        ii = i;
        jj = j + dy1;
        break;
      case 5:
        ii = i + dx1;
        jj = j + dy1;
        break;
      case 6:
        ii = i + dx2;
        jj = j + dy1;
        break;
      case 7:
        ii = i;
        jj = j + dy2;
        break;
      case 8:
        ii = i + dx1;
        jj = j + dy2;
        break;
      case 9:
        ii = i + dx2;
        jj = j + dy2;
        break;
      }
      tall = gBrett[ii][jj];
      if (tall && !brukt[tall])
        brukt[tall] = true;
    }

    for (k = 1; k <= ANTX; k++)
      if (!brukt[k])
      {
        gBrett[i][j] = k;
        finnLosning(n + 1);
        gBrett[i][j] = 0;
      }
  }
  else
    finnLosning(n + 1);
}

void lesFraFil()
{
  ifstream innfil("eks_40_SUDOKU.dta");
  int i, j;
  char dummy;
  char buffer[STRLEN];

  if (innfil)
  {
    cout << "\n\nLeser fra filen 'EKS_40_SUDOKU.DTA' .....\n";
    for (i = 0; i < ANTX; i++)
    {
      for (j = 0; j < ANTY; j += 3)
      {
        innfil >> gBrett[i][j] >> gBrett[i][j + 1] >> gBrett[i][j + 2];
        if (j + 2 < ANTY - 1)
          innfil >> dummy;
      }
      innfil.ignore();
      if ((i == 2 || i == 5))
        innfil.getline(buffer, STRLEN);
    }
  }
  else
    cout << "\n\n\tFant ikke filen 'EKS_40_SUDOKU.DTA'!\n\n";
}

void skrivLosning()
{
  int i, j;

  cout << "\n\nL�SNING:";
  for (i = 0; i < ANTX; i++)
  {
    cout << "\n\t";
    for (j = 0; j < ANTY; j++)
      cout << gBrett[i][j] << ' ';
  }
  cout << "\n\n";
}

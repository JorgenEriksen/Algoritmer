

#include <iostream>
#include <iomanip>
#include <ctype.h>
#include "fringe.h"
using namespace std;

const int ANTBOKSTAVER = 27;

int gFrekvens[ANTBOKSTAVER * 2];
int gForelder[ANTBOKSTAVER * 2];
int gKode[ANTBOKSTAVER];
int gLengde[ANTBOKSTAVER];
int gSisteIndeks;
Fringe gFringe;

void bestemForeldre();
void finnBitmonsterOgLengde();
void lesOgTellFrekvens();
void skriv(const int nr);

int main()
{

  lesOgTellFrekvens();
  skriv(1);

  bestemForeldre();
  skriv(2);

  finnBitmonsterOgLengde();
  skriv(3);

  return 0;
}

void bestemForeldre()
{
  int i,
      nodeV,
      nodeH;

  for (i = 0; i < ANTBOKSTAVER; i++)
    if (gFrekvens[i])
      gFringe.update(i, gFrekvens[i]);

  for (; !gFringe.empty(); i++)
  {
    nodeV = gFringe.remove();
    nodeH = gFringe.remove();
    gForelder[i] = 0;
    gForelder[nodeV] = i;
    gForelder[nodeH] = -i;

    gFrekvens[i] = gFrekvens[nodeV] + gFrekvens[nodeH];

    if (!gFringe.empty())
      gFringe.update(i, gFrekvens[i]);
  }
  gSisteIndeks = i;
}

void finnBitmonsterOgLengde()
{
  int i,
      antBit,
      monster,
      kode,
      mor;

  for (i = 0; i < ANTBOKSTAVER; i++)
  {
    antBit = 0;
    kode = 0;
    monster = 1;
    if (gFrekvens[i])
    {
      for (mor = gForelder[i];
           mor != 0;
           mor = gForelder[mor],
          monster *= 2,
          antBit++)
        if (mor < 0)
        {
          kode += monster;
          mor = -mor;
        }
    }
    gKode[i] = kode;
    gLengde[i] = antBit;
  }
}

void lesOgTellFrekvens()
{
  char tegn;
  cout << "\n\nSkriv bokstaver, avslutt med '!':\n";
  tegn = getchar();
  while (tegn != '!')
  {
    tegn = toupper(tegn);
    if (tegn == ' ')
      gFrekvens[0]++;
    else if (isalpha(tegn))
      gFrekvens[static_cast<int>(tegn - 'A' + 1)]++;
    tegn = getchar();
  }
}

void skriv(const int nr)
{
  int i, n;

  n = ((nr != 2) ? ANTBOKSTAVER : gSisteIndeks + 1);

  cout << "\n\n";
  if (gFrekvens[0])
    cout << " ' '";
  for (i = 1; i < n; i++)
    if (gFrekvens[i])
    {
      if (i < ANTBOKSTAVER)
        cout << setw(4) << static_cast<char>('A' + i - 1);
      else
        cout << setw(4) << i;
    }

  if (nr <= 2)
  {
    cout << "\ngFrekvens:\n";
    for (i = 0; i < n; i++)
      if (gFrekvens[i])
        cout << setw(4) << gFrekvens[i];
  }

  if (nr == 2)
  {
    cout << "\ngForelder:\n";
    for (i = 0; i < n; i++)
      if (gFrekvens[i])
        cout << setw(4) << gForelder[i];
  }

  if (nr == 3)
  {
    cout << "\ngKode:\n";
    for (i = 0; i < n; i++)
      if (gFrekvens[i])
        cout << setw(4) << gKode[i];

    cout << "\ngLengde:\n";
    for (i = 0; i < n; i++)
      if (gFrekvens[i])
        cout << setw(4) << gLengde[i];
  }
  cout << "\n\n";
}

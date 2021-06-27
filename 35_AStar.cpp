

#include <iostream>
#include <cmath>
#include "fringe.h"
using namespace std;

const int DIMENSJON = 20;
const int ARRLEN = DIMENSJON * 101;
const int USETT = -999;
const int MAALRUTE = 1814;
const int STARTRUTE = 208;

bool AStar();
int heuristics(int nr);
void lagOgSkrivRute();

char gRutenett[DIMENSJON + 2][DIMENSJON + 3] = {"XXXXXXXXXXXXXXXXXXXXXX",
                                                "X        XXXXXX      X",
                                                "X             X      X",
                                                "X   X                X",
                                                "X   X           X    X",
                                                "X   X           X    X",
                                                "X   XXXXXXX     XXX  X",
                                                "X      X        X    X",
                                                "X     XX        X    X",
                                                "X     X  XXXXXXXX    X",
                                                "X                    X",
                                                "X   XX XXXXXXXXXX    X",
                                                "X   X         X      X",
                                                "X   X       XXX      X",
                                                "X             X      X",
                                                "X          XXXX      X",
                                                "XXXXXXXXXX           X",
                                                "X          XXXXXX    X",
                                                "X   XXXX        X    X",
                                                "X   XXXX        XXX  X",
                                                "X                    X",
                                                "XXXXXXXXXXXXXXXXXXXXXX"};

Fringe gFringe(DIMENSJON *DIMENSJON);
int gKantVekt[ARRLEN + 1];
int gTilknytning[ARRLEN + 1];

int main()
{

  for (int i = 101; i <= (ARRLEN); i++)
    gKantVekt[i] = USETT;

  if (AStar())
    lagOgSkrivRute();
  else
    cout << "\n\n\tIkke mulig � finne vei fra "
         << STARTRUTE << " til " << MAALRUTE;

  cout << "\n\n";
  return 0;
}

bool AStar()
{
  int i,
      nr = STARTRUTE,
      nabo,
      x, y,
      vekt,
      tillegg;

  gFringe.update(nr, -USETT);
  gTilknytning[nr] = 0;
  gKantVekt[nr] = 0;

  while (!gFringe.empty())
  {

    nr = gFringe.remove();

    if (nr == MAALRUTE)
      return true;

    gKantVekt[nr] = -gKantVekt[nr];

    for (i = 1; i <= 8; i++)
    {
      switch (i)
      {
      case 1:
        nabo = nr - 100;
        tillegg = 2;
        break;
      case 2:
        nabo = nr - 99;
        tillegg = 3;
        break;
      case 3:
        nabo = nr + 1;
        tillegg = 2;
        break;
      case 4:
        nabo = nr + 101;
        tillegg = 3;
        break;
      case 5:
        nabo = nr + 100;
        tillegg = 2;
        break;
      case 6:
        nabo = nr + 99;
        tillegg = 3;
        break;
      case 7:
        nabo = nr - 1;
        tillegg = 2;
        break;
      case 8:
        nabo = nr - 101;
        tillegg = 3;
        break;
      }

      x = nabo % 100;
      y = nabo / 100;

      if ((gRutenett[y][x] != 'X') && (gKantVekt[nabo] < 0))
      {
        vekt = gKantVekt[nr] + tillegg;

        if (gFringe.update(nabo, vekt + heuristics(nabo)))
        {
          gKantVekt[nabo] = -vekt;
          gTilknytning[nabo] = nr;
        }
      }
    }
  }
  return false;
}

int heuristics(int nr)
{
  int dx = ((nr % 100) - (MAALRUTE % 100)),
      dy = ((nr / 100) - (MAALRUTE / 100));
  float luftlinje = sqrt((dx * dx) + (dy * dy));
  return (2 * luftlinje);
}

void lagOgSkrivRute()
{
  int i, j,
      nr;

  gRutenett[STARTRUTE / 100][STARTRUTE % 100] = 'S';
  gRutenett[MAALRUTE / 100][MAALRUTE % 100] = 'M';

  nr = gTilknytning[MAALRUTE];
  while (gTilknytning[nr] != 0)
  {
    gRutenett[nr / 100][nr % 100] = '.';

    nr = gTilknytning[nr];
  }

  for (i = 0; i < DIMENSJON + 2; i++)
  {
    for (j = 0; j < DIMENSJON + 2; j++)
      cout << gRutenett[i][j];
    cout << '\n';
  }
}

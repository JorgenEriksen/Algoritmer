

#include <iostream>
#include <fstream>
using namespace std;

const int MAXONSKER = 3;
const int MAXGJENST = 200;
const int MAXPERS = 100;

int gAntPersoner,
    gAntGjenstander;

int gOnsker[MAXPERS][MAXONSKER];
int gGjenstand[MAXGJENST];
int gBesteFordeling[MAXGJENST];
bool gLosningFunnet = false;
int gBestePrioritet = (MAXPERS * MAXONSKER) + 1;
int gTotalPrioritet = 0;

void lesFraFil()
{
   ifstream innfil("EKS_44_ONSKER.DTA");

   if (innfil)
   {

      innfil >> gAntGjenstander >> gAntPersoner;

      if (gAntGjenstander < 0 || gAntGjenstander >= MAXGJENST ||
          gAntPersoner < 0 || gAntPersoner >= MAXPERS)
      {
         cout << "\n'gAntGjenstander' / 'gAntPersoner' i feil intervall\n";
      }

      for (int i = 0; i < gAntPersoner; i++)
      {
         innfil >> gOnsker[i][0] >> gOnsker[i][1] >> gOnsker[i][2];

         gOnsker[i][0]--;
         gOnsker[i][1]--;
         gOnsker[i][2]--;
      }
   }
   else
      cout << "\n\n\tFant ikke filen 'EKS_44_OgAntPersonerSKER.DTA'!\n\n";
}

void kopier(const int arrFra[], int arrTil[])
{
   for (int i = 0; i < gAntGjenstander; i++)
      arrTil[i] = arrFra[i];
}

void fordelGjenstander(const int n)
{
   if (n == gAntPersoner)
   {
      gLosningFunnet = true;
      gBestePrioritet = gTotalPrioritet;
      kopier(gGjenstand, gBesteFordeling);
   }
   else
   {
      for (int i = 0; i < MAXONSKER; i++)
         if (!gGjenstand[gOnsker[n][i]])
         {
            gTotalPrioritet += (i + 1);

            if (gTotalPrioritet < gBestePrioritet)
            {
               gGjenstand[gOnsker[n][i]] = n + 1;
               fordelGjenstander(n + 1);
               gGjenstand[gOnsker[n][i]] = 0;
            }
            gTotalPrioritet -= (i + 1);
         }
   }
}

int main()
{

   lesFraFil();

   fordelGjenstander(0);

   if (gLosningFunnet)
   {
      cout << "\n\n"
           << gAntGjenstander << " gjenstander til fordeling p� "
           << gAntPersoner << " personer:\n\n";
      cout << "Totalt beste prioritet ble " << gBestePrioritet
           << ", i forhold til minimumet som er " << gAntPersoner
           << ".\n\nBeste l�sning er:\n";
      for (int i = 0; i < gAntGjenstander; i++)
      {
         cout << "\tGjenstand nr." << i + 1 << " til ";
         if (gBesteFordeling[i])
            cout << "person nr." << gBesteFordeling[i] << '\n';
         else
            cout << "INGEN\n";
      }
   }
   else
      cout << "\n\nIngen fordeling mulig, da for mange "
           << "personer �nsker seg de samme gjenstandene!";

   cout << "\n\n";
   return 0;
}

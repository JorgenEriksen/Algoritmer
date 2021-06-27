

#ifndef __FRINGE_H
#define __FRINGE_H

enum Utskrift
{
   Bokstav,
   Tall
};

class Fringe
{
private:
   int *keyene;
   int *vektene;
   int antall;

public:
   Fringe(const int max = 200)
   {
      keyene = new int[max];
      vektene = new int[max];
      antall = 0;
   }
   ~Fringe()
   {
      delete[] keyene;
      delete[] vektene;
   }

   void display(const Utskrift skriv) const
   {
      std::cout << "\tFringe:\t";
      for (int i = 0; i < antall; i++)
      {
         if (skriv == Bokstav)
            std::cout << char(keyene[i] + 'A' - 1);
         else
            std::cout << keyene[i];
         std::cout << ':' << vektene[i] << "  ";
      }
   }

   bool empty() const { return (antall == 0); }

   bool update(const int key, const int vekt)
   {
      int j,
          i = 0;

      while ((keyene[i] != key) && (i < antall))
         i++;
      if ((i < antall) && (vekt >= vektene[i]))
         return false;

      if (i < antall)
      {
         for (j = i; j < antall - 1; j++)
         {
            keyene[j] = keyene[j + 1];
            vektene[j] = vektene[j + 1];
         }
         --antall;
      }

      i = 0;
      while ((vektene[i] < vekt) && (i < antall))
         i++;
      ++antall;
      for (j = antall - 1; j > i; j--)
      {
         keyene[j] = keyene[j - 1];
         vektene[j] = vektene[j - 1];
      }
      keyene[i] = key;
      vektene[i] = vekt;
      return true;
   }

   int remove()
   {
      int key = keyene[0];
      for (int i = 0; i < antall - 1; i++)
      {
         keyene[i] = keyene[i + 1];
         vektene[i] = vektene[i + 1];
      }
      --antall;
      return key;
   }
};

#endif

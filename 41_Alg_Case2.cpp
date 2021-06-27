

#include <iostream>
using namespace std;

const int SLUTT = 33550336;

bool erPerfekt(const int n)
{
   int sum = 0, slutt = n / 2;

   for (int i = 1; i <= slutt; i++)
   {
      if (n % i == 0)
         sum += i;
      if (sum > n)
         return false;
   }

   return (sum == n);
}

int main()
{

   cout << "De fem f�rste perfekte tallene:\n";

   for (int tall = 1; tall <= SLUTT; tall++)
      if (erPerfekt(tall))
         cout << '\t' << tall << '\n';

   return 0;
}

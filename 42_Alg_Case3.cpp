

#include <iostream>
#include <cstring>
using namespace std;

const int LEN = 9;
const int N = 8;

char txt0[N][LEN] = {"0403", "05043", "05047", "113", "1143", "11612345",
                     "11812345", "62529903"};
char txt1[N][LEN] = {"0403", "05043", "05047", "113", "1134", "11612345",
                     "11812345", "62529903"};
char txt2[N][LEN] = {"0403", "05043", "050437", "113", "1143", "11612345",
                     "11812345", "62529903"};

int num[][N] = {{113, 403, 1143, 5043, 5047, 11612345, 11812345, 62529903},
                {113, 403, 1134, 5043, 5047, 11612345, 11812345, 62529903},
                {113, 403, 1143, 5043, 50437, 11612345, 11812345, 62529903}};

char txt3[N][LEN] = {"113", "0403", "1143", "05043", "05047", "11612345",
                     "11812345", "62529903"};
char txt4[N][LEN] = {"113", "0403", "1134", "05043", "05047", "11612345",
                     "11812345", "62529903"};
char txt5[N][LEN] = {"113", "0403", "1143", "05043", "050437", "11612345",
                     "11812345", "62529903"};

bool prefixA(const char t[N][LEN])
{
  for (int i = 0; i < N - 1; i++)
  {
    if (!strncmp(t[i], t[i + 1], strlen(t[i])))
    {
      cout << "\t\t" << t[i] << " er et prefiks av " << t[i + 1] << '\n';
      return true;
    }
  }
  return false;
}

bool prefixB(const int n[N])
{
  int i, j, tall;

  for (i = N - 1; i > 0; i--)
  {
    tall = n[i];
    while (tall > 0)
    {
      for (j = i - 1; j >= 0; j--)
        if (tall == n[j])
        {
          cout << "\t\t" << n[j] << " er et prefiks av " << n[i] << '\n';
          return true;
        }
      tall /= 10;
    }
  }
  return false;
}

bool prefixC(const char t[N][LEN])
{
  int i, j;
  for (i = 0; i < N - 1; i++)
  {
    for (j = i + 1; j <= N - 1; j++)
      if (!strncmp(t[i], t[j], strlen(t[i])))
      {
        cout << "\t\t" << t[i] << " er et prefiks av " << t[j] << '\n';
        return true;
      }
  }
  return false;
}

int main()
{

  cout << "txt0 er " << ((prefixA(txt0)) ? "IKKE " : "") << "OK\n\n";
  cout << "txt1 er " << ((prefixA(txt1)) ? "IKKE " : "") << "OK\n\n";
  cout << "txt2 er " << ((prefixA(txt2)) ? "IKKE " : "") << "OK\n\n";
  cout << "\n\n";

  cout << "num[0] er " << ((prefixB(num[0])) ? "IKKE " : "") << "OK\n\n";
  cout << "num[1] er " << ((prefixB(num[1])) ? "IKKE " : "") << "OK\n\n";
  cout << "num[2] er " << ((prefixB(num[2])) ? "IKKE " : "") << "OK\n\n";
  cout << "\n\n";

  cout << "txt3 er " << ((prefixC(txt3)) ? "IKKE " : "") << "OK\n\n";
  cout << "txt4 er " << ((prefixC(txt4)) ? "IKKE " : "") << "OK\n\n";
  cout << "txt5 er " << ((prefixC(txt5)) ? "IKKE " : "") << "OK\n\n";
  cout << "\n\n";

  return 0;
}



#include <iostream>
using namespace std;

const int MAXDEPTH = 5;

void kryss(int x1, int y1, int x2, int y2, int n)
{
    int dx = (x2 - x1) / 2;
    int dy = (y2 - y1) / 2;

    cout << n << ' ';

    if (n < MAXDEPTH)
    {
        kryss(x1, y1, x1 + dx, y1 + dy, n + 1);
        kryss(x1 + dx, y1, x2, y1 + dy, n + 1);
        kryss(x1, y1 + dy, x1 + dx, y2, n + 1);
        kryss(x1 + dx, y1 + dy, x2, y2, n + 1);
    }
}

int main()
{

    kryss(0, 0, 1919, 1079, 1);

    cout << "\n\n";
    return 0;
}

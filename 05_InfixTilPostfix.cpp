

#include <iostream>
#include <stack>
using namespace std;

void skriv(stack<char> st)
{
    while (!st.empty())
    {
        cout << ' ' << st.top();
        st.pop();
    }
    cout << '\n';
}

int main()
{
    stack<char> stakk;
    char tegn;

    cout << "\n\nSkriv et infix-regneuttrykk:\n";

    while ((tegn = cin.get()) != '\n')
    {
        if (tegn == ')')
        {
            cout << stakk.top();
            stakk.pop();
        }
        else if (tegn == '+' || tegn == '*')
            stakk.push(tegn);

        while (tegn >= '0' && tegn <= '9')
        {
            cout << tegn;
            tegn = cin.get();
        }

        if (tegn != '(')
            cout << ' ';
    }

    cout << "\n\n";
    return 0;
}

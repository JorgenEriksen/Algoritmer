

#include <iostream>
#include <stack>
using namespace std;

void skriv(stack<int> st)
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
    stack<int> stakk;
    char tegn;
    int tall;

    cout << "\n\nSkriv et postfix-regneuttrykk:\n";

    while ((tegn = cin.get()) != '\n')
    {
        tall = 0;
        while (tegn == ' ')
            tegn = cin.get();

        if (tegn == '+')
        {
            tall = stakk.top();
            stakk.pop();
            tall += stakk.top();
            stakk.pop();
        }
        else if (tegn == '*')
        {
            tall = stakk.top();
            stakk.pop();
            tall *= stakk.top();
            stakk.pop();
        }

        while (tegn >= '0' && tegn <= '9')
        {

            tall = (10 * tall) + (tegn - '0');
            tegn = cin.get();
        }

        stakk.push(tall);
    }

    cout << "\n\nSvaret er:  " << stakk.top() << "\n\n";
    stakk.pop();

    return 0;
}

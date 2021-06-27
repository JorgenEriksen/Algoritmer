#include <iostream> //  cout
#include <string>   //  string
using namespace std;

template <typename T>
class Stack
{

private:
    T *data;
    int kapasitet, antall;

public:
    Stack(const int lengde = 200)
    {
        data = new T[lengde];
        kapasitet = lengde;
        antall = 0;
    }

    ~Stack() { delete[] data; }

    void display() const
    {
        for (int i = 0; i < antall; i++)
            cout << i << ": " << data[i] << "  ";
        cout << "\n\t'antall': " << antall << '\n';
    }

    bool empty() const { return (antall == 0); }

    T pop()
    {
        if (!empty())
            return (data[--antall]);
        else
            cout << "\nStack is empty!\n\n";
        return 0;
    }

    void push(const T t)
    {
        if (antall < kapasitet)
            data[antall++] = t;
        else
            cout << "\nStack is already full!\n\n";
    }
};

int main()
{
    Stack<int> iStakk;
    Stack<char> cStakk;
    Stack<string> sStakk;

    iStakk.push(29);
    iStakk.push(22);
    iStakk.push(17);
    iStakk.push(7);
    iStakk.push(6);
    iStakk.display();

    cout << "\npop: " << iStakk.pop() << "  pop: " << iStakk.pop() << '\n';
    iStakk.display();

    iStakk.pop();
    iStakk.pop();
    iStakk.pop();
    iStakk.display();

    iStakk.pop();

    cStakk.push('G');
    cStakk.pop();
    cStakk.pop();

    sStakk.push("Bananmos");
    sStakk.pop();

    return 0;
}

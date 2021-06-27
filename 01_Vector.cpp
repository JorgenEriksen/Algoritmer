#include <iostream> //  cout
#include <string>   //  string
using namespace std;

template <typename T>
class Vector
{
private:
    T *data;
    int kapasitet, antall;

public:
    Vector(const int lengde = 200)
    {
        data = new T[lengde];
        kapasitet = lengde;
        antall = 0;
    }
    ~Vector() { delete[] data; }
    int capacity() const { return kapasitet; }
    void clear()
    {
        antall = 0;
    }
    void display() const
    {
        for (int i = 0; i < antall; i++)
            cout << i << ": " << data[i] << "  ";
        cout << "\n\t'antall': " << antall << '\n';
    }
    bool empty() const { return (antall == 0); }
    T get(const int pos) const
    {
        if (pos >= 0 && pos < antall)
            return data[pos];
        else
        {
            cout << "\nIndex out of bounds .....\n\n";
            return 0;
        }
    }
    bool insert(const int pos, const T t)
    {
        if (antall < kapasitet)
        {
            if (pos >= 0 && pos <= antall)
            {
                for (int i = antall; i > pos; i--)
                    data[i] = data[i - 1];
                data[pos] = t;
                antall++;
                return true;
            }
            else
                cout << "\nIndex out of bounds .....\n\n";
        }
        else
            cout << "\nVector is already full!\n\n";
        return false;
    }
    T pop_back()
    {
        if (!empty())
        {
            T siste = data[antall - 1];
            antall--;
            return siste;
        }
        else
            cout << "\nEmpty Vector - impossible to pop!\n\n";
        return 0;
    }
    T pop_front()
    {
        if (!empty())
        {
            T forste = data[0];
            remove(0);
            return forste;
        }
        else
            cout << "\nEmpty Vector - impossible to pop!\n\n";
        return 0;
    }
    bool push_back(const T t)
    {
        return insert(antall, t);
    }
    bool push_front(const T t)
    {
        return insert(0, t);
    }
    bool remove(const int pos)
    {
        if (pos >= 0 && pos < antall)
        {
            for (int i = pos; i < antall - 1; i++)
                data[i] = data[i + 1];
            antall--;
            return true;
        }
        else
        {
            cout << "\nIndex out of bounds .....\n\n";
            return false;
        }
    }
    void resize(const int nyLengde)
    {
    }
    void set(const int pos, const T verdi)
    {
        if (pos >= 0 && pos < antall)
            data[pos] = verdi;
        else
            cout << "\nIndex out of bounds .....\n\n";
    }
    int size() const { return antall; }
};

int main()
{
    Vector<int> iVec;
    Vector<char> cVec;
    Vector<string> sVec;
    sVec.push_back("AA");
    sVec.push_back("BB");
    sVec.push_front("CC");
    sVec.push_front("DD");
    cout << "capacity: " << sVec.capacity()
         << ",  size: " << sVec.size() << '\n';
    sVec.display();
    sVec.remove(3);
    sVec.remove(0);
    sVec.display();
    sVec.pop_back();
    sVec.pop_front();
    sVec.display();
    sVec.push_back("EE");
    sVec.push_back("FF");
    sVec.push_front("GG");
    sVec.push_front("HH");
    sVec.display();
    sVec.insert(2, "II");
    sVec.insert(0, "JJ");
    sVec.insert(6, "KK");
    sVec.insert(7, "PP");
    sVec.insert(8, "QQ");
    sVec.display();
    sVec.set(6, "MM");
    sVec.set(3, "NN");
    sVec.display();
    cout << "Nr.3: " << sVec.get(3) << " Nr.6: " << sVec.get(6) << '\n';
    return 0;
}

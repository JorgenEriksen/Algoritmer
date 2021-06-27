

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Queue
{

private:
    T *data;
    int kapasitet, antall,
        forste, siste;

public:
    Queue(const int lengde = 200)
    {
        data = new T[lengde];
        kapasitet = lengde;
        antall = forste = siste = 0;
    }

    ~Queue() { delete[] data; }

    void display() const
    {
        int indeks = forste;
        for (int i = 0; i < antall; i++)
        {
            cout << indeks << ": " << data[indeks++] << "  ";
            if (indeks == kapasitet)
                indeks = 0;
        }
        cout << "\n\t'antall': " << antall << "\t'forste': "
             << forste << "\t'siste': " << siste << '\n';
    }

    bool empty() const { return (antall == 0); }

    T get()
    {
        T verdi;
        if (!empty())
        {
            verdi = data[forste++];
            antall--;
            if (forste == kapasitet)
                forste = 0;
            return verdi;
        }
        else
            cout << "\nQueue is empty!\n\n";
        return 0;
    }

    void put(const T t)
    {
        if (antall < kapasitet)
        {
            data[siste++] = t;
            antall++;
            if (siste == kapasitet)
                siste = 0;
        }
        else
            cout << "\nQueue is already full!\n\n";
    }
};

int main()
{
    Queue<int> iKo;
    Queue<char> cKo;
    Queue<string> sKo;

    iKo.put(29);
    iKo.put(22);
    iKo.put(17);
    iKo.put(7);
    iKo.put(6);
    iKo.display();

    cout << "\nget: " << iKo.get();
    cout << "  get: " << iKo.get() << '\n';
    iKo.display();

    iKo.get();
    iKo.get();
    iKo.get();
    iKo.display();

    iKo.get();

    iKo.put(304);
    iKo.put(312);
    iKo.get();
    iKo.display();
    iKo.get();
    iKo.display();

    cKo.put('G');
    cKo.get();
    cKo.get();

    sKo.put("Bananmos");
    sKo.get();

    return 0;
}

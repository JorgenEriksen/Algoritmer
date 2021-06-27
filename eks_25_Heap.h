

#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T>
class Heap
{
private:
    T *data;
    int lengde,
        antall;
    T sentinelKey;

    void upHeap(int keyNr)
    {
        T verdi = data[keyNr];
        data[0] = sentinelKey;
        while (data[keyNr / 2] < verdi)
        {
            data[keyNr] = data[keyNr / 2];
            keyNr = keyNr / 2;
        }
        data[keyNr] = verdi;
    }

public:
    Heap(const int len = 200)
    {
        data = new T[len];
        lengde = len;
        antall = 0;
        if (typeid(T) == typeid(int))
            sentinelKey = 1000000;
        else if (typeid(T) == typeid(unsigned char))
            sentinelKey = static_cast<unsigned char>(255);
    }

    ~Heap() { delete[] data; }

    void change(const int keyNr, const T nyVerdi)
    {
    }

    void display() const
    {
        for (int i = 1; i <= antall; i++)
            cout << ' ' << data[i];
    }

    void downHeap(T arr[], const int ant, int keyNr)
    {
        int j;
        T verdi = arr[keyNr];
        while (keyNr <= ant / 2)
        {
            j = 2 * keyNr;

            if (j < ant && arr[j] < arr[j + 1])
                j++;
            if (verdi >= arr[j])
                break;
            arr[keyNr] = arr[j];
            keyNr = j;
        }
        arr[keyNr] = verdi;
    }

    void extract(const int keyNr)
    {
    }

    void insert(const T verdi)
    {
        if (antall < lengde - 1)
        {
            data[++antall] = verdi;
            upHeap(antall);
        }
        else
            cout << "\nHeapen er full med " << lengde
                 << " elementer (inkl. sentinel key)!\n\n";
    }

    T remove()
    {
        if (antall > 0)
        {
            T verdi = data[1];
            data[1] = data[antall--];
            downHeap(data, antall, 1);
            return verdi;
        }
        else
        {
            cout << "\nHeapen er helt tom - ingenting i 'remove'!\n\n";
            return sentinelKey;
        }
    }

    T replace(const T verdi)
    {
        data[0] = verdi;
        downHeap(data, antall, 0);
        return data[0];
    }
};

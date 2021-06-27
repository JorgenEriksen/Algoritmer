

#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

enum HashType
{
    LinearProbing,
    DoubleHashing
};

class Hashing
{
private:
    char *tabell;
    int lengde;
    HashType hType;

    int hash1(const int modVerdi, const int kVerdi)
    {
        return (kVerdi % modVerdi);
    }

    int hash2(const int hashVerdi, const int kVerdi)
    {
        return (hashVerdi - (kVerdi % hashVerdi));
    }

    int kVerdi(char bokstav)
    {
        bokstav = toupper(bokstav);
        if (bokstav >= 'A' && bokstav <= 'Z')
            return (static_cast<int>(bokstav - 'A') + 1);
        else
            return 0;
    }

public:
    Hashing(const HashType hT, const int len)
    {
        lengde = len;
        hType = hT;
        tabell = new char[len];
        for (int i = 0; i < lengde; i++)
            tabell[i] = '-';
    }

    ~Hashing() { delete[] tabell; }

    void display() const
    {
        for (int i = 0; i < lengde; i++)
            cout << setw(3) << i << ':';
        cout << '\n';
        for (int i = 0; i < lengde; i++)
            cout << "  " << tabell[i] << ' ';
        cout << "\n\n";
    }

    void insert(const int hashVerdi, const char data)
    {
        int dataTilK = kVerdi(data);
        int indeks = hash1(lengde, dataTilK);
        int tillegg = hash2(hashVerdi, dataTilK);

        while (tabell[indeks] != '-')
        {

            indeks = (hType == LinearProbing) ? (indeks + 1) : (indeks + tillegg);
            indeks %= lengde;
        }
        tabell[indeks] = data;
        display();
    }
};

int main()
{
    char tegn;

    char tekst1[] = "EPLEROGBANANER";
    char tekst2[] = "KRAGEROSTAVERN";

    Hashing hashTabell1(LinearProbing, 17);

    Hashing hashTabell2(DoubleHashing, 17);

    for (int i = 0; i <= 13; i++)
        hashTabell1.insert(4, tekst1[i]);
    cout << "\t\t\t\t\tSkriv ett tegn: .....";
    cin >> tegn;

    for (int i = 0; i <= 13; i++)
        hashTabell2.insert(4, tekst2[i]);
    cout << "\t\t\t\t\tSkriv ett tegn: .....";
    cin >> tegn;

    cout << "\n\n";
    return 0;
}

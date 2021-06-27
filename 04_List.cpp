

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class List
{

private:
    struct Node
    {
        T data;
        Node *neste;
        Node(const T d)
        {
            data = d;
            neste = nullptr;
        }
    };

    Node *hode;
    int antallNoder;

public:
    List(const T t)
    {
        hode = new Node(t);
        antallNoder = 0;
    }

    ~List()
    {
        Node *np;
        while (hode)
        {
            np = hode->neste;
            delete hode;
            hode = np;
        }
    }

    void display() const
    {
        Node *np = hode->neste;
        while (np)
        {
            cout << '\t' << np->data << '\n';
            np = np->neste;
        }
        cout << "\n\tAntall noder i listen:  " << antallNoder << '\n';
    }

    bool empty() const { return (antallNoder == 0); }

    bool find(const T t) const
    {
        Node *np = hode->neste;
        while (np && np->data < t)
            np = np->neste;
        return (np && np->data == t);
    }

    void insert(const T t)
    {
        Node *np = hode,
             *nyNode = new Node(t);

        while (np->neste && np->neste->data < nyNode->data)
            np = np->neste;

        nyNode->neste = np->neste;
        np->neste = nyNode;
        antallNoder++;
    }

    T remove(const T t)
    {
        Node *np = hode,
             *np2 = hode->neste;
        while (np2 && np2->data < t)
        {
            np = np2;
            np2 = np2->neste;
        }

        if (np2 && np2->data == t)
        {
            np->neste = np2->neste;
            np2->neste = nullptr;
            antallNoder--;
            return np2->data;
        }
        else
            return 0;
    }

    T removeNo(const int no)
    {
        Node *np = hode,
             *np2 = hode->neste;
        if (no >= 1 && no <= antallNoder)
        {
            for (int i = 1; i < no; i++)
            {
                np = np2;
                np2 = np2->neste;
            }
            np->neste = np2->neste;
            np2->neste = nullptr;
            antallNoder--;
            return np2->data;
        }
        else
            cout << "\nNumber out of bounds .....\n\n";
        return 0;
    }

    int size() const { return antallNoder; }
};

int main()
{
    List<string> liste("");

    liste.insert("Oslo");
    liste.insert("Bergen");
    liste.insert("Molde");
    liste.insert("Nas");
    liste.insert("Armenistis");
    liste.insert("Hamar");
    liste.display();

    cout << "\nHamar finnes";
    if (!liste.find("Hamar"))
        cout << " IKKE!";
    cout << "\nLarvik finnes";
    if (!liste.find("Larvik"))
        cout << " IKKE!";
    cout << '\n';

    if (liste.remove("Molde") == "")
        cout << "� fjerne 'Molde' mislyktes!\n";
    if (liste.remove("Oslo") == "")
        cout << "� fjerne 'Oslo' mislyktes!\n";

    liste.display();

    cout << "Fjernet nr.3: " << liste.removeNo(3);
    liste.display();
    cout << "Fjernet nr.3: " << liste.removeNo(3);
    liste.display();
    cout << "Fjernet nr.1: " << liste.removeNo(1);
    liste.display();

    List<int> liste2(0);
    liste2.insert(29);
    liste2.insert(17);
    liste2.insert(22);
    liste2.display();

    if (liste2.remove(312) == 0)
        cout << "\n\nFant ikke 312!\n";
    if (liste2.removeNo(6) == 0)
        cout << "Fant ikke nr.6!\n";

    cout << "\n\n";
    return 0;
}



#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

template <typename Data, typename MerData>
class BST
{
private:
    struct Node
    {
        Data data;
        MerData merData;
        Node *left, *right;

        Node(const Data d, const MerData md)
        {
            data = d;
            merData = md;
            left = right = nullptr;
        }
    };

    Node *hode;

    void traverserInorder(Node *node) const
    {
        if (node)
        {
            traverserInorder(node->left);
            cout << '\t' << node->data;
            if (node->left)
                cout << "    V.barn: " << node->left->data;
            if (node->right)
                cout << "    H.barn:    " << node->right->data;
            cout << '\n';
            traverserInorder(node->right);
        }
    }

public:
    BST()
    {
        if (typeid(MerData) == typeid(int))
            hode = new Node(0, 0);
        else if (typeid(MerData) == typeid(char))
            hode = new Node(0, 0);
        else if (typeid(MerData) == typeid(string))
            hode = new Node(0, "");
    }

    ~BST() {}

    void display() const
    {
        traverserInorder(hode->right);
    }

    void insert(const Data verdi, const MerData merData)
    {
        Node *mor = hode,
             *node = hode->right;

        if (node)
        {
            while (node)
            {
                mor = node;

                node = (verdi < node->data) ? node->left : node->right;
            }
            node = new Node(verdi, merData);
            if (verdi < mor->data)
                mor->left = node;
            else
                mor->right = node;
        }
        else
            hode->right = new Node(verdi, merData);
    }

    bool remove(const Data verdi)
    {
        Node *morFjernes,
            *fjernes,
            *morEtterfolger,
            *etterfolger;

        morFjernes = hode;
        fjernes = hode->right;

        while (fjernes && verdi != fjernes->data)
        {
            morFjernes = fjernes;

            fjernes = (verdi < fjernes->data) ? fjernes->left : fjernes->right;
        }

        if (!fjernes)
            return false;

        etterfolger = fjernes;

        if (!fjernes->right)
            etterfolger = etterfolger->left;

        else if (!fjernes->right->left)
        {
            etterfolger = etterfolger->right;
            etterfolger->left = fjernes->left;
        }

        else
        {
            morEtterfolger = etterfolger->right;

            while (morEtterfolger->left->left)
                morEtterfolger = morEtterfolger->left;

            etterfolger = morEtterfolger->left;

            morEtterfolger->left = etterfolger->right;

            etterfolger->left = fjernes->left;
            etterfolger->right = fjernes->right;
        }

        delete fjernes;

        if (verdi < morFjernes->data)
            morFjernes->left = etterfolger;
        else
            morFjernes->right = etterfolger;

        return true;
    }

    MerData search(const Data verdi) const
    {
        Node *node = hode->right;
        while (node && node->data != verdi)
            node = (verdi < node->data) ? node->left : node->right;

        if (node)
            return node->merData;
        else
            return hode->merData;
    }
};

int main()
{
    BST<char, string> bst;

    bst.insert('L', "Liam");
    bst.insert('C', "Charlie");
    bst.insert('F', "Frank");
    bst.insert('T', "Tony");
    bst.insert('P', "Pat");
    bst.insert('N', "Nigel");
    bst.insert('S', "Steve");
    bst.insert('R', "Ray");
    bst.insert('I', "Ian");
    bst.insert('O', "Oliver");
    bst.display();
    cout << "\n\n";

    cout << "MerData hentet: " << bst.search('C') << '\n';
    cout << "MerData hentet: " << bst.search('N') << '\n';
    cout << "MerData hentet: " << bst.search('Q') << '\n';

    if (bst.remove('L'))
        cout << "\nFjernet 'L':\n";
    bst.display();

    if (bst.remove('T'))
        cout << "\nFjernet 'T':\n";
    bst.display();

    if (bst.remove('C'))
        cout << "\nFjernet 'C':\n";
    bst.display();

    cout << "\n\n";
    return 0;
}

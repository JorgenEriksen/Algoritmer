

#include <iostream>
using namespace std;

struct Node
{
    int ID;
    Node *left, *right;
    Node(const char id, Node *l, Node *r)
    {
        ID = id;
        left = l;
        right = r;
    }
};

Node *gRoot = nullptr;

void hoyreGren()
{
    Node *node = gRoot;
    while (node)
    {
        cout << node->ID << ' ';

        node = (node->right) ? node->right : node->left;
    }
}

void gren(Node *node)
{
    int id = node->ID;
    node = gRoot;
    while (node)
    {
        cout << node->ID << ' ';

        node = (id < node->ID) ? node->left : node->right;
    }
}

void grener(Node *node)
{
    if (node)
    {
        if (!node->left && !node->right)
        {
            gren(node);
            cout << '\n';
        }
        else
        {
            grener(node->left);
            grener(node->right);
        }
    }
}

int main()
{
    Node *n6, *n8, *n11a, *n11b, *n12, *n13a, *n13b,
        *n17, *n28, *n31, *n33, *n34, *n35a, *n35b, *n39;

    n8 = new Node(8, nullptr, nullptr);
    n11b = new Node(11, nullptr, nullptr);
    n13b = new Node(13, nullptr, nullptr);
    n31 = new Node(31, nullptr, nullptr);
    n34 = new Node(34, nullptr, nullptr);
    n35b = new Node(35, nullptr, nullptr);
    n12 = new Node(12, n11b, nullptr);
    n39 = new Node(39, n35b, nullptr);
    n6 = new Node(6, nullptr, n8);
    n13a = new Node(13, n12, n13b);
    n28 = new Node(28, nullptr, n31);
    n35a = new Node(35, n34, n39);
    n11a = new Node(11, n6, n13a);
    n33 = new Node(33, n28, n35a);
    n17 = new Node(17, n11a, n33);
    gRoot = n17;

    cout << "\n\nTester oppgave A:\n";
    hoyreGren();
    cout << "\n\n\n";

    cout << "Tester oppgave B:\n";
    gren(n31);
    cout << '\n';
    gren(n8);
    cout << '\n';
    gren(n35b);
    cout << '\n';
    gren(n13b);
    cout << '\n';
    gren(n11b);
    cout << '\n';
    gren(n34);
    cout << "\n\n\n";

    cout << "Tester oppgave C:\n";
    grener(gRoot);

    cout << "\n\n";
    return 0;
}

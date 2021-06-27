

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct Node
{
    int verdi;
    char ID;
    int sum;
    Node *left;
    Node *right;
    Node *forelder;
};

void besok(Node *node);
Node *generate(const int depth, const int probability);
void settForelder(Node *node);
void settSum(Node *node);
void traverse(Node *node);

Node *gRoot = nullptr;
int gNumber = 0;

int main()
{
    char ch;

    srand(0);

    cout << "\nNodene i starttreet:\n";

    gRoot = generate(5, 80);
    traverse(gRoot);
    cin >> ch;

    cout << "\n\nTester oppgave A - Nodene etter at 'sum' er satt:\n";
    settSum(gRoot);
    traverse(gRoot);
    cin >> ch;

    cout << "\n\nTester oppgave B - Nodene etter at 'forelder' er satt:\n";
    settForelder(gRoot);
    traverse(gRoot);

    cout << "\n\n";
    return 0;
}

void besok(Node *node)
{
    cout << setw(4) << node->verdi << " -  ID: " << node->ID
         << "   sum:" << setw(4) << node->sum;
    if (node->forelder)
        cout << "   'mor': " << node->forelder->ID;
    cout << '\n';
}

Node *generate(const int depth, const int probability)
{
    Node *rot = nullptr;

    if (depth > 0)
    {
        if (rand() % 100 < probability)
        {
            rot = new Node;
            rot->left = generate(depth - 1, probability);

            rot->verdi = ++gNumber;
            rot->ID = static_cast<char>('A' - 1 + gNumber);
            rot->sum = 0;
            rot->forelder = nullptr;

            rot->right = generate(depth - 1, probability);
        }
    }
    return rot;
}

void settForelder(Node *node)
{
    if (node)
    {
        settForelder(node->left);
        settForelder(node->right);
        node->forelder = nullptr;
        if (node->left)
            node->left->forelder = node;
        if (node->right)
            node->right->forelder = node;
    }
}

void settSum(Node *node)
{
    if (node)
    {
        settSum(node->left);
        settSum(node->right);
        node->sum = node->verdi;
        if (node->left)
            node->sum += node->left->sum;
        if (node->right)
            node->sum += node->right->sum;
    }
}

void traverse(Node *node)
{
    if (node)
    {
        traverse(node->left);
        besok(node);
        traverse(node->right);
    }
}

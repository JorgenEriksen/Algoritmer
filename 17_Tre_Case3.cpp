

#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    char ID;
    int nivaa;
    Node *left;
    Node *right;
    Node()
    {
        ID = '-';
        nivaa = 0;
        left = right = nullptr;
    }
};

void besok(Node *node);
void bladTilRot(Node *node, Node *blad);
void finnVerdier(Node *node, int &sumNivaa, int &antall);
Node *generate(const int depth, const int probability);
void settNivaa(Node *node);
void skrivForfedre(Node *node);
void traverse(Node *node);

Node *gRoot;
int gNumber = 65;

int main()
{
    int sumNiva = 0, antall = 0;
    char ch;

    srand(0);

    cout << "\nNodene i starttreet:\n";

    gRoot = generate(5, 80);
    traverse(gRoot);
    cin >> ch;

    cout << "\n\nTester oppgave A - Nodene etter at 'nivaa' er satt:\n";
    settNivaa(gRoot);
    traverse(gRoot);
    cin >> ch;

    cout << "\n\nTester oppgave B - Finner niv�er TOTALT og antall noder:\n";
    finnVerdier(gRoot, sumNiva, antall);

    cout << "Gjennomsnittsniv�et i treet:  "
         << static_cast<float>(sumNiva) / antall;
    cin >> ch;

    cout << "\n\nTester oppgave C - Alle bladnodenes forfedre:\n";
    skrivForfedre(gRoot);
    cout << "\n\n";
    return 0;
}

void besok(Node *node)
{
    cout << ' ' << node->ID << ":  " << node->nivaa << '\n';
}

void bladTilRot(Node *node, Node *blad)
{
    if (node != blad)
    {

        if (blad->ID < node->ID)
            bladTilRot(node->left, blad);

        else
            bladTilRot(node->right, blad);
    }
    cout << node->ID << ' ';
    if (node == gRoot)
        cout << '\n';
}

void finnVerdier(Node *node, int &sumNivaa, int &antall)
{
    if (node)
    {
        sumNivaa += node->nivaa;
        antall++;

        finnVerdier(node->left, sumNivaa, antall);
        finnVerdier(node->right, sumNivaa, antall);
    }
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
            rot->ID = static_cast<char>(gNumber++);
            rot->right = generate(depth - 1, probability);
        }
    }
    return rot;
}

void settNivaa(Node *node)
{

    if (node->left)
    {
        node->left->nivaa = node->nivaa + 1;
        settNivaa(node->left);
    }

    if (node->right)
    {
        node->right->nivaa = node->nivaa + 1;
        settNivaa(node->right);
    }
}

void skrivForfedre(Node *node)
{
    if (node)
    {
        if (!node->left && !node->right)
        {

            cout << '\t';
            Node *q = gRoot;
            while (true)
            {
                cout << q->ID << ' ';
                if (node->ID < q->ID)
                    q = q->left;
                else if (node->ID > q->ID)
                    q = q->right;
                else
                    break;
            }
            cout << '\n';
        }
        else
        {
            skrivForfedre(node->left);
            skrivForfedre(node->right);
        }
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

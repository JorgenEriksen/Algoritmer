

#include <iostream>
#include <iomanip>
using namespace std;

struct Node
{
    char ID;
    Node *left, *right;
    Node(char id)
    {
        ID = id;
        left = right = nullptr;
    }
};

void besok(const Node *node);
Node *byggTre();
void traverserInorder(Node *node);
void traverserPostorder(Node *node);
void traverserPreorder(Node *node);

int gNivaa = -1;
int gNr;

int main()
{
    Node *root;

    root = byggTre();

    gNr = 0;

    cout << "\n\nPreorder traversering:\n";
    traverserPreorder(root);

    gNr = 0;
    cout << "\n\nInorder traversering:\n";
    traverserInorder(root);

    gNr = 0;
    cout << "\n\nPostorder traversering:\n";
    traverserPostorder(root);

    cout << "\n\n";
    return 0;
}

void besok(const Node *node)
{
    cout << setw(6) << ++gNr << ": " << node->ID
         << "  p� niv�: " << gNivaa << '\n';
}

Node *byggTre()
{

    Node *noder[15];
    for (int i = 0; i < 15; i++)
        noder[i] = new Node(static_cast<char>('A' + i));

    noder[0]->left = noder[1];
    noder[0]->right = noder[2];
    noder[1]->left = noder[3];
    noder[1]->right = noder[4];
    noder[2]->left = noder[5];
    noder[3]->left = noder[6];
    noder[3]->right = noder[7];
    noder[4]->right = noder[8];
    noder[5]->left = noder[9];
    noder[6]->right = noder[10];
    noder[7]->left = noder[11];
    noder[7]->right = noder[12];
    noder[8]->left = noder[13];
    noder[9]->right = noder[14];
    return noder[0];
}

void traverserInorder(Node *node)
{
    if (node)
    {
        gNivaa++;
        traverserInorder(node->left);
        besok(node);
        traverserInorder(node->right);
        gNivaa--;
    }
}

void traverserPostorder(Node *node)
{
    if (node)
    {
        gNivaa++;
        traverserPostorder(node->left);
        traverserPostorder(node->right);
        besok(node);
        gNivaa--;
    }
}

void traverserPreorder(Node *node)
{
    if (node)
    {
        gNivaa++;
        besok(node);
        traverserPreorder(node->left);
        traverserPreorder(node->right);
        gNivaa--;
    }
}

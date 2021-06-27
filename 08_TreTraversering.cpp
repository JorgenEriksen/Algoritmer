

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node
{
    char ID;
    bool besokt;
    Node *left, *right;
    Node(char id)
    {
        ID = id;
        left = right = nullptr;
        besokt = false;
    }
};

void besok(const Node *node);
Node *byggTre();
void traverserInorder(Node *node);
void traverserLevelorder(Node *node);
void traverserPostorder(Node *node);
void traverserPreorder(Node *node);

stack<Node *> gStakk;
queue<Node *> gKo;

int main()
{
    Node *root;

    root = byggTre();

    cout << "\n\nPreorder traversering:\n\t";
    traverserPreorder(root);

    cout << "\n\nLevelorder traversering:\n\t";
    traverserLevelorder(root);

    cout << "\n\nInorder traversering:\n\t";
    traverserInorder(root);

    cout << "\n\nPostorder traversering:\n\t";
    traverserPostorder(root);

    cout << "\n\n";
    return 0;
}

void besok(const Node *node)
{
    cout << ' ' << node->ID;
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
    while (node || !gStakk.empty())
    {
        if (node)
        {
            gStakk.push(node);
            node = node->left;
        }
        else
        {
            node = gStakk.top();
            gStakk.pop();
            besok(node);
            node = node->right;
        }
    }
}

void traverserLevelorder(Node *node)
{
    if (node)
    {
        gKo.push(node);
        while (!gKo.empty())
        {
            node = gKo.front();
            gKo.pop();
            besok(node);
            if (node->left)
                gKo.push(node->left);
            if (node->right)
                gKo.push(node->right);
        }
    }
}

void traverserPostorder(Node *node)
{
}

void traverserPreorder(Node *node)
{
    if (node)
    {
        gStakk.push(node);
        while (!gStakk.empty())
        {
            node = gStakk.top();
            gStakk.pop();
            besok(node);
            if (node->right)
                gStakk.push(node->right);
            if (node->left)
                gStakk.push(node->left);
        }
    }
}

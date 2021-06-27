

#include <iostream>
#include <stack>
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

void travserPostorder(const Node *node);
void travserInorder(const Node *node);

int main()
{
    stack<Node *> stakk;
    char tegn;
    Node *nyNode;

    cout << "\n\nSkriv et postfix-regneuttrykk:\n";

    tegn = cin.get();
    while (tegn != '\n')
    {
        while (tegn == ' ')
            tegn = cin.get();
        nyNode = new Node(tegn);
        if (tegn == '+' || tegn == '*')
        {
            nyNode->right = stakk.top();
            stakk.pop();
            nyNode->left = stakk.top();
            stakk.pop();
        }
        stakk.push(nyNode);
        tegn = cin.get();
    }

    cout << "\n\n";
    travserPostorder(stakk.top());
    cout << "\n\n";
    travserInorder(stakk.top());
    cout << "\n\n";

    return 0;
}

void travserPostorder(const Node *node)
{
    if (node)
    {
        travserPostorder(node->left);
        travserPostorder(node->right);
        cout << ' ' << node->ID;
    }
}

void travserInorder(const Node *node)
{
    if (node)
    {
        if (node->left)
            cout << '(';
        travserInorder(node->left);
        cout << ' ' << node->ID;
        travserInorder(node->right);
        if (node->right)
            cout << ')';
    }
}

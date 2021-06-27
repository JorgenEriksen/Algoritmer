

#include <iostream>
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

Node *gRoot = nullptr;
Node *gNoder[10];
Node *gNode1 = nullptr,
     *gNode2 = nullptr,
     *gForrige = nullptr;
int gMaxHOB = -1;
int gNivaa = -1;
char gKeyer[101];
int gNr = 0;

void besokOppgA(Node *node);
void besokOppgC(Node *node);
Node *byggTre();
void finnNoder(Node *node);
void insertionSort(char arr[], const int N);
void traverserInorder(Node *node);
void traverserInorder2(Node *node);
void traverserOppgA(Node *node);
void traverserOppgB(Node *node);

int main()
{
    char ch;

    gRoot = byggTre();
    traverserInorder(gRoot);

    cout << "\n\nTester oppgave A - Finner maxniv�et for oddetalls bladnode:\n";
    traverserOppgA(gRoot);
    cout << "H�yeste niv� for oddetalls terminalnode er: " << gMaxHOB << '\n';

    cout << "\n\nTester oppgave B - Gj�r om til bin�rt s�ketre:\n";

    gNr = 0;
    traverserOppgB(gRoot);
    gKeyer[0] = '\0';
    insertionSort(gKeyer, gNr);

    gNr = 0;
    traverserInorder2(gRoot);

    cout << "Bin�rt s�ketre, traversert inorder (dvs. alfabetisk utskrift):\n";
    traverserInorder(gRoot);

    cout << "\n\n\nTester oppgave C - Finner to stk ombyttede noder:\n";
    cout << "Bytter 'G' og 'S'. \n";
    ch = gNoder[7]->ID;
    gNoder[7]->ID = gNoder[9]->ID;
    gNoder[9]->ID = ch;
    traverserInorder(gRoot);

    finnNoder(gRoot);

    cout << "\nBytter tilbake 'node1' og 'node2'. \n";
    ch = gNode1->ID;
    gNode1->ID = gNode2->ID;
    gNode2->ID = ch;
    traverserInorder(gRoot);

    gNode1 = gNode2 = gForrige = nullptr;
    cout << "\n\nBytter 'E' (rota) og 'O'. \n";
    ch = gNoder[1]->ID;
    gNoder[1]->ID = gNoder[8]->ID;
    gNoder[8]->ID = ch;
    traverserInorder(gRoot);

    finnNoder(gRoot);

    cout << "\nBytter tilbake 'node1' og 'node2'. \n";
    ch = gNode1->ID;
    gNode1->ID = gNode2->ID;
    gNode2->ID = ch;
    traverserInorder(gRoot);

    cout << "\n\n";
    return 0;
}

void besokOppgA(Node *node)
{
    if (!node->left && !node->right && (gNivaa % 2) && (gNivaa > gMaxHOB))
        gMaxHOB = gNivaa;
}

void besokOppgC(Node *node)
{
    if (gForrige)
    {
        if (gForrige->ID > node->ID)
        {
            if (!gNode1)
                gNode1 = gForrige;
            else
                gNode2 = node;
        }
    }
    gForrige = node;
}

Node *byggTre()
{
    gNoder[1] = new Node('A');
    gNoder[2] = new Node('G');
    gNoder[3] = new Node('E');
    gNoder[4] = new Node('O');
    gNoder[5] = new Node('S');
    gNoder[6] = new Node('A');
    gNoder[7] = new Node('R');
    gNoder[8] = new Node('N');
    gNoder[9] = new Node('L');
    gNoder[1]->left = gNoder[2];
    gNoder[1]->right = gNoder[3];
    gNoder[2]->right = gNoder[4];
    gNoder[3]->left = gNoder[5];
    gNoder[3]->right = gNoder[6];
    gNoder[5]->left = gNoder[7];
    gNoder[6]->left = gNoder[8];
    gNoder[6]->right = gNoder[9];
    return gNoder[1];
}

void finnNoder(Node *node)
{
    if (node)
    {
        finnNoder(node->left);
        besokOppgC(node);
        finnNoder(node->right);
    }
}

void insertionSort(char arr[], const int N)
{
    int i, j;
    char v;
    for (i = 2; i <= N; i++)
    {
        v = arr[i];
        j = i;
        while (arr[j - 1] > v)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = v;
    }
}

void traverserInorder(Node *node)
{
    if (node)
    {
        traverserInorder(node->left);
        cout << ' ' << node->ID;
        traverserInorder(node->right);
    }
}

void traverserInorder2(Node *node)
{
    if (node)
    {
        traverserInorder2(node->left);
        node->ID = gKeyer[++gNr];

        traverserInorder2(node->right);
    }
}

void traverserOppgA(Node *node)
{
    if (node)
    {
        gNivaa++;
        besokOppgA(node);
        traverserOppgA(node->left);
        traverserOppgA(node->right);

        gNivaa--;
    }
}

void traverserOppgB(Node *node)
{
    if (node)
    {
        traverserOppgB(node->left);
        traverserOppgB(node->right);
        gKeyer[++gNr] = node->ID;
    }
}

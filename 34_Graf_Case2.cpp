

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

const int MAXNODER = 100;
const int MAXNABOER = 10;
enum Status
{
    USETT,
    SETT
};

struct Node
{
    int ID;
    int antKanter;
    Node *nabo[MAXNABOER];
    Node *kopi;
    Status status;
    Node(const int id, const int ant)
    {
        ID = id;
        antKanter = ant;
        kopi = nullptr;
        status = USETT;
    }
};

Node *gNoder[MAXNODER];

int gTotAntNoder;
Node *gGrafen;

void kopierIterativt();
void kopierRekursivt(Node *node);
void lesGrafFraFil();
void nullGraf(Node *node);
void skrivGraf(Node *node);

int main()
{
    char valg;

    lesGrafFraFil();

    gGrafen = gNoder[0];

    cout << "Initiell graf - etter at lest fra fil:";
    skrivGraf(gNoder[0]);
    nullGraf(gNoder[0]);

    cout << "\n\n\nVil du teste I(terativt) eller R(ekursivt):  ";
    cin >> valg;
    valg = toupper(valg);

    if (valg == 'I')
    {

        kopierIterativt();

        cout << "\n\nKopi-grafen ved TO gjennomganger vha. for-l�kker:";
        skrivGraf(gNoder[0]->kopi);
        nullGraf(gNoder[0]->kopi);
    }
    else
    {

        kopierRekursivt(gGrafen);

        cout << "\n\nKopi-grafen ved EN gjennomgang vha. rekursjon:";
        skrivGraf(gGrafen->kopi);
        nullGraf(gGrafen->kopi);
    }

    cout << "\n\n";
    return 0;
}

void kopierIterativt()
{
    int i, j;
    for (i = 0; i < gTotAntNoder; i++)

        gNoder[i]->kopi = new Node(gNoder[i]->ID + 100, gNoder[i]->antKanter);

    for (i = 0; i < gTotAntNoder; i++)
    {
        for (j = 0; j < gNoder[i]->antKanter; j++)
            gNoder[i]->kopi->nabo[j] = gNoder[i]->nabo[j]->kopi;
    }
}

void kopierRekursivt(Node *node)
{
    int j;
    if (node->kopi == nullptr)
    {

        node->kopi = new Node(node->ID + 200, node->antKanter);

        for (j = 0; j < node->antKanter; j++)
        {
            kopierRekursivt(node->nabo[j]);

            node->kopi->nabo[j] = node->nabo[j]->kopi;
        }
    }
}

void lesGrafFraFil()
{
    int i, j,
        id, antKanter;

    ifstream innfil("EKS_34_Graf_Case2.DTA");

    if (innfil)
    {
        cout << "\n\nLeser inn grafen fra 'EKS_34_Graf_Case2.DTA' .....\n\n";

        innfil >> gTotAntNoder;
        for (i = 0; i < gTotAntNoder; i++)
        {
            innfil >> antKanter;
            gNoder[i] = new Node(i, antKanter);
        }

        for (i = 0; i < gTotAntNoder; i++)
            for (j = 0; j < gNoder[i]->antKanter; j++)
            {
                innfil >> id;
                gNoder[i]->nabo[j] = gNoder[id];
            }
    }
    else
        cout << "\n\nFinner ikke filen EKS_34_Graf_Case2.DTA'!\n\n";
}

void nullGraf(Node *node)
{
    if (node->status == SETT)
    {
        node->status = USETT;

        for (int i = 0; i < node->antKanter; i++)
            nullGraf(node->nabo[i]);
    }
}

void skrivGraf(Node *node)
{
    int i;
    if (node->status == USETT)
    {
        node->status = SETT;
        cout << "\n\tNode nr." << node->ID << ", har naboene:   ";
        for (i = 0; i < node->antKanter; i++)
            cout << node->nabo[i]->ID << "  ";
        for (i = 0; i < node->antKanter; i++)
            skrivGraf(node->nabo[i]);
    }
}

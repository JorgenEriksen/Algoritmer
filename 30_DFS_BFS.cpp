

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int ANTNODER = 6;
const int USETT = 0;
const int SENERE = -1;

void BFS(int nr);
void DFS(const int nr);
void DFS_Liste(const int nr);
void initierNaboListe();
void nullstill();
void skriv();

int gNaboMatrise[ANTNODER][ANTNODER] = {{0, 1, 1, 1, 1, 0},
                                        {1, 0, 1, 0, 0, 1},
                                        {1, 1, 0, 0, 0, 0},
                                        {1, 0, 0, 0, 1, 1},
                                        {1, 0, 0, 1, 0, 0},
                                        {0, 1, 0, 1, 0, 0}};

int gBesokt[ANTNODER];
int gBesoktSomNr;

queue<int> gBesokeSenere;
vector<int> gNaboListe[ANTNODER];

int main()
{
    int i;

    cout << "\n\n DYBDE-F�RST-S�K (DFS) vha. nabo-MATRISE:\n";
    nullstill();

    for (i = 0; i < ANTNODER; i++)
        if (gBesokt[i] == USETT)
            DFS(i);

    cout << "\n\n BREDDE-F�RST-S�K (BFS) vha. nabo-MATRISE:\n";
    nullstill();

    for (i = 0; i < ANTNODER; i++)
        if (gBesokt[i] == USETT)
            BFS(i);

    cout << "\n\n DYBDE-F�RST-S�K (DFS) vha. nabo-LISTE:\n";
    nullstill();
    initierNaboListe();

    for (i = 0; i < ANTNODER; i++)
        if (gBesokt[i] == USETT)
            DFS_Liste(i);

    cout << "\n\n";
    return 0;
}

void BFS(int nr)
{
    int j;
    gBesokeSenere.push(nr);
    while (!gBesokeSenere.empty())
    {
        nr = gBesokeSenere.front();
        gBesokeSenere.pop();
        gBesokt[nr] = ++gBesoktSomNr;
        for (j = 0; j < ANTNODER; j++)
            if (gNaboMatrise[nr][j])
                if (gBesokt[j] == USETT)
                {
                    gBesokeSenere.push(j);
                    gBesokt[j] = SENERE;
                }
    }
}

void DFS(const int nr)
{
    gBesokt[nr] = ++gBesoktSomNr;

    for (int j = 0; j < ANTNODER; j++)
        if (gNaboMatrise[nr][j])
            if (gBesokt[j] == USETT)
                DFS(j);
}

void DFS_Liste(const int nr)
{
    int nabo;
    gBesokt[nr] = ++gBesoktSomNr;

    for (unsigned int j = 0; j < gNaboListe[nr].size(); j++)
    {
        nabo = gNaboListe[nr].at(j);

        if (gBesokt[nabo - 1] == USETT)
            DFS_Liste(nabo - 1);
    }
}

void initierNaboListe()
{
    gNaboListe[0].push_back(5);
    gNaboListe[0].push_back(4);
    gNaboListe[0].push_back(2);
    gNaboListe[0].push_back(3);
    gNaboListe[1].push_back(3);
    gNaboListe[1].push_back(1);
    gNaboListe[1].push_back(6);
    gNaboListe[2].push_back(2);
    gNaboListe[2].push_back(1);
    gNaboListe[3].push_back(1);
    gNaboListe[3].push_back(6);
    gNaboListe[3].push_back(5);
    gNaboListe[4].push_back(1);
    gNaboListe[4].push_back(4);
    gNaboListe[5].push_back(4);
    gNaboListe[5].push_back(2);
}

void nullstill()
{
    gBesoktSomNr = 0;
    for (int i = 0; i < ANTNODER; i++)
        gBesokt[i] = USETT;
}

void skriv()
{
    for (int i = 0; i < ANTNODER; i++)
        cout << ' ' << gBesokt[i];
    cout << '\n';
}

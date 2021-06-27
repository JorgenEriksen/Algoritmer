

bool unionerOgFinn2(int nr1, int nr2, const bool unioner)
{
    int i = nr1, j = nr2;

    while (gForeldre[i] > 0)
        i = gForeldre[i];

    while (gForeldre[j] > 0)
        j = gForeldre[j];

    int indeks = 0;
    while (gForeldre[nr1] > 0)
    {
        indeks = nr1;
        nr1 = gForeldre[nr1];
        gForeldre[indeks] = i;
    }

    while (gForeldre[nr2] > 0)
    {
        indeks = nr2;
        nr2 = gForeldre[nr2];
        gForeldre[indeks] = j;
    }

    if (unioner && (i != j))
    {
        if (gForeldre[j] < gForeldre[i])
        {
            gForeldre[j] += gForeldre[i] - 1;

            gForeldre[i] = j;
        }
        else
        {
            gForeldre[i] += gForeldre[j] - 1;

            gForeldre[j] = i;
        }
    }

    return (i == j);
}

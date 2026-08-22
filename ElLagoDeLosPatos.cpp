#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void cambiarPos(vector<char> &patos, vector<int> &indices, int N)
{
    int x = 0;

    if (patos[0] != patos[N - 1])
    {
        x = 1;
        indices[0] = N - 1 + 1;
        indices[N - 1] = 0 + 1;
    }
    for (int i = x; i < N - 1 - x; i++)
    {
        if (patos[i] != patos[i + 1])
        {
            indices[i] = i + 1 + 1;
            indices[i + 1] = i + 1;
        }
    }
    cout << "SI" << endl;
    for (auto caracter : indices)
        cout << caracter << " ";
}

int main()
{
    int N;
    if (!(cin >> N))
        return 0;
    vector<char> patos(N);

    int cantI = 0;
    int cantO = 0;

    for (int i = 0; i < N; i++)
    {

        cin >> patos[i];

        if (patos[i] == 'I')
            cantI++;
        else
            cantO++;
    };

    vector<int> indices(N);

    if (cantI != cantO)
    {
        cout << "NO" << endl;
    }
    else
    {
        cambiarPos(patos, indices, N);
    }

    return 0;
}
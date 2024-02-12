#include <bits/stdc++.h>
using namespace std;

bool v[100000];
int BFS(int move[], int n)
{

    for (int i = 0; i < n; i++)
    {
        v[i] = false;
    }
    queue<pair<int, int>> q;
    v[0] = 1;
    pair<int, int> s = {0, 0};
    q.push(s);

    pair<int, int> p;
    while (!q.empty())
    {
        p = q.front();
        int k = p.first;
        if (k == n - 1)
        {
            break;
        }

        q.pop();
        for (int j = k + 1; j <= (k + 6) && j < n; j++)
        {
            if (!v[j])
            {
                pair<int, int> a;
                a.second = (p.second + 1);
                v[j] = 1;
                if (move[j] != -1)
                {
                    a.first = move[j];
                }
                else
                {
                    a.first = j;
                }
                q.push(a);
            }
        }
    }
    return p.second;
}

int main()
{
    ifstream inputFile("input2.txt");
    ofstream outputFile("output2.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    if (!outputFile.is_open())
    {
        cerr << "Error opening output file." << endl;
        return 1;
    }
    int n, l, s;
    inputFile >> n >> l >> s;
    int move[n];
    for (int i = 0; i < n; i++)
    {
        move[i] = -1;
    }
    for (int i = 0; i < l + s; i++)
    {
        int a, b;
        inputFile >> a >> b;
        move[a - 1] = b - 1;
    }
    outputFile << BFS(move, n) << endl;
    return 0;
}
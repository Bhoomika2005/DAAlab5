#include <bits/stdc++.h>
using namespace std;
// solved using breadth first search for the connected region and calculating the maximum count
// Time complexity:0(N^2) and Space Complexity: O(N^2) where matrix is of the size N.
int breadth_first_search(vector<vector<int>> mat, vector<vector<int>> &visited, int startrow, int startcol)
{
    int count = 1;
    queue<pair<int, int>> q;
    int n = mat.size();
    int m = mat[0].size();
    q.push({startrow, startcol});
    visited[startrow][startcol] = 1;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int row = p.first;
        int col = p.second;
        for (int i = row - 1; i <= row + 1; i++)
        {
            for (int j = col - 1; j <= col + 1; j++)
            {
                if (i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == 0 && mat[i][j] == 1)
                {
                    visited[i][j] = 1;
                    count++;
                    q.push({i, j});
                }
            }
        }
    }
    return count;
}

int maxRegion(vector<vector<int>> mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int maxx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1 && visited[i][j] == 0)
            {
                int count = breadth_first_search(mat, visited, i, j);
                if (maxx < count)
                    maxx = count;
            }
        }
    }
    return maxx;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < m; j++)
        {
            int k;
            cin >> k;
            v.push_back(k);
        }
        mat.push_back(v);
    }
    int max = maxRegion(mat);
    cout << max << endl;
    return 0;
}
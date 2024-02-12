#include <bits/stdc++.h>
using namespace std;

bool is_bi(vector<vector<bool>> v)
{
	int n = v.size();
	vector<int> col(n, 0);
	queue<int> q;
	q.push(0);
	col[0] = 1;
	while (!q.empty())
	{
		int k = q.front();
		q.pop();
		for (int i = 0; i < n; i++)
		{
			if (v[i][k] == 1)
			{
				if (col[k] == 1)
				{
					if (col[i] == 0)
					{
						col[i] = 2;
						q.push(i);
					}
					else if (col[i] == 1)
					{
						return 0;
					}
				}
				else
				{
					if (col[i] == 0)
					{
						col[i] = 1;
						q.push(i);
					}
					else if (col[i] == 2)
					{
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

int main()
{
	ifstream inputFile("input3.txt");
	ofstream outputFile("output3.txt");

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
	int n;
	inputFile >> n;
	vector<vector<bool>> v(n, vector<bool>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			bool k;
			inputFile >> k;

			v[i][j] = !k;
			if (i == j)
			{
				v[i][j] = 0;
			}
		}
	}
	if (is_bi(v))
	{
		outputFile << "YES" << endl;
	}
	else
	{
		outputFile << "NO" << endl;
	}
	return 0;
}

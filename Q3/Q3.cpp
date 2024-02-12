#include <bits/stdc++.h>
using namespace std;

const int V = 5;

// Bipartite checking
bool isBip(int G[][V], int src, int colorArr[])
{
	colorArr[src] = 1;

	// Create a queue of vertex numbers and enqueue source vertex for BFS traversal
	queue<int> q;
	q.push(src);

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		// Find all non-colored adjacent vertices
		for (int v = 0; v < V; ++v)
		{
			// An edge from u to v exists and destination v is not colored
			if (G[u][v] && colorArr[v] == -1)
			{
				colorArr[v] = 1 - colorArr[u];
				q.push(v);
			}

			else if (G[u][v] && colorArr[v] == colorArr[u])
				return false;
		}
	}

	return true;
}

// Returns true if a Graph G[][] is Bipartite or not. Note
// that G may not be connected.
bool isBipartite(int G[][V])
{
	// Create a color array to store colors assigned
	// to all vertices. Vertex number is used as index in
	// this array. The value '-1' of colorArr[i]
	// is used to indicate that no color is assigned to
	// vertex 'i'. The value 1 is used to indicate first
	// color is assigned and value 0 indicates
	// second color is assigned.
	int colorArr[V];
	for (int i = 0; i < V; ++i)
		colorArr[i] = -1;

	// One by one check all not yet colored vertices.
	for (int i = 0; i < V; i++)
		if (colorArr[i] == -1)
			if (isBip(G, i, colorArr) == false)
				return false;

	return true;
}

// Returns true if G can be divided into
// two Cliques, else false.
bool canBeDividedinTwoCliques(int G[][V])
{
	// Find complement of G[][]
	// All values are complemented except
	// diagonal ones
	int GC[V][V];
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			GC[i][j] = (i != j) ? !G[i][j] : 0;

	// Return true if complement is Bipartite
	// else false.
	return isBipartite(GC);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input3.txt", "r", stdin);
	freopen("output3.txt", "w", stdout);
#endif
	int G[V][V];
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			cin >> G[i][j];
		}
	}

	canBeDividedinTwoCliques(G) ? cout << "Yes" : cout << "No";
	return 0;
}

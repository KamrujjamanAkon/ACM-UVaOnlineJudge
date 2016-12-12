#include <iostream>

using namespace std;

int adj[201][201];
int colorMap[201];

int nNodes, nEdge;

void init()
{
	int i, j;

	for (i = 0; i < nNodes; i++)
	{
		colorMap[i] = 0;
		for (j = 0; j < nNodes; j++)
		{
			adj[i][j] = 0;
		}
	}
}

bool isSafe(int src, int c)
{
	int i;

	for (i = 0; i < nNodes; i++)
	{
		if ((adj[src][i] == 1) && (c == colorMap[i]))
		{
			return false;
		}
	}

	return true;
}

bool graphColor(int src)
{
	int c;

	if (src == nNodes)
		return true;

	for (c = 1; c <= 2; c++)
	{
		if (isSafe(src, c))
		{
			colorMap[src] = c;

			if (graphColor(src + 1) == true)
			{
				return true;
			}

			colorMap[src] = 0;
		}
	}

	return false;
}

int main()
{
	int i, a, b;

	freopen("in.txt", "r", stdin);

	while (cin >> nNodes)
	{
		if (nNodes == 0)
			break;

		cin >> nEdge;

		init();

		for (i = 0; i < nEdge; i++)
		{
			cin >> a >> b;
			adj[a][b] = 1;
			adj[b][a] = 1;
		}

		if (graphColor(0) == false)
			cout << "NOT BICOLORABLE." << endl;
		else
			cout << "BICOLORABLE." << endl;

	}


	return 0;
}

#include <iostream>

using namespace std;

int parents[30005], parentsCount[30005];

int find(int x)
{
	if (x == parents[x])
	{
		return parents[x];
	}

	find(parents[x]);
}

void uni(int x, int y)
{
	int a, b;

	a = find(x);
	b = find(y);

	parents[b] = a;

	parentsCount[a] += parentsCount[b];
	parentsCount[b] = 0;
}

int main()
{
	int t, cas, maxCount;
	int i, a, b, m, n;

	freopen("in.txt", "r", stdin);

	cin >> cas;

	for(t=1; t<=cas; t++)
	{
		cin >> m >> n;

		for(i=1; i<=m; i++)
		{ 
			parents[i] = i;
			parentsCount[i] = 1;
		}

		for(i=1; i<=n; i++)
		{
			cin >> a >> b; 
			if(find(a) != find(b))
				uni(a, b);
		}

		maxCount = 0;

		for(i=1;i<=m;i++)
		{
			if(maxCount < parentsCount[i])
				maxCount = parentsCount[i];
		}

		cout << maxCount << endl;
	}

	return 0;
}
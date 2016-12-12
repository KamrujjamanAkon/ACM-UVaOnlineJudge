#include <iostream>

using namespace std;

int parent[50005];
int rankk[50005];

int find(int x)
{
	if(x == parent[x])
		return parent[x];

	find(parent[x]);
}

void uni(int a, int b)
{
	int x, y;

	x = find(a);
	y = find(b);

	parent[x] = y;

	rankk[y] += rankk[x];
	rankk[x] = 0;
}

int main()
{
	int n, m, a, b, cas;
	int i, grp;;

	freopen("in.txt", "r", stdin);

	cas = 0;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0)
			break;

		cas++;
		for(i=0; i<=n; i++)
		{
			parent[i] = i;
			rankk[i] = 1;
		}

		for(i=1; i<=m; i++)
		{
			cin >> a >> b;

			if(find(a) != find(b))
				uni(a, b);
		}

		grp = 0;
		for(i=1; i<=n; i++)
		{
			if(rankk[i] != 0)
				grp++;
		}

		cout << "Case " << cas << ": " << grp << endl;

	}

	return 0;
}
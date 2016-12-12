#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long parent[200005];


struct Byteland
{
	long frm, to, cost;
};

vector <Byteland> bland;

bool myComp(const Byteland &a, const Byteland &b)
{
	return a.cost < b.cost;
}

long findSet(long a)
{
	/*if(a!=parent[a])
		parent[a] = findSet(parent[a]);

	return parent[a];*/

	if(a==parent[a])
		return parent[a];

	return parent[a] = findSet(parent[a]);
}


int unionSet(long a, long b)
{
	long x, y;
	x = findSet(a);
	y = findSet(b);
	if(x!=y)
	{
		parent[x] = y;
		return 1;
	}
	return 0;
}

int main()
{
	long junc, roads, i, saveCost;
	Byteland byteland;

	freopen("in.txt","r",stdin);

	while(cin >> junc >> roads)
	{
		if(junc==0 && roads==0)
			break;

		bland.clear();

		for(i=0; i<=junc; i++)
			parent[i] = i;

		for(i=0; i<roads; i++)
		{
			cin >> byteland.frm >> byteland.to >> byteland.cost;
			bland.push_back(byteland);
		}

		sort(bland.begin(), bland.end(), myComp);

		saveCost = 0;
		for(i=0; i<roads;i++)
		{
			if(!unionSet(bland[i].frm, bland[i].to))
			{
				saveCost += bland[i].cost;
			}
		}

		cout << saveCost << endl;
	}

	return 0;
}
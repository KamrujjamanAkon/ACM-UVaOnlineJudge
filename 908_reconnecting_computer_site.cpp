#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long parent[1000005];

struct CompSites
{
	long com1, com2, cost;
};

vector <CompSites> comsite;

bool myComp(const CompSites &a, const CompSites &b)
{
	return a.cost < b.cost;
}

long findSet(long a)
{
	if(a==parent[a])
		return parent[a];

	findSet(parent[a]);
}

void unionSet(long a, long b)
{
	long x, y;
	x = findSet(a);
	y = findSet(b);

	parent[x] = y;

}

int main()
{
	long ncomps, m, k, i, j, testcase;
	long a, b, w, iniCost, finalCost;
	CompSites CompSites;

	freopen("in2.txt","r",stdin);


	testcase = 0;
	while(cin >> ncomps)
	{
		if(testcase > 0)
			cout << endl;

		iniCost = 0;
		for(i=0; i<ncomps-1; i++)
		{
			cin >> a >> b >> w;
			iniCost += w;	
		}

		cout << iniCost << endl;

		for(i=0; i<=ncomps; i++)
			parent[i] = i;

		comsite.clear();

		cin >> m;
		for(i=0; i<m; i++)
		{
			cin >> CompSites.com1 >> CompSites.com2 >> CompSites.cost;
			comsite.push_back(CompSites);
		}	

		cin >> k;
		for(i=0; i<k; i++)
		{
			cin >> CompSites.com1 >> CompSites.com2 >> CompSites.cost;
			comsite.push_back(CompSites);
		}

		sort(comsite.begin(), comsite.end(), myComp);

		finalCost = 0;
		for(i=0; i<(m+k);i++)
		{
			if(findSet(comsite[i].com1) != findSet(comsite[i].com2))
			{
				unionSet(comsite[i].com1, comsite[i].com2);
				finalCost += comsite[i].cost;
			}
		}

		cout << finalCost << endl;

		testcase++;
	}

	return 0;
}
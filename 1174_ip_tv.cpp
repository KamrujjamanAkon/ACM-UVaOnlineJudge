#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int parent[2005];

struct Cities
{
	int city1, city2, cost;
};

vector <Cities> city;

bool myComp(const Cities &a, const Cities &b)
{
	return a.cost < b.cost;
}

int findSet(int a)
{
	if(a==parent[a])
		return parent[a];

	findSet(parent[a]);
}

void unionSet(int a, int b)
{
	int x, y;
	x = findSet(a);
	y = findSet(b);

	parent[x] = y;

}

int main()
{
	int t, kase, cityNum, cost;
	int m, n, i, transCost;
	Cities Cities;

	string c1, c2;

	map <string, int> cityMap;

	freopen("in2.txt","r",stdin);

	cin >> kase;
	for(t=0; t<kase; t++)
	{
		cin >> m >> n;

		city.clear();
		cityMap.clear();

		for(i=0; i<=m; i++)
			parent[i] = i;

		cityNum = 1;
		for(i=0; i<n; i++)
		{
			cin >> c1 >> c2 >> cost;

			if(!cityMap[c1])
			{
				cityMap[c1] = cityNum;
				cityNum++;
			}

			if(!cityMap[c2])
			{
				cityMap[c2] = cityNum;
				cityNum++;
			}

			Cities.cost = cost;
			Cities.city1 = cityMap[c1];
			Cities.city2 = cityMap[c2];
			city.push_back(Cities);
		}

		sort(city.begin(), city.end(), myComp);

		transCost = 0;
		for(i=0; i<n;i++)
		{
			if(findSet(city[i].city1) != findSet(city[i].city2))
			{
				unionSet(city[i].city1, city[i].city2);
				transCost += city[i].cost;
			}
		}

		cout << transCost << endl;

		if(t < kase-1)
			cout << endl;
	}

	return 0;
}
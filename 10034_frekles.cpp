#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

int parent[105];

struct points
{
	double x ,y;
};

points pointslist[105];

struct edges
{
	int a, b;
	double weight;
};

vector <edges> edgelist;

bool myComp(const edges &a, const edges &b)
{
	return a.weight < b.weight;
}

int findSet(int a)
{
	if(a == parent[a])
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
	int npooints, i, j, cas, testCas;
	double tempWeight;

	edges edg;

	freopen("in.txt","r",stdin);

	cin >> cas;
	
	for(testCas=0; testCas<cas; testCas++ )
	{

		edgelist.clear();

		cin >> npooints;

		for(i=0; i<npooints; i++)
			cin >> pointslist[i].x >> pointslist[i].y;

		for(i=0; i<npooints; i++)
		{
			for(j=i+1; j<npooints; j++)
			{
					tempWeight = sqrt(((pointslist[i].x - pointslist[j].x) * (pointslist[i].x - pointslist[j].x)) + ((pointslist[i].y - pointslist[j].y) * (pointslist[i].y - pointslist[j].y)));
					edg.a = i+1;
					edg.b = j+1;
					edg.weight = tempWeight;

					edgelist.push_back(edg);
			}
		}

		sort(edgelist.begin(), edgelist.end(), myComp);

		for(i=0; i<=npooints; i++)
			parent[i] = i;

		double totalCost = 0.0;
		for(i=0; i<edgelist.size(); i++)
		{
			if(findSet(edgelist[i].a) != findSet(edgelist[i].b))
			{
				unionSet(edgelist[i].a, edgelist[i].b);
				totalCost += edgelist[i].weight;
			}
		}

		cout << fixed << setprecision(2) << totalCost << endl;

		if(testCas < cas-1)
			cout << endl;

	}

	return 0;
}
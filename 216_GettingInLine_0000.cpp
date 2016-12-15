#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int data[200], visited[200], n, finalPath[200], x[200], y[200];
float  minCable, singleDis[200];

void init()
{
	int i;

	for ( i = 0; i < n; i++)
		visited[i] = 0;

	minCable = 999999.99;
}

float findDistance(float x1, float y1, float x2, float y2)
{
	return sqrt(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2)));
}

void print()
{
	int i;
	float curCable, temp, tempDis[200];

	curCable = 0;
	temp = 0;

	for (i = 0; i < n - 1; i++)
	{
		temp = (findDistance(x[data[i]], y[data[i]], x[data[i + 1]], y[data[i + 1]]) + 16);
		tempDis[i] = temp;
		curCable += temp;

	}		

	if (curCable < minCable)
	{
		minCable = curCable;
		for (i = 0; i < n-1; i++)
		{
			finalPath[i] = data[i];
			singleDis[i] = tempDis[i];
		}
		finalPath[i] = data[i];
	}

}

void findSolution(int i)
{
	int j;

	if (i==n)
	{
		print();
		return;
	}

	for ( j = 0; j < n; j++)
	{
		if (visited[j] == 0)
		{
			visited[j] = 1;
			data[i] = j;
			findSolution(i+1);
			visited[j] = 0;
		}

	}
}

int main()
{
	int i, kase=1;

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin >> n)
	{
		if (n == 0)
			break;

		for ( i = 0; i < n; i++)
			cin >> x[i] >> y[i];

		init();
		findSolution(0);

		cout << "**********************************************************" << endl;
		cout << "Network #" << kase++ << endl;

		for (i = 0; i < n - 1; i++)
		{
			cout << "Cable requirement to connect (";
			cout << x[finalPath[i]] << "," << y[finalPath[i]] << ") to (";
			cout << x[finalPath[i + 1]] << "," << y[finalPath[i + 1]] << ") is ";
			cout << setprecision(2) << fixed << singleDis[i] << " feet." << endl;
		}
		cout << "Number of feet of cable required is " << setprecision(2) << fixed << minCable << "." << endl;
		
	}

	return 0;
}
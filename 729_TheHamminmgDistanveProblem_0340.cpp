#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int n, h;
int base[16];
int data[16];

void init()
{
	int i;

	

	return;
}

void print()
{
	int i, count;

	//for(i=0; i<n; i++)
	//	cout << "--> "<< data[i];

	//cout << endl;

	count=0;

	for(i=n-1; i>=0; i--)
	{
		if(data[i]!=base[i])
			count++;

		if (count > h)
			break;
	}

	if (count == h)
	{
		for(i=0; i<n; i++)
			cout << data[i];

		cout  << endl;
	}

	
}

void findSol(int indx)
{
	int i;

	if(indx == n)
	{
		print();
		return;
	}

	for(i=0;i<2;i++)
	{
		data[indx] = i;
		findSol(indx+1);
	}

}

int main()
{
	int t, kase, i, firstCase;

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	

	cin >> kase;

	for(i=0; i<16; i++)
		base[i] = 0;

	firstCase = 1;

	for(t=0; t<kase; t++)
	{
		cin >> n >> h;

		if (firstCase)
			firstCase = 0;
		else
			cout << endl;


		findSol(0);
	}



	return 0;
}
#include <iostream>
using namespace std;


#define length 26

char str[2000], out[2000];
int var[length], visited[length], path[length][length], n, first = 0, found = 0;

void findSol(int indx)
{
	int i, j, k;

	if (indx == n)
	{
		found = 1;

		out[indx] = '\0';
		cout << out[0];
		for ( k = 1; out[k]; k++)
			cout << " " << out[k];

		cout << endl;
		return;
	}

	for (i = 0; i < length; i++)
	{
		if (var[i] && visited[i] == 0)
		{
			for ( j = 0; j < length; j++)
				if (path[i][j] && visited[j] == 1)
					return;

			visited[i] = 1;
			out[indx] = i + 'A';
			findSol(indx+1);

			visited[i] = 0;
		}
	}
}


void init()
{
	int i, j;

	for ( i = 0; i < length; i++)
	{
		var[i] = 0;
		visited[i] = 0;
		for (j = 0; j < length; j++)
			path[i][j] = 0;
	}

	n = 0;
}

int main()
{
	int t, kase, i, ind1, ind2;

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> kase;
	gets(str);

	for ( t = 0; t < kase; t++)
	{
		gets(str);
		gets(str);

		init();

		for ( i = 0; str[i]; i++)
		{
			if (str[i] >='A' && str[i] <='Z')
			{
				ind1 = str[i] - 'A';
				var[ind1] = 1;
				n++;
			}	
		}

		gets(str);

		for ( i = 0; str[i]; i++)
		{
			if (str[i] == '<')
			{
				ind1 = str[i - 1] - 'A';
				ind2 = str[i + 1] - 'A';

				path[ind1][ind2] = 1;
			}
		}

		if (first == 0)
			first = 1;
		else
			cout << endl;

		found = 0;
		findSol(0);

		if (found == 0)
		{
			cout << "NO" << endl;
		}
	}


	return 0;
}
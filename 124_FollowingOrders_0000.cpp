#include <iostream>

using namespace std;

#define length 26

char str[2000], out[2000];
int var[length], used[length], path[length][length];
int nVar, first;

void init()
{
	int i, j;

	for ( i = 0; i < length; i++)
	{
		used[i] = 0;
		var[i] = 0;
		for ( j = 0; j < length; j++)
		{
			path[i][j] = 0;
		}
	}

	nVar = 0;
}

void findSolution(int indx)
{
	int i, j;

	if (indx == nVar)
	{
		out[indx] = '\0';
		cout << out << endl;
		return;
	}

	for ( i = 0; i < length; i++)
	{
		if (var[i] && used[i] == 0)
		{
			for ( j = 0; j < length; j++)
			{
				if (path[i][j] && used[j] == 1)
					return;
			}

			used[i] = 1;
			out[indx] = i + 'a';
			findSolution(indx+1);
			used[i] = 0;
		}
	}
}

int main()
{
	int i, ind1, ind2;

	freopen("in.txt", "r", stdin);

	first = 0;

	while (gets(str))
	{
		if (first == 0)
			first = 1;
		else
			cout << endl;

		init();

		for (i = 0; str[i]; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				ind1 = str[i] - 'a';
				var[ind1] = 1;
				nVar++;
			}
		}

		gets(str);

		for ( i = 0; str[i]; i++)
		{
			while (str[i] == ' ')
				i++;

			ind1 = str[i] - 'a';
			i++;

			while (str[i] == ' ')
				i++;

			ind2 = str[i] - 'a';
			path[ind1][ind2] = 1;
		}

		findSolution(0);
	}

	return 0;
}
#include <iostream>

#define length 26

using namespace std;

char line1[2000], line2[2000], out[2000];
int path[length][length], used[length], var[length];
int nVar;

void init()
{
	int i, j;

	for (i = 0; i < length; i++)
	{
		used[i] = 0;
		var[i] = 0;
		for (j = 0; j < 100; j++)
			path[i][j] = 0;
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

	for (i = 0; i < length; i++)
	{
		if (var[i] && used[i] == 0)
		{
			for (j = 0; j < length; j++)
				if (path[i][j] && used[j] == 1)
					return;

			used[i] = 1;
			out[indx] = i + 'A';
			findSolution(indx + 1);
			used[i] = 0;
		}
	}
}


int main()
{
	int i, ind1, ind2;

	freopen("in.txt", "r", stdin);



	while (gets(line1))
	{
		init();
		while (gets(line2) && line2[0] != '#')
		{
			for (i = 0; line1[i] && line2[i]; i++)
			{
				if (line1[i] != line2[i])
				{
					ind1 = line1[i] - 'A';
					var[ind1] = 1;

					ind2 = line2[i] - 'A';
					var[ind2] = 1;

					path[ind1][ind2] = 1;
					break;
				}
			}

			for (i = 0; line2[i]; i++)
				line1[i] = line2[i];

			line1[i] = '\0';
		}

		for (i = 0; i < length; i++)
			if (var[i] == 1)
				nVar++;

		findSolution(0);
	}

	return 0;
}
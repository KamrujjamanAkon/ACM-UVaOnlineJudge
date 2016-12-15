#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int source[105], timee[105], duration[105], target[105], n, visited[105];

int findSol(int tim, int ext)
{
	int j, a, b;

	for (j = 0; j < n; j++)
	{
		if (ext == source[j])
		{
			a = timee[j];
			b = timee[j] + duration[j];

			if (tim >= a && tim <= b)
			{
				if (visited[j] == 1)
					return 9999;
				else
				{
					visited[j] = 1;
					return findSol(tim, target[j]);
				}
			}
		}
	}

	return ext;
}

int main()
{
	int t, kase, i, res;
	int tim, ext;

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);


	scanf("%d", &kase);

	printf("CALL FORWARDING OUTPUT\n");


	for (t = 1; t <= kase; t++)
	{
		i = 0;
		while (scanf("%d", &source[i]))
		{
			if (source[i] == 0)
				break;

			scanf("%d %d %d", &timee[i], &duration[i], &target[i]);
			i++;
		}

		n = i;

		printf("SYSTEM %d\n", t);

		while (scanf("%d", &tim))
		{
			if (tim == 9000)
				break;

			for (i = 0; i < n; i++)
				visited[i] = 0;

			scanf("%d", &ext);
			res = findSol(tim, ext);

			printf("AT %04d CALL TO %04d RINGS %04d\n", tim, ext, res);
		}
	}

	printf("END OF OUTPUT\n");

	return 0;
}


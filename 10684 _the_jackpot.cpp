#include <stdio.h>

int main()
{
	int i, n;

	int bets[10005];
	int maxEndHere, maxSoFar;

	freopen("in.txt", "r", stdin);

	while (scanf("%d", &n))
	{
		if (n == 0)
			break;

		for (i = 0; i < n; i++)
		{
			scanf("%d", &bets[i]);
		}

		maxEndHere = 0;
		maxSoFar = 0;

		for ( i = 0; i < n; i++)
		{
			maxEndHere += bets[i];

			if (maxEndHere < 0)
				maxEndHere = 0;

			if (maxSoFar < maxEndHere)
				maxSoFar = maxEndHere;
		}


		if (maxSoFar > 0)
			printf("The maximum winning streak is %d.\n", maxSoFar);
		else
			printf("Losing streak.\n");
			
	}

	return 0;
}

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define ALLOWED_SIZE	125
#define ALLOWED_WEIGHT  7

int main()
{
	float len, wid, dep, wei;

	int t, kase, totalCount, totalSize;

	freopen("input.txt", "r", stdin);

	scanf("%d", &kase);
	totalCount = 0;

	for (t = 0; t < kase; t++)
	{
		scanf("%f %f %f %f", &len, &wid, &dep, &wei);

	
		if (((len<=56 && wid<=45 && dep<=25) || (len+wid+dep <= ALLOWED_SIZE)) && (wei <= ALLOWED_WEIGHT))
		{
			printf("1\n");
			totalCount++;
		}
		else
			printf("0\n");
	}

	printf("%d\n", totalCount);

	return 0;
}
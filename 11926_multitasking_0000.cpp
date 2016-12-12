#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#define YES 1
#define NO  0

using namespace std;

int taskTime[1000100];

int checkOverlap(int start, int end)
{
	int i;
	for (i = start; i < end; i++)
	{
		if (taskTime[i] == YES)
			return YES;
		
		taskTime[i] = YES;
	}

	return NO;
}

int main()
{
	int n, m, i, j, conflict, sTime, eTime, rTime;

	freopen("input.txt", "r", stdin);

	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;

		memset(taskTime, NO, sizeof(taskTime));
		conflict = NO;

		for (i = 0; i < n; i++)
		{
			cin >> sTime >> eTime;

			if (conflict == NO && checkOverlap(sTime, eTime) == YES)
				conflict = YES;
		}


		for (i = 0; i < m; i++)
		{
			cin >> sTime >> eTime >> rTime;
			while (conflict == NO && sTime < 1000000)
			{
				if (checkOverlap(sTime, eTime) == YES)
					conflict = YES;

				sTime += rTime;
				eTime += rTime;

				if (eTime > 1000000)
					eTime = 1000000;
			}
		}

		if (conflict == YES)
			cout << "CONFLICT" << endl;
		else
			cout << "NO CONFLICT" << endl;

	}

	return 0;
}
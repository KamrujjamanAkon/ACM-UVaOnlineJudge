#include <iostream>
#include <memory.h>

using namespace std;

int n, totalSum;
int val[105], dp[105][50005];


int solveProblem(int i, int sum1)
{
	int left, right, sum2;

	if (dp[i][sum1] >= 0)
	{
		return dp[i][sum1];
	}

	if (i == n)
	{
		sum2 = totalSum - sum1;
		return dp[i][sum1] = abs(sum1 - sum2);
	}

	left = solveProblem(i + 1, sum1);
	right = solveProblem(i + 1, sum1 + val[i]);

	if (left < right)
	{
		dp[i][sum1] = left;
		return left;
	}
	else
	{
		dp[i][sum1] = right;
		return right;
	}
}

int main()
{
	int i, t, kase, res;

	cin >> kase;
	for (t = 0; t<kase; t++)
	{
		cin >> n;

		memset(dp, -1, sizeof(dp));

		totalSum = 0;
		for (i = 0; i < n; i++)
		{
			cin >> val[i];
			totalSum += val[i];
		}

		res = solveProblem(0, 0);

		cout << res << endl;
	}

	return 0;
}
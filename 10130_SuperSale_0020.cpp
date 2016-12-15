#include <iostream>
#include <memory.h>

using namespace std;

int n, p[1005], w[1005], g, maxG;
int dp[1005][31];

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int solve(int i, int cap)
{
	int left, right;

	if (dp[i][cap] >= 0)
	{
		return dp[i][cap];
	}

	if (i == n)
	{
		return 0;
	}
	left = solve(i+1, cap);

	if (cap >= w[i])
		right = p[i] + solve(i + 1, cap - w[i]);
	else
		right = 0;

	return dp[i][cap] = max(left, right);
}

int main()
{
	int t, kase, i, maxPrice;

	freopen("in.txt", "r", stdin);

	cin >> kase;
	for (t = 1; t <= kase; t++)
	{
		cin >> n;

		memset(dp, -1, sizeof(dp));

		for (i = 0; i < n; i++)
		{
			cin >> p[i] >> w[i];
		}

		cin >> g;

		maxPrice = 0;

		for (i = 0; i < g; i++)
		{
			cin >> maxG;
			maxPrice += solve(0, maxG);
		}

		cout << maxPrice << endl;
	}

	return 0;
}
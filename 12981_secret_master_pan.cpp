#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
	int t, kase, n;

	freopen("in.txt", "r", stdin);

	cin >> kase;

	for (t = 1; t <= kase; t++)
	{
		cin >> n;

		cout << "Case #" << t << ": " << n+n-1 << endl;
	}

	return 0;
}
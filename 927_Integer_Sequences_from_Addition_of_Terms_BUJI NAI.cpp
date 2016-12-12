#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int main()
{
	int t, kase;
	int a[25], d, k, i, j;
	char ch;

	freopen("input.txt", "r", stdin);
	cin >> kase;

	for (t = 0; t < kase; t++)
	{
		while (cin >> ch)
		{
			if (ch == 13)
				break;

			if (ch >= '0' && ch <= '9')
				a[j++] = ch - '0';
		}
		cin >> d >> k;

		for (i = 0; i < j; i++)
		{

		}

	}



}
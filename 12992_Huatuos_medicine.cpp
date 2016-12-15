#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
	int t, kase, flag, temp, cnt;
	int orgnl[2][2];
	int wrong[2][2];

	freopen("in.txt", "r", stdin);

	cin >> kase;

	for (t = 1; t <= kase; t++)
	{
		cin >> orgnl[0][0];
		cin >> orgnl[0][1];
		cin >> orgnl[1][0];
		cin >> orgnl[1][1];

		cin >> wrong[0][0];
		cin >> wrong[0][1];
		cin >> wrong[1][0];
		cin >> wrong[1][1];

		flag = 0;
		cnt = 0;
		while (1)
		{
			if (cnt == 4)
				break;

			if ((orgnl[0][0] == wrong[0][0]) &&
				(orgnl[0][1] == wrong[0][1]) &&
				(orgnl[1][0] == wrong[1][0]) &&
				(orgnl[1][1] == wrong[1][1]) )
			{
				flag = 1;
				cout << "Case #" << t << ": " << "POSSIBLE" << endl;
				break;
			}

			//rotate
			cnt++;
			temp = wrong[0][0];
			wrong[0][0] = wrong[0][1];
			wrong[0][1] = wrong[1][1];
			wrong[1][1] = wrong[1][0];
			wrong[1][0] = temp;

		}

		if(flag == 0)
			cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;

	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>

#define length 8

using namespace std;

int board[65][65], visited[65][65], maxSum;

void init()
{
	int i, j;

	for (i = 0; i < length; i++)
		for (j = 0; j < length; j++)
			visited[i][j] = 0;

	maxSum = 0;
}

void printSolution()
{
	int i, j, curSum;

	curSum = 0;

	for ( i = 0; i < length; i++)
	{
		for (j = 0; j < length; j++)
		{
			//cout << visited[i][j] << " ";

			if (visited[i][j] == 1)
			{
				curSum += board[i][j];
			}
		}
		//cout << endl;
	}
	//cout << endl;
	//cout << endl;

	if (maxSum < curSum)
		maxSum = curSum;
}

bool isPossibleToPlace(int i, int j)
{
	bool possible = 1;
	int x, y;

	x = i;
	y = j;

	//check left diagonal
	for (i = i - 1, j = j - 1; i >= 0 && j >= 0; i--, j--)
		if (visited[i][j] == 1)
			possible = 0;

	//check top
	i = x;
	j = y;
	for (i = i - 1; i >= 0; i--)
		if (visited[i][j] == 1)
			possible = 0;


	//check right diagonal
	i = x;
	j = y;
	for (i = i - 1, j = j + 1; i >= 0 && j < length; i--, j++)
		if (visited[i][j] == 1)
			possible = 0;

	return possible;
}

void placeQueen(int i)
{
	int j;

	if (i == length)
	{
		printSolution();
		return;
	}

	for (j = 0; j < length; j++)
	{
		if (visited[i][j] == 0)
		{
			if (isPossibleToPlace(i, j))
			{
				visited[i][j] = 1;
				placeQueen(i + 1);
				visited[i][j] = 0;
			}
		}

	}
}


int main()
{
	int t, kase, i, j;

	freopen("in.txt", "r", stdin);

	cin >> kase;

	for (t = 0; t < kase; t++)
	{
		init();

		for (i = 0; i < length; i++)
			for (j = 0; j < length; j++)
				cin >> board[i][j];


		placeQueen(0);

		cout << right << setw(5) << maxSum << endl;

	}

	return 0;
}
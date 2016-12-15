#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

#define length 8

int visited[100][100];
int queenPos[94][10];

int k = 0;

int serial = 0;

void print()
{
	int i, j;

	//cout << ++serial << "---> ";
	
	++serial;
	for (i = 0; i < length; i++)
	{
		for (j = 0; j < length; j++)
		{
			//cout << visited[j][i] << " ";

			if (visited[i][j] == 1)
			{
				//cout << j+1 << " ";
				queenPos[serial][i+1] = j+1;
			}
		}
		//cout << endl;
	}

	//cout << endl;
}

bool isPossible(int x, int y)
{
	int i, j;

	//top check
	for (i = x - 1, j = y; i >= 0; i--)
		if (visited[i][j] == 1)
			return false;


	//left diagonal check
	for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
		if (visited[i][j] == 1)
			return false;

	//right diagonal check
	for (i = x - 1, j = y + 1; i >= 0 && j < length; i--, j++)
		if (visited[i][j] == 1)
			return false;

	return true;
}

void placeQueen(int i)
{
	int  j;

	if (i == length)
	{
		print();
		return;
	}

	for (j = 0; j < length; j++)
	{
		if (visited[i][j] == 0)
		{
			if (isPossible(i, j))
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
	int r, c, kase;

	placeQueen(0);

	freopen("in.txt", "r", stdin);

	cin >> kase;
	while (kase--)
	{
		cin >> r >> c;
		
		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl << endl;

		for (int i = 1; i <= 92; i++)
		{
			if(queenPos[i][r]!=c)continue;

			for(int j=1;j<=length;j++)
			{
				cout<<queenPos[i][j];
			}
			cout<<endl;
		}

	}


	return 0;
}
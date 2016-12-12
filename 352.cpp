#include <iostream>

using namespace std;

int warField[30][30];
int dimen, egalCount;


void findWarEgales(int i, int j)
{
	if((i-1)>=1 && (j-1)>=1) 
	{
		if(warField[i-1][j-1] < 0)
		{
			warField[i-1][j-1] = egalCount;
			findWarEgales(i-1, j-1);
		}
	}

	if((i-1)>=1 && (j)>=1) 
	{
		if(warField[i-1][j] < 0)
		{
			warField[i-1][j] = egalCount;
			findWarEgales(i-1, j);
		}
	}

	if((i-1)>=1 && (j+1)<=dimen)
	{
		if(warField[i-1][j+1] < 0)
		{
			warField[i-1][j+1] = egalCount;
			findWarEgales(i-1, j+1);
		}
	}

	if((i)>=1 && (j-1)>=1) 
	{
		if(warField[i][j-1] < 0)
		{
			warField[i][j-1] = egalCount;
			findWarEgales(i, j-1);
		}
	}

	if((i)>=1 && (j+1)<=dimen) 
	{
		if(warField[i][j+1] < 0)
		{
			warField[i][j+1] = egalCount;
			findWarEgales(i, j+1);
		}
	}

	if((i+1)<=dimen && (j-1)>=1) 
	{
		if(warField[i+1][j-1] < 0)
		{
			warField[i+1][j-1] = egalCount;
			findWarEgales(i+1, j-1);
		}
	}

	if((i+1)<=dimen && (j)>=1) 
	{
		if(warField[i+1][j] < 0)
		{
			warField[i+1][j] = egalCount;
			findWarEgales(i+1, j);
		}
	}

	if((i+1)<=dimen && (j+1)<=dimen) 
	{
		if(warField[i+1][j+1] < 0)
		{
			warField[i+1][j+1] = egalCount;
			findWarEgales(i+1, j+1);
		}
	}

	return;
}

//void Print()
//{
//	int i, j;
//	for(i=1; i<=dimen; i++)
//	{
//		for(j=1; j<=dimen; j++)
//		{
//			cout << warField[i][j] << " ";
//		}
//		cout << endl;
//	}
//}

int main()
{
	int i, j, imgno;
	char val;

	freopen("in.txt","r", stdin);

	imgno = 0;
	while(cin >> dimen)
	{
		getchar();
		imgno++;

		for(i=1; i<=dimen; i++)
		{
			for(j=1; j<=dimen; j++)
			{
				cin >> val;
				if(val == '1')
					warField[i][j] = -1;
				else
					warField[i][j] = 0;
			}
		}

		egalCount = 1;

		for(i=1; i<=dimen; i++)
		{
			for(j=1; j<=dimen; j++)
			{
				if(warField[i][j] < 0)
				{
					warField[i][j] = egalCount;
					findWarEgales(i, j);
					egalCount++;
				}
			}
		}

		//Print();

		cout << "Image number " << imgno << " contains " << egalCount - 1 <<" war eagles." << endl;
	}
	return 0;
}
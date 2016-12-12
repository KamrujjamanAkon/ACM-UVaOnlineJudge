#include <iostream>

using namespace std;

int oilDeposit[105][105];
int m, n, oiDepositCount;


void findOilDeposit(int i, int j)
{
	if((i-1)>=1 && (j-1)>=1) 
	{
		if(oilDeposit[i-1][j-1] < 0)
		{
			oilDeposit[i-1][j-1] = oiDepositCount;
			findOilDeposit(i-1, j-1);
		}
	}

	if((i-1)>=1 && (j)>=1) 
	{
		if(oilDeposit[i-1][j] < 0)
		{
			oilDeposit[i-1][j] = oiDepositCount;
			findOilDeposit(i-1, j);
		}
	}

	if((i-1)>=1 && (j+1)<=n)
	{
		if(oilDeposit[i-1][j+1] < 0)
		{
			oilDeposit[i-1][j+1] = oiDepositCount;
			findOilDeposit(i-1, j+1);
		}
	}

	if((i)>=1 && (j-1)>=1) 
	{
		if(oilDeposit[i][j-1] < 0)
		{
			oilDeposit[i][j-1] = oiDepositCount;
			findOilDeposit(i, j-1);
		}
	}

	if((i)>=1 && (j+1)<=n) 
	{
		if(oilDeposit[i][j+1] < 0)
		{
			oilDeposit[i][j+1] = oiDepositCount;
			findOilDeposit(i, j+1);
		}
	}

	if((i+1)<=m && (j-1)>=1) 
	{
		if(oilDeposit[i+1][j-1] < 0)
		{
			oilDeposit[i+1][j-1] = oiDepositCount;
			findOilDeposit(i+1, j-1);
		}
	}

	if((i+1)<=m && (j)>=1) 
	{
		if(oilDeposit[i+1][j] < 0)
		{
			oilDeposit[i+1][j] = oiDepositCount;
			findOilDeposit(i+1, j);
		}
	}

	if((i+1)<=m && (j+1)<=n) 
	{
		if(oilDeposit[i+1][j+1] < 0)
		{
			oilDeposit[i+1][j+1] = oiDepositCount;
			findOilDeposit(i+1, j+1);
		}
	}

	return;
}

void Print()
{
	int i, j;
	for(i=1; i<=m; i++)
	{
		for(j=1; j<=n; j++)
		{
			cout << oilDeposit[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int i, j;
	char val;

	//freopen("in.txt","r", stdin);

	while(cin >> m >> n)
	{
		getchar();
		if(m == 0)
			break;

		for(i=1; i<=m; i++)
		{
			for(j=1; j<=n; j++)
			{
				cin >> val;
				if(val == '@')
					oilDeposit[i][j] = -1;
				else
					oilDeposit[i][j] = 0;
			}
		}

		oiDepositCount = 1;

		for(i=1; i<=m; i++)
		{
			for(j=1; j<=n; j++)
			{
				if(oilDeposit[i][j] < 0)
				{
					oilDeposit[i][j] = oiDepositCount;
					findOilDeposit(i, j);
					oiDepositCount++;
				}
			}
		}

		//Print();

		cout  << oiDepositCount - 1  << endl;
	}
	return 0;
}
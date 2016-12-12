#include <iostream>
#include <string>

using namespace std;

int parentList[27];
int rankk[27];

int find(int x)
{
	if(x == parentList[x])
		return parentList[x];

	find(parentList[x]);
}

void uni(int x, int y)
{
	int a, b;

	a= find(x);
	b= find(y);

	parentList[b] = a;

	rankk[a] += rankk[b];
	rankk[b] = 0;
}


int main()
{
	int t, cas, i, grp;
	int node,n1, n2;
	string str;
	char ch;

	freopen("in.txt", "r", stdin);

	cin >> cas;

	getline(cin, str);
	getline(cin, str);

	for(t=0; t<cas; t++)
	{

		cin >> ch;
		getline(cin, str);

		node = ch - 64;
		grp = 0;

		for(i=0; i<=node; i++)
		{
			parentList[i] = i;
			rankk[i] = 1;
		}

		while(getline(cin,str))
		{
			if(str == "")
				break; 

			n1 = str[0] - 64;
			n2 = str[1] - 64;

			if(find(n1) != find(n2))
				uni(n1, n2);
		}

		for(i=1; i<=node; i++)
		{
			if(rankk[i] != 0)
				grp++;
		}

		cout << grp << endl;

		if(t < cas-1)
			cout << endl;
	}

	return 0;
}

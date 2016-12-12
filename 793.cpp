#include <iostream>
#include <string>

using namespace std;

int parents[10000];

int find(int x)
{
	if(x == parents[x])
		return parents[x];

	find(parents[x]);
}

void uni(int x, int y)
{
	int a, b;

	a = find(x);
	b = find(y);

	parents[b] = a;
}

int main()
{
	int t, cas, successful, unsuccessful;
	int no_of_computers, i, a, b;
	char ch;
	string str;

	freopen("in.txt", "r", stdin);

	cin >> cas;

	for(t=1; t<=cas; t++)
	{
		cin >> no_of_computers; 
		getline(cin, str);


		for(i=0; i<=no_of_computers; i++)
		{
			parents[i] = i;
		}

		successful = 0;
		unsuccessful = 0;
		while(cin.get(ch)) 
		{
			if(ch=='\n')	
				break;

			cin>>a>>b;		

			if(ch =='c')
			{
				if(find(a) != find(b))
					uni(a, b);
			}
			else if(ch =='q')
			{
				if(find(a) == find(b))
					successful++;
				else
					unsuccessful++;
			}
			cin.get(ch);

		}

		cout << successful << "," << unsuccessful << endl;

		if(t < cas)
			cout << endl;
	}

	return 0;
}
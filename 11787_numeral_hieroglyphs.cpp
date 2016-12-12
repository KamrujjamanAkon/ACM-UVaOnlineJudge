#include <stdio.h>
#include <string.h>

char str[505];
long long val[100];
int charCount[100];

void init()
{
	val['B'] = 1;
	val['U'] = 10;
	val['S'] = 100;
	val['P'] = 1000;
	val['F'] = 10000;
	val['T'] = 100000;
	val['M'] = 1000000;
}

bool isError1(int len)
{
	long long i, temp1, temp2;
	for (i = 0; i < len - 1; i++)
	{
		temp1 = val[str[i]];
		temp2 = val[str[i + 1]];

		if (temp1 >= temp2)
		{
			//do nothing
		}
		else
		{
			return false;
		}
	}

	return true;
}

bool isError2(int len)
{
	long long i, temp1, temp2;
	for (i = 0; i < len - 1; i++)
	{
		temp1 = val[str[i]];
		temp2 = val[str[i + 1]];

		if (temp1 <= temp2)
		{
			//do nothing
		}
		else
		{
			return false;
		}
	}

	return true;
}



int main()
{
	int t, kase, i, len, flag;
	long long sum;

	freopen("in.txt", "r", stdin);

	init();
	scanf("%d", &kase);

	for (t = 1; t <= kase; t++)
	{
		scanf("%s", &str);
		len = strlen(str);
		sum = 0;
		flag = 1;

		for (i = 0; i < 100; i++)
			charCount[i] = 0;

		if (isError1(len))
		{
			for (i = 0; i < len; i++)
			{
				charCount[str[i]]++;
				if (charCount[str[i]] > 9)
				{
					flag = 0;
					break;
				}
				else
					sum += val[str[i]];
			}

			if (flag == 0)
				printf("error\n");
			else
				printf("%d\n", sum);
		}
		else if (isError2(len))
		{
			for (i = 0; i < len; i++)
			{
				charCount[str[i]]++;
				if (charCount[str[i]] > 9)
				{
					flag = 0;
					break;
				}
				else
					sum += val[str[i]];
			}

			if (flag == 0)
				printf("error\n");
			else
				printf("%d\n", sum);
		}
		else
			printf("error\n");

	}

	return 0;
}
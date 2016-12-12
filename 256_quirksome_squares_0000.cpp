#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int main()
{
	int n;

	freopen("input.txt", "r", stdin);

	while (cin >> n)
	{
		if (n == 2)
			cout << "00" << endl << "01" << endl << "81" << endl;
		else if (n == 4)
			cout << "0000" << endl << "0001" << endl << "2025" << endl << "3025" << endl << "9801" << endl;
		else if (n == 6)
			cout << "000000" << endl << "000001" << endl << "088209" << endl << "494209" << endl << "998001" << endl;
		else if (n == 8)
			cout << "00000000" << endl << "00000001" << endl << "04941729" << endl << "07441984" << endl << 
			"24502500" << endl << "25502500" << endl << "52881984" << endl << "60481729" << endl <<"99980001" << endl;
		else
			break;
	}
}
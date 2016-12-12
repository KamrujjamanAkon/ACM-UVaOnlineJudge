#include <iostream>
using namespace std;

int main()
{
	long long int input, mod, div;

	while(cin >> input)
	{
		if(input == 0)
			return 0;

		mod = input % 9;
		div = input / 9;

		if(mod == 0)
			cout << (input + div-1) << " " << (input + div) << endl;
		else
			cout << (input + div) << endl;
	}

	return 0;
}
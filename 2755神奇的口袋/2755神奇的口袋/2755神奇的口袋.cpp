#include <iostream>
using namespace std;

int method[25][45] = {0};
int main()
{
	int n;
	cin >> n;
	int value[25] = {0};
	for(int i = 0; i < n; ++i)
	{
		cin >> value[i];
	}
	method[n][0] = 1;
	for(int i = n - 1; i >= 0; --i)
	{
		for(int j = 0; j <= 40; ++j)
		{
			method[i][j] += method[i + 1][j];
			if(value[i] <= j)
			{
				method[i][j] += method[i + 1][j - value[i]];
			}

		}
	}
	cout << method[0][40] << endl;
	system("pause");
	return 0;
}

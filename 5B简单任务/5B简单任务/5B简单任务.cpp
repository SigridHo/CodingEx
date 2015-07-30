#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int mi[110] = {0};
int main()
{
	int t;
	cin >> t;
	for(int i = 0 ; i < t; ++i)
	{
		int times;
		cin  >> times;
		memset(mi, 0, sizeof(mi));
		for(int j = 0; j <= times; ++j)
		{
			cin >> mi[j];
		}
		if(times == 0) cout << "0" << endl;
		else
		{
			for(int j = 0; j < times; ++j)
			{
				mi[j] *= (times - j);
			}
			cout << mi[0];
			if(times > 1)
			{
				for(int j = 1; j < times; ++j)
					cout << ' ' << mi[j];
				
			}
			cout << endl;
		}
	}
	return 0;
}
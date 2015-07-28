#include <iostream>
using namespace std;

int main()
{
	int n, k;
	while(cin >> n >> k)
	{
		double m = 200;
		int s = n;
		int i = 0;
		for(i = 1;i <= 20 ; ++i)
		{
			if(s > m)
			{
				cout << i  << endl;
				break;
			}
			s += n;
			m = m * (1 + k * 0.01);
		}
		if(i > 20) cout << "Impossible" << endl;
 	}
	return 0;
}
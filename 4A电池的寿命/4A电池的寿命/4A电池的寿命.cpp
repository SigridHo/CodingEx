#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int power[1010] = {0};
int main()
{
	int n;
	while(cin >> n)
	{
		memset(power, 0, sizeof(power));
		double sum = 0;
		for(int i = 0; i < n; ++i)
		{
			cin >> power[i];
			sum += power[i];
		}
		for(int i = 0; i < n - 1; ++i)
			for(int j = i + 1; j < n; ++j)
			{
				if(power[i] < power[j])
				{
					int temp = power[i];
					power[i] = power[j]; 
					power[j] = temp;
				}

			}
		if(sum - power[0] >= power[0]) printf("%.1lf\n", sum / 2);
		else printf("%.1lf\n", sum - power[0]);
	}

	return 0;
}
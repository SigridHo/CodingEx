#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int mol[10030] = {0};
bool result[110] = {0};
bool tem[110] = {0};
int main()
{
	int n, k;
	cin >> n >> k;
	int temp;
	for(int i = 0; i < n; ++i)
	{
		cin >> temp;
		temp = ((temp % k ) + k) % k; 
		mol[i] = temp;
	}
	tem[mol[0]] = true;
	tem[k - mol[0]] = true;
	if(n > 1)
	{
		for(int i = 1; i < n; ++i)
		{
			memset(result, 0, sizeof(result));
			for(int j = 0; j < k; ++j)
			{
				if(tem[j])
				{
					
					result[((j - mol[i]) + k) % k] = true;
					result[(j + mol[i]) % k] = true;
				}
			}
			for(int j = 0; j < k; ++j)
			{
				tem[j] = result[j];
			}
		}
	}
	if(tem[0]) cout << "Divisible" << endl;
	else cout << "Not divisible" << endl;
	system("pause");
	return 0;
}

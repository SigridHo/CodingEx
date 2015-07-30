#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dp[21] = {0};
int main()
{
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 3;
	if(n > 1)
	{
		for(int i = 2; i <= n; ++i)
		{
			dp[i] = dp[i - 1];
			for(int j = 0; j < i - 1; ++j)
				dp[i] += (2 * dp[j]);
			dp[i] += 2;
		}
	}
	cout << dp[n] << endl;
	system("pause");
	return 0;
}
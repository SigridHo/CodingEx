#include <iostream>
using namespace std;

int main() 
{
	int N, K;
	while(cin >> N >> K)
	{
		if(N == 0 && K == 0) break;
		double value = 200;
		int earn = N;
		bool disable = true;
		for(int i = 1; i <= 20; ++i)
		{
			if(earn >= value) 
			{
				cout << i << endl;
				disable = false;
				break;
			}
			else
			{
				earn += N;
				value = value * (1 + K * 0.01);
			}
		}
		if(disable) cout << "Impossible" << endl;
	}
	return 0;
}
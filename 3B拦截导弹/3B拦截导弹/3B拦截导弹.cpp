#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int height[30] = {0};
	int answer[30] = {0}; 
	for(int i = 0; i < n; ++i)
	{
		cin >> height[i];
		answer[i] = 1;
	}
	if(n == 1) cout << "1" << endl;
	else
	{
		for(int i = 1; i < n; ++i)
		{
			int temp = 1;
			for(int j = 0; j < i; ++j)
			{
				if(height[j] >= height[i] && answer[j] + 1 > temp)
					temp = answer[j] + 1;
			}
			answer[i] = temp;
		}
		int max = answer[0];
		for(int i = 1; i < n; ++i)
		{
			if(answer[i] > max) max = answer[i];
		}
		cout << max << endl;
	}
	system("pause");
	return 0;
}
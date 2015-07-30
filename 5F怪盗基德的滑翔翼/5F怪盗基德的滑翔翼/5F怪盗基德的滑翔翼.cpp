#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int height[110] = {0};
int Left[110] = {0};
int Right[110] = {0};

int main()
{
	int t;
	cin >> t;
	for(int l  = 0; l < t; ++l)
	{
		memset(height, 0, sizeof(height));
		memset(Left, 0, sizeof(Left));
		memset(Right, 0, sizeof(Right));
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i)
		{
			cin >> height[i];
			Left[i] = 1;
			Right[i] = 1;
		}
		if(n == 1) cout << "1" << endl;
		else
		{
			for(int i = 1; i < n; ++i)
			{
				int temp = 1;
				for(int j = 0; j < i; ++j)
				{
					if(height[j] > height[i] && Right[j] + 1 > temp)
						temp = Right[j] + 1;
				}
				Right[i] = temp;
			}
			for(int i = n - 2; i >= 0; --i)
			{
				int temp = 1;
				for(int j = n - 1; j > i; --j)
				{
					if(height[j] > height[i] && Left[j] + 1 > temp)
						temp = Left[j] + 1;
				}
				Left[i] = temp;
			}
			int MAX = 1;
			for(int i = 0; i < n; ++i)
			{
				if(Left[i] > MAX) MAX = Left[i];
				if(Right[i] > MAX) MAX = Right[i];
			}
			cout << MAX << endl;
		}
	}
	return 0;
}

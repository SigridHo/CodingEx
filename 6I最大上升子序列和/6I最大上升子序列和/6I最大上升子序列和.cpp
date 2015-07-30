#include <iostream>
using namespace std;

int number[1010] = {0};
int answer[1010] = {0};
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> number[i];
		answer[i] = number[i];
	}
	int max = answer[0];
	int temp = 0;
	if(n > 1)
	{
		for(int i = 1; i < n; ++i)
		{
			temp = answer[i];
			for(int j = 0; j < i; ++j)
			{
				if(number[i] > number[j] && answer[j] + number[i] > temp)
					temp = answer[j] + number[i];
			}
			answer[i] = temp;
			if(answer[i] > max) max = answer[i];
		}
	}
	cout << max << endl;
	system("pause");
	return 0;
}
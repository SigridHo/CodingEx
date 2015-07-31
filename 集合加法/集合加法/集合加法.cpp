#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int a[10009] = {0};
int b[10009] = {0};
int main() 
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int sum = 0; 
		cin >> sum;
		int numa = 0;
		int numb = 0;
		cin >> numa;
		int temp = 0;
		for(int j = 0; j < numa; ++j)
		{
			cin >>  temp;
			a[temp]++;
		}
		cin >> numb;
		for(int j = 0;j < numb; ++j)
		{
			cin >> temp;
			b[temp]++;
		}
		int answer = 0;
		if(sum != 1) 
		{
			for(int i = 1; i < sum; ++i)
				answer += a[i] * b[sum - i];
		}
		cout << answer << endl;
	}
	return 0;
}
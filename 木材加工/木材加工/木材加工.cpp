#include <iostream>
#include <cstdio>
using namespace std;

int wood[10000] = {0};
int n, k = 0;
bool check(int max)
{
	int total = 0;
	for(int i = 0; i < n; ++i)
	{
		total += wood[i] / max;
	}
	if(total >= k) return true;
	else return false;
}
int main() 
{
	cin >> n >> k;
	long long sum = 0;
	for(int i = 0 ; i < n; ++i)
	{
		cin >> wood[i];
		sum += wood[i];
	}
	int right = sum / k;
	if(right == 0) 
	{
		cout << '0' << endl;
		return 0;
	}
	int left = 1;
	int max = 0;
	while(right != left && right != left + 1)
	{
		max = (right + left ) / 2;
		if(check(max))
		{
			left = max;
			
		}
		else
		{
			right = max;
		}
	}
	if(check(right)) cout << right << endl;
	else if(check(max)) cout << max << endl;
	else if(check(left)) cout << left << endl;
	else cout << '0' << endl;
	return 0;
}
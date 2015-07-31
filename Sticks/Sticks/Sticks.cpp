#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool used[65] = {0};
int n;
bool check(int rest, int RestLength, int length, int s[65])
{
	if(rest == 0 && RestLength == 0) return true;
	if(RestLength == 0)
		RestLength = length;
	for(int i = 0; i < n ; ++ i)
	{
		if(s[i] <= RestLength && used[i] == false)
		{
			if(i >= 1 && s[i] == s[i - 1] && used[i - 1] == false) continue;
			used[i] = true;
			if(check(rest - 1, RestLength - s[i], length, s))
			{
				return true;
			}
			else 
			{
				used[i] = false;
				if(RestLength == length) return false;
			}
		}
	}
	return false;
}

int main() 
{
	while(1)
	{
		
		cin >> n;
		if(n == 0) break;
		int s[70] = {0};
		int temp = 0;
		int sum = 0;
		int max = 0;
		for(int i = 0; i < n; ++i)
		{
			cin >> s[i];
			sum += s[i];
			if(s[i] > max) max = s[i];
		}
		memset(used, 0, sizeof(used));
		for(int i = 0; i < n - 1; ++i)
			for(int j = i + 1; j < n; ++j)
			{
				if(s[i] < s[j])
				{
					temp = s[i];
					s[i] = s[j];
					s[j] = temp;
				}
			}
		int length = 0;
		bool findout = false;
		for(length = max ; length <= sum / 2; ++length)
		{
			if(sum % length == 0)
			{
				memset(used, 0, sizeof(used));
				if(check(n, length, length, s))
				{
					cout << length << endl;
					findout = true;
					break;
				}
			}
		}
		if(!findout) cout << sum << endl;
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

vector <int> sticks;
int n;
int length = 0;
int used[70] = {0};
bool bfs(int r, int m)
{
	if(r == 0 && m == 0) return true;
	if(m == 0) m = length;
	for(int i = 0; i < n; ++i)
	{
		if(!used[i] && sticks[i] <= m)
		{
			if(i > 0)
			{
				if(!used[i - 1] && sticks[i - 1] == sticks[i]) continue;
			}
			used[i] = 1;
			if(bfs(r - 1, m - sticks[i])) return true;
			else
			{
				used[i] = 0;
				if(m == length) return false;
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
		int temp = 0, sum = 0;
		sticks.clear();
		memset(used, 0, sizeof(used));
		for(int i = 0; i < n; ++i)
		{
			cin >> temp;
			sticks.push_back(temp);
			sum += temp;
		}
		sort(sticks.begin(), sticks.end(), greater<int>());
		bool devide = false;
		for(length = sticks[0]; length <= sum / 2; ++length)
		{
			if(sum % length != 0) continue;
			if(bfs(n, length)) 
			{
				devide = true;
				cout << length << endl;
				break;
			}
		}
		if(!devide) cout << sum << endl;
	}
	return 0;
}
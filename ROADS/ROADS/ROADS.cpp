#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <cstdio>
#include <set>
using namespace std;

struct dest
{
	int city;
	int length;
	int toll;
};
vector<dest> map[120];
int mi = 100000000;
struct ans
{
	int length;
	int toll;
};
vector<ans> memory[120];
int k, n, r;

void fds(int s, int length, int toll)
{
	if(s == n) 
	{
		if(length < mi && toll <= k) mi = length;
		return;
	}
	if(toll > k) return;
	if(length > mi) return;
	if(map[s].size() != 0) 
	{
		int size = map[s].size();
		ans temp;
		for(int i = 0; i < size; ++i)
		{
			temp.length = length + map[s][i].length;
			temp.toll = toll + map[s][i].toll;
			if(memory[map[s][i].city].size() != 0)
			{
				int t = memory[map[s][i].city].size();
				bool check = true;
				for(int j = 0; j < t; ++j)
				{
					if(memory[map[s][i].city][j].length <= temp.length && memory[map[s][i].city][j].toll <= temp.toll) 
					{
						check = false;
						break;
					}
				}
				if(!check) continue;
			}
			if(toll + map[s][i].toll > k) continue;
			memory[map[s][i].city].push_back(temp);
			fds(map[s][i].city, length + map[s][i].length, toll + map[s][i].toll);
			
		}
	}
}
int main()
{
	
	cin >> k >> n >> r;
	int s, d, l, t;
	for(int i = 0; i < r; ++i)
	{
		dest temp;
		cin >> s >> d >> l >> t;
		temp.city = d;
		temp.length = l;
		temp.toll = t;
		map[s].push_back(temp);
	}
	fds(1, 0, 0);
	
	if(mi != 100000000)cout << mi << endl;
	else cout << "-1" << endl;

	
	system("pause");
	return 0;
}




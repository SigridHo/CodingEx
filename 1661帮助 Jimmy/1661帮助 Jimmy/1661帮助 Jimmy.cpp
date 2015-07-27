#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define impossible 10000000;
struct board
{
	int height;
	int left;
	int right;
};
board queue[1010] = {0};
int n, x, y, MAX;
bool operator < (board a1, board a2)
{
	return a1.height < a2.height;
}
int memleft[1010] = {0};
int memright[1010] = {0};
int rightmintime(int number);
int leftmintime(int number)
{
	if(memleft[number] != -1) return memleft[number];
	bool leftrest = false;
	for(int i = number - 1; i >= 0; -- i)
	{
		if(queue[i].left <= queue[number].left  && queue[i].right >= queue[number].left)
		{
			leftrest = true;
			if(queue[number].height  - queue[i].height > MAX) 
			{
				memleft[number] = impossible;
				return impossible;
			}
			else
			{
				int t1 = leftmintime(i) + queue[number].left - queue[i].left;
				int t2 = rightmintime(i) + queue[i].right - queue[number].left;
				memleft[number] = queue[number].height - queue[i].height + min(t1, t2);
				return memleft[number];
			}
		}
	}
	if(!leftrest)
	{
		if(queue[number].height > MAX)
		{
			memleft[number] = impossible;
			return impossible;
		}
		else 
		{
			memleft[number] = queue[number].height;
			return memleft[number];
		}
	}
}
int rightmintime(int number)
{
	if(memright[number] != -1) return memright[number];
	bool rightrest = false;
	for(int i = number - 1; i >= 0; -- i)
	{
		if(queue[i].left <= queue[number].right  && queue[i].right >= queue[number].right)
		{
			rightrest = true;
			if(queue[number].height  - queue[i].height > MAX) 
			{
				memright[number] = impossible;
				return impossible;
			}
			else
			{
				int t1 = leftmintime(i) + queue[number].right - queue[i].left;
				int t2 = rightmintime(i) + queue[i].right - queue[number].right;
				memright[number] = queue[number].height - queue[i].height + min(t1, t2);
				return memright[number];
			}
		}
	}
	if(!rightrest)
	{
		if(queue[number].height > MAX)
		{
			memright[number] = impossible;
			return impossible;
		}
		else 
		{
			memright[number] = queue[number].height;
			return memright[number];
		}
	}
}
int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		
		cin >> n  >> x >> y >> MAX;
		memset(queue, 0, sizeof(queue));
		memset(memleft, -1, sizeof(memleft));
		memset(memright, -1, sizeof(memright));
		queue[n].height = y;
		queue[n].left = x;
		queue[n].right = x;
		for(int j = 0; j < n; ++j)
		{
			cin >> queue[j].left >> queue[j].right >> queue[j].height;
		}
		sort(queue, queue + n + 1);
		int t1 = leftmintime(n);
		int t2 = rightmintime(n);
		if(t1 > t2) cout << t2 << endl;
		else cout << t1 << endl;
	}
	return 0;
}
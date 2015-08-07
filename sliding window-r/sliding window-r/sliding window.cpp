#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n, k;
int seq[1000010] = {0};
int vmin[1000010] = {0};
int vmax[1000010] = {0};
class cmp1
{
public:
	bool operator() (int a, int b) 
	{
		return seq[a] > seq[b];
	}
};
class cmp2
{
public:
	bool operator() (int a, int b) 
	{
		return seq[a] < seq[b];
	}
};
priority_queue<int , vector<int>, cmp1> MinQue;
priority_queue<int ,vector<int>, cmp2> MaxQue;

int main()
{
	scanf("%d%d", &n, &k);
	for(int i  = 0; i < n; ++i)
	{
		scanf("%d", &seq[i]);
	}
	for(int i = 0; i < k - 1; ++i)
	{
		MinQue.push(i);
		MaxQue.push(i);
	}
	for(int i = k -1; i < n; ++i)
	{
		MinQue.push(i);
		MaxQue.push(i);
		while(MinQue.top() < i - k + 1)
			MinQue.pop();
		vmin[i] = seq[MinQue.top()];
		while(MaxQue.top() < i - k + 1)
			MaxQue.pop();
		vmax[i] = seq[MaxQue.top()];
	}
	for(int i = k - 1; i < n; ++i )
	{
		if(i != n - 1)
			printf("%d ", vmin[i]);
		else
			printf("%d\n", vmin[i]);
	}
	for(int i  = k - 1; i < n; ++i)
	{
		if(i != n - 1)
			printf("%d ", vmax[i]);
		else
			printf("%d\n", vmax[i]);
	}
	system("pause");
	return 0;
}
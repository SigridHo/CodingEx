#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int open[100010] = {0};
int closed[100010] = {0};
int Head = 0;
int End = 0;

int bfs(int n, int k)
{
	for(int i = 0; ; ++i)
	{
		int temp = End;
		while(Head != temp)
		{
			if(Head == End) return 0;
			if(open[Head] == k) return i;
			if(open[Head] - 1 >= 0 &&  open[Head] - 1 <= 100000 && closed[open[Head] - 1] == 0)
			{
				closed[open[Head] - 1] = 1;
				open[End] = open[Head] - 1;
				++End;
			}
			if(open[Head] + 1 >= 0 && open[Head] + 1 <= 100000 && closed[open[Head] + 1] == 0)
			{
				closed[open[Head] + 1] = 1;
				open[End] = open[Head] + 1;
				++End;
			}
			if(open[Head] * 2 >= 0 && open[Head] * 2 <= 100000 && closed[open[Head] * 2] == 0)
			{
				closed[open[Head] * 2] = 1;
				open[End] = open[Head] * 2;
				++End;
			}
			Head++;
		}
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	open[0] = n;
	closed[n] = 1;
	End = 1;
	cout << bfs(n, k) << endl;
	system("pause");
	return 0;
}
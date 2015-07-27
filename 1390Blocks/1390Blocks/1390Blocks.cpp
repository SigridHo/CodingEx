#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <string>
#include <cstdio>
using namespace std;

int square[220] = {0};
int memory[220][220][220] = {0};
struct segment
{
	int color;
	int length;
};
segment queue[220] = {0};
int getscore(int begin, int end, int exlength)
{
	if(memory[begin][end][exlength] != 0) return memory[begin][end][exlength];
	if(begin == end)
	{
		memory[begin][end][exlength] = (exlength + queue[end].length) * (exlength + queue[end].length);
		return (exlength + queue[end].length) * (exlength + queue[end].length);
	}
	int score1 = getscore(begin, end - 1,0) + (exlength + queue[end].length) * (exlength + queue[end].length);
	int score2 = 0;
	for(int i = begin; i < end; ++i)
	{
		if(queue[i].color == queue[end].color)
		{
			score2 = getscore(begin, i, exlength + queue[end].length ) + getscore(i + 1, end - 1, 0);
			score1 = max(score1, score2);
		}
	}
	memory[begin][end][exlength] = score1;
	return score1;
}
int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i)
	{
		int n;
		cin >> n;
		memset(square, 0, sizeof(square));
		for(int j = 0; j < n; ++ j)
			cin >> square[j];
		memset(memory, 0, sizeof(memory));
		int segnum = 0;
		queue[0].color = square[0];
		queue[0].length = 1;
		for(int j = 1; j < n; ++j)
		{
			if(square[j] == square[j - 1])
			{
				queue[segnum].length++;
			}
			else
			{
				segnum++;
				queue[segnum].color =square[j];
				queue[segnum].length = 1;
			}
		}
		printf("Case %d: %d\n", i, getscore(0, segnum, 0));
	}
	return 0;
}
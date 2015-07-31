#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

char maze[35][35][35] = {0};
struct position
{
	int L;
	int R;
	int C;
	bool operator == (position temp)
	{
		if(L == temp.L && R == temp.R && C == temp.C) return true;
		else return false;
	}
};
int L, R, C;
position open[30000] = {0};
int closed[35][35][35] = {0};
int Head = 0;
int End = 0;
int step = 0;
bool bfs(position start, position end)
{
	for(step = 0;; ++step)
	{
		if(Head == End) return false;
		int temp = End;
		while(Head != temp)
		{
			if(open[Head] == end) return true;
			if(open[Head].L - 1 > 0 && open[Head].L - 1 <= L && maze[open[Head].L - 1][open[Head].R][open[Head].C] != '#' && closed[open[Head].L - 1][open[Head].R][open[Head].C] == 0)
			{
				open[End].L = open[Head].L - 1;
				open[End].R = open[Head].R;
				open[End].C = open[Head].C;
				closed[open[Head].L - 1][open[Head].R][open[Head].C] = 1;
				End++;
			}
			if(open[Head].R - 1 > 0 && open[Head].R - 1 <= R && maze[open[Head].L][open[Head].R - 1][open[Head].C] != '#' && closed[open[Head].L][open[Head].R - 1][open[Head].C] == 0)
			{
				open[End].L = open[Head].L;
				open[End].R = open[Head].R - 1;
				open[End].C = open[Head].C;
				closed[open[Head].L][open[Head].R - 1][open[Head].C] = 1;
				End++;
			}
			if(open[Head].C - 1 > 0 && open[Head].C - 1 <= C && maze[open[Head].L][open[Head].R][open[Head].C - 1] != '#' && closed[open[Head].L][open[Head].R][open[Head].C - 1] == 0)
			{
				open[End].L = open[Head].L;
				open[End].R = open[Head].R;
				open[End].C = open[Head].C - 1;
				closed[open[Head].L][open[Head].R][open[Head].C - 1] = 1;
				End++;
			}
			if(open[Head].L + 1 > 0 && open[Head].L + 1 <= L && maze[open[Head].L + 1][open[Head].R][open[Head].C] != '#' && closed[open[Head].L + 1][open[Head].R][open[Head].C] == 0)
			{
				open[End].L = open[Head].L + 1;
				open[End].R = open[Head].R;
				open[End].C = open[Head].C;
				closed[open[Head].L + 1][open[Head].R][open[Head].C] = 1;
				End++;
			}
			if(open[Head].R + 1 > 0 && open[Head].R + 1 <= R && maze[open[Head].L][open[Head].R + 1][open[Head].C] != '#' && closed[open[Head].L][open[Head].R + 1][open[Head].C] == 0)
			{
				open[End].L = open[Head].L;
				open[End].R = open[Head].R + 1;
				open[End].C = open[Head].C;
				closed[open[Head].L][open[Head].R + 1][open[Head].C] = 1;
				End++;
			}
			if(open[Head].C + 1 > 0 && open[Head].C + 1 <= C && maze[open[Head].L][open[Head].R][open[Head].C + 1] != '#' && closed[open[Head].L][open[Head].R][open[Head].C + 1] == 0)
			{
				open[End].L = open[Head].L;
				open[End].R = open[Head].R;
				open[End].C = open[Head].C + 1;
				closed[open[Head].L][open[Head].R][open[Head].C + 1] = 1;
				End++;
			}
			Head++;
		}
	}
}
int main()
{
	
	while(1)
	{
		cin >> L >> R >> C;
		if(L == 0 && R == 0 && C == 0) break;
		memset(maze, 0, sizeof(maze));
		memset(open, 0, sizeof(open));
		memset(closed, 0, sizeof(closed));
		Head = 0;
		End = 1;
		step = 0;
		position start;
		position end;
		for(int i = 1; i <= L; ++i)
		{
			for(int j = 1; j <= R; ++j)
			{
				for(int k = 1; k <= C; ++k)
				{
					cin >> maze[i][j][k];
					if(maze[i][j][k] == 'S') 
					{
						start.L = i;
						start.R = j;
						start.C = k;
					}
					if(maze[i][j][k] == 'E') 
					{
						end.L = i;
						end.R = j;
						end.C = k;
					}
				}
			}
		}
		open[0] = start;
		closed[start.L][start.R][start.C] = 1;
		if(bfs(start, end))
		{
			cout << "Escaped in " << step << " minute(s)." << endl;
		}
		else
		{
			cout << "Trapped!" << endl;
		}
	}
	return 0;
}
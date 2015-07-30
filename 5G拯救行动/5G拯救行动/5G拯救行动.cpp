#include <iostream>
#include <cstring>
#include <string>
using namespace std;

char Map[220][220] = {0};
int Flag[220][220] = {0};
struct point
{
	int x;
	int y;
};
bool operator == (point a1, point a2)
{
	if(a1.x == a2.x && a1.y == a2.y) return true;
	else return false;
}
point Start;
point Finish;
int Head, Tail;
point Opened[41000] = {0};
point Closed[41000] = {0};
int Floor = 0;
bool Check(point a)
{
	point tem;
	tem.x = a.x - 1;
	tem.y = a.y;
	if(tem == Finish) return true;
	tem.x = a.x + 1;
	tem.y = a.y;
	if(tem == Finish) return true;
	tem.x = a.x;
	tem.y = a.y - 1;
	if(tem == Finish) return true;
	tem.x = a.x;
	tem.y = a.y + 1;
	if(tem == Finish) return true;
	return false;
}
bool bfs()
{
	int temp = 1;
	while(1)
	{
		point tem;
		if(Opened[Head] == Finish)
		{
			return true;
		}
		if(Head == Tail) return false;
		if(Map[Opened[Head].x][Opened[Head].y] == '@' || Map[Opened[Head].x][Opened[Head].y] == 'r'|| (Map[Opened[Head].x][Opened[Head].y] == 'x' && Flag[Opened[Head].x][Opened[Head].y] == 2))
		{
			if((Map[Opened[Head].x - 1][Opened[Head].y] == 'a') || (Map[Opened[Head].x - 1][Opened[Head].y] == '@' && Flag[Opened[Head].x - 1][Opened[Head].y] == 0) || (Map[Opened[Head].x - 1][Opened[Head].y] == 'x' && Flag[Opened[Head].x - 1][Opened[Head].y] == 0))
			{
				Flag[Opened[Head].x - 1][Opened[Head].y]++;
				tem.x = Opened[Head].x - 1;
				tem.y = Opened[Head].y;
				Opened[Tail] = tem;
				Tail++;
			}
			if((Map[Opened[Head].x + 1][Opened[Head].y] == 'a') || (Map[Opened[Head].x + 1][Opened[Head].y] == '@' && Flag[Opened[Head].x + 1][Opened[Head].y] == 0) || (Map[Opened[Head].x + 1][Opened[Head].y] == 'x' && Flag[Opened[Head].x + 1][Opened[Head].y] == 0))
			{
				Flag[Opened[Head].x + 1][Opened[Head].y]++;
				tem.x = Opened[Head].x + 1;
				tem.y = Opened[Head].y;
				Opened[Tail] = tem;
				Tail++;
			}
			if((Map[Opened[Head].x][Opened[Head].y - 1] == 'a')||(Map[Opened[Head].x][Opened[Head].y - 1] == '@' && Flag[Opened[Head].x][Opened[Head].y - 1] == 0) || (Map[Opened[Head].x][Opened[Head].y - 1] == 'x' && Flag[Opened[Head].x][Opened[Head].y - 1] == 0))
			{
				Flag[Opened[Head].x][Opened[Head].y - 1]++;
				tem.x = Opened[Head].x;
				tem.y = Opened[Head].y - 1;
				Opened[Tail] = tem;
				Tail++;
			}
			if((Map[Opened[Head].x][Opened[Head].y + 1] == 'a')||(Map[Opened[Head].x][Opened[Head].y + 1] == '@' && Flag[Opened[Head].x][Opened[Head].y + 1] == 0) || (Map[Opened[Head].x][Opened[Head].y + 1] == 'x' && Flag[Opened[Head].x][Opened[Head].y + 1] == 0))
			{
				Flag[Opened[Head].x][Opened[Head].y + 1]++;
				tem.x = Opened[Head].x ;
				tem.y = Opened[Head].y + 1;
				Opened[Tail] = tem;
				Tail++;
			}
		}
		else
		{
			
				Flag[Opened[Head].x][Opened[Head].y]++;
				Opened[Tail] = Opened[Head];
				Tail++;
			
		}
		Head++;
		if(Head == temp)
		{
			Floor++;
			temp = Tail;
		}
	}
}
int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		memset(Map, 0, sizeof(Map));
		memset(Flag, 0, sizeof(Flag));
		memset(Opened, 0, sizeof(Opened));
		memset(Closed, 0, sizeof(Closed));
		Head = 0; Tail = 0;Floor = 0;
		int m, n;
		cin >> m >> n;
		for(int j = 1; j <= m; ++j)
			for(int k = 1; k <= n; ++k)
			{
				cin >> Map[j][k];
				if(Map[j][k] == 'r')
				{
					Start.x = j;
					Start.y = k;
					Flag[j][k] = 1;
					Opened[0] = Start;
					Tail = 1;
				}
				if(Map[j][k] == 'a')
				{
					Finish.x = j;
					Finish.y = k;
				}
			}
		if(bfs()) cout << Floor << endl;
		else cout << "Impossible" << endl;
	}
	return 0;
}
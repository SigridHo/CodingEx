#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct rice
{
	int x;
	int y;
};
rice plant[5001] = {0};
int n = 0;
int R, C;
bool operator < (rice a1, rice a2)
{
	if(a1.x != a2.x)
		return (a1.x < a2.x);
	else return (a1.y < a2.y);
}
int calculate(rice a1, rice a2)
{
	int step = 2;
	int dx = a2.x - a1.x;
	int dy = a2.y - a1.y;
	rice plant0;
	plant0.x = a2.x + dx;
	plant0.y = a2.y + dy;
	while(plant0.x >= 1 && plant0.x <= R && plant0.y >= 1 && plant0.y <= C)
	{
		if(binary_search(plant, plant + n, plant0))
		{
			step++;
			plant0.x += dx;
			plant0.y += dy;
		}
		else
		{
			step = 0;
			break;
		}
	}
	return step;
}

int main()
{
	cin >> R >> C;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> plant[i].x >> plant[i].y;
	}
	sort(plant, plant + n);
	int max = 2;
	for(int i = 0 ; i < n - 1; ++i)
		for(int j = i + 1; j < n; ++j)
		{
			int px = plant[i].x - (plant[j].x - plant[i].x);
			int py = plant[i].y - (plant[j].y - plant[i].y);
			if(px >= 1 && px <= R && py >= 1 && py <= C)
				continue;
			int dx = plant[i].x + (max - 1) * (plant[j].x - plant[i].x);
			int dy = plant[i].y + (max - 1) * (plant[j].y - plant[i].y);
			if(dx < 1 || dx > R) break;
			if(dy < 1 || dy > C) continue;
			int step = calculate(plant[i], plant[j]);
			if(step  > max) max = step;
		}
	if(max > 2)
		cout << max << endl; 
	else cout << "0" << endl;
	system("pause");
	return 0;
}
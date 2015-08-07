#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int step = 0;
int MaxA = 150;
int MaxB = 50010;
int used[200][50010] = {0};
class Pair
{
public:
	int valA;
	int valB;
	Pair(int a = 0, int b = 0): valA(a), valB(b){}
};
queue<Pair> List;
int t;
int front = 0;
int rear = 1;
void bfs()
{
	int p1 = front;
	int p2 = rear;
	while(!List.empty())
	{
		Pair temp = List.front();
		p1 = front;
		if(p1 == p2)
		{
			step++;
			p2 = rear;
		}
		if(temp.valA == t || temp.valB == t)
			return;
		int s = temp.valA + temp.valB;
		int sum = 2 * temp.valB;
		int sub = temp.valB - temp.valA;
		if(temp.valA < MaxA && s < MaxB && used[temp.valA][s] == 0)
		{
			Pair p(temp.valA, s);
			List.push(p);
			used[temp.valA][s] = 1;
			rear++;
		}
		if(temp.valB < MaxA && s < MaxB && used[temp.valB][s] == 0)
		{
			Pair p(temp.valB, s);
			List.push(p);
			used[temp.valB][s] = 1;
			rear++;
		}
		if(temp.valA < MaxA && sum < MaxB && used[temp.valA][sum] == 0)
		{
			Pair p(temp.valA, sum);
			List.push(p);
			used[temp.valA][sum] = 1;
			rear++;
		}
		if(temp.valB < MaxA && sum < MaxB && used[temp.valB][sum] == 0)
		{
			Pair p(temp.valB, sum);
			List.push(p);
			used[temp.valB][sum] = 1;
			rear++;
		}
		if(temp.valA < sub)
		{
			if(temp.valA < MaxA && sub < MaxB && used[temp.valA][sub] == 0)
			{
				Pair p(temp.valA, sub);
				List.push(p);
				used[temp.valA][sub] = 1;
				rear++;
			}
		}
		else
		{
			if(temp.valA < MaxB && sub < MaxA && used[sub][temp.valA] == 0)
			{
				Pair p(sub, temp.valA);
				List.push(p);
				used[sub][temp.valA] = 1;
				rear++;
			}
		}
		if(temp.valB < MaxB && sub < MaxA && used[sub][temp.valB] == 0)
		{
			Pair p(sub, temp.valB);
			List.push(p);
			used[sub][temp.valB] = 1;
			rear++;
		}
		List.pop();
		front++;
	}
}
int main()
{
	scanf("%d", &t);
	Pair p(0, 1);
	used[0][1] = 1;
	List.push(p);
	bfs();
	printf("%d\n", step);
	system("pause");
	return 0;
}
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 1010;
const int HashSize = 10007;
struct Point
{
	int x;
	int y;
	int key;
	Point()
	{
		x = 0;
		y = 0;
		key = 0;
	}
};
int GetKey(int a, int b)
{
	return ((a * a + b * b) % HashSize) + 1;
}
struct Node
{
	int x;
	int y;
	Node* next;
	Node()
	{
		x = 0;
		y = 0;
		next = NULL;
	}
};
Point Init[N];
Node* HashTable[HashSize];
void Insert(Point a)
{
	int label = a.key;
	if(HashTable[label] == NULL)
	{
		Node* temp = new Node;
		temp->x = a.x;
		temp->y = a.y;
		HashTable[label] = temp;
	}
	else
	{
		Node* temp = HashTable[label];
		while(temp->next)
		{
			temp = temp->next;
		}
		temp->next = new Node;
		temp->next->x = a.x;
		temp->next->y = a.y;
	}
}
bool Find(int x, int y)
{
	int label = GetKey(x, y);
	Node* temp = HashTable[label];
	while(temp != NULL)
	{
		if(((temp->x) == x) && ((temp->y == y)))
			return true;
		temp = temp->next;
	}
	return false;
}
int main()
{
	while(1)
	{
		int n;
		scanf("%d", &n);
		if(n == 0) break;
		memset(Init, 0, sizeof(Init));
		memset(HashTable, 0, sizeof(HashTable));
		for(int i = 0 ; i < n; ++i)
		{
			scanf("%d%d", &(Init[i].x), &(Init[i].y));
			Init[i].key = GetKey(Init[i].x, Init[i].y);
			Insert(Init[i]);
		}
		if(n < 4)
		{
			printf("0\n");
			continue;
		}
		long long ans = 0;
		for(int i = 0; i < n - 1; ++i)
		{
			for(int j = i + 1; j < n; ++j)
			{
				int a = Init[i].x - Init[j].x;
				int b = Init[i].y - Init[j].y;

				int x3 = Init[i].x + b;
				int y3 = Init[i].y - a;
				int x4 = Init[j].x + b;
				int y4 = Init[j].y - a;
				if(Find(x3, y3) && Find(x4, y4))
					ans++;
				x3 = Init[i].x - b;
				y3 = Init[i].y + a;
				x4 = Init[j].x - b;
				y4 = Init[j].y + a;
				if(Find(x3, y3) && Find(x4, y4))
					ans++;
			}
		}
		ans >>= 2;
		printf("%lld\n", ans);
	}
	return 0;
}
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int size = 10000;
struct Node
{
	int x;
	int y;
	int Num;
	Node* next;
	Node()
	{
		x = 0;
		y = 0;
		Num = 0;
		next = NULL;
	}
	bool operator == (Node a)
	{
		if(x != a.x) return false;
		if(y != a.y) return false;
		return true;
	}
	Node& operator = (Node &a)
	{
		x = a.x;
		y = a.y;
		Num = a.Num;
		if(a.next != NULL)
		{
			next = new  Node;
			*next = *(a.next);
		}
		else next = NULL;
		return *this;
	}
};
void Insert(Node HashTable[size + 10], int num, Node a)
{
	if(HashTable[num].Num == 0)
	{
		HashTable[num] = a;
		return ;
	}
	Node* &temp = HashTable[num].next;
	while(temp != NULL)
	{
		temp = temp->next;
	}
	temp = new Node;
	*temp = a;
	return ;
}
int GetKey(int a, int b)
{
	return (((a * a) + (b * b) + size) % size) + 1;
}
bool Find(Node HashTable[size + 10], int a, int b)
{
	Node temp;
	temp.x = a;
	temp.y = b;
	int key = GetKey(a, b);
	if(HashTable[key].Num == 0) return false;
	if(HashTable[key] == temp) return true;
	Node* Check = HashTable[key].next;
	while(1)
	{
		if(Check == NULL) break;
		if((*Check) == temp)
			return true;
		if(Check->next == NULL) break;
		*Check = *(Check->next);
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
		Node HashTable[size + 10];
		Node Init[1010];
		for(int i = 0; i < n; ++i)
		{
			scanf("%d%d", &Init[i].x, &Init[i].y);
			Init[i].Num = GetKey(Init[i].x, Init[i].y);
			Insert(HashTable, Init[i].Num, Init[i]);
		}
		long long ans = 0;
		if(n < 4) 
		{
			printf("0\n");
			continue;
		}
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
				if(Find(HashTable, x3, y3) && Find(HashTable, x4, y4))  
                    ans++;  
  
                x3 = Init[i].x - b;  
                y3 = Init[i].y + a;  
                x4 = Init[j].x - b;  
                y4 = Init[j].y + a;  
  
                if(Find(HashTable, x3,y3) && Find(HashTable, x4,y4))  
                    ans++;  
			}
		}
		ans >>= 2;
		printf("%lld\n", ans);
	}
	return 0;
}
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
class node
{
public:
	int val;
	node* prev, *next;
	node(int v = 0)
	{
		val = v;
		prev = NULL;
		next = NULL;
	}
};
class List
{
public:
	int size;
	node* head;
	node* tail;
	List(int s) 
	{
		head = tail = new node;
		size = s;
		node* ptr = head;
		for(int i = 1; i <= s; ++i)
		{
			ptr->next= new node(i);
			ptr->next->prev = ptr;
			ptr = ptr->next;
		}
		ptr->next = head->next;
		head->prev = ptr;
		tail = ptr;
	}
};

int cmp(const void* a, const void* b)
{
	return *((int *)a) - *((int *)b);
}
int main()
{
	int N, K, P;
	scanf("%d%d%d", &N, &K, &P);
	List arr(K);
	int* ans = new int[K / N + 1];
	int round = 0;
	int front = 0;
	int rear = K;
	while(arr.size > 0)
	{
		for(int i = 0; i < N - 1; ++i)
		{
			arr.head->next = arr.head->next->next;
			arr.head->next->prev = arr.head;
			arr.head->prev->next = arr.head->next;
			arr.size--;
			node* ptr = arr.head->next;
			for(int j = 0; j < P; ++j)
			{
				ptr = ptr->next;
			}
			arr.head->next->prev = arr.head->prev;
			arr.head->next= ptr;
			arr.head->prev = ptr->prev;
			ptr->prev = arr.head;
		}
		ans[round] = arr.head->next->val;
		arr.head->next = arr.head->next->next;
		arr.head->next->prev = arr.head;
		arr.head->prev->next = arr.head->next;
		arr.size--;
		node* ptr = arr.head->next;
		for(int j = 0; j < P; ++j)
		{
			ptr = ptr->next;
		}
		arr.head->next->prev = arr.head->prev;
		arr.head->next= ptr;
		arr.head->prev = ptr->prev;
		ptr->prev = arr.head;
		round++;
	}
	qsort(ans, round, sizeof(int), cmp);
	for(int i = 0; i < round; ++i)
		printf("%d\n", ans[i]);
	system("pause");
	return 0;
}
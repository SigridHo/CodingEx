#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

struct Node
{
	int count;
	Node* children[26];
	Node()
	{
		count = 0;
		memset(children, 0, sizeof(children));
	}
};
Node* tree = new Node;
char word[1000][30] = {0};
void insert(char a[30])
{
	int len = strlen(a);
	Node* temp = tree;
	for(int i = 0; i < len; ++i)
	{
		int m = a[i] - 'a';
		if(temp->children[m] == NULL)
		{
			temp->children[m] = new Node;
			(temp->children[m])->count = 1;
			temp = temp->children[m];
		}
		else
		{
			(temp->children[m])->count++;
			temp = temp->children[m];
		}
	}
}
void search(char a[30])
{
	Node* temp = tree;
	int len = strlen(a);
	char b[30] = {0};
	strcpy(b, a);
	for(int i = 0; i < len; ++i)
	{
		int m = a[i] - 'a';
		if((temp->children[m])->count == 1)
		{
			b[i + 1] = 0;
			printf("%s %s\n", a, b);
			return;
		}
		else
			temp = temp->children[m];
	}
	printf("%s %s\n", a, b);
}
int main()
{
	int i =0;
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	while(cin >> word[i])
	{
		insert(word[i]);
		i++;
	}
	for(int j = 0; j < i; ++j)
	{
		search(word[j]);
	}
	return 0;
}
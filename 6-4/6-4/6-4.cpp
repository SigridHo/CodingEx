#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

class Node
{
public:
	int Mark;
	Node* son[10];
	Node()
	{
		Mark = 0;
		memset(son, NULL, sizeof(son));
	}
	Node operator = (Node a)
	{
		Mark = a.Mark;
		for(int i = 0; i < 10; ++i)
		{
			son[i] = a.son[i];
		}
		return *this;
	}
};
class tenTree
{
public:
	Node* root;
	tenTree()
	{
		root = new Node;
	}
	bool Insert(Node* current, char* Phone, int len, int i);
};
bool tenTree::Insert(Node* current, char* Phone, int len, int i)
{
	int SonID = Phone[i] - '0';
	if((current->son)[SonID] == NULL)
	{
		(current->son)[SonID] = new Node;
	}
	else
	{
		if((current->son)[SonID]->Mark != 0)
			return false;
		if(i == len - 1) return false;
	}
	if(i == len - 1)
	{
		(current->son)[SonID]->Mark = 1;
		return true;
	}
	return Insert((current->son)[SonID], Phone, len, i + 1);
}
int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i)
	{
		int n;
		scanf("%d", &n);
		tenTree tree;
		bool FindOut = false;
		for(int i = 0; i < n; ++i)
		{
			char temp[12] = {0};
			scanf("%s", temp);
			int len = strlen(temp);
			bool InsertSucceed = true;
			if(!FindOut) 
				InsertSucceed = tree.Insert(tree.root, temp, len, 0);
			if(!InsertSucceed) FindOut = true;
		}
		if(FindOut) printf("NO\n");
		else printf("YES\n");
	}

	return 0;
}
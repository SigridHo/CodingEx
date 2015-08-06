#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

class Node
{
public:
	char key[20];
	Node *parent, *Lson, *Rson;
	Node(char* info)
	{
		strcpy(key, info);
		parent = NULL;
		Lson = NULL;
		Rson = NULL;
	}
	Node()
	{
		key[0] = '\0';
		parent = NULL;
		Lson = NULL;
		Rson = NULL;
	}
	Node operator = (Node a)
	{
		strcpy(key, a.key);
		parent = a.parent;
		Lson = a.Lson;
		Rson = a.Rson;
		return *this;
	}
};
const int lineSize = 20;
char line[lineSize];
bool findout(Node* root, char* info)
{
	bool GetIt = false;
	if(strcmp(info, root->key) == 0) 
	{
		GetIt = true;
		while(root->Rson != NULL)
		{
			root = root->Rson;
			printf("%s", root->key);
		}
		printf("\n");
		return GetIt;
	}
	else
	{
		if(root->Lson != NULL)
		{
			GetIt = findout(root->Lson, info);
			if(GetIt) return GetIt;
		}
		if(root->Rson != NULL)
		{
			return findout(root->Rson, info);
		}
	}
	return false;
}
int main()
{
	int n;
	scanf("%d\n", &n);
	char info[20] = {0};
	for(int i = 0; i < n; ++i)
	{
		Node* root = NULL;
		Node* current = new Node;
		stack <Node* > Parent;
		bool son = true;
		while(1)
		{
			info[0] = '\0';
			cin.getline(info, lineSize, '\n');
		//	sscanf(line, "%s", info);
			if(info[0] == '\0')
				break;
			if(info[0] == '{')
			{
				son = true;
				Parent.push(current);
			}
			else if(info[0] == '}')
			{
				current = Parent.top();
				Parent.pop();
				son = false;
			}
			else
			{
				if(root == NULL)
				{
					root = new Node(info);
					current = root;
				}
				else
				{
					if(son)
					{
						current->Lson = new Node(info);
						current->Lson->parent = current;
						current = current->Lson;
					}
					else
					{
						current->Rson = new Node(info);
						current->Rson->parent = current;
						current = current->Rson;
					}
					son = false;
				}
			}
		}
		info[0] = '\0';
		cin.getline(info, lineSize, '\n');
	//	sscanf(line, "%s", info);
		if(!findout(root, info))
			printf("No\n");
		cin.getline(line, lineSize, '\n');
		cin.getline(line, lineSize, '\n');
	}
	scanf("!");
	system("pause");
	return 0;
}

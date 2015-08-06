#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

char Proceeding[1001000] = {0};
class Node
{
public:
	Node *parent, *Lson, *Rson;
	Node()
	{
		parent = NULL;
		Lson = NULL;
		Rson = NULL;
	}
};
int Depth2 = 0;
void dfs(Node* root, int row)
{
	if(row > Depth2) Depth2 = row;
	if(root->Lson != NULL)
	{
		dfs(root->Lson, row + 1);
	}
	if(root->Rson != NULL)
		dfs(root->Rson, row + 1);
}
int main()
{
	int number = 1;
	while(1)
	{
		memset(Proceeding, 0, sizeof(Proceeding));
		cin >> Proceeding;
		if(Proceeding[0] == '#') 
			break;
		int len = strlen(Proceeding);
		int Depth1 = 0;
		int temp = 0;
		for(int i = 0 ; i < len; ++i)
		{
			if(Proceeding[i] == 'd')
			{
				temp++;
				if(temp > Depth1) Depth1 = temp;
			}
			else
				temp--;
		}
		Node* root = new Node;
		Node* current = root;
		for(int i = 0; i < len; ++i)
		{
			if(Proceeding[i] == 'd')
			{
				if(current->Lson == NULL)
				{
					current->Lson = new Node;
					current->Lson->parent = current;
					current = current->Lson;
				}
				else
				{
					current = current->Lson;
					while(current->Rson != NULL)
					{
						current = current->Rson;
					}
					current->Rson = new Node;
					current->Rson->parent = current;
					current = current->Rson;
				}
			}
			else
			{
				if(current->parent->Lson == current)
				{
					current = current->parent;
				}
				else
				{
					while(current->parent->Lson != current)
					{
						current = current->parent;
					}
					current = current->parent;
				}
			}
		}
		Depth2 = 0;
		dfs(root, 0);
		printf("Tree %d: %d => %d\n", number, Depth1, Depth2);
		number++;
	}
	return 0;
}
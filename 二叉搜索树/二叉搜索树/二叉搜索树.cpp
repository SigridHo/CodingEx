#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

class Node
{
public:
	int key;
	Node* parent;
	Node* Lson;
	Node* Rson;
	Node(int val = 0)
	{
		key = val;
		parent = NULL;
		Lson = NULL;
		Rson = NULL;
	}
};
class BST
{
public:
	Node* root;
	BST() {root = NULL;}
	void Insert(int val)
	{
		if(root == NULL)
		{
			root = new Node(val);
		}
		else
		{
			Node* ptr = root;
			while(ptr != NULL)
			{
				if(ptr->key == val)
					return;
				else if(ptr->key < val)
				{
					if(ptr->Rson == NULL)
					{
						ptr->Rson = new Node(val);
						return;
					}
					else ptr = ptr->Rson;
				}
				else 
				{
					if(ptr->Lson == NULL)
					{
						ptr->Lson = new Node(val);
						return;
					}
					else ptr = ptr->Lson;

				}
			}
		}
	}
};
int ans[10000] = {0};
int step = 0;
void Travel(Node* p)
{
	if(p == NULL) return;
	ans[step] = p->key;
	step++;
	Travel(p->Lson);
	Travel(p->Rson);
}
int main()
{
	int temp;
	BST tree;
	while(cin >> temp)
	{
		tree.Insert(temp);
	}
	Travel(tree.root);
	for(int i = 0; i < step; ++i)
	{
		if(i != step - 1)
			cout << ans[i] << ' ';
		else cout << ans[i] << endl;
	}
	system("pause");
	return 0;

}
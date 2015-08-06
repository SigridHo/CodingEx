#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

class BinaryTreeNode
{
public:
	int key;
	BinaryTreeNode* parent, *Lson, *Rson;
	BinaryTreeNode()
	{
		parent = NULL;
		Lson = NULL;
		Rson = NULL;
	}
};
class BinarySearchTree
{
public:
	BinaryTreeNode* root;
	BinarySearchTree(){root = NULL;};
	void InsertNode(BinaryTreeNode * newpointer);
};
void BinarySearchTree::InsertNode(BinaryTreeNode * newpointer)
{
	BinaryTreeNode * pointer = NULL;
	if(root == NULL)
	{
		root = new BinaryTreeNode;
		root = newpointer;
		return;
	}
	else pointer = root;
	while(pointer != NULL)
	{
		if(newpointer->key == pointer->key)
			return;
		else if(newpointer->key < pointer->key)
		{
			if(pointer->Lson == NULL)
			{
				pointer->Lson = newpointer;
				return;
			}
			else
				pointer = pointer->Lson;
		}
		else
		{
			if(pointer->Rson == NULL)
			{
				pointer->Rson = newpointer;
				return ;
			}
			else pointer = pointer->Rson;
		}
	}
}
int result[10000] = {0};
int cal = 0;
void dfs(BinaryTreeNode* current)
{
	result[cal] = current->key;
	cal++;
	if(current->Lson != NULL)
	{
		dfs(current->Lson);
	}
	if(current->Rson != NULL)
	{
		dfs(current->Rson);
	}
}
int main()
{
	int value;
	BinarySearchTree BST;
	while(cin >> value)
	{
		BinaryTreeNode* temp;
		temp = new BinaryTreeNode;
		temp->key = value;
		BST.InsertNode(temp);
	}
		memset(result,sizeof(result), 0);
		dfs(BST.root);
		cout << result[0];
		if(cal > 1)
		{
			for(int i = 1; i < cal; ++i)
			{
				cout << ' ' << result[i];
			}
		}
		cout << endl;
	system("pause");
	return 0;
}
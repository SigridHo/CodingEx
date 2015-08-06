#include <iostream>
#include <cstring>
#include <string>
using namespace std;

char first[110] = {0};
char middle[110] = {0};
char last[110] = {0};

class BinaryTreeNode
{
public:
	char value;
	BinaryTreeNode* leftchild;
	BinaryTreeNode* rightchild;
	BinaryTreeNode* parent;
	BinaryTreeNode() 
	{
		value = 0;
		leftchild = NULL;
		rightchild = NULL;
		parent = NULL;
	}
};
class BinaryTree
{
public:
	BinaryTreeNode* root;
	BinaryTree() {root = NULL;};
};
int fstep = 0, mstep = 0, lstep = 0;
void gothrough(BinaryTreeNode* root)
{
	if(root != NULL)
	{
		first[fstep] = root->value;
		fstep++;
		if(root->leftchild != NULL) gothrough(root->leftchild);
		middle[mstep] = root->value;
		mstep++;
		if(root->rightchild != NULL) gothrough(root->rightchild);
		last[lstep] = root->value;
		lstep++;
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i< n; ++i)
	{
		BinaryTree tree;
		BinaryTreeNode* pointer = tree.root;
		BinaryTreeNode* parentpointer= NULL;
		int prev = 0;
		int current = 0;
		bool noleft = false;
		while(1)
		{
			char TreeInfo [110] = {0};
			cin >> TreeInfo;
			if(strcmp(TreeInfo, "0") == 0) break;
			
			char info;
			current = 0;
			while(TreeInfo[current] == '-')
				current++;
			if(TreeInfo[current] == '*') 
			{
				noleft = true;
				pointer = NULL;
				parentpointer->rightchild = pointer;
				continue;
			}
			else 
			{
				info = TreeInfo[current];
			}
			if(!noleft) 
			{
				pointer = new BinaryTreeNode;
				pointer->value = info;
				if(prev < current) 
				{
					pointer->parent = parentpointer;
					parentpointer->leftchild = pointer;
				}
				else if(current > 0)
				{
					for(int k = prev; k >= current; k--)
					{
						parentpointer = parentpointer->parent;
					}
					if(parentpointer != NULL)
					{
						pointer->parent = parentpointer;
						parentpointer->rightchild = pointer;
					}
				}
			}
			else
			{
				pointer = new BinaryTreeNode;
				pointer->value = info;
				if(prev < current) 
				{
					pointer->parent = parentpointer;
					parentpointer->rightchild = pointer;
				}
				else if(current > 0)
				{
					
					for(int k = prev; k >= current; k--)
					{
						parentpointer = parentpointer->parent;
					}
					if(parentpointer != NULL)
					{
						pointer->parent = parentpointer;
						parentpointer->rightchild = pointer;
					}
				}
			}
			parentpointer = pointer;
			prev = current;
			if(current == 0)
			{
				pointer->parent = NULL;
				tree.root = pointer;
			}
			pointer = pointer->leftchild;
			noleft = false;
		}
		memset(first, 0, sizeof(first));
		memset(middle, 0, sizeof(middle));
		memset(last, 0, sizeof(last));
		mstep = 0;
		fstep = 0;
		lstep = 0;
		gothrough(tree.root);
		cout << first << endl;
		cout << last << endl;
		cout << middle << endl;
		cout << endl;
	}
	system("pause");
	return 0;
}
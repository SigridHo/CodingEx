#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

class Node
{
public:
	int  Count;
	Node *parent, *Lson, *Rson;
	Node()
	{
		parent = NULL;
		Lson = NULL;
		Rson = NULL;
		Count = 1;
	}
	Node operator = (Node a)
	{
		parent = a.parent;
		Lson = a.Lson;
		Rson = a.Rson;
		return *this;
	}
};
class ParentTree
{
public:
	Node* arr;
	int Size;
	ParentTree(int size)
	{
		arr = new Node[size];
		Size = size;
	}
	Node* FindPC(Node* node);
	bool Different(int i, int j);
	void Union(int i, int j);
};
Node* ParentTree::FindPC(Node* node) 
{	
	if(node->parent == NULL)
		return node;
	node->parent = (FindPC(node->parent));
	return node->parent;
}
bool ParentTree::Different(int i,int j){
	Node* pointeri = FindPC(&arr[i]);		//找到结点i的根
	Node* pointerj = FindPC(&arr[j]);		//找到结点j的根
	return pointeri != pointerj;
}
void ParentTree::Union(int i,int j){
	//将结点i和结点j所属的树合并成为一棵树
	Node* pointeri = FindPC(&arr[i]);	//找到结点i的根
	Node* pointerj = FindPC(&arr[j]); 	//找到结点j的根	
	if(pointeri != pointerj){
		if(pointeri->Count >= pointerj->Count)
		{
			pointerj->parent = pointeri;
		    pointeri->Count = pointeri->Count + pointerj->Count;
		}
		else
		{
		    pointeri->parent = pointerj;
		    pointerj->Count = pointeri->Count + pointerj->Count;
		}
	}//end if
}

int main()
{
	int number = 1;
	while(1)
	{
		int n, m;
		cin >> n >> m;
		if( n == 0 && m == 0)
			break;
		int val1, val2;
		ParentTree tree(n);
		for(int i = 0; i < m ;++i)
		{
			cin >> val1 >> val2;
			if(tree.Different(val1 - 1, val2 - 1))
				tree.Union(val1 - 1, val2 - 1);
		}
		int sum = 0;
		for(int i = 0; i < n; ++i)
			if((tree.arr[i]).parent == NULL) sum++;
		printf("Case %d: %d\n", number, sum);
		number++;
	}
	return 0;
}
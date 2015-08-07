#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

class HuffmanTreeNode
{
public:
	int key;
	HuffmanTreeNode* parent, *Lson, *Rson;
	bool operator < (const HuffmanTreeNode & temp) const
	{
		return key > temp.key;
	}
	HuffmanTreeNode() {parent = NULL; Lson = NULL; Rson = NULL;};
};
class HuffmanTree
{
public:
	HuffmanTreeNode * root;
	void MergeTree(HuffmanTreeNode ht1, HuffmanTreeNode ht2, HuffmanTreeNode * parent);
	HuffmanTree(int weight[], int n);
};
void cal(int & sum, int depth,HuffmanTreeNode* current)
{
	if(current->Lson == NULL && current->Rson == NULL)
		sum += depth * current->key;
	else
	{
		if(current->Lson != NULL)
			cal(sum, depth + 1, current->Lson);
		if(current->Rson != NULL)
			cal(sum, depth + 1, current->Rson);
	}
}
class cmp   
{  
    public:  
    bool operator()( const HuffmanTreeNode & n1, const HuffmanTreeNode & n2) const  
    {  
        return n1 < n2;  
    }  
};  
void HuffmanTree::MergeTree(HuffmanTreeNode ht1, HuffmanTreeNode ht2, HuffmanTreeNode * parent)
{
	parent->Lson = new HuffmanTreeNode;
	ht1.parent = parent;
	*(parent->Lson) = ht1;
	parent->Rson = new HuffmanTreeNode;
	ht2.parent = parent;
	*(parent->Rson) = ht2;
	parent->key = ht1.key + ht2.key;
}
HuffmanTree::HuffmanTree(int weight[], int n)
{
	priority_queue<HuffmanTreeNode, vector<HuffmanTreeNode>, cmp> q;
	HuffmanTreeNode * NodeList = new HuffmanTreeNode[n];
	for(int i = 0; i < n; ++i)
	{
		NodeList[i].key = weight[i];
		NodeList[i].parent = NodeList[i].Lson = NodeList[i].Rson = NULL;
		q.push(NodeList[i]);
	}

	for(int i = 0; i < n - 1; ++i)
	{
		HuffmanTreeNode *parent, firstchild, secondchild;
		parent = new HuffmanTreeNode;
		firstchild = q.top();

		q.pop();
		secondchild = q.top();
		q.pop();
		MergeTree(firstchild, secondchild, parent);
		q.push(*parent);
		root = parent;
	}
	delete []NodeList;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		int weight[110] = {0};
		for(int j = 0; j < n; ++j)
		{
			cin >> weight[j];
		}
		HuffmanTree HT(weight, n);
		int sum = 0;
		cal(sum, 0, HT.root);
		cout << sum << endl;
	}
	return 0;	
}
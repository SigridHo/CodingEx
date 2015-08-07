#include <iostream>
#include <cstring>

class BinaryTreeNode{};

void InOrder(BinaryTreeNode* pointer, BinaryTreeNode* root)
{
	if(root != NULL)
	{
		InOrder(pointer, root->leftchild());		// 没遇到一个节点，先访问其左子树
		if(root->leftchild() == NULL && root->rightchild() == NULL)
		{											// 该节点为叶节点
			if(pointer == NULL)						// pointer为头结点
			{
				pointer = root;						// 直接将head指向当前节点
			}
			else 
			{
				pointer->right = root;				// pointer为叶节点，将其右指针指向当前节点
				pointer = root;						// 相当于将当前节点插入链表
			}

		}
		InOrder(pointer, root->rightchild());		// 访问右子树
	}
}
BinaryTreeNode* LeaveList(BinaryTreeNode* root)
{
	BinaryTreeNode* head = NULL;					// 生成头结点
	InOrder(head, root);							// 递归遍历构建链表
	return head;									// 返回头结点
}
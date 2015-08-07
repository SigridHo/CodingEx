#include <iostream>
#include <cstring>

class BinaryTreeNode{};

void InOrder(BinaryTreeNode* pointer, BinaryTreeNode* root)
{
	if(root != NULL)
	{
		InOrder(pointer, root->leftchild());		// û����һ���ڵ㣬�ȷ�����������
		if(root->leftchild() == NULL && root->rightchild() == NULL)
		{											// �ýڵ�ΪҶ�ڵ�
			if(pointer == NULL)						// pointerΪͷ���
			{
				pointer = root;						// ֱ�ӽ�headָ��ǰ�ڵ�
			}
			else 
			{
				pointer->right = root;				// pointerΪҶ�ڵ㣬������ָ��ָ��ǰ�ڵ�
				pointer = root;						// �൱�ڽ���ǰ�ڵ��������
			}

		}
		InOrder(pointer, root->rightchild());		// ����������
	}
}
BinaryTreeNode* LeaveList(BinaryTreeNode* root)
{
	BinaryTreeNode* head = NULL;					// ����ͷ���
	InOrder(head, root);							// �ݹ������������
	return head;									// ����ͷ���
}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <cmath>
using namespace std;

int value[30] = {0};
int sum = 0;
int L = 0;
int R = 0;
class Node
{
public:
	char key;
	Node* parent, *Lson, *Rson;
	Node(char val = 0)
	{
		key = val;
		parent = NULL;
		Lson = NULL;
		Rson = NULL;
	}
	Node operator = (Node a)
	{
		key = a.key;
		parent = a.parent;
		Lson = a.Lson;
		Rson = a.Rson;
		return *this;
	}
};
int Calculate(int a, int b, char op)
{
	switch(op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		return 0;
	}
}
bool IsOper(char op)
{
	char str[6] = {'(', ')', '+', '-', '*', '/'};
	for(int i = 0;  i < 6; ++i)
	{
		if(op == str[i])
			return true;
	}
	return false;
}
int GetPriority(char op)
{
	switch(op)
	{
	case '*':
	case '/':
		return 2; break;
	case '+':
	case '-':
		return 1; break;
	default:
		return 0;
	}
}
void build(Node* &temp, char expr[])
{
	stack <char> OperStack;
	stack <Node* > DataStack;
	stack <int> Answer;
	char CurrentChar = 0;
	int Calculator = 0;
	CurrentChar = expr[Calculator];
	Calculator++;
	char TmpChar;
	while(CurrentChar != '\0' || (!OperStack.empty()))
	{
		if(CurrentChar != '\0' && (!IsOper(CurrentChar)))
		{
			temp = new Node(CurrentChar);
			DataStack.push(temp);
			Answer.push(value[CurrentChar - 'a']);
			CurrentChar = expr[Calculator];
			Calculator++;
		}
		else
		{
			if(CurrentChar == '(')
			{
				OperStack.push(CurrentChar);
				CurrentChar = expr[Calculator];
				Calculator++;
			}
			else if(CurrentChar == ')')
			{
				while(1)
				{
					TmpChar = OperStack.top();
					OperStack.pop();
					if(TmpChar == '(')
						break;
					temp = new Node(TmpChar);
					if(!DataStack.empty())
					{
						temp->Rson = DataStack.top();
						DataStack.pop();
						sum = Answer.top();
						R = sum;
						Answer.pop();
					}
					if(!DataStack.empty())
					{
						temp->Lson = DataStack.top();
						DataStack.pop();
						sum = Answer.top();
						L = sum;
						Answer.pop();
					}
					if((temp->Rson != NULL) && (temp->Lson != NULL))
						sum = Calculate(L, R, TmpChar);
					Answer.push(sum);
					DataStack.push(temp);
				}
				CurrentChar = expr[Calculator];
				Calculator++;
			}
			else if(OperStack.empty() || (CurrentChar != '\0' && (GetPriority(CurrentChar) > GetPriority(OperStack.top()))))
			{
				OperStack.push(CurrentChar);
				CurrentChar = expr[Calculator];
				Calculator++;
			}
			else
			{
				temp = new Node(OperStack.top());
				OperStack.pop();
				if(!DataStack.empty())
				{
					temp->Rson = DataStack.top();
					DataStack.pop();
					sum = Answer.top();
					R = sum;
					Answer.pop();
				}
				if(!DataStack.empty())
				{
					temp->Lson = DataStack.top();
					sum = Answer.top();
					L = sum;
					Answer.pop();
					DataStack.pop();
				}
				DataStack.push(temp);
				if((temp->Lson != NULL) && (temp->Rson != NULL))
					sum = Calculate(L, R, temp->key);
				Answer.push(sum);
			}
		}
	}
	sum = Answer.top();
}
int Maxrow = 0;
int Maxline = 0;
int LeftTotal = 0;
bool right = false;
void LastTra(Node* p, int row)
{
	if(row > Maxrow) Maxrow = row;
	if(p->Lson != NULL)
	{
		LastTra(p->Lson, row + 1);
	}
	if(p->Rson != NULL)
	{
		LastTra(p->Rson, row + 1);
	}
	cout << p->key;
}
string ans[1000];
void print(Node* sta, int depth, int col, int row,int maxh)
{
	if (sta == NULL)
		return;
	while (ans[row].size() < col)
		ans[row] += ' ';
	ans[row] += sta->key;
	if (sta->Lson != NULL)
	{
		while (ans[row + 1].size() < col - 1)
			ans[row + 1] += ' ';
			ans[row + 1] += "/ \\";
	}
	print(sta->Lson, depth + 1, col - (int)pow(2, (double)maxh - depth - 1), row + 2, maxh);
	print(sta->Rson, depth + 1, col + (int)pow(2, (double)maxh - depth - 1), row + 2, maxh);
}

int main()
{
	
	char expression[10000] = {0};
	cin >> expression;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		char var;
		cin >> var;
		int info;
		cin >> info;
		value[var - 'a'] = info;
	}
	Node* tree = NULL;
	build(tree, expression);
	LastTra(tree, 0);
	cout << endl;
	print(tree, 0, (int)pow(2, (double)Maxrow ) - 1, 0, Maxrow);
	int MaxLength = 0;
	for(int i = 0; i <= 2 * Maxrow; ++i)
	{
		if(ans[i].size() > MaxLength) MaxLength = ans[i].size();
	}
	for(int i = 0; i <= 2 * Maxrow; ++i)
	{
		cout << ans[i];
		int j = ans[i].size();
		for(; j < MaxLength; j++)
			cout << ' ';
		cout << endl;
	}
	cout << sum << endl;
	
	return 0;
}
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

class operation
{
public:
	char ope[10];
	int number;
	operation(char a[10] = NULL, int value = 0)
	{
		if(a != NULL) strcpy(ope, a);
		else ope[0] = NULL;
		number = value;
	}
};
operation ops[2000];

class Stack
{
private:
	int mSize;
	int top;
	int* st;
public:
	Stack(int size = 1001)
	{
		mSize = size;
		top = -1;
		st = new int[mSize];
	}
	~Stack()
	{
		delete[] st;
	}
	void clear()
	{
		top = -1;
	}
	bool push(const int item);
	bool pop(int & item);
	bool peek(int & item);
};
bool Stack::peek(int &item)
{
	if(top == -1) return false;
	else 
	{
		item = st[top];
		return true;
	}
	
}
bool Stack::push(const int item)
{
	if(top == mSize - 1) return false;
	top++;
	st[top] = item;
	return true;
}
bool Stack::pop(int &item)
{
	if(top == -1)
		return false;
	item = st[top];
	top--;
	return true;
}
int main()
{
	int n;
	cin >> n;
	int result[1000] = {0};
	for(int i = 0; i < n; ++i)
		cin >> result[i];
	Stack st;
	st.push(1);
	ops[0].number = 1;
	strcpy(ops[0].ope, "PUSH");
	int count = 1;
	int point = 2;
	bool finish = true;
	for(int i = 0; i < n; ++i)
	{
		if(result[i] < 1 || result[i] > n) 
		{
			cout << "NO" << endl;
			finish = false;
			break;
		}
		else
		{
			int temp;
			st.peek(temp);
			while(temp < result[i])
			{
				st.push(point);
				strcpy(ops[count].ope, "PUSH");
				ops[count].number = point;
				point++;
				count++;
				st.peek(temp);
			}
			if(temp == result[i])
			{
				st.pop(temp);
				strcpy(ops[count].ope, "POP");
				ops[count].number = temp;
				count++;
			}
			if(temp > result[i])
			{
				cout << "NO" << endl;
				finish = false;
				break;
			}
		}
		
	}
	if(finish)
	{
		for(int i = 0; i < count; ++i)
		{
			cout << ops[i].ope << ' ' << ops[i].number << endl;
		}
	}
	system("pause");
	return 0;
}
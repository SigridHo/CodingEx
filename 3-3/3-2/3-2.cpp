#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

class arr
{
public:
	int digits[5];
	int length;
	arr operator = (arr val);
};
arr arr::operator=(arr val)
{
	length = val.length;
	for(int i = 0; i < length; ++i)
		digits[i] = val.digits[i];
	return *this;
}
arr exchange(int value, int len)
{
	arr temp; 
	temp.length = len;
	for(int i = 0; i < len; ++i)
	{
		temp.digits[i] = value % 10;
		value /= 10;
	}
	return temp;
}
int Number_Length(int value)
{
	int length = 0;
	while(value != 0)
	{
		value = value / 10;
		length++;
	}
	return length;
}
int arrtonum(arr val)
{
	int result = 0;
	for(int i = val.length - 1; i >= 0; --i)
	{
		result *= 10;
		result += val.digits[i];
	}
	return result;
}
class Queue
{
private:
	int mSize;
	int front;
	int rear;
	arr * qu;
public:
	Queue(int size = 1010)                            // build up a queue
	{
		mSize = size + 1;
		qu = new arr[mSize];
		front = rear = 0;
	}
	~Queue()
	{
		delete[] qu;
	}
	bool enQueue(arr item);
	bool deQueue(arr& item);
	void show_Queue();
};

bool Queue::deQueue(arr& item)
{
	if(front == rear) return false;
	item = qu[front];
	front = (front + 1) % mSize;
	return true;
}

bool Queue::enQueue(arr item)
{
	if(((rear + 1) % mSize) == front)
		return false;
	qu[rear] = item;
	rear = (rear + 1) % mSize;
	return true;
}

void Queue::show_Queue()
{
	if(front != rear)
	{
		cout << arrtonum(qu[front]);
		if((front + 1) % mSize != rear)
		{
			for(int i = front + 1; i < rear; ++i)
			{
				cout << ' ' << arrtonum(qu[i]);
			}
		}
	}
	cout << endl;
}
int main()
{
	int n;
	cin >> n;
	int initial[1010] = {0};
	int Max_Number = -1;
	for(int i = 0; i < n; ++i)
	{
		cin >> initial[i];
		if(initial[i] > Max_Number)
			Max_Number = initial[i];
	}
	int len = Number_Length(Max_Number);
	arr data[1010];
	for(int i = 0; i < n; ++i)
	{
		data[i] = exchange(initial[i], len);
	}
	Queue qu[10];
	for(int i = 0; i < len; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			qu[data[j].digits[i]].enQueue(data[j]);
		}
		cout << "Step" << i + 1 << "." << endl;
		for(int j = 0; j < 10; ++j)
		{
			cout << "Queue" << j << ':';
			qu[j].show_Queue();
		}
		int pc = 0;
		for(int j = 0; j < 10; ++j)
		{
			while(qu[j].deQueue(data[pc]))
			{
				pc++;
			}
		}
	}
	cout << arrtonum(data[0]);
	if(n > 1)
	{
		for(int i = 1; i < n; ++i)
			cout <<  ' ' << arrtonum(data[i]);
	}
	cout << endl;
	system("pause");
	return 0;
}
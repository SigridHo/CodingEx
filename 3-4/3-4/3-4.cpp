#include <iostream>
using namespace std;
int Min = 0x7fffffff;
int Max = 0x80000000;
class min_max
{
public:
	int min;
	int max;
	min_max operator=(min_max value)
	{
		min = value.min;
		max = value.max;
		return *this;
	}
};
class Queue
{
private:
	int mSize;
	int front;
	int rear;
	int* qu;
public:
	Queue(int size = 1000001)
	{
		mSize = size + 1;
		qu = new int[mSize];
		front = rear = 0;
	}
	~Queue()
	{
		delete[] qu;
	}
	void clear()
	{
		front = rear;
	}
	bool enQueue(int item)
	{
		if(((rear + 1) % mSize) == front)
			return false;
		qu[rear] = item;
		rear = (rear + 1) % mSize;
		return true;
	}
	bool deQueue()
	{
		if(front == rear)
			return false;
		front = (front + 1) % mSize;
		return true;
	}
	min_max getvalue();
};
min_max Queue::getvalue()
{
	min_max result;
	result.max = Max;
	result.min = Min;
	if(front == rear)
	{
		return result;
	}
	if(Max != 0x80000000 && Min != 0x7FFFFFFF && qu[rear] > Max) 
	{
		Max = qu[rear];
		result.max = qu[rear];
		return result;
	}
	else if(Max != 0x80000000 && Min != 0x7FFFFFFF && qu[rear] < Min)
	{
		Min = qu[rear];
		result.min = qu[rear];
		return result;
	}
	else if(Max != 0x80000000 && Min != 0x7FFFFFFF && qu[front] > Min && qu[front] < Max)
		return result;
	else
	{
		int i = front;
		while(i != rear)
		{
			if(qu[i] < result.min) result.min = qu[i];
			if(qu[i] > result.max) result.max = qu[i];
			i = (i + 1) % mSize;
		}
		return result;
	}
}
int initial[1000000] = {0};
min_max answer[1000000];
int main()
{
	int n, k;
	cin >> n >> k;
	
	for(int i = 0 ; i < n; ++i)
		cin>> initial[i];
	Queue sequence(k);
	for(int i = 0; i < k; ++i)
		sequence.enQueue(initial[i]);
	answer[0] = sequence.getvalue();
	if(n - k > 1)
	{
		for(int i = 1; i <= n - k; ++i)
		{
			sequence.deQueue();
			sequence.enQueue(initial[i + k - 1]);
			answer[i] = sequence.getvalue();
		}
	}
	cout << answer[0].min;
	if(n - k > 1)
	{
		for(int i = 1; i <= n - k; ++i)
			cout << ' ' << answer[i].min;
	}
	cout << endl;
	cout << answer[0].max;
	if(n - k > 1)
	{
		for(int i = 1; i <= n - k; ++i)
			cout << ' ' << answer[i].max;
	}
	cout << endl;
	system("pause");
	return 0;
}
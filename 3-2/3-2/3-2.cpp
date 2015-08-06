#include <iostream>
using namespace std;

class Pair
{
public:
	int val1;
	int val2;
	Pair(int a = 0, int b = 0)
	{
		val1 = a;
		val2 = b;
	}
	Pair operator = (Pair val)
	{
		val1 = val.val1;
		val2 = val.val2;
		return *this;
	}
};
const int a = 10000;
const int b = 50000;
int used[20001][20001] = {0};
int P = 0;

class Queue
{
public:
	int mSize;
	int front;
	int rear;
	Pair* qu;
	Queue(int size = 300000)
	{
		mSize = size + 1;
		qu = new Pair[mSize];
		front = rear = 0;
	}
	~Queue()
	{
		delete [] qu;
	}
	bool enQueue(Pair item);
	bool deQueue(Pair& item);
	bool getFront(Pair& item);
};
bool Queue::enQueue(Pair item)
{
	if(((rear + 1) % mSize) == front)
		return false;
	qu[rear] = item;
	rear = (rear + 1) % mSize;
	return true;
}
bool Queue::deQueue(Pair& item)
{
	if(front == rear) return false;
	item = qu[front];
	front = (front + 1) % mSize;
	return true;
}
bool Queue::getFront(Pair& item)
{
	if(front == rear) return false;
	item = qu[front];
	return true;
}
Queue sequence;
int step = 0;
void bfs()
{
	int p1 = sequence.front;
	int p2 = sequence.rear;
	int sum = 0;
	int sub = 0;
	while(sequence.front != sequence.rear)
	{
		
		Pair temp;
		sequence.getFront(temp);
		p1 = sequence.front;
		if(p1 == p2) 
		{
			step++;
			p2 = sequence.rear;
		}
		if(temp.val1 == P || temp.val2 == P)
			return;
		sum = temp.val1 + temp.val2;
		if(temp.val1 < 150 && sum < 50010 && used[temp.val1][sum] == 0)
		{
			Pair t1(temp.val1, sum);
			sequence.enQueue(t1);
			used[temp.val1][sum] = 1;
		}
		if(temp.val2 < 150 && sum < 50010 && used[temp.val2][sum] == 0)
		{
			Pair t1(temp.val2, sum);
			sequence.enQueue(t1);
			used[temp.val2][sum] = 1;
		}
	/*	if(temp.val1 != 0)
		{
			sum = temp.val1 * 2;
			if(temp.val1 < 150 && sum < 50010 && used[temp.val1][sum] == 0)
			{
				Pair t1(temp.val1, sum);
				sequence.enQueue(t1);
				used[temp.val1][sum] = 1;
			}
			if(temp.val2 > sum)
			{
				if(sum < 150 && temp.val2 < 50010 && used[sum][temp.val2] == 0)
				{
					Pair t1(sum, temp.val2);
					sequence.enQueue(t1);
					used[sum][temp.val2] = 1;
				}
			}
			else
			{
				if(temp.val2 < 150 && sum < 50010 && used[temp.val2][sum] == 0)
				{
					Pair t1(temp.val2, sum);
					sequence.enQueue(t1);
					used[temp.val2][sum] = 1;
				}
			}
		} */
		sum = temp.val2 * 2;
		if(temp.val1 < 150 && sum < 50010 && used[temp.val1][sum] == 0)
		{
			Pair t1(temp.val1, sum);
			sequence.enQueue(t1);
			used[temp.val1][sum] = 1;
		}
		if(temp.val2 < 150 && sum < 50010 && used[temp.val2][sum] == 0)
		{
			Pair t1(temp.val2, sum);
			sequence.enQueue(t1);
			used[temp.val2][sum] = 1;
		}
		sub = temp.val2 - temp.val1;
		if(sub > temp.val1)
		{
			if(temp.val1 < 150 && sub < 50010 && used[temp.val1][sub] == 0)
			{
				Pair t1(temp.val1,sub);
				sequence.enQueue(t1);
				used[temp.val1][sub] = 1;
			}
		}
		else
		{
			if(sub < 150 && temp.val1 < 50010 && used[sub][temp.val1] == 0)
			{
				Pair t1(sub, temp.val1);
				sequence.enQueue(t1);
				used[sub][temp.val1] = 1;
			}
		}
		if(sub < 150 && temp.val2 < 50010 && used[sub][temp.val2] == 0)
		{
			Pair t1(sub, temp.val2);
			sequence.enQueue(t1);
			used[sub][temp.val2] = 1;
		}
		Pair t2;
		sequence.deQueue(t2);
	}
}
int main()
{
	
	cin >> P;
	Pair temp(0, 1);
	used[0][1] = 1;
	sequence.enQueue(temp);
	bfs();
	cout << step << endl;
	system("pause");
	return 0;
}

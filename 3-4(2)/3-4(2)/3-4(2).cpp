#include <iostream>
using namespace std;

int MinSequence[1000000] = {0};
int MaxSequence[1000000] = {0};
int n, k;
class data
{
public:
	int value;
	int position;
	data operator =(data val)
	{
		value = val.value;
		position = val.position;
		return *this;
	}
};

class LQueue
{
private:
	int mSize;
	int front;
	int rear;
	data* qu;
public:
	LQueue(int size)
	{
		mSize = size + 1;
		front = rear = 0;
		qu = new data[mSize];
	}
	~LQueue()
	{
		delete qu;
	}
	data enQueue(data item);
};
data LQueue::enQueue(data item)
{
	int i = (rear - 1 + mSize) % mSize;
	while(i >= front && qu[i].value > item.value)
	{
		i--;
	}
	int temp = (i + 1) % mSize;
	qu[temp] = item;
	rear = (i + 2) % mSize;
	if(qu[temp].position  - qu[front].position >= k) front = (front + 1) % mSize;
	return qu[front];
}
class GQueue
{
private:
	int mSize;
	int front;
	int rear;
	data* qu;
public:
	GQueue(int size)
	{
		mSize = size + 1;
		front = rear = 0;
		qu = new data[mSize];
	}
	~GQueue()
	{
		delete qu;
	}
	data enQueue(data item);
};
data GQueue::enQueue(data item)
{
	int i = (rear - 1 + mSize) % mSize;
	while(i >= front && qu[i].value < item.value)
	{
		i--;
	}
	int temp = (i + 1) % mSize;
	qu[temp] = item;
	rear = (i + 2) % mSize;
	if(qu[temp].position  - qu[front].position >= k) front = (front + 1) % mSize;
	return qu[front];
}
data ini[1000000];
int initial[1000000];
int main()
{
	
	cin >> n >> k;
	
	for(int i = 0 ; i < n; ++i)
	{
		cin>> initial[i];
		ini[i].position = i;
		ini[i].value = initial[i];
	}
	LQueue sequence1(n);
	GQueue sequence2(n);
	for(int i = 0; i < k - 1; ++i)
	{
		sequence1.enQueue(ini[i]);
		sequence2.enQueue(ini[i]);
	}
	int j = 0;
	for(int i = k - 1; i < n; ++i)
	{
		MinSequence[j] = (sequence1.enQueue(ini[i])).value;
		MaxSequence[j] = (sequence2.enQueue(ini[i])).value;
		j++;
	}
	cout << MinSequence[0];
	int tem = 1;
	if(n - k > 1)
	{
		while(tem < j)
		{
			cout << ' ' << MinSequence[tem];
			tem++;
		}
	}
	cout << endl;
	cout << MaxSequence[0];
	tem = 1;
	if(n - k > 1)
	{
		while(tem < j)
		{
			cout << ' ' << MaxSequence[tem];
			tem++;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}


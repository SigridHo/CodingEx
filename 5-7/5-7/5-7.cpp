#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

class MinHeap
{
public:
	int* arr;
	int CurrentSize;
	int MaxSize;
	MinHeap(int n);
	bool Insert(int& newNode);
	void ShiftUp(int position);
	void ShiftDown(int position);
	int parent(int pos)
	{
		return (pos - 1) / 2;
	}
	int RemoveMin();
};
bool MinHeap::Insert(int& newNode) {
	if (CurrentSize==MaxSize)		
		return false;
	arr[CurrentSize]=newNode;
	ShiftUp(CurrentSize);			
	CurrentSize++;
}
void MinHeap::ShiftUp(int position) {    
	int temppos = position;
	int temp = arr[temppos];
	while ((temppos > 0) && (arr[parent(temppos)]>temp)) 
	{
		arr[temppos] = arr[parent(temppos)];
	    temppos = parent(temppos);
	}
	arr[temppos]=temp;
}
void MinHeap::ShiftDown (int position)
{
	int i = position;			
	int j = 2 * i + 1;				
	int	temp = arr[i];		
	while (j < CurrentSize){		
	      if ((j < CurrentSize - 1)&(arr[j] > arr[j + 1]))
		      j++;			
	      if (temp > arr[j]){
		      arr[i] = arr[j];
		      i = j;
			  j = 2 * j + 1;		
	      }  else break;
	}
	arr[i]=temp;
}


MinHeap::MinHeap(int n)
{
	if(n < 0)
		return;
	else
	{
		arr = new int[n];
		CurrentSize = 0;
		MaxSize = n;
	}
}
int MinHeap::RemoveMin() 
{ 
	if (CurrentSize==0)
	{
		return 0;
	}
	else { 
		CurrentSize--;
		int temp = arr[0];
		arr[0] = arr[CurrentSize];
		arr[CurrentSize] = temp;
		if (CurrentSize>1)  			 
			ShiftDown(0);			
		return arr[CurrentSize];
	}
} 

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		MinHeap MH(n);
		for(int j = 0; j < n; ++j)
		{
			int type;
			cin >> type;
			if(type == 1)
			{
				int value;
				cin >> value;
				MH.Insert(value);
			}
			else
			{
				cout << MH.RemoveMin() << endl;
			}
		}
	}
	system("pause");
	return 0;
}
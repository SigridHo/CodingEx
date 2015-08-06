#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

int* Middle;
int* Last;
int* First;
int CurrentFirst = 0;

void FindFirst(int* M, int* L, int number)
{
	First[CurrentFirst] = *(L + number - 1);
	CurrentFirst++;
	int left = 0;
	for(left = 0; left < number; ++left)
	{
		if(*(M + left) == *(L + number - 1))
			break;
	}
	if(left > 0) FindFirst(M, L, left);
	int right = number - left - 1;
	if(right > 0) 
	{
		M = M + left + 1;
		L = L + left;
		FindFirst(M, L, right);
	}
}
int main()
{
	Middle = new int[2000];
	Last = new int[2000];
	First = new int[2000];
	int i = 0;
	int Number = 0;
	while(1)
	{
		
		cin >> Middle[i];
		Number++;
		i++;
		char c = getchar();
		if(c == '\n') break;
	}
	for(i = 0; i < Number; ++i)
	{
		cin >> Last[i];
	}
	FindFirst(Middle, Last, Number);
	for(int i = 0; i < Number - 1; ++i)
	{
		cout << First[i] << ' ';
	}
	cout << First[Number -1] << endl;
	system("pause");
	return 0;
}

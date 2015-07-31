#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int closed[362890] = {0};
char moved[362890] = {0};
int open[362890][10] = {0};
int Head = 0;
int End = 1;
char answer[362890] = {0};
bool check(int a[9])
{
	for(int i = 0; i < 8; ++i)
	{
		if(a[i] != i + 1) return false;
	}
	if(a[8] != 0) return false;
	else return true;
}
int times[10] = {1, 1, 2, 6, 24,120,720, 5040, 40320, 362880};
int number(int a[10])
{
	int sum = 1;
	for(int i = 0; i < 9; ++i)
	{
		if(i == 0) sum += (a[i] - 1) * times[8 - i];
		else
		{
			int temp = 0;
			for(int j = 0; j < i ; ++j)
			{
				if(a[j] < a[i]) temp++;
			}
			sum += (a[i] - 1 - temp) * times[8 - i];
		}
	}
	return sum;
}
int temp[10] = {0};
void bfs()
{
	
	while(1)
	{
		int num = number(open[Head]);
		if(num == 1) return;
		if(Head == End) return;
		if(open[Head][9] - 3 >= 0)
		{
			for(int i = 0; i < 9; ++i)
				temp[i] = open[Head][i];
			temp[open[Head][9]] = temp[open[Head][9] - 3];
			temp[open[Head][9] - 3] = 9;
			if(closed[number(temp)] == 0)
			{
				
				moved[number(temp)] = 'u';
				closed[number(temp)] = num;
				for(int i = 0; i < 9; ++i)
					open[End][i] = temp[i];
				open[End][9] = open[Head][9] - 3;
				End++;
			}
		}
		if(open[Head][9] + 3 <= 8)
		{
			for(int i = 0; i < 9; ++i)
				temp[i] = open[Head][i];
			temp[open[Head][9]] = temp[open[Head][9] + 3];
			temp[open[Head][9] + 3] = 9;
			if(closed[number(temp)] == 0)
			{
	
				moved[number(temp)] = 'd';
				closed[number(temp)] = num;
				for(int i = 0; i < 9; ++i)
					open[End][i] = temp[i];
				open[End][9] = open[Head][9] +3;
				End++;
			}
		}
		if(open[Head][9] % 3 != 0)
		{
			for(int i = 0; i < 9; ++i)
				temp[i] = open[Head][i];
			temp[open[Head][9]] = temp[open[Head][9] - 1];
			temp[open[Head][9] - 1] = 9;
			if(closed[number(temp)] == 0)
			{
				
				moved[number(temp)] = 'l';
				closed[number(temp)] = num;
				for(int i = 0; i < 9; ++i)
					open[End][i] = temp[i];
				open[End][9] = open[Head][9] - 1;
				End++;
			}
		}		
		
		if(open[Head][9] % 3 != 2)
		{
			for(int i = 0; i < 9; ++i)
				temp[i] = open[Head][i];
			temp[open[Head][9]] = temp[open[Head][9] + 1];
			temp[open[Head][9] + 1] = 9;
			if(closed[number(temp)] == 0)
			{
				
				moved[number(temp)] = 'r';
				closed[number(temp)] = num;
				for(int i = 0; i < 9; ++i)
					open[End][i] = temp[i];
				open[End][9] = open[Head][9] + 1;
				End++;
			}
		}
		
		
		Head++;
	}
}
int main()
{
	
	char temp = 0;
	int zero = -1;
	for(int i = 0; i < 9; ++i)
	{
		cin >> temp;
		if(temp == 'x') 
		{
			open[0][i] = 9;
			zero = i;
		}
		else open[0][i] = temp - '0';
	}
	open[0][9] = zero;
	closed[number(open[0])] = -1;
	int sum = 0;
	for(int i = 1; i < 9; ++i)
	{
		for(int j = 0; j < i; ++j)
		{
			if(open[0][i] != 9 && open[0][j] != 9 && open[0][j] > open[0][i]) sum++;
		}

	}
	if(sum % 2 != 0) cout << "unsolvable" << endl;
	else
	{
		bfs();
		int tem = number(open[Head]);
		int i = 0;
		int n = number(open[0]);
		for(;; ++i)
		{
			
			answer[i] = moved[tem];
			if(closed[tem] == n) break; 
			tem = closed[tem];
			
		}
		for(int j = i; j >= 0; -- j)
			cout << answer[j];
		cout << endl;
	}
	system("pause");
	return 0;
}


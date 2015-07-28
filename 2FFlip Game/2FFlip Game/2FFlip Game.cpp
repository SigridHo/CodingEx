#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int chess[6][6] = {0};
int first[6] = {0};
set <int> a;
int swi[6][6] = {0};
int copychess[6][6] = {0};
void settle(int num, int first[6])
{
	for(int i = 1; i <= 4; ++i)
	{
		first[i] = num % 2;
		num /= 2;
	}
}
void change(int i ,int j)
{
	copychess[i][j] ^= 1;
	copychess[i - 1][j] ^= 1;
	copychess[i + 1][j] ^= 1;
	copychess[i][j - 1] ^= 1;
	copychess[i][j + 1] ^= 1;

}
bool chec(int color)
{
	for(int i = 1; i <=4; ++i)
		for(int j= 1; j <= 4; ++j)
		{
			copychess[i][j] = chess[i][j];
		}
	for(int i = 1; i <= 4; ++i)
	{
		swi[1][i] = first[i];
		if(first[i] == 1) change(1, i);
	}
	for(int i = 1; i <= 3; ++i)
	{
		for(int j = 1; j <= 4; ++j)
		{
			if(copychess[i][j] == color)
			{
				swi[i + 1][j] = 1;
				change(i + 1, j);
			}
		}

	}
	for(int i = 1; i <= 4; ++i)
	{
		if(copychess[4][i] == color)return false;
	}
	int sum = 0;
	for(int i = 1; i <= 4; ++i)
		for(int j = 1; j <= 4; ++j)
		{
			if(swi[i][j] == 1) sum++;
		}
	a.insert(sum);
	return true;
}
int main()
{
	char c;
	bool findout = false;
	for(int i =1; i <=4; ++i)
		for(int j = 1; j <= 4; ++j)
		{
			cin >> c;
			if(c == 'b') chess[i][j] = 0;
			else chess[i][j] = 1;
		}
	for(int i = 0; i < 16; ++i)
	{
		settle(i, first);
		if(chec(0))
		{
			memset(swi, 0, sizeof(swi));
			findout = true;
		}
		if(chec(1))
		{
			memset(swi, 0, sizeof(swi));
			findout = true;
		}
	}
	if(!findout) cout << "Impossible"  << endl;
	else cout << *a.begin() << endl;
	system("pause");
	return 0;
}
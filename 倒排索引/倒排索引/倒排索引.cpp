#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

struct Node
{
	int Number;
	string arr[100];
	Node()
	{
		Number = 0;
	}
};
Node Library[1010];
int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		int len;
		scanf("%d", &len);
		Library[i].Number = len;
		for(int j = 0; j < len; ++j)
		{
			cin >> (Library[i].arr)[j];
		}
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; ++i)
	{
		string tmp;
		cin >> tmp;
		int ans[1010] = {0};
		bool Found = false;
		int cnt = 0;
		for(int j = 1; j <= N; ++j)
		{
			for(int k = 0; k < Library[j].Number; ++k)
			{
				if(tmp == (Library[j].arr)[k])
				{
					Found = true;
					ans[cnt] = j;
					cnt++;
					break;
				}
			}
		}
		if(Found)
		{
			for(int j = 0; j < cnt; ++j)
			{
				if(j != cnt - 1)
					cout << ans[j] << ' ' ;
				else cout << ans[j] << endl;
			}
		}
		else
			cout << "NOT FOUND\n";
	}
	system("pause");
	return 0;
}
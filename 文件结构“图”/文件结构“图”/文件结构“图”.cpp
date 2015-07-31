#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <iterator>
#include <cstdio>
using namespace std;

string arr[10000];
struct mycompare
{
	bool operator () (string a, string b)
	{
		return a < b;
	}
};
int show(int m, int n)
{
	if(m == 0) printf("ROOT\n");
	else 
	{
		for(int i = 0; i < m; ++i)
			printf("|     ");
		cout << arr[n] << endl;
	}
	set<string,mycompare> myset;
	int i = 0;
	for(i = n + 1; ; ++i)
	{
		if(arr[i][0] == 'f') myset.insert(arr[i]);
		else if(arr[i][0] == 'd') i = show(m + 1, i); 
		else if(arr[i][0] == ']' || arr[i][0] == '*') break;
	}
	set<string,mycompare>::iterator it;
	if(myset.begin() != myset.end()) 
		for(it = myset.begin(); it != myset.end(); it++)
			{
				for(int i = 0; i < m; ++i)
					printf("|     ");
				cout << *it << endl;
			}
	myset.clear();
	return i;
}
int main()
{
	for(int n = 1; ; ++n)
	{
		for(int i = 0; ; ++i)
		{
			cin >> arr[i];
			if(arr[i][0] == '*') break;
			if(arr[i][0] == '#') return 0;
		}
		printf("DATA SET %d:\n", n);
		show(0, -1);
		cout << endl;
		for(int i = 0; i < 10000; ++i)
			if(arr[i] != "")arr[i] = "";
	}
	return 0;
}
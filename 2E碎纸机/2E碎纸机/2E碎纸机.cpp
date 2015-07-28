#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

char s1[8] = {0};
char s2[8] = {0};
int aim = 0;
multiset<int, greater<int> > result;
bool error = false;
bool rejected = false;
bool zero = false;
bool findout= false;
void crash(int times, char s[8], int done)
{
	if(times == 0)
	{
		int t = atoi(s) + done;
		if(t <= aim)
		{
			result.insert(t);
			return;
		}
	}
	int len = strlen(s);
	int sum = 0;
	int temp = 0;
	for(int i = 0; i < len - times; ++i)
	{
		temp = 0;
		for(int j = 0; j <= i; ++j)
		{
			temp *= 10;
			temp += s[j] - '0';
		}
		char ts[8]= {0};
		for(int j = i + 1; j < len; ++j)
		{
			ts[j - i - 1] = s[j];
		}
		crash(times - 1, ts, temp);
	}
}
int main()
{
	while(1)
	{
		cin >> s1 >> s2;
		if(strcmp(s1, "0") == 0 && strcmp(s2, "0") == 0) break;
		error = false;
		rejected = false;
		findout = false;
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		result.clear();
		aim = atoi(s1);
		if(strcmp(s1, s2) == 0)
		{
			cout << s1 << endl;
			continue;
		}
		for(int i = len2 - len1; i < len2; ++i)
		{
			crash(i, s2, 0);
		}
		if(result.end() == result.begin()) 
		{
			error = true;
			cout << "error" << endl;
			continue;
		}
		if(*result.begin() == *(result.begin()++))
		{
			rejected = true;
			cout << "rejected" << endl;
			continue;
		}
		cout << *(result.begin()) << ' ';

	}
	return 0;
}
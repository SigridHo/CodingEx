#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

char s1[8] = {0};
char s2[8] = {0};
int aim = 0;
int kn[6] = {0};
int length = 0;
struct result
{
	int sum;
	vector<int> knives;
};
bool operator < (result a1, result a2)
{
	return a1.sum > a2.sum ;
}
bool operator == (result a1, result a2)
{
	if(a1.sum == a2.sum )
	{
		for(int i = 0; i < 6; ++i)
			if(a1.knives[i] != a2.knives[i]) return false;
		return true;
	}
	return false;
}
multiset<result> answer;

bool crack(int time, char s[8],int ki, int done)
{
	if(done > aim) return false;
	result tem;
	if(time == 0)
	{
		done = done + atoi(s);
		if(done <= aim)
		{
			tem.sum =done;
			for(int i = 0; i < 6; ++i)
			{
				(tem.knives).push_back(kn[i]);
			}
			answer.insert(tem);
			return true;
		}
		return false;
	}
	int len = strlen(s);
	for(int i = 0; i < len - time; ++i)
	{
		kn[ki] = length - strlen(s) + i + 1;
		char st[8] = {0};
		int temp = 0;
		for(int j = 0; j <= i; ++j)
		{
			temp *= 10;
			temp += s[j] - '0';
		}
		for(int j = i + 1; j < len; ++j)
		{
			st[j - i - 1] = s[j];
		}
		done += temp;
		crack(time - 1, st, ki + 1, done);
		done -= temp;
	}
	return true;
}

int main()
{
	while(1)
	{
		cin >> s1 >> s2;
		if(strcmp(s1, "0") == 0 && strcmp(s2, "0") == 0) break;
		if(strcmp(s1, s2) == 0)
		{
			cout << s1 << ' ' << s1 << endl;
			continue;
		}
		answer.clear();
		memset(kn, 0, sizeof(kn));
		int len1= strlen(s1);
		int len2 = strlen(s2);
		length = len2;
		aim = atoi(s1);
		for(int i = 0; i < len2; ++i)
		{
			crack(i, s2, 0, 0);
		}
		if(answer.begin() == answer.end()) 
		{
			cout << "error" << endl;
		}
		else 
		{
			if(answer.size() > 1 && (!((*(answer.begin())) == (*(++answer.begin())))) && (*(answer.begin())).sum == (*(++answer.begin())).sum)
			{
				cout << "rejected" << endl;
			}
			else
			{
				cout << (*(answer.begin())).sum << ' ';
				int t = 0;
				for(t = 0; t < len2; ++t)
				{
					cout << s2[t];
					for(int j = 0; j < 6; ++j)
					{
						if(t == ((*(answer.begin())).knives)[j] - 1) cout << ' ';
					}
				}
				cout << endl;
			}
		}
	}
	return 0;
}
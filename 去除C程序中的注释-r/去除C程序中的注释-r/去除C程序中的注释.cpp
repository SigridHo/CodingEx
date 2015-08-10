#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char src[20000] = {0};
char dest[20000] = {0};
bool str = false;
bool cha = false;
bool note = false;
bool backslash = false;

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	cin.getline(src, 20000, 0);
	int len = strlen(src);
	int j = 0;
	for(int i  =0; i < len ;++i)
	{
		if(!note)
		{
			if(!str && !cha)
			{
				if((src[i] == '/') && (i + 1 < len) && (src[i + 1] == '*'))
				{
					i++;
					note = true;
				}
				else
				{
					dest[j] = src[i];
					j++;
				}
				if(src[i] == '\'' && !backslash)
					cha = true;
				if(src[i] == '\"' && !backslash)
					str = true;
				if(src[i] == '\\')
					backslash = true;
				else backslash = false;

			}
			else if(str)
			{
				dest[j] = src[i];
				j++;
				if(src[i] == '\"' && !backslash)
					str = false;
				if(src[i] == '\\')
					backslash = true;
				else backslash = false;
			}
			else if(cha)
			{
				dest[j] = src[i];
				j++;
				if(src[i] == '\'' && !backslash)
					cha = false;
				if(src[i] == '\\')
					backslash = true;
				else backslash = false;
			}
		}
		else
		{
			if((src[i] == '*') && (i + 1 < len) && (src[i + 1] == '/'))
			{
				i++;
				note = false;
			}
			if(src[i] == '\\')
				backslash = true;
			else backslash = false;
		}
	}
	printf("%s", dest);
	return 0;
}
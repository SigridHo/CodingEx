#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;


char student[55][55] = {0};
char teacher[300] = {0};
bool check(char dest[55], char source[300])
{
	int len = strlen(dest);
	int j = 0;
	for(int i = 0 ; i< len; ++i)
	{
		if(dest[i] == source[j] || dest[i] - 'a' + 'A' == source[j] || dest[i] - 'A'  + 'a' == source[j])
		{
			j++;
			continue;
		}
		else if(source[j] == '[')
		{
			bool temp = false;
			while(source[j] != ']')
			{
				j++;
				if(dest[i] == source[j]|| dest[i] - 'a' + 'A' == source[j] || dest[i] - 'A' + 'a' == source[j])
				{
					temp = true;
				}
			}
			if(!temp) return false;
			else 
			{
				j++;
				continue;
			}
		}
		else return false;
	}
	int len2 = strlen(source);
	if(len2 != j) return false;
	return true;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n; ++i)
	{
		cin >> student[i];
	}
	cin >> teacher;
	for(int i = 0 ; i < n; ++i)
	{
		if(check(student[i], teacher))
		{
			cout << i + 1 << ' ' << student[i] << endl;
		}
	}
	system("pause");
	return 0;
}

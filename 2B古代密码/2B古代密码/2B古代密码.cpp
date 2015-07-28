#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	char s1[110] = {0};
	char s2[110] = {0};
	cin >> s1 >> s2;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int count1[30] = {0};
	int count2[30] = {0};
	for(int i = 0 ; i < len1; ++i)
	{
		count1[s1[i] - 'A']++;
	}
	sort(count1, count1 + 26);
	for(int i = 0; i < len2; ++i)
	{
		count2[s2[i] - 'A']++;
	}
	sort(count2, count2 + 26);
	bool temp = true;
	for(int i = 0; i < 26; ++i)
	{
		if(count1[i] != count2[i])
		{
			temp = false;
			cout << "NO" << endl;
			break;
		}

	}
	if(temp) cout << "YES" << endl;
	system("pause");
	return 0;

}

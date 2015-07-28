#include <iostream>
#include <cstring>
#include <string>
using namespace std;

char s1[220] = {0};
char s2[220] = {0};
int answer[220][220] = {0};
int main()
{
	while(cin >> s1 >> s2)
	{
		memset(answer, 0, sizeof(answer));
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		for(int i = 1; i <= len1; ++i)
		{
			for(int j =1; j <= len2; ++j)
			{
				if(s1[i - 1] == s2[j - 1]) answer[i][j] = answer[i - 1][j - 1] + 1;
				else
				{
					answer[i][j] = max(answer[i - 1][j], answer[i][j - 1]);
				}
	
			}
		}
		cout << answer[len1][len2] << endl;
	}
	return 0;
}
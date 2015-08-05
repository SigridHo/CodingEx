#include <iostream>
#include <cstring>
using namespace std;


void cal(char s[160], char s0[160], int n)
{
	if(n == 1) return;
	int l1 = strlen(s);
	int l2 = strlen(s0);
	int answer[160] = {0};
	for(int i = 0; i < l2; i++)
	{
		for(int j = 0; j < l1; j++)
		{
			answer[i + j] += (s0[i] - '0') * (s[j] - '0');
		}
	}
	for(int i = 0; i  < l1 + l2 + 1; i++)
	{
		if(answer[i] > 9)
		{
			answer[i + 1] += answer[i] / 10;
			answer[i] %= 10;
		}
	}
	if(answer[l1 + l2 - 1] == 0)
	{
		for(int i = 0; i < l1 + l2 - 1; i++)
		{
			s[i] = answer[i] + '0';
		}
	}
	else
	{
		for(int i = 0; i < l1 + l2; i++)
		{
			s[i] = answer[i] + '0';
		}
	}
	cal(s, s0, n - 1);
}
void standardlize(char s[160], int dig)
{
	int len = strlen(s);
	if(dig > len)
	{
		s[dig] = '.';
		for(int i = len; i <dig; i++)
			s[i] = '0';
	}
	if(dig == len)
		s[dig] = '.';
	if(dig < len)
	{
		for(int i = len; i > dig; i--)
			s[i] = s[i - 1];
		s[dig] = '.';
		int sum2 = 0;
		for(int i = len; i > dig; i--)
		{
			if(s[i] == '0') sum2++;
			else break;
		}
		s[len - sum2 + 1] = 0;
	}
	len = strlen(s);
	int sum1 = 0;
	for(int i = 0; i < dig; i++)
	{
		if(s[i] == '0') sum1++;
		else break;
	}
	for(int i = 0; i < len - sum1; i++)
		s[i] = s[i + sum1];
	s[len - sum1] = 0;
}

void standard(char s[160])
{
	int len = strlen(s);
	for(int i = len - 1; i > 0; i--)
	{
		if(s[i] == '0') s[i] = 0;
		else break;
	}
}

void reverse(char s[160])
{
	int len = strlen(s);
	char answer[160] = {0};
	for(int i = 0; i < len; i++)
	{
		answer[i] = s[len - i - 1];
	}
	if(answer[len - 1] == '.') answer[len - 1] = 0;
	strcpy(s, answer);
}
int main() {
	
	int n = 0;
	char s1[10] = {0};
	while(cin >> s1 >> n)
	{
		 int len = strlen(s1);
		 int dig = 0;
		 for(int i = len - 1; i >= 0; i--)
		 {
			 if(s1[i] != '.') dig++;
			 else break;
		 }
		 if(dig == 0)
		{
			
			s1[len - 1] = 0;
		 }
		 char s[160] = {0};
		 for(int i = 0; i < len; i++)
		 {
			s[i] = s1[len - 1 - i];
		 }
		 if(dig == len)
			 dig = 0;
		 
		 else
		 {
			 for(int i = dig; i < len - 1; i++)
			 {
				 s[i] = s[i + 1];
			 }
			 s[len - 1] = 0;
		 }
		 char s0[10] = {0};
		 strcpy(s0, s);
	     cal(s, s0, n);
		 if(dig != 0) standardlize(s, dig * n);
		 else standard(s);
		 reverse(s);
		 len = strlen(s);
		 if(len == 0) cout << '0' << endl;
		 else
			 cout << s << endl;
		 len = strlen(s);
		 for(int i = 0; i < len; i++)
			 s[i] = 0;
		 for(int i = 0; i < 10; i++)
			 s0[i] = 0;
		 len = strlen(s1);
		 for(int i = 0; i < len; i++)
			 s1[i] = 0;
	}
	return 0;
}
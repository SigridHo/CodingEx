#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int pos1[10] = {1, 0, 1, 1, 0, 1, 1, 1, 1, 1};
int pos2[10] = {1, 0, 0, 0, 1, 1, 1, 0, 1, 1};
int pos3[10] = {1, 1, 1, 1, 1, 0, 0, 1, 1, 1};
int pos4[10] = {0, 0, 1, 1, 1, 1, 1, 0, 1, 1};
int pos5[10] = {1, 0, 1, 0, 0, 0, 1, 0, 1, 0};
int pos6[10] = {1, 1, 0, 1, 1, 1, 1, 1, 1, 1};
int pos7[10] = {1, 0, 1, 1, 0, 1, 1, 0, 1, 1};

int main()
{
	int s;
	char n[10] = {0};
	while(1) 
	{
		int num[10] = {0};
		cin >> s >> n;
		if(s == 0 && strcmp(n, "0") == 0) break;
		int dig = strlen(n);
		for(int i = 0; i < dig; ++i)
			num[i] = n[i] - '0';
		for(int i = 0; i < dig; ++i)
		{
			cout << ' ';
			for(int j = 0; j < s; ++j)
			{
				if(pos1[num[i]] == 1) cout << '-';
				else cout << ' ';
			}
			cout << ' ';
			if(i != dig - 1) cout << ' ';
			else cout << endl;

		}
		for(int i = 0; i < s; ++i)
		{
			for(int j = 0; j < dig; ++j)
			{
				if(pos2[num[j]] == 1) cout << '|';
				else cout << ' ';
				for(int k = 0; k < s; ++k)
					cout << ' ';
				if(pos3[num[j]] == 1) cout << '|';
				else cout << ' ';
				if(j != dig - 1) cout << ' ';
				else cout << endl;
			}
			
		}
		for(int i = 0; i < dig; ++i)
		{
			cout << ' ';
			for(int j = 0; j < s; ++j)
			{
				if(pos4[num[i]] == 1) cout << '-';
				else cout << ' ';
			}
			cout << ' ';
			if(i != dig - 1) cout << ' ';
			else cout << endl;

		}
		for(int i = 0; i < s; ++i)
		{
			for(int j = 0; j < dig; ++j)
			{
				if(pos5[num[j]] == 1) cout << '|';
				else cout << ' ';
				for(int k = 0; k < s; ++k)
					cout << ' ';
				if(pos6[num[j]] == 1) cout << '|';
				else cout << ' ';
				if(j != dig - 1) cout << ' ';
				else cout << endl;
			}
			
		}
		for(int i = 0; i < dig; ++i)
		{
			cout << ' ';
			for(int j = 0; j < s; ++j)
			{
				if(pos7[num[i]] == 1) cout << '-';
				else cout << ' ';
			}
			cout << ' ';
			if(i != dig - 1) cout << ' ';
			else cout << endl;

		}
		cout << endl;
	}
}
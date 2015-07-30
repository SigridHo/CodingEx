#include <iostream>
#include <cstring>
#include <string>
using namespace std;

char num[30] = {0};
int number[10] = {0};
int seq[10] = {0};
int sample[10] = {0};
bool che(int i)
{
	if(i == 8)
	{
		if(number[i] % 3 == 0) return che(9);
		else return false;
	}
	if(i == 9)
	{
		if(number[i] % 3 == 0) return true;
		else return false;
	}
	if(number[i] % 3 == 0) return che(i + 1);
	else
	{
		if(number[i + 1] < (number[i] % 3) || number[i + 2] < (number[i] % 3)) return false;
		else 
		{
			number[i + 1] -= (number[i] % 3);
			number[i + 2] -= (number[i] % 3);
			return che(i  + 1);
		}
	}
	
}
int main()
{
	while(1)
	{
		memset(num, 0, sizeof(num));
		memset(seq, 0, sizeof(seq));
		memset(sample, 0 , sizeof(sample));
		memset(number, 0, sizeof(number));
		cin.getline(num, 40); 
		int len = strlen(num);
		if(len == 1 && num[0] == '0') break;
		int total = 0;
		for(int i = 0; i < len; ++i)
		{
			if(num[i] != ' ')
			{
				number[num[i] - '0']++;
				seq[total] = num[i] - '0';
				total++;
			}
		}
		for(int i = 1; i <= 9; ++i)
			sample[i] = number[i];
		if(total % 3 != 2) 
		{
			cout << "XIANGGONG" << endl;
		}
		else
		{
			if(total == 2)
			{
				if(seq[0] == seq[1]) cout << "HU" << endl;
				else cout << "BUHU" << endl;
			}
			else
			{
				bool findout = false;
				for(int i = 1; i <= 9; ++i)
				{
					if(number[i] >= 2)
					{
						number[i] -= 2;
						if(che(1))
						{
							cout << "HU" << endl;
							findout = true;
							break;
						}
						for(int i = 1; i <= 9; ++i)
							number[i] = sample[i];
					}
				}
				
				if(!findout) cout << "BUHU" << endl;
			}
		}


	}
	return 0;
}

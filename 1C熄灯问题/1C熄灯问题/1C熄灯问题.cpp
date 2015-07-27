#include <iostream>
#include <cstring>
using namespace std;

int status[7][8] = {0};
int firstline[8] = {0};
int switches[7][8] = {0};

void setstatus(int i , int firstline[8])
{
	for(int j = 1; j <= 6; ++j)
	{
		firstline[j] = i % 2;
		i /= 2;
	}
}

bool chec()
{
	int tempstatus[7][8] = {0};
	for(int i = 1; i <= 5; ++i)
		for(int j = 1; j <= 6; ++j)
			tempstatus[i][j] = status[i][j];
	memset(switches, 0, sizeof(switches));
	for(int i = 1; i <= 6; ++i)
	{
		switches[1][i] = firstline[i];
	}

	for(int i = 1; i <= 5; ++i)
	{
		for(int j = 1; j <= 6; ++j)
		{
			if(firstline[j] == 1)
			{
				tempstatus[i][j] ^= 1;
				tempstatus[i][j - 1] ^= 1;
				tempstatus[i][j + 1] ^= 1;
				tempstatus[i + 1][j] ^= 1;
			}
		}
		for(int j = 1; j <= 6; ++j)
		{
			if(tempstatus[i][j] == 1)
			{
				firstline[j] = 1;
				switches[i + 1][j] = 1;
			}
			else firstline[j] = 0;
		}
	}
	for(int j = 1; j <= 6; ++j)
	{
		if(firstline[j] == 1) return false;
	}
	return true;
}

int main() 
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		for(int j  = 1; j <= 5; ++j)
			for(int k = 1 ; k <=  6; ++k)
				cin >> status[j][k];
		cout << "PUZZLE #" << i << endl;
		for(int i = 0; i  < 64; ++i)
		{
			setstatus(i, firstline);
			if(chec()) 
			{
				for(int j = 1; j <= 5; ++j)
				{
					for(int k  = 1; k < 6; ++k)
					{
						cout << switches[j][k] << ' ';
					}
					cout <<switches[j][6] << endl;
				}
				break;
			}
		}

	}
	return 0 ;
}
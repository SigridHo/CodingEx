#include <iostream>
#include <cmath>
using namespace std;

int prime[500000] = {0};
int count = 0;
bool checkprime(int num)
{
	bool check = true;
	int k = 0;
	k = sqrt((double)num);
	if(k < 3) return true;
	for(int i = 3; i <= k; i = i + 2)
	{
		if(num % i == 0)
		{
			check = false;
			break;
		}
	}
	return check;
}
void creatprime()
{
	for(int i = 3; i < 1000000; i = i + 2)
	{
		if(checkprime(i))
		{
			prime[count] = i;
			count++;
		}
	}
}
int main() {
	creatprime();
	while(1)
	{
		int number;
		cin >> number;
		if(number == 0) break;
		bool che = false;
		int i = 0, di = 0, num = 0;
		for(i = 3; i < number; di++)
		{
			i = prime[di];
			num = number - i;
			for(int j = 0; j < count; j++)
			{
				if(num == prime[j])
				{
					che = true;
					break;
				}
				if(prime[j] > num)
					break;
			}
			if(che)
			{
				cout << number << " = " << i << " + " << num << endl;
				break;
			}
		}
		if(!che)
		{
			cout << "Goldbach's conjecture is wrong." << endl;
		}
	}
	return 0;
}
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

int main() {

	while(1)
	{
		int number;
		cin >> number;
		if(number % 2 != 0 || number < 6) break;
		bool che = false;
		int i = 0, di = 0, num = 0;
		for(i = 3; i < number; i = i + 2)
		{
			num = number - i;
			if(checkprime(i) && checkprime(num))
			{
					che = true;
					break;
			}
		}
		if(!che)
		{
			cout << "Goldbach's conjecture is wrong." << endl;
		}
		else
		{
			cout << number << " = " << i << " + " << num << endl;
		}
	}
	return 0;
}
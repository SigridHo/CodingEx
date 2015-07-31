#include <iostream>
using namespace std;

int bomb[30] = {0};
int k;
int count(int limit, int number)
{
	if(number == k - 1)
	{
		if(bomb[number] <= limit)
			return 1;
		else return 0;
	}
	if(bomb[number] > limit) return count(limit, number + 1);
	else
	{
		int temp1 = count(limit, number + 1);
		int temp2 = count(bomb[number], number + 1) + 1;
		if(temp1 > temp2) return temp1;
		else return temp2;
	}
}
int main()
{
	cin >> k;
	for(int i = 0; i < k; ++i)
		cin >> bomb[i];
	int total = count(100000, 0);
	cout << total << endl;
	system("pause");
	return 0;
}
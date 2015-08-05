#include <iostream>
using namespace std;

int cal(int k, int step)
{
	if(k == 1) return step + 1;
	if(k % 2 == 0)
		return cal(k / 2, step + 1);
	else return cal(3 * k + 1, step + 1);

}
int main() {
	int i = 0, j = 0;
	while(cin >> i >> j)
	{
		cout << i << ' ' << j << ' ';
		int max = 0, temp = 0;
		if(i < j)
		{
			for(int k = i; k <= j; k++)
			{
				temp = cal(k, 0);
				if(temp > max) max = temp;
			}
		}
		else
		{
			for(int k = j; k <= i; k++)
			{
				temp = cal(k, 0);
				if(temp > max) max = temp;
			}
		}
		cout << max << endl;
	}
	return 0;
}
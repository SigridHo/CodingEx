#include <iostream>
using namespace std;

int a[110] = {0};
int b[110] = {0};
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i< n; ++i)
	{
		int times,ta,tb;
		cin >> times >> ta >> tb;
		for(int j = 0; j < ta; ++j)
			cin >> a[j];
		for(int j = 0; j< tb; ++j)
			cin >> b[j];
		int sum = 0;
		for(int i = 0; i < times; ++i)
		{
			if((a[i % ta] == 0 && b[i % tb] == 2) || (a[i % ta] == 2 && b[i % tb] == 5) || (a[i % ta] == 5 && b[i % tb] == 0)) sum++;
			if((a[i % ta] == 0 && b[i % tb] == 5) || (a[i % ta] == 2 && b[i % tb] == 0) || (a[i % ta] == 5 && b[i % tb] == 2)) sum--;
		}
		if(sum > 0) cout << "A" << endl;
		if(sum == 0) cout << "draw" << endl;
		if(sum < 0) cout << "B" << endl;
	}
	return 0;
}
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

multiset<int,greater<int> > cow;
int main()
{
	
	int n, b;
	cin >> n >> b;
	int  temp;
	for(int i = 0; i < n; ++i)
	{
		cin >> temp;
		cow.insert(temp);
	}
	long long sum = 0;
	multiset<int, greater<int> >::iterator it;
	it = cow.begin();
	int step = 0;
	while(sum < b)
	{
		sum += *it;
		it++;
		step++;
	}
	cout << step << endl;
	system("pause");
	return 0;
}
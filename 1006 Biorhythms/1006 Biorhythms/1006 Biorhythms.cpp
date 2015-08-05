#include <iostream>
using namespace std;

int main() {
	int p = 0, e = 0, i = 0, d = 0;
	for(int j = 1; ; j++)
	{
		cin >> p >> e >> i >> d;
		if(p == -1 && e == -1 && i == -1 && d == -1)
		     break;
		int day = 0;
		int diff = 0;
		p = p % 23;
		e = e % 28;
		i = i % 33;
		for(day = d + 1; ; day++)
		{
			if(day % 33 == i && day % 23 == p && day % 28 == e)
			{
				diff = day - d;
				break;
			}
		}
		cout << "Case " << j << ": the next triple peak occurs in " << diff << " days." << endl;
	}
	return 0;
}
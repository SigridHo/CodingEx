#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	int k, la, lb, ia, ib, fa, fb;
	cin >> k >> la >> lb >> ia >> ib >> fa >> fb;
	int time = fa;
	int pos = la + fa;
	bool findout = false;
	for(int i = 0; i < 100000; ++i)
	{
		if((((time % ib) + ib ) % ib) == (((fb % ib) + ib) % ib))
		{
			if((((pos % k) + k) % k) ==((((lb - time) % k) + k) % k))
			{
				findout = true;
				cout << time << endl;
				break;
			}
		}
		time += ia;
		pos = (pos + ia) % k;
	}
	if(!findout) cout << "no answer" << endl;
	system("pause");
	return 0;
}
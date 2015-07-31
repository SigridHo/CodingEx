#include <iostream>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

static bool check[100000000] = {0};
class A
{
	multiset<int> MSET;
public:
	void add(int x)
	{
		MSET.insert(x);
		cout << MSET.count(x) << endl;
	}
	void del(int x)
	{
		if(MSET.count(x) != 0)
			cout << MSET.erase(x) << endl;
		else cout << '0' << endl;
	}
	void ask(int x)
	{
		cout << MSET.count(x) << endl;
	}
};

int main() {
	A MYSET;
	int n;
	cin >> n;
	string cmd;
	int x;
	for(int i = 0; i < n; ++i)
	{
		cin >> cmd;
		if(cmd == "add")
		{
			cin >> x;
			if(!check[x]) check[x] = true;
			MYSET.add(x);
		}
		if(cmd == "del")
		{
			cin >> x;
			MYSET.del(x);
		}
		if(cmd == "ask")
		{
			cin >> x;
			cout << (int)check[x] << ' ';
			MYSET.ask(x);
		}
	}
	system("pause");
	return 0;
}
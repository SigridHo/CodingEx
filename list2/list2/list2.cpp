#include <iostream>
#include <list>
#include <string>;
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int id1 = 0, id2 = 0, num = 0;
	string cmd;
	list<int>* pl[10005] = {0};
	for(int i = 0; i < n; ++i)
	{
		cin >> cmd;
		if(cmd == "new")
		{
			cin >> id1;
			delete pl[id1];
			pl[id1] = new list<int>;
		}
		if(cmd == "add")
		{
			cin >> id1 >> num;
			list<int>::iterator i;
			i = pl[id1]->begin();
			while((i != pl[id1]->end()) && ((*i) < num))++i;
			pl[id1]->insert(i, num);
		}
		if(cmd == "merge")
		{
			cin >> id1 >> id2;
			if(id1 != id2)
				pl[id1]->merge(*pl[id2]);
		}
		if(cmd == "unique")
		{
			cin >> id1;
			pl[id1]->unique();
		}
		if(cmd == "out")
		{
			cin >> id1;
			list<int>::const_iterator i;
			if(pl[id1]->begin() == pl[id1]->end()) cout << endl;
			else
			{
				for(i = pl[id1]->begin(); i != pl[id1]->end(); ++i)
				{
					cout << *i << ' ';
				}
				cout << endl;
			}
		}
	}
	for (int i = 0; i < 10000; ++i) delete pl[i];
	return 0;
}

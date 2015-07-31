#include <iostream>
#include <list>
#include <cstring>
#include <algorithm>
using namespace std;

class A
{
public:
	list<int> num;
	int id;
	A(int temp = 0):id(temp){};
	void out();
};

void A::out() {
	num.sort();
	if(num.begin() == num.end()) {
		cout << endl; 
		return;
	}
	list<int>::const_iterator i;
	for(i = num.begin(); i != num.end(); ++i)
	{
		cout << *i << ' ';
	}
	cout << endl;
	return;
}
int main() {
	int n;
	cin >> n;
	A* pa[1000];
	char SConductor[10] = {0};
	int count = 0;
	for(int i = 0; i != n; ++i)
	{
		cin >> SConductor;
		if(strcmp(SConductor,"new") == 0)
		{
			int temp;
			cin >> temp;
			pa[count] = new A(temp);
			count++;
		}
		if(strcmp(SConductor, "add") == 0)
		{
			int temp1, temp2;
			cin >> temp1 >> temp2;
			for(int j = 0; j <= count; ++j)
			{
				if(pa[j]->id == temp1)
				{
					(pa[j]->num).push_back(temp2);
					break;
				}
			}
		}
		if(strcmp(SConductor, "merge") == 0)
		{
			int temp1, temp2;
			cin >> temp1 >> temp2;
			int t1 = 0, t2 = 0;
			for(int j = 0; j <= count; ++j)
			{
				if(pa[j]->id == temp1)
				{
					t1 = j;
					for(int k = j + 1; k <= count; ++ k)
					{
						if(pa[k]->id == temp2)
						{
							t2 = k;
							break;
						}
					}
					break;
				}
				if(pa[j]->id == temp2)
				{
					t2 = j;
					for(int k = j + 1; k <= count; ++ k)
					{
						if(pa[k]->id == temp1)
						{
							t1 = k;
							break;
						}
					}
					break;
				}
			}
			pa[t1]->num.merge(pa[t2]->num);
		}
		if(strcmp(SConductor, "unique") == 0)
		{
			int temp1;
			cin >> temp1;
			for(int j = 0; j <= count; j++)
			{
				if(pa[j]->id == temp1)
				{
					pa[j]->num.sort();
					pa[j]->num.unique();
					break;
				}
			}
		}
		if(strcmp(SConductor, "out") == 0)
		{
			int temp1;
			cin >> temp1;
			for(int j = 0; j <= count; ++j)
			{
				if(pa[j]->id == temp1)
				{
					pa[j]->out();
					break;
				}
			}
		}
	}
	
	system("pause");
	delete []pa;
	return 0;
}
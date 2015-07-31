#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

typedef multimap<int, int> MAP;
int main() {
	MAP mp;
	int n;
	scanf("%d", &n);
	int power, id;
	MAP::iterator ite;
	ite = mp.begin();
	mp.insert(map<int, int>::value_type(1000000000, 1));
	for(int i = 0; i < n; ++i)
	{
		scanf("%d%d",&id, &power);
		printf("%d ", id);
		ite = mp. insert(map<int, int>::value_type(power, id));
		int gap1 = 0;
		if(ite != mp.begin())
		{
		    gap1 = (*ite).first - (*(--ite)).first;
			ite++;
			int gap2 = 0;
			if(ite != (--mp.end()))
			{
				int a = (++ite)->first;
				ite--;
				int b = (ite)->first;
				gap2 = a - b;
				if(gap2 < gap1)
				{
					printf("%d\n", (++ite)->second);
					ite--;
				}
				else 
				{
					printf("%d\n", (*(--ite)).second);
					ite++;
				}
			}
			else 
			{
				printf("%d\n", (*(--ite)).second);
				ite++;
			}
		}
		else 
		{	
			printf("%d\n", (*(++ite)).second);
			ite--;
		}
	}
	
	return 0;
}
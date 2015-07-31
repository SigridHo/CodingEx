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
		MAP::iterator storite = ite;
		int gap1 = 1000000000;
		int gap2 = 1000000000;
		int idmin1 = 0;
		int idmin2 = 0;
		int pow = (*ite).first;
		if(ite != mp.begin())
		{
			gap1 = pow - (*(--ite)).first;
			idmin1 = (*ite).second;
			MAP::iterator ite2;
			ite2 = ite;
			int temgap = 0;
			for( ; ite2 != (--mp.begin()); --ite2)
			{
				temgap = pow - (*ite2).first;
				if(temgap == gap1)
				{
					if((*ite2).second < idmin1)
						idmin1 = (*ite2).second;
				}
				else break;
			}
		}
		ite = storite;
		if(ite != (--mp.end()))
		{

			gap2 = (*(++ite)).first - pow;
			idmin2 = (*ite).second;
			MAP::iterator ite3;
			ite3 = ite;
			int temgap = 0;
			for( ; ite3 != mp.end(); ++ite3)
			{
				temgap = (*ite3).first - pow;
				if(temgap == gap2)
				{
					if((*ite3).second < idmin2)
						idmin2 = (*ite3).second;
				}
				else break;
			}
		}
		if(gap1 < gap2)
			printf("%d\n", idmin1);
		else if(gap1 > gap2)
			printf("%d\n", idmin2);
		else
		{
			if(idmin1 < idmin2)
				printf("%d\n", idmin1);
			else printf("%d\n", idmin2);
		}
	}
	system("pause");
	return 0;
}
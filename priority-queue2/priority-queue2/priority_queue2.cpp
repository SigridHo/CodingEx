#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <set>
using namespace std;




set<int> iset;
bool flag = true;
void FindZYS(unsigned int m) {
    for (unsigned int i = 2; i <= m; ++i)
    {
        if ((m % i == 0) && (flag == true))
        {
            iset.insert(i);
            unsigned int n = m / i;    
            FindZYS(n);
            return;
        } 
    }
}
 int sep(int n)
{
	iset.clear();
	flag = true;
	FindZYS(n);
	iset.erase(n);
	return(iset.size());
}



struct mygreater
{
	bool operator()(const int&a, const int& b)
	{
		int t1 = sep(a);
		int t2 = sep(b);
		if(t1 > t2)
			return true;
		else if(t1 == t2)
		{
			if(a > b) return true;
			if(a < b) return false;
		}
		else return false;
	}
};

struct mylesser
{
	bool operator()(const int&a, const int& b)
	{
		int t1 = sep(a);
		int t2 = sep(b);
		if(t1 < t2)
			return true;
		else if(t1 == t2)
		{
			if(a < b) return true;
			if(a > b) return false;
		}
		else return false;
	}

};



int main() {
	multiset<int, mygreater> ms;
	int n;
	scanf("%d", &n);
	int x = 0;
	for(int i = 0; i < n; ++ i)
	{
		for(int j = 0; j < 10; ++j)
		{
			scanf("%d", &x);

			ms.insert(x);
			cout << x << ' '<< sep(x) << endl;
		}
		printf("%d %d\n", *ms.begin(), *(--ms.end()));
		ms.erase(ms.begin());
		ms.erase(--ms.end());

	}
	system("pause");
	return 0;
}
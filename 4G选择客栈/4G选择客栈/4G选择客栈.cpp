#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <vector>
using namespace std;

struct hotel
{
	int color;
	int number;
};
bool operator < (hotel a1, hotel a2)
{
	if(a1.color != a2.color ) return (a1.color < a2.color);
	else
		return(a1.number < a2.number);
}
vector <int> coffee;
vector <int> choices;
multiset<hotel> lijiang;
int main()
{
	int n, k, p;
	scanf("%d%d%d", &n , &k, &p);
	int tem1, tem2;
	hotel temp;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &tem1, &tem2);
		temp.color = tem1;
		temp.number = i;
		if(tem2 <= p) coffee.push_back(i);
		lijiang.insert(temp);
	}
	vector<int>::iterator it1;
	for(it1 = coffee.begin(); it1 != coffee.end(); ++it1)
	{
		if(it1 == coffee.begin())
		{
			for(int j = 0; j <= *it1; ++j)
			{
				choices.push_back(*it1);
			}
		}
		else
		{
			for(int j = *(it1 - 1) + 1; j <= *it1; ++j)
			{
				choices.push_back(*it1);
			}
		}

	}
	multiset<hotel>::iterator it2;
	multiset<hotel>::iterator it3;
	int cal = 0;
	for(it2 = lijiang.begin(); it2 != lijiang.end();it2++)
	{
		if((*it2).number <= *(coffee.end() - 1))
		{
			for(it3 = (++it2), it2--; it3 != lijiang.end(); it3++)
			{
				if((*it2).color == (*it3).color)
				{
					if((*it3).number >= choices[(*it2).number]) cal++;
					else continue;
				}
				else break;
			}
		}
		else
			break;
	}
	printf("%d\n", cal);
	system("pause");
	return 0;
}
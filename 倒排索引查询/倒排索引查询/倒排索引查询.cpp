#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <map>
#include <set>
using namespace std;

map <int, int> remap;
map <int, int> mymap;
#define MaxN 1000010
bitset <MaxN> Archi[1005];
int IDSum = 0;
bitset <MaxN> Words;

int main()
{
	int n = 0;
	int Doc_sum = 0;
	int ID = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &Doc_sum);
		for(int j  = 0; j < Doc_sum; ++j)
		{
			scanf("%d", &ID);
			int tmp = remap[ID];
			if(tmp == 0)
			{
				++IDSum;
				mymap[IDSum] = ID;
				remap[ID] = IDSum;
				tmp = IDSum;
			}
			Archi[i + 1][tmp] = 1;
		}
	}
	int m = 0;
	int state = 0;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		bool First = true;
		bool Find = false;
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &state);
			if (state == 1)/*该单词需要存在*/
			{
				if (First)
				{
					Words = Archi[j + 1];
					First = false;
				}
				else Words &= Archi[j + 1];
			}
			else if (state == -1)
			{
				if (First)
				{
					Words = ~Archi[j + 1];
					First = false;
				}
				else Words &= ~Archi[j + 1];
			}
		}


		if (Words.none())
		{
			printf("NOT FOUND\n");
			continue;
		}

		First = true;
		set <int> set_tmp;
		for (int j = 1; j <= IDSum; ++j)
		{
			if (Words[j])
				set_tmp.insert(mymap[j]);
		}
		set <int> :: iterator setp = set_tmp.begin();
		while (setp != set_tmp.end())
		{
			if (!First)
				printf(" ");
			First = false;
			printf("%d", *setp);
			setp++;
		}
		printf("\n");
	}
	return 0;
}


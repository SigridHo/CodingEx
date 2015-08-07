#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

struct Node
{
	char str[20];
	int val;
	Node(char a[20] = "", int v = 0)
	{
		if(a[0] != 0)
			strcpy(str, a);
		else str[0] = 0;
		val = v;
	}
};
Node table[40] = {Node("negative", -1), Node("zero", 0), Node("one", 1), Node("two", 2), Node("three", 3), Node("four", 4), Node("five", 5), Node("six", 6), Node("seven", 7), Node("eight", 8), Node("nine", 9), Node("ten", 10), Node("eleven", 11), Node("twelve",12), Node( "thirteen", 13), Node("fourteen", 14), Node("fifteen",15), Node("sixteen",16), Node("seventeen",17), Node("eighteen", 18), Node("nineteen", 19), Node("twenty",20), Node("thirty",30), Node("forty", 40), Node("fifty", 50), Node("sixty", 60), Node("seventy", 70), Node("eighty", 80), Node("ninety", 90), Node("hundred", 100), Node("thousand",1000), Node("million", 1000000)};
char num[200] = {0};
int transnum[100] = {0};
int main()
{
	while(cin.getline(num, 200))
	{
		char temp[20] = {0};
		memset(transnum, 0, sizeof(transnum));
		int j = 0;
                int len = strlen(num);
                if(len == 0) break;
		istringstream is (num);
		while(is >> temp)
		{
			for(int i = 0; i < 40; ++i)
			{
				if(strcmp(temp, table[i].str) == 0)
				{
					transnum[j] = table[i].val;
					j++;
					break;
				}
			}
		}
		int sum1 = 0;
		int sum2 = 0;
		int tsum = 0;
		bool negative = false;
		for(int k = 0; k < j; ++k)
		{
			if(transnum[k] == -1)
				negative = true;
			else if(transnum[k] == 1000000)
			{
				sum1 = tsum * 1000000;
				tsum = 0;
			}
			else if(transnum[k] == 1000)
			{
				sum2 = tsum * 1000;
				tsum = 0;
			}
			else if(transnum[k] == 100)
			{
				tsum *= 100;
			}
			else
			{
				tsum += transnum[k];
			}
		}
		int sum = sum1 + sum2 + tsum;
		if(negative) sum *= -1;
		printf("%d\n", sum);
	}
	return 0;
}
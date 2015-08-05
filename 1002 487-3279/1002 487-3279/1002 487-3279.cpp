#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

struct sam
{
	char number[20];
	int time;
};

char Phone_Number[100000][20] = {0};
char change[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', '7', '7', '7', '8', '8', '8', '9', '9', '9', '9'};
sam times[100000] = {0};

void standardize(int number)
{
	char ans[20] = {0};
	int len = strlen(Phone_Number[number]);
	int dig = 0;
	for(int i = 0; i < len; i++)
	{
		if(Phone_Number[number][i] >= 'A' && Phone_Number[number][i] <= 'Z')
		{
			ans[dig] = change[Phone_Number[number][i] - 'A'];
			dig++;
			if(dig == 3)
			{
				ans[dig] = '-';
				dig++;
			}
		}
		else if(Phone_Number[number][i] >= '0' && Phone_Number[number][i] <= '9')
		{
			ans[dig] = Phone_Number[number][i];
			dig++;
			if(dig == 3)
			{
				ans[dig] = '-';
				dig++;
			}
		}

	}
	strcpy(Phone_Number[number], ans);
}

void order(int n)
{
	char temp[20] = {0};
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
		{
			if(strcmp(Phone_Number[i], Phone_Number[j]) > 0)
			{
				strcpy(temp, Phone_Number[i]);
				strcpy(Phone_Number[i], Phone_Number[j]);
				strcpy(Phone_Number[j], temp);
			}
		}
}
int compare(const void *a,const void *b)
{
    return (strcmp((char *)a,(char *)b));
}
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> Phone_Number[i];
		standardize(i);
	}
	qsort(Phone_Number, n, sizeof(Phone_Number[0]), compare);
	int count = 0;
	bool same = false;
	strcpy(times[0].number, Phone_Number[0]);
	for(int i = 1; i < n; i++)
	{
		if(strcmp(Phone_Number[i], Phone_Number[i - 1]) == 0)
		{
			if(!same) same = true;
			times[count].time++;
		}
		else
		{
		    count++;
			strcpy(times[count].number, Phone_Number[i]);
		}
	}
	if(!same)
		cout << "No duplicates." << endl;
	else
	{
		for(int i = 0 ; i <= count; i++)
		{
			if(times[i].time > 0)
			{
				cout << times[i].number << ' ' << times[i].time + 1 << endl;
			}
		}
	}
	system("pause");
	return 0;
}
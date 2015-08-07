#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int getorder(char* src, int n)
{
	char arr[60] = {0};
	strcpy(arr, src);
	int count = 0;
	for(int i = 1; i < n; ++i)
	{
		char temp = arr[i];
		int j = i - 1;
		while(j >= 0&& temp < arr[j])
		{
			arr[j + 1] = arr[j];
			count++;
			j--;
		}
		arr[j + 1] = temp;
	}
	return count;
}
class DNA
{
public :
	char seq[60];
	int ordernumber;
	DNA operator = (DNA a)
	{
		strcpy(seq, a.seq);
		ordernumber = a.ordernumber;
		return *this;
	}
	DNA()
	{
		seq[0] = '\0';
		ordernumber = 0;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	DNA* arr = new DNA[m];
	for(int i = 0 ; i < m; ++i)
	{
		cin >> arr[i].seq;
		arr[i].ordernumber = getorder(arr[i].seq, n);
	}
	for(int i = 0; i < m - 1; ++i)
	{
		for(int j = m - 1; j > i; --j)
		{
			if(arr[j].ordernumber < arr[j - 1].ordernumber)
			{
				DNA temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
	for(int i  = 0; i < m; ++i)
		cout << arr[i].seq << endl;
	system("pause");
	return 0;
}
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
char arr[10000][260] = {0};
long long sum = 0;
void addlength(int n)
{
	int max = 0;
	int temp = 0;
	int j = 0;
	while(arr[n - 1][j] == arr[n][j])
	{
		temp++;
		j++;
		if(j >= strlen(arr[n - 1]) || j >= strlen(arr[n]) ) break;
	}
	if(temp > max) max = temp;
	sum = sum + 1 + strlen(arr[n]) - max;
}
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> arr[i];
	
	sum += strlen(arr[0]);
	if(n > 1) 
	{
		for(int i = 1; i < n; ++i)
		{
			addlength(i);
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}
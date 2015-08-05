#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char s1[200] = {0};
	char s2[200] = {0};
	cin >> s1 >> s2;
	int arr1[27] = {0};
	int arr2[27] = {0};

	int len = strlen(s1);
	for(int i = 0; i < len; i++)
	{
		arr1[s1[i] - 'A']++;
		arr2[s2[i] - 'A' ]++;

	}
	int temp = 0;
	for(int i = 0; i < 26 - 1; i++)
		for(int j =  i + 1; j < 26; j++)
		{
			if(arr1[i] > arr1[j])
			{
				temp = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = temp;
			}
			if(arr2[i] > arr2[j])
			{
				temp = arr2[i];
				arr2[i] = arr2[j];
				arr2[j] = temp;
			}
		}
	bool check = true;
	for(int i = 0; i < 27; i++)
	{
		if(arr1[i] != arr2[i])
		{
			check = false;
			break;
		}
	}
	
	if(check) cout << "YES" << endl;
	else cout << "NO" << endl;
	system("pause");
	return 0;
}
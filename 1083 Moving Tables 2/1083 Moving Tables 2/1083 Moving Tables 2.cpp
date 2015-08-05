#include <iostream>
using namespace std;

struct table
{
	int s;
	int t;
};

int main() {
	int T = 0;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int N = 0;
		cin >> N;
		int sum = 0;
		table arr[220] = {0};
		int temp = 0;
		int corridor[220] = {0};
		for(int j = 0; j < N; j++)
		{
			cin >> arr[j].s >> arr[j].t;
			if(arr[j].s > arr[j].t)
			{
				temp = arr[j].s;
				arr[j].s = arr[j].t;
				arr[j].t = temp;
			}
			arr[j].s = (arr[j].s - 1) / 2;
			arr[j].t = (arr[j].t - 1) / 2;
			for(int k = arr[j].s; k <= arr[j].t; k++)
			{
				corridor[k]++;
			}
		}
		sum = corridor[0];
		for(int j = 0; j < 202; j++)
		{
			if(sum < corridor[j])
				sum = corridor[j];
		}
		sum *= 10;
		cout << sum << endl;
	}
	system("pause");
	return 0;
}
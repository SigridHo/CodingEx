#include <iostream>
using namespace std;

struct table
{
	bool check;
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
		for(int j = 0; j < N; j++)
		{
			cin >> arr[j].s >> arr[j].t;
			if(arr[j].s > arr[j].t)
			{
				temp = arr[j].s;
				arr[j].s = arr[j].t;
				arr[j].t = temp;
			}
		}
		for(int j = 0; j < N; j++)
		{
			if(j == N - 1 && !arr[j].check) sum++;
			else
			{
				if(!arr[j].check)
				{
					sum++;
				    for(int k = j + 1; k < N; k++)
				    {
						if(arr[j].t % 2 == 0)
						{
							if(arr[k].s > arr[j].t) arr[k].check = true;
						}
						else
						{
							if(arr[k].s > arr[j].t + 1) arr[k].check = true;
						}
					}
				}
			}
		}
		sum *= 10;
		cout << sum << endl;
	}
	system("pause");
	return 0;
}
#include <iostream>
using namespace std;

int main() {
	while(1)
	{
		int n;
		cin >> n;
		if(n == 0) break;
		int num[70] = {0};
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> num[i];
			sum += num[i];
		}
		for(int i = 0; i < n - 1; i++)
			for(int j = i + 1; j < n; j++)
			{
				if(num[i] < num[j])
				{
					int temp = num[i];
					num[i] = num[j];
					num[j] = temp;
				}
			}
		for(int i = 1; i <= sum; i++)
		{
			if(sum % i == 0)
			{
				bool check = true;
				if(i < num[0]) check = false;
				int arr[70] = {0};
				if(check)
				{
					int tem = i;
				    for(int j = 0; j < n; j++)
				    {
						if(arr[j] == 0){
							arr[j] = 1;
							tem -= num[j];
							if(tem == 0) continue;
							if(tem < num[n - 1])
							{
								check = false;
								break;
							}
							while(tem != i) {
							for(int k = n - 1; k >= 0; k--)
							{
								if(arr[k] == 0 && tem == num[k])
								{
									tem = i;
									arr[k] = 1;
									break;
								}
								if(arr[k] == 0 && tem < num[k])
								{
									break;
								}
							}
							if(tem != i)
							{
								for(int k0 = n - 1; k0 >= 0; k0--)
								{
									if(arr[k0] == 0 )
									{
										if(tem < arr[k0])
										{
											check = false;
											break;
										}
										else
										{
											arr[k0] = 1;
											tem -= num[k0];
										}
									}
								}
							}
							}
						}
					}
				}
				if(check)
				{
					cout << i << endl;
					break;
				}
			}
		}
	}
	return 0;
}
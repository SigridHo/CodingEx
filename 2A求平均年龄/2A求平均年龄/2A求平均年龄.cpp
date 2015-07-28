#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	double sum = 0;
	int n;
	scanf("%d", &n);
	int temp;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &temp);
		sum += temp;
	}
	sum /= n;
	printf("%.2lf\n", sum);
	system("pause");
	return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
#define maxl 100000000
int n = 0, L = 0, A = 0, B = 0, pRead = 0, pWrite = 0;
int cowrange[maxl] = {0};
int f[maxl] = {0};
int qstate[maxl] = {0};
int main()
{
	int i = 0, s = 0, e = 0, cows = 0;
	scanf("%d%d%d%d", &n , &L, & A, &B);
	A = A + A;
	B = B + B;
	for(i = 0; i <= L; ++i)
	{
		f[i] = maxl;
		cowrange[i] = 0;
	}
	for(i = 0; i < n; ++i)
	{
		scanf("%d%d", &s, &e);
		cowrange[s + 1]++;
		cowrange[e]--;
	}
	f[0] = 0;
	for(i = 2; i <= L; i += 2)
	{
		cows = cows + cowrange[i] + cowrange[i - 1];
		if(i < A) continue;
		while((pRead < pWrite) && (qstate[pRead] < i - B)) pRead++;
		while((pRead < pWrite) && (f[qstate[pWrite - 1]] >= f[i - A])) pWrite--;
		qstate[pWrite++] = i - A;
		if((cows == 0) && (f[qstate[pRead]] != maxl)) f[i] = f[qstate[pRead]] + 1;
	}
	if(f[L] == maxl) f[L] = -1;
	printf("%d\n", f[L]);
	system("pause");
	return 0;
}

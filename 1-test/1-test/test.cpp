#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int m = 0, n = 0, i = 0;
	scanf("%x %x %d", &m, &n, &i);
	n = (n | ((~n >> 32 - i) << 32 - i)) & ((~((~n >> 32 - i) << 32 - i)) ^ (~0 >> 32 - i << 32 - i));
	printf("%x\n%x\n", m , n);
	getchar();system("pause");
	return 0;
}
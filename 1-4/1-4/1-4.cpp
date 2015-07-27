#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main(int argc, char* argv[]) {
	int Num1 = 0, Num2 = 0;
	Num1 = atoi(argv[1]);
	Num2 = atoi(argv[argc - 1]);
	int Sum = 0;
	Sum = Num1 + Num2;
	cout << Sum << endl;
	return 0;
}
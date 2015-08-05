#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double sum = 0;
	double month = 0;
	for(int i = 0; i < 12; i++)
	{
		cin >> month;
		sum += month;
	}
	sum /= 12;
	cout <<"$" << setprecision(2) << fixed << sum << endl;
	system("pause");
	return 0;
}
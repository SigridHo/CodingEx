#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i = 0 ; i < n; i++)
	{
		double x = 0, y = 0;
		cin >> x >> y;
		double r = 0;
		r = x * x + y * y;
		double s = 0;
		s = 3.14 * r / 2;
		int year = 0;
		year = s / 50 + 1;
		cout << "Property " << i + 1 << ": This property will begin eroding in year " << year << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	system("pause");
	return 0;
}
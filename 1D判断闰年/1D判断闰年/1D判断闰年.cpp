#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if((n % 4 != 0) || (n % 100 == 0 && n % 400 != 0) || (n % 3200 == 0)) cout << "N" << endl;
	else cout << "Y" << endl;
	system("pause");
	return 0;
}

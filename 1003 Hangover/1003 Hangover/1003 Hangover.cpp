#include <iostream> 
using namespace std;

int main() {
	double total = 0;
	while(1)
	{
		cin >> total;
		if(total == 0.00)
			break;
		double sum = 0;
		double i = 0;
		for(i = 2; i < 300; i++)
		{
			sum += 1 / i;
			if(sum >= total)
				break;
		}
		cout << i - 1 << " card(s)" << endl;
	}
	return 0;
}
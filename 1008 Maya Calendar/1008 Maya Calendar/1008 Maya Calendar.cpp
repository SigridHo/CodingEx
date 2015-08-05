#include <iostream>
#include <cstring>
using namespace std;

char hamo[19][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
char tzmo[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

struct haab
{
	int day;
	char month[10];
	int year;
};

int main() {
	int n;
	cin >> n;
	cout << n << endl;
	for(int i = 0; i < n; i++)
	{
		haab ha;
		char c;
		cin >> ha.day >> c >> ha.month >> ha.year;
		int sum = 0;
		int month = 0;
		for(int j = 0; j < 19; j++)
		{
			if(strcmp(ha.month, hamo[j]) == 0)
			{
				month = j;
				break;
			}
		}
		sum = ha.year * 365 + month * 20 + ha.day + 1;
		int d = 0, m =0, y = 0;
    	if(sum % 260 == 0)
		{
			y = sum / 260 - 1;
			m = 19;
			d = 13;
		}
		else 
		{
			y = sum / 260;
			sum %= 260;
			m = sum % 20 - 1;
			d = sum % 13;
			if(m == -1) m = 19;
			if(d == 0) d = 13;
		} 
		cout << d << ' ' << tzmo[m] << ' '<< y << endl;
	}
	system("pause");
	return 0;
}
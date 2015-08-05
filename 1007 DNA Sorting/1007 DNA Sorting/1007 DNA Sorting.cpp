#include <iostream>
using namespace std;

struct DNA
{
	char sequence[60];
	int ranker;
	int pairs;
};

int cal(char s[60], int len)
{
	int sum = 0;
	for(int i = 0; i < len - 1; i++)
		for(int j = i + 1; j < len; j++)
		{
			if(s[i] > s[j])
				sum++;
		}
	return sum;
}

int main() {
	int n, m;
	cin >> n >> m;
	DNA dna[110] = {0};
	for(int i = 0; i < m; i++)
	{
		cin >> dna[i].sequence;
		dna[i].ranker = i;
		dna[i].pairs = cal(dna[i].sequence, n);

	}
	DNA temp;
	for(int i = 0; i < m - 1; i++)
		for(int j = i + 1; j < m; j++)
		{
			if(dna[i].pairs > dna[j].pairs)
			{
				temp = dna[i];
				dna[i] = dna[j];
				dna[j] = temp;
			}
		}
	for(int i = 0; i < m - 1; i++)
		for(int j = i + 1; j < m; j++)
		{
			if(dna[i].pairs == dna[j].pairs && dna[i].ranker > dna[j].ranker)
			{
				temp = dna[i];
				dna[i] = dna[j];
				dna[j] = temp;
			}
		}
	for(int i = 0; i < m; i++)
		cout << dna[i].sequence << endl;
	system("pause");
	return 0;
}
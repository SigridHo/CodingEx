#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

map<int, int> D;

int sep(int n)
{
	if (D.find(n) != D.end()) return D[n];
	int k = 0, r = n;
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			++k;
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1 && n < r) ++k;
	return D[r] = k;
}

struct mygreater
{
	bool operator()(const int&a, const int& b)
	{
		int t1 = sep(a);
		int t2 = sep(b);
		if(t1 > t2)
			return true;
		else if(t1 == t2)
		{
			if(a > b) return true;
			if(a < b) return false;
		}
		else return false;
	}
};

struct mylesser
{
	bool operator()(const int&a, const int& b)
	{
		int t1 = sep(a);
		int t2 = sep(b);
		if(t1 < t2)
			return true;
		else if(t1 == t2)
		{
			if(a < b) return true;
			if(a > b) return false;
		}
		else return false;
	}

};



int main() {
	priority_queue<int, vector<int>, mygreater> pq1;
	priority_queue<int, vector<int>, mylesser> pq2;
	int n;
	scanf("%d", &n);
	int x = 0;
	for(int i = 0; i < n; ++ i)
	{
		for(int j = 0; j < 10; ++j)
		{
			scanf("%d", &x);

			pq1.push(x);
			pq2.push(x);

		}
		printf("%d %d\n", pq2.top(), pq1.top());
		pq1.pop();
		pq2.pop();

	}
	system("pause");
	return 0;
}
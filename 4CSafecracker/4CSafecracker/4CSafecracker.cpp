#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int num[28][7] = {0};
int main()
{
	for(int i = 1; i <= 26; ++i)
	{
		num[i][1] = i;
		num[i][2] = i * i;
		num[i][3] = num[i][2] * i;
		num[i][4] = num[i][3] * i;
		num[i][5] = num[i][4] * i;
	}


	while(1)
	{
		int n;
		cin >> n;
		char letter[15];
		cin >> letter;
		if(n == 0 && strcmp(letter, "END") == 0) break;
		int size = strlen(letter);
		for(int i = 0; i  < size - 1; ++i)
			for(int j = i + 1; j < size; ++j)
			{
				if(letter[i] < letter[j])
				{
					char temp = letter[i];
					letter[i] = letter[j];
					letter[j] = temp;
				}
			}
		int i , j , k , l , m;
		bool find = false;
		for(i = 0; i < size; ++i){			
			for(j = 0; j < size; ++j){
				if(j == i) continue;
				for(k = 0 ; k < size; ++k){
					if(k == i || k == j) continue;
					for(l = 0; l < size; ++l){
						if(l == i || l == j || l == k) continue;
						for(m = 0 ; m < size; ++m)
						{
							if(m == i || m == j || m == k || m == l) continue;
							if(num[letter[i] - 'A' + 1][1] - num[letter[j] - 'A' + 1][2] + num[letter[k] - 'A' + 1][3] - num[letter[l] - 'A' + 1][4] + num[letter[m] - 'A' + 1][5] == n)
							{
								
								 find = true;
								 break;
							}
						}
						if(find) break;
					}
					if(find) break;
				}
				if(find) break;
			}
			if(find) break;
		}
		if(find)
		{
			cout << letter[i] << letter[j] << letter[k] << letter[l] << letter[m] << endl;
		}
		else cout << "no solution" << endl;
	}
	return 0;
}
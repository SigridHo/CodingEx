#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

struct point
{
	double x;
	double y;
};

int main() {
	for(int i = 1; ; ++i)
	{
		char str[210] = {0};
		cin >> str;
		if(strcmp(str, "END") == 0) return 0;
		int length = 0;
		point dest = {0};
		for(int j = 0; j < strlen(str) - 1; ++j)
		{
			if(str[j] >= '0' && str[j] <= '9')
			{
				length = length * 10 + (str[j] - '0');
			}
			else if(str[j] == ',' || str[j] == '.') continue;
			else 
			{
				if(str[j + 1] == ',' || str[j + 1] == '.')
				{
					if(str[j] == 'N') dest.y += length;
					if(str[j] == 'E') dest.x += length;
					if(str[j] == 'W') dest.x -= length;
					if(str[j] == 'S') dest.y -= length;
					length = 0;
				}
				else
				{
					if(str[j] == 'N') dest.y += length / sqrt((double)2);
					if(str[j] == 'S') dest.y -= length / sqrt((double)2);
					if(str[j + 1] == 'E') dest.x += length / sqrt((double)2);
					if(str[j + 1] == 'W') dest.x -= length / sqrt((double)2);
					++j;
					length = 0;
				}
			}
		}
		double dis = 0;
		dis = sqrt(dest.x * dest.x + dest.y * dest.y);
		printf("Map #%d\n", i);
		printf("The treasure is located at (%.3lf,%.3lf).\n", dest.x, dest.y);
		printf("The distance to the treasure is %.3lf.\n\n", dis );
	}

	return 0;
}



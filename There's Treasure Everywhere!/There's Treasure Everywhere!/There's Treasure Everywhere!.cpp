#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

struct step
{
	int length;
	string direct;
};

struct point
{
	double x;
	double y;
};
int main() {
	for(int i = 1; ; ++i)
	{
		char c;
		string temp;
		step STEP[210];
		for(int j = 0; j < 200; ++j)
		{
			STEP[j].direct = "";
			STEP[j].length = 0;
		}
		c = cin.peek();

		if(c == 'E') 
		{
			cin >> temp;
			return 0;
		}
		else if(c == '.')
		{
			cin >> c;
			printf("Map #%d\n", i);
			printf("The treasure is located at (0.000,0.000).\n");
			printf("The distance to the treasure is 0.000.\n\n");
			getchar();
		}
		else
		{
			int j = 0;
			point dest = {0};
			while(1)
			{
				
				cin >> STEP[j].length;
				c = getchar();
				STEP[j].direct = c;
				c = cin.peek();
				if(c == ',') 
				{
					cin >> c;
					++j;
				}
				else if(c == '.')
				{
					cin >> c;
					++j;
					break;
				}
				else
				{
					cin >> c;
					STEP[j].direct.push_back(c);
					++j;
					c = cin.peek();
					if(c == '.') {cin >> c; break;}
					else {cin >> c; continue;}
				}
			}
			for(int k = 0; k < j; ++k)
			{
				if(STEP[k].direct == "E") dest.x += STEP[k].length;
				if(STEP[k].direct == "S") dest.y -= STEP[k].length;
				if(STEP[k].direct == "W") dest.x -= STEP[k].length;
				if(STEP[k].direct == "N") dest.y += STEP[k].length;
				if(STEP[k].direct == "NE") {
					dest.x += STEP[k].length / sqrt((double)2);
					dest.y += STEP[k].length / sqrt((double)2);
				}
				if(STEP[k].direct == "SE") {
					dest.x += STEP[k].length / sqrt((double)2);
					dest.y -= STEP[k].length / sqrt((double)2);
				}
				if(STEP[k].direct == "NW") {
					dest.x -= STEP[k].length / sqrt((double)2);
					dest.y += STEP[k].length / sqrt((double)2);
				}
				if(STEP[k].direct == "SW") {
					dest.x -= STEP[k].length / sqrt((double)2);
					dest.y -= STEP[k].length / sqrt((double)2);
				}
			}
			double dis = 0;
			dis = sqrt(dest.x * dest.x + dest.y * dest.y);
			printf("Map #%d\n", i);
			printf("The treasure is located at (%.3lf,%.3lf).\n", dest.x, dest.y);
			printf("The distance to the treasure is %.3lf.\n\n", dis );
			getchar();
		}
	}
	return 0;
}
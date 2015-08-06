#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

char SourceFile[20000] = {0};
char DestFile[20000] = {0};
bool note = false;
bool str = false;
bool cha = false;
bool backslash = false;

int main()
{
	freopen("test.in","r",stdin); /*如果in.txt不在连接后的exe的目录，需要指定路径如D:\\in.txt*/
	freopen("test.out","w",stdout);/*同上*/
	cin.getline(SourceFile, 20000, 0);
	int len = strlen(SourceFile);
	int j = 0;
	for(int i = 0; i < len; ++i)
	{
		if(!note)
		{
			if((!str) && (!cha))
			{
				if(SourceFile[i] != '/')
				{
					DestFile[j] = SourceFile[i];
					j++;
				}
				else
				{
					if((i + 1 < len) && (SourceFile[i + 1] == '*'))
					{
						note = true;
						i++;
					}
					else
					{
						DestFile[j] = SourceFile[i];
						j++;
					}
				}
				if(SourceFile[i] == '\"' && (!backslash))
					str = true;
				if(SourceFile[i] == '\'' && (!backslash))
					cha = true;
				if(SourceFile[i] == '\\')
					backslash = true;
				else backslash = false;
			}
			else if(str)
			{
				if(SourceFile[i] == '\"' && (!backslash))
					str = false;
				DestFile[j] = SourceFile[i];
				j++;
				if(SourceFile[i] == '\\')
					backslash = true;
				else backslash = false;
			}
			else if(cha)
			{
				if(SourceFile[i] == '\'' && (!backslash))
					cha = false;
				DestFile[j] = SourceFile[i];
				j++;
				if(SourceFile[i] == '\\')
					backslash = true;
				else backslash = false;
			}
		}
		else
		{
			if(SourceFile[i] == '*')
			{
				if((i + 1 < len) && (SourceFile[i + 1] == '/'))
				{
					note = false;
					i++;
				}
			}
			if(SourceFile[i] ==  '\\')
				backslash = true;
			else backslash = false;
		}

	}
	printf("%s", DestFile);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
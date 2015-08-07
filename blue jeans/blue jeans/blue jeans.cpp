#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

#define StrLen 60

using namespace std;

string str[11];
int n;

int main()
{
    int t;
    scanf("%d", &t);
    for(int p = 0; p < t; ++p) 
	{
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            cin >> str[i];
        
        string result = "";
        for(int i = 3; i <= StrLen; i++) 
		{
            for(int j = 0; j <= StrLen - i; j++) 
			{
                string tmp = str[0].substr(j, i);
                bool flag = true;
                for(int k = 1; k < n; k++) 
				{
                    if(str[k].find(tmp) == string::npos) 
					{
                        flag = false;
                        break;
                    }
                }
                if(flag && result.size() < tmp.size())
                    result = tmp;
                else if(flag && tmp.size() == result.size() && tmp < result)
                    result = tmp;
            }
        }
        
        if(result == "")
            printf("no significant commonalities\n");
        else
            cout << result << endl;
    }
    system("pause");
    return 0;
}
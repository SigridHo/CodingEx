#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

class CHugeInt {
	char* str;
public:
	~CHugeInt() {
		if(str) delete[]str;
	}
	CHugeInt(const char* a)
	{
		if(a){
			int len = strlen(a);
			str = new char[len + 1];
			for(int i = 0; i < len; i++)
			{
				str[i] = a[len - 1 - i];
			}
			str[len] = 0;
		} 
		else str = NULL;
	}
	CHugeInt(int n = 0)
	{
		if(n == 0) str = new char [1000];
		else {
			int num[100] = {0};
			int count = 0;
			while(n != 0)
			{
				num[count] = n % 10;
				n /= 10;
				count++;
			}
			str = new char[count + 1];
			for(int i = 0; i < count; i++)
			{
				str[i] = (char) (num[i] + '0');
			}
			str[count] = 0;
		}
	}
	CHugeInt(const CHugeInt& a)
	{
		if(a.str!= NULL) 
		{
			int len = strlen(a.str);
			str = new char[len + 1];
			strcpy(str, a.str);
			str[len] = 0;			
		}
		else str = NULL;
	}
	CHugeInt& operator = (const CHugeInt& a);
	CHugeInt operator + (const CHugeInt& a);
	CHugeInt operator ++ (int);
	CHugeInt& operator ++ ();
	CHugeInt& operator += (int n);
	friend CHugeInt operator + (int a, const CHugeInt& b);
	friend ostream& operator << (ostream& os, const CHugeInt& a);
};

CHugeInt& CHugeInt::operator= (const CHugeInt& a)
{
	if(str) delete[]str;
	if(a.str)
	{
		
		int len = strlen(a.str);
		str = new char[len + 1];
		for(int i = 0; i < len; i++)
		{
			str[i] = a.str[i];
		}
		str[len] = 0;
	}
	else str = NULL;
	return *this;
}
CHugeInt& CHugeInt::operator += (int n)
{
	*this = *this + (CHugeInt)n;
	return *this;
}
CHugeInt CHugeInt::operator ++ (int)
{
	CHugeInt temp = *this;
	*this = *this + 1;
	return temp;
}
CHugeInt& CHugeInt::operator ++ ()
{
	*this = *this + 1;
	return *this;
}
ostream& operator << ( ostream& os, const CHugeInt& a)
{
	int len = strlen(a.str);
	for(int i = 0; i < len; ++i)
	{
		os << a.str[len - 1 - i];
	}
	return os;
}
CHugeInt CHugeInt::operator+(const CHugeInt& a)
{
	int l1 = strlen(str);
	int l2 = strlen(a.str);
	int l = max(l1, l2);
	int *t = new int[l + 1];
	memset(t, 0, sizeof(int) * (l + 1));
	for(int i = 0; i < l1; i++)
	{
		t[i] += str[i] - '0';
	}
	for(int i = 0; i < l2; i++)
	{
		t[i] += a.str[i] - '0';
	}
	for(int i = 0; i < l; i++)
	{
		if(t[i] > 9)
		{
			t[i + 1] += t[i] / 10;
			t[i] %= 10;

		}
	}
	if(t[l]) l++;
	CHugeInt temp;
	for(int i = 0; i < l; i++)
	{
		temp.str[i] = (char) (t[i] + '0');
	}
	temp.str[l] = 0;
	return temp;
}
CHugeInt operator + (int a, const CHugeInt& b){
	return (CHugeInt)a + b;
}
int main() {
	CHugeInt a("1234545436342424354354365289899834234235"); 
	CHugeInt d(9999); 
	CHugeInt temp = CHugeInt("100000088888888") + 111112; 
	CHugeInt temp2 = 111112 + CHugeInt("100000088888888"); 
	cout << "1)" << temp << endl; 
	cout << "2)" << temp2 << endl; 
	cout << "3)" << ++d << endl; 
	cout << "4)" << d++ << endl; 
	cout << "5)" << d << endl; 
	d += 5; 
	cout << "6)" << d << endl; 
	cout << "7)" << d + temp; 
	system("pause");
	return 0;
}
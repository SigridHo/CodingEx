#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 

class CHugeInt {
	private:
		char* str;
	public:
		CHugeInt (const CHugeInt& a)
		{
			if(a.str != NULL)
			{
				int len = strlen(a.str);
				str = new char[len + 1]; //*******************************
				strcpy(str, a.str);
				str[len] = 0;
			}
			else str = NULL;
		}
		~CHugeInt () {
			if(str) delete[]str;
		}
		CHugeInt (const char* a) {
			if(a) {
				int len = strlen(a);
				str = new char[len + 1]; //***************************
				for(int i = 0; i < len; i++)
				{
					str[i] = a[len - i - 1];
				}
				str[len] = 0;
			}
			else str = NULL;
		}
		CHugeInt (int n = 0) {
			if(n == 0) str = new char[10000];
			else {
				int num[100000] = {0};
				int temp = 0;
				while(n != 0) {
					num[temp] = n % 10;
					n /= 10;
					temp++;
				}
				str = new char[temp + 1]; //**********************
				for(int i = 0; i < temp; i++)
				{
					str[i] = char (num[i] + '0');
				}
				str[temp] = 0;
			}
		}
		CHugeInt operator+ (const CHugeInt& a);
		CHugeInt& operator++ ();
		CHugeInt operator++ (int);
		CHugeInt& operator += (int n);
		CHugeInt& operator = (const CHugeInt & a);
		friend CHugeInt operator + (int a, CHugeInt & b);
		friend ostream & operator << (ostream& os, const CHugeInt & b);
		
};

CHugeInt& CHugeInt::operator = (const CHugeInt & a) 
{
	if(a.str != NULL)
	{
		if(str) delete [] str;
		int len = strlen(a.str);
		str = new char[len + 1]; //***********************
		strcpy(str, a.str);
		str[len] = 0;
	}
	else str = NULL;
	return * this;
}
CHugeInt CHugeInt::operator+ (const CHugeInt& a) {
	int l1 = strlen(str);
	int l2 = strlen(a.str);
	int ans[100000] = {0};
	int len = 0;
	if(l1 > l2) {
		for(int i = 0; i < l2; i++)
		{
			ans[i] += (int) (str[i] - '0') + (a.str[i] - '0');
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
		for(int i = l2 - 1; i < l1; i++)
		{
			if(i < l1 - 1) ans[i + 1] += int (str[i + 1] - '0'); //*****************************
			if(ans[i] >= 10)
			{
				ans[i + 1] += ans[i] / 10;
				ans[i] %= 10;
			}
		}
		if(ans[l1] != 0)
		{
			len = l1 + 1;
		}
		else len = l1;

	}
	else {
		for(int i = 0; i < l1; i++)
		{
			ans[i] += (str[i] - '0') + (a.str[i] - '0');
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
		for(int i = l1 - 1; i < l2; i++)
		{
			if(i < l2 - 1) ans[i + 1] += (int) (a.str[i + 1] - '0'); //***********************************
			if(ans[i] >= 10)
			{
				ans[i] %= 10;
			}
		}
		if(ans[l2] != 0)
			len = l2 + 1;
		else len =l2 ;
	}
	/*CHugeInt t;
	t.str[len] = 0;
	for(int i = 0; i < len; ++i)
	{
		t.str[i] = char (ans[i]  + '0');
	}
	*this = t;*/
	if(str) delete[] str;
	str = new char[len + 1];
	for(int i = 0; i < len; ++ i)
	{
		str[i] = char(ans[i] + '0');
	}
	str[len] = 0;
	return * this;
}
CHugeInt operator + (int a, CHugeInt & b)
{
	return CHugeInt(a) + b;
}
CHugeInt & CHugeInt::operator+= (int n) {

	*this =  *this + n;
	return *this;
}
CHugeInt & CHugeInt :: operator++ ()
{
	*this = *this + 1;
	return *this;
}

CHugeInt CHugeInt :: operator++ (int) //***************************
{
	/*
	*this = *this + 1;
	return *this;
	*/
	CHugeInt tmp = *this;
	*this = *this + 1;
	return tmp;
}


ostream & operator << (ostream & os, const CHugeInt & b) 
{
	int len = strlen(b.str);
	for(int i = 0; i < len; ++i)
	{
		os << b.str[len - i - 1];
	}
	return os;
}


int  main() 
{ 
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

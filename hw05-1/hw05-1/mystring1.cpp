#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

class MyString
{
	char* str;
	public:
		MyString(const char* a);
		MyString(MyString& a);
		MyString();
		~MyString() {
			if(str) delete [] str;
		}
		MyString& operator = (const MyString& a);
		MyString operator + (const MyString & a);
		char& operator[] (int n);
		MyString& operator +=(const char* a);
		char* operator () (int m, int n);
		friend bool operator < (const MyString& a, const MyString& b);
		friend bool operator > (const MyString& a, const MyString& b);
		friend bool operator == (const MyString& a, const MyString& b);
		friend ostream& operator << (ostream& os, const MyString& a);
		friend MyString operator +(const char* a, const MyString & b);
};

MyString::MyString(const char* a) 
{
	if(a)
	{
		int len = strlen(a);
		str = new char[len + 1];
		strcpy(str, a);
		str[len] = 0;
	}
	else str = NULL;
}

MyString::MyString(MyString& a)
{
	if(a.str)
	{
		int len = strlen(a.str);
		str = new char[len + 1];
		strcpy(str, a.str);
		str[len] = 0;
	}
	else str = NULL;
}

MyString::MyString() {
	str = NULL;
}

MyString& MyString::operator= (const MyString & a)
{
	if(str) delete [] str;
	if(a.str)
	{
		int len = strlen(a.str);
		str = new char[len + 1];
		strcpy(str, a.str);
		str[len] = 0;
	}
	else str = NULL;
	return *this;
}

MyString MyString::operator+ (const MyString& a)
{
	MyString temp;
	int l1 = strlen(str);
	int l2 = strlen(a.str);
	temp = new char[l1 + l2 + 1];
	for(int i = 0; i < l1; i++)
	{
		temp.str[i] = str[i];	
	}
	for(int i = l1; i < l1 + l2; i++)
	{
		temp.str[i] = a.str[i - l1];
	}
	temp.str[l1 + l2] = 0;
	return temp;
}

char& MyString::operator [] (int n)
{
	return str[n];
}

MyString& MyString::operator += (const char* a)
{
	int l1 = strlen(str);
	int l2 = strlen(a);
	int l = l1 + l2;
	MyString temp = new char[l + 1];
	for(int i = 0; i < l1; i++)
	{
		temp[i] = str[i];
	}
	for(int i = l1 ; i < l; i++)
	{
		temp[i] = a[i - l1];
	}
	temp[l] = 0;
	*this = temp;
	return *this;
}

MyString operator + (const char* a, const MyString& b)
{
	MyString temp = (MyString)a + b;
	return temp;
}

char* MyString::operator()(int m, int n)
{
	char * t = new char[n + 1];
	for(int i = 0; i < n; ++i)
	{
		t[i] = str[i + m];
	}
	t[n] = 0;
	return t;
}

ostream& operator << (ostream& os, const MyString& a)
{
	if(a.str)
		os << a.str;
	else os << "";
	return os;
}

bool operator < (const MyString& a, const MyString& b)
{
	int l1 = strlen(a.str);
	int l2 = strlen(b.str);
	int l = min(l1, l2);
	for(int i = 0; i < l; i++)
	{
		if(a.str[i] > b.str[i]) return false;
		else if(a.str[i] < b.str[i]) return true;
	}
	if(l1 >= l2) return false;
	return true;
}

bool operator > (const MyString& a, const MyString& b)
{
	int l1 = strlen(a.str);
	int l2 = strlen(b.str);
	int l = min(l1, l2);
	for(int i = 0; i < l; i++)
	{
		if(a.str[i] < b.str[i]) return false;
		else if(a.str[i] > b.str[i]) return true;
	}
	if(l1 <= l2) return false;
	return true;
}

bool operator == (const MyString& a, const MyString& b)
{
	int l1 = strlen(a.str);
	int l2 = strlen(b.str);
	int l = min(l1, l2);
	if(l1 != l2) return false;
	for(int i = 0; i < l; i++)
	{
		if(a.str[i] != b.str[i]) return false;
	}
	return true;
}
int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString); 
	for( int i = 0;i < 4;i ++ ) 
		cout << SArray[i] << endl; //输出s1的下标为0的字符开始长度为4的子串 
	cout << s1(0,4) << endl; //输出s1的下标为5的字符开始长度为10的子串 
	cout << s1(5,10) << endl; 
	system("pause");
	return 0;
}

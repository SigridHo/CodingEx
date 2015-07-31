#include <iostream>
using namespace std;

template <class T>
void mysort(T* a, T* b, bool (*f) (T n1, T n2))
{
	T temp;
	int n = b - a;
	for(int i = 0; i != n - 1; ++i)
		for(int j = i + 1; j != n; ++j)
		{
			if(!(*f)(a[i], a[j]))
			{
				temp = a[i];
				a[i]=  a[j];
				a[j] = temp;
			}
		}

}
bool Greater2(int n1,int n2) 
{
	return n1 > n2;
}
bool Greater1(int n1,int n2) 
{
	return n1 < n2;
}
bool Greater3(double d1,double d2)
{
	return d1 < d2;
}
#define NUM 5
int main()
{
    int an[NUM] = { 8,123,11,10,4 };
    mysort(an,an+NUM,Greater1); //��С�������� 
    for( int i = 0;i < NUM; i ++ )
        printf("%d ",an[i]);
    mysort(an,an+NUM,Greater2); //�Ӵ�С���� 
    printf("\n");
    for( int i = 0;i < NUM; i ++ )
        printf("%d ",an[i]);
    printf("\n");
    double d[6] = { 1.4,1.8,3.2,1.2,3.1,2.1};
    mysort(d+1,d+5,Greater3); //��������±�1���±�4��С�������� 
    for( int i = 0;i < 6; i ++ )
        printf("%f ",d[i]);
	system("pause");
	return 0;
}

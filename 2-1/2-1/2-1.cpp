#include <list>
template <class T>
void reverse (int n)
{
	Link<T> *p, *q, *r;
	if(n <= 1) return;
	for(int i = 0; i < n - 1; ++i)
	{
		p = setPos(i);
		if(p == NULL) return;
		q = p->next;
		if(q == NULL) return;
		r = setPos(0);
		p->next = q->next;
		if(p->next == NULL) tail = p;
		q->next = r;
		head = q;
	}
}
int main()
{
	return 0;
}
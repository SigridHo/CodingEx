
#include <iostream>
#include <iterator>

#include <string>
#include <map>
using namespace std;
class Student
{
	public:
	string name;
	struct Info{
		int id;
		double gpa;
	} info;
	Student(string s= 0 ,int i = 0,double g = 0):name(s)   {
		info.id = i; info.gpa = g;
	}
};
int main()
{
	typedef  multimap<string, Student::Info>  MYMAP;
	Student all[] = 
		{ Student("Tom",111111,3.2),Student("Jack",222222,3.1),Student("Bob",33333,2.2),Student("Mike",44444,3.5)};

	MYMAP mp;
	for( int i = 0;i < 4; ++ i)
		mp.insert(MYMAP::value_type(all[i].name, all[i].info)) ;
	MYMAP::iterator i;
	for( i = mp.begin(); i != mp.end(); ++i ) {
		cout << i->first << "," << i->second.id << "," << i->second.gpa << endl;
	}
	system("pause");
	return 0;
}


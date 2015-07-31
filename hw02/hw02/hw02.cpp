#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
using namespace std;

class cStudent{            //定义一个学生信息的类
private:                   //所有的成员变量皆私有
	char name[30];
	int age;
	int number;
	double score1, score2, score3, score4;
public:                   //一系列成员函数声明
	void SetScore(double s1_, double s2_, double s3_, double s4_);
	void SetName(char name_[30]);
	void SetAge(int age_);
	void SetNum(int number_);
	double Aver();
	void PrintName();
	void PrintAge();
	void PrintNum();
};

/*用于初始化成绩的函数*/
void cStudent::SetScore(double s1_, double s2_, double s3_, double s4_) {     
	score1 = s1_;
	score2 = s2_;
	score3 = s3_;
	score4 = s4_;
}

/*用于初始化年龄的函数*/
void cStudent::SetAge(int age_) {
	age = age_;
}

/*用于初始化姓名的函数*/
void cStudent::SetName(char name_[30]) {
	strcpy(name, name_);
}

/*用于初始化学号的函数*/
void cStudent::SetNum(int number_) {
	number = number_;
}

/*用于计算平均成绩的函数*/
double cStudent::Aver() {
	double temp = (score1 + score2 + score3 + score4) / 4;
	return temp;
}

/*用于打印姓名的函数*/
void cStudent::PrintName() {
	printf("%s", name);
}

/*用于打印年龄的函数*/
void cStudent::PrintAge() {
	printf("%d", age);
}

/*用于打印学号的函数*/
void cStudent::PrintNum() {
	printf("%d", number);
}


int main() {
	char name[30] = {0};
	int age = 0;
	int number = 0;
	double s1 = 0, s2 = 0, s3 = 0, s4 = 0;
	cin.getline(name, 30, ',');  //读入姓名
	scanf("%d,%d,%lf,%lf,%lf,%lf", &age, &number, &s1, &s2, &s3, &s4);
	cStudent stu1;   //定义对象
	stu1.SetAge(age);  //对象初始化
	stu1.SetName(name);
	stu1.SetNum(number);
	stu1.SetScore(s1,s2,s3,s4);
	double score = stu1.Aver();  //计算平均成绩
	stu1.PrintName();  //打印输出
	printf(",");
	stu1.PrintAge();
	printf(",");
	stu1.PrintNum();
	printf(",%g\n",score);
	return 0;
}
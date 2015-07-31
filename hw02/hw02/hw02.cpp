#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
using namespace std;

class cStudent{            //����һ��ѧ����Ϣ����
private:                   //���еĳ�Ա������˽��
	char name[30];
	int age;
	int number;
	double score1, score2, score3, score4;
public:                   //һϵ�г�Ա��������
	void SetScore(double s1_, double s2_, double s3_, double s4_);
	void SetName(char name_[30]);
	void SetAge(int age_);
	void SetNum(int number_);
	double Aver();
	void PrintName();
	void PrintAge();
	void PrintNum();
};

/*���ڳ�ʼ���ɼ��ĺ���*/
void cStudent::SetScore(double s1_, double s2_, double s3_, double s4_) {     
	score1 = s1_;
	score2 = s2_;
	score3 = s3_;
	score4 = s4_;
}

/*���ڳ�ʼ������ĺ���*/
void cStudent::SetAge(int age_) {
	age = age_;
}

/*���ڳ�ʼ�������ĺ���*/
void cStudent::SetName(char name_[30]) {
	strcpy(name, name_);
}

/*���ڳ�ʼ��ѧ�ŵĺ���*/
void cStudent::SetNum(int number_) {
	number = number_;
}

/*���ڼ���ƽ���ɼ��ĺ���*/
double cStudent::Aver() {
	double temp = (score1 + score2 + score3 + score4) / 4;
	return temp;
}

/*���ڴ�ӡ�����ĺ���*/
void cStudent::PrintName() {
	printf("%s", name);
}

/*���ڴ�ӡ����ĺ���*/
void cStudent::PrintAge() {
	printf("%d", age);
}

/*���ڴ�ӡѧ�ŵĺ���*/
void cStudent::PrintNum() {
	printf("%d", number);
}


int main() {
	char name[30] = {0};
	int age = 0;
	int number = 0;
	double s1 = 0, s2 = 0, s3 = 0, s4 = 0;
	cin.getline(name, 30, ',');  //��������
	scanf("%d,%d,%lf,%lf,%lf,%lf", &age, &number, &s1, &s2, &s3, &s4);
	cStudent stu1;   //�������
	stu1.SetAge(age);  //�����ʼ��
	stu1.SetName(name);
	stu1.SetNum(number);
	stu1.SetScore(s1,s2,s3,s4);
	double score = stu1.Aver();  //����ƽ���ɼ�
	stu1.PrintName();  //��ӡ���
	printf(",");
	stu1.PrintAge();
	printf(",");
	stu1.PrintNum();
	printf(",%g\n",score);
	return 0;
}
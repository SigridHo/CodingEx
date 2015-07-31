#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int DRAGON=0,NINJIA=1,ICEMAN=2,LION=3,WOLF=4;    // Type of Warriors
const int Order[2][5]={{2,3,4,1,0},{3,0,1,2,4}};  // Order of each headquarter
const char* WholeColor[2]={"red","blue"};     // Color of each headquarter
const char* WarriorName[5]={"dragon","ninja","iceman","lion","wolf"};  
const char* WeaponName[3]={"sword","bomb","arrow"};  
int HeadquarterLife[2] = {0,0}, InitialLife[5] = {0}, WarriorPower[5], noworder[2] = {0, 0}, number[2] = {0,0};
int CityNumber = 0, ArrowPower = 0, LoyaltyDecrease = 0, TotalTime = 0, PastTime = 0, Hour = -1;
bool RedOne = false;
bool BlueOne = false;
int temp1[23] = {0};  // the result of attack if each city
int temp2[23] = {0};  // the result of antiatack of each city

/*weapon part*/
class sword
{
	int Power;
public:
	sword(int a):Power(a){};
	void UseSword() {
		Power *= 0.8;
	}
	bool CheckPower()
	{
		if(Power > 0) return false;
		else return true;
	}
	int GetPower() {return Power;}
};

class arrow
{
	int UsedTimes;
	int Power;
public:
	arrow(int a):Power(a), UsedTimes(3){};
	int UseArrow() 
	{
		UsedTimes--;
		return Power;
	}
	int GetPower() {return Power;}
	int GetUsedTimes() {return UsedTimes;}
	bool CheckUsedTimes()
	{
		return ((bool)UsedTimes);
	}
};

/*Warrior part*/
class Warrior
{
public:
	int Color;
	int Hp;
	int Type;
	int Power;
	int Number;
	sword* Sword;
	arrow* Arrow;
	bool Bomb;

	Warrior(int, int, int );
	bool Attack(Warrior* temp, int citynumber);
	bool CheckAttack(Warrior temp);
	virtual bool LIONESCAPE() {return false;}
	virtual void IcemanMarch() {return;}
	virtual bool AntiAttack(Warrior* temp, int citynumber);
	virtual bool CheckAntiAttack(Warrior temp);
	virtual double GetMorale() { return -1;}
	virtual void MoraleIncrease() {return;}
	virtual void MoraleDecrease() {return;}
	virtual void LOYALTYDECREASE() {return;}
};
class Dragon:public Warrior
{
	double morale;
public:
	Dragon(int color, int type, int number):Warrior(color, type, number)
	{
		morale = (double)HeadquarterLife[Color] / InitialLife[0];
		printf("Its morale is %.2f\n", morale);
	}
	double GetMorale() {return morale;}
	void MoraleDecrease() {morale-=0.2;}
	void MoraleIncrease() {morale += 0.2;}
};
class Ninja:public Warrior
{
public:
	Ninja(int color, int type, int number): Warrior(color, type, number){};
	bool AntiAttack(Warrior* temp, int number) {return false;}
	bool CheckAntiAttack(Warrior temp){return false;}
};
class Lion:public Warrior
{
	int loyalty;
public:
	Lion(int color, int type, int number): Warrior(color, type, number)
	{
		loyalty = HeadquarterLife[Color];
		printf("Its loyalty is %d\n", loyalty);
	}
	bool LIONESCAPE()
	{
		if(loyalty <= 0) return true;
		else return false;
	}
	void LOYALTYDECREASE() {
		loyalty -= LoyaltyDecrease;
	}
};
class Iceman:public Warrior
{
	int step;
public:
	Iceman(int color, int type, int number): Warrior(color, type, number), step(0){};
	void IcemanMarch();
};
class Wolf:public Warrior
{
public:
	Wolf(int color, int type, int number): Warrior(color, type, number){};
};

bool Warrior::Attack(Warrior* temp, int citynumber)
{
	if((*temp).Hp == 0) 
	{
		temp = NULL;
		return true;
	}
	(*temp).Hp -= Power;
	if(Sword != NULL)
	{
		(*temp).Hp -= Sword->GetPower();
		Sword->UseSword();
		if(Sword->CheckPower()) Sword = NULL;
	}
	printf("%.3d:40 %s %s %d attacked %s %s %d in city %d with %d elements and force %d\n", Hour, WholeColor[Color], WarriorName[Type], Number, WholeColor[(*temp).Color], WarriorName[(*temp).Type], (*temp).Number, citynumber, Hp, Power);
	if((*temp).Hp > 0) 
		return false;
	else 
	{
		printf("%.3d:40 %s %s %d was killed in city %d\n", Hour, WholeColor[temp->Color], WarriorName[temp->Type], temp->Number, citynumber);
		temp = NULL;
		return true;
	}
}
bool Warrior::CheckAttack(Warrior temp)
{
	if(temp.Hp == 0) return true;
	temp.Hp -= Power;
	if(Sword != NULL)
	{
		temp.Hp -= Sword->GetPower();
	}
	if(temp.Hp > 0) return false;
	else return true;
}
bool Warrior::AntiAttack(Warrior* temp, int citynumber)
{
	int tem = Power * 0.5;
	(*temp).Hp -= tem;
	if(Sword != NULL)
	{
		
		(*temp).Hp -= Sword->GetPower();
		Sword->UseSword();
		if(Sword->CheckPower()) Sword = NULL;
	}
	printf("%.3d:40 %s %s %d fought back against %s %s %d in city %d\n", Hour, WholeColor[Color], WarriorName[Type], Number, WholeColor[(*temp).Color], WarriorName[(*temp).Type], (*temp).Number, citynumber);
	if((*temp).Hp > 0) return false;
	else
	{
		printf("%.3d:40 %s %s %d was killed in city %d\n", Hour, WholeColor[temp->Color], WarriorName[temp->Type], temp->Number, citynumber);
		temp = NULL;
		return true;
	}
}
bool Warrior::CheckAntiAttack(Warrior temp)
{
	temp.Hp -= Power * 0.5;
	if(Sword != NULL)
	{
		temp.Hp -= Sword->GetPower();
	}
	if(temp.Hp > 0) return false;
	else return true;
}
Warrior::Warrior(int color, int type, int number)
{
	printf("%.3d:00 %s %s %d born\n", Hour, WholeColor[color], WarriorName[type], number);
	Type = type;
	HeadquarterLife[color] -= InitialLife[Type];
	Number = number;
	Color = color;
	Hp = InitialLife[Type];
	Power = WarriorPower[Type];
	Sword = NULL;
	Arrow = NULL;
	Bomb = false;
	if(Type == DRAGON || Type == ICEMAN)
	{
		if(number % 3 == 0)
		{
			if(Power * 0.2 != 0)
			{
				Sword = new sword(Power * 0.2);
			}
		}
		else if(number % 3 == 1)
		{
			Bomb = true;
		}
		else if(number % 3 == 2)
		{
			Arrow = new arrow(ArrowPower);
		}
	}
	else if(Type == NINJIA)
	{
		if(number % 3 == 0)
		{
			if(Power * 0.2 != 0)
			{
				Sword = new sword(Power * 0.2);
			}
			Bomb = true;
		}
		else if(number % 3 == 1)
		{
			Bomb = true;
			Arrow = new arrow(ArrowPower);
		}
		else if(number % 3 == 2)
		{
			if(Power * 0.2 != 0)
			{
				Arrow = new arrow( ArrowPower);
				Sword = new sword(Power * 0.2);
			}
		}
	}
}
void Iceman::IcemanMarch()
{
	step++;
	if(step % 2 == 0)
	{
		Power += 20;
		if(Hp <= 9) Hp = 1;
		else Hp -= 9;
	}
}

/*City part*/
class City
{
public:
	int Number;
	int Color;
	int Hp;
	int Flag;
	Warrior* state[2];

	void build(int x);
	int GetHp() {return Hp;}
	void AddElement(){Hp += 10;}
	void UseBomb();
	int ATTACK();
	int ANTIATTACK();
	void YELL();
	void ChangeFlag();
	void DragonCheck();
	void PRIZE();
};
City citys[23];
int prize[23] = {0};
void City::UseBomb()
{
	if((state[0] != NULL) && (state[1] != NULL) && (state[0]->Hp != 0) && (state[1]->Hp != 0))
	{
		if(state[0]->Bomb)
		{
			if(Color == 0 || (Color == -1 && Number % 2 == 1))
			{
				if(!state[0]->CheckAttack(*state[1]) && state[1]->CheckAntiAttack(*state[0])) 
				{
					printf("%.3d:38 red %s %d used a bomb and killed blue %s %d\n", Hour, WarriorName[state[0]->Type], state[0]->Number, WarriorName[state[1]->Type], state[1]->Number);
					state[0] = NULL;
					state[1] = NULL;
					return;
				}
			}
			else
			{
				if(state[1]->CheckAttack(*state[0]))
				{
					printf("%.3d:38 red %s %d used a bomb and killed blue %s %d\n", Hour, WarriorName[state[0]->Type], state[0]->Number, WarriorName[state[1]->Type], state[1]->Number);
					state[0] = NULL;
					state[1] = NULL;
					return;
				}
			}
		}
		if(state[1]->Bomb)
		{
			if(Color == 1 || (Color == -1 && Number % 2 == 0))
			{
				if(!state[1]->CheckAttack(*state[0]) && state[0]->CheckAntiAttack(*state[1])) 
				{
					printf("%.3d:38 blue %s %d used a bomb and killed red %s %d\n", Hour, WarriorName[state[1]->Type], state[1]->Number, WarriorName[state[0]->Type], state[0]->Number);
					state[1] = NULL;
					state[0] = NULL;
					return;
				}
			}
			else
			{
				if(state[0]->CheckAttack(*state[1]))
				{
					printf("%.3d:38 blue %s %d used a bomb and killed red %s %d\n", Hour, WarriorName[state[1]->Type], state[1]->Number, WarriorName[state[0]->Type], state[0]->Number);
					state[1] = NULL;
					state[0] = NULL;
					return;
				}
			}
		}
	}
}
void City::DragonCheck()
{
	if(state[0] != NULL && state[0]->Type == DRAGON)
	{
		if(temp1[Number] == 0 || temp1[Number] == 2 || (temp1[Number] == -1 && temp2[Number] == 0))
			state[0]->MoraleIncrease();
		else state[0]->MoraleDecrease();
	}
	if(state[1] != NULL && state[1]->Type == DRAGON)
	{
		if(temp1[Number] == 1 || temp1[Number] == 3 || (temp1[Number] == -1 && temp2[Number] == 1))
			state[1]->MoraleIncrease();
		else state[1]->MoraleDecrease();
	}
}
void City::ChangeFlag()
{
	if(temp1[Number] == -1 && temp2[Number] == -1) Flag = 0;
	if(temp1[Number] == 0 || (temp1[Number] == -1 && temp2[Number] == 0) || temp1[Number] == 2)
	{ 
		bool rise = false;
		if(Color != 0) rise = true;
		if(Flag >= 0) {Flag = -1;}
		else 
		{
			Flag--;
			Color = 0;
			if(Flag == -2 && rise)printf("%.3d:40 red flag raised in city %d\n", Hour, Number);
		}
	}
	if(temp1[Number] == 1 || (temp1[Number] == -1 && temp2[Number] == 1) || temp1[Number] == 3) 
	{
		bool rise = false;
		if(Color != 1) rise = true;
		if(Flag <= 0) {Flag = 1;}
		else
		{
			Flag++;
			Color = 1;
			if(Flag == 2 && rise)printf("%.3d:40 blue flag raised in city %d\n", Hour, Number);
		}
	}
}
void City::YELL()
{
	if(temp1[Number] != 10 && (state[0] != NULL)&& (state[0]->Hp > 0) && (state[0]->Type == DRAGON))
	{
		if(Color == 0 || (Color == -1 && Number % 2 == 1))
		{
			if(state[0]->GetMorale() > 0.8)
			{
				printf("%.3d:40 %s %s %d yelled in city %d\n", Hour, WholeColor[state[0]->Color], WarriorName[state[0]->Type], state[0]->Number, Number);
			}
		}
	}
	if(temp1[Number] != 10&& (state[1] != NULL) &&(state[1]->Hp > 0) && (state[1]->Type == DRAGON))
	{
		if(Color == 1 || (Color == -1 && Number % 2 == 0))
		{
			if(state[1]->GetMorale() > 0.8)
			{
				printf("%.3d:40 %s %s %d yelled in city %d\n", Hour, WholeColor[state[1]->Color], WarriorName[state[1]->Type], state[1]->Number, Number);
			}
		}
	}
}
int City::ANTIATTACK()
{
	sword* temps = NULL;
	arrow* tempa = NULL;
	bool tempb = NULL;
	bool wolf = false;
	if(Color == 0 || (Color == -1 && Number % 2 == 1))
	{
		if(state[1]->CheckAntiAttack(*state[0])) 
		{
			if(state[1]->Type == WOLF) 
			{
				wolf = true;
				if((state[1]->Sword == NULL) && (state[0]->Sword != NULL))	temps = state[0]->Sword;
				if((state[1]->Arrow == NULL) && (state[0]->Arrow != NULL))	tempa = state[0]->Arrow;
				if(!state[1]->Bomb && state[0]->Bomb) tempb = true;
			}
			int temp = 0;
			bool lion = false;
			if(state[0]->Type == LION)	
			{
				lion = true;
				temp= state[0]->Hp;
			}
			state[1]->AntiAttack(state[0],Number);
			if(state[0]->Hp <= 0) state[0] = NULL;
			if(lion)  state[1]->Hp += temp;
			if(wolf)
			{
				if(temps != NULL) state[1]->Sword = temps;
				if(tempa != NULL) state[1]->Arrow = tempa;
				if(tempb) state[1]->Bomb = true; 
			}
			return 1;
		}
		else
		{
			if(state[1]->Type == LION) state[1]->LOYALTYDECREASE();
			state[1]->AntiAttack(state[0],Number);
			return -1;
		}
	}
	else
	{
		if(state[0]->CheckAntiAttack(*state[1]))
		{
			if(state[0]->Type == WOLF) 
			{
				wolf = true;
				if((state[0]->Sword == NULL) && (state[1]->Sword != NULL))	temps = state[1]->Sword;
				if((state[0]->Arrow == NULL) && (state[1]->Arrow != NULL))	tempa = state[1]->Arrow;
				if(!state[0]->Bomb && state[1]->Bomb) tempb = true;
			}
			int temp = 0;
			bool lion = false;
			if(state[1]->Type == LION)	
			{
				lion = true;
				temp = state[1]->Hp;
			}
			state[0]->AntiAttack(state[1], Number);
			if(state[1] ->Hp <= 0) state[1] = NULL;
			if(lion) state[0]->Hp += temp;
			if(wolf)
			{
				if(temps != NULL) state[0]->Sword = temps;
				if(tempa != NULL) state[0]->Arrow = tempa;
				if(tempb) state[0]->Bomb = true; 
			}
			return 0;
		}
		else 
		{
			if(state[0]->Type == LION) state[0]->LOYALTYDECREASE();
			state[0]->AntiAttack(state[1], Number);
			return -1;
		}
	}
}
int City:: ATTACK() 
{
	sword* temps = NULL;
	arrow* tempa = NULL;
	bool tempb = NULL;
	bool wolf = false;
	if((state[0] != NULL) && (state[1] != NULL) && (state[0]->Hp <= 0) && (state[1]->Hp <= 0)) 
	{state[0] = NULL; state[1] = NULL; return 10;}
	if((state[0] != NULL) && (state[0]->Hp <= 0) && (state[1] == NULL)) {state[0] = NULL; return 10;}
	if((state[1] != NULL) && (state[1]->Hp <= 0) && (state[0] == NULL)) {state[1] = NULL; return 10;}
	if(state[0] != NULL && state[1] != NULL)
	{
		if(state[0]->Hp <= 0) 
		{
			if(state[1]->Type == WOLF) 
			{
				if((state[1]->Sword == NULL) && (state[0]->Sword != NULL))	state[1]->Sword = state[0]->Sword;
				if((state[1]->Arrow == NULL) && (state[0]->Arrow != NULL))	state[1]->Arrow = state[0]->Arrow;
				if(!state[1]->Bomb && state[0]->Bomb) state[1]->Bomb = true;
			}
			state[0] = NULL;
			return 3; // red warrior is killed by arrow
		}
		else if(state[1]->Hp <= 0)
		{
			if(state[0]->Type == WOLF) 
			{
				if((state[0]->Sword == NULL) && (state[1]->Sword != NULL))	state[0]->Sword = state[1]->Sword;
				if((state[0]->Arrow == NULL) && (state[1]->Arrow != NULL))	state[0]->Arrow = state[1]->Arrow;
				if(!state[0]->Bomb && state[1]->Bomb) state[0]->Bomb = true;
			}
			state[1] = NULL;
			return 2;  // blue warrior is killed by arrow
		}
		else
		{
			if(Color == 0 || (Color == -1 && Number % 2 == 1))
			{
				if(state[0]->CheckAttack(*state[1])) 
				{
					if(state[0]->Type == WOLF) 
					{
						wolf = true;
						if((state[0]->Sword == NULL) && (state[1]->Sword != NULL))	temps = state[1]->Sword;
						if((state[0]->Arrow == NULL) && (state[1]->Arrow != NULL))	tempa = state[1]->Arrow;
						if(!state[0]->Bomb && state[1]->Bomb) tempb = true;
					}
					int temp = 0;
					bool lion = false;
					if(state[1]->Type == LION)	
					{
						temp = state[1]->Hp;
						lion = true;
					}
					state[0]->Attack(state[1], Number);
					state[1] = NULL;
					if(lion) state[0]->Hp += temp;
					if(wolf)
					{
						if(temps != NULL) state[0]->Sword = temps;
						if(tempa != NULL) state[0]->Arrow = tempa;
						if(tempb) state[0]->Bomb = true; 
					}
					return 0;
				}
				else 
				{
					if(state[0]->Type == LION) state[0]->LOYALTYDECREASE();
					state[0]->Attack(state[1], Number);
					return -1;
				}
			}
			else
			{
				if(state[1]->CheckAttack(*state[0])) 
				{
					if(state[1]->Type == WOLF) 
					{
						wolf = true;
						if((state[1]->Sword == NULL) && (state[0]->Sword != NULL))	temps = state[0]->Sword;
						if((state[1]->Arrow == NULL) && (state[0]->Arrow != NULL))	tempa = state[0]->Arrow;
						if(!state[1]->Bomb && state[0]->Bomb) tempb = true;
					}
					int temp = 0;
					bool lion = false;
					if(state[0]->Type == LION)	
					{
						lion = true;
						temp = state[0]->Hp;
					}
					state[1]->Attack(state[0], Number);
					state[0] = NULL;
					if(lion)
					{
						state[1]->Hp += temp;
					}
					if(wolf)
					{
						if(temps != NULL) state[1]->Sword = temps;
						if(tempa != NULL) state[1]->Arrow = tempa;
						if(tempb) state[1]->Bomb = true; 
					}
					return 1;
				}
				else 
				{
					if(state[1]->Type == LION) state[1]->LOYALTYDECREASE();
					state[1]->Attack(state[0], Number);
					return -1;
				}
			}
		}
	}
	else 
	{
		if((state[0] != NULL) && (state[0]->Hp == 0)) state[0] = NULL;
		if((state[1] != NULL) && (state[1]->Hp == 0)) state[1] = NULL;
		return 10;
	}
}
void City::build(int x)
{
	Number = x;
	Color = -1;
	Hp = 0;
	Flag = 0;
	state[0] = NULL;
	state[1] = NULL;
}
void City::PRIZE()
{
	if(temp1[Number] == 0 || temp1[Number] == 2 || (temp1[Number] == -1 && temp2[Number] == 0))
		prize[Number] = -1;
	if(temp2[Number] == 1 || temp2[Number] == 3 || (temp1[Number] == -1 && temp2[Number] == 1))
		prize[Number] = 1;
}

// static functons
void CREATEWARRIOR()
{
	for(int i = 0; i <= 1; ++i)
	{
		if(HeadquarterLife[i] >= InitialLife[Order[i][noworder[i]]])
		{
			Warrior* temp;
			number[i]++;
			if(Order[i][noworder[i]] == DRAGON) temp = new Dragon(i, Order[i][noworder[i]], number[i]);
			else if(Order[i][noworder[i]] == LION)temp = new Lion(i, Order[i][noworder[i]], number[i]);
			else if(Order[i][noworder[i]] == ICEMAN)temp = new Iceman(i, Order[i][noworder[i]], number[i]);
			else if(Order[i][noworder[i]] == WOLF)temp = new Wolf(i, Order[i][noworder[i]], number[i]);
			else if(Order[i][noworder[i]] == NINJIA)temp = new Ninja(i, Order[i][noworder[i]], number[i]);
			if(i == 0)
			{
				citys[0].state[0] = temp;
			}
			else citys[CityNumber + 1].state[1] = temp;
			noworder[i] = (noworder[i] + 1) % 5;
		}
	}
}
void LIONRUNAWAY()
{
	
	if((citys[0].state[0] != NULL)  && (citys[0].state[0]->LIONESCAPE()))
	{
		printf("%.3d:05 red lion %d ran away\n", Hour, citys[0].state[0]->Number);
		citys[0].state[0] = NULL;
	}
	for(int i = 1; i <= CityNumber; ++i)
	{
		for(int j = 0; j < 2; ++j)
		{
			if((citys[i].state[j] != NULL) && (citys[i].state[j]->LIONESCAPE()))
			{
				printf("%.3d:05 %s lion %d ran away\n", Hour, WholeColor[citys[i].state[j]->Color], citys[i].state[j]->Number);
				citys[i].state[j] = NULL;
			}
		}		
	}
	if((citys[CityNumber + 1].state[1] != NULL) && (citys[CityNumber + 1].state[1]->LIONESCAPE()))
	{
		printf("%.3d:05 blue lion %d ran away\n", Hour, citys[CityNumber + 1].state[1]->Number);
		citys[CityNumber + 1].state[1] = NULL;
	}
}

bool WARRIORMARCH()
{
	bool RedOver = false;
	bool BlueOver = false;
	if(citys[CityNumber + 1].state[0] != NULL)
	{
		BlueOne = true;
		if(citys[CityNumber].state[0] != NULL) BlueOver = true;
	}
	if(citys[0].state[1] != NULL)
	{ 
		RedOne = true;
		if(citys[1].state[1] != NULL) RedOver = true;
	}
	for(int i = CityNumber; i >= 0; -- i)
	{
		if(citys[i].state[0] != NULL)
		{
			if(citys[i].state[0]->Type == ICEMAN) citys[i].state[0]->IcemanMarch();
			citys[i + 1].state[0] = citys[i].state[0];
			citys[i].state[0] = NULL;
		}
	}
	for(int i = 1; i <= CityNumber + 1; ++ i)
	{
		if(citys[i].state[1] != NULL)
		{
			if(citys[i].state[1]->Type == ICEMAN) citys[i].state[1]->IcemanMarch();
			citys[i - 1].state[1] = citys[i].state[1];
			citys[i].state[1] = NULL;
		}
	}
	for(int i = 0; i <= CityNumber + 1; ++ i)
	{
		if(i == 0)
		{
			if(citys[i].state[1] != NULL && (!RedOne || RedOver))
			{
				printf("%.3d:10 blue %s %d reached red headquarter with %d elements and force %d\n", Hour, WarriorName[citys[i].state[1]->Type], citys[i].state[1]->Number, citys[i].state[1]->Hp, citys[i].state[1]->Power);
				
				RedOne = true;
				if(RedOver) 
				{
					printf("%.3d:10 red headquarter was taken\n", Hour);
					
				}
			}
		}
		else if(i == CityNumber + 1)
		{
			if(citys[i].state[0] != NULL && (!BlueOne || BlueOver))
			{
				printf("%.3d:10 red %s %d reached blue headquarter with %d elements and force %d\n", Hour, WarriorName[citys[i].state[0]->Type], citys[i].state[0]->Number, citys[i].state[0]->Hp, citys[i].state[0]->Power);
				
				BlueOne = true;
				if(BlueOver)
				{
					printf("%.3d:10 blue headquarter was taken\n", Hour);
				
				}
			}
		}
		else
		{
			for(int j = 0; j < 2; ++ j)
			{
				if(citys[i].state[j] != NULL)
				{
					printf("%.3d:10 %s %s %d marched to city %d with %d elements and force %d\n", Hour, WholeColor[citys[i].state[j]->Color], WarriorName[citys[i].state[j]->Type], citys[i].state[j]->Number, i, citys[i].state[j]->Hp, citys[i].state[j]->Power);
					
				}
			}
		}
	}
	if(RedOver || BlueOver) return true;
	else return false;
	
}
void FREETAKE()
{
	for(int i = 1; i <= CityNumber; ++i)
	{
		if(citys[i].state[0] != NULL && citys[i].state[0]->Hp > 0 && (citys[i].state[1] == NULL || citys[i].state[1]->Hp == 0))
		{
			printf("%.3d:30 red %s %d earned %d elements for his headquarter\n", Hour, WarriorName[citys[i].state[0]->Type], citys[i].state[0]->Number, citys[i].Hp);
			HeadquarterLife[0] += citys[i].Hp;
			citys[i].Hp = 0;
		}
		else if(citys[i].state[1] != NULL && citys[i].state[1]->Hp > 0 && (citys[i].state[0] == NULL || citys[i].state[0]->Hp == 0))
		{
			printf("%.3d:30 blue %s %d earned %d elements for his headquarter\n", Hour, WarriorName[citys[i].state[1]->Type], citys[i].state[1]->Number, citys[i].Hp);
			HeadquarterLife[1] += citys[i].Hp;			
			citys[i].Hp = 0;
		}
	}
}
void ARROWGO()
{
	if(citys[1].state[0] != NULL && citys[1].state[0]->Arrow != NULL)
	{
		if(citys[2].state[1] != NULL)
		{
			citys[2].state[1]->Hp -= (citys[1].state[0]->Arrow)->UseArrow();
			if((citys[1].state[0]->Arrow)->GetUsedTimes() == 0) citys[1].state[0]->Arrow = NULL;
			if(citys[2].state[1]->Hp <= 0)
			{
				printf("%.3d:35 red %s %d shot and killed blue %s %d\n", Hour, WarriorName[citys[1].state[0]->Type],citys[1].state[0]->Number, WarriorName[citys[2].state[1]->Type], citys[2].state[1]->Number);
				if(citys[2].state[0] != NULL) citys[2].state[1]->Hp = 0;
				else citys[2].state[1] = NULL;
			}
			else printf("%.3d:35 red %s %d shot\n", Hour, WarriorName[citys[1].state[0]->Type],citys[1].state[0]->Number);
					
		}
	}
	for(int i = 2; i < CityNumber; ++ i)
	{
		if(citys[i].state[0] != NULL && citys[i].state[0]->Arrow != NULL)
		{
			if(citys[i + 1].state[1] != NULL)
			{
				citys[i + 1].state[1]->Hp -= (citys[i].state[0]->Arrow)->UseArrow();
				if((citys[i].state[0]->Arrow)->GetUsedTimes() == 0) citys[i].state[0]->Arrow = NULL;
				if(citys[i + 1].state[1]->Hp <= 0)
				{
					printf("%.3d:35 red %s %d shot and killed blue %s %d\n", Hour, WarriorName[citys[i].state[0]->Type],citys[i].state[0]->Number, WarriorName[citys[i + 1].state[1]->Type], citys[i + 1].state[1]->Number);
					citys[i + 1].state[1]->Hp = 0;
				}
				else printf("%.3d:35 red %s %d shot\n", Hour, WarriorName[citys[i].state[0]->Type],citys[i].state[0]->Number);
			}
		}
		if(citys[i].state[1] != NULL && citys[i].state[1]->Arrow != NULL)
		{
			if(citys[i - 1].state[0] != NULL)
			{
				citys[i - 1].state[0]->Hp -= (citys[i].state[1]->Arrow)->UseArrow();
				if((citys[i].state[1]->Arrow)->GetUsedTimes() == 0) citys[i].state[1]->Arrow = NULL;
				if(citys[i - 1].state[0]->Hp <= 0)
				{
					printf("%.3d:35 blue %s %d shot and killed red %s %d\n", Hour, WarriorName[citys[i].state[1]->Type],citys[i].state[1]->Number, WarriorName[citys[i - 1].state[0]->Type], citys[i - 1].state[0]->Number);
					citys[i - 1].state[0]->Hp = 0;
				}
				else printf("%.3d:35 blue %s %d shot\n", Hour, WarriorName[citys[i].state[1]->Type],citys[i].state[1]->Number);
			}
		}
	}
	if(citys[CityNumber].state[1] != NULL && citys[CityNumber].state[1]->Arrow != NULL)
	{
		if(citys[CityNumber - 1].state[0] != NULL)
		{
			citys[CityNumber - 1].state[0]->Hp -= (citys[CityNumber].state[1]->Arrow)->UseArrow();
			if((citys[CityNumber].state[1]->Arrow)->GetUsedTimes() == 0) citys[CityNumber].state[1]->Arrow = NULL;
			if(citys[CityNumber - 1].state[0]->Hp <= 0)
			{
				printf("%.3d:35 blue %s %d shot and killed red %s %d\n", Hour, WarriorName[citys[CityNumber].state[1]->Type],citys[CityNumber].state[1]->Number, WarriorName[citys[CityNumber - 1].state[0]->Type], citys[CityNumber - 1].state[0]->Number);
				if(citys[CityNumber - 1].state[1] != NULL) citys[CityNumber - 1].state[0]->Hp = 0;
				else citys[CityNumber -1].state[0] = NULL;
			}
			else printf("%.3d:35 blue %s %d shot\n", Hour, WarriorName[citys[CityNumber].state[1]->Type],citys[CityNumber].state[1]->Number);
		}
	}
}
void EARNELEMENTS()
{
	for(int i = 1; i <= CityNumber; ++i)
	{
		if(temp1[i] == 0 || temp1[i] == 2 || (temp1[i] == -1 && temp2[i] == 0))
		{
			HeadquarterLife[0] += citys[i].GetHp();
			citys[i].Hp = 0;
			printf("%.3d:40 %s %s %d earned %d elements for his headquarter\n", Hour, WholeColor[citys[i].state[0]->Color], WarriorName[citys[i].state[0]->Type], citys[i].state[0]->Number, citys[i].GetHp());
		}
		if(temp1[i] == 1 || temp1[i] == 3 || (temp1[i] == -1 && temp2[i] == 1))
		{
			HeadquarterLife[1] += citys[i].GetHp();
			citys[i].Hp = 0;
			printf("%.3d:40 %s %s %d earned %d elements for his headquarter\n", Hour, WholeColor[citys[i].state[1]->Color], WarriorName[citys[i].state[1]->Type], citys[i].state[1]->Number, citys[i].GetHp());
		}
	}
}
/*void CITYPRIZE()
{
	for(int i = CityNumber; i >= 1; --i)
	{
		if(HeadquarterLife[0] < 8) break;
		bool redwin = false;
		if((citys[i].state[0] == NULL) || (citys[i].state[1] == NULL) || citys[i].state[0]->Hp == 0) continue;
		if(citys[i].state[1]->Hp == 0) redwin = true;
		else if(citys[i].Color == 0 || (citys[i].Color == - 1 && citys[i].Number % 2 == 1))
		{
			if(citys[i].state[0]->CheckAttack(*(citys[i].state[1]))) redwin = true;
			
		}
		else if(citys[i].Color == 1 || (citys[i].Color == -1 && citys[i].Number % 2 == 0))
		{
			if((!citys[i].state[1]->CheckAttack(*(citys[i].state[0]))) && citys[i].state[0]->CheckAntiAttack(*(citys[i].state[1]))) redwin = true;
		}
		if(redwin) prize[i] = -1;
	}
	for(int i = 1; i <= CityNumber; ++i)
	{
		if(HeadquarterLife[1] < 8) break;
		bool bluewin = false;
		if(prize[i] != 0) continue;
		if((citys[i].state[0] == NULL) || (citys[i].state[1] == NULL) || citys[i].state[1]->Hp == 0) continue;
		if(citys[i].state[0]->Hp == 0) bluewin = true;
		else if(citys[i].Color == 1 || (citys[i].Color == - 1 && citys[i].Number % 2 == 0))
		{
			if(citys[i].state[1]->CheckAttack(*(citys[i].state[0]))) bluewin = true;
		}
		else if(citys[i].Color == 0 || (citys[i].Color == -1 && citys[i].Number % 2 == 1))
		{
			if((!citys[i].state[0]->CheckAttack(*(citys[i].state[1]))) && citys[i].state[1]->CheckAntiAttack(*(citys[i].state[0]))) bluewin = true;
		}
		if(bluewin) prize[i] = 1;
	}
}*/
void HEADQUARTERANNOUNCE()
{
	printf("%.3d:50 %d elements in red headquarter\n", Hour, HeadquarterLife[0]);
	printf("%.3d:50 %d elements in blue headquarter\n", Hour, HeadquarterLife[1]);
}
void REDANNOUNCE()
{
	for(int i = 0; i <= CityNumber + 1; ++i)
	{
		if(citys[i].state[0] != NULL)
		{
			bool weap1 = false;
			bool weap2 = false;
			bool weap3 = false;
			if(citys[i].state[0]->Arrow != NULL && citys[i].state[0]->Arrow->GetUsedTimes() == 0) citys[i].state[0]->Arrow = NULL;
			if(citys[i].state[0]->Sword != NULL && citys[i].state[0]->Sword->GetPower() <= 0) citys[i].state[0]->Sword = NULL;
			printf("%.3d:55 red %s %d has ", Hour, WarriorName[citys[i].state[0]->Type], citys[i].state[0]->Number);
			if(citys[i].state[0]->Arrow != NULL)
			{
				
				weap1 = true;
				printf("arrow(%d)", citys[i].state[0]->Arrow->GetUsedTimes());
			}
			if(citys[i].state[0]->Bomb)
			{
				weap2 = true;
				if(weap1) printf(",bomb");
				else printf("bomb");
			}
			if(citys[i].state[0]->Sword != NULL)
			{
				weap3 = true;
				if(weap1 || weap2) printf(",sword(%d)", citys[i].state[0]->Sword->GetPower());
				else printf("sword(%d)", citys[i].state[0]->Sword->GetPower());
			}
			if(!weap1 && !weap2 && !weap3) printf("no weapon");
			printf("\n");
		}
	}
}
void BLUEANNOUNCE()
{
	for(int i = 0; i <= CityNumber + 1; ++i)
	{
		if(citys[i].state[1] != NULL)
		{
			bool weap1 = false;
			bool weap2 = false;
			bool weap3 = false;
			if(citys[i].state[1]->Arrow != NULL && citys[i].state[1]->Arrow->GetUsedTimes() == 0) citys[i].state[1]->Arrow = NULL;
			if(citys[i].state[1]->Sword != NULL && citys[i].state[1]->Sword->GetPower() <= 0) citys[i].state[1]->Sword = NULL;
			printf("%.3d:55 blue %s %d has ", Hour, WarriorName[citys[i].state[1]->Type], citys[i].state[1]->Number);
			if(citys[i].state[1]->Arrow != NULL)
			{
				weap1 = true;
				printf("arrow(%d)", citys[i].state[1]->Arrow->GetUsedTimes());
			}
			if(citys[i].state[1]->Bomb)
			{
				weap2 = true;
				if(weap1) printf(",bomb");
				else printf("bomb");
			}
			if(citys[i].state[1]->Sword != NULL)
			{
				weap3 = true;
				if(weap1 || weap2) printf(",sword(%d)", citys[i].state[1]->Sword->GetPower());
				else printf("sword(%d)", citys[i].state[1]->Sword->GetPower());
			}
			if(!weap1 && !weap2 && !weap3) printf("no weapon");
			printf("\n");
		}
	}
}
int main() {
	freopen("out.txt", "w", stdout);
	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++ i)
	{
		 for(int j = 0; j < 23; ++j)
		 {
			 citys[j].build(-1);
		 }
		 int TotalLife;
		 scanf("%d%d%d%d%d",&TotalLife, &CityNumber, &ArrowPower, &LoyaltyDecrease, &TotalTime);
		 HeadquarterLife[0] = TotalLife;
		 HeadquarterLife[1] = TotalLife;
		 noworder[0] = 0;
		 noworder[1] = 0;
		 number[0] = 0;
		 number[1] = 0;
		 for(int j = 0; j < 5; ++j)
		 {
			 scanf("%d", &InitialLife[j]);
		 }
		 for(int j = 0; j < 5; ++j)
		 {
			 scanf("%d", &WarriorPower[j]);
		 }
		 for(int j = 0; j <= CityNumber + 1; ++j)
		 {
			 citys[j].build(j);
		 }
		 bool GameOver = false;
		 printf("Case %d:\n", i);
		 RedOne = false;
		 BlueOne = false;
		 PastTime = 0;
		 Hour = -1;
		 
		 while(1)
		 {
			 Hour++;
			 CREATEWARRIOR();
			 PastTime += 5;
			 if(PastTime > TotalTime) break;
			 LIONRUNAWAY();
			 PastTime += 5;
			 if(PastTime > TotalTime) break;
			 GameOver = WARRIORMARCH();
			 if(GameOver) break;
			 PastTime += 10;
			 if(PastTime > TotalTime) break;
			 for(int j = 1; j <= CityNumber; ++j) citys[j].AddElement();
			 PastTime += 10;
			 if(PastTime > TotalTime) break;
			 FREETAKE();
			 PastTime += 5;
			 if(PastTime > TotalTime) break;
			 ARROWGO();
			 PastTime += 3;
			 if(PastTime > TotalTime) break;
			 for(int j = 1; j <= CityNumber; ++j)
			 {
				 citys[j].UseBomb();
			 }
			 PastTime += 2;
			 if(PastTime > TotalTime) break;
			 for(int j = 0; j < 23; ++j)
			 {
				 temp1[j] = 10;
				 temp2[j] = 10;
			 }
			 for(int j = 0; j < 23; ++j)
			 {
				 prize[j] = 0;
			 }
			/* CITYPRIZE()*/
			 int Life1 = HeadquarterLife[0];
			 int Life2 = HeadquarterLife[1];
			 for(int j = 1; j <= CityNumber; ++ j)
			 {
				 temp1[j] = citys[j].ATTACK();  /* temp1= 0 means red win, 1 means blue win, -1 means no kill, 10 means no battle, 2 means blue has been killed by arrow, 3 means red has been killed by arrow */  
				 if(temp1[j] == -1)
				 {
					if(citys[j].state[0] == NULL && citys[j].state[1] == NULL) temp2[j] = -1;
					else temp2[j] = citys[j].ANTIATTACK();
				 }
				 citys[j].DragonCheck();
				 citys[j].YELL();
				 if(temp1[j] == 1 ||temp1[j] == 3 || (temp1[j] == -1 && temp2[j] == 1))
				 {
					 HeadquarterLife[1] += citys[j].GetHp();
					 printf("%.3d:40 %s %s %d earned %d elements for his headquarter\n", Hour, WholeColor[citys[j].state[1]->Color], WarriorName[citys[j].state[1]->Type], citys[j].state[1]->Number, citys[j].GetHp());
					 citys[j].Hp = 0;
				 }
				 if(temp1[j] == 0 || temp1[j] == 2 || (temp1[j] == -1 && temp2[j] == 0))
				 {
					 HeadquarterLife[0] += citys[j].GetHp();
					 printf("%.3d:40 %s %s %d earned %d elements for his headquarter\n", Hour, WholeColor[citys[j].state[0]->Color], WarriorName[citys[j].state[0]->Type], citys[j].state[0]->Number, citys[j].GetHp());
					 citys[j].Hp = 0;
				 }
				 citys[j].ChangeFlag();
				 citys[j].PRIZE();
			 }
			 for(int j = CityNumber; j > 0; j--)
			 {
				 if(prize[j] == -1 && Life1 >= 8)
				 {
					 HeadquarterLife[0] -= 8;
					 Life1 -= 8;
					 citys[j].state[0]->Hp += 8;
				 }
			 }
			 for(int j = 1; j <= CityNumber; ++j)
			 {
				 if(prize[j] == 1 && Life2 >= 8)
				 {
					 HeadquarterLife[1] -= 8;
					 Life2 -= 8;
					 citys[j].state[1]->Hp += 8;
				 }
			 }
			 PastTime += 10;
			 if(PastTime > TotalTime) break;
			 HEADQUARTERANNOUNCE();
			 PastTime += 5;
			 if(PastTime > TotalTime) break;
			 REDANNOUNCE();
			 BLUEANNOUNCE();
			 PastTime += 5;
			 if(PastTime > TotalTime) break;
		 }
	}
	return 0;
}
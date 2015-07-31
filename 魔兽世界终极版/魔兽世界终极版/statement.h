#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
#include <stdlib.h>
#include <cstdio>
using namespace std;


static string WeaponNumber[3] = { "sword", "bomb", "arrow"};
static string OrderRed[5] = {"iceman", "lion", "wolf", "ninja", "dragon"};
static string OrderBlue[5] = {"lion", "dragon", "ninja", "iceman", "wolf"};
struct SSword
{
	int ISwordPower;
};

struct SBomb
{
	bool bomb;
};

struct SArrow
{
	int IArrowPower;
};

struct SWeapon : SSword, SBomb, SArrow
{
	string WeaponName;
	int INumber;
};

struct SWarrior
{
	int INumber;
	int IRank;
	int ILife;
	int IPower;
	SWeapon sw1, sw2, sw3;
	SWarrior(int life = 0, int power = 0, int number = 0):ILife(life), IPower(power),INumber(number){};
};

struct SDragon : public SWarrior
{
	double morale;
	SDragon(int life = 0, int power = 0):SWarrior(life, power){};
};

struct SNinja : SWarrior
{
	SNinja(int life = 0, int power = 0):SWarrior(life, power){};
};

struct SIceman : SWarrior
{
	SIceman(int life = 0, int power = 0):SWarrior(life, power){};
};

struct SLion : SWarrior
{
	int ILoyalty;
	int IDecrease;
	SLion(int life = 0, int power = 0, int dec = 0):SWarrior(life, power), IDecrease(dec){};
};

struct SWolf :SWarrior
{
	SWolf(int life = 0, int power = 0):SWarrior(life, power){};
};

struct CCity
{
	int ICityLife;
	int flag;  // 0 means no flag, 1 means red flag, 2 means blue flag
	bool dragon[2];
	bool lion[2];
	bool iceman[2];
	bool ninja[2];
	bool wolf[2];
	SDragon dra;
	SLion lio;
	SIceman sic;
	SNinja nin;
	SWolf wol;
};

CCity CityArray[23] = {0};

struct CHeadquarter
{
public:
	int arrowpow;
	string Colour;
	int ICityNumber;
	int ITotalNumber;
	int ITotalLife;
	SLion Lion;
	SDragon Dragon;
	SNinja Ninja;
	SIceman Iceman;
	SWolf Wolf;

	CHeadquarter(string col, int M, int citynumber, int R, int K, int IniLifeDragon, int IniLifeNinja, int IniLifeIceman, int IniLifeLion, int IniLifeWolf, int IniPowDragon, int IniPowNinja, int IniPowIceman, int IniPowLion, int IniPowWolf,int number = 0):  ITotalNumber(number), ITotalLife(M), ICityNumber(citynumber),Lion(IniLifeLion, IniPowLion, K), Dragon(IniLifeDragon, IniPowDragon), Ninja(IniLifeNinja, IniPowNinja), Iceman(IniLifeIceman, IniPowIceman), Wolf(IniLifeWolf, IniPowWolf),arrowpow(R){};
	void Create(){};

};

void CHeadquarter::Create()
{
	int number = ITotalNumber % 5;
	if(Colour == "red")
	{
		while(1)
		{
			if(Dragon.IRank == number)
			{
				if(ITotalLife >= Dragon.ILife)
				{
					ITotalLife -= Dragon.ILife;
					ITotalNumber++;
					CityArray[ICityNumber].dra.ILife = Dragon.ILife;
					CityArray[ICityNumber].dra.INumber = ITotalNumber;
					CityArray[ICityNumber].dra.IPower = Dragon.IPower;
					CityArray[ICityNumber].dra.morale = (double)ITotalLife / Dragon.ILife;
					CityArray[ICityNumber].dra.sw1.INumber = ITotalNumber % 3;
					int temp = ITotalNumber % 3;
					CityArray[ICityNumber].dra.sw1.WeaponName = WeaponNumber[temp];
					if(temp == 0) CityArray[ICityNumber].dra.sw1.ISwordPower = Dragon.IPower * 0.2;
					if(temp == 1) CityArray[ICityNumber].dra.sw1.bomb = true;
					if(temp == 2) CityArray[ICityNumber].dra.sw1.IArrowPower = arrowpow;
					break;

				}
				else break;
			}
		}
	}
	

}
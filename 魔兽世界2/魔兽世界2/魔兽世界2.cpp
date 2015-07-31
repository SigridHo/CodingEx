#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <cmath>
#include <stdio.h>
using namespace std;

struct sWarrior {   // the number and initial life of each warrior

	int nNumber;  
	int nLife;
	int nrank;
};

char weapon[4][10] = {"sword", "bomb", "arrow"};

class CLion:public sWarrior
{
public:
	int loyalty;
};

class CIceman:public sWarrior
{
public:
	char weap[10];
};
class CNinja:public sWarrior
{
public:
	char weap[2][10];
};
class CDragon:public sWarrior
{
public:
	char weap[10];
	double morale;
};
char OrderRed[5][10] = {"iceman", "lion", "wolf", "ninja", "dragon"};
char OrderBlue[5][10] = {"lion", "dragon", "ninja", "iceman", "wolf"};

int OrderLifeRed[5] = {0};
int OrderLifeBlue[5] = {0};

int nOrderRed = 0, nOrderBlue = 0;

class cHeadquater {  
	private :
		int nTotalLife;  // the total life left
		int nTotalNumber;
		CLion sLion;  // the five kinds of warriors 
		CIceman sIceman;
		sWarrior sWolf;
		CNinja sNinja;
		CDragon sDragon;
	public:
		char nColor[10];
		cHeadquater(char Color_[10], int TotalLife_, int Dragon_, int Ninja_, int Iceman_, int Lion_, int Wolf_);
		bool check(char Color_[10]);
		void print(char Color_[10]);
};

cHeadquater :: cHeadquater(char Color_[10], int TotalLife_, int Dragon_, int Ninja_, int Iceman_, int Lion_, int Wolf_) {
	strcpy(nColor, Color_);
	if(strcmp(Color_, "red") == 0) {
		sIceman.nrank = 0;
		sLion.nrank = 1;
		sWolf.nrank = 2;
		sNinja.nrank = 3;
		sDragon.nrank = 4;
	}
	else {
		sLion.nrank = 0;
		sDragon.nrank = 1;
		sNinja.nrank = 2;
		sIceman.nrank = 3;
		sWolf.nrank = 4;
	}
	nTotalLife = TotalLife_;
	nTotalNumber = 0;
	sLion.nLife = Lion_;
	sLion.nNumber = 0;
	sLion.loyalty = 0;
	sDragon.nLife = Dragon_;
	sDragon.nNumber = 0;
	sDragon.morale = 0;
	strcpy(sDragon.weap,"");
	sNinja.nLife = Ninja_;
	sNinja.nNumber = 0;
	strcpy(sNinja.weap[0],"");
	strcpy(sNinja.weap[1], "");
	sIceman.nLife = Iceman_;
	sIceman.nNumber = 0;
	strcpy(sIceman.weap, "");
	sWolf.nLife = Wolf_;
	sWolf.nNumber = 0;
}

bool cHeadquater::check(char Color_[10]) {
	if(strcmp(Color_, "red") == 0) {
		int temp = nOrderRed;
		while(1){
			if(sLion.nrank == nOrderRed) {
				if(nTotalLife >= sLion.nLife) {
					nTotalLife -= sLion.nLife;
					sLion.nNumber++;
					nTotalNumber++;
					sLion.loyalty = nTotalLife;
					nOrderRed = (nOrderRed + 1) % 5;
					return true;
				}
				else {
					nOrderRed = (nOrderRed + 1) % 5;
				}
			}
			else if(sIceman.nrank == nOrderRed) {
				if(nTotalLife >= sIceman.nLife) {
					nTotalLife -= sIceman.nLife;
					sIceman.nNumber++;
					nTotalNumber++;
					strcpy(sIceman.weap, weapon[nTotalNumber % 3]); 
					nOrderRed = (nOrderRed + 1) % 5;
					return true;
				}
				else {
					nOrderRed = (nOrderRed + 1) % 5;
				}
			}
			else if(sDragon.nrank == nOrderRed) {
				if(nTotalLife >= sDragon.nLife) {
					nTotalLife -= sDragon.nLife;
					sDragon.nNumber++;
					nTotalNumber++;
					strcpy(sDragon.weap, weapon[nTotalNumber % 3]);
					sDragon.morale = (double)nTotalLife / sDragon.nLife;
					nOrderRed = (nOrderRed + 1) % 5;
					return true;
				}
				else {
					nOrderRed = (nOrderRed + 1) % 5;
				}
			}

			else if(sNinja.nrank == nOrderRed) {
				if(nTotalLife >= sNinja.nLife) {
					nTotalLife -= sNinja.nLife;
					sNinja.nNumber++;
					nTotalNumber++;
					strcpy(sNinja.weap[0],weapon[nTotalNumber% 3]);
					strcpy(sNinja.weap[1], weapon[(nTotalNumber + 1) % 3]);
					nOrderRed = (nOrderRed + 1) % 5;
					return true;
				}
				else {
					nOrderRed = (nOrderRed + 1) % 5;
				}
			}
			else if(sWolf.nrank == nOrderRed) {
				if(nTotalLife >= sWolf.nLife) {
					nTotalLife -= sWolf.nLife;
					sWolf.nNumber++;
					nTotalNumber++;
					nOrderRed = (nOrderRed + 1) % 5;
					return true;
				}
				else {
					nOrderRed = (nOrderRed + 1) % 5;
				}
			}
			if(nOrderRed == temp) break;
		}
		return false;
	}
	else {
		int temp = nOrderBlue;
		while(1){
			if(sLion.nrank == nOrderBlue) {
				if(nTotalLife >= sLion.nLife) {
					nTotalLife -= sLion.nLife;
					sLion.nNumber++;
					nTotalNumber++;
					sLion.loyalty = nTotalLife;
					nOrderBlue = (nOrderBlue + 1) % 5;
					return true;
				}
				else {
					nOrderBlue = (nOrderBlue + 1) % 5;
				}
			}
			else if(sIceman.nrank == nOrderBlue) {
				if(nTotalLife >= sIceman.nLife) {
					nTotalLife -= sIceman.nLife;
					sIceman.nNumber++;
					nTotalNumber++;
					strcpy(sIceman.weap, weapon[nTotalNumber % 3]); 
					nOrderBlue = (nOrderBlue + 1) % 5;
					return true;
				}
				else {
					nOrderBlue = (nOrderBlue + 1) % 5;
				}
			}
			else if(sDragon.nrank == nOrderBlue) {
				if(nTotalLife >= sDragon.nLife) {
					nTotalLife -= sDragon.nLife;
					sDragon.nNumber++;
					nTotalNumber++;
					strcpy(sDragon.weap, weapon[nTotalNumber % 3]);
					sDragon.morale = (double)nTotalLife / sDragon.nLife;
					nOrderBlue = (nOrderBlue + 1) % 5;
					return true;
				}
				else {
					nOrderBlue = (nOrderBlue + 1) % 5;
				}
			}

			else if(sNinja.nrank == nOrderBlue) {
				if(nTotalLife >= sNinja.nLife) {
					nTotalLife -= sNinja.nLife;
					sNinja.nNumber++;
					nTotalNumber++;
					strcpy(sNinja.weap[0],weapon[nTotalNumber% 3]);
					strcpy(sNinja.weap[1], weapon[(nTotalNumber + 1) % 3]);
					nOrderBlue = (nOrderBlue + 1) % 5;
					return true;
				}
				else {
					nOrderBlue = (nOrderBlue + 1) % 5;
				}
			}
			else if(sWolf.nrank == nOrderBlue) {
				if(nTotalLife >= sWolf.nLife) {
					nTotalLife -= sWolf.nLife;
					sWolf.nNumber++;
					nTotalNumber++;
					nOrderBlue = (nOrderBlue + 1) % 5;
					return true;
				}
				else {
					nOrderBlue = (nOrderBlue + 1) % 5;
				}
			}
			if(nOrderBlue == temp) break;
		}
		return false;
	}	
}

void cHeadquater::print(char Color_[10]) {
	
	if(strcmp(Color_, "red") == 0) {
		int temp = (nOrderRed - 1 + 5) % 5;
		printf("%s %s %d born with strength %d,",Color_, OrderRed[temp], nTotalNumber, OrderLifeRed[temp]);
		if(sLion.nrank == temp) {
			printf("%d %s in %s headquarter\n", sLion.nNumber,OrderRed[temp], Color_);
			printf("It's loyalty is %d\n", sLion.loyalty);
		}
		else if(sIceman.nrank == temp) {
			printf("%d %s in %s headquarter\n", sIceman.nNumber,OrderRed[temp], Color_);
			printf("It has a %s\n", sIceman.weap);
		}
		else if(sNinja.nrank == temp) {
			printf("%d %s in %s headquarter\n", sNinja.nNumber,OrderRed[temp], Color_);
			printf("It has a %s and a %s\n", sNinja.weap[0],sNinja.weap[1]);
		}
		else if(sDragon.nrank == temp) {
			printf("%d %s in %s headquarter\n", sDragon.nNumber,OrderRed[temp], Color_);
			printf("It has a %s,and it's morale is %.2lf\n", sDragon.weap, sDragon.morale);
		}
		else if(sWolf.nrank == temp) {
			printf("%d %s in %s headquarter\n", sWolf.nNumber,OrderRed[temp], Color_);
		}
	}
	else {
		int temp = (nOrderBlue - 1 + 5) % 5;
		printf("%s %s %d born with strength %d,",Color_, OrderBlue[temp], nTotalNumber, OrderLifeBlue[temp]);
		if(sLion.nrank == temp) {
			printf("%d %s in %s headquarter\n", sLion.nNumber,OrderBlue[temp], Color_);
			printf("It's loyalty is %d\n", sLion.loyalty);
		}
		else if(sIceman.nrank == temp) {
			printf("%d %s in %s headquarter\n", sIceman.nNumber,OrderBlue[temp], Color_);
			printf("It has a %s\n", sIceman.weap);
		}
		else if(sNinja.nrank == temp) {
			printf("%d %s in %s headquarter\n", sNinja.nNumber,OrderBlue[temp], Color_);
			printf("It has a %s and a %s\n", sNinja.weap[0],sNinja.weap[1]);
		}
		else if(sDragon.nrank == temp) {
			printf("%d %s in %s headquarter\n", sDragon.nNumber,OrderBlue[temp], Color_);
			printf("It has a %s,and it's morale is %.2lf\n", sDragon.weap, sDragon.morale);
		}
		else if(sWolf.nrank == temp) {
			printf("%d %s in %s headquarter\n", sWolf.nNumber,OrderBlue[temp], Color_);
		}
	}
}
int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int times = 0;
	scanf("%d", &times);
	for(int i = 0; i != times; ++i) {
		int nInitialTotalLife = 0;
		nOrderRed = 0;
		nOrderBlue = 0;
		scanf("%d", &nInitialTotalLife);
		int Dra = 0, Nin = 0, Ice = 0, Lio = 0, Wol = 0;
		scanf("%d%d%d%d%d", &Dra, &Nin, &Ice, &Lio, &Wol);
		OrderLifeRed[0] = Ice;
		OrderLifeRed[1] = Lio;
		OrderLifeRed[2] = Wol;
		OrderLifeRed[3] = Nin;
		OrderLifeRed[4] = Dra;
		OrderLifeBlue[0] = Lio;
		OrderLifeBlue[1] = Dra;
		OrderLifeBlue[2] = Nin;
		OrderLifeBlue[3] = Ice;
		OrderLifeBlue[4] = Wol;
		cHeadquater cRedHeadquater("red", nInitialTotalLife, Dra, Nin, Ice, Lio, Wol), cBlueHeadquater("blue", nInitialTotalLife, Dra, Nin, Ice, Lio, Wol);
		printf("Case:%d\n", (i + 1));
		bool bRedAlive = true, bBlueAlive = true;
		for(int j = 0; ; ++j) {
			if(bRedAlive && cRedHeadquater.check("red"))
			{
				printf("%03d ", j);
				cRedHeadquater.print("red");
			}
			else if(bRedAlive) {
				printf("%03d red headquarter stops making warriors\n", j);
				bRedAlive = false;
			}
			if(bBlueAlive && cBlueHeadquater.check("blue"))
			{
				printf("%03d ", j);
				cBlueHeadquater.print("blue");
			}
			else if(bBlueAlive) {
				printf("%03d blue headquarter stops making warriors\n", j);
				bBlueAlive = false;
			}
			if(!bRedAlive && !bBlueAlive) break;
		}
	}
	return 0;
}
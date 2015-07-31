#include "statement.h"

CHeadquarter::CHeadquarter(string col, int M, int citynumber, int R, int K, int IniLifeDragon, int IniLifeNinja, int IniLifeIceman, int IniLifeLion, int IniLifeWolf, int IniPowDragon, int IniPowNinja, int IniPowIceman, int IniPowLion, int IniPowWolf,int number = 0):  ITotalNumber(number), ITotalLife(M), ICityNumber(citynumber),Lion(IniLifeLion, IniPowLion, K), Dragon(IniLifeDragon, IniPowDragon), Ninja(IniLifeNinja, IniPowNinja), Iceman(IniLifeIceman, IniPowIceman), Wolf(IniLifeWolf, IniPowWolf),arrowpow(R){
	Dragon.morale = (double)ITotalLife / IniLifeDragon;
	if(col == "red")
	{
		Iceman.IRank = 0;
		Lion.IRank = 1;
		Wolf.IRank = 2;
		Ninja.IRank = 3;
		Dragon.IRank = 4;
	}
	if(col == "blue")
	{
		Lion.IRank = 0;
		Dragon.IRank = 1;
		Ninja.IRank = 2;
		Iceman.IRank = 3;
		Wolf.IRank = 4;
	}
};
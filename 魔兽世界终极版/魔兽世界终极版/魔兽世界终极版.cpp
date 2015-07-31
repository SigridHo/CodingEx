#include "statement.h"
#include "function.h"

int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++ i)
	{
		 printf("Case %d:", i);
		 int M, N, R, K, T;
		 scanf("%d%d%d%d%d",&M, &N, &R, &K, &T);
		 int IniLifeDragon, IniLifeNinja, IniLifeIceman, IniLifeLion, IniLifeWolf;
		 scanf("%d%d%d%d%d", &IniLifeDragon,&IniLifeNinja,&IniLifeIceman,&IniLifeLion,&IniLifeWolf);
		 int IniPowDragon, IniPowNinja, IniPowIceman, IniPowLion, IniPowWolf;
		 scanf("%d%d%d%d%d", &IniPowDragon, &IniPowNinja, &IniPowIceman, &IniPowLion, &IniPowWolf);
		 CHeadquarter RedHeadquarter("red", M, 0, R, K, IniLifeDragon, IniLifeNinja, IniLifeIceman, IniLifeLion, IniLifeWolf, IniPowDragon, IniPowNinja, IniPowIceman, IniPowLion, IniPowWolf);
		 CHeadquarter BlueHeadquarter("blue", M, N + 1, R, K, IniLifeDragon, IniLifeNinja, IniLifeIceman, IniLifeLion, IniLifeWolf, IniPowDragon, IniPowNinja, IniPowIceman, IniPowLion, IniPowWolf);
		 int hour;
		 hour = T / 60;
		 int minute;
		 minute = T % 60;
		 for(int j = 0; j < hour; ++ j)
		 {
			 RedHeadquarter.Create();
			 BlueHeadquarter.Create();
		 }

	}
	return 0;
}
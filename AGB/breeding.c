/*
	"The egg will hatch into a level 5 version of the bottom of the female's evolutionary chain (or the non-Ditto parent)."

  After creating a new mon, take three IVs at random from the parents.

       DAD  MOM  KID
  HP   [5]   1   [5]
  Atk   6   [2]  [2]
  Def   8    3    6
  Spd  [9]   4   [9]
  SAt   2    5    2
  SDf   4    6    8

*/
#include "openpoke.h"

/*    Depth:     0               1
Charmander   Charmander   Charmander
Charmeleon   Charmander   Charmander
Charizard    Charmander   Charmeleon
Ultrazard?   Charmeleon   Charizard

Can't have any higher values than 1.
*/
int FindDevo(int targetSpecies, int depth)
{
	int i, j;
	for(i=1; i < pkTotal; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(Evolutions[(i*4*5)+(j*4)+2] == targetSpecies)
			{
				if(depth == 0)
				{
					return FindDevo(i, 1);
				} else
				{
					return i;
				}
			}
		}
	}
	return targetSpecies;
}

int GetEggMoves(int species, unsigned short * list)
{
	int ii, ct;
	for(ii = 0; ii < pkTotal; ii++)
	{
		if(EggMoves[ii] == species + 20000) break;
	}
	ii++;
	for(ct = 0; ct < 9; ct++)
	{
		if(EggMoves[ii+ct] > 20000) break;
		list[ct] = EggMoves[ii+ct];
	}
	return ct;
}

int GetGender(int species, int pv)
{
	if(BaseStats[species].Gender < 0xFF)
	{
		if((u8)pv > BaseStats[species].Gender)
		{
			return 0;
		} else
		{
			return 1;
		}
	}
	return 0xFF;
}

int sub_804651C(int * g1, int * g2)
{
	int i,j;
	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
			if(g1[i] == g2[j])
				return TRUE;
	return FALSE;
}

int GetBreedProbability(aPokemon *monx)
{
	int groups[2][2], species[2], otids[2], genders[2];
	int i;
	for(i = 0; i < 2; i++)
	{
		species[i] = GetMonsterMainStats(&monx[i], pSpecies);
		otids[i] = GetMonsterMainStats(&monx[i], pOTID);
		genders[i] = GetGender(species[i], GetMonsterMainStats(&monx[i], pPersonal));
		groups[i][0] = BaseStats[species[i]].EggGroup1;
		groups[i][1] = BaseStats[species[i]].EggGroup2;
	}

	if(groups[0][0] == eggNone || groups[1][0] == eggNone)
		return 0;

	if(groups[0][0] == eggDitto || groups[1][0] == eggDitto)
	{
		if(groups[1][0] == eggDitto) //second must be Ditto
			return (otids[0] == otids[1]) ? 20 : 50;
	} else
		return 0;

	if(genders[0] == genders[1] || genders[0] == 0xFF || genders[1] == 0xFF) //homo sex is sin ;)
		return 0;

	if(sub_804651C(groups[0], groups[1]) == FALSE)
		return 0;

	if(species[0] == species[1])
		return (otids[0] == otids[1]) ? 70 : 50; //UPC has this in reverse: 50 if ==.

	return (otids[0] == otids[1]) ? 20 : 50;
}



void GetDaycareNames(aPokemon *monx) //used by Spec_B5
{
	//char otname[12];
	if(GetMonsterMainStats(&monx[0], pSpecies) != 0)
	{
		strcpy(StringVar[1], monx[0].Personal.Nickname);
		strcpy(StringVar[3], monx[0].Personal.OTName);
		//GetNickName(monx, StringVar[1]);
		//GetMonsterMainStats(monx, pOTName, otname);
		//CopyString(StringVar[3], otname);
	}

	if(GetMonsterMainStats(&monx[1], pSpecies) != 0)
		strcpy(StringVar[2], monx[1].Personal.Nickname);
		//GetNickName(&monx[1], StringVar[2]);
}

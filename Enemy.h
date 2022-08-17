#pragma once
#include <iostream>
#include <string>
#include <cstdio>
#include <list>
#include "Actor.h"
#include "Inventory.h"

using namespace std;

class Enemy : public Actor
{
private:

	int expA; // exp awarded
	int itemN; // item awarded
	int goldA; // gold awarded
	bool leader; // lead
	int party_num;

public:

	// constructor
	Enemy();

	Enemy(string name, elementType, int expA, int gA, int item);

	//Enemy enemiesList(int indexPass); please leave me alone

	Enemy enemyRandEncounterI();

	Enemy enemyRandEncounterII();

	Enemy BossCall(int);

	//Enemy callTroopMember(int);

	struct summonData
	{
		string name;
		int hpd = 0;
		int spd = 0; // special
		int fpd = 0; // fighter (aural) 
		int ATKd = 0; // attack
		int DEFd = 0; // defence (armor based)
		int SPEEDd = 0; // speed 
		int AGId = 0; // agility
		int DEXd = 0; // dexterity
		int INTd = 0; // intelligence
		int SPRd = 0; // spirit
		int STRd = 0; // strength (also effects status)
		int ENDd = 0; // endurance (bodily based / also effects status)
		int CONd = 0; // constitution (mental, body, soul, based / also effects status)
		int hp = 0;
		int sp = 0;
		int fp = 0;
		int ATK = 0;
		int DEF = 0;
		int SPEED = 0;
		int AGI = 0;
		int DEX = 0;
		int INT = 0;
		int SPR = 0;
		int STR = 0;
		int END = 0;
		int CON = 0;
		elementType summonType;
	};

	struct magicArch
	{
		string name;
		// total damage output
		int tdo;
		// health
		int hpd = 0;
		// special points
		int spd = 0;
		// aural points
		int fpd = 0;
		// stat add
		int ATKd = 0;
		int DEFd = 0;
		int SPEEDd = 0;
		int AGId = 0;
		int DEXd = 0;
		int INTd = 0;
		int SPRd = 0;
		int STRd = 0;
		int ENDd = 0;
		int CONd = 0;

		//core stat changes
		int hp = 0;
		int sp = 0;
		int fp = 0;
		int ATK = 0;
		int DEF = 0;
		int SPEED = 0;
		int AGI = 0;
		int DEX = 0;
		int INT = 0;
		int SPR = 0;
		int STR = 0;
		int END = 0;
		int CON = 0;

		int manaCharge = 0;
		int auralCharge = 0;
		elementType spellType;
		// rune effects...
		// combined effect
	};

	struct skillSet
	{
		string name;
		// stat add
		int hpd = 0;
		int spd = 0;
		int fpd = 0;
		int ATKd = 0;
		int DEFd = 0;
		int SPEEDd = 0;
		int AGId = 0;
		int DEXd = 0;
		int INTd = 0;
		int SPRd = 0;
		int STRd = 0;
		int ENDd = 0;
		int CONd = 0;
		int efficiency;
		int executionRating;
		// damage ouput
		int dmgOut;
		int consumption;
		int dynamicPlus;
		int apPlus;
	};

	struct STset
	{
		string name;
		// stat multipliers
		int hpd = 0;
		int spd = 0;
		int fpd = 0;
		int ATKd = 0;
		int DEFd = 0;
		int SPEEDd = 0;
		int AGId = 0;
		int DEXd = 0;
		int INTd = 0;
		int SPRd = 0;
		int STRd = 0;
		int ENDd = 0;
		int CONd = 0;

		// dmgouput
		int dmgOuput;
		int mgkMulti;
		int spMulti;
		int fpMulti;
		int dpMulti;
		int apMulti;
	};

	struct codeBasePwr
	{
		string name;
		// stat changes
		int ATKd = 0;
		int DEFd = 0;
		int SPEEDd = 0;
		int AGId = 0;
		int DEXd = 0;
		int INTd = 0;
		int SPRd = 0;
		int STRd = 0;
		int ENDd = 0;
		int CONd = 0;

		//core stat changes
		int ATK = 0;
		int DEF = 0;
		int SPEED = 0;
		int AGI = 0;
		int DEX = 0;
		int INT = 0;
		int SPR = 0;
		int STR = 0;
		int END = 0;
		int CON = 0;

		string components[3]; // these are items used in the process
		int calculationsOmega; // the time spent
		int algorithmicComplexity; // the Lv. of hack that is required to perform the hack and its success rate
		int complilationSpd; // the speed of the hack overall
		int OP; // overall PWR
	};

	int getItem();

	int getGold();

	int getEXP();

	int getSPDPlus();

	void setItem(int);

	void setGold(int);

	void setEXP(int);

	//void setTroop(Enemy d, int indx);

	// list of enemy types and methods
	//list <Enemy> enemyTroop = {};
};

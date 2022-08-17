#pragma once
#include <list>
#include <vector>
#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>
#include "Actor.h"

using namespace std;
//this is a parent class for enemies, actors and player actors
class Actor
{
private:
	static const int statusGroups = 20;
	bool leader;
public:
	Actor();
	
	void setStatbaseCall(int call, int set);
	int getStatbaseCall(int call);

	// 15 statbase
	int statbaseArr[15] =
	{
		hp,
		sp,
		fp,
		ap,
		dp,
		ATK,
		DEF,
		SPEED,
		AGI,
		DEX,
		INT,
		SPR,
		STR,
		END,
		CON
	};
	// use this ref for tasks
	int statbaseArrd[13] =
	{
		hpd, // 0
		spd,
		fpd,
		ATKd,
		DEFd,
		SPEEDd,
		AGId,
		DEXd,
		INTd,
		SPRd,
		STRd,
		ENDd,
		CONd // 12
	};

#pragma region vars
	// is this a player
	bool isPlayer = false;

	// statbase 15
	int hp = 0; // health f
	int sp = 0; // special f
	int fp = 0; // fighter (aural) f
	int ap = 0; // abiliy (optained after every level) (you'll also obtain -ap- from special items, Bosses and TurnA clashes these points are for upgrading and learning summons, magic, hacks, actions and Sts) f
	int dp = 0; // dynamic points (obtained after a Turn A clash for stat upgrading) f
		// battler statbase <- ap goes here
	int ATK = 0; // attack
	int DEF = 0; // defence (armor based)
	int SPEED = 0; // speed f
		// ability stats <- dp goes here
	int AGI = 0; // agility
	int DEX = 0; // dexterity
	int INT = 0; // intelligence
	int SPR = 0; // spirit
	int STR = 0; // strength (also effects status)
	int END = 0; // endurance (bodily based / also effects status)
	int CON = 0; // constitution (mental, body, soul, based / also effects status)

	//deductables
	int hpd = 0; // health
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
	int party_num = 6; // number of people you can have

	int num_Statuses = 0;

	// battle system 
	int turn_Num = 0; // this defines the order in the turn hierarchy later on

	// experience
	unsigned int EXP; // experience to obtain the per level ap gain
	string title;
#pragma endregion

	// just use maps for now on.

	string My_Statuses[statusGroups]{};

	// variables
	string name = ""; // YOUR NAME!
	string bio = ""; // YOUR STORY!
	

	// stat multiplier flag
	bool statmulti;
	int dummyPlus;
	int newSpd;

	enum class elementType
	{
		Water = 0,
		Fire = 1,
		Earth = 2,
		Air = 3,
		Lightning = 4,
		Phase = 5,
		Bio = 6,
		Light = 7,
		Dark = 8,
		Normal = 9
	};
	elementType d{};
	Actor(elementType h);

	elementType getElement();
	void setElement(int);

#pragma region getters
	bool getLeadRole()
	{
		return leader;
	}

	string getName()
	{
		return name;
	};

	string getTitle()
	{
		return title;
	}

	int getNumOfStates()
	{
		return num_Statuses;
	}

	int getParty_num()
	{
		return party_num;
	}

	bool getSMulti()
	{
		return statmulti;
	}

	//Hp Getter
	int getHp()
	{
		return hp;
	};

	//Sp Getter
	int getSp()
	{
		return sp;
	};

	//Fp Getter
	int getFp()
	{
		return fp;
	};

	//Ap Getter
	int getAp()
	{
		return ap;
	};

	//Dp Getter
	int getDp()
	{
		return dp;
	};

	//atk Getter
	int getAtk();

	//def Getter
	int getDEF()
	{
		return DEF;
	};

	//spd Getter
	int getSPD()
	{
		return SPEED;
	};

	//agi Getter
	int getAGI()
	{
		return AGI;
	};

	//dex Getter
	int getDEX()
	{
		return DEX;
	};

	//int Getter
	int getINT()
	{
		return INT;
	};

	//spr Getter
	int getSPR()
	{
		return SPR;
	};

	//str Getter
	int getSTR()
	{
		return STR;
	};

	//end Getter
	int getEND()
	{
		return END;
	};

	//con Getter
	int getCON()
	{
		return CON;
	};

	//get Status
	//statusEff getStatus();

	//exp Getter
	int getExp()
	{
		return EXP;
	};

#pragma endregion

	// setters / mutators

#pragma region setters

	void setLead(bool m)
	{
		leader = m;
	}

	void setNumOfStates(int n)
	{
		num_Statuses = n;
	}

	void setParty_num(int n)
	{
		party_num = n;
	}

	void setSPDplus(int m)
	{
		dummyPlus = m;
	}

	void setName(string x)
	{
		name = x;
	}

	void statMSet(bool d)
	{
		statmulti = d;
	}

	void setHp(int hpin)
	{
		hp = hpin;
	}

	void setSp(int spin)
	{
		sp = spin;
	}

	void setFp(int fpin)
	{
		fp = fpin;
	}

	void setAp(int apin)
	{
		ap = apin;
	}

	void setDp(int dpin)
	{
		dp = dpin;
	}

	void setAtk(int atin)
	{
		ATK = atin;
	}

	void setDEF(int dein)
	{
		DEF = dein;
	}

	void setSPD(int sdin)
	{
		SPEED = sdin;
	}

	void setSTR(int stin)
	{
		STR = stin;
	}

	void setAGI(int agin)
	{
		AGI = agin;
	}

	void setEND(int send)
	{
		END = send;
	}

	void setCON(int coin)
	{
		CON = coin;
	}

	void setDEX(int dexin)
	{
		DEX = dexin;
	}

	void setINT(int intIn)
	{
		INT = intIn;
	}

	void setSPR(int sprIn)
	{
		SPR = sprIn;
	}

	void setEXP(int expin, int plus)
	{
		//int eDrain = plus;

		if (statmulti == true)
		{
			EXP += expin + plus;
		}
		else
		{
			cout << "EXP multiplier gain has faded." << endl;
			EXP += expin;
			//EXP -= eDrain;
		}
	}

#pragma endregion

	// down couts

#pragma region getters
	//Hp Getter
	int getHpd()
	{
		return hpd;
	};

	//Sp Getter
	int getSpd()
	{
		return spd;
	};

	//Fp Getter
	int getFpd()
	{
		return fpd;
	};

	//atk Getter
	int getATKd()
	{
		return ATKd;
	};

	//def Getter
	int getDEFd()
	{
		return DEFd;
	};

	//spd Getter
	int getSPDd()
	{
		return SPEEDd;
	};

	//agi Getter
	int getAGId()
	{
		return AGId;
	};

	//dex Getter
	int getDEXd()
	{
		return DEXd;
	};

	//int Getter
	int getINTd()
	{
		return INTd;
	};

	//spr Getter
	int getSPRd()
	{
		return SPRd;
	};

	//str Getter
	int getSTRd()
	{
		return STRd;
	};

	//end Getter
	int getENDd()
	{
		return ENDd;
	};

	//con Getter
	int getCONd()
	{
		return CONd;
	};

	int getBGspd()
	{
		return newSpd;
	};

#pragma endregion

#pragma region setters

	void setHpd(int hpin)
	{
		hpd = hpin;
	}

	void setSpd(int spin)
	{
		spd = spin;
	}

	void setFpd(int fpin)
	{
		fpd = fpin;
	}

	void setATKd(int atin)
	{
		ATKd = atin;
	}

	void setDEFd(int dein)
	{
		DEFd = dein;
	}

	void setSPDd(int spddin)
	{
		SPEEDd = spddin;
	}

	void setSTRd(int stin)
	{
		STRd = stin;
	}

	void setAGId(int agin)
	{
		AGId = agin;
	}

	void setENDd(int send)
	{
		ENDd = send;
	}

	void setCONd(int coin)
	{
		CONd = coin;
	}

	void setDEXd(int dexin)
	{
		DEXd = dexin;
	}

	void setINTd(int intIn)
	{
		INTd = intIn;
	}

	void setSPRd(int sprIn)
	{
		SPRd = sprIn;
	}

	void setBGSpd(int spdIn);
#pragma endregion

	// functions

	void removeStates(int);
	void stateCheck();

	void statPlus(char, int);

	void setState(string);

	string getState();

	string getState2(int call);

	void printStates();

	void setTitle(string n);

	int getSPDPlus();

	bool stateIsEmpty();

	int battleGuage(int spd);

	string normalOutput(string normal)
	{
		return normal;
	};
	string getActorName()
	{
		return name;
	}
	~Actor();
};
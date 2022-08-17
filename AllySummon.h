#pragma once
#include "Actor.h"
// remember to set the exSkills, hacks, Sts and magic
class AllySummon : public Actor
{
private:

public:
	AllySummon();
	AllySummon(elementType h, string sk[], string st[], string mgk[], string hck[], string pcs[]);
	string exSkills[4]; // < -- 4 cap not five
	string exSTs[4]; // < -- 4 cap not five
	string exMagic[4]; // < -- 4 cap not five
	string exHack[4]; // < -- 4 cap not five
	string exPsichs[4];
	// that 4 slot is for hacks or a push.
	// needs to be clear
#pragma region getters

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
	~AllySummon();
};
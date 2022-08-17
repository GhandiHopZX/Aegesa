#pragma once
#include <iostream>
#include <list>
#include <string>

using namespace std;

class SpecialTech
{
public:
	SpecialTech();
	SpecialTech(string n, int scf, int fp, int ap,
		int dp, int atk, int def, int speed,
		int agi, int dex, int inte, 
		int spr, int str, int end, int con);

	string getName();
	int getSCF();
	int getFP();
	int getAP();
	int getSP();
	int getDP();
	int getATK();
	int getDEF();
	int getSPEED();
	int getAGI();
	int getDEX();
	int getINT();
	int getSPR();
	int getSTR();
	int getEND();
	int getCON();

	string returnEff();

	void setScF
	(int fp, int ap, int sp, int dp,
	int atk, int def, int speed, int agi, 
	int dex, int inte, int spr, 
	int str, int end, int con);

	void setName(string);
	void setFp(int fp);
	void setAp(int ap);
	void setSp(int sp);
	void setDp(int dp);
	void setATK(int ATK);
	void setDEF(int DEF);
	void setSPEED(int SPEED);
	void setAGI(int AGI);
	void setDEX(int DEX);
	void setINT(int INT);
	void setSPR(int SPR);
	void setSTR(int STR);
	void setEND(int END);
	void setCON(int CON);
	void popFrontEff();
	~SpecialTech();

private:
	// name 
	string name;

	// the total combined force will be given from the Battle system functions
	int scF;

	// the stat multipliers
	int fp;
	int ap;
	int sp;
	int dp;
	int ATK; // multiplier
	int DEF; // multiplier
	int	SPEED; // multiplier
	int AGI,
		DEX,
		INT,
		SPR,
		STR,
		END,
		CON;
	list<string> effList{};
};


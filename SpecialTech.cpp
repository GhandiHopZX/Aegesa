#include "SpecialTech.h"
SpecialTech::SpecialTech()
{
	this->name = "";
}

SpecialTech::SpecialTech
(string n, int scf, int fp,
	int ap, int dp, int atk,
	int def, int speed, int agi,
	int dex, int inte, int spr,
	int str, int end, int con)
{
	setName(n);
	scF += scf;
	setFp(fp);
	setAp(ap);
	setDp(dp);
	setATK(atk);
	setDEF(def);
	setSPEED(speed);
	setAGI(agi);
	setDEX(dex);
	setINT(inte);
	setSPR(spr);
	setSTR(str);
	setEND(end);
	setCON(con);

	setScF(fp,ap,sp,dp,atk,def,speed,agi,dex,inte,spr,str,end,con);
}

string SpecialTech::getName()
{
	return name;
}

int SpecialTech::getSCF()
{
	return scF;
}

int SpecialTech::getFP()
{
	return fp;
}

int SpecialTech::getAP()
{
	return ap;
}

int SpecialTech::getSP()
{
	return sp;
}

int SpecialTech::getDP()
{
	return dp;
}

int SpecialTech::getATK()
{
	return ATK;
}

int SpecialTech::getDEF()
{
	return DEF;
}

int SpecialTech::getSPEED()
{
	return SPEED;
}

int SpecialTech::getAGI()
{
	return AGI;
}

int SpecialTech::getDEX()
{
	return DEX;
}

int SpecialTech::getINT()
{
	return INT;
}

int SpecialTech::getSPR()
{
	return SPR;
}

int SpecialTech::getSTR()
{
	return STR;
}

int SpecialTech::getEND()
{
	return END;
}

int SpecialTech::getCON()
{
	return CON;
}

string SpecialTech::returnEff()
{
	return effList.front();
}

void SpecialTech::setScF
	(int fp, int ap, int sp, 
	int dp, int atk, int def,
	int speed, int agi, int dex, 
	int inte, int spr, int str,
	int end, int con)
{
	scF += fp * ap * sp * dp * atk * def * speed * agi * dex * inte * spr * str * end * con;
}

void SpecialTech::setName(string d)
{
	name = d;
}

void SpecialTech::setFp(int fp)
{
	fp = fp;
}

void SpecialTech::setAp(int ap)
{
	this->ap = ap;
}

void SpecialTech::setSp(int sp)
{
	this->sp = sp;
}

void SpecialTech::setDp(int dp)
{
	this->dp = dp;
}

void SpecialTech::setATK(int ATK)
{
	this->ATK = ATK;
}

void SpecialTech::setDEF(int DEF)
{
	this->DEF = DEF;
}

void SpecialTech::setSPEED(int SPEED)
{
	this->SPEED = SPEED;
}

void SpecialTech::setAGI(int AGI)
{
	this->AGI = AGI;
}

void SpecialTech::setDEX(int DEX)
{
	this->DEX = DEX;
}

void SpecialTech::setINT(int INT)
{
	this->INT = INT;
}

void SpecialTech::setSPR(int SPR)
{
	this->SPR = SPR;
}

void SpecialTech::setSTR(int STR)
{
	this->STR = STR;
}

void SpecialTech::setEND(int END)
{
	this->END = END;
}

void SpecialTech::setCON(int CON)
{
	this->CON = CON;
}

void SpecialTech::popFrontEff()
{
	effList.pop_front();
}

SpecialTech::~SpecialTech()
{
}
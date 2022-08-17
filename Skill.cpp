#include "Skill.h"
Skill::Skill()
{
	this->apR = 0;
	this->dmg = 0;
	this->spR = 0;
	this->totalDmg = 0;
}

Skill::Skill(string n, int apr, int dmgi, int spr, int totalD, int addMul,
	int AGI, int DEX, int INT, int SPR, int STR, int END, int CON)
{
	this->name = n;
	this->apR = apr;
	this->dmg = dmgi;
	this->spR = spr;
	statMulti( AGI, DEX, INT,  SPR,  STR,  END,  CON);
	this->totalDmg = totalD;
}

Skill::Skill(string n, int apr, int dmgi, int spr, int totalD)
{
	this->name = n;
	this->apR = apr;
	this->dmg = dmgi;
	this->spR = spr;
	this->totalDmg = totalD;
}

void Skill::statMulti(int AGI, int DEX, int INT, int SPR, int STR, int END, int CON)
{
	totalDmg += (AGI + DEX + INT + SPR + STR + END + CON) * 0.667;
}

void Skill::setDmg(int d, int spIn, int apIn)
{
	totalDmg += d + spIn + apIn;
}

void Skill::setSpR(int set)
{
	spR = set;
}

void Skill::setApR(int set)
{
	apR = set;
}

void Skill::setName(string n)
{
	name = n;
}

string Skill::getName()
{
	return name;
}

int Skill::getDmg()
{
	return totalDmg;
}

int Skill::getSpR()
{
	return spR;
}

int Skill::getApR()
{
	return apR;
}

Skill::~Skill()
{
}
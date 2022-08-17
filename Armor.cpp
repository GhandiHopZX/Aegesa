#include "armor.h"

Armor::Armor()
{
	name = "";
	hp = 0;
	sp = 0;
	fp = 0;
	atk = 0;
	def = 0;
	speed = 0;
	agi = 0;
	dex = 0;
	intel = 0;
	spr = 0;
	str = 0;
	end = 0;
	con = 0;
	value = 0;
	quantity = 0;
}

Armor::Armor(int baseInts[14], string names)
{
	name = names;
	hp = baseInts[0];
	sp = baseInts[1];
	fp = baseInts[2];
	atk = baseInts[3];
	def = baseInts[4];
	speed = baseInts[5];
	agi = baseInts[6];
	dex = baseInts[7];
	intel = baseInts[8];
	spr = baseInts[9];
	str = baseInts[10];
	end = baseInts[11];
	con = baseInts[12];
	value = baseInts[13];
	quantity = baseInts[14];
}

#pragma region baseintsGetsAnSets


int Armor::getHp()
{
	return hp;
}

int Armor::getSp()
{
	return sp;
}

int Armor::getFp()
{
	return fp;
}

int Armor::getatk()
{
	return atk;
}

int Armor::getef()
{
	return def;
}

int Armor::getspee()
{
	return speed;
}

int Armor::getagi()
{
	return agi;
}

int Armor::getdex()
{
	return dex;
}

int Armor::getintel()
{
	return intel;
}

int Armor::getspr()
{
	return spr;
}

int Armor::getstr()
{
	return str;
}

int Armor::getend()
{
	return end;
}

int Armor::getcon()
{
	return con;
}

int Armor::getval()
{
	return value;
}

void Armor::setHp(int h)
{
	hp = h;
}

void Armor::setSp(int s)
{
	sp = s;
}

void Armor::setFp(int f)
{
	fp = f;
}

void Armor::setatk(int a)
{
	atk = a;
}

void Armor::setdef(int d )
{
	def = d;
}

void Armor::setspeed(int sp)
{
	speed = sp;
}

void Armor::setagi(int ag)
{
	agi = ag;
}

void Armor::setdex(int e)
{
	dex = e;
}

void Armor::setintel(int inte)
{
	intel = inte;
}

void Armor::setspr(int sp)
{
	spr = sp;
}

void Armor::setstr(int sr)
{
	str = sr;
}

void Armor::setend(int enr)
{
	end = enr;
}

void Armor::setcon(int cone)
{
	con = cone;
}

void Armor::setval(int v)
{
	value = v;
}
#pragma endregion

Armor::~Armor()
{
}
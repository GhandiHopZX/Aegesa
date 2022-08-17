#include "Weapon.h"

Weapon::Weapon()
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

Weapon::Weapon(int baseInts[], string names)
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


int Weapon::getHp()
{
	return hp;
}

int Weapon::getSp()
{
	return sp;
}

int Weapon::getFp()
{
	return fp;
}

int Weapon::getatk()
{
	return atk;
}

int Weapon::getef()
{
	return def;
}

int Weapon::getspee()
{
	return speed;
}

int Weapon::getagi()
{
	return agi;
}

int Weapon::getdex()
{
	return dex;
}

int Weapon::getintel()
{
	return intel;
}

int Weapon::getspr()
{
	return spr;
}

int Weapon::getstr()
{
	return str;
}

int Weapon::getend()
{
	return end;
}

int Weapon::getcon()
{
	return con;
}

int Weapon::getval()
{
	return value;
}

void Weapon::setHp(int h)
{
	hp = h;
}

void Weapon::setSp(int s)
{
	sp = s;
}

void Weapon::setFp(int f)
{
	fp = f;
}

void Weapon::setatk(int a)
{
	atk = a;
}

void Weapon::setdef(int d)
{
	def = d;
}

void Weapon::setspeed(int sp)
{
	speed = sp;
}

void Weapon::setagi(int ag)
{
	agi = ag;
}

void Weapon::setdex(int e)
{
	dex = e;
}

void Weapon::setintel(int inte)
{
	intel = inte;
}

void Weapon::setspr(int sp)
{
	spr = sp;
}

void Weapon::setstr(int sr)
{
	str = sr;
}

void Weapon::setend(int enr)
{
	end = enr;
}

void Weapon::setcon(int cone)
{
	con = cone;
}

void Weapon::setval(int v)
{
	value = v;
}
#pragma endregion


Weapon::~Weapon()
{
}

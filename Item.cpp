#include "Item.h"

Item::Item()
{
	name = "";
	hpd = 0;
	spd = 0;
	fpd = 0;
	atkd = 0;
	defd = 0;
	speedd = 0;
	agid = 0;
	dexd = 0;
	inteld = 0;
	sprd = 0;
	strd = 0;
	endd = 0;
	cond = 0;
	value = 0;
	quantity = 0;
}

Item::Item(int baseInts[14], string e)
{
	name = e;
	hpd = baseInts[0];
	spd = baseInts[1];
	fpd = baseInts[2];
	atkd = baseInts[3];
	defd = baseInts[4];
	speedd = baseInts[5];
	agid = baseInts[6];
	dexd = baseInts[7];
	inteld = baseInts[8];
	sprd = baseInts[9];
	strd = baseInts[10];
	endd = baseInts[11];
	cond = baseInts[12];
	value = baseInts[13];
	quantity = baseInts[14];
}

#pragma region baseintsGetsAndSets
int Item::getHpd()
{
	return hpd;
}

int Item::getSpd()
{
	return spd;
}

int Item::getFpd()
{
	return fpd;
}

int Item::getatkd()
{
	return atkd;
}

int Item::getdefd()
{
	return defd;
}

int Item::getspeedd()
{
	return speedd;
}

int Item::getagid()
{
	return agid;
}

int Item::getdexd()
{
	return dexd;
}

int Item::getinteld()
{
	return inteld;
}

int Item::getsprd()
{
	return sprd;
}

int Item::getstrd()
{
	return strd;
}

int Item::getendd()
{
	return endd;
}

int Item::getcond()
{
	return cond;
}

int Item::getval()
{
	return value;
}

void Item::setHpd(int h)
{
	hpd = h;
}

void Item::setSpd(int s)
{
	spd = s;
}

void Item::setFpd(int f)
{
	fpd = f;
}

void Item::setatkd(int a)
{
	atkd = a;
}

void Item::setdefd(int d)
{
	defd = d;
}

void Item::setspeedd(int sp)
{
	speedd = sp;
}

void Item::setagid(int ag)
{
	agid = ag;
}

void Item::setdexd(int de)
{
	dexd = de;
}

void Item::setinteld(int inte)
{
	inteld = inte;
}

void Item::setsprd(int sp)
{
	sprd = sp;
}

void Item::setstrd(int sr)
{
	strd = sr;
}

void Item::setendd(int endr)
{
	endd = endr;
}

void Item::setcond(int conde)
{
	cond = conde;
}

void Item::setval(int v)
{
	value = v;
}
#pragma endregion

Item::~Item()
{
}
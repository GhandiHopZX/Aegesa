#include "Magic.h"
// keep in mind each spell does not expend any SP, AP, Dp or FP 
Magic::Magic()
{
	name = "";
	this->castingTime = 0;
	this->MGK = 0;
	this->runeALv = 0;
	this->runeDLv = 0;
	this->runeTLv = 0;
	this->runeVLv = 0;
	this->targetRadius = 0;
	this->enabled = true;
}

Magic::Magic(string namer, int targetR, int spd, 
	int intd, int spU, int dp, int sprd,
	int fpd, int sumDp, int sumSpd, int SPEED,
	int sumFpd, int fpEx, int dpEx, int ap,
	int beyondFp, int eventFp, string effe)
{
	name = namer;
	this->targetRadius = targetR;
	setCS(fpd, ap, spd, SPEED);
	setRAL(beyondFp, eventFp);
	setRDL(sumDp, sumSpd, sumFpd);


	setRTL(spd, intd, sprd);
	setRVL(calcSPO(spU,fpd,dp),spU,dp,fpd,spd);
	setMgkPwr();
	
	eff.push_front(effe);
	this->enabled = true;
}

int Magic::calcSPO(int spu, int fpd, int dp)
{
	return spu + fpd*dp;
}

void Magic::setName(string v)
{
	name = v;
}

void Magic::setMgkPwr()
{
	MGK = runeALv + runeDLv + runeTLv + runeVLv;
}

void Magic::setMgkPwr(int t)
{
	MGK = t;
}

int Magic::getMgkPwr()
{
	return MGK;
}

int Magic::getRTL()
{
	return runeTLv;
}

int Magic::getRVL()
{
	return runeVLv;
}

int Magic::getRDL()
{
	return runeDLv;
}

int Magic::getRAL()
{
	return runeALv;
}

int Magic::getCS()
{
	return castingTime;
}

string Magic::getEff(string m)
{
	for (std::list<string>::iterator it = eff.begin(); it != eff.end(); it++)
	{
		if (it->data() == m)
		{
			return it->data();
		}
		else
		{
			return ""; // this will get deleted which it should
		}
	}
	return "";
}

bool Magic::getEnabled()
{
	return enabled;
}

string Magic::getName()
{
	return name;
}

void Magic::setEnabled(bool d)
{
	enabled = d;
}

void Magic::setRTL(int spd, int intd, int sprd)
{
	runeTLv = spd + intd + sprd;
}

void Magic::setRVL(int spo, int spU, int dp, int fpd, int spd)
{
	spo = (spU + fpd * dp) + ((spU + fpd * dp) * 0.6);
	runeVLv = spo;
}

void Magic::setRDL(int sumdp, int sumspd, int sumfpd)
{
	runeDLv = sumdp + sumfpd + sumspd;
}

void Magic::setRAL(int bfp, int efp)
{
	runeALv = bfp * efp;
}

void Magic::setCS(int fpd, int ap, int spd, int SPEED)
{
	castingTime = static_cast<int>((fpd + ap + spd) / (SPEED * 0.6));
}

void Magic::addEff(string d)
{
	eff.push_front(d);
}

Magic::~Magic()
{
}
#include "AllySummon.h"

AllySummon::AllySummon()
{
	name = "";
	hpd = getHpd();
	spd = getSpd(); // special
	fpd = getFpd(); // fighter (aural)

	ATKd = getATKd(); // attack
	DEFd = getDEFd(); // defence (armor based)
	SPEEDd = getSPDd(); // speed

	AGId = getAGId(); // agility
	DEXd = getDEXd(); // dexterity
	INTd = getINTd(); // intelligence
	SPRd = getSPRd(); // spirit
	STRd = getSTRd(); // strength (also effects status)
	ENDd = getENDd(); // endurance (bodily based / also effects status)
	CONd = getCONd(); // constitution (mental, body, soul, based / also effects status)

	hp = 0;
	sp = 0;
	fp = 0;
	ATK = 0;
	DEF = 0;
	SPEED = 0;
	AGI = 0;
	DEX = 0;
	INT = 0;
	SPR = 0;
	STR = 0;
	END = 0;
	CON = 0;
}

AllySummon::AllySummon(elementType h, string sk[], string st[], string mgk[], string hck[], string pcs[])
{
	name = "";
	hpd = getHpd();
	spd = getSpd(); // special
	fpd = getFpd(); // fighter (aural)

	ATKd = getATKd(); // attack
	DEFd = getDEFd(); // defence (armor based)
	SPEEDd = getSPDd(); // speed

	AGId = getAGId(); // agility
	DEXd = getDEXd(); // dexterity
	INTd = getINTd(); // intelligence
	SPRd = getSPRd(); // spirit
	STRd = getSTRd(); // strength (also effects status)
	ENDd = getENDd(); // endurance (bodily based / also effects status)
	CONd = getCONd(); // constitution (mental, body, soul, based / also effects status)

	hp = 0;
	sp = 0;
	fp = 0;
	ATK = 0;
	DEF = 0;
	SPEED = 0;
	AGI = 0;
	DEX = 0;
	INT = 0;
	SPR = 0;
	STR = 0;
	END = 0;
	CON = 0;

	// 4 combat utilities
	this->exSkills[0] = sk[0];
	this->exSTs[0] = st[0];
	this->exMagic[0] = mgk[0];
	this->exHack[0] = hck[0];
	this->exPsichs[0] = pcs[0];
	this->exSkills[1] = sk[1];
	this->exSTs[1] = st[1];
	this->exMagic[1] = mgk[1];
	this->exHack[1] = hck[1];
	this->exPsichs[1] = pcs[1];
	this->exSkills[2] = sk[2];
	this->exSTs[2] = st[2];
	this->exMagic[2] = mgk[2];
	this->exHack[2] = hck[2];
	this->exPsichs[2] = pcs[2];
	this->exSkills[3] = sk[3];
	this->exSTs[3] = st[3];
	this->exMagic[3] = mgk[3];
	this->exHack[3] = hck[3];
	this->exPsichs[3] = pcs[3];

	this->d = h;
}

int AllySummon::getAtk()
{
	return ATK;
}



AllySummon::~AllySummon()
{
}
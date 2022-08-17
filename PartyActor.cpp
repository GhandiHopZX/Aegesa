#include "PartyActor.h"
#include <tuple>

PartyActor::PartyActor()
{
	bio = "";
	leader = false;
}

void PartyActor::unEquipWeapon(int num)
{
	weapons[num].atk = 0;
	weapons[num].maxhp = 0;
	weapons[num].maxsp = 0;
	weapons[num].ap = 0;
	weapons[num].fp = 0;
	weapons[num].atk = 0;
	weapons[num].def = 0;
	weapons[num].speed = 0;
	weapons[num].agi = 0;
	weapons[num].dex = 0;
	weapons[num].intel = 0;
	weapons[num].spr = 0;
	weapons[num].str = 0;
	weapons[num].end = 0;
	weapons[num].con = 0;
	weapons[num].value = 0;
	weapons[num].name = "";
	
}

void PartyActor::unEquipArmor(int num)
{
	armors[num].atk = 0;
	armors[num].maxhp = 0;
	armors[num].maxsp = 0;
	armors[num].ap = 0;
	armors[num].fp = 0;
	armors[num].atk = 0;
	armors[num].def = 0;
	armors[num].speed = 0;
	armors[num].agi = 0;
	armors[num].dex = 0;
	armors[num].intel = 0;
	armors[num].spr = 0;
	armors[num].str = 0;
	armors[num].end = 0;
	armors[num].con = 0;
	armors[num].value = 0;
	armors[num].name = "";
}

// equip weapon

// equip armor

void PartyActor::setlead(bool l)
{
	leader = l;
}

void PartyActor::statWeaponTransfer(int num, int maxhp, int ap, 
	int maxsp, int fpd, int atkd, int defd,
	int speedd, int agid, int dexd, int inteld, 
	int sprd, int strd, int endd, int cond, 
	int value, string name)
{
	weapons[num].atk    += atkd;
	weapons[num].maxhp  += maxhp;
	weapons[num].maxsp  += maxsp;
	weapons[num].ap     += ap;
	weapons[num].fp     += fpd;
	weapons[num].atk     += atkd;
	weapons[num].def     += defd;
	weapons[num].speed   += speedd;
	weapons[num].agi    += agid;
	weapons[num].dex    += dexd;
	weapons[num].intel  += inteld;
	weapons[num].spr    += sprd;
	weapons[num].str    += strd;
	weapons[num].end    += endd;
	weapons[num].con    += cond;
	weapons[num].value  += value;
	weapons[num].name   = name;
}

void PartyActor::statArmorTransfer(int num, int maxhp, 
	int ap, int maxsp, int fpd, int atkd, 
	int defd, int speedd, int agid, int dexd,
	int inteld, int sprd, int strd, int endd,
	int cond, int value, string name)
{
	armors[num].atk += atkd;
	armors[num].maxhp += maxhp;
	armors[num].maxsp += maxsp;
	armors[num].ap += ap;
	armors[num].fp += fpd;
	armors[num].atk += atkd;
	armors[num].def += defd;
	armors[num].speed += speedd;
	armors[num].agi += agid;
	armors[num].dex += dexd;
	armors[num].intel += inteld;
	armors[num].spr += sprd;
	armors[num].str += strd;
	armors[num].end += endd;
	armors[num].con += cond;
	armors[num].value += value;
	armors[num].name = name;
}

void PartyActor::itemUsageTransfer(int num)
{
	setHpd(items[num].hpd + getHpd());
	setSpd(items[num].spd + getSpd());
	setATKd(items[num].atkd + getATKd());
	setDEFd(items[num].defd + getDEFd());
	setFpd(items[num].fpd + getFpd());
	setSPDd(items[num].speedd + getSPDd());
	setAGId(items[num].agid + getAGId());
	setCONd(items[num].cond + getCONd());
	setDEXd(items[num].dexd + getDEXd());
	setENDd(items[num].endd + getENDd());
	setINTd(items[num].inteld + getINTd());
	setSTRd(items[num].strd + getSTRd());
	setSPRd(items[num].sprd + getSPRd());
	
	items[num].quantity -= 1;
}

void PartyActor::setBio(string b)
{
	bio = b;
}

bool PartyActor::getLead()
{
	return leader;
}

int PartyActor::afps(int choice)
{
	return armors[choice].fp;
}

int PartyActor::adefs(int choice)
{
	return armors[choice].def;
}

int PartyActor::aspeeds(int choice)
{
	return armors[choice].speed;
}

int PartyActor::aagis(int choice)
{
	return armors[choice].agi;
}

int PartyActor::adexs(int d)
{
	return armors[d].dex;
}

int PartyActor::aintels(int d)
{
	return armors[d].intel;
}

int PartyActor::asprs(int d)
{
	return armors[d].spr;
}

int PartyActor::astrs(int d)
{
	return armors[d].str;
}

int PartyActor::aends(int d)
{
	return armors[d].end;
}

int PartyActor::acons(int d)
{
	return armors[d].con;
}

int PartyActor::aaps(int d)
{
	return armors[d].ap;
}

int PartyActor::fps(int choice)
{
	return items[choice].fpd;
}

int PartyActor::defs(int choice)
{
	return items[choice].defd;
}

int PartyActor::speeds(int choice)
{
	return items[choice].speedd;
}

int PartyActor::agis(int choice)
{
	return items[choice].agid;
}

int PartyActor::dexs(int choice)
{
	return items[choice].dexd;
}

int PartyActor::intels(int choice)
{
	return items[choice].inteld;
}

int PartyActor::sprs(int choice)
{
	return items[choice].sprd;
}

int PartyActor::strs(int choice)
{
	return items[choice].strd;
}

int PartyActor::ends(int choice)
{
	return items[choice].endd;
}

int PartyActor::cons(int choice)
{
	return items[choice].cond;
}

int PartyActor::hps(int choice)
{
	return items[choice].hpd;
}

int PartyActor::atks(int choice)
{
	return items[choice].atkd;
}

int PartyActor::sps(int choice)
{
	return items[choice].spd;
}

int PartyActor::values(int choice)
{
	return items[choice].value;
}

string PartyActor::iname(int choice)
{
	return items[choice].name;
}

int PartyActor::quantites(int choice)
{
	return items[choice].quantity;
}

int PartyActor::whps(int choice)
{
	return weapons[choice].maxhp;
}

int PartyActor::watks(int choice)
{
	return weapons[choice].atk;
}

int PartyActor::wsps(int choice)
{
	return weapons[choice].maxsp;
}

int PartyActor::waps(int choice)
{
	return weapons[choice].ap;
}

int PartyActor::wfps(int choice)
{
	return weapons[choice].fp;
}

int PartyActor::wdef(int choice)
{
	return weapons[choice].def;
}

int PartyActor::wspeed(int choice)
{
	return weapons[choice].speed;
}

int PartyActor::wagi(int choice)
{
	return weapons[choice].agi;
}

int PartyActor::wdex(int choice)
{
	return weapons[choice].dex;
}

int PartyActor::wint(int choice)
{
	return weapons[choice].intel;
}

int PartyActor::wspr(int choice)
{
	return weapons[choice].spr;
}

int PartyActor::wstr(int choice)
{
	return weapons[choice].str;
}

int PartyActor::wend(int choice)
{
	return weapons[choice].end;
}

int PartyActor::wcon(int choice)
{
	return weapons[choice].con;
}

int PartyActor::wvalues(int choice)
{
	return weapons[choice].value;
}

string PartyActor::wname(int choice)
{
	return weapons[choice].name;
}

int PartyActor::wquantites(int choice)
{
	return weapons[choice].quantity;
}

int PartyActor::ahps(int choice)
{
	return armors[choice].maxhp;
}

int PartyActor::aatks(int choice)
{
	return armors[choice].atk;
}

int PartyActor::asps(int choice)
{
	return armors[choice].maxsp;
}

int PartyActor::avalues(int choice)
{
	return armors[choice].value;
}

string PartyActor::aname(int choice)
{
	return armors[choice].name;
}

int PartyActor::aquantites(int choice)
{
	return armors[choice].quantity;
}

int PartyActor::findWIndex(string c)
{
	for (int i = 0; i < 3; i++)
	{
		if (c == weapons[i].name)
		{
			return i;
		}
	}
	return NULL;
}

int PartyActor::findAIndex(string c)
{
	for (int i = 0; i < 3; i++)
	{
		if (c == armors[i].name)
		{
			return i;
		}
	}
	return NULL;
}

int PartyActor::findItemIndex(string c)
{
	for (int i = 0; i < 25; i++)
	{
		if (c == items[i].name)
		{
			return i;
		}
	}
	return NULL;
}

int PartyActor::FindEmptyASlot()
{
	for (int i = 0; i < 3; i++)
	{
		if (armors[i].name.empty())
		{
			return i;
		}
	}
	return NULL;
}

int PartyActor::FindEmptyISlot()
{
	for (int i = 0; i < 25; i++)
	{
		if (items[i].name.empty())
		{
			return i;
		}
	}
	return NULL;
}

int PartyActor::FindEmptyWSlot()
{
	for (int i = 0; i < 3; i++)
	{
		if (weapons[i].name.empty())
		{
			return i;
		}
	}
	return NULL;
}

string PartyActor::getBio()
{
	return bio;
}

PartyActor::~PartyActor()
{
}
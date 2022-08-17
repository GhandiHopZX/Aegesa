#include "dbRef.h"

using namespace std;

dbRef::dbRef()
{
	// not this
	/*stListInit();
	skillListInit();
	initActions();
	initSpells();
	initHacks();
	initSummons();
	initWarehouse();
	initPsy();*/

	// addons and inits work
	// like this
	Skill IlonS;
	IlonS.setName("Ilon's Slice");
	IlonS.setApR(4);
	IlonS.setSpR(2);
	skillList.emplace_front(IlonS); // add em like this
}

// todo: remember to fill up these baddie arrays

// badies 
Enemy baddiesLv3[100];
Enemy baddiesLv4[100];
Enemy baddiesLv5[100];
Enemy baddiesLv6[100];
Enemy baddiesLv7[100];
Enemy baddiesLv8[100];
Enemy baddiesLv9[100];
Enemy baddiesLv10[100];
Enemy baddiesLv11[100];
Enemy baddiesLv12[100];
Enemy randomB[100];

// stop adding shit here
#pragma region Basic array shit
AllySummon Gigalljerhorn,
Hegels_Naught, Malfesian, Aegesiar,
Yol, HakuShaku, Idola, Bahamut, Jezebel,
Chupamar, FleshWalker, AckolyteSilver,
Dolan, Sypher, KnightMare, Innana;

Action talk,
wave, cry;

Hack dDoss, fileCorruption,
unEncrypt;

Magic ikes_ecke_flare, solomons_cmd,
guidestone_invokation, rune_respell,
extol, weak_exaltation, Strong_Exaltation;

Skill stride_fire, swordDance, quickStrike,
deathlyGash, quietStab, teinkenTenSealPalm,
OccamsReduction;

SpecialTech torsionBlaze, polarJustice,
dragonFist, psionicExcursion;

Inventory outBin, outerHeaven, diamondDoggo,
thicc_memes, backyard;

Psi moto;

// initializer arrays
AllySummon arraySummons[120] =
{
	Gigalljerhorn,
	Hegels_Naught,
	Malfesian,
	Aegesiar,
	Yol, 
	HakuShaku,
	Idola, 
	Bahamut,
	Jezebel, 
	Chupamar,
	FleshWalker, 
	AckolyteSilver,
	Dolan,
	Sypher,
	KnightMare,
	Innana
};

Action arrayActions[30]
{
	talk, wave, cry
};

Magic spellArray[60] =
{
	ikes_ecke_flare, solomons_cmd, guidestone_invokation,
	rune_respell, extol, weak_exaltation, Strong_Exaltation
};

Skill skillsArray[70] =
{
	stride_fire, swordDance, quickStrike, deathlyGash,
	quietStab, teinkenTenSealPalm, OccamsReduction
};

Hack arrayHacks[30] =
{
	dDoss, fileCorruption, unEncrypt
};

SpecialTech arraySts[40] =
{
	torsionBlaze, polarJustice, dragonFist, psionicExcursion
};

Inventory arrayAllStorages[50] =
{
	outBin,
	outerHeaven,
	diamondDoggo,
	thicc_memes,
	backyard
};

Psi arrayAllPsi[100] =
{ (moto) };
#pragma endregion

// init lists Never use this again unless you're lazy af
// TODO: there's work to be done here Lots more inits

#pragma region AllySummoninit
void dbRef::initSummons()
{
	// arraySummons
	Actor::elementType h{};
	const int MIN = 1;
	const int MAX_STATIN = 20;
	const int MAX_ERAND = 15;
	int summonRand = (rand() % (MAX_ERAND - MIN + 1)) + MIN; // 1 - 15
	int statRand = (rand() % (MAX_STATIN - MIN + 1)) + MIN; // 1 - 20
	// constants
	arraySummons[0].setElement(9);
	arraySummons[0].name = "Gigalljerhorn";
	arraySummons[1].setElement(5);
	arraySummons[1].name = "Hegels Naught";
	arraySummons[2].setElement(5);
	arraySummons[2].name = "Malfesian";
	arraySummons[3].setElement(2);
	arraySummons[3].name = "Aegesiar";
	arraySummons[4].setElement(3);
	arraySummons[4].name = "Yol";
	arraySummons[5].setElement(5);
	arraySummons[5].name = "HakuShaku";
	arraySummons[6].setElement(8);
	arraySummons[6].name = "Idola";
	arraySummons[7].setElement(0);
	arraySummons[7].name = "Bahamut";
	arraySummons[8].setElement(1);
	arraySummons[8].name = "Jezebel";
	arraySummons[9].setElement(8);
	arraySummons[9].name = "Chupamar";
	arraySummons[10].setElement(8);
	arraySummons[10].name = "FleshWalker";
	arraySummons[11].setElement(4);
	arraySummons[11].name = "AckolyteSilver";
	arraySummons[12].setElement(6);
	arraySummons[12].name = "Dolan";
	arraySummons[13].setElement(0);
	arraySummons[13].name = "Sypher";
	arraySummons[14].setElement(8);
	arraySummons[14].name = "KnightMare";
	arraySummons[15].setElement(7);
	arraySummons[15].name = "Innana";

	// action Constants
	// magic Constants
	// Skill consts
	// st consts

	// everones stats
	for (int i = 0; i < 14; i++)
	{
		arraySummons[i].AGI = statRand;
		arraySummons[i].AGId = summonRand;
		arraySummons[i].ap = statRand;
		arraySummons[i].ATK = statRand;
		arraySummons[i].ATKd = summonRand;
		arraySummons[i].CON = statRand;
		arraySummons[i].CONd = summonRand;
		arraySummons[i].DEF = statRand;
		arraySummons[i].DEFd = summonRand;
		arraySummons[i].DEX = statRand;
		arraySummons[i].DEXd = summonRand;
		arraySummons[i].dp = statRand;
		arraySummons[i].END = statRand;
		arraySummons[i].ENDd = summonRand;
		arraySummons[i].fp = statRand;
		arraySummons[i].fpd = summonRand;
		arraySummons[i].hp = statRand;
		arraySummons[i].hpd = summonRand;
		arraySummons[i].INT = statRand;
		arraySummons[i].INTd = summonRand;
		arraySummons[i].sp = statRand;
		arraySummons[i].spd = statRand;
		arraySummons[i].SPEED = statRand;
		arraySummons[i].SPEEDd = summonRand;
		arraySummons[i].SPR = statRand;
		arraySummons[i].SPRd = summonRand;
		arraySummons[i].STR = statRand;
		arraySummons[i].STRd = summonRand;
	}
}
#pragma endregion
#pragma region Action init
void dbRef::initActions()
{
	arrayActions[0].setIdea("Talk");
	arrayActions[0].setDes("Conversation with a target.");
	arrayActions[0].setEff("Talkative");
	arrayActions[0].setPriority(2);
	arrayActions[0].setTargetR(1);
	arrayActions[0].setTimes(1);
	arrayActions[0].setFlag(false);

	arrayActions[1].setIdea("Wave");
	arrayActions[1].setDes("A greeting gesture..");
	arrayActions[1].setEff("Welcoming");
	arrayActions[1].setPriority(2);
	arrayActions[1].setTargetR(1);
	arrayActions[1].setTimes(1);
	arrayActions[1].setFlag(false);

	arrayActions[2].setIdea("Cry");
	arrayActions[2].setDes("An expression of misery..");
	arrayActions[2].setEff("Sadness");
	arrayActions[2].setPriority(2);
	arrayActions[2].setTargetR(1);
	arrayActions[2].setTimes(1);
	arrayActions[2].setFlag(false);
}
#pragma endregion
#pragma region Hack init
void dbRef::initHacks()
{
	arrayHacks[0].setName("dDoss");
	arrayHacks[1].setName("fileCorruption");
	arrayHacks[2].setName("unEncrypt");
}
#pragma endregion
#pragma region Magic init
void dbRef::initSpells()
{
	spellArray[0].setName("Ike's Ecke Flare");
	spellArray[0].addEff("Burning");
	spellArray[0].setEnabled(true);
	spellArray[0].setMgkPwr(10);
	spellArray[1].setName("Solomon's Command");
	spellArray[1].addEff("Subdued");
	spellArray[1].setEnabled(true);
	spellArray[1].setMgkPwr(0);
	spellArray[2].setName("Guidestone Ivokation");
	spellArray[2].addEff("");
	spellArray[2].setEnabled(true);
	spellArray[2].setMgkPwr(0);
	spellArray[3].setName("Rune Respell");
	spellArray[3].addEff("Burning");
	spellArray[3].setEnabled(true);
	spellArray[3].setMgkPwr(0);
	spellArray[4].setName("Extol");
	spellArray[4].addEff("");
	spellArray[4].setEnabled(true);
	spellArray[4].setMgkPwr(0);
	spellArray[5].setName("Weak Ealtation");
	spellArray[5].addEff("");
	spellArray[5].setEnabled(true);
	spellArray[5].setMgkPwr(0);
}
#pragma endregion
#pragma region Skills Init
void dbRef::initSkills()
{
	skillsArray[0].setName("Stride Fire");
	skillsArray[1].setName("Sword Dance");
	skillsArray[2].setName("Quick Strike");
	skillsArray[3].setName("Deathly Gash");
	skillsArray[4].setName("Quiet Stab");
	skillsArray[5].setName("Teinken Ten Seal Palm");
	skillsArray[6].setName("Occams Reduction");
}
#pragma endregion
#pragma region STs init
void dbRef::initSTs() 
{
	arraySts[0].setName("Torsion Blaze");
	arraySts[1].setName("Polar Justice");
	arraySts[2].setName("Dragon Fist");
	arraySts[3].setName("Psionic Excursion");
}
	
#pragma endregion
#pragma region Inventory Init
void dbRef::initWarehouse()
{
	arrayAllStorages[0].setName("outBin");
	arrayAllStorages[1].setName("OuterHeaven");
	arrayAllStorages[2].setName("DiamondDoggo");
	arrayAllStorages[3].setName("xXThiccMemesXx");
	arrayAllStorages[4].setName("Backyard");
}
	
#pragma endregion
#pragma region Psi init
void dbRef::initPsys()
{
	arrayAllPsi[0].setName("Moto");
}
#pragma endregion

// global ints
int dbRef::getSkillArrSize()
{
	return skillArrS;
}

int dbRef::getSummArrSize()
{
	return summArrS;
}

int dbRef::getActionArrSize()
{
	return actionArrS;
}

int dbRef::getPsiArrSize()
{
	return psiArrS;
}

int dbRef::getMagicArrSize()
{
	return spellArrS;
}

int dbRef::getHackArrSize()
{
	return hackArrS;
}

int dbRef::getSTArrSize()
{
	return stArrS;
}

int dbRef::getStorArrSize()
{
	return storArrS;
}

Action dbRef::learnActionInit(int call)
{
	return arrayActions[call];
}

AllySummon dbRef::learnSummonInit(int call)
{
	return arraySummons[call];
}

Enemy dbRef::baddieCall(int call, int l)
{
	switch (l) // level of the foes
	{
	case 3:
		return baddiesLv3[call];
	case 4:
		
		return baddiesLv4[call];
	case 5:
		
		return baddiesLv5[call];
	case 6:
		
		return baddiesLv6[call];
	case 7:
		
		return baddiesLv7[call];
	case  8:
		
		return baddiesLv8[call];
	case  9:
		
		return baddiesLv9[call];
	case 10 :
		
		return baddiesLv10[call];
	case  11:
		
		return baddiesLv11[call];
	case 12 :
		
		return baddiesLv12[call];
	default:
		return randomB[call];
	}
	return randomB[call];
}

Hack dbRef::hackCall(int call)
{
	return arrayHacks[call];
}

Magic dbRef::spellCall(int call)
{
	return spellArray[call];
}

Skill dbRef::skillCall(int call)
{
	return skillsArray[call];
}

SpecialTech dbRef::stCall(int call)
{
	return arraySts[call];
}

Inventory dbRef::containerCall(int call)
{
	return arrayAllStorages[call];
}

//searches
Psi dbRef::searchPsi(string d)
{
	dbRef::initPsy();
	for (list<Psi>::iterator fm = psiList.begin(); fm != psiList.end(); ++fm)
	{
		if (fm->getName() == d)
		{
			return fm.operator*();
		}
	}
}
void dbRef::initPsy()
{
	int im{};
	for (list<Psi>::iterator fm = psiList.begin();
		im != getPsiArrSize(); ++fm, ++im)
	{
		psiList.push_front(arrayAllPsi[im]);
	}
}

void dbRef::skillListInit()
{
	int im{};
	for (list<Skill>::iterator fm = skillList.begin();
		im != getSkillArrSize(); ++fm,++im)
	{
		skillList.push_front(skillsArray[im]);
	}
}

Skill dbRef::searchSkill(string d)
{
	skillListInit();
	for (list<Skill>::iterator fm = skillList.begin(); fm != skillList.end(); ++fm)
	{
		if (fm->getName() == d)
		{
			return fm.operator*();
		}
	}
}

void dbRef::hackListInit()
{
	int im{};
	for (list<Hack>::iterator fm = codeList.begin();
		im != getHackArrSize(); ++fm, ++im)
	{
		codeList.push_front(arrayHacks[im]);
	}
}

Hack dbRef::searchHack(string d)
{
	hackListInit();
	for (list<Hack>::iterator fm = codeList.begin(); fm != codeList.end(); ++fm)
	{
		if (fm->getName() == d)
		{
			return fm.operator*();
		}
	}
}

void dbRef::spellListInit()
{
	int im{};
	for (list<Magic>::iterator fm = spellList.begin();
		im != getMagicArrSize(); ++fm, ++im)
	{
		spellList.push_front(spellArray[im]);
	}
}

Magic dbRef::searchMagic(string d)
{
	spellListInit();
	for (list<Magic>::iterator fm = spellList.begin(); fm != spellList.end(); ++fm)
	{
		if (fm->getName() == d)
		{
			return fm.operator*();
		}
	}
}

SpecialTech dbRef::searchST(string d)
{
	stListInit();
	for (list<SpecialTech>::iterator fm = stList.begin(); fm != stList.end(); ++fm)
	{
		if (fm->getName() == d)
		{
			return fm.operator*();
		}
	}
}

void dbRef::stListInit()
{
	int im{};
	for (list<SpecialTech>::iterator fm = stList.begin();
		im != getStorArrSize(); ++fm, ++im)
	{
		stList.push_front(arraySts[im]);
	}
}

Inventory dbRef::searchInv(string d)
{
	containerListInit();
	for (list<Inventory>::iterator fm = invList.begin(); fm != invList.end(); ++fm)
	{
		if (fm->getName() == d)
		{
			return fm.operator*();
		}
	}
}

void dbRef::containerListInit()
{
	int im{};
	for (list<Inventory>::iterator fm = invList.begin();
		im != getMagicArrSize(); ++fm, ++im)
	{
		invList.push_front(arrayAllStorages[im]);
	}
}

Action dbRef::searchAction(string d)
{
	containerListInit();
	for (list<Action>::iterator fm = actionList.begin(); fm != actionList.end(); ++fm)
	{
		if (fm->getIdea() == d)
		{
			return fm.operator*();
		}
	}
	return actionList.front();
}

void dbRef::actionListInit()
{
	int im{};
	for (list<Action>::iterator fm = actionList.begin();
		im != getActionArrSize(); ++fm, ++im)
	{
		actionList.push_front(arrayActions[im]);
	}
}

#pragma region allArmors
Inventory::armor composite_bodymesh;
Inventory::armor composite_semiconductors;
Inventory::armor composite_fiberwear;
Inventory::armor composite_overplates;

Inventory::armor allDefaultArmors[] =
{
	composite_bodymesh,
	composite_fiberwear,
	composite_overplates,
	composite_semiconductors
};
#pragma endregion

dbRef::~dbRef()
{
}
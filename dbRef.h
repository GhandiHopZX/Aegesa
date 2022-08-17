#pragma once
#include <iostream>
#include <list>
#include <string>
#include <tuple>
#include "Action.h"
#include "AllySummon.h"
#include "Enemy.h"
#include "Hack.h"
#include "Magic.h"
#include "Skill.h"
#include "SpecialTech.h"
#include "Inventory.h"

using namespace std;

class dbRef
{
public:

	dbRef();

	int getSkillArrSize();

	int getSummArrSize();

	int getActionArrSize();

	int getMagicArrSize();

	int getHackArrSize();

	int getSTArrSize();

	int getPsiArrSize();

	int getStorArrSize();

	void initSummons();
	void initActions();
	void initHacks();
	void initSpells();
	void initSkills();
	void initSTs();
	void initWarehouse();
	void initPsys();
	Psi searchPsi(string d);
	void initPsy();

	Action learnActionInit(int call);
	AllySummon learnSummonInit(int call);
	Enemy baddieCall(int call, int level);
	Hack hackCall(int call);
	Magic spellCall(int call);
	Skill skillCall(int call);
	SpecialTech stCall(int call);
	Inventory containerCall(int call);
	void hackListInit();
	Hack searchHack(string h);
	void spellListInit();
	Magic searchMagic(string);
	void skillListInit();
	SpecialTech searchST(string);
	void stListInit();
	Inventory searchInv(string);
	void containerListInit();
	Action searchAction(string);
	void actionListInit();

	Skill searchSkill(string d);

	~dbRef();

private:
	// don't change any
	int skillArrS = 70; 
	int summArrS = 120;
	int actionArrS = 30;
	int spellArrS = 60;
	int hackArrS = 30;
	int stArrS = 40;
	int storArrS = 50;
	int psiArrS = 100;

	// lists

	// init for skill list
	list<Skill> skillList;

	list<AllySummon> summonList;

	list<Action> actionList;

	list<Magic> spellList;

	list<Hack> codeList;

	list<SpecialTech> stList;

	list<Inventory> invList;

	list<Psi> psiList;
};
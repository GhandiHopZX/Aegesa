#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <stack>
#include <stdlib.h>
#include <malloc.h>
#include "Actor.h"
#include "Enemy.h"

using namespace std;
string oneForEachlvl[] = 
{
"Pyronaught",  "Boltinaught",
"Spectranaught", "Hypernaught", "Kyronaught",
"Voltranaught", "Miranaught", "Floranaught",
"Bionaught", "Rubinaught", "Emranaught",
};

Enemy::Enemy()
{
	elementType();
	goldA = 0;
	expA = 0;
	itemN = 0;
	leader = false;
	party_num = 4;
	bio = "";
	title = "";
	isPlayer = false;

	name = "";
	//this->allEffGet;
	this->battleGuage(NULL);
	this->dummyPlus = 0;
	this->getAGI();
	this->getAp();
	this->getAtk();
	this->getCON();
	this->getDEF();
	this->getDEX();
	this->getDp();
	this->getEND();
	this->getEXP();
	this->Enemy::getExp();
	this->getSPDPlus();
	this->getINT();
	this->getHp();
	this->getSp();
	this->getSPD();
	this->getFp();
	this->getSPR();
}

Enemy::Enemy(string namer, elementType h, int expAw, int gA, int item)
{
	name = namer;
	expA = expAw;
	goldA = gA;
	itemN = item;
	this->d = h;
	isPlayer = false;
}

Enemy Enemy::enemyRandEncounterI()
{
	// lv1 constants
#pragma region Lvl. 1
	string enemyNameI;

	const int MAX_ERAND = 13;
	const int MAX_GOLD = 1100;
	const int MAX_ITEM = 14;
	const int MAX_STATN = 10;
	const int MAX_HP = 120;
	const int MAX_SP = 23;

	const int MIN = 1;
	const int GOLD_MIN = 100;

	const string lvl1names[14] =
	{ "Mongrel", "Rancor", "Mandrake", "Dynanaught",
		"Gorgon Eye", "Jackal", "Golem", "Worm", "Pci Eater",
	"Temptest", "Mecha Recon", "Harpy", "Leech", "Gorigami" };

	int enemyRand = (rand() % (MAX_ERAND - MIN + 1)) + MIN; // 1 - 13
	int goldRand = (rand() % (MAX_GOLD - GOLD_MIN + 1)) + GOLD_MIN; // 100 - 1100
	int itemRand = (rand() % (MAX_ITEM - MIN + 1)) + MIN; // 1 - 14
	int statRand = (rand() % (MAX_STATN - MIN + 1)) + MIN; // 1 - 10
	int hpRand = (rand() % (MAX_HP - MIN + 1)) + MIN;
	int spRand = (rand() % (MAX_SP - MIN + 1)) + MIN;


	enemyNameI = lvl1names[enemyRand];
	Enemy Randlvl1(enemyNameI, elementType::Normal, enemyRand, goldRand, itemRand);

#pragma region statslv1

	Randlvl1.setHp(hpRand);
	Randlvl1.setSp(spRand);
	Randlvl1.setAp(statRand);
	Randlvl1.setFp(statRand);
	Randlvl1.setDp(0);

	Randlvl1.setHpd(hpRand);
	Randlvl1.setSpd(spRand);
	Randlvl1.setFpd(statRand);

	Randlvl1.setAGI(statRand);
	Randlvl1.setSTR(statRand);
	Randlvl1.setEND(statRand);
	Randlvl1.setCON(statRand);
	Randlvl1.setSPR(statRand);
	Randlvl1.setINT(statRand);
	Randlvl1.setDEX(statRand);

	Randlvl1.setAtk(statRand);
	Randlvl1.setSPD(statRand);
	Randlvl1.setDEF(statRand);

	Randlvl1.setAGId(statRand);
	Randlvl1.setSTRd(statRand);
	Randlvl1.setENDd(statRand);
	Randlvl1.setCONd(statRand);
	Randlvl1.setSPRd(statRand);
	Randlvl1.setINTd(statRand);
	Randlvl1.setDEXd(statRand);

	Randlvl1.setATKd(statRand);
	Randlvl1.setSPDd(statRand);
	Randlvl1.setDEFd(statRand);
#pragma endregion
	
#pragma endregion

	return Randlvl1;
}

Enemy Enemy::enemyRandEncounterII()
{
	// lv2 constants

#pragma region Lv.2
	string enemyNameII;

	const int MAX_ERAND2 = 13;
	const int MAX_GOLD2 = 2400;
	const int MAX_ITEM2 = 22;
	const int MAX_STATN2 = 18;
	const int MAX_HP2 = 248;
	const int MAX_SP2 = 50;

	const int MIN2 = 8;
	const int GOLD_MIN2 = 400;

	const string lvl2names[25] =
	{ "DynaDom", "Ryotan", "Yuki", "Tolemy",
		"Ghoul", "Vlask", "Wyrm", "Anaconda", "RT-Rex",
	"Hydronaught", "Ginko Lizard"};

	int enemyRand2 = (rand() % (MAX_ERAND2 - MIN2 + 1)) + MIN2; // 8 - 13
	int goldRand2 = (rand() % (MAX_GOLD2 - GOLD_MIN2 + 1)) + GOLD_MIN2; // 400 - 2400
	int itemRand2 = (rand() % (MAX_ITEM2 - MIN2 + 1)) + MIN2; // 8 - 22
	int statRand2 = (rand() % (MAX_STATN2 - MIN2 + 1)) + MIN2; // 8 - 18
	int hpRand2 = (rand() % (MAX_HP2 - MIN2 + 1)) + MIN2; // 8 - 248 
	int spRand2 = (rand() % (MAX_SP2 - MIN2 + 1)) + MIN2; // 8 - 50

	enemyNameII = lvl2names[enemyRand2];
	Enemy Randlvl2(enemyNameII, elementType::Water, enemyRand2, goldRand2, itemRand2);
#pragma region statslv2

	Randlvl2.setHp(hpRand2);
	Randlvl2.setSp(spRand2);
	Randlvl2.setAp(statRand2);
	Randlvl2.setFp(statRand2);
	Randlvl2.setDp(0);
		   
	Randlvl2.setHpd(hpRand2);
	Randlvl2.setSpd(spRand2);
	Randlvl2.setFpd(statRand2);
		   
	Randlvl2.setAGI(statRand2);
	Randlvl2.setSTR(statRand2);
	Randlvl2.setEND(statRand2);
	Randlvl2.setCON(statRand2);
	Randlvl2.setSPR(statRand2);
	Randlvl2.setINT(statRand2);
	Randlvl2.setDEX(statRand2);
		   
	Randlvl2.setAtk(statRand2);
	Randlvl2.setSPD(statRand2);
	Randlvl2.setDEF(statRand2);
		   
	Randlvl2.setAGId(statRand2);
	Randlvl2.setSTRd(statRand2);
	Randlvl2.setENDd(statRand2);
	Randlvl2.setCONd(statRand2);
	Randlvl2.setSPRd(statRand2);
	Randlvl2.setINTd(statRand2);
	Randlvl2.setDEXd(statRand2);
		   					
	Randlvl2.setATKd(statRand2);
	Randlvl2.setSPDd(statRand2);
	Randlvl2.setDEFd(statRand2);
#pragma endregion
#pragma endregion

	return Randlvl2;
}

Enemy Enemy::BossCall(int call)
{
	const int MAX_BOSS = 12;

	// call 0 for tha boss
	//lv 1 Bosses
	Enemy MorphQueen("MorphQueen", elementType::Phase, 160, 400, 2);
	Enemy GiggaRaugght("GiggaRaugght", elementType::Normal, 2000 /*if you manage to beat him*/, 15000, 12);

	Enemy lvl1index[MAX_BOSS] =
	{
		MorphQueen,
		GiggaRaugght
	};

#pragma region MQBossStats
	MorphQueen.setAtk(20);
	MorphQueen.setDEF(13);
	MorphQueen.setSPD(10);

	MorphQueen.setSPR(14);
	MorphQueen.setAGI(9);
	MorphQueen.setCON(15);
	MorphQueen.setINT(24);
	MorphQueen.setEND(20);
	MorphQueen.setDEX(10);
	MorphQueen.setSTR(15);

	MorphQueen.setDp(0);
	MorphQueen.setFp(20);
	MorphQueen.setAp(10);
	MorphQueen.setSp(300);
	MorphQueen.setHp(250);
#pragma endregion

#pragma region GRBossStats
	GiggaRaugght.setAtk(500);
	GiggaRaugght.setDEF(430);
	GiggaRaugght.setSPD(100);

	GiggaRaugght.setSPR(140);
	GiggaRaugght.setAGI(90);
	GiggaRaugght.setCON(150);
	GiggaRaugght.setINT(240);
	GiggaRaugght.setEND(200);
	GiggaRaugght.setDEX(100);
	GiggaRaugght.setSTR(150);

	GiggaRaugght.setDp(0);
	GiggaRaugght.setFp(200);
	GiggaRaugght.setAp(100);
	GiggaRaugght.setSp(3000);
	GiggaRaugght.setHp(2500);
	GiggaRaugght.setTitle("THE GIGGANTRION");
#pragma endregion

	return lvl1index[call];
}

int Enemy::getItem()
{
	return itemN;
}

int Enemy::getGold()
{
	return goldA;
}

int Enemy::getEXP()
{
	return expA;
}

int Enemy::getSPDPlus()
{
	return dummyPlus;
}

void Enemy::setItem(int rei)
{
	itemN += rei;
}

void Enemy::setGold(int reg)
{
	goldA += reg;
}

void Enemy::setEXP(int rexp)
{
	expA = rexp;
}
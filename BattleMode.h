#pragma once
#include "PartyActor.h"//
#include "Enemy.h"//
#include "AllySummon.h"//
#include "BattleMode.h"//
#include "ArrayList.h"//
#include "Inventory.h"//
#include "Action.h"//
#include "Hack.h"//
#include "SpecialTech.h"//
#include "Skill.h"//
#include "Magic.h"//
#include "Psi.h"
#include "dbRef.h"//
#include <list>
#include <iostream>
#include <algorithm>
#include <vector>
#include <filesystem>
#include <fstream>
#include <cstdlib>

class BattleMode
{
private:
	

	struct StatusEffect
	{
		string name; // name of effect
		int sbReduction[15]; //how many statuses will be effected
		int call; // calling the array sbRedux
		int duration; // how many turns or travel paces it lasts
		bool type; // true = pos eff, false = neg eff
	};

	struct Battler
	{
		string name = "";

		// whose team the battler's on.
		int team = 0;

		// statbase
		int statbaseDArr[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		int statbaseArr[15] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

		// strings of states
		string states[20] = { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };

		/* armor reference
		int maxhp = 0; // 0
		int maxsp = 0; // 1
		int fp = 0; // 2
		int ap = 0;// 3
		int atk = 0; //4
		int def = 0; //5
		int speed = 0; //6
		int agi = 0; // 7
		int dex = 0; // 8
		int intel = 0; // 9
		int spr = 0; // 10
		int str = 0; // 11
		int end = 0; //12
		int con = 0; //13
		int value = 0; //14
		int quantity = 0; //15
		*/

		// Weapons (16 stats including gold value)
		string wepNames[3] = { "", "", "" };
		int wepstatAdd[15][3] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,{0,0,0} };

		// Armors (16 stats including gold value)
		string armorNames[3];
		int armstatAdd[15][3]{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,{0,0,0} };

		// keep these objects below strings:
		// 
		// Skills
		string skillBase[20] = { "","","", "", "", "", "", "", "", "", "", "", "", "", "","","", "", "", "" };
		// STs
		string Stbase[20]{ "","","", "", "", "", "", "", "", "", "", "", "", "", "","","", "", "", "" };
		// Actions
		string ActonBase[20]{ "","","", "", "", "", "", "", "", "", "", "", "", "", "","","", "", "", "" };
		// Hacks
		string CodeBase[20]{ "","","", "", "", "", "", "", "", "", "", "", "", "", "","","", "", "", "" };
		// Summons
		string SummonBase[20] = { "","","", "", "", "", "", "", "", "", "", "", "", "", "","","", "", "", "" };
		// Magic
		string MagicBase[20] = { "","","", "", "", "", "", "", "", "", "", "", "", "", "","","", "", "", "" };

		// statBase reference
		/* battler stats
		{
		hp, 0
		sp, 1
		fp, 2
		ATK, 3
		DEF, 4
		SPEED, 5
		AGI, 6
		DEX, 7
		INT, 8
		SPR, 9
		STR, 10
		END, 11
		CON 12
		GOLD 13
		};
		*/
		// 1 - 3 weak 50%, moderate 67%, strong 72%
		// 1 = .5
		// 2 = .67
		// 3 = .72
		float defFlag;
		float actionFlag;
		float magicFlag;
		float escapeFlag;
		float stFlag;
		float skillFlag;
		float attackFlag;
		float summonFlag;
		float hackFlag;
	};
	enum class TaskType
	{
		Attack, // weapon + armor and base stat damage combo /
		Defend, // damage reduction /
		Act, // interface with enemies, allies, area and events /
		Hack, // Discombobulate the inner workings of your victim /
		Skill, // Skills = armor + weapon + base stat damage + effects + critmultiplier /
		ST, // Special Techniques /
		Summon, // deploy robots, call pets, summon Geists or Beckon Vulcanite /
		Magic, // cast some magical shit /
		Items, // consumables and mcguffins /
		Customize, // change gear /
		Escape // Chance roll. Run from the fight /
	};
	struct Task
	{
		/// Make sure you input the rune data before you cast any magic
		/// Same with hacking executions
		int db_choice = 0; // picks the skill, action, ST..etc in its array
		int targetRange = 0; // 0 = single, 1 = multi, 2 = AOE
		TaskType decision = TaskType::Attack;// What are you doing? Attacking? Defending?
		char Tc = 'k'; // letter = Tasktype abbreviated for the ActionBase
		list<Battler> actorR; // Player Target(s) <- leave this alone in mind
		list<Battler> enemyR; // Enemy target(s) <- leave this alone /
		Battler singleTarget;
		list<Battler> multiTarget;
		Battler selfTarget;
		int isTask = 1; // 1 for yes 0 for no //default is 1
		/// <summary>
		/// team 1 + is good 
		/// team 0 is bad
		/// anything else is another faction or enemy
		///</summary>
		/// <param name="team_num"></param>
		/// <returns></returns>
		int team_num = NULL;
		string message= "";
	};

	Inventory invento;

	// variables
	bool battleTime; // if its time to fight
	bool* aGuage;
	int turn_Number = 0;

	// DC = damage calculation 
	// clash auto calculates dmg
	enum t
	{
		cl = 0, // clash
		T1P = 1, // turn 1 player
		TC = 2, // turn check
		ET = 3, // enemy turn
		TCII = 4, // turn check
		DCU = 5,  // DC update reset/determine turn
		MUL = 6, // multiturn
		END = 7 // call rewards and end the battle
	}; //turn number
	// this moves the phase forward
	t operator++(int n);

	// current number of members
	int numMembers = 0;
	int numEnemies = 0;
	int multiTurns = 0;

	// party members
	list<PartyActor> Wp = {};

	list<PartyActor> Wpcpy = {};

	list<PartyActor> WPF = {};

	// one per combattant
	// ally summons 
	list<AllySummon> Pet = {};
	// enemy summons
	list<AllySummon> badPet = {};

	// enemies
	list<Enemy> troop = {};

	list<Enemy> troopF = {};

	list<Enemy> troopcpy = {};

	// BattlerArray
	Battler AllBattlers[14];
	Battler AllBattlersF[14]; // using this as a secondary for enemies
	list<int>SpdArr = {}; // then this one then turnmode 2
	list<int>SpdArrD = {}; // check for highest 1
	list<int>SpdArrCpy = {};
	list<Battler> AllBattlersList{};

public: 
	
	BattleMode();

	BattleMode(PartyActor crew[], Enemy badies[], Inventory invent, bool* ag, bool battle);
	
	// public vars

	list<Battler> MbL = {}; // Multiple battlers List
	list<Task> TaskBase = {}; // set of actions(Tasks) ready to pop off
	list<string> HOT = {}; // Hierarchy of turns 

	// objects
	Inventory playerStuff; // cpy of invent
	dbRef cDatabase;

	// total numberofBattlers
	int allBattlers = static_cast<int>(AllBattlersList.size());

	~BattleMode();

	Inventory::item Items(Task);

	// commands
	void Escape(Battler, int aiC); //
	void Attack(Battler g, int aiC);
	void Defend(Battler, int aiC); //
	void ItemMenu(Battler, int aiC); //
	void Skillo(Battler, int aiC);
	void Summono(Battler, int aiC);
	void STo(Battler, int aiC);
	void Hacko(Battler, int aiC);
	void Actiono(Battler, int aiC);
	void Psio(Battler, int aiC);
	
	void ChangeItems(Battler, int aiC);
	void ChangeArmors(Battler, int aiC);
	void ChangeWeapons(Battler, int aiC);
	

	// class reliant cmds // Battler In question and Target Task
	void EscapeC(Battler, Task); //
	void AttackC(Battler, Task); //
	void DefendC(Battler, Task); //
	void HackC(Battler, Task); // 
	void SummonC(Task); // task only
	void STC(Battler, Task); //
	void SkillC(Battler, Task); //
	void ActionC(Battler, Task); //
	void MagicC(Battler, Task); //
	void PsiC(Battler, Task);
	void ItemC(Battler,Task);
	void ChangeArmr(Battler, Task);
	void ChangeWeps(Battler, Task);
	void ChangeItms(Battler, Task);

	//functions
	double randCalc();
	// this is a function variant
	Task newTask(char);
	Task newTaskAI(int);

	// find Battler
	Battler findBattler(string name);
	
	// call victory
	void victoryDet(Task);

	// this actualy works call it once...
	void initializer(PartyActor load[], Enemy tr[]);

	// call test
	void test_Transfer_CallII(PartyActor Scop[], Enemy Ecop[], int m, int e);

	// battle mode switch
	void phaseTrigger(BattleMode::t f);

	// The basic one of them all
	void ActionIN(Task); // a task that will be carried out by way of placing one in

	void ForcedActionIN(Task forced[]); // in an effect or something that can't be interrupted

	void MultiActionIN(Task tsl[]); // actions that combine in one line all at once

	void turnOrderSetto(PartyActor p[], Enemy e[], int countp, int counte);

	// battle system functions - Phase one Calculations
	// party lead is what is taken in
	void victorDeterminant(Battler);

	// enemy count
	BattleMode::Task gatherThisBattlersEnemies(Battler d);

	// this is for hp determination support 
	int gatherAllEnemyHpds(Task target);

	// this is for battle sys support / use the
	// task parameter to determine which team
	// you're trying to escape from
	int gatherAllEnemySpds(Battler, Task);
	// escape or fail
	bool determineEscape();
	// hit or miss // this can be used for many things
	bool determineHit(Battler, Task); 
	// defense rating
	int defRating(Battler, Task);
	// item execution returns values 
	// to whatever actor selected
	// use the parameter to determine 
	// the right container
	// for the right party
	void itemReturnValue(Battler, Task);
	// hack success
	void hackDotExe(Battler, Task);
	// summon add // use the battler 
	// param to mark the summon's masta
	void addSummonB(Battler, Task);
	// Special Technique rating
	void specialTechPwr(Battler, Task);
	// Skill rating
	void skillPwr(Battler, Task);
	// Action effect
	void actionEff(Battler, Task);
	// Magic rating
	void magicEff(Battler, Task);
	// adc
	auto attackDMGCALC(BattleMode::Battler h);
	void executeTaskMulti();
	//TODO
	//###############  FIRST PHASE  ################// this is the first phase TC
	

	//TODO
	//%%%%% 2ND PHASE %%%%%// hackers, magicians and fighters... yep 
	// SKILL, MGK, HCK PSY, SUMM

	//TODO
	// determining status effects 3rd

	//TODO
	// Phase LAST
	//========// Phases of Calculation //=========// Phase 4
	// execution
	void executeTask(); // execute tha tasks from the bottom

	// for resetting the speed lists
	void ReOrderSettto(); 
	// run this then TurnCheckII
	void TurnCheck();
	// run this then ReOrderSetto
	void TurnCheckII();
	BattleMode::Task newTask(char ip, Battler d);
	// turn Call: this starts a turn
	void turnCallPVP();
	void playerturnCall(Battler);
	// halt execution until all multi-turns are counted
	// multiturnCalculation - > calculate; update any data and delete out the mBL here
	void multiturnCalc();

	// ai turn
	void aiTurn();
	void aiTurn(Battler);

	char determineAiAction(char choice, int ailv);
	
	// multi turn
	void multiTurnCall();

	// Battle system Numerics

	// this updates an enemy after a battler turn has gone
	void UpdateAT(Battler); 
	void UpdateALL();

	void reset(); // checks the speed lists
	// and if they're both clear then 
	//the main enemy and Player lists 
	// will clear the old battler list 
	// then make a new battler list.

	void hpCheck(); // this checks after every damage calc or hp change
	// for any hp 0.

	void clashMode();

	void afterBattleUpdate();

	// find the maximum array of tasks...
	int FindTaskArrMax(Task p[]);

	const char intToChar(int arrIn[]);

	// End Battle return functions
	Inventory::armor armorRw(int);
	Inventory::weapon weaponRw(int);
	Inventory::item itemRw(int);
	int expRw();

};
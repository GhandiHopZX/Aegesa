#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <chrono>
#include <thread>
#include <map>
#include <algorithm>
#include <fstream>
#include "World.h"
// battle system stuff
#include "stateEffects.h"
#include "Enemy.h"
#include "aegesa.h"
#include "Player_Actor.h"
#include "inventory.h"
#include "battleSystem.h"

using namespace std;

// full party GLOBALS
Player_Actor Actor1; // Proper instantiation
Player_Actor Alicia; //
Player_Actor Renae; //
Player_Actor Iyn; //
inventory mainInventory; //
stateEffects st;

//HashTableSet anyHash; // magic hash of many things
//						// List aggregation stuff

World::World()
{
	mao = 0; // int posx = 0;
	tse = 0; // int posy = 0;
	tung = 0; // int posz = 0;

	//set time

	StartTime();
	// file load for play_time goes here
	// "                     "
	play_time += StartTime(); //every time the world is loaded =) also playtime contains the file_data

	mapN maps[5] =
	{
		lostCity[5][0][0],
		darkForest[5][0][0],
		eikka[5][0][0],
		rheTan[5][0][0],
		aegesaShrine[5][0][0]
	};
}

void World::beginningStory()
{
	// init
	ItemType dummy;
	dummy.initItems();
	//system("COLOR e4"); // shop color
	system("COLOR 09");
	system("CLS");

	string nameIn = "k";
	string bioIn = "";

	// What's Your Name?

	cout << "What's Your Name?: " << endl;
	cin >> nameIn;
	Actor1.setName(nameIn);
	cout << endl;

	// What's Your Story?
	cout << "What's Your Story?: " << endl;
	Actor1.setBio(bioIn);
	cin >> bioIn;

	cout << endl;

#pragma region Actor1_SetStats

	Actor1.setATK(5);
	Actor1.setAGI(1);
	Actor1.setSPD(3);
	Actor1.setDEF(2);
	Actor1.setSTR(2);
	Actor1.setDEX(2);
	Actor1.setSPR(1);
	Actor1.setCON(4);
	Actor1.setEND(2);
	Actor1.setINT(7);

	Actor1.setHp(15);
	Actor1.setSp(250);
	Actor1.setFp(2);

	Actor1.setATKd(1);
	Actor1.setAGId(1);
	Actor1.setSPDd(3);
	Actor1.setDEFd(1);
	Actor1.setSPRd(1);
	Actor1.setSTRd(1);
	Actor1.setDEXd(1);
	Actor1.setCONd(1);
	Actor1.setENDd(1);
	Actor1.setINTd(1);

	Actor1.setHpd(12);
	Actor1.setSpd(15);
	Actor1.setFpd(1);

	Actor1.setAp(5);
	Actor1.setDp(0); // always set these defaulted to 0

	// weapon eq
	ItemType Basic_Injector;

#pragma region Basic_Injector_Setup
	Basic_Injector.setStatBank(13, 1);
	Basic_Injector.setStatBank(4, 5);
	Basic_Injector.setStatBank(11, 1);
	Basic_Injector.setStatBank(5, 1);
	Basic_Injector.setStatBank(7, 1);
	Basic_Injector.setStatBank(10, 1);
	Basic_Injector.setStatBank(14, 10);
	Basic_Injector.setStatBank(8, 3);
	Basic_Injector.setName("Basic_Injector");
	Basic_Injector.setStatBank(15, 1);
	Basic_Injector.setStatBank(6, 1);
	Basic_Injector.setStatBank(9, 1);
	Basic_Injector.setStatBank(11, 1);
	Basic_Injector.setStatBank(16, 1);
	Basic_Injector.setStatBank(17, true);
	Basic_Injector.setStatBank(18, false);
	Basic_Injector.setStatBank(19, false);

#pragma endregion

#pragma endregion

#pragma region Alicia_SetStats
	Alicia.setName("Alicia");
	Alicia.setBio("Lost class 3 Android unit. Locked Away for 10 years, now follows you in your journey for the AType upgrade to save her friend..");
	Alicia.setATK(6);
	Alicia.setSPD(8);
	Alicia.setAGI(7);
	Alicia.setDEF(4);
	Alicia.setSTR(10);
	Alicia.setDEX(12);
	Alicia.setCON(7);
	Alicia.setEND(5);
	Alicia.setSPR(1);
	Alicia.setINT(6);

	Alicia.setHp(15);
	Alicia.setSp(155);
	Alicia.setFp(5);

	Alicia.setATKd(6);
	Alicia.setAGId(7);
	Alicia.setSPDd(8);
	Alicia.setDEFd(4);
	Alicia.setSTRd(10);
	Alicia.setDEXd(12);
	Alicia.setCONd(7);
	Alicia.setENDd(5);
	Alicia.setSPRd(1);
	Alicia.setINTd(6);

	Alicia.setHpd(15);
	Alicia.setSpd(150);
	Alicia.setFpd(5);

	Alicia.setAp(5);
	Alicia.setDp(0); // always set these defaulted to 0

	ItemType Gold_Dragon_Claws;
	ItemType Kommodo_Chestplate;
	ItemType Kommodo_Leggings;
	ItemType Kommodo_Palm_Soles;

#pragma region GoldDClaws
	Gold_Dragon_Claws.setStatBank(13, 1);
	Gold_Dragon_Claws.setStatBank(4, 5);
	Gold_Dragon_Claws.setStatBank(11, 1);
	Gold_Dragon_Claws.setStatBank(5, 1);
	Gold_Dragon_Claws.setStatBank(7, 1);
	Gold_Dragon_Claws.setStatBank(10, 1);
	Gold_Dragon_Claws.setStatBank(14, 10);
	Gold_Dragon_Claws.setStatBank(8, 3);
	Gold_Dragon_Claws.setName("Gold_Dragon_Claws");
	Gold_Dragon_Claws.setStatBank(15, 1);
	Gold_Dragon_Claws.setStatBank(6, 1);
	Gold_Dragon_Claws.setStatBank(9, 1);
	Gold_Dragon_Claws.setStatBank(11, 1);
	Gold_Dragon_Claws.setStatBank(16, false);
	Gold_Dragon_Claws.setStatBank(17, true);
	Gold_Dragon_Claws.setStatBank(18, false);
#pragma endregion

#pragma region Kommodo_Chestplate
	Kommodo_Chestplate.setStatBank(13, 1);
	Kommodo_Chestplate.setStatBank(4, 5);
	Kommodo_Chestplate.setStatBank(11, 1);
	Kommodo_Chestplate.setStatBank(5, 1);
	Kommodo_Chestplate.setStatBank(7, 1);
	Kommodo_Chestplate.setStatBank(10, 1);
	Kommodo_Chestplate.setStatBank(14, 10);
	Kommodo_Chestplate.setStatBank(8, 3);
	Kommodo_Chestplate.setName("Kommodo_Chestplate");
	Kommodo_Chestplate.setStatBank(15, 1);
	Kommodo_Chestplate.setStatBank(6, 1);
	Kommodo_Chestplate.setStatBank(9, 1);
	Kommodo_Chestplate.setStatBank(11, 1);
	Kommodo_Chestplate.setStatBank(16, false);
	Kommodo_Chestplate.setStatBank(17, false);
	Kommodo_Chestplate.setStatBank(18, true);
#pragma endregion

#pragma region Kommodo_Leggings
	Kommodo_Leggings.setStatBank(13, 1);
	Kommodo_Leggings.setStatBank(4, 5);
	Kommodo_Leggings.setStatBank(11, 1);
	Kommodo_Leggings.setStatBank(5, 1);
	Kommodo_Leggings.setStatBank(7, 1);
	Kommodo_Leggings.setStatBank(10, 1);
	Kommodo_Leggings.setStatBank(14, 10);
	Kommodo_Leggings.setStatBank(8, 3);
	Kommodo_Leggings.setName("Kommodo_Leggings");
	Kommodo_Leggings.setStatBank(15, 1);
	Kommodo_Leggings.setStatBank(6, 1);
	Kommodo_Leggings.setStatBank(9, 1);
	Kommodo_Leggings.setStatBank(11, 1);
	Kommodo_Leggings.setStatBank(16, false);
	Kommodo_Leggings.setStatBank(17, false);
	Kommodo_Leggings.setStatBank(18, true);
#pragma endregion

#pragma region Kommodo_Palm_Soles
	Kommodo_Palm_Soles.setStatBank(13, 1);
	Kommodo_Palm_Soles.setStatBank(4, 5);
	Kommodo_Palm_Soles.setStatBank(11, 1);
	Kommodo_Palm_Soles.setStatBank(5, 1);
	Kommodo_Palm_Soles.setStatBank(7, 1);
	Kommodo_Palm_Soles.setStatBank(10, 1);
	Kommodo_Palm_Soles.setStatBank(14, 10);
	Kommodo_Palm_Soles.setStatBank(8, 3);
	Kommodo_Palm_Soles.setName("Kommodo_Palm_Soles");
	Kommodo_Palm_Soles.setStatBank(15, 1);
	Kommodo_Palm_Soles.setStatBank(6, 1);
	Kommodo_Palm_Soles.setStatBank(9, 1);
	Kommodo_Palm_Soles.setStatBank(11, 1);
	Kommodo_Palm_Soles.setStatBank(16, false);
	Kommodo_Palm_Soles.setStatBank(17, false);
	Kommodo_Palm_Soles.setStatBank(18, true);
#pragma endregion

#pragma endregion

#pragma region opening setting
	// location name set
	maps->name = "Lost City";

	system("COLOR 07");
	dialougeAction(Actor1, "Wakes up");
	cout << Actor1.getName() + ": " + "Huhhh..." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "damn..." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "Where am I" << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "how.." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "How did I survive?" << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "Shit... I hope he doesn't find me. Wherever here is.." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "Huh... Hmmmn.." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "This opening above me.." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "It feels.." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "good..." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "Weird.." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "WAIT!" << endl;
	cin.get();
	dialouge(Actor1, "I wana see if I can find that light I just saw...");
	dialouge(Actor1, "I wana see if if its even real.");
	dialougeAction(Actor1, "Looks up");
	dialouge(Actor1, "No way....");
	dialougeAction(Actor1, "Jolts from the cold now heated air...");
	dialougeAction(Actor1, "Sees the now visible white clad figure.");
	dialougeAction(Alicia, "Figure steps in from the darkness..");
	dialouge(Alicia, "Aegesa... Type.");
	dialouge(Actor1, "W... what..? What are you talking about?");
	dialouge(Alicia, "Aegesa Type.. ARE YOU COGNIZANT OF YOUR ENVIRONMENT?");
	dialouge(Actor1, "cogni.. of what?.. What are you talking about?");
	dialouge(Alicia, "You are aware of your surroundings are you not?");
	dialouge(Actor1, "No I'm stupid... Sorry. Not very cognizant of anything at the moment...");
	dialouge(Alicia, "Your genetic template says your a savant compared to the average...");
	dialouge(Actor1, "So you're another one of those hackers AREN'T YOU!?");
	dialouge(Alicia, "I am not sure of what argument this pertains to..");
	dialouge(Actor1, "You talk like a robot... Are you that then?");
	dialougeAction(Alicia, "FLASH");
	dialougeAction(Alicia, "POSE");
	dialouge(Alicia, "I am a CLASS III GUARDIAN TIER ANDROID!");
	dialouge(Alicia, "I have searched for a compatable Aegesa type. Suitable for both combat and architectural assembly..");
	dialouge(Actor1, "Whoa that means you're.. No kidding you're the real deal!");
	dialouge(Alicia, "What are you referencing?");
	dialouge(Actor1, "Ok You're from the machine itself huh?");
	dialouge(Alicia, "I'm from the Crown City...");
	dialouge(Actor1, "......");
	dialouge(Alicia, "I know it may seem hard to believe but I am not what you may hypothesize...");
	dialouge(Actor1, "I don't even know what you're talking about..");
	dialouge(Alicia, "....");
	dialouge(Actor1, "If you came from some make believe world that hasn't existed before on the world maps then tell me where it is!");
	dialouge(Alicia, "Alright then..");
	dialouge(Alicia, "I'll show you where it is. If you help me find my friend..");
	dialouge(Actor1, "I'm not too sure I should even really trust you to go with you to any place...");

	// party insert

	//playerParty[partySize] = this also needs to be a list
	//{ with lots of functions
	//Actor1,
	//Alicia
	//};
	//

	// from now on change this if you want to see anykind of numeric
	// or datatype change or like I said just make it a list

	changePartySize(2);
	addPartyMember(0, Actor1);
	addPartyMember(1, Alicia);
	playerParty[0].setLead(true);

	// gear setup

	playerParty[1].setWeapon(0, Gold_Dragon_Claws);
	playerParty[1].setArmor(0, Kommodo_Chestplate);
	playerParty[1].setArmor(1, Kommodo_Leggings);
	playerParty[1].setArmor(2, Kommodo_Palm_Soles);

	playerParty[0].setWeapon(0, Basic_Injector);

	//mainInventory.

	mainInventory.rewardCall("AEGESA FRAGMENT", 1);

	system("CLS");
	cout << "-----======= ALICIA HAS JOINED YOUR PARTY ======-----" << endl;
	lineStop();
#pragma endregion

	//end of chapter 0

	chapter1();
}

void World::chapter1()
{
	int i = 0;
	// menu time
	menu();

	//end of chapter
	chapter2();
}

void World::chapter2()
{
	//end of chapter
	chapter3();
}

void World::chapter3()
{
	//end of chapter
	chapter4();
}

void World::chapter4()
{
	//end of chapter
	chapter5();
}

void World::chapter5()
{
	//end of chapter
	//endGame(); call this when you beat the game
	lineStop();
}

void World::gameOver()
{
	cout << "GAME OVER" << endl;
}

void World::endGame()
{
	cout << "Will you dream again?" << endl;
	// end of game? =)
	// lineStop(); use this outside of the function.
}

//Enemy Encounter call ins
// call the battle system stuff

// celluar world navigation.
// with a map ;)

void World::menu()
{
	system("CLS");
	char choice = {};
	navigation();

	cout << "\nPlease select an option....\n (i) Inventory,\n (n) Navigation,\n (p) Party,\n (d) Save/Load,\n (o) Options\n" << endl;
	cin >> choice;
	switch (choice)
	{
	case 'i':
	case 'item':
		inventory();
		break;

	case 'n':
	case 'navi':
		navigation(location, mao, tse, tung);
		break;

	case 'p':
	case 'part':
		// array calls can be used alone without needing to use brackets
		partyMenu(playerParty);
		break;

	case 'd':
	case 'data':
		//
		//dataCall();
		gameOver();
		lineStop();
		break;

	case 'o':
	case 'opti':
		optionMenuCall();
		break;

	default:
		cout << "Invalid Choice" << endl;
		menu();
		break;
	}
}

void World::inventory()
{
	mainInventory.PlayerItemInventory(playerParty);
	menu();
}

void World::navigation()
{
	cout << "Current Location: " << maps[location].name << endl;
}

void World::gameLoop(int mx, int my, int mz, mapN m, int location, Player_Actor party[])
{
	switch (mEVTriggerActive())
	{
	case true:
		switch (m.name.at(0))
		{
		case 'L':
			//"Lost City"
			evRandomizer(party, m, mx, my, mz);
			break;
		case 'D':
			//"Dark Forest"
			break;
		case 'E':
			//"Eikka"
			break;
		case 'R':
			//"RheTan"
			break;

		case 'A':
			//"Aegesa Shrine"
			break;

		default:
			break;
		}
		break;

	case false:
		break;
	}
}

// work on this
void World::evRandomizer(Player_Actor party[], mapN location, int mx, int my, int mz)
{
	const int MAX_EVRAND = 450;
	unsigned int evRand = (rand() % (MAX_EVRAND - MIN + 1)) + MIN;

	//battle processing and dot giving
	for (int i = 0; i < partySize; i++)
	{
		if ((party[i].My_Statuses[i].at(0) == 'D') && party[i].isPlayer == true)
		{
			// game over
		}
		else if (!(party[i].My_Statuses[i].at(0) == 'D') && party[i].isPlayer == true) // check for in_party npcs and dead ppl
		{
			eventCalls(location, mEVTriggerActive(), evRand);
		}
		else
		{
			eventCalls(location, mEVTriggerActive(), evRand);
		}
		//party[i];
	}

	party->isPlayer;
}

// k
void World::partyMenu(Player_Actor party[])
{
	char choice2 = ' ';
	string scin = " ";

	system("CLS");
	cout << "Current Party" << endl;
	cout << "" << endl;

	int party_ppl = party->getParty_num();

	// print menu
	for (int i = 0; i < party_ppl; i++)
	{
		cout << party[i].getName() << ": " << '\n' << "HP" << ": " << '\t' << party[i].getHpd() << '/' << party[i].getHp();
		cout << '\n' << "SP" << ": " << '\t' << party[i].getSpd() << '/' << party[i].getSp() << endl;

		if (!party[i].stateIsEmpty())
		{
		}

		else
		{
			cout << "[::state(s)::]" << endl;
			for (size_t f = 0; f < party[f].getNumOfStates(); f++)
			{
				party[f].printStates();
				//cout << "[" << << " " << "]" << endl;
			}

			cout << endl;
		}
	}

	scin = "\0";
	cout << "Please select an option....\n (s) Status,\n (e) Equip,\n (sa) SkillActions,\n (t) ClassTree \n";
	cin >> scin;

	choice2 = choiceIn(scin);

	switch (choice2)
	{
	case 's':
		// select party member
		// status for member
		statusCall(playerParty);
		lineStop();
		menu();
		break;

	case 'e':
		// select party member
		// equip items

		mainInventory.EquipItemSelect(playerParty);
		menu();
		break;

	case 'sa':
		// select party member
		// skill set
		menu();
		break;

	case 't':
		// select party member
		// class tree
		menu();
		break;

	default:
		cout << "Invalid choice..." << endl;
		menu();
		break;
	}
}

void World::eventCalls(World::mapN local, bool trigger, int evNCall)
{
	switch (mEVTriggerActive())
	{
	case true:
		switch (local.name.at(0))
		{
		case 'L':
			//"Lost City"
			eventTypeNamesLV1[evNCall];
			break;
		case 'D':
			//"Dark Forest"
			break;
		case 'E':
			//"Eikka"
			break;
		case 'R':
			//"RheTan"
			break;

		case 'A':
			//"Aegesa Shrine"
			break;

		default:
			break;
		}
		break;

	case false:
		break;
	}
}

void World::dataCall() {}

void World::optionMenuCall() {}

// Statuses
void World::statusCall(Player_Actor p[])
{
	int partyNum = p->getParty_num();
	int choice = 0;

	cout << "Status for ?" << endl;

	for (int i = 0; i < partyNum; i++)
	{
		// for the ones to choose
		cout << p[i].getName() << endl;
		cout << endl;
	}

	cout << "Select Member... " << "0 - " << partyNum - 1 << endl;

	cin >> choice;

	system("CLS");

	while (choice < 0 || choice > partyNum)
	{
		cout << "Invalid selection. Reselect...";
		cin >> choice;
		break;
	}

	if (choice <= partyNum)
	{
		int max_Weps = 2;

		int max_Armors = 3;

		int i = 0;

		ItemType a;
		ItemType w;

		cout << p[choice].getName() << endl;

		cout << "States" << endl;
		p[choice].printStates();

		cout << endl;

		// addup armors
		for (int i = 0; i < max_Armors; i++)
		{
			a.setStatBank(5,  a.getStatBank(5) + p[choice].getArmorEQ2(i).getStatBank(5));
			a.setStatBank(6,  a.getStatBank(6) + p[choice].getArmorEQ2(i).getStatBank(6));
			a.setStatBank(7,  a.getStatBank(7) + p[choice].getArmorEQ2(i).getStatBank(7));
			a.setStatBank(14, a.getStatBank(14) + p[choice].getArmorEQ2(i).getStatBank(14));
			a.setStatBank(8,  a.getStatBank(8) + p[choice].getArmorEQ2(i).getStatBank(8));
			a.setStatBank(9,  a.getStatBank(9) + p[choice].getArmorEQ2(i).getStatBank(9));
			a.setStatBank(10, a.getStatBank(10) + p[choice].getArmorEQ2(i).getStatBank(10));
			a.setStatBank(13, a.getStatBank(13) + p[choice].getArmorEQ2(i).getStatBank(13));
			a.setStatBank(11, a.getStatBank(11) + p[choice].getArmorEQ2(i).getStatBank(11));
			a.setStatBank(12, a.getStatBank(12)  + p[choice].getArmorEQ2(i).getStatBank(12));
		}
		// addup weapons
		for (int i = 0; i < max_Weps; i++)
		{
			w.setStatBank(5, a.getStatBank(5) + p[choice].getArmorEQ2(i).getStatBank(5));
			w.setStatBank(6, a.getStatBank(6) + p[choice].getArmorEQ2(i).getStatBank(6));
			w.setStatBank(7, a.getStatBank(7) + p[choice].getArmorEQ2(i).getStatBank(7));
			w.setStatBank(14, a.getStatBank(14) + p[choice].getArmorEQ2(i).getStatBank(14));
			w.setStatBank(8, a.getStatBank(8) + p[choice].getArmorEQ2(i).getStatBank(8));
			w.setStatBank(9, a.getStatBank(9) + p[choice].getArmorEQ2(i).getStatBank(9));
			w.setStatBank(10, a.getStatBank(10) + p[choice].getArmorEQ2(i).getStatBank(10));
			w.setStatBank(13, a.getStatBank(13) + p[choice].getArmorEQ2(i).getStatBank(13));
			w.setStatBank(11, a.getStatBank(11) + p[choice].getArmorEQ2(i).getStatBank(11));
			w.setStatBank(12, a.getStatBank(6) + p[choice].getArmorEQ2(i).getStatBank(12));
		}

		cout << "HP: " << p[choice].getHpd() << "/" << p[choice].getHp() << endl;
		cout << "SP: " << p[choice].getSpd() << "/" << p[choice].getSp() << endl;
		cout << "FP: " << p[choice].getFpd() << "/" << p[choice].getFp() << endl;
		cout << "AP: " << p[choice].getAp() << endl;
		cout << "DP: " << p[choice].getDp() << endl << endl;

		cout << "ATK: " << p[choice].getATKd() << "/" << p[choice].getATK() + a.getStatBank(5)  + w.getStatBank(5) << endl;
		cout << "DEF: " << p[choice].getDEFd() << "/" << p[choice].getDEF() + a.getStatBank(6) + w.getStatBank(6) << endl;
		cout << "SPD: " << p[choice].getSPDd() << "/" << p[choice].getSPD() + a.getStatBank(7) + w.getStatBank(7) << endl;
		cout << "AGI: " << p[choice].getAGId() << "/" << p[choice].getAGI() + a.getStatBank(14) + w.getStatBank(14) << endl;
		cout << "DEX: " << p[choice].getDEXd() << "/" << p[choice].getDEX() + a.getStatBank(8) + w.getStatBank(8) << endl;
		cout << "INT: " << p[choice].getINTd() << "/" << p[choice].getINT() + a.getStatBank(9) + w.getStatBank(9) << endl;
		cout << "SPR: " << p[choice].getSPRd() << "/" << p[choice].getSPR() + a.getStatBank(10) + w.getStatBank(10) << endl;
		cout << "STR: " << p[choice].getSTRd() << "/" << p[choice].getSTR() + a.getStatBank(13) + w.getStatBank(13) << endl;
		cout << "END: " << p[choice].getENDd() << "/" << p[choice].getEND() + a.getStatBank(11) + w.getStatBank(11) << endl;
		cout << "CON: " << p[choice].getCONd() << "/" << p[choice].getCON() + a.getStatBank(12) + w.getStatBank(12) << endl;

		switch (p[choice].getLeadRole())
		{
		case true:
			cout << "Leader" << endl;
			break;

		case false:
			cout << "Not Leader" << endl;
			break;
		}

		cout << endl;

		cout << "OK?" << endl;
	}
	lineStop();
}

void World::dialouge(Player_Actor pn, string in)
{
	cout << pn.getName() + ": " + in << endl;
	lineStop();
}

void World::dialougeAction(Player_Actor pn, string in)
{
	cout << pn.getName() + ": " + "*" + " " + in + "*" << endl;
	lineStop();
}

string World::dialougeInput(string pvalue)
{
	getline(cin, pvalue);
	pvalue.erase(remove(pvalue.begin(), pvalue.end(), '\n'), pvalue.end());
	return pvalue;
}

void World::navigation(int selectedMap, int x, int y, int z)
{
	system("CLS");
	// maps

	// n = north, ne = northeast, nw = northwest,
	// sw = southwest, s = south, se = southeast
	// w = west, e = east
	// z = floor
	// these are for changing the coodinates to each floor
	int xC = 0;
	int yC = 0;
	int zC = 0;

	whereAmI(selectedMap, x, y, z);

	cout << "\nWhere will you go?\n (n)north,\n"
		<< "(e)east,\n (w)west,\n (s)south,\n (1)northeast,\n"
		<< "(2)northwest,\n (3)southeast,\n (4)southwest,\n (q)nowhere\n" << endl;

	char dir = {};
	cin >> dir;
	switch (dir)
	{
	case 'n':
		maps[selectedMap].y += 1;
		tse = maps[selectedMap].y;
		// event randomizer
		//mEVTriggerSetter(true);

		whereAmI(selectedMap, x, y, z);
		menu();
		break;
	case '1':
		maps[selectedMap].y += 1;
		tse = maps[selectedMap].y;
		maps[selectedMap].x += 1;
		mao = maps[selectedMap].x;
		// event randomizer
		//mEVTriggerSetter(true);
		whereAmI(selectedMap, x, y, z);
		menu();
		break;
	case '2':
		maps[selectedMap].y += 1;
		maps[selectedMap].x -= 1;
		tse = maps[selectedMap].y;
		mao = maps[selectedMap].x;
		// event randomizer
		//mEVTriggerSetter(true);
		whereAmI(selectedMap, x, y, z);
		menu();
		break;
	case 's':
		maps[selectedMap].y -= 1;
		tse = maps[selectedMap].y;
		// event randomizer
		//mEVTriggerSetter(true);
		whereAmI(selectedMap, x, y, z);
		menu();
		break;
	case '3':
		maps[selectedMap].y -= 1;
		maps[selectedMap].x += 1;
		tse = maps[selectedMap].y;
		mao = maps[selectedMap].x;
		// event randomizer
		//mEVTriggerSetter(true);
		whereAmI(selectedMap, x, y, z);
		menu();
		break;
	case '4':
		maps[selectedMap].y -= 1;
		maps[selectedMap].x -= 1;
		tse = maps[selectedMap].y;
		mao = maps[selectedMap].x;
		// event randomizer
		//mEVTriggerSetter(true);
		whereAmI(selectedMap, x, y, z);
		menu();
		break;
	case 'w':
		maps[selectedMap].x -= 1;
		mao = maps[selectedMap].x;
		// event randomizer
		//mEVTriggerSetter(true);
		whereAmI(selectedMap, x, y, z);
		menu();
		break;
	case 'e':
		maps[selectedMap].x += 1;
		mao = maps[selectedMap].x;
		// event randomizer
		//mEVTriggerSetter(true);
		whereAmI(selectedMap, x, y, z);
		menu();
		break;

	case 'q':
		menu();
		break;

	default:
		cout << "not a direction or command" << endl;
		whereAmI(selectedMap, x, y, z);
		menu();
		break;
	}

	switch (z)
	{
	case (1):
		z++;
		break;

	case (-1):
		z--;
		break;
	default:
		maps[selectedMap].z = z;
		tung = maps[selectedMap].z;
		break;
	}
}

void World::whereAmI(int selectedMap, int x, int y, int z)
{
	cout << "\nCurrent Location:" << endl;
	cout << "AT: " << maps[selectedMap].name << endl;
	cout << "row: " << maps[selectedMap].x << endl;
	cout << "column: " << maps[selectedMap].y << endl;
	cout << "floor: " << maps[selectedMap].z << endl;
}

char World::choiceIn(string choiceBuffer)
{
	//string choiceBuffer;
	char choice = NULL;
	//cin >> choice;
	char* choiceWritable = new char[choiceBuffer.size() + 1];

	copy(choiceBuffer.begin(), choiceBuffer.end(), choiceWritable);

	choiceWritable[choiceBuffer.size()] = '\0';

	char* choice3 = choiceWritable;

	char& choice4 = *choice3;

	choice = choice4;

	delete[] choiceWritable;

	return choice;
}

// this thing eats the string that comes after every
// 'ENTER' press so the system doesn't poop out too much at once...
// don't use this for anything but text dialouge unless you know what you're doing.
string World::lineStop()
{
	string pvalue;
	getline(cin, pvalue);
	pvalue.erase();
	return pvalue;
}

void World::StopTime()
{
	std::this_thread::yield();
}

long World::StartTime()
{
	long copy = 0;
	auto playtime = std::chrono::high_resolution_clock::now; // you might need to convert this into a long or some kind of type that can be saved and stored for later use
	//copy = static_cast<long>(playtime);
	return copy;
}

void World::mEVTriggerSetter(bool mEVT)
{
	movedEVTrigger = mEVT;
}

int World::getPartySize()
{
	return playerParty->getParty_num();
}

bool World::mEVTriggerActive()
{
	return movedEVTrigger;
}

string World::tokenChangerAdd(int partyNum, int place, string name, stateEffects t)
{
	string happened = "";

	for (int i = 0; i < 20; i++)
	{
		// does this buff/de exist?
		if (name != t.allEffGet[i])
		{
			// pointer
			string* me{};

			me = &t.allEffGet[i];

			t.add_state(place, true, me);
		}
		else if (i > 20)
		{
			cout << "State Type does not exist..." << endl;
			break;
		}
		else
		{
			t.allEffGet[i] = name;
			happened = name;
			return name;
			break;
		}
	}
	currentPartyStates[partyNum].insert(pair<int, stateEffects>(place, t));
	happened = playerParty[partyNum].getName() + " is " + t.buffName;
	return happened;
}

string World::tokenChangerRem(int partyNum, int place, string name, stateEffects t)
{
	auto& cell = currentPartyStates[partyNum];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++)
	{
		if (bItr->first == place)
		{
			keyExists = true;
			t.remove_state(place, true);
			bItr = cell.erase(bItr);
			cout << "[INFO] state removed." << endl;
			break;
		}
	}

	if (!keyExists)
	{
		cout << "[WARNING] state not found. PAIR NOT REMOVED." << endl;
	}

	string hap = playerParty[partyNum].getName() + " is free of " + t.buffName;

	return hap;
}

void World::tokenChecker(int partyNum, stateEffects t)
{
	auto& cell = currentPartyStates[partyNum];
	auto bItr = begin(cell);
	int steff = t.turns_Of_aff;
	int m = bItr->first;

	for (; bItr != end(cell); bItr++)
	{
		switch (steff)
		{
		case 0:
			tokenChangerRem(partyNum, m, t.buffName, t);
			break;

		default:
			if (steff <= 0)
			{
				m = bItr->first;
				tokenChangerRem(partyNum, m, t.buffName, t);
			}
			else
			{
				cout << playerParty[partyNum].getName() << "Has affliction of " << t.buffName;
			}
			break;
		}
	}
}

void World::tokenNegate(int wholeParty, stateEffects x)
{
}

void World::changePartySize(int isIn)
{
	playerParty->setParty_num(isIn);
}

void World::addPartyMember(int m, Player_Actor in)
{
	playerParty[m].setName(in.getName());
	playerParty[m].setBio(in.getBio());

	playerParty[m].setAGI(in.getAGI());
	playerParty[m].setAGId(in.getAGId());
	playerParty[m].setSTR(in.getSTR());
	playerParty[m].setSTRd(in.getSTRd());
	playerParty[m].setSPR(in.getSPR());
	playerParty[m].setSPRd(in.getSPRd());
	playerParty[m].setAp(in.getAp());
	playerParty[m].setATK(in.getATK());
	playerParty[m].setATKd(in.getATKd());
	playerParty[m].setCON(in.getCON());
	playerParty[m].setCONd(in.getCONd());
	playerParty[m].setBGSpd(in.getBGspd());
	playerParty[m].setDEF(in.getDEFd());
	playerParty[m].setDEFd(in.getDEFd());
	playerParty[m].setDEX(in.getDEX());
	playerParty[m].setDEXd(in.getDEXd());
	playerParty[m].setEND(in.getEND());
	playerParty[m].setENDd(in.getENDd());
	playerParty[m].setSPD(in.getSPD());
	playerParty[m].setSPDd(in.getSPDd());
	playerParty[m].setFp(in.getFp());
	playerParty[m].setFpd(in.getFpd());
	playerParty[m].setDp(in.getDp());
	playerParty[m].setINT(in.getINT());
	playerParty[m].setINTd(in.getINTd());
	playerParty[m].setSp(in.getSp());
	playerParty[m].setHp(in.getHp());
	playerParty[m].setHpd(in.getHpd());
	playerParty[m].setSpd(in.getSpd());
	playerParty[m].setState("NORMAL");
	playerParty[m].setTitle(in.getTitle());
}

void World::removePartyMember(int m, Player_Actor out, string deleteCall)
{
	int negation = 1;
	int partyNum = playerParty[m].getParty_num();
	const int sPartyNum = 6;
	fstream outFile;
	Player_Actor arr[sPartyNum];

	deleteCall = out.getName();

	for (int i = 0; i < partyNum; i++)
	{
		if (playerParty[i].getName() == deleteCall)
		{
			// overrite the one before the last with the last

			// save its data here
			outFile.open("/" + deleteCall + ".dat", ios::out, ios::trunc);
			if (!outFile)
			{
				return;
			}
			else
			{
				outFile.write(deleteCall.c_str(), playerParty[i].getAGI());
				outFile.write(deleteCall.c_str(), playerParty[i].getAGId());
				outFile.write(deleteCall.c_str(), playerParty[i].getAp());
				outFile.write(deleteCall.c_str(), playerParty[i].getATK());
				outFile.write(deleteCall.c_str(), playerParty[i].getATKd());
				outFile.write(deleteCall.c_str(), playerParty[i].getBGspd());
				outFile.write(deleteCall.c_str(), playerParty[i].getBio().size());
				outFile.write(deleteCall.c_str(), playerParty[i].getCON());
				outFile.write(deleteCall.c_str(), playerParty[i].getCONd());
				outFile.write(deleteCall.c_str(), playerParty[i].getDEF());
				outFile.write(deleteCall.c_str(), playerParty[i].getDEFd());
				outFile.write(deleteCall.c_str(), playerParty[i].getDEX());
				outFile.write(deleteCall.c_str(), playerParty[i].getDEXd());
				outFile.write(deleteCall.c_str(), playerParty[i].getDp());
				outFile.write(deleteCall.c_str(), playerParty[i].getEND());
				outFile.write(deleteCall.c_str(), playerParty[i].getENDd());
				outFile.write(deleteCall.c_str(), playerParty[i].getExp());
				outFile.write(deleteCall.c_str(), playerParty[i].getFp());
				outFile.write(deleteCall.c_str(), playerParty[i].getFpd());
				outFile.write(deleteCall.c_str(), playerParty[i].getHp());
				outFile.write(deleteCall.c_str(), playerParty[i].getHpd());
				outFile.write(deleteCall.c_str(), playerParty[i].getINT());
				outFile.write(deleteCall.c_str(), playerParty[i].getINTd());
				outFile.write(deleteCall.c_str(), playerParty[i].getName().size());
				outFile.write(deleteCall.c_str(), playerParty[i].getParty_num());
				outFile.write(deleteCall.c_str(), playerParty[i].getSMulti());
				outFile.write(deleteCall.c_str(), playerParty[i].getSp());
				outFile.write(deleteCall.c_str(), playerParty[i].getSPD());
				outFile.write(deleteCall.c_str(), playerParty[i].getSpd());
				outFile.write(deleteCall.c_str(), playerParty[i].getSPDd());
				outFile.write(deleteCall.c_str(), playerParty[i].getSPDPlus());
				outFile.write(deleteCall.c_str(), playerParty[i].getSPR());
				outFile.write(deleteCall.c_str(), playerParty[i].getSPRd());
				outFile.write(deleteCall.c_str(), playerParty[i].getState().size());
				outFile.write(deleteCall.c_str(), playerParty[i].getSTR());
				outFile.write(deleteCall.c_str(), playerParty[i].getSTRd());
			}
			outFile.close();
		}

		// deletion
		if (playerParty[m].getName() == deleteCall)
		{
			playerParty[m].setParty_num(partyNum - negation);
		}

		if (playerParty[i].getName() != deleteCall)
		{
			// save party into a object array
			arr[i] = playerParty[i];
		}
	}

	// restoration
	for (int i = 0; i < partyNum; i++)
	{
		playerParty[i] = arr[i];
	}
}

//templates;
template <class ArmorOut>
ArmorOut setArmor(int y, ArmorOut d, Player_Actor a)
{
	a.mActorArmorE[y] = d;
	cout << "armor " << d.name << "equipped" << endl;
}

template <class WeaponOut>
WeaponOut setWeapon(int y, WeaponOut d, Player_Actor a)
{
	a.mActorWeaponE[y] = d;
	cout << "weapon " << d.name << "equipped" << endl;
}

World::~World()
{
	StopTime(); // use this outside of this constructor for any game shutdown.
}
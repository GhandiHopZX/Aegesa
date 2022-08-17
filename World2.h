#pragma once
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <ctime>
#include <unordered_set>
#include <chrono>
#include "aegesa.h"
#include "Player_Actor.h"
#include "Enemy.h"
#include "stateEffects.h"

class World // this is the mainline story for Code AnEx AEGESA
{
	// this game has up to 5 chapters...
	// I know shocking!!!
	// but its a prequel to a story I haven't fully written yet.
	// sorry for the bad storytelling if that's your thing....

private:

	//keep this for state effects above map structs
	map<int, stateEffects> currentPartyStates[6];

	// Hub worlds that have cellular navigation
	// for now we only have ch 0 - 5 to cover the lost city arc
	// and that's it for now.
	// this is the lost city player pos and map
	struct mapN
	{
		int x = 0;
		int y = 0;
		int z = 0;
		string name;
	};

	int mao = 0;
	int tse = 0;
	int tung = 0;
	long play_time = 0;
	int location = 0; // 0 lostCity, 1 darkForest, 2 ekana, 3 rheTan, 4 aegesaShrine...
	const int MIN = 1;
	const int MAX_STATES = 20;
	const static int partySize = 6;
	const static int ePartySize = 4;
	bool movedEVTrigger;

	mapN lostCity[11][11][4];
	mapN darkForest[11][11][2];
	mapN eikka[11][11][1];
	mapN rheTan[11][11][1];
	mapN aegesaShrine[11][11][5];

public:
	World();

	mapN maps[5] =
	{
		lostCity[5][0][0],
		darkForest[5][0][0],
		eikka[5][0][0],
		rheTan[5][0][0],
		aegesaShrine[5][0][0]
	};

	string eventTypeNamesLV1[40]
	{
		"Yokai Attack",
		"Cyber Ghosts",
		"", // quest
		"Wild Monsters"
	};

	string stateTokenC[20]
	{
		"REGENERATION",
		"POISON",
		"STUNED",
		"DEAD",
		"HACKED",
		"CRIPPLE",
		"INEBREATED",
		"SLEEP",
		"CURSEDVSDARK",
		"CURSRDVSLIGHT",
		"CURSEDVSDEMONIC",
		"CURSED",
		"ANGER"
	};

	// setters/mutators

	void beginningStory(); //Awaken Marko(or Player one)
	void chapter1(); //RE-BIRTH
	void chapter2(); //Shattered and Hollow
	void chapter3(); //Green Gold
	void chapter4(); //Renae's Secret/Lost Civilization
	void chapter5(); //Alicia's Verdict

	void gameOver(); // obvious
	void endGame(); // game end

	// menu stuff
	void menu();

	// menu calls
	void inventory();

	void navigation();

	void partyMenu();

	void dataCall();

	void optionMenuCall();

	// submenu calls
	void statusCall(Player_Actor p[]);

	//Main game loop: 1. main menu, 2. when move, 3. randomizer or => 4. if theres a story ev that engages. 5. back to top
	void gameLoop(int mx, int my, int mz, mapN m, int location, Player_Actor party[]);

	void evRandomizer(Player_Actor party[], mapN location, int mx, int my, int mz); // location is for mob levels

	void partyMenu(Player_Actor party[]);

	void eventCalls(World::mapN local, bool trigger, int);

	void dialouge(Player_Actor pn, string in);

	void dialougeAction(Player_Actor pn, string in);

	string dialougeInput(string pvalue);

	void navigation(int selectedMap, int m, int c, int e);

	void whereAmI(int selectedMap, int x, int y, int z);

	char choiceIn(string);

	string lineStop();

	void StopTime();

	long StartTime();

	void mEVTriggerSetter(bool);

	// getters/accessors
	int getPartySize();
	bool mEVTriggerActive();

	// state modifiers
	string tokenChangerAdd(int partyNum, int place, string name, stateEffects t);
	string tokenChangerRem(int partyNum, int place, string name, stateEffects);
	void tokenChecker(int, stateEffects);
	void tokenNegate(int wholeParty, stateEffects);

	// other functions
	Player_Actor playerParty[partySize]; // menus

	void addPartyMember(int, Player_Actor in);
	void removePartyMember(int m, Player_Actor out, string deleteCall);
	aegesa battlersP[partySize]; // for the player_Actors
	aegesa battlersE[ePartySize]; // for the enemy

	~World();

	void changePartySize(int isIn);
};

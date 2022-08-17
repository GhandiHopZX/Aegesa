#pragma once
#include <string>
#include "Actor.h"

class PartyActor : public Actor
{

private:
	// gei
	string bio;
	// party stuff
	bool leader;
	// inventory
	const int capacity = 25;

public:

	PartyActor();

	void unEquipWeapon(int num);

	void unEquipArmor(int num);

	string skillBase[50];

	//struct summonData
	//{
	//	string name;
	//	int hpd = 0;
	//	int spd = 0; // special
	//	int fpd = 0; // fighter (aural) 
	//	int ATKd = 0; // attack
	//	int DEFd = 0; // defence (armor based)
	//	int SPEEDd = 0; // speed 
	//	int AGId = 0; // agility
	//	int DEXd = 0; // dexterity
	//	int INTd = 0; // intelligence
	//	int SPRd = 0; // spirit
	//	int STRd = 0; // strength (also effects status)
	//	int ENDd = 0; // endurance (bodily based / also effects status)
	//	int CONd = 0; // constitution (mental, body, soul, based / also effects status)
	//	int hp = 0;
	//	int sp = 0;
	//	int fp = 0;
	//	int ATK = 0;
	//	int DEF = 0;
	//	int SPEED = 0;
	//	int AGI = 0;
	//	int DEX = 0;
	//	int INT = 0;
	//	int SPR = 0;
	//	int STR = 0;
	//	int END = 0;
	//	int CON = 0;
	//	elementType summonType;
	//};

	//struct magicArch
	//{
	//	string name;
	//	// total damage output
	//	int tdo;
	//	// health
	//	int hpd = 0;
	//	// special points
	//	int spd = 0;
	//	// aural points
	//	int fpd = 0;
	//	// stat add
	//	int ATKd = 0;
	//	int DEFd = 0;
	//	int SPEEDd = 0;
	//	int AGId = 0;
	//	int DEXd = 0;
	//	int INTd = 0;
	//	int SPRd = 0;
	//	int STRd = 0;
	//	int ENDd = 0;
	//	int CONd = 0;

	//	//core stat changes
	//	int hp = 0;
	//	int sp = 0;
	//	int fp = 0;
	//	int ATK = 0;
	//	int DEF = 0;
	//	int SPEED = 0;
	//	int AGI = 0;
	//	int DEX = 0;
	//	int INT = 0;
	//	int SPR = 0;
	//	int STR = 0;
	//	int END = 0;
	//	int CON = 0;

	//	int manaCharge = 0;
	//	int auralCharge = 0;
	//	elementType spellType;
	//	// rune effects...
	//	// combined effect
	//};

	//struct skillSet
	//{
	//	string name;
	//	// stat add
	//	int hpd = 0;
	//	int spd = 0; 
	//	int fpd = 0;  
	//	int ATKd = 0;
	//	int DEFd = 0; 
	//	int SPEEDd = 0; 
	//	int AGId = 0; 
	//	int DEXd = 0;
	//	int INTd = 0;
	//	int SPRd = 0;
	//	int STRd = 0;
	//	int ENDd = 0;
	//	int CONd = 0;
	//	int efficiency;
	//	int executionRating;
	//	// damage ouput
	//	int dmgOut;
	//	int consumption;
	//	int dynamicPlus;
	//	int apPlus;
	//};

	//struct STset
	//{
	//	string name;
	//	// stat multipliers
	//	int hpd = 0;
	//	int spd = 0;
	//	int fpd = 0;
	//	int ATKd = 0;
	//	int DEFd = 0;
	//	int SPEEDd = 0;
	//	int AGId = 0;
	//	int DEXd = 0;
	//	int INTd = 0;
	//	int SPRd = 0;
	//	int STRd = 0;
	//	int ENDd = 0;
	//	int CONd = 0;
	//	
	//	// dmgouput
	//	int dmgOuput;
	//	int mgkMulti;
	//	int spMulti;
	//	int fpMulti;
	//	int dpMulti;
	//	int apMulti;
	//};

	//struct codeBasePwr
	//{
	//	string name;
	//	// stat changes
	//	int ATKd = 0;
	//	int DEFd = 0;
	//	int SPEEDd = 0;
	//	int AGId = 0;
	//	int DEXd = 0;
	//	int INTd = 0;
	//	int SPRd = 0;
	//	int STRd = 0;
	//	int ENDd = 0;
	//	int CONd = 0;

	//	//core stat changes
	//	int ATK = 0;
	//	int DEF = 0;
	//	int SPEED = 0;
	//	int AGI = 0;
	//	int DEX = 0;
	//	int INT = 0;
	//	int SPR = 0;
	//	int STR = 0;
	//	int END = 0;
	//	int CON = 0;

	//	string components[3]; // these are items used in the process
	//	int calculationsOmega; // the time spent
	//	int algorithmicComplexity; // the Lv. of hack that is required to perform the hack and its success rate
	//	int complilationSpd; // the speed of the hack overall
	//	int OP; // overall PWR
	//};

	struct weapon
	{
		int maxhp = 0;
		int maxsp = 0;
		int fp = 0;
		int ap = 0;
		int atk = 0;
		int def = 0;
		int speed = 0;
		int agi = 0;
		int dex = 0;
		int intel = 0;
		int spr = 0;
		int str = 0;
		int end = 0;
		int con = 0;
		int value = 0;
	
		string name = "";
		int quantity = 0;
	};

	struct armor
	{
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
		string name = "";
		int quantity = 0; //15
	};
	
	struct item
	{
		int hpd = 0;
		int spd = 0;
		int fpd = 0;
		int atkd = 0;
		int defd = 0;
		int speedd = 0;
		int agid = 0;
		int dexd = 0;
		int inteld = 0;
		int sprd = 0;
		int strd = 0;
		int endd = 0;
		int cond = 0;
		int value = 0;
		string name = "";
		int quantity = 0;
	};

	armor armors[3];
	weapon weapons[3];
	item items[25];

	void setlead(bool l);

	void statWeaponTransfer(
		int num, int maxhp,
		int ap, int maxsp,
		int fpd, int atkd,
		int defd, int speedd,
		int agid, int dexd,
		int inteld, int sprd,
		int strd, int endd,
		int cond, int value,
		string name);

	void statArmorTransfer(
		int num, int maxhp,
		int ap, int maxsp,
		int fpd, int atkd,
		int defd, int speedd,
		int agid, int dexd,
		int inteld, int sprd,
		int strd, int endd,
		int cond, int value,
		string name);

	void itemUsageTransfer(
		int num);

	void setBio(string b);

	bool getLead();

	int afps(int choice);

	int adefs(int choice);

	int aspeeds(int choice);

	int aagis(int choice);

	int adexs(int);

	int aintels(int);

	int asprs(int);

	int astrs(int);

	int aends(int);

	int acons(int);

	int aaps(int d);

	int fps(int choice);

	int defs(int choice);

	int speeds(int choice);

	int agis(int choice);

	int dexs(int choice);

	int intels(int choice);

	int sprs(int choice);

	int strs(int choice);

	int ends(int choice);

	int cons(int choice);

	int hps(int choice);

	int atks(int choice);

	int sps(int choice);

	int values(int choice);

	string iname(int choice);

	int quantites(int choice);

	int whps(int choice);

	int watks(int choice);

	int wsps(int choice);

	int waps(int choice);

	int wfps(int choice);

	int wdef(int choice);

	int wspeed(int choice);

	int wagi(int choice);

	int wdex(int choice);

	int wint(int choice);

	int wspr(int choice);

	int wstr(int choice);

	int wend(int choice);

	int wcon(int choice);

	int wvalues(int choice);

	string wname(int choice);

	int wquantites(int choice);

	int ahps(int choice);

	int aatks(int choice);

	int asps(int choice);

	int avalues(int choice);

	string aname(int choice);

	int aquantites(int choice);

	// saver indexers
	int findWIndex(string);
	int findAIndex(string);
	int findItemIndex(string);

	int FindEmptyASlot();

	int FindEmptyISlot();

	int FindEmptyWSlot();

	// personals
	string getBio();

	~PartyActor();

};
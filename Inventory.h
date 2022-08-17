#include <iostream>
#include <list>
using namespace std;

#pragma once
class Inventory // this class just implements an organizational tool
{
public:

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
		int quantity = 0; //15
		string name = "";
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

	list<weapon> auxWeapons; // for aux storage
	list<armor> auxArmors; // for aux storage
	list<item> auxItems; // for aux storage

	armor my_armors[25];

	weapon my_weapons[25];

	item my_items[25];

	Inventory();

	void itemCheck();

	void TranserArmors(int maxhp, int ap, int maxsp, int fpd, 
		int atkd, int defd, int speedd, int agid, int dexd,
		int inteld, int sprd, int strd, int endd, int cond, 
		int value, string name, int quantity);

	// these call the items from the player into this organizational class

	void TranserWeapons(int maxhp, int ap, int maxsp, int fpd, 
		int atkd, int defd, int speedd, int agid, int dexd,
		int inteld, int sprd, int strd, int endd, int cond, 
		int value, string name, int quantity);

	void TranserItems(int maxhp, int maxsp, int fpd, int atkd,
		int defd, int speedd, int agid, int dexd, int inteld, 
		int sprd, int strd, int endd, int cond, int value,
		string name, int quantity);

	void TranserAllArmors(int maxhp[], int ap[],
		int maxsp[], int atk[],
		int fp[],
		int def[], int speed[], 
		int agi[], int dex[], 
		int intel[], int spr[],
		int str[], int end[],
		int con[], int value[], 
		string name[], int quantity[]);

	void TranserAllWeapons(int maxhp[], int ap[],
		int maxsp[], int atk[],
		int fp[],
		int def[], int speed[],
		int agi[], int dex[],
		int intel[], int spr[],
		int str[], int end[],
		int con[], int value[],
		string name[], int quantity[]);

	void TranserAllItems(int maxhp[],
		int maxsp[], int atk[],
		int fp[],
		int def[], int speed[],
		int agi[], int dex[],
		int intel[], int spr[],
		int str[], int end[],
		int con[], int value[],
		string name[], int quantity[]);

	void weaponZeroOut(int call);
	void itemZeroOut(int);
	void armorZeroOut(int);
	item myItemCall(int);
	armor myArmorCall(int);
	weapon myWepCall(int);

	item myItmListCall(int);
	armor myArmListCall(int);
	weapon myWepListCall(int);

	// this doesnt't nuke itm aux
	void initAuxItemList(); 

	// this doesnt't nuke wep aux
	void initAuxWeaponList(); 

	// this doesnt't nuke armor aux
	void initAuxArmorList();

	Inventory::item itemAuxCall(int call);
	Inventory::armor armorAuxCall(int call);
	Inventory::weapon weaponAuxCall(int call);

	void moveItmToAux(item);
	void moveArmToAux(armor);
	void moveWepToAux(weapon);

	int findWIndex(string);
	int findAIndex(string);
	int findItemIndex(string);

	int FindEmptyASlot();

	int FindEmptyISlot();

	int FindEmptyWSlot();

	void displaylistItem();
	void displaylistWeapon();
	void displaylistArmor();
	void DisplayMenuCall();
	void setName(string);
	string getName();
	list<pair<weapon, int>> getDemow();
	list<pair<armor, int>> getDemoa();
	list<pair<item, int>> getDemoi();

	~Inventory();

private:
	string name;
	list<pair<weapon, int>> demow; // shit that gets moved from weapons aux
	list<pair<armor, int>> demoa;
	list<pair<item, int>> demoi;
};


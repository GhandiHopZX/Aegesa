#pragma once
#include <string>
#include "Item.h"

using namespace std;

class Item
{
public:
	Item();
	/// <summary>
/// hpd = baseInts[0];
/// spd = baseInts[1];
/// fpd = baseInts[2];
/// atkd = baseInts[3];
/// defd = baseInts[4];
/// speedd = baseInts[5];
/// agid = baseInts[6];
/// dexd = baseInts[7];
/// inteld = baseInts[8];
/// sprd = baseInts[9];
/// strd = baseInts[10];
/// endd = baseInts[11];
/// cond = baseInts[12];
/// value = baseInts[13];
/// quantity = baseInts[14]; 
/// </summary>
/// <param name="baseInts"></param>
/// <param name="name"></param>
	Item(int[14], string);

	//getters
	int getHpd();
	int getSpd();
	int getFpd();
	int getatkd();
	int getdefd();
	int getspeedd();
	int getagid();
	int getdexd();
	int getinteld();
	int getsprd();
	int getstrd();
	int getendd();
	int getcond();
	int getval();

	//accessors
	void setHpd(int);
	void setSpd(int);
	void setFpd(int);
	void setatkd(int);
	void setdefd(int);
	void setspeedd(int);
	void setagid(int);
	void setdexd(int);
	void setinteld(int);
	void setsprd(int);
	void setstrd(int);
	void setendd(int);
	void setcond(int);
	void setval(int);
	~Item();

private:
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
#pragma once
#include <string>
using namespace std;
class Weapon
{
private:
	int hp = 0;
	int sp = 0;
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
public:
	Weapon();
	/// <summary>
/// hp = baseInts[0];
/// sp = baseInts[1];
/// fp = baseInts[2];
/// atk = baseInts[3];
/// def = baseInts[4];
/// speed = baseInts[5];
/// agi = baseInts[6];
/// dex = baseInts[7];
/// intel = baseInts[8];
/// spr = baseInts[9];
/// str = baseInts[10];
/// end = baseInts[11];
/// con = baseInts[12];
/// value = baseInts[13];
/// quantity = baseInts[14]; 
/// </summary>
/// <param name="baseInts"></param>
/// <param name="name"></param>
	Weapon(int baseInts[], string name);
	int getHp();
	int getSp();
	int getFp();
	int getatk();
	int getef();
	int getspee();
	int getagi();
	int getdex();
	int getintel();
	int getspr();
	int getstr();
	int getend();
	int getcon();
	int getval();
	void setHp(int h);
	void setSp(int s);
	void setFp(int f);
	void setatk(int a);
	void setdef(int d);
	void setspeed(int sp);
	void setagi(int ag);
	void setdex(int e);
	void setintel(int inte);
	void setspr(int sp);
	void setstr(int sr);
	void setend(int enr);
	void setcon(int cone);
	void setval(int v);
	~Weapon();
};


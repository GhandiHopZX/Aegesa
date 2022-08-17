#pragma once
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Skill
{
public:
	Skill();

	Skill(string n, int apr, int dmgi, int spr, int totalD, int addMul, int AGI, int DEX, int INT, int SPR, int STR, int END, int CON);

	Skill(string n, int apr, int dmgi, int spr, int totalD);

	// setters

	void statMulti(
		int AGI,
		int DEX,
		int INT,
		int SPR,
		int STR,
		int END,
		int CON
	); // non 3 base stats go here
	void setDmg(int d, int spIn, int apIn);
	void setSpR(int set);
	void setApR(int set);
	void setName(string n);

	string getName();
	
	// getters
	int getDmg();
	int getSpR();
	int getApR();

	~Skill();

private:
	int totalDmg;
	int spR;
	int apR;
	int dmg;
	string name;
	list<string> eff; // total status afflictions
	list<string> targetNames; // if single target // pop the bottom of whatever targets are in question
};
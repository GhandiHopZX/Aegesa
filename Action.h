#pragma once
#include <list>
#include <string>
#include <iostream>

using namespace std;

class Action
{
private:
	bool done; // flag for events
	int times;
	string idea;
	int priority;
	string description;
	string effCall; // status effects
	int targetRadius; // 0 single , 1 multi, 2 aoe
	string name;

public:
	Action();
	Action(bool done, int times, string idea, 
		int priority, string des,
		string effCall, int targetRadius);
	~Action();
	
	int getTimes();
	string getIdea();
	int getPriority();
	bool getFlag();
	string getDes();
	string getEff();
	int getTargetR();

	void popFrontEffList();
	void setFlag(bool d);
	void setTimes(int);
	void setIdea(string n);
	void setPriority(int);
	void setDes(string d);
	void setEff(string ef);
	void setTargetR(int r);

	list<string> effList = {};
};
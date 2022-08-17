#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <vector>
#include <utility>
#include "Actor.h"

using namespace std;

Actor::Actor()
{
	EXP = 0;
	dummyPlus = NULL;
	statmulti = NULL;
	party_num = 4;
	num_Statuses = 0;

	hpd = getHpd();
	spd = getSpd(); // special
	fpd = getFpd(); // fighter (aural)

	ATKd = getATKd(); // attack
	DEFd = getDEFd(); // defence (armor based)
	SPEEDd = getSPDd(); // speed

	AGId = getAGId(); // agility
	DEXd = getDEXd(); // dexterity
	INTd = getINTd(); // intelligence
	SPRd = getSPRd(); // spirit
	STRd = getSTRd(); // strength (also effects status)
	ENDd = getENDd(); // endurance (bodily based / also effects status)
	CONd = getCONd(); // constitution (mental, body, soul, based / also effects status)
}

Actor::Actor(elementType h)
{
	EXP = 0;
	dummyPlus = NULL;
	statmulti = NULL;
	party_num = 4;
	num_Statuses = 0;

	hpd = getHpd();
	spd = getSpd(); // special
	fpd = getFpd(); // fighter (aural)

	ATKd = getATKd(); // attack
	DEFd = getDEFd(); // defence (armor based)
	SPEEDd = getSPDd(); // speed

	AGId = getAGId(); // agility
	DEXd = getDEXd(); // dexterity
	INTd = getINTd(); // intelligence
	SPRd = getSPRd(); // spirit
	STRd = getSTRd(); // strength (also effects status)
	ENDd = getENDd(); // endurance (bodily based / also effects status)
	CONd = getCONd(); // constitution (mental, body, soul, based / also effects status)
	d = h;
}

Actor::elementType Actor::getElement()
{
	return d;
}

void Actor::setElement(int e)
{
	d = static_cast<elementType>(e);
}

void Actor::setStatbaseCall(int call, int set)
{
	statbaseArr[call] = set;
}

int Actor::getStatbaseCall(int call)
{
	return statbaseArr[call];
}

void Actor::setBGSpd(int spdIn)
{
	newSpd = getSPDd() + static_cast<int>(0.3) * (spdIn * getSPD());
}

// states are added here
void Actor::setState(string name)
{
	setNumOfStates(getNumOfStates() + 1);
	stateCheck();
	for (int i = 0; i < 20; i++)
	{
		int m = getNumOfStates() + 1;
		//My_Statuses2.
		//validate actual states
		//add one if needed
		//put in the state
		if (My_Statuses[i].empty())
		{
			My_Statuses[i] = name;
		}
	}
}

// gets one state
string Actor::getState()
{
	stateCheck();
	string sups[20];

	string fullSet[20];

	for (int i = 0; i < getNumOfStates(); i++)
	{
		if (!sups[i].empty())
		{
			fullSet[i] += sups[i];
		}
	}
	return fullSet[0];
}
// gets any state with the number for its slot
string Actor::getState2(int call)
{
	stateCheck();
	string sups[20];
	string fullSet[20];

	for (int i = 0; i < getNumOfStates(); i++)
	{
		if (!sups[i].empty())
		{
			fullSet[i] += sups[i];
		}
	}
	return fullSet[call];
}

// print all states
void Actor::printStates()
{
	string cstate;
	cstate = " CURRENT STATES";

	// iterator
	int i = 0;
	for (; i < 20; i++)
	{
		cout << "[" << My_Statuses[i] << "]" << " /" << " ";
	}
}

// Title change
void Actor::setTitle(string n)
{
	title = n;
}

// speed add for in battle status
int Actor::getSPDPlus()
{
	return dummyPlus;
}

// no state avaliable
bool Actor::stateIsEmpty()
{
	for (int i = 0; i < 20; i++)
	{
		if (My_Statuses[i].empty())
		{
			return true;
		}

		if (My_Statuses[i] == "")
		{
			return true;
		}

		if (!My_Statuses[i].empty())
		{
			return false; // then the state isn't existant here its something else
		}
	}

	return false;
}

int Actor::getAtk()
{
	return ATK;
}

// gets rid of states
void Actor::removeStates(int io)
{
	My_Statuses[io] = "";
	setNumOfStates(getNumOfStates() - 1);
}

// is the state there??
void Actor::stateCheck()
{
	for (int i = 0; i < getNumOfStates(); i++)
	{
		if (My_Statuses[i].empty())
		{
			removeStates(i);
		}
		else if (My_Statuses[i] == "NORMAL")
		{
			return;
		}
	}
}

int Actor::battleGuage(int spd)
{
	return spd * getSPDd() * 0.03;
}

Actor::~Actor()
{
}
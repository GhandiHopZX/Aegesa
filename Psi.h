#pragma once
#include <iostream>
#include <list>
#include <string>
using namespace std;

/// <summary>
/// This is a new kind of skill that 
/// requires the player to not be a dick 
/// and balance your shit out.
/// you get two scales
/// one being your lowest point
/// and one being your highest
/// it swings one way and then the other
/// depending on your core middle temperment(temp)
/// too high of a temperment and you could instantly DIE.
/// too low and you could DIE.
/// no games are to be had with this one
/// just plays, meditation and pace
/// </summary>
class Psi
{
	private:
		string name;
		int penNeg; // temp go down
		int penPos; // temp go up

	public:
		//ctr
		Psi();
		//name , positive limit, negative limit
		Psi(string, int pos, int neg);
		//Trigger Effect and Status Call
		Psi(string name, int pos, int neg, string Eff, string Status);
		//setters
		int getNeg();
		int getPos();
		string getName();
		
		//accors
		void setNeg(int);
		void setPos(int);
		void setName(string);

		// battle functions 

		// psiplus, psineg, temperment
		// this thing deals damage or gives
		// life. Whatever you want.
		// higher or lower,
		// if its a Psiability that 
		// has negative limits eg -12
		// and the final modifier is -11
		// then the ability is going to do
		// damage.
		// Likewise a positive 
		// modifier does the opposite
		int psiCalc(int, int, int);
		// turns of effect
		int turnsOE(int pCalc, int n, int p);
};


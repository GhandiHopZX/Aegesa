#pragma once
#include <string>
#include <list>

using namespace std;

class Magic
{
public:
	Magic();
	Magic(string name, int targetR, int spd, int intd, 
		int spU, int dp, int sprd, int fpd, int sumDp, 
		int sumSpd, int SPEED, int sumFpd, int fpEx,
		int dpEx, int ap, int beyondFp, int eventFp, string eff);

	int calcSPO(int spu, int fpd, int dp);

	int getMgkPwr();
	int getRTL();
	int getRVL();
	int getRDL();
	int getRAL();
	int getCS();
	string getEff(string m);
	bool getEnabled();
	string getName();

	void setName(string);
	void setMgkPwr();
	void setMgkPwr(int t);
	
	void setEnabled(bool);
	void setRTL(int spd, int intd, int sprd);
	void setRVL(int spo, int spU, int dp, int fpd, int spd);
	void setRDL(int sumdp, int sumspd, int sumfpd);
	void setRAL(int bfp, int efp);
	void setCS(int fpd, int ap, int spd, int SPEED); // casting speed
	void addEff(string);
	
	~Magic();

private:
	string name;
	bool enabled;
	int targetRadius = 0; // 0 single, 1 multi, 2 aoe 
	int MGK = 0; // calculated magic power
	int castingTime = 0; // turns taken to cast spell
	int runeTLv = 0; // Stat based (stats -> Spd+Intd+SPRd)
	int runeVLv = 0; // TeamSynergy based (SpO += team usage of SP during the same turn, SpO = (spU + FPd*DP) *+= 0.6 )
	int runeDLv = 0; // Summon based (Summon DP + Summon SPd + Summon FPd)
	int runeALv = 0; // Blessings from beyond (Aural, Environment, Events, non-Item, non-summon and non-party influences)
	list<string> eff = {}; // total status afflictions
	list<string> targetNames = {}; // if single target // pop the bottom of whatever targets are in question
};
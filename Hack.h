#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "AllySummon.h"
#include "SpecialTech.h"
#include "magic.h"
#include "skill.h"
#include "Enemy.h"
#include "Psi.h"
#include "PartyActor.h"
using namespace std;

// This is hardware in hardware simulated injection.
// literally. In the setting, the Vinortex is the world
// they live in that is part digital, 
// somewhat astral, and physical
// all at the same time
// its reality just fused with the cyber
// so u use hacks accelerated and executed by hardware internal or external 
// to commit a cybercrime. (or a cyberdeed)

/// <summary>
/// most of this is already done so 
/// just imput the data required and use
/// some balancing. You don't need to 
/// make this shit accurate to what a hack
/// uses for resources. Just use a number 
/// that coincides with what the hardware 
/// pushes.
/// some stats having less is good 
/// more is sometimes bad
/// </summary>
class Hack
{
public:
	
	Hack();

	Hack(int fpIn, int dpIn, int enI, int enAlly, int enEv, int enMgk, 
		int enEx, int outEn, int notation2, int cpuUsage, int mem,
		int sto, int netstor, string name2, int cp2, int storage2,
		int FLOPs2, int cycles2, float second2, int cores2, int cycle2,
		int nodes2, int sockets2, int rack2, int racks2, int node, 
		int socket2, int core2, int simds, int mul_AddUits2, int cbSize, int node2);

	//void setClockS(int not, int cpuUsage, int mem, int storage, int networkUsage);
	void cutEn(int outerFp, int outerEn); // cutting the req 
	// to do: that one digit being the quotient in this function needs to be a literal second for time.
	void setCp(int cpIn);
	void setCompS(int);
	void setCull(int enI, int enally, int enEnv, int enMgk, int enEx); //enEx is anything outside of the given criterion
	void setMem(int mem);
	void setCpuU(int);
	void setStorage(int);
	void setNetU(int);
	void setFLOPs(int);
	void setSythesis(int fp, int dp, int cull); 
	void setCycles(int);
	void setClockS(int noet, int cpuusage, int mem, int storage, int networkusage);
	void setNodes(int);
	void setSockets(int);
	void setFirstRack(int);
	void setRacks(int);
	void setFirstNode(int);
	void setSocket(int);
	void setCore(int);
	void setSecond(float);
	void setNotation(int);
	void setEnable(bool);
	void setName(string);
	
	bool execute(int enReq, int enRedux, int maxEnIn, int CompSup, int CpUp);

	string getName();

	// all hacks
	Skill stealSkill(int, Skill c[]);
	Magic disableMgk(int, Magic m[]);
	Enemy removal(int, Enemy d[]);

	// use the names as a targeting array 
	string targetBuff(int, string d[]); 
	string target(int, string d[]);
	string removalp(int, string p[]);

	void removeStat(int call, int statb[14]);

	// use these to modify the hack
	string statusCall(string w);
	string statusChange(string zName, string sdChanger);

	// call these inside a battlerobjectTarget
	string targetStatusChange(string zName, string sdChanger);
	int changeSide(int, int);
	int ddoss(int serviceTurnsLost, int cp);
	string reProgram();

	// u can use this too to change the hack
	void reName(string zName);

	// getters
	int getCp();
	int getNotation(); // 0 - 6
	int getEn();
	int getMem();
	int getCpuUsage();
	int getStorage();
	int getNetworkUsage();
	int getFLOPs();
	int getCycles();
	int getNodes();
	int getSythesis();
	int getSockets();
	int getFirstRack();
	int getRacks();
	int getFirstNode();
	int getSocket();
	int getCore();
	float getSecond();
	int getCull();
	bool getEnabled();

	~Hack();

private:
	string name; //
	bool enabled; // this thing is disabled if it doesn't work
	int cp; // computation power calculated / FLOPS //

	int cpuUsage; // more res //
	int mem; // memory
	int storage; // more space //
	int networkUsage; // more memory on network //
	int notation; //

	int FLOPs; //
	int cycles; //
	int cores; //
	int cycle; //
	int nodes; //
	int sockets; //
	int rack; //
	int racks; //
	int node; //

	int socket; //
	int core; //
	float second; //

	int simds; // single instruction multiple data unit
	int mul_AddUits;
	int clockS; // Rate of how many clock cycles a CPU can perform per second.
	int enReq; // en required
	int recourses; // memory used
	int codebaseSize; // thiccness of the code = atypical size
	int compSpeed; // compilation speed = speedd / notation

	int energy; // required energy = energy used (injector energy required)
	int synthesis; // non-factoral to cp. factoral to energy cutting /= fpd * dp * cull

	int cull; // non-factoral to cp. factoral to energy cutting. 
			  //culling comes from power that is outside the user (allies, items, env, etc)
	// cull = outerfpd + outerEn
	int targetRadius = 0; // 0 single, 1 multi, 2 aoe
	list<string>eff = {}; // total status afflictions
	list<string>targetNames = {}; // if single target // pop the bottom of whatever targets are in question
};


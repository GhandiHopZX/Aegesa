#include "Hack.h"

Hack::Hack()
{
	this->name = "";

	cp = 0;

	this->codebaseSize = 0; // instructions
	this->compSpeed = 0; // compilation speed = omega notational estimation and flop performance
	this->cull = 0; // aux energy not from you
	this->energy = 0; // injector energy
	this->synthesis = 0; // your fpd, dp and cull multiplied together as a new cull
	this->enReq = 0; // energy required
	this->enabled = true;
}

Hack::Hack(int fpIn, int dpIn, int enI, int enAlly, int enEv,
		int enMgk, int enEx, int outEn, int notation2, int cpuUsage2,
		int mem2, int sto, int netstor, string name2, int cp2,
		int storage2, int FLOPs2, int cycles2, float second2,
		int cores2, int cycle2, int nodes2, int sockets2, int rack2,
		int racks2, int node, int socket2, int core2, int simds,
		int mul_AddUits2, int cbSize, int node2)
{
	this->name = name2;
	this->mem = mem2;
	this->second = second2;
	this->core = core2;
	this->socket = socket2;
	this->node = node2;
	this->racks = racks2;
	this->rack = rack;
	this->sockets = sockets2;
	this->nodes = nodes2;
	this->core = core2;
	this->cycle = cycle2;
	this->cores = cores2;
	this->networkUsage = netstor;
	this->notation = notation2;
	this->FLOPs = FLOPs2;
	this->cycle = cycle2;
	this->cycles = cycles2;
	this->storage = storage2;
	this->cpuUsage = cpuUsage2;
	this->mul_AddUits = mul_AddUits2;
	this->codebaseSize = cbSize; // instructions
	this->compSpeed = 0; // compilation speed = omega notational estimation and flop performance
	this->cull = enAlly + enEv + enEx + enMgk; // aux energy not from you
	this->energy = enI; // injector energy
	this->synthesis = 0; // your fpd, dp and cull multiplied together as a new cull
	this->enReq = 0; // energy required
	this->enabled = true;
	
	setClockS(notation2, cpuUsage2, mem2, sto, netstor);
	setCp(cp2);
	cutEn(fpIn, outEn);
	setCull(enI, enAlly, enEv, enMgk, enEx);
	setSythesis(fpIn, dpIn, getCull());
}

int Hack::getCp()
{
	return cp;
}

int Hack::getNotation()
{
	return notation;
}

int Hack::getEn()
{
	return enReq;
}

int Hack::getMem()
{
	return mem;
}

int Hack::getCpuUsage()
{
	return cpuUsage;
}

int Hack::getStorage()
{
	return storage;
}

int Hack::getNetworkUsage()
{
	return networkUsage;
}

int Hack::getFLOPs()
{
	return FLOPs;
}

int Hack::getCycles()
{
	return cycles;
}

int Hack::getNodes()
{
	return nodes;
}

int Hack::getSythesis()
{
	return synthesis;
}

int Hack::getSockets()
{
	return sockets;
}

int Hack::getFirstRack()
{
	return rack;
}

int Hack::getRacks()
{
	return racks;
}

int Hack::getFirstNode()
{
	return node;
}

int Hack::getSocket()
{
	return socket;
}

int Hack::getCore()
{
	return core;
}

float Hack::getSecond()
{
	return 0.0f;
}

void Hack::cutEn(int d, int a)
{
	enReq -= d + a;
}

void Hack::setCp(int cpIn)
{
	cp = racks * (nodes/rack) * (sockets/node) * (core/socket) * (cycles/second) * (FLOPs/cycle);
	cp += cpIn;
}

void Hack::setCompS(int d)
{
	compSpeed = d / getNotation();
}

void Hack::setCull(int enI, int enally, int enEnv, int enMgk, int enEx)
{
	cull = enI * enally * enEnv * enMgk * enEx;
}

void Hack::setMem(int mem)
{
	this->mem = mem;
}

void Hack::setCpuU(int t)
{
	this->cpuUsage = t;
}

void Hack::setStorage(int e)
{
	this->storage = e;
}

void Hack::setNetU(int Nu)
{
	networkUsage = Nu;
}

void Hack::setFLOPs(int w)
{
	FLOPs = w;
}

void Hack::setSythesis(int fp, int dp, int cull)
{
	energy += fp * dp* cull;
}

void Hack::setCycles(int d)
{
	cycles = d;
}

void Hack::setClockS(int nota, int cpuusage, int mem, int storage, int networkusage)
{
	clockS = nota * (cpuusage + mem + storage + networkusage);
}

void Hack::setNodes(int e)
{
	nodes = e;
}

void Hack::setSockets(int r)
{
	sockets = r;
}

void Hack::setFirstRack(int ty)
{
	rack = ty;
}

void Hack::setRacks(int t)
{
	racks = t;
}

void Hack::setFirstNode(int h)
{
	node = h;
}

void Hack::setSocket(int j)
{
	socket = j;
}

void Hack::setCore(int h)
{
	core = h;
}

void Hack::setSecond(float gh)
{
	second = gh;
}

void Hack::setNotation(int u)
{
	notation = u;
}

void Hack::setEnable(bool f)
{
	enabled = f;
}

void Hack::setName(string d)
{
	name = d;
}

bool Hack::execute(int enReq, int enRedux, int maxEnIn, int CompSup, int CpUp)
{
	enReq += this->enReq;
	enReq -= enRedux;
	this->compSpeed += CompSup;
	this->cp += CpUp;
	if (!(enReq > maxEnIn))
	{
		return false;
	}
	return enabled;
}

string Hack::getName()
{
	return name;
}

Skill Hack::stealSkill(int f, Skill c[])
{
	return c[f]; // just load this into the thing
}

Magic Hack::disableMgk(int d, Magic m[])
{
	m[d].setEnabled(false);
	return m[d];
}

Enemy Hack::removal(int w, Enemy d[])
{
	d[w].name = "";
	return d[w];
}

string Hack::targetBuff(int g, string d[])
{
	return d[g];
}

string Hack::target(int h, string d[])
{
	return d[h];
}

string Hack::removalp(int y, string p[])
{
	return p[y];
}

void Hack::removeStat(int call, int statb[14])
{
	statb[call] = 0;
}

string Hack::statusCall(string w)
{
	for (std::list<string>::iterator it = eff.begin(); it != eff.end(); ++it)
	{
		if (it->empty())
		{
			eff.erase(it);
		}
		if (it->data() == w)
		{
			return it->data();
		}
	}
}

string Hack::targetStatusChange(string zName, string sdChanger)
{
	zName = sdChanger;
	return zName;
}

void Hack::reName(string zName)
{
	name = zName;
}

int Hack::changeSide(int d, int yourSide)
{
	int choice{};
	char sndChoice{};
	cout << "What side do you want this target to be on..?" << endl;
	cin >> choice;
	if (choice != yourSide)
	{
		cout << "That's not your side? are you sure? (y) (n) " << endl;
	}
	cin >> sndChoice;
	switch (sndChoice)
	{
	case 'y':
		cout << "Change complete!" << endl;
		system("PAUSE");
		return choice;

	case 'n':
		return
		changeSide(d, yourSide);

	default:
		cout << "try again..." << endl;
		system("PAUSE");
		break;
	}
}

int Hack::ddoss(int serviceTurnsLost, int cp)
{
	int max_turn_loss = cp / 2;
	int choice;
	cout << "Are you sure this counts the turns you need...? 1 -" << " " << max_turn_loss << endl;
	cout << "Select the turns you want your enemy to lose.." << endl;
	cin >> choice;
	if (choice > max_turn_loss)
	{
		cout << "Critical failure....." << endl;
		system("PAUSE");
		return 0;
	}
	return choice;
}

string Hack::reProgram()
{
	string doAction;
	cout << "What do you want done?" << endl;
	cin >> doAction;
	return doAction;
}

string Hack::statusChange(string w, string change)
{
	for (std::list<string>::iterator it = eff.begin(); it != eff.end(); ++it)
	{
		if (it->empty())
		{
			eff.erase(it);
		}
		if (it->data() == w)
		{
			eff.erase(it);
			eff.push_back(change);
			return it->data();
		}
	}
}

int Hack::getCull()
{
	return cull;
}

bool Hack::getEnabled()
{
	return enabled;
}

Hack::~Hack()
{
}
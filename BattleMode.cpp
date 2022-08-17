#include "BattleMode.h"

// all template functions go here

template <typename T> int FindArrMax(T d[])
{
	int n = 0;
	int ma = 0;
	int i = 0;
	if (d[0] != NULL)
	{
		while (i >= 0 && n + d[i] > ma)
		{
			++ma;
			++n;
			++i;
		}
	}
	return static_cast<int>(ma);
}

// globals
// structs
// stubbaroos
// and so on...
 
//function event flow loop order after turnOrderSetto
// THA TOP
// BattleMode()
// turnCheck
// reOrderSetto
// TurnHierarchyC
// turn(multi, enemy, single)
// calculation or clash (if clash then skip damage calc)
// damage calculation
//	HP Check
//	(if enemies or all pm are 0)
//	{
//		~BattleMode() <- end the battle
//	}
// back to top ^

/// <summary> Test flow
/// 
///- ---All current starting method call flow---
///  test_Transfer_CallII
///  initializer
///  turnOrderSetto
///  
/// </summary>
/// 

// operator parameters. 
// I guess you could put some stuff here later
BattleMode::t BattleMode::operator++(int daym)
{
	switch (daym)
	{
	case 0:
		return cl;
	case 1:
		return T1P;
	case 2:
		return TC;
	case 3:
		return ET;
	case 4:
		return TCII;
	case 5:
		return DCU;
	case 6:
		return MUL;
	case 7:
		return END;
	default:
		daym = 0;
		return cl;
	}
}

BattleMode::BattleMode()
{
	bool* ag0 = nullptr; // This checks for whether or not its your starting turn
	this->aGuage = ag0;
	this->battleTime = true;
}

BattleMode::BattleMode(PartyActor crew[], Enemy badies[], Inventory invent, bool* ag, bool battle)
{
	this->turn_Number = 0;
	this->numEnemies = badies->getParty_num();
	this->numMembers = crew->getParty_num();
	this->battleTime = battle;
	this->aGuage = ag; // turn A mode initializer
	invent = invento;
	phaseTrigger(TC);
}

void BattleMode::victorDeterminant(Battler n)
{
	string filePath;
	string abSave{};

	// setpath
	filePath = "Save.bin";

	// set file
	fstream abOut((filePath).c_str(), ios::out | ios::binary, ios_base::trunc);

	// 1. Collect party data from this battler
	int i = 0;
	
	abOut.open(abSave);
	for (std::list<Battler>::iterator
		it = AllBattlersList.begin();
		it != AllBattlersList.end(); ++it)
	{
		if (it.operator->()->team == n.team)
		{
			// 2. Put them all in a list (WPF)
			for (std::list<PartyActor>::iterator
				bat = WPF.begin();
				bat != WPF.end(); ++bat)
			{
				// convert the it battler to a party member
				// by sending these values back to WPF
				if (it.operator->()->name == bat.operator->()->name)
				{
					// updating data
					// 3. Update them all using battler data.
					abOut.write((char*) &it.operator*(), sizeof(it.operator*())); // dunno if this works
				}
			}
		}
		++i;
	}
	// 4. then save to a file. < - 
	abOut.close();

	// ONWARD TO THE SPOILS OF VICTORY!

	cout << "You Win!" << endl;
	BattleMode::~BattleMode();
}

BattleMode::Battler BattleMode::findBattler(string namer)
{
	for (std::list<Battler>::iterator it = AllBattlersList.begin(); it != AllBattlersList.end(); ++it)
	{
		if (it->name == namer)
		{
			return it.operator*();
		}
	}
	return Battler(); // NULL?
}

void BattleMode::victoryDet(Task task_target)
{
	if (gatherAllEnemyHpds(task_target) <= 0)
	{
		phaseTrigger(END);
	}
}
      
void BattleMode::initializer(PartyActor load[], Enemy tr[])
{
	int countP = 0;
	int countE = 0;
	
	for (int i = 0; i < 6; i++)
	{
		if (!(load[i].getActorName().empty()))
		{
			cout << load[i].getName() << " In Party..." << endl;
			++countP;
		}
	}
	
	int i = 0;
	for (; i < 8; i++)
	{
		if (!(tr[i].getActorName().empty()))
		{
			cout << tr[i].getActorName() << " ..In Party" << endl;
			++countE;
		}
	}

	//auto ite = troop;
	// count 
	// each 
	// side
	cout << "\nMy Party count: " << countP << endl;
	cout << "Targets in sight: " << countE << endl << endl;
	// Now
	// use an algorithm to 

		// place each and every party member
		// in a place of speed stat based hierarchy.
		// this way, each Party member is called in
		// correct order at the first time of battle
		// 
		// this can change when the speed stat is..
		// a reorder function will be called 
		// doing the same thing just 
		// for during combat turn placement.

	// function call here

	turnOrderSetto(load, tr, countP, countE);
}

void BattleMode::test_Transfer_CallII(PartyActor Scop[], Enemy Ecop[], int m, int e)
{
	//actors
	for (int i = 0; i < m; i++)
	{
		if (!(Scop[i].getActorName().empty()))
		{
			cout << "PartyMember: " << Scop[i].name << " Loaded" << endl;
		}
	}

	//baddies
	for (int i = 0; i < e; i++)
	{
		if (!(Ecop[i].getActorName().empty()))
		{
			cout << "EnemyData: " << Ecop[i].name << " Loaded" << endl;
		}
	}

	cout << "initializer test" << endl;

	initializer(Scop, Ecop);

	//cout << "ok " << endl;
}

void BattleMode::phaseTrigger(BattleMode::t j)
{
	// initials being set

	t turn{};
	// look into the turn list
	
	for (int i = 0; i < 2; i++)
	{
		// 6 turn branch 
		switch (turn)
		{
		case cl: // turn A mode Clash time
			++turn_Number;
			clashMode();
			break;
		
		case T1P:
			++turn_Number;
			turnCallPVP();
			break;
		
		case TC:
			TurnCheck();
			break;
		
		case ET:
			++turn_Number;
			aiTurn();
			break;
		
		case TCII:
			TurnCheckII();
			ReOrderSettto();
			break;
		
		case DCU:
			//damage calculation
			UpdateALL();
			hpCheck();
			ReOrderSettto();
			TurnCheck();
			break;

		case MUL:
			++turn_Number;
			multiTurnCall();
			break;

		case END:
			BattleMode::~BattleMode();
			i = 2;
			break;
		
		default:
			UpdateALL();
			hpCheck();
			ReOrderSettto();
			TurnCheck();
			break;
		}

	// turn

	// deterimine function

	// save front slot ?

	// insert

	// action

	// pop 

	/*
		Later on you may have to re-initialize 
	these party members in another list
	or push them back to another space in
	the sequence once the stack pops off
	this can be used to make turnmaking alot
	easier.
	Once the pop happens the actor needs to compare
	the speed stat with each individual fighter
	both ally and foe to find a place back in the
	list...
		I guess you'd just emplace the turn maker then pop
	then rince and repeat.

	turn, determine, save, insert, action, pop
	*/
		i = 0;	// end of loop goes back to start
	}
}

void BattleMode::ActionIN(Task t)
{
	TaskBase.push_front(t);
	executeTask();
}

void BattleMode::ForcedActionIN(Task forced[])
{
	int i = 0;
	for(; i < FindTaskArrMax(forced); ++i)
	{
		TaskBase.push_back(forced[i]);
	}
	executeTask();
}

// probably dont need this
void BattleMode::MultiActionIN(Task tsl[])
{
	int i = 0;
	for (; i < FindTaskArrMax(tsl); ++i)
	{
		TaskBase.push_front(tsl[i]);
		executeTaskMulti(); // < - inside the loop makes the burst fire execution work
	}
}

auto BattleMode::attackDMGCALC(BattleMode::Battler h)
{
	int& ar = h.statbaseDArr[3];
	ar += h.statbaseDArr[10];
	ar += h.wepstatAdd[4][0];
	ar += h.wepstatAdd[4][1];
	ar += h.wepstatAdd[4][2];
	ar += h.wepstatAdd[11][0];
	ar += h.wepstatAdd[11][1];
	ar += h.wepstatAdd[11][2];
	
	ar += h.armstatAdd[4][0];
	ar += h.armstatAdd[4][1];
	ar += h.armstatAdd[4][2];
	ar += h.armstatAdd[11][0];
	ar += h.armstatAdd[11][1];
	ar += h.armstatAdd[11][2];
	return ar;
}

void BattleMode::executeTaskMulti()
{

}

// you need this though
void BattleMode::executeTask() // DC/EXE MODE
{
	// stat changers
	int atkS = 0;
	int skATK = 0;
	int mgkAtk = 0;
	int stAtk = 0;
	int newDef = 0;
	int newEva = 0; // EVA = 

	// original stats
	//int ogStats[n = the number of stat changers];

	Battler selectedB = findBattler(TaskBase.back().singleTarget.name);
	Skill dataS;
	switch (TaskBase.back().team_num)
	{
	case 0:
		//ai
		break;
	default:
		switch (TaskBase.back().targetRange)
		{
		case 0: // single target
			//TaskBase.back().;
			switch (TaskBase.back().decision)
			{
			case TaskType::Attack: // done
				atkS = 0;
				/// <summary>
				///  TODO ADD
				/// an ATK DC fucntion
				/// add self target functionality throughout this class
				/// and update the db_choice stuff
				/// remember to 0 out atkS on every case
				/// </summary>
				atkS += findBattler(TaskBase.back().selfTarget.name).statbaseDArr[3];
				atkS += findBattler(TaskBase.back().selfTarget.name).wepstatAdd[5][0];
				atkS += findBattler(TaskBase.back().selfTarget.name).wepstatAdd[5][1];
				atkS += findBattler(TaskBase.back().selfTarget.name).wepstatAdd[5][2];
				atkS += findBattler(TaskBase.back().selfTarget.name).armstatAdd[5][0];
				atkS += findBattler(TaskBase.back().selfTarget.name).armstatAdd[5][1];
				atkS += findBattler(TaskBase.back().selfTarget.name).armstatAdd[5][2];
				// DC
				atkS = atkS - findBattler(TaskBase.back().singleTarget.name).statbaseDArr[4];
				break;

			case TaskType::Defend: // done
				findBattler(TaskBase.back().selfTarget.name).statbaseDArr[4] +=
					TaskBase.back().selfTarget.statbaseDArr[4] * randCalc();
				break;

			case TaskType::Skill: // done
				skATK = 0;

				//skill boost
				dataS = cDatabase.searchSkill(TaskBase.back().selfTarget.skillBase[TaskBase.back().db_choice]);
				dataS.statMulti(findBattler(TaskBase.back().selfTarget.name).statbaseDArr[6],
					findBattler(TaskBase.back().selfTarget.name).statbaseDArr[7],
					findBattler(TaskBase.back().selfTarget.name).statbaseDArr[8],
					findBattler(TaskBase.back().selfTarget.name).statbaseDArr[9],
					findBattler(TaskBase.back().selfTarget.name).statbaseDArr[10],
					findBattler(TaskBase.back().selfTarget.name).statbaseDArr[11],
					findBattler(TaskBase.back().selfTarget.name).statbaseDArr[12]);

				// sp reduction (this will get moved down the phases)
				//findBattler(TaskBase.back().selfTarget.name).statbaseDArr[1] - dataS.getSpR();

				//armor
				skATK += findBattler(TaskBase.back().selfTarget.name).statbaseDArr[3];
				skATK += findBattler(TaskBase.back().selfTarget.name).wepstatAdd[5][0];
				skATK += findBattler(TaskBase.back().selfTarget.name).wepstatAdd[5][1];
				skATK += findBattler(TaskBase.back().selfTarget.name).wepstatAdd[5][2];
				skATK += findBattler(TaskBase.back().selfTarget.name).armstatAdd[5][0];
				skATK += findBattler(TaskBase.back().selfTarget.name).armstatAdd[5][1];
				skATK += findBattler(TaskBase.back().selfTarget.name).armstatAdd[5][2];
				// natural dp boost
				skATK += findBattler(TaskBase.back().selfTarget.name).wepstatAdd[4][0];
				skATK += findBattler(TaskBase.back().selfTarget.name).wepstatAdd[4][1];
				skATK += findBattler(TaskBase.back().selfTarget.name).wepstatAdd[4][2];
				skATK += findBattler(TaskBase.back().selfTarget.name).armstatAdd[4][0];
				skATK += findBattler(TaskBase.back().selfTarget.name).armstatAdd[4][1];
				skATK += findBattler(TaskBase.back().selfTarget.name).armstatAdd[4][2];
				skATK += findBattler(TaskBase.back().selfTarget.name).statbaseDArr[3] * randCalc();

				//dataS.setApR(); < - ? use for ap heavy stuff Skill - > ST? // move this down some phases
				//dataS.setDmg(,); move this down too

				// addups
				skATK += dataS.getDmg(); // eventually this goes down as well

				// def
				skATK -= findBattler(TaskBase.back().singleTarget.name).statbaseDArr[4];
				// DC
				findBattler(TaskBase.back().singleTarget.name).statbaseDArr[0] -= skATK;
				break;

			case TaskType::Magic:
				mgkAtk += selectedB.armstatAdd[10][0];
				mgkAtk += selectedB.armstatAdd[10][1];
				mgkAtk += selectedB.armstatAdd[10][2];
				mgkAtk += selectedB.wepstatAdd[10][0];
				mgkAtk += selectedB.wepstatAdd[10][1];
				mgkAtk += selectedB.wepstatAdd[10][2];
				mgkAtk += selectedB.statbaseDArr[10] + 
				selectedB.statbaseDArr[9] + 
				selectedB.statbaseDArr[2];
				mgkAtk *= selectedB.statbaseDArr[10] * randCalc();
				//def
				mgkAtk -= findBattler(TaskBase.back().singleTarget.name).statbaseDArr[5];
				// DC
				findBattler(TaskBase.back().singleTarget.name).statbaseDArr[0] -= mgkAtk;
				break;

			case TaskType::ST:
				stAtk = 0;
				stAtk += 
					randCalc() * (selectedB.statbaseDArr[1] +
					selectedB.statbaseDArr[1] *
					selectedB.statbaseDArr[2] *
					selectedB.statbaseDArr[9]);
				break;

			case TaskType::Items:
				findBattler(TaskBase.back().selfTarget.name).statbaseDArr[0] += Items(TaskBase.back()).hpd;
				findBattler(TaskBase.back().selfTarget.name).statbaseDArr[1] += Items(TaskBase.back()).spd;
				findBattler(TaskBase.back().selfTarget.name).statbaseDArr[2] += Items(TaskBase.back()).fpd;
				findBattler(TaskBase.back().selfTarget.name).statbaseDArr[3] += Items(TaskBase.back()).atkd;
				findBattler(TaskBase.back().selfTarget.name).statbaseDArr[4] += Items(TaskBase.back()).defd;
				findBattler(TaskBase.back().selfTarget.name).statbaseDArr[5] += Items(TaskBase.back()).speedd;
				findBattler(TaskBase.back().selfTarget.name).statbaseDArr[6] += Items(TaskBase.back()).agid;
				findBattler(TaskBase.back().selfTarget.name).statbaseDArr[7] += Items(TaskBase.back()).dexd;
				findBattler(TaskBase.back().selfTarget.name).statbaseDArr[8] += Items(TaskBase.back()).inteld;
				findBattler(TaskBase.back().selfTarget.name).statbaseDArr[9] += Items(TaskBase.back()).sprd;
				findBattler(TaskBase.back().selfTarget.name).statbaseDArr[10] += Items(TaskBase.back()).strd;
				findBattler(TaskBase.back().selfTarget.name).statbaseDArr[11] += Items(TaskBase.back()).endd;
				findBattler(TaskBase.back().selfTarget.name).statbaseDArr[12] += Items(TaskBase.back()).cond;
				break;

			case TaskType::Escape:
				newEva += randCalc() * (findBattler(TaskBase.back().selfTarget.name).statbaseDArr[6] 
					+ findBattler(TaskBase.back().selfTarget.name).statbaseDArr[7]
					+ findBattler(TaskBase.back().selfTarget.name).statbaseDArr[5]);
				Escape(findBattler(TaskBase.back().selfTarget.name), 0);
				break;

			case TaskType::Hack:
				HackC(findBattler(TaskBase.back().selfTarget.name), TaskBase.back());
				break;

			case TaskType::Summon: // summmon
				SummonC(TaskBase.back());
				break;

			case TaskType::Act: // action
				break;

			case TaskType::Customize:
				break;

			default:
				break;

			}
			break;

		case 1: // multi target
			switch (TaskBase.back().decision)
			{
			case TaskType::Attack:
				break;

			case TaskType::Defend:
				break;

			case TaskType::Skill:
				break;

			case TaskType::Magic:
				break;

			case TaskType::ST:
				break;

			case TaskType::Items:
				break;

			case TaskType::Escape:
				break;

			case TaskType::Hack:
				break;

			case TaskType::Summon: // summmon
				break;

			case TaskType::Act: // action
				break;

			case TaskType::Customize: //
				break;

			default:
				break;
			}
			break;

		case 2: // AOE target
			switch (TaskBase.back().decision)
			{
			case TaskType::Attack:
				break;

			case TaskType::Defend:
				break;

			case TaskType::Skill:
				break;

			case TaskType::Magic:
				break;

			case TaskType::ST:
				break;

			case TaskType::Items:
				break;

			case TaskType::Escape:
				break;

			case TaskType::Hack:
				break;

			case TaskType::Summon: // summmon
				break;

			case TaskType::Act: // action
				break;

			case TaskType::Customize: // 
				break;

			default:
				break;
			}
			break;

		default:
			break;
		}
		break;
	}
	
}

void BattleMode::turnOrderSetto(PartyActor p[], Enemy e[], int countp, int counte)
{
	int highestPlace = 0;
	int teamAdd = 0;
	int countp2 = countp;
	int counte2 = counte;
	int battlerC = 0;
	
	// actors first
	// battler Conversion
	for (int i = 0; i < countp2; i++)
	{
		//load the actors in the vector via some magical way...
		Wp.push_front(p[i]);
		cout << Wp.front().getName()
		<< "  ..LOCKED IN" << endl;
	}

	for (int i = 0; i < counte2; i++)
	{
		//load the actors in the vector via some magical way...
		troop.push_front(e[i]);
		cout << troop.front().getName() 
			<< "  ..LOCKED IN" << endl;
	}

	// teams set
	for (int i = 0; i < counte; i++)
	{
		// baddies
		AllBattlers[i].name = e[i].getName();

		AllBattlersF[i].statbaseArr[0] = e[i].getHp();
		AllBattlersF[i].statbaseArr[1] = e[i].getSp();
		AllBattlersF[i].statbaseArr[2] = e[i].getFp();
		AllBattlersF[i].statbaseArr[3] = e[i].getAp();
		AllBattlersF[i].statbaseArr[4] = e[i].getDp();
		AllBattlersF[i].statbaseArr[5] = e[i].getAtk();
		AllBattlersF[i].statbaseArr[6] = e[i].getDEF();
		AllBattlersF[i].statbaseArr[7] = e[i].getSPD();
		AllBattlersF[i].statbaseArr[8] = e[i].getAGI();
		AllBattlersF[i].statbaseArr[9] = e[i].getDEX();
		AllBattlersF[i].statbaseArr[10] = e[i].getINT();
		AllBattlersF[i].statbaseArr[11] = e[i].getSPR();
		AllBattlersF[i].statbaseArr[12] = e[i].getSTR();
		AllBattlersF[i].statbaseArr[13] = e[i].getEND();
		AllBattlersF[i].statbaseArr[14] = e[i].getCON();
		AllBattlersF[i].team = teamAdd;
		// ded	   
		AllBattlersF[i].statbaseDArr[0] = e[i].getHpd();
		AllBattlersF[i].statbaseDArr[1] = e[i].getSpd();
		AllBattlersF[i].statbaseDArr[2] = e[i].getFpd();
		AllBattlersF[i].statbaseDArr[3] = e[i].getATKd();
		AllBattlersF[i].statbaseDArr[4] = e[i].getDEFd();
		AllBattlersF[i].statbaseDArr[5] = e[i].getSPDd();
		AllBattlersF[i].statbaseDArr[6] = e[i].getAGId();
		AllBattlersF[i].statbaseDArr[7] = e[i].getDEXd();
		AllBattlersF[i].statbaseDArr[8] = e[i].getINTd();
		AllBattlersF[i].statbaseDArr[9] = e[i].getSPRd();
		AllBattlersF[i].statbaseDArr[10] = e[i].getSTRd();
		AllBattlersF[i].statbaseDArr[11] = e[i].getENDd();
		AllBattlersF[i].statbaseDArr[12] = e[i].getCONd();

		//for weapoFns 
		AllBattlersF[i].wepstatAdd[0][0] = NULL;
		AllBattlersF[i].wepstatAdd[0][1] = NULL;
		AllBattlersF[i].wepstatAdd[0][2] = NULL;
		AllBattlersF[i].wepstatAdd[1][0] = NULL;
		AllBattlersF[i].wepstatAdd[1][1] = NULL;
		AllBattlersF[i].wepstatAdd[1][2] = NULL;
		AllBattlersF[i].wepstatAdd[2][0] = NULL;
		AllBattlersF[i].wepstatAdd[2][1] = NULL;
		AllBattlersF[i].wepstatAdd[2][2] = NULL;
		AllBattlersF[i].wepstatAdd[3][0] = NULL;
		AllBattlersF[i].wepstatAdd[3][1] = NULL;
		AllBattlersF[i].wepstatAdd[3][2] = NULL;
		AllBattlersF[i].wepstatAdd[4][0] = NULL;
		AllBattlersF[i].wepstatAdd[4][1] = NULL;
		AllBattlersF[i].wepstatAdd[4][2] = NULL;
		AllBattlersF[i].wepstatAdd[5][0] = NULL;
		AllBattlersF[i].wepstatAdd[5][1] = NULL;
		AllBattlersF[i].wepstatAdd[5][2] = NULL;
		AllBattlersF[i].wepstatAdd[6][0] = NULL;
		AllBattlersF[i].wepstatAdd[6][1] = NULL;
		AllBattlersF[i].wepstatAdd[6][2] = NULL;
		AllBattlersF[i].wepstatAdd[7][0] = NULL;
		AllBattlersF[i].wepstatAdd[7][1] = NULL;
		AllBattlersF[i].wepstatAdd[7][2] = NULL;
		AllBattlersF[i].wepstatAdd[8][0] = NULL;
		AllBattlersF[i].wepstatAdd[8][1] = NULL;
		AllBattlersF[i].wepstatAdd[8][2] = NULL;
		AllBattlersF[i].wepstatAdd[9][0] = NULL;
		AllBattlersF[i].wepstatAdd[9][1] = NULL;
		AllBattlersF[i].wepstatAdd[9][2] = NULL;
		AllBattlersF[i].wepstatAdd[10][0] = NULL;
		AllBattlersF[i].wepstatAdd[10][1] = NULL;
		AllBattlersF[i].wepstatAdd[10][2] = NULL;
		AllBattlersF[i].wepstatAdd[11][0] = NULL;
		AllBattlersF[i].wepstatAdd[11][1] = NULL;
		AllBattlersF[i].wepstatAdd[11][2] = NULL;
		AllBattlersF[i].wepstatAdd[12][0] = NULL;
		AllBattlersF[i].wepstatAdd[12][1] = NULL;
		AllBattlersF[i].wepstatAdd[12][2] = NULL;
		AllBattlersF[i].wepstatAdd[13][0] = NULL;
		AllBattlersF[i].wepstatAdd[13][1] = NULL;
		AllBattlersF[i].wepstatAdd[13][2] = NULL;
		AllBattlersF[i].wepstatAdd[14][0] = NULL;
		AllBattlersF[i].wepstatAdd[14][1] = NULL;
		AllBattlersF[i].wepstatAdd[14][2] = NULL;
		AllBattlersF[i].wepstatAdd[14][0] = NULL;
		AllBattlersF[i].wepstatAdd[14][1] = NULL;
		AllBattlersF[i].wepstatAdd[14][2] = NULL;

		// for armors 
		AllBattlersF[i].armstatAdd[0][0] = NULL;
		AllBattlersF[i].armstatAdd[0][1] = NULL;
		AllBattlersF[i].armstatAdd[0][2] = NULL;
		AllBattlersF[i].armstatAdd[1][0] = NULL;
		AllBattlersF[i].armstatAdd[1][1] = NULL;
		AllBattlersF[i].armstatAdd[1][2] = NULL;
		AllBattlersF[i].armstatAdd[2][0] = NULL;
		AllBattlersF[i].armstatAdd[2][1] = NULL;
		AllBattlersF[i].armstatAdd[2][2] = NULL;
		AllBattlersF[i].armstatAdd[3][0] = NULL;
		AllBattlersF[i].armstatAdd[3][1] = NULL;
		AllBattlersF[i].armstatAdd[3][2] = NULL;
		AllBattlersF[i].armstatAdd[4][0] = NULL;
		AllBattlersF[i].armstatAdd[4][1] = NULL;
		AllBattlersF[i].armstatAdd[4][2] = NULL;
		AllBattlersF[i].armstatAdd[5][0] = NULL;
		AllBattlersF[i].armstatAdd[5][1] = NULL;
		AllBattlersF[i].armstatAdd[5][2] = NULL;
		AllBattlersF[i].armstatAdd[6][0] = NULL;
		AllBattlersF[i].armstatAdd[6][1] = NULL;
		AllBattlersF[i].armstatAdd[6][2] = NULL;
		AllBattlersF[i].armstatAdd[7][0] = NULL;
		AllBattlersF[i].armstatAdd[7][1] = NULL;
		AllBattlersF[i].armstatAdd[7][2] = NULL;
		AllBattlersF[i].armstatAdd[8][0] = NULL;
		AllBattlersF[i].armstatAdd[8][1] = NULL;
		AllBattlersF[i].armstatAdd[8][2] = NULL;
		AllBattlersF[i].armstatAdd[9][0] = NULL;
		AllBattlersF[i].armstatAdd[9][1] = NULL;
		AllBattlersF[i].armstatAdd[9][2] = NULL;
		AllBattlersF[i].armstatAdd[10][0] = NULL;
		AllBattlersF[i].armstatAdd[10][1] = NULL;
		AllBattlersF[i].armstatAdd[10][2] = NULL;
		AllBattlersF[i].armstatAdd[11][0] = NULL;
		AllBattlersF[i].armstatAdd[11][1] = NULL;
		AllBattlersF[i].armstatAdd[11][2] = NULL;
		AllBattlersF[i].armstatAdd[12][0] = NULL;
		AllBattlersF[i].armstatAdd[12][1] = NULL;
		AllBattlersF[i].armstatAdd[12][2] = NULL;
		AllBattlersF[i].armstatAdd[13][0] = NULL;
		AllBattlersF[i].armstatAdd[13][1] = NULL;
		AllBattlersF[i].armstatAdd[13][2] = NULL;
		AllBattlersF[i].armstatAdd[14][0] = NULL;
		AllBattlersF[i].armstatAdd[14][1] = NULL;
		AllBattlersF[i].armstatAdd[14][2] = NULL;
		AllBattlersF[i].armstatAdd[14][0] = NULL;
		AllBattlersF[i].armstatAdd[14][1] = NULL;
		AllBattlersF[i].armstatAdd[14][2] = NULL;
		++battlerC;
	}
	++teamAdd;
	for (int i = 0; i < countp; i++)
	{
		AllBattlers[i].name = p[i].getName();

		AllBattlers[i].statbaseArr[0] = p[i].getHp();
		AllBattlers[i].statbaseArr[1] = p[i].getSp();
		AllBattlers[i].statbaseArr[2] = p[i].getFp();
		AllBattlers[i].statbaseArr[3] = p[i].getAp();
		AllBattlers[i].statbaseArr[4] = p[i].getDp();
		AllBattlers[i].statbaseArr[5] = p[i].getAtk();
		AllBattlers[i].statbaseArr[6] = p[i].getDEF();
		AllBattlers[i].statbaseArr[7] = p[i].getSPD();
		AllBattlers[i].statbaseArr[8] = p[i].getAGI();
		AllBattlers[i].statbaseArr[9] = p[i].getDEX();
		AllBattlers[i].statbaseArr[10] = p[i].getINT();
		AllBattlers[i].statbaseArr[11] = p[i].getSPR();
		AllBattlers[i].statbaseArr[12] = p[i].getSTR();
		AllBattlers[i].statbaseArr[13] = p[i].getEND();
		AllBattlers[i].statbaseArr[14] = p[i].getCON();
		AllBattlers[i].team = teamAdd;

		// ded
		AllBattlers[i].statbaseDArr[0] = p[i].getHpd();
		AllBattlers[i].statbaseDArr[1] = p[i].getSpd();
		AllBattlers[i].statbaseDArr[2] = p[i].getFpd();
		AllBattlers[i].statbaseDArr[3] = p[i].getATKd();
		AllBattlers[i].statbaseDArr[4] = p[i].getDEFd();
		AllBattlers[i].statbaseDArr[5] = p[i].getSPDd();
		AllBattlers[i].statbaseDArr[6] = p[i].getAGId();
		AllBattlers[i].statbaseDArr[7] = p[i].getDEXd();
		AllBattlers[i].statbaseDArr[8] = p[i].getINTd();
		AllBattlers[i].statbaseDArr[9] = p[i].getSPRd();
		AllBattlers[i].statbaseDArr[10] = p[i].getSTRd();
		AllBattlers[i].statbaseDArr[11] = p[i].getENDd();
		AllBattlers[i].statbaseDArr[12] = p[i].getCONd();

		// for weapons 
		AllBattlers[i].wepNames[0] = p[i].weapons[0].name;
		AllBattlers[i].wepNames[1] = p[i].weapons[1].name;
		AllBattlers[i].wepNames[2] = p[i].weapons[2].name;

		AllBattlers[i].wepstatAdd[0][0] = p[i].weapons->maxhp;
		AllBattlers[i].wepstatAdd[0][1] = p[i].weapons->maxhp;
		AllBattlers[i].wepstatAdd[0][2] = p[i].weapons->maxhp;

		AllBattlers[i].wepstatAdd[1][0] = p[i].weapons->maxsp;
		AllBattlers[i].wepstatAdd[1][1] = p[i].weapons->maxsp;
		AllBattlers[i].wepstatAdd[1][2] = p[i].weapons->maxsp;

		AllBattlers[i].wepstatAdd[2][0] = p[i].weapons->fp;
		AllBattlers[i].wepstatAdd[2][1] = p[i].weapons->fp;
		AllBattlers[i].wepstatAdd[2][2] = p[i].weapons->fp;

		AllBattlers[i].wepstatAdd[3][0] = p[i].weapons->ap;
		AllBattlers[i].wepstatAdd[3][1] = p[i].weapons->ap;
		AllBattlers[i].wepstatAdd[3][2] = p[i].weapons->ap;

		AllBattlers[i].wepstatAdd[4][0] = p[i].weapons->atk;
		AllBattlers[i].wepstatAdd[4][1] = p[i].weapons->atk;
		AllBattlers[i].wepstatAdd[4][2] = p[i].weapons->atk;

		AllBattlers[i].wepstatAdd[5][0] = p[i].weapons->def;
		AllBattlers[i].wepstatAdd[5][1] = p[i].weapons->def;
		AllBattlers[i].wepstatAdd[5][2] = p[i].weapons->def;

		AllBattlers[i].wepstatAdd[6][0] = p[i].weapons->speed;
		AllBattlers[i].wepstatAdd[6][1] = p[i].weapons->speed;
		AllBattlers[i].wepstatAdd[6][2] = p[i].weapons->speed;

		AllBattlers[i].wepstatAdd[7][0] = p[i].weapons->agi;
		AllBattlers[i].wepstatAdd[7][1] = p[i].weapons->agi;
		AllBattlers[i].wepstatAdd[7][2] = p[i].weapons->agi;

		AllBattlers[i].wepstatAdd[8][0] = p[i].weapons->dex;
		AllBattlers[i].wepstatAdd[8][1] = p[i].weapons->dex;
		AllBattlers[i].wepstatAdd[8][2] = p[i].weapons->dex;

		AllBattlers[i].wepstatAdd[9][0] = p[i].weapons->intel;
		AllBattlers[i].wepstatAdd[9][1] = p[i].weapons->intel;
		AllBattlers[i].wepstatAdd[9][2] = p[i].weapons->intel;

		AllBattlers[i].wepstatAdd[10][0] = p[i].weapons->spr;
		AllBattlers[i].wepstatAdd[10][1] = p[i].weapons->spr;
		AllBattlers[i].wepstatAdd[10][2] = p[i].weapons->spr;

		AllBattlers[i].wepstatAdd[11][0] = p[i].weapons->str;
		AllBattlers[i].wepstatAdd[11][1] = p[i].weapons->str;
		AllBattlers[i].wepstatAdd[11][2] = p[i].weapons->str;

		AllBattlers[i].wepstatAdd[12][0] = p[i].weapons->end;
		AllBattlers[i].wepstatAdd[12][1] = p[i].weapons->end;
		AllBattlers[i].wepstatAdd[12][2] = p[i].weapons->end;

		AllBattlers[i].wepstatAdd[13][0] = p[i].weapons->con;
		AllBattlers[i].wepstatAdd[13][1] = p[i].weapons->con;
		AllBattlers[i].wepstatAdd[13][2] = p[i].weapons->con;

		AllBattlers[i].wepstatAdd[14][0] = p[i].weapons->value;
		AllBattlers[i].wepstatAdd[14][1] = p[i].weapons->value;
		AllBattlers[i].wepstatAdd[14][2] = p[i].weapons->value;

		AllBattlers[i].armorNames[0] = p[i].armors[0].name;
		AllBattlers[i].armorNames[1] = p[i].armors[1].name;
		AllBattlers[i].armorNames[2] = p[i].armors[2].name;

		AllBattlers[i].armstatAdd[0][0] = p[i].armors->maxhp;
		AllBattlers[i].armstatAdd[0][1] = p[i].armors->maxhp;
		AllBattlers[i].armstatAdd[0][2] = p[i].armors->maxhp;

		AllBattlers[i].armstatAdd[1][0] = p[i].armors->maxsp;
		AllBattlers[i].armstatAdd[1][1] = p[i].armors->maxsp;
		AllBattlers[i].armstatAdd[1][2] = p[i].armors->maxsp;

		AllBattlers[i].armstatAdd[2][0] = p[i].armors->fp;
		AllBattlers[i].armstatAdd[2][1] = p[i].armors->fp;
		AllBattlers[i].armstatAdd[2][2] = p[i].armors->fp;

		AllBattlers[i].armstatAdd[3][0] = p[i].armors->ap;
		AllBattlers[i].armstatAdd[3][1] = p[i].armors->ap;
		AllBattlers[i].armstatAdd[3][2] = p[i].armors->ap;

		AllBattlers[i].armstatAdd[4][0] = p[i].armors->atk;
		AllBattlers[i].armstatAdd[4][1] = p[i].armors->atk;
		AllBattlers[i].armstatAdd[4][2] = p[i].armors->atk;

		AllBattlers[i].armstatAdd[5][0] = p[i].armors->def;
		AllBattlers[i].armstatAdd[5][1] = p[i].armors->def;
		AllBattlers[i].armstatAdd[5][2] = p[i].armors->def;

		AllBattlers[i].armstatAdd[6][0] = p[i].armors->speed;
		AllBattlers[i].armstatAdd[6][1] = p[i].armors->speed;
		AllBattlers[i].armstatAdd[6][2] = p[i].armors->speed;

		AllBattlers[i].armstatAdd[7][0] = p[i].armors->agi;
		AllBattlers[i].armstatAdd[7][1] = p[i].armors->agi;
		AllBattlers[i].armstatAdd[7][2] = p[i].armors->agi;

		AllBattlers[i].armstatAdd[8][0] = p[i].armors->dex;
		AllBattlers[i].armstatAdd[8][1] = p[i].armors->dex;
		AllBattlers[i].armstatAdd[8][2] = p[i].armors->dex;

		AllBattlers[i].armstatAdd[9][0] = p[i].armors->intel;
		AllBattlers[i].armstatAdd[9][1] = p[i].armors->intel;
		AllBattlers[i].armstatAdd[9][2] = p[i].armors->intel;

		AllBattlers[i].armstatAdd[10][0] = p[i].armors->intel;
		AllBattlers[i].armstatAdd[10][1] = p[i].armors->intel;
		AllBattlers[i].armstatAdd[10][2] = p[i].armors->intel;

		AllBattlers[i].armstatAdd[10][0] = p[i].armors->spr;
		AllBattlers[i].armstatAdd[10][1] = p[i].armors->spr;
		AllBattlers[i].armstatAdd[10][2] = p[i].armors->spr;

		AllBattlers[i].armstatAdd[11][0] = p[i].armors->str;
		AllBattlers[i].armstatAdd[11][1] = p[i].armors->str;
		AllBattlers[i].armstatAdd[11][2] = p[i].armors->str;

		AllBattlers[i].armstatAdd[12][0] = p[i].armors->end;
		AllBattlers[i].armstatAdd[12][1] = p[i].armors->end;
		AllBattlers[i].armstatAdd[12][2] = p[i].armors->end;

		AllBattlers[i].armstatAdd[13][0] = p[i].armors->con;
		AllBattlers[i].armstatAdd[13][1] = p[i].armors->con;
		AllBattlers[i].armstatAdd[13][2] = p[i].armors->con;

		AllBattlers[i].armstatAdd[14][0] = p[i].armors->value;
		AllBattlers[i].armstatAdd[14][1] = p[i].armors->value;
		AllBattlers[i].armstatAdd[14][2] = p[i].armors->value;

		// a struct convert here
		//HOT.push_front();
		++battlerC;
	}

	// setting all battlers speeds for turns
	for (int i = 0; i < countp; i++)
	{
		SpdArr.push_front(AllBattlers[i].statbaseDArr[5]);
	}

	for (int i = 0; i < counte; i++)
	{
		SpdArr.push_front(AllBattlersF[i].statbaseDArr[5]);
	}

	SpdArr.sort(); // who goes first

	// battlers list COMBINED from origin AND F
	for (size_t i = 0; i < countp; i++)
	{
		AllBattlersList.push_front(AllBattlers[i]);
	}
	for (size_t i = 0; i < counte; i++)
	{
		AllBattlersList.push_front(AllBattlersF[i]);
	}

	// turn hierarchy setup
	for (std::list<int>::iterator it 
		= SpdArr.begin(); it != SpdArr.end(); ++it)
	{
		for (std::list<Battler>::iterator it = 
			AllBattlersList.begin(); it != AllBattlersList.end(); ++it)
		{
			if (it->statbaseDArr[5] == SpdArr.front())
			{
				HOT.push_front(it->name);
			}
		}
	}

	// you're actually poping off the
	// bottom after every turn from now on..
	// turn order TIME!!!

}

BattleMode::Task BattleMode::gatherThisBattlersEnemies(Battler d)
{
	Task me;
	for (std::list<Battler>::iterator jd = 
		AllBattlersList.begin(); jd != AllBattlersList.end(); ++jd)
	{
		if (jd->team != d.team)
		{
			me.enemyR.push_front(jd.operator*());
		}
	}
	return me;
}

int BattleMode::gatherAllEnemyHpds(Task task_target)
{
	int sum = 0;
	for (std::list<Battler>::iterator jd = 
		task_target.enemyR.begin(); jd != task_target.enemyR.end(); ++jd)
	{
		sum += jd->statbaseDArr[0];
	}
	return sum;
}

int BattleMode::gatherAllEnemySpds(Battler c, Task task_target)
{
	int sum = 0;
	for (std::list<Battler>::iterator jd = 
		task_target.enemyR.begin(); jd != task_target.enemyR.end(); ++jd)
	{
		sum += jd->statbaseDArr[5];
	}
	return sum;
}

bool BattleMode::determineEscape()
{
	return false;
}

bool BattleMode::determineHit(Battler, Task)
{
	return false;
}

int BattleMode::defRating(Battler, Task)
{
	return 0;
}

void BattleMode::itemReturnValue(Battler, Task)
{
}

void BattleMode::hackDotExe(Battler, Task)
{
}

void BattleMode::addSummonB(Battler, Task)
{
}

void BattleMode::specialTechPwr(Battler, Task)
{
}

void BattleMode::skillPwr(Battler, Task)
{
}

void BattleMode::actionEff(Battler, Task)
{
}

void BattleMode::magicEff(Battler, Task)
{
}

void BattleMode::ReOrderSettto()
{
	if (SpdArr.empty() && !SpdArrCpy.empty())
	{
		for (int i = 0; i < SpdArrCpy.size(); i++)
		{
			for (std::list<Battler>::iterator it = AllBattlersList.begin(); it != AllBattlersList.end(); ++it)
			{
				if (!(it->statbaseDArr[0] <= 0))
				{
					SpdArr.push_front(SpdArrCpy.front());
				}
				else
				{
					it->name = ""; // kill list up next
					UpdateAT(AllBattlersList.front());
					AllBattlersList.pop_front();
				}
			}
			SpdArrCpy.pop_front();
		}
	}
	else 
	{
		for (int i = 0; i < AllBattlersList.size(); i++)
		{
			if (!(AllBattlersList.front().statbaseDArr[0] <= 0))
			{
				SpdArr.push_front(AllBattlersList.front().statbaseDArr[5]);
			}
			else
			{
				UpdateAT(AllBattlersList.front());
				AllBattlersList.pop_front();
			}

		}
	}
	for (std::list<Battler>::iterator it = AllBattlersList.begin(); it != AllBattlersList.end(); ++it)
	{
		if (it->name.empty())
		{
			AllBattlersList.erase(it);
		}
	}
	SpdArr.sort();
}

void BattleMode::TurnCheck()
{
	for (std::list<Battler>::iterator it = AllBattlersList.begin(); it != AllBattlersList.end(); ++it)
	{
		// collecting the multiples
		for (std::list<Battler>::iterator irt = AllBattlersList.begin(); irt != AllBattlersList.end(); ++irt)
		{
			if (irt->statbaseDArr[5] == it->statbaseDArr[5] && irt->name == it->name)
			{
				this->MbL.push_front(it.operator*());
				this->MbL.push_front(irt.operator*());
			}
		}
		system("CLS");
			
			if (SpdArr.back() == it->statbaseDArr[5])
			{
				SpdArr.pop_back();
				HOT.pop_back();
				this->MbL.push_front(it.operator*());
			}
	}
	phaseTrigger(TCII);
}

void BattleMode::TurnCheckII() // this doesn't go back on the latter of phases
{
	cout << HOT.back() << "'s TURN! s(Next Turn) " << HOT.back() << endl;
	// find out who's turn it is...
	
	switch (MbL.back().team)
	{
	case 0: // bad bois
		aiTurn();
		HOT.pop_back();
		break;
	case 1: // your bois
		playerturnCall(MbL.back());
		HOT.pop_back();
		break;
	default: // other bois
		turnCallPVP();
		HOT.pop_back();
		break;
	}
	
}

/// <summary>
	/// this is inside of TurnCall this setup the target and 
	/// selection so that the task can be stored...
	/// dont bother pushing anything to the tasklist
	/// thats been done..
	/// </summary>
	/// <param name="newTask"></param>
	/// <returns></returns>
BattleMode::Task BattleMode::newTask(char ip, Battler d)
{
	char de;
	Task doing;
	de = ip;
	
	switch (de)
	{
	case 'a':
		Attack(d, 0);
		break;
	case 'd':
		Defend(d, 0);
		break;
	case 's':
		//cout << d.name << " uses the skill... " << endl; hold on.. pop off the taskbase please..
		SkillC(d, doing); // change this to the generic command?
		break;
	case 't':
		ActionC(d, doing);
		break;
	case 'h':
		HackC(d, doing);
		break;
	case 'q':
		STC(d, doing);
		break;
	case 'u':
		SummonC(doing /*self target*/);
		break;
	case 'i':
		ItemMenu(d, 0);
		break;
	case 'e':
		STC(d, doing);
		break;
	default:
		de = 'd';
		system("PAUSE");
		newTask(de);
		break;
	}
	return doing;
}

void BattleMode::turnCallPVP()
{
	for (std::list<Battler>::reverse_iterator 
		it = AllBattlersList.rbegin(); 
		it != AllBattlersList.rend(); ++it)
	{
		if (it->name == HOT.back())
		{
			char choice{};
			switch (it->team)
			{
				// ai turn
			case 0:
				phaseTrigger(ET);
				break;
			default:
				system("CLS");
				cout << it->name << ": ORE NO TAN!" << endl;
				cout << "\n\tSelect an option using a key!" << endl;
				cout << endl;
				cout << "(Attack) (a)" << endl;
				cout << "(Defend) (d)" << endl;
				cout << "(Skill)  (s)" << endl;
				cout << "(Action) (t)" << endl;
				cout << "(Hack)   (h)" << endl;
				cout << "(ST)     (q)" << endl;
				cout << "(Psi)	  (p)" << endl;
				cout << "(Summon) (u)" << endl;
				cout << "(Item)   (i)" << endl;
				cout << "(Escape) (e)" << endl;
				// change armr
				cout << "(ChangeArmr) (ca)" << endl;
				// wep
				cout << "(ChangeWep) (cw)" << endl;
				// items
				cout << "(ChangeItms) (ci)" << endl;
				cin >> choice;
				ActionIN(newTask(choice));
				
				break;
			}
		}
	}
}

void BattleMode::playerturnCall(Battler a)
{
	char choice{};
	switch (a.team)
	{
	case 0:
		// ai turn
		phaseTrigger(ET);
		break;
	default:
		
		system("CLS");
		cout << a.name << ": ORE NO TAN!" << endl;
		cout << "\n\tSelect an option using a key!" << endl;
		cout << endl;
		cout << "(Attack) (a)" << endl;
		cout << "(Defend) (d)" << endl;
		cout << "(Skill)  (s)" << endl;
		cout << "(Action) (t)" << endl;
		cout << "(Hack)   (h)" << endl;
		cout << "(ST)     (q)" << endl;
		cout << "(Psi)	  (p)" << endl;
		cout << "(Summon) (u)" << endl;
		cout << "(Item)   (i)" << endl;
		cout << "(Escape) (e)" << endl;
		cin >> choice;
		switch (choice)
		{
		case 'a':
			ActionIN(newTask(choice, a)); // here it begins
			break;
		case 'd':
			ActionIN(newTask(choice, a)); // here it begins
			break;
		case 's':
			ActionIN(newTask(choice, a)); // here it begins
			break;
		case 't':
			ActionIN(newTask(choice, a)); // here it begins
			break;
		case 'h':
			ActionIN(newTask(choice, a)); // here it begins
			break;
		case 'q':
			ActionIN(newTask(choice, a)); // here it begins
			break;
		case 'p':
			ActionIN(newTask(choice, a));
			break;
		case 'u':
			ActionIN(newTask(choice, a)); // here it begins
			break;
		case 'i':
			ActionIN(newTask(choice, a)); // here it begins
			break;
		case 'e':
			ActionIN(newTask(choice, a)); // here it begins
			break;
		default:
			cout << "OK ITS YOUR TURN. Calm down I know you're excited.."
				<< "Geez.. \n Now please choose a valid choice." << endl;
			playerturnCall(a);
			break;
		}
		break;
	}
}

void BattleMode::aiTurn()
{
	switch (AllBattlersList.back().team)
	{
	case 0:
		// ai time
		aiTurn(AllBattlersList.back());
		break;
	default: 
		// this is if this thing glitches
		cout << "Turn skipped?" << endl;
		phaseTrigger(T1P);
		break;
	}
}

void BattleMode::multiturnCalc()
{
	switch (MbL.back().team)
	{
	case 0:

		break;

	case 1:
		break;
	}
}

void BattleMode::multiTurnCall()
{
	for (std::list<Battler>::iterator it = MbL.begin(); it != MbL.end(); ++it)
	{
		cout << it->name << "Now share a turn" << endl;
	}

	for (std::list<Battler>::iterator it = MbL.begin(); it != MbL.end(); ++it)
	{
		if (it->statbaseDArr[5] == SpdArr.back()) // from greatest to least
		{
			SpdArr.pop_back();
			switch (it->team)
			{
			case 0:
				aiTurn(it.operator*());
				break;
			default:
				playerturnCall(it.operator*());
				break;
			}
		}
	}
	multiturnCalc();
}

// updates a single battler
void BattleMode::UpdateALL() // run this alot
{
	for (std::list<Battler>::iterator jW = AllBattlersList.begin(); jW != AllBattlersList.end(); ++jW)
	{
		switch (jW->team)
		{
		case 0:
			for (std::list<Enemy>::iterator it = troop.begin(); it != troop.end(); ++it)
			{
				if (it->name == jW->name)
				{
					//update all stats and everything else
					it->setName(jW->name);
					it->hp = jW->statbaseArr[0];
					it->sp = jW->statbaseArr[1];
					it->fp = jW->statbaseArr[2];
					it->ap = jW->statbaseArr[3];
					it->dp = jW->statbaseArr[4];
					it->ATK = jW->statbaseArr[5];
					it->DEF = jW->statbaseArr[6];
					it->SPEED = jW->statbaseArr[7];
					it->AGI = jW->statbaseArr[8];
					it->DEX = jW->statbaseArr[9];
					it->INT = jW->statbaseArr[10];
					it->SPR = jW->statbaseArr[11];
					it->STR = jW->statbaseArr[12];
					it->END = jW->statbaseArr[13];
					it->CON = jW->statbaseArr[14];

					// ded
					it->hpd = jW->statbaseDArr[0];
					it->spd = jW->statbaseDArr[1];
					it->fpd = jW->statbaseDArr[2];
					it->ATKd = jW->statbaseDArr[3];
					it->DEFd = jW->statbaseDArr[4];
					it->SPEEDd = jW->statbaseDArr[5];
					it->AGId = jW->statbaseDArr[6];
					it->DEXd = jW->statbaseDArr[7];
					it->INTd = jW->statbaseDArr[8];
					it->SPRd = jW->statbaseDArr[9];
					it->STRd = jW->statbaseDArr[10];
					it->ENDd = jW->statbaseDArr[11];
					it->CONd = jW->statbaseDArr[12];
				}
			}
			break;
		default:
			for (std::list<PartyActor>::iterator it = Wp.begin(); it != Wp.end(); ++it)
			{
				if (it->name == jW->name)
				{
					//update all stats and everything else
					it->setName(jW->name);
					it->hp = jW->statbaseArr[0];
					it->sp = jW->statbaseArr[1];
					it->fp = jW->statbaseArr[2];
					it->ap = jW->statbaseArr[3];
					it->dp = jW->statbaseArr[4];
					it->ATK = jW->statbaseArr[5];
					it->DEF = jW->statbaseArr[6];
					it->SPEED = jW->statbaseArr[7];
					it->AGI = jW->statbaseArr[8];
					it->DEX = jW->statbaseArr[9];
					it->INT = jW->statbaseArr[10];
					it->SPR = jW->statbaseArr[11];
					it->STR = jW->statbaseArr[12];
					it->END = jW->statbaseArr[13];
					it->CON = jW->statbaseArr[14];

					// ded
					it->hpd = jW->statbaseDArr[0];
					it->spd = jW->statbaseDArr[1];
					it->fpd = jW->statbaseDArr[2];
					it->ATKd = jW->statbaseDArr[3];
					it->DEFd = jW->statbaseDArr[4];
					it->SPEEDd = jW->statbaseDArr[5];
					it->AGId = jW->statbaseDArr[6];
					it->DEXd = jW->statbaseDArr[7];
					it->INTd = jW->statbaseDArr[8];
					it->SPRd = jW->statbaseDArr[9];
					it->STRd = jW->statbaseDArr[10];
					it->ENDd = jW->statbaseDArr[11];
					it->CONd = jW->statbaseDArr[12];

					// for weapons 
					it->weapons[0].name = jW->wepNames[0];
					it->weapons[1].name = jW->wepNames[1];
					it->weapons[2].name = jW->wepNames[2];

					it->weapons[0].maxhp = jW->wepstatAdd[0][0];
					it->weapons[1].maxhp = jW->wepstatAdd[0][1];
					it->weapons[2].maxhp = jW->wepstatAdd[0][2];

					it->weapons[0].maxsp = jW->wepstatAdd[1][0];
					it->weapons[1].maxsp = jW->wepstatAdd[1][1];
					it->weapons[2].maxsp = jW->wepstatAdd[1][2];

					it->weapons[0].fp = jW->wepstatAdd[2][0];
					it->weapons[1].fp = jW->wepstatAdd[2][1];
					it->weapons[2].fp = jW->wepstatAdd[2][2];

					it->weapons[0].ap = jW->wepstatAdd[3][0];
					it->weapons[1].ap = jW->wepstatAdd[3][1];
					it->weapons[2].ap = jW->wepstatAdd[3][2];

					it->weapons[0].atk = jW->wepstatAdd[4][0];
					it->weapons[1].atk = jW->wepstatAdd[4][1];
					it->weapons[2].atk = jW->wepstatAdd[4][2];

					it->weapons[0].def = jW->wepstatAdd[5][0];
					it->weapons[1].def = jW->wepstatAdd[5][1];
					it->weapons[2].def = jW->wepstatAdd[5][2];

					it->weapons[0].speed = jW->wepstatAdd[6][0];
					it->weapons[1].speed = jW->wepstatAdd[6][1];
					it->weapons[2].speed = jW->wepstatAdd[6][2];

					it->weapons[0].agi = jW->wepstatAdd[7][0];
					it->weapons[1].agi = jW->wepstatAdd[7][1];
					it->weapons[2].agi = jW->wepstatAdd[7][2];

					it->weapons[0].dex = jW->wepstatAdd[8][0];
					it->weapons[1].dex = jW->wepstatAdd[8][1];
					it->weapons[2].dex = jW->wepstatAdd[8][2];

					it->weapons[0].intel = jW->wepstatAdd[9][0];
					it->weapons[1].intel = jW->wepstatAdd[9][1];
					it->weapons[2].intel = jW->wepstatAdd[9][2];

					it->weapons[0].spr = jW->wepstatAdd[10][0];
					it->weapons[1].spr = jW->wepstatAdd[10][1];
					it->weapons[2].spr = jW->wepstatAdd[10][2];

					it->weapons[0].str = jW->wepstatAdd[11][0];
					it->weapons[1].str = jW->wepstatAdd[11][1];
					it->weapons[2].str = jW->wepstatAdd[11][2];

					it->weapons[0].end = jW->wepstatAdd[12][0];
					it->weapons[1].end = jW->wepstatAdd[12][1];
					it->weapons[2].end = jW->wepstatAdd[12][2];

					it->weapons[0].con = jW->wepstatAdd[13][0];
					it->weapons[1].con = jW->wepstatAdd[13][1];
					it->weapons[2].con = jW->wepstatAdd[13][2];

					it->weapons[0].value = jW->wepstatAdd[14][0];
					it->weapons[1].value = jW->wepstatAdd[14][1];
					it->weapons[2].value = jW->wepstatAdd[14][2];

					it->armors[0].name = jW->armorNames[0];
					it->armors[1].name = jW->armorNames[1];
					it->armors[2].name = jW->armorNames[2];

					it->armors[0].maxhp = jW->armstatAdd[0][0];
					it->armors[1].maxhp = jW->armstatAdd[0][1];
					it->armors[2].maxhp = jW->armstatAdd[0][2];

					it->armors[0].maxsp = jW->armstatAdd[1][0];
					it->armors[1].maxsp = jW->armstatAdd[1][1];
					it->armors[2].maxsp = jW->armstatAdd[1][2];

					it->armors[0].fp = jW->armstatAdd[2][0];
					it->armors[1].fp = jW->armstatAdd[2][1];
					it->armors[2].fp = jW->armstatAdd[2][2];

					it->armors[0].ap = jW->armstatAdd[3][0];
					it->armors[1].ap = jW->armstatAdd[3][1];
					it->armors[2].ap = jW->armstatAdd[3][2];

					it->armors[0].atk = jW->armstatAdd[4][0];
					it->armors[1].atk = jW->armstatAdd[4][1];
					it->armors[2].atk = jW->armstatAdd[4][2];

					it->armors[0].def = jW->armstatAdd[5][0];
					it->armors[1].def = jW->armstatAdd[5][1];
					it->armors[2].def = jW->armstatAdd[5][2];

					it->armors[0].speed = jW->armstatAdd[6][0];
					it->armors[1].speed = jW->armstatAdd[6][1];
					it->armors[2].speed = jW->armstatAdd[6][2];

					it->armors[0].agi = jW->armstatAdd[7][0];
					it->armors[1].agi = jW->armstatAdd[7][1];
					it->armors[2].agi = jW->armstatAdd[7][2];

					it->armors[0].dex = jW->armstatAdd[8][0];
					it->armors[1].dex = jW->armstatAdd[8][1];
					it->armors[2].dex = jW->armstatAdd[8][2];

					it->armors[0].intel = jW->armstatAdd[9][0];
					it->armors[1].intel = jW->armstatAdd[9][1];
					it->armors[2].intel = jW->armstatAdd[9][2];

					it->armors[0].spr = jW->armstatAdd[10][0];
					it->armors[1].spr = jW->armstatAdd[10][1];
					it->armors[2].spr = jW->armstatAdd[10][2];

					it->armors[0].str = jW->armstatAdd[11][0];
					it->armors[1].str = jW->armstatAdd[11][1];
					it->armors[2].str = jW->armstatAdd[11][2];

					it->armors[0].end = jW->armstatAdd[12][0];
					it->armors[1].end = jW->armstatAdd[12][1];
					it->armors[2].end = jW->armstatAdd[12][2];

					it->armors[0].con = jW->armstatAdd[13][0];
					it->armors[1].con = jW->armstatAdd[13][1];
					it->armors[2].con = jW->armstatAdd[13][2];

					it->armors[0].value = jW->armstatAdd[14][0];
					it->armors[1].value = jW->armstatAdd[14][1];
					it->armors[2].value = jW->armstatAdd[14][2];
				}
			}
			break;
		}
	}
}

void BattleMode::UpdateAT(Battler jW)
{
	switch (jW.team)
	{
	case 0:
		for (std::list<Enemy>::iterator it = troop.begin(); it != troop.end(); ++it)
		{
			if (it->name == jW.name)
			{
				//update all stats and everything else
				it->setName(jW.name);
				it->hp = jW.statbaseArr[0];
				it->sp = jW.statbaseArr[1];
				it->fp = jW.statbaseArr[2];
				it->ap = jW.statbaseArr[3];
				it->dp = jW.statbaseArr[4];
				it->ATK = jW.statbaseArr[5];
				it->DEF = jW.statbaseArr[6];
				it->SPEED = jW.statbaseArr[7];
				it->AGI = jW.statbaseArr[8];
				it->DEX = jW.statbaseArr[9];
				it->INT = jW.statbaseArr[10];
				it->SPR = jW.statbaseArr[11];
				it->STR = jW.statbaseArr[12];
				it->END = jW.statbaseArr[13];
				it->CON = jW.statbaseArr[14];

				// ded
				it->hpd = jW.statbaseDArr[0];
				it->spd = jW.statbaseDArr[1];
				it->fpd = jW.statbaseDArr[2];
				it->ATKd = jW.statbaseDArr[3];
				it->DEFd = jW.statbaseDArr[4];
				it->SPEEDd = jW.statbaseDArr[5];
				it->AGId = jW.statbaseDArr[6];
				it->DEXd = jW.statbaseDArr[7];
				it->INTd = jW.statbaseDArr[8];
				it->SPRd = jW.statbaseDArr[9];
				it->STRd = jW.statbaseDArr[10];
				it->ENDd = jW.statbaseDArr[11];
				it->CONd = jW.statbaseDArr[12];
			}
		}
		break;
	default:
		for (std::list<PartyActor>::iterator it = Wp.begin(); it != Wp.end(); ++it)
		{
			if (it->name == jW.name)
			{
				//update all stats and everything else
				it->setName(jW.name);
				it->hp = jW.statbaseArr[0];
				it->sp = jW.statbaseArr[1];
				it->fp = jW.statbaseArr[2];
				it->ap = jW.statbaseArr[3];
				it->dp = jW.statbaseArr[4];
				it->ATK = jW.statbaseArr[5];
				it->DEF = jW.statbaseArr[6];
				it->SPEED = jW.statbaseArr[7];
				it->AGI = jW.statbaseArr[8];
				it->DEX = jW.statbaseArr[9];
				it->INT = jW.statbaseArr[10];
				it->SPR = jW.statbaseArr[11];
				it->STR = jW.statbaseArr[12];
				it->END = jW.statbaseArr[13];
				it->CON = jW.statbaseArr[14];

				// ded
				it->hpd = jW.statbaseDArr[0];
				it->spd = jW.statbaseDArr[1];
				it->fpd = jW.statbaseDArr[2];
				it->ATKd = jW.statbaseDArr[3];
				it->DEFd = jW.statbaseDArr[4];
				it->SPEEDd = jW.statbaseDArr[5];
				it->AGId = jW.statbaseDArr[6];
				it->DEXd = jW.statbaseDArr[7];
				it->INTd = jW.statbaseDArr[8];
				it->SPRd = jW.statbaseDArr[9];
				it->STRd = jW.statbaseDArr[10];
				it->ENDd = jW.statbaseDArr[11];
				it->CONd = jW.statbaseDArr[12];

				// for weapons 
				it->weapons[0].name = jW.wepNames[0];
				it->weapons[1].name = jW.wepNames[1];
				it->weapons[2].name = jW.wepNames[2];

				it->weapons[0].maxhp = jW.wepstatAdd[0][0];
				it->weapons[1].maxhp = jW.wepstatAdd[0][1];
				it->weapons[2].maxhp = jW.wepstatAdd[0][2];

				it->weapons[0].maxsp = jW.wepstatAdd[1][0];
				it->weapons[1].maxsp = jW.wepstatAdd[1][1];
				it->weapons[2].maxsp = jW.wepstatAdd[1][2];

				it->weapons[0].fp = jW.wepstatAdd[2][0];
				it->weapons[1].fp = jW.wepstatAdd[2][1];
				it->weapons[2].fp = jW.wepstatAdd[2][2];

				it->weapons[0].ap = jW.wepstatAdd[3][0];
				it->weapons[1].ap = jW.wepstatAdd[3][1];
				it->weapons[2].ap = jW.wepstatAdd[3][2];

				it->weapons[0].atk = jW.wepstatAdd[4][0];
				it->weapons[1].atk = jW.wepstatAdd[4][1];
				it->weapons[2].atk = jW.wepstatAdd[4][2];

				it->weapons[0].def = jW.wepstatAdd[5][0];
				it->weapons[1].def = jW.wepstatAdd[5][1];
				it->weapons[2].def = jW.wepstatAdd[5][2];

				it->weapons[0].speed = jW.wepstatAdd[6][0];
				it->weapons[1].speed = jW.wepstatAdd[6][1];
				it->weapons[2].speed = jW.wepstatAdd[6][2];

				it->weapons[0].agi = jW.wepstatAdd[7][0];
				it->weapons[1].agi = jW.wepstatAdd[7][1];
				it->weapons[2].agi = jW.wepstatAdd[7][2];

				it->weapons[0].dex = jW.wepstatAdd[8][0];
				it->weapons[1].dex = jW.wepstatAdd[8][1];
				it->weapons[2].dex = jW.wepstatAdd[8][2];

				it->weapons[0].intel = jW.wepstatAdd[9][0];
				it->weapons[1].intel = jW.wepstatAdd[9][1];
				it->weapons[2].intel = jW.wepstatAdd[9][2];

				it->weapons[0].spr = jW.wepstatAdd[10][0];
				it->weapons[1].spr = jW.wepstatAdd[10][1];
				it->weapons[2].spr = jW.wepstatAdd[10][2];

				it->weapons[0].str = jW.wepstatAdd[11][0];
				it->weapons[1].str = jW.wepstatAdd[11][1];
				it->weapons[2].str = jW.wepstatAdd[11][2];

				it->weapons[0].end = jW.wepstatAdd[12][0];
				it->weapons[1].end = jW.wepstatAdd[12][1];
				it->weapons[2].end = jW.wepstatAdd[12][2];

				it->weapons[0].con = jW.wepstatAdd[13][0];
				it->weapons[1].con = jW.wepstatAdd[13][1];
				it->weapons[2].con = jW.wepstatAdd[13][2];

				it->weapons[0].value = jW.wepstatAdd[14][0];
				it->weapons[1].value = jW.wepstatAdd[14][1];
				it->weapons[2].value = jW.wepstatAdd[14][2];

				it->armors[0].name = jW.armorNames[0];
				it->armors[1].name = jW.armorNames[1];
				it->armors[2].name = jW.armorNames[2];

				it->armors[0].maxhp = jW.armstatAdd[0][0];
				it->armors[1].maxhp = jW.armstatAdd[0][1];
				it->armors[2].maxhp = jW.armstatAdd[0][2];

				it->armors[0].maxsp = jW.armstatAdd[1][0];
				it->armors[1].maxsp = jW.armstatAdd[1][1];
				it->armors[2].maxsp = jW.armstatAdd[1][2];

				it->armors[0].fp = jW.armstatAdd[2][0];
				it->armors[1].fp = jW.armstatAdd[2][1];
				it->armors[2].fp = jW.armstatAdd[2][2];

				it->armors[0].ap = jW.armstatAdd[3][0];
				it->armors[1].ap = jW.armstatAdd[3][1];
				it->armors[2].ap = jW.armstatAdd[3][2];

				it->armors[0].atk = jW.armstatAdd[4][0];
				it->armors[1].atk = jW.armstatAdd[4][1];
				it->armors[2].atk = jW.armstatAdd[4][2];

				it->armors[0].def = jW.armstatAdd[5][0];
				it->armors[1].def = jW.armstatAdd[5][1];
				it->armors[2].def = jW.armstatAdd[5][2];

				it->armors[0].speed = jW.armstatAdd[6][0];
				it->armors[1].speed = jW.armstatAdd[6][1];
				it->armors[2].speed = jW.armstatAdd[6][2];

				it->armors[0].agi = jW.armstatAdd[7][0];
				it->armors[1].agi = jW.armstatAdd[7][1];
				it->armors[2].agi = jW.armstatAdd[7][2];

				it->armors[0].dex = jW.armstatAdd[8][0];
				it->armors[1].dex = jW.armstatAdd[8][1];
				it->armors[2].dex = jW.armstatAdd[8][2];

				it->armors[0].intel = jW.armstatAdd[9][0];
				it->armors[1].intel = jW.armstatAdd[9][1];
				it->armors[2].intel = jW.armstatAdd[9][2];

				it->armors[0].spr = jW.armstatAdd[10][0];
				it->armors[1].spr = jW.armstatAdd[10][1];
				it->armors[2].spr = jW.armstatAdd[10][2];

				it->armors[0].str = jW.armstatAdd[11][0];
				it->armors[1].str = jW.armstatAdd[11][1];
				it->armors[2].str = jW.armstatAdd[11][2];

				it->armors[0].end = jW.armstatAdd[12][0];
				it->armors[1].end = jW.armstatAdd[12][1];
				it->armors[2].end = jW.armstatAdd[12][2];

				it->armors[0].con = jW.armstatAdd[13][0];
				it->armors[1].con = jW.armstatAdd[13][1];
				it->armors[2].con = jW.armstatAdd[13][2];

				it->armors[0].value = jW.armstatAdd[14][0];
				it->armors[1].value = jW.armstatAdd[14][1];
				it->armors[2].value = jW.armstatAdd[14][2];
			}
		}
		break;
	}
}

void BattleMode::reset() // what?
{
	
}

void BattleMode::hpCheck()
{
	Task guy;
	int hpSum = 0;
	for (std::list<Battler>::iterator it = AllBattlersList.begin();
		it != AllBattlersList.end(); ++it)
	{
		if (it->team = 0)
		{
			guy.enemyR.push_front(it.operator*());
		}
		
		if (it->statbaseDArr[0] <= 0)
		{
			AllBattlersList.erase(it);
		}
		if (it->team)
		{
			hpSum += it->statbaseDArr[5];
			if (hpSum <= 0)
			{
				victoryDet(guy);
				// call victory or loss
				return;
			}
		}
	}

	for (std::list<PartyActor>::iterator it = Wp.begin(); 
		it != Wp.end(); ++it)
	{
		if (it->getHpd() <= 0)
		{
			Wp.erase(it);
		}
	}

	for (std::list<Enemy>::iterator it = troop.begin();
		it != troop.end(); ++it)
	{
		if (it->getHpd() <= 0)
		{
			troop.erase(it);
		}
	}
}

void BattleMode::clashMode()
{

}

void BattleMode::afterBattleUpdate()
{
	
}

Inventory::armor BattleMode::armorRw(int r)
{
	return Inventory::armor();
}

Inventory::weapon BattleMode::weaponRw(int r)
{
	return Inventory::weapon();
}

Inventory::item BattleMode::itemRw(int r)
{
	return Inventory::item();
}

int BattleMode::expRw()
{
	return 0;
}

double BattleMode::randCalc()
{
	const int MAX_ = 3;
	const int MIN_ = 1;

	int randRate = 0;
	float o = 0.0;
	// rand calc to determine 1 - 3 weak 50%, moderate 67%, strong 72%
	//  1 - 3 switch for returns
	randRate = (rand() % (MAX_ - MIN_ + 1)) + MIN_;
	switch (randRate)
	{
	case 1:
		return o = .50;
	case 2:
		return o = .67;
	case 3:
		return o = .72;
	default:
		return o = .1;
	}
}

BattleMode::Task BattleMode::newTask(char choice) 
{
	switch (choice)
	{
	case 'a':
		// here it begins
		Attack(MbL.back(),0);
		break;
	case 'd':
		Defend(MbL.back(),0); // here it begins
		break;
	case 's':
		Skillo(MbL.back(),0); // here it begins
		break;
	case 't':
		Actiono(MbL.back(),0); // here it begins
		break;
	case 'h':
		Hacko(MbL.back(),0); // here it begins
		break;
	case 'p':
		Psio(MbL.back(),0);
		break;
	case 'q':
		STo(MbL.back(),0); // here it begins
		break;
	case 'u':
		Summono(MbL.back(),0); // here it begins
		break;
	case 'i':
		ItemMenu(MbL.back(),0); // here it begins
		break;
	case 'e':
		Escape(MbL.back(),0); // here it begins
		break;
	default:
		cout << "OK ITS YOUR TURN. Calm down I know you're excited.."
			<< "Geez.. \n Now please choose a valid choice." << endl;
		system("PAUSE");
		turnCallPVP();
		break;
	}
	return Task();
}

void BattleMode::aiTurn(Battler ays)
{
	int aiLevel = 0;
	switch (ays.team)
	{
	case 0:
		// ai time
		aiLevel += ays.armstatAdd[8][0];
		aiLevel += ays.armstatAdd[8][1];
		aiLevel += ays.armstatAdd[8][2];

		aiLevel += ays.wepstatAdd[8][0];
		aiLevel += ays.wepstatAdd[8][1];
		aiLevel += ays.wepstatAdd[8][2];

		aiLevel += ays.statbaseDArr[8];
		aiLevel += ays.statbaseDArr[12];
		aiLevel += ays.statbaseDArr[9];
		aiLevel /= 3;

		break;
	default:
		// this is if this thing glitches
		cout << "Turn skipped?" << endl;
		phaseTrigger(T1P);
		break;
	}
}

char BattleMode::determineAiAction(char choice, int ailv)
{
	double idet = ailv * randCalc();
	char serd[10] = { 'a', 'd', 's', 't', 'h' ,'p', 'q', 'u', 'i', 'e'};
	int mai = 0;
	const int max = 9;
	
	while (idet > 0)
	{
		/// a d s t h p q u i e
		serd[mai];

		// breakpin
		if (idet >= 0)
		{
			break;
		}
		mai = (rand() % (max - 0 + 1)) + 1;
	}

	return serd[mai];
}

BattleMode::Task BattleMode::newTaskAI(int aiLevel)
{
	Task s;
	bool autoCall = true;
	bool* eh = new bool;
	*eh = autoCall;
	/// <summary>
	/// incomming enstrangly Long af if statements for AI determinants
	/// Nah I'll just use some probablilies and switches.
	/// 
	/// ai lvls 1 - 4.
	/// 
	/// a d s t h p q u i e  are the choice offsetters for 
	/// specific variant actions to be given
	/// </summary>
	/// <param name="choice">
	/// </param>
	/// <returns>
	/// </returns>
	char choice;
	switch (autoCall)
	{
	case true:
		//lv1
		choice = 'a'; // initializer variant of a d s t h p q u i e 
		choice = determineAiAction(choice, aiLevel);
		if (MbL.back().statbaseDArr[8] > 10)
		{
			switch (choice)
			{
			case 'a':
				// here it begins
				Attack(MbL.back(), aiLevel);
				break;
			case 'd':
				Defend(MbL.back(), aiLevel); // here it begins
				break;
			case 's':
				Skillo(MbL.back(), aiLevel); // here it begins
				break;
			case 't':
				Actiono(MbL.back(), aiLevel); // here it begins
				break;
			case 'h':
				Hacko(MbL.back(), aiLevel); // here it begins
				break;
			case 'p':
				Psio(MbL.back(), aiLevel);
				break;
			case 'q':
				STo(MbL.back(), aiLevel); // here it begins
				break;
			case 'u':
				Summono(MbL.back(), aiLevel); // here it begins
				break;
			case 'i':
				ItemMenu(MbL.back(), aiLevel); // here it begins
				break;
			case 'e':
				Escape(MbL.back(), aiLevel); // here it begins
				break;
			default:
				turnCallPVP();
				break;
			}
		}
		//lv2
		choice = 'd'; // initializer variant
		choice = determineAiAction(choice, aiLevel);
		if (MbL.back().statbaseDArr[8] > 60)
		{
			switch (choice)
			{
			case 'a':
				// here it begins
				Attack(MbL.back(), aiLevel);
				break;
			case 'd':
				Defend(MbL.back(), aiLevel); // here it begins
				break;
			case 's':
				Skillo(MbL.back(), aiLevel); // here it begins
				break;
			case 't':
				Actiono(MbL.back(), aiLevel); // here it begins
				break;
			case 'h':
				Hacko(MbL.back(), aiLevel); // here it begins
				break;
			case 'p':
				Psio(MbL.back(), aiLevel);
				break;
			case 'q':
				STo(MbL.back(), aiLevel); // here it begins
				break;
			case 'u':
				Summono(MbL.back(), aiLevel); // here it begins
				break;
			case 'i':
				ItemMenu(MbL.back(), aiLevel); // here it begins
				break;
			case 'e':
				Escape(MbL.back(), aiLevel); // here it begins
				break;
			default:
				turnCallPVP();
				break;
			}
		}
		//lv3
		choice = 'p'; // initializer variant
		choice = determineAiAction(choice, aiLevel);
		if (MbL.back().statbaseDArr[8] > 120)
		{
			switch (choice)
			{
			case 'a':
				// here it begins
				Attack(MbL.back(), aiLevel);
				break;
			case 'd':
				Defend(MbL.back(), aiLevel); // here it begins
				break;
			case 's':
				Skillo(MbL.back(), aiLevel); // here it begins
				break;
			case 't':
				Actiono(MbL.back(), aiLevel); // here it begins
				break;
			case 'h':
				Hacko(MbL.back(), aiLevel); // here it begins
				break;
			case 'p':
				Psio(MbL.back(), aiLevel);
				break;
			case 'q':
				STo(MbL.back(), aiLevel); // here it begins
				break;
			case 'u':
				Summono(MbL.back(), aiLevel); // here it begins
				break;
			case 'i':
				ItemMenu(MbL.back(), aiLevel); // here it begins
				break;
			case 'e':
				Escape(MbL.back(), aiLevel); // here it begins
				break;
			default:
				turnCallPVP();
				break;
			}
		}
		//lv4
		choice = '/'; // initializer variant
		choice = determineAiAction(choice, aiLevel);
		if (MbL.back().statbaseDArr[8] > 320)
		{
			switch (choice)
			{
			case 'a':
				// here it begins
				Attack(MbL.back(), aiLevel);
				break;
			case 'd':
				Defend(MbL.back(), aiLevel); // here it begins
				break;
			case 's':
				Skillo(MbL.back(), aiLevel); // here it begins
				break;
			case 't':
				Actiono(MbL.back(), aiLevel); // here it begins
				break;
			case 'h':
				Hacko(MbL.back(), aiLevel); // here it begins
				break;
			case 'p':
				Psio(MbL.back(), aiLevel);
				break;
			case 'q':
				STo(MbL.back(), aiLevel); // here it begins
				break;
			case 'u':
				Summono(MbL.back(), aiLevel); // here it begins
				break;
			case 'i':
				ItemMenu(MbL.back(), aiLevel); // here it begins
				break;
			case 'e':
				Escape(MbL.back(), aiLevel); // here it begins
				break;
			default:
				turnCallPVP();
				break;
			}
		}	
		break;
	default:
		break;
	}
	
	delete(eh);
	
	return s;
}

Inventory::item BattleMode::Items(Task d)
{
	if (d.db_choice > 25)
	{
		return invento.myItmListCall(d.db_choice);
	}
	else
	return invento.myItemCall(d.db_choice);
}

void BattleMode::Escape(Battler g, int aiC)
{
	int eva = 0;
	const int MAX_ = 3;
	const int MIN_ = 1;
	
	int randRate = 0;
	float o = 0.0;
	// rand calc to determine 1 - 3 weak 50%, moderate 67%, strong 72%
	//  1 - 3 switch for returns
	randRate = (rand() % (MAX_ - MIN_ + 1)) + MIN_;
	switch (randRate)
	{
	case 1:
		o = .50;
		break;
	case 2:
		o = .67;
		break;
	case 3:
		o = .72;
		break;
	default:
		o = .1;
		break;
	}
	eva = (g.statbaseDArr[6] + g.statbaseDArr[7]) + (g.statbaseDArr[6] + g.statbaseDArr[7]) * o;

	Task escape;

	for (std::list<Battler>::iterator jW = AllBattlersList.begin(); jW != AllBattlersList.end(); ++jW)
	{
		if (jW->team != g.team)
		{
			escape.enemyR.push_front(jW.operator*());
		}
	}
	escape.decision = TaskType::Escape;
	escape.targetRange = 0;
	escape.Tc = 'e';
	double escR = gatherAllEnemySpds(g, escape) * 0.67;
	if (eva >= escR)
	{
		TaskBase.push_front(escape);
	}
}

void BattleMode::Attack(Battler g, int aiC) // int? wip
{
	Task Atk;
	int n = 0;
	int atkAdd;
	const int MAX_ = 3;
	const int MIN_ = 1;

	double atkR = 0.0;

	int choice = 0;

	int randRate = 0;
	float o = 0.0;
	// rand calc to determine 1 - 3 weak 50%, moderate 67%, strong 72%
	//  1 - 3 switch for returns
	randRate = (rand() % (MAX_ - MIN_ + 1)) + MIN_;
	switch (randRate)
	{
	case 1:
		o = .50;
		break;
	case 2:
		o = .67;
		break;
	case 3:
		o = .72;
		break;
	default:
		o = .1;
		break;
	}
	// addup
	atkAdd = (
		g.statbaseDArr[3] + g.statbaseDArr[10] + 
		g.wepstatAdd[4][0] + g.wepstatAdd[11][0] + 
		g.wepstatAdd[4][1] + g.wepstatAdd[11][1] +
		g.wepstatAdd[4][2] + g.wepstatAdd[11][2] );

	//Task Time
	Task attack;

	int cm = {};
	list<pair<int, Battler>> eArr;
	pair<int, Battler> d;

	// choosing an attack Target
	for (std::list<Battler>::iterator it = AllBattlersList.begin(); 
		it.operator!=(AllBattlersList.end()); it++)
	{
		if (it.operator*().team == 0) // checking enemy teamate
		{
			cout << "# " << n << it.operator*().name << endl;
			pair <int, Battler> v (n, it.operator*());
			eArr.push_back(v);
		}
		++n;
	}
	cin >> cm;

	// selection / mutations
	for (std::list<pair<int, Battler>>::iterator it = eArr.begin();
		it.operator!=(eArr.end()); it++)
	{
		if (cm == it.operator*().first)
		{
			pair <int, Battler> v(it.operator*());
			d.first = v.first;
			d.second = v.second;
			break;
		}
	}

	// target stat addup
	atkR = d.second.statbaseDArr[11] 
		+ d.second.statbaseDArr[10]
		+ d.second.statbaseDArr[4];

	TaskType e = TaskType::Attack;
	attack.decision = e;
	attack.targetRange = 0; // generically this will be 0
	attack.Tc = 'a';
	attack.singleTarget = d.second;
	
	// determine success
	if (atkAdd >= atkR)
	{
		// pushing in the Task onto the list of actions
		TaskBase.push_front(attack);
	}
}

void BattleMode::Defend(Battler g, int aiC)
{
	Task defend;

	int n = 0;
	int defAdd = 0;
	const int MAX_ = 3;
	const int MIN_ = 1;

	double defR = 0.0;

	int choice = 0;

	int randRate = 0;
	float o = 0.0;
	// rand calc to determine 1 - 3 weak 50%, moderate 67%, strong 72%
	//  1 - 3 switch for returns
	randRate = (rand() % (MAX_ - MIN_ + 1)) + MIN_;
	switch (randRate)
	{
	case 1:
		o = .50;
		break;
	case 2:
		o = .67;
		break;
	case 3:
		o = .72;
		break;
	default:
		o = .1;
		break;
	}

	//addup defence
	defR = (
		g.statbaseDArr[4] + g.statbaseDArr[11] + 
		g.armstatAdd[5][0] + g.armstatAdd[12][0] +
		g.armstatAdd[5][1] + g.armstatAdd[12][1] +
		g.armstatAdd[5][2] + g.armstatAdd[12][2] );
	
	// self target
	TaskType e = TaskType::Defend;
	defend.decision = e;
	defend.targetRange = 0; // generically this will be 0
	defend.Tc = 'd';
	defend.singleTarget = g;

	TaskBase.push_front(defend);

}

void BattleMode::ItemMenu(Battler g, int aiC)
{
	// Make item Menu
	cout << " Please select your choice:" << endl;
	cout << " armors(0) weapons(1) items(2) " << endl;
	int a = 0;
	int k ={};
	int o = {};
	int sel{};
	int arrD{};
	list<Inventory::armor> arQ;
	cin >> k;
	// view/alter items?
	switch (k)
	{
	case 0:
		cout << "equip armors?" << endl;
		playerStuff.displaylistArmor();
		
		cout << "yes(0), no(1), go back(2)" << endl;
		cin >> o;
		
		if (o == 0)
		{
			cout << "select your armor " << endl;
			cout << "slots using a number(#)" << endl;
			
			for (int i = 0; i < 3; i++)
			{
				cout << i << " " << g.armorNames[i] << endl;
			}
			cin >> sel;
			// 0 - 3 armor selections
			system("CLS");
			cout << "Now select the armor number to equip it!" << endl;
			// displaylist Armors 
			int i{};
			for (i = 0; i < 3; i++)
			{
				cout << i << " " << g.armorNames[i] << endl;
			}
			
			for (size_t ie = 0; ie < 25; ie++)
			{
				if (!(playerStuff.my_armors[ie].name.empty())) // leave the value in the middle blank. it'll only return the already existant set value.
				{
					cout << i << " " << playerStuff.my_armors[ie].name << endl;
					arQ.push_back(playerStuff.my_armors[ie]);
				}
			}
			for(std::list<Inventory::armor>::iterator
				bat = playerStuff.auxArmors.begin();
			bat != playerStuff.auxArmors.end(); ++bat)
			{
				if (!(bat.operator*().name.empty()))
				{
					cout << i << " " << bat.operator*().name << endl;
					arQ.push_back(bat.operator*());
				}
			}
			i = NULL;
			// equip it
			int eq{};
			cin >> eq;
			// we do things the hard way...
			// create the item
			Inventory::armor amo;
			// store it in invent
			
			// overwrite the selected slot
			g.armorNames[sel] = "";
			// statup
			cout << " OK! " << endl;
		}
		if (o == 1)
		{
			return;
		}
		if (o == 2)
		{
			ItemMenu(g, aiC);
		}
	case 1:
		cout << "equip weapon?" << endl;
		playerStuff.displaylistWeapon();
		cout << "yes(0), no(1), go back(2)" << endl;
		switch (o)
		{
		case 0:
			break;

		case 1:
			break;

		case 2:
			break;
		default:
			break;
		}
		break;

	case 2:
		cout << "use item?" << endl;
		playerStuff.displaylistItem();
		cout << "yes(0), no(1), go back(2)" << endl;
		switch (o)
		{
		case 0:
			break;

		case 1:
			break;

		case 2:
			break;
		default:
			break;
		}
		break;

	default:
		ItemMenu(g, aiC);
		break;
	}
	
	// consume?
}

void BattleMode::Skillo(Battler, int aiC)
{
}

void BattleMode::Summono(Battler, int aiC)
{
}

void BattleMode::STo(Battler, int aiC)
{
}

void BattleMode::Hacko(Battler, int aiC)
{
}

void BattleMode::Actiono(Battler, int aiC)
{
}

void BattleMode::Psio(Battler, int aiC)
{
}

/*self target*/
void BattleMode::EscapeC(Battler, Task)
{
}

void BattleMode::AttackC(Battler, Task)
{
}

void BattleMode::DefendC(Battler, Task)
{
}

void BattleMode::HackC(Battler g, Task d)
{
}

void BattleMode::SummonC(Task d)
{
}

void BattleMode::STC(Battler, Task)
{
}

void BattleMode::SkillC(Battler, Task)
{
}

void BattleMode::ActionC(Battler, Task)
{
}

void BattleMode::MagicC(Battler, Task)
{
}

void BattleMode::PsiC(Battler, Task)
{
}

void BattleMode::ItemC(Battler, Task)
{
}

//Options
void BattleMode::ChangeArmr(Battler, Task)
{
}

void BattleMode::ChangeWeps(Battler, Task)
{
}

void BattleMode::ChangeItms(Battler, Task)
{
}

void BattleMode::ChangeItems(Battler g, int aiC)
{
	
}

void BattleMode::ChangeArmors(Battler g, int aiC)
{
}

void BattleMode::ChangeWeapons(Battler g, int aiC)
{
}

int BattleMode::FindTaskArrMax(Task mo[])
{
	int n = 0;
	int ma = 0;
	int i = 0;
	while (i >= 0 && n + mo[i].isTask > ma)
	{
		++ma;
		++n;
		++i;
	}
	return ma;
}

const char BattleMode::intToChar(int arrIn[])
{
	int m = 0;
	char e = 'g';
	
	for (int i = 0; i < FindArrMax(arrIn); i++)
	{
		return e = static_cast<char>(arrIn[i]);
	}
}

BattleMode::~BattleMode()
{
	// call rewards 
	// 
	// // TODO :
	// using the battler parameter
	// you can call to determine the victor's
	// prizes
	// who is already the battler in question.
	// So just init the scripts and finish
	// by updating everything and save 
	// the victor's data to a file.
	
	// check if anyone on winning team died.
	// if there is a victor team end the 
	// fight with a victory and an exp roll
	// update transfer all data including rewards
	// any misc data update
	// save file update.
	// 	( you can use a function that allows data to recall 
	//	from a parameter set entirely in World.cpp and 
	//  an updater function for that World which would work
	//  a thousand times more)
	// delete all battle mode and list data.
	// 
}
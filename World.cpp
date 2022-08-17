#include <iostream>
#include <tuple>
#include "World.h"
#include "BattleMode.h"

using namespace std;

PartyActor playerParty[6];
Inventory playerInventory;
BattleMode b;
Enemy troopers[8];

// make a list of allysummon names and 
// call their actions from teh menu
// also u can use their unique actions to
// trigger different events or interact with
// current ones.

World::World()
{
}

void World::Campagin()
{
	// player 1
	PartyActor Actor1;
	string nameIn;
	cout << "What's your name?" << endl;
	cin >> nameIn;

	// initialize the party
	playerParty[0].setName(nameIn); // 1

	cout << "OK!" << endl;

	// good goys
	playerParty[1].setName("Youul"); // 6
	playerParty[2].setName("Irene"); // 2 
	playerParty[3].setName("Ri"); // 3
	playerParty[4].setName("Cammila"); // 5
	playerParty[5].setName("Alicia"); // 4

#pragma region Party SPD statbase setter
	playerParty[0].setSPD(15);
	playerParty[1].setSPD(5);
	playerParty[2].setSPD(13);
	playerParty[3].setSPD(10);
	playerParty[4].setSPD(7);
	playerParty[5].setSPD(9);

	playerParty[0].setSPDd(14);//
	playerParty[1].setSPDd(6);//
	playerParty[2].setSPDd(12);//
	playerParty[3].setSPDd(11);///
	playerParty[4].setSPDd(4);//
	playerParty[5].setSPDd(9);//
#pragma endregion

	// bad gois
	troopers[0].setName("DevilBaller"); // 1
	troopers[1].setName("Hallmanr"); // 5
	troopers[2].setName("Ulliquilor"); // 2
	troopers[3].setName("Pman"); // 3
	troopers[4].setName("TypedVar"); // 6
	troopers[5].setName("EqualizerM"); // 4
	troopers[6].setName("CrazedMisfit"); // 8 
	troopers[7].setName("Brawler"); // 7


#pragma region Enemy SPEED statbase setter
	troopers[0].setSPD(15);
	troopers[1].setSPD(7);
	troopers[2].setSPD(13);
	troopers[3].setSPD(10);
	troopers[4].setSPD(7);
	troopers[5].setSPD(9);
	troopers[6].setSPD(2);
	troopers[7].setSPD(3);

	troopers[0].setSPDd(14);//
	troopers[1].setSPDd(6);//
	troopers[2].setSPDd(12);//
	troopers[3].setSPDd(10);///
	troopers[4].setSPDd(4);//
	troopers[5].setSPDd(9);//
	troopers[6].setSPDd(1);///
	troopers[7].setSPDd(2);///
#pragma endregion
	
	//
	//gai = get<0>(h);
	//cout << gai << endl; this works

	b.test_Transfer_CallII(playerParty, troopers, 6, 8); //loading entire objects

	// battle test

	system("PAUSE");

	//system("CLS");

	// main menu
	// <<<<<<<<<

}

void World::addPartyMember(int m, PartyActor in)
{
	playerParty[m].setName(in.getActorName());
	playerParty[m].setBio(in.getBio());

	playerParty[m].setAGI(in.getAGI());
	playerParty[m].setAGId(in.getAGId());
	playerParty[m].setSTR(in.getSTR());
	playerParty[m].setSTRd(in.getSTRd());
	playerParty[m].setSPR(in.getSPR());
	playerParty[m].setSPRd(in.getSPRd());
	playerParty[m].setAp(in.getAp());

	playerParty[m].setATKd(in.getATKd());
	playerParty[m].setCON(in.getCON());
	playerParty[m].setCONd(in.getCONd());
	playerParty[m].setBGSpd(in.getBGspd());
	playerParty[m].setDEF(in.getDEFd());
	playerParty[m].setDEFd(in.getDEFd());
	playerParty[m].setDEX(in.getDEX());
	playerParty[m].setDEXd(in.getDEXd());
	playerParty[m].setEND(in.getEND());
	playerParty[m].setENDd(in.getENDd());
	playerParty[m].setSPD(in.getSPD());
	playerParty[m].setSPDd(in.getSPDd());
	playerParty[m].setFp(in.getFp());
	playerParty[m].setFpd(in.getFpd());
	playerParty[m].setDp(in.getDp());
	playerParty[m].setINT(in.getINT());
	playerParty[m].setINTd(in.getINTd());
	playerParty[m].setAtk(in.getAtk());
	playerParty[m].setSp(in.getSp());
	playerParty[m].setHp(in.getHp());
	playerParty[m].setHpd(in.getHpd());
	playerParty[m].setSpd(in.getSpd()); // Sp deductable
	playerParty[m].setState("NORMAL");
	playerParty[m].setTitle(in.getTitle());
}

// equipennn time!

void World::EquipMenuCall(PartyActor px[])
{
	system("CLS");
	playerInventory.initAuxArmorList(); 
	playerInventory.initAuxItemList();
	playerInventory.initAuxWeaponList();
	Inventory::armor arS;
	Inventory::item irS;
	Inventory::weapon wrS;
	int choiceP{};
	char slel{};
	int armorc{};
	int itemc{};
	int weaponc{};
	int count;
	int armorSlot{};
	cout << "select which set of items you wish to see. \n Weapons(w), itmes(i), armors(a), Quit(q) " << endl;
	cin >> slel;

	switch (slel)
	{
	case 'a':
		playerInventory.displaylistArmor();
		cout << "OK?" << endl;
		system("PAUSE");
		EquipMenuCall(px);

		cout << "select the armor you wish to equip (choose number#(0 ... x)) or quit" << endl;

		switch (armorc)
		{
		case '0':
		default:
			count = 0;
			list<pair<Inventory::armor, int>> bpp;
			for (int i = 0; i < 25; i++)
			{
				pair <Inventory::armor, int> ds;
				ds.first = playerInventory.my_armors[i];
				ds.second = count;
				bpp.push_front(ds);
				cout << count << " " << playerInventory.my_armors[i].name << endl;
				++count;
			}
			for (std::list<pair<Inventory::armor, int>>::iterator geno
				= playerInventory.getDemoa().begin(); geno != playerInventory.getDemoa().end(); ++geno)
			{
				bpp.push_front(playerInventory.getDemoa().front());
				cout << count << " " << playerInventory.getDemoa().front().first.name << endl;
				++count;
				playerInventory.getDemoa().pop_front();
			}
			// list complete for selection
			cin >> armorc;
			// choice selected
			system("CLS");
			for (int i = 0; i < 5; i++)
			{
				cout << i + 1 << " " << px[i].name << endl;
			}
			cout << "choose a player to equip it to" << endl;
			cin >> choiceP;
			if (armorc <= count)
			{
				for (std::list<pair<Inventory::armor, int>>::iterator id =
					bpp.begin(); id != bpp.end(); ++id)
				{
					if (armorc == id.operator*().second)
					{
						arS = id.operator*().first;

						// choose an armor slot...
						cout << "Choose an armor slot..# or auto eq?(-1)" << endl;
						int ept{};
						cin >> ept;
						switch (ept)
						{
						case -1:
							// auto equip?
							ept = px[choiceP].FindEmptyASlot();
							ArmorTransferToPlayer(ept, armorc, choiceP, px[choiceP], arS);
							break;

						default:
							ArmorTransferToPlayer(ept, armorc, choiceP, px[choiceP], arS);
							break;
						}
					}
				}
			}
			else
			{
				cout << "stop messing around.." << endl;
				system("PAUSE");
				slel = 'a';
				EquipMenuCall(px);
			}
			break;
		}

	case 'i':
		playerInventory.displaylistItem();
		cout << "OK?" << endl;
		system("PAUSE");
		EquipMenuCall(px);

		cout << "select the item you wish to equip (choose number#(1 ... x))" << endl;
		
		switch (itemc)
		{
		case '0':
			break;
		default:
			count = 0;
			list<pair<Inventory::item, int>> bpp;
			for (int i = 0; i < 25; i++)
			{
				pair <Inventory::item, int> ds;
				ds.first = playerInventory.my_items[i];
				ds.second = count;
				bpp.push_front(ds);
				cout << count << " " << playerInventory.my_items[i].name << endl;
				++count;
			}
			for (std::list<pair<Inventory::item, int>>::iterator geno
				= playerInventory.getDemoi().begin(); geno != playerInventory.getDemoi().end(); ++geno)
			{
				bpp.push_front(playerInventory.getDemoi().front());
				cout << count << " " << playerInventory.getDemoi().front().first.name << endl;
				++count;
				playerInventory.getDemoi().pop_front();
			}
			// list complete for selection
			cin >> itemc;
			// choice selected
			system("CLS");
			for (int i = 0; i < 5; i++)
			{
				cout << i + 1 << " " << px[i].name << endl;
			}
			cout << "choose a player to equip it to" << endl;

			cin >> choiceP;

			if (itemc <= count)
			{
				for (std::list<pair<Inventory::item, int>>::iterator id =
					bpp.begin(); id != bpp.end(); ++id)
				{
					if (itemc == id.operator*().second)
					{
						irS = id.operator*().first;

						// choose an armor slot...
						cout << "Choose an armor slot..# or auto eq?(-1)" << endl;
						int ept{};
						cin >> ept;
						switch (ept)
						{
						case -1:
							// auto equip?
							ept = px[choiceP].FindEmptyASlot();
							ItemTransferToPlayer(ept, itemc, choiceP, px[choiceP], irS);
							break;

						default:
							ItemTransferToPlayer(ept, armorc, choiceP, px[choiceP], irS);
							break;
						}
					}
				}
			}
			else
			{
				cout << "stop messing around.." << endl;
				system("PAUSE");
				slel = 'a';
				EquipMenuCall(px);
			}
			break;
		}

	case 'w':
		playerInventory.displaylistWeapon();
		cout << "OK?" << endl;
		system("PAUSE");
		EquipMenuCall(px);

		cout << "select the weapon you wish to equip (choose number#(1 ... x))" << endl;
		switch (weaponc)
		{
		case 0:
			break;
		default:
			list<Inventory::weapon> bpp;
			for (int i = 0; i < 25; i++)
			{
				bpp.push_front(playerInventory.my_weapons[i]);
			}
			for (std::list<pair<Inventory::weapon, int>>::iterator geno
				= playerInventory.getDemow().begin(); geno != playerInventory.getDemow().end(); ++geno)
			{
				bpp.push_front(playerInventory.getDemow().front().first);
			}
			break;
		}

	case 'q':
		break;
	default:

		playerInventory.displaylistItem();

		playerInventory.displaylistWeapon();

		playerInventory.displaylistArmor();
		cout << "All items listed here. Ok?" << endl;
		system("PAUSE");
		EquipMenuCall(px);

		break;
	}

}

void World::WeaponTransferToInvent(int call, int pn, PartyActor in)
{
	Inventory saver;
	Inventory saverSnd;
	string nameFind;
	int FindO = 0;
	int FindS = 0;
	int FindSnd = 0;

	// transfer this wep
	saver.TranserWeapons
	(
		in.whps(call),
		in.waps(call),
		in.wsps(call),
		in.wfps(call),
		in.watks(call),
		in.wdef(call),
		in.wspeed(call),
		in.wagi(call),
		in.wdex(call),
		in.wint(call),
		in.wspr(call),
		in.wstr(call),
		in.wend(call),
		in.wcon(call),
		in.wvalues(call),
		in.wname(call),
		in.wquantites(call)
	);

	nameFind = in.wname(call);

	// number item slot you saved for
	FindS = saver.findWIndex(nameFind);

	// find an empty slot in the inventory
	if (playerInventory.FindEmptyWSlot() != NULL)
	{
		FindO = playerInventory.FindEmptyWSlot();
		// transfer to that slot
		playerInventory.TranserWeapons
		(
			saver.my_weapons[FindO].maxhp,
			saver.my_weapons[FindO].ap,
			saver.my_weapons[FindO].maxsp,
			saver.my_weapons[FindO].fp,
			saver.my_weapons[FindO].atk,
			saver.my_weapons[FindO].def,
			saver.my_weapons[FindO].speed,
			saver.my_weapons[FindO].agi,
			saver.my_weapons[FindO].dex,
			saver.my_weapons[FindO].intel,
			saver.my_weapons[FindO].spr,
			saver.my_weapons[FindO].str,
			saver.my_weapons[FindO].end,
			saver.my_weapons[FindO].con,
			saver.my_weapons[FindO].value,
			saver.my_weapons[FindO].name,
			saver.my_weapons[FindO].quantity
		);
		// then that slot that was emptied for you the player is cleared
		// zero out the emptieness
		playerParty[pn].unEquipWeapon(call);
	}
	else
	{
		// do like this
		for (int i = 0; i < 25; i++)
		{
			if (saver.my_weapons[i].name == in.wname(call))
			{
				playerInventory.moveWepToAux(saver.my_weapons[i]);
			}
		}

		// finally unequip
		playerParty[pn].unEquipWeapon(call);
	}
}

void World::WeaponTransferToPlayer(int call, int selection, int pn, PartyActor in)
{
	// invent item
	Inventory saver;
	//player item
	Inventory saverSnd;
	string nameFind;
	int FindO = 0;
	int FindS = 0;
	int FindSnd = 0;

	// save the slot for the weapon in question
	saverSnd.TranserWeapons
	(
		in.whps(call),
		in.waps(call),
		in.wsps(call),
		in.wfps(call),
		in.watks(call),
		in.wdef(call),
		in.wspeed(call),
		in.wagi(call),
		in.wdex(call),
		in.wint(call),
		in.wspr(call),
		in.wstr(call),
		in.wend(call),
		in.wcon(call),
		in.wvalues(call),
		in.wname(call),
		in.wquantites(call)
	);

	// Transfer to 0th saver slot

	saver.TranserWeapons
	(
		playerInventory.my_weapons[selection].maxhp,
		playerInventory.my_weapons[selection].ap,
		playerInventory.my_weapons[selection].maxsp,
		playerInventory.my_weapons[selection].fp,
		playerInventory.my_weapons[selection].atk,
		playerInventory.my_weapons[selection].def,
		playerInventory.my_weapons[selection].speed,
		playerInventory.my_weapons[selection].agi,
		playerInventory.my_weapons[selection].dex,
		playerInventory.my_weapons[selection].intel,
		playerInventory.my_weapons[selection].spr,
		playerInventory.my_weapons[selection].str,
		playerInventory.my_weapons[selection].end,
		playerInventory.my_weapons[selection].con,
		playerInventory.my_weapons[selection].value,
		playerInventory.my_weapons[selection].name,
		playerInventory.my_weapons[selection].quantity
	);

	// find a slot in the player invent with the same name
	nameFind = in.wname(call);

	// int to string // string to int 
	if (FindO = playerInventory.findWIndex(nameFind) == -1)
	{
		// s w a p 

		playerParty[pn].weapons[call].atk = saver.my_weapons[0].atk;//
		playerParty[pn].weapons[call].ap = saver.my_weapons[0].ap;//
		playerParty[pn].weapons[call].agi = saver.my_weapons[0].agi;//
		playerParty[pn].weapons[call].end = saver.my_weapons[0].end;//
		playerParty[pn].weapons[call].fp = saver.my_weapons[0].fp;//
		playerParty[pn].weapons[call].intel = saver.my_weapons[0].intel;//
		playerParty[pn].weapons[call].def = saver.my_weapons[0].def;//
		playerParty[pn].weapons[call].dex = saver.my_weapons[0].dex;//
		playerParty[pn].weapons[call].spr = saver.my_weapons[0].spr;//
		playerParty[pn].weapons[call].str = saver.my_weapons[0].str;//
		playerParty[pn].weapons[call].speed = saver.my_weapons[0].speed;//
		playerParty[pn].weapons[call].con = saver.my_weapons[0].con;//
		playerParty[pn].weapons[call].maxhp = saver.my_weapons[0].maxhp;//
		playerParty[pn].weapons[call].maxsp = saver.my_weapons[0].maxsp;//
		playerParty[pn].weapons[call].name = saver.my_weapons[0].name;//
		playerParty[pn].weapons[call].quantity = saver.my_weapons[0].quantity;//
		playerParty[pn].weapons[call].value = saver.my_weapons[0].value;// 17

		// saved slot goes here 

		playerInventory.my_weapons[selection].maxhp = saverSnd.my_weapons[0].maxhp; //1
		playerInventory.my_weapons[selection].atk = saverSnd.my_weapons[0].atk;//2
		playerInventory.my_weapons[selection].ap = saverSnd.my_weapons[0].ap;//3
		playerInventory.my_weapons[selection].spr = saverSnd.my_weapons[0].spr;//4
		playerInventory.my_weapons[selection].end = saverSnd.my_weapons[0].end;//5
		playerInventory.my_weapons[selection].intel = saverSnd.my_weapons[0].intel;//6
		playerInventory.my_weapons[selection].dex = saverSnd.my_weapons[0].dex;//7
		playerInventory.my_weapons[selection].str = saverSnd.my_weapons[0].str;//8
		playerInventory.my_weapons[selection].speed = saverSnd.my_weapons[0].speed;//9
		playerInventory.my_weapons[selection].fp = saverSnd.my_weapons[0].fp;//10
		playerInventory.my_weapons[selection].def = saverSnd.my_weapons[0].def;//
		playerInventory.my_weapons[selection].maxsp = saverSnd.my_weapons[0].maxsp;//
		playerInventory.my_weapons[selection].value = saverSnd.my_weapons[0].value;//
		playerInventory.my_weapons[selection].name = saverSnd.my_weapons[0].name;//
		playerInventory.my_weapons[selection].quantity = saverSnd.my_weapons[0].quantity;//15
		playerInventory.my_weapons[selection].con = saverSnd.my_weapons[0].con; // 16
		playerInventory.my_weapons[selection].agi = saverSnd.my_weapons[0].agi; // 17
	}
	else
	{
		Inventory::weapon d;

		// KERCHONG!!! 
		playerParty[pn].weapons[call].atk      = saver.my_weapons[0].atk;//
		playerParty[pn].weapons[call].ap       = saver.my_weapons[0].ap;//
		playerParty[pn].weapons[call].agi      = saver.my_weapons[0].agi;//
		playerParty[pn].weapons[call].end      = saver.my_weapons[0].end;//
		playerParty[pn].weapons[call].fp       = saver.my_weapons[0].fp;//
		playerParty[pn].weapons[call].intel    = saver.my_weapons[0].intel;//
		playerParty[pn].weapons[call].def      = saver.my_weapons[0].def;//
		playerParty[pn].weapons[call].dex      = saver.my_weapons[0].dex;//
		playerParty[pn].weapons[call].spr      = saver.my_weapons[0].spr;//
		playerParty[pn].weapons[call].str      = saver.my_weapons[0].str;//
		playerParty[pn].weapons[call].speed    = saver.my_weapons[0].speed;//
		playerParty[pn].weapons[call].con      = saver.my_weapons[0].con;//
		playerParty[pn].weapons[call].maxhp    = saver.my_weapons[0].maxhp;//
		playerParty[pn].weapons[call].maxsp    = saver.my_weapons[0].maxsp;//
		playerParty[pn].weapons[call].name     = saver.my_weapons[0].name;//
		playerParty[pn].weapons[call].quantity = saver.my_weapons[0].quantity;//
		playerParty[pn].weapons[call].value    = saver.my_weapons[0].value;// 17

		// saved slot where? = > aux
		
		d.maxhp = saverSnd.my_weapons[0].maxhp;//
		d.ap = saverSnd.my_weapons[0].ap;//
		d.maxsp = saverSnd.my_weapons[0].maxsp;//
		d.fp = saverSnd.my_weapons[0].fp;//
		d.atk = saverSnd.my_weapons[0].atk;//
		d.def = saverSnd.my_weapons[0].def;//
		d.speed = saverSnd.my_weapons[0].speed;//
		d.agi = saverSnd.my_weapons[0].agi;//
		d.dex = saverSnd.my_weapons[0].dex;//
		d.intel = saverSnd.my_weapons[0].intel;//
		d.spr = saverSnd.my_weapons[0].spr;//
		d.str = saverSnd.my_weapons[0].str;//
		d.end = saverSnd.my_weapons[0].end;//
		d.con = saverSnd.my_weapons[0].con;//
		d.value = saverSnd.my_weapons[0].value;// 17
		d.name = saverSnd.my_weapons[0].name;//
		d.quantity = saverSnd.my_weapons[0].quantity;//

		playerInventory.auxWeapons.push_front(d);
	}
}

void World::WeaponTransferToPlayer(int call, int selection, int pn, PartyActor in, Inventory::weapon wrm)
{
#pragma region old
	// invent item
	Inventory saver;
	//player item
	Inventory saverSnd;
	string nameFind;
	int FindO = 0;
	int FindS = 0;
	int FindSnd = 0;

	// save the slot for the weapons in question
	saverSnd.TranserWeapons
	(
		in.whps(call),
		in.waps(call),
		in.wsps(call),
		in.wfps(call),
		in.watks(call),
		in.wdef(call),
		in.wspeed(call),
		in.wagi(call),
		in.wdex(call),
		in.wint(call),
		in.wspr(call),
		in.wstr(call),
		in.wend(call),
		in.wcon(call),
		in.wvalues(call),
		in.wname(call),
		in.wquantites(call)
	);

	// Transfer to 0th saver slot

	saver.TranserWeapons
	(
		playerInventory.my_weapons[selection].maxhp,
		playerInventory.my_weapons[selection].ap,
		playerInventory.my_weapons[selection].maxsp,
		playerInventory.my_weapons[selection].fp,
		playerInventory.my_weapons[selection].atk,
		playerInventory.my_weapons[selection].def,
		playerInventory.my_weapons[selection].speed,
		playerInventory.my_weapons[selection].agi,
		playerInventory.my_weapons[selection].dex,
		playerInventory.my_weapons[selection].intel,
		playerInventory.my_weapons[selection].spr,
		playerInventory.my_weapons[selection].str,
		playerInventory.my_weapons[selection].end,
		playerInventory.my_weapons[selection].con,
		playerInventory.my_weapons[selection].value,
		playerInventory.my_weapons[selection].name,
		playerInventory.my_weapons[selection].quantity
	);

	// find a slot in the player invent with the same name
	nameFind = in.wname(call);

	// make an armor cpy from the params
	Inventory::weapon e;
	e = wrm;

	// put it into an empty armor slot...
	playerParty[call].statWeaponTransfer(
		playerParty[call].FindEmptyWSlot(),
		e.maxhp,
		e.ap,
		e.maxsp,
		e.fp,
		e.atk,
		e.def,
		e.speed,
		e.agi,
		e.dex,
		e.intel,
		e.spr,
		e.str,
		e.end,
		e.con,
		e.value,
		e.name
	);

	// if theres an armor equipped move it to invent
	if (!(saverSnd.getName().empty()))
	{
		for (int i = 0; i < 25; i++)
		{
			if (playerInventory.my_weapons[i].name.empty())
			{
				playerInventory.my_weapons[i] = saverSnd.my_weapons[0];
				// if equip was succesful

				cout << "Weapon + " + e.name + "equipped.." << endl;
			}
			else
			{
				// or aux if invent is full
				playerInventory.auxWeapons.push_back(saverSnd.my_weapons[0]);
				// if equip was succesful

				cout << "Weapon + " + e.name + "equipped.." << endl;
			}
		}
	}
	//if not zero out
	else
	{
		playerInventory.weaponZeroOut(selection);
	}

#pragma endregion

}

void World::ItemTransferToInvent(int call, int pn, PartyActor in)
{
	Inventory saver;
	Inventory saverSnd;
	string nameFind;
	int FindO = 0;
	int FindS = 0;
	int FindSnd = 0;

	// transfer this wep
	saver.TranserItems
	(
		in.hps(call),
		in.sps(call),
		in.fps(call),
		in.atks(call),
		in.defs(call),
		in.speeds(call),
		in.agis(call),
		in.dexs(call),
		in.intels(call),
		in.sprs(call),
		in.strs(call),
		in.ends(call),
		in.cons(call),
		in.values(call),
		in.iname(call),
		in.quantites(call)
	);

	nameFind = in.iname(call);

	// number item slot you saved for https://www.cplusplus.com/reference/tuple/tuple_element/
	FindS = saver.findItemIndex(nameFind);

	// find an empty slot in the inventory
	if (playerInventory.FindEmptyISlot() != NULL)
	{
		FindO = playerInventory.FindEmptyISlot();
		// transfer to that slot
		playerInventory.TranserItems
		(
			saver.my_items[FindO].hpd,
			saver.my_items[FindO].spd,
			saver.my_items[FindO].fpd,
			saver.my_items[FindO].atkd,
			saver.my_items[FindO].defd,
			saver.my_items[FindO].speedd,
			saver.my_items[FindO].agid,
			saver.my_items[FindO].dexd,
			saver.my_items[FindO].inteld,
			saver.my_items[FindO].sprd,
			saver.my_items[FindO].strd,
			saver.my_items[FindO].endd,
			saver.my_items[FindO].cond,
			saver.my_items[FindO].value,
			saver.my_items[FindO].name,
			saver.my_items[FindO].quantity
		);
		// then that slot that was emptied for you the player is cleared
		// zero out the emptieness
		playerParty[pn].items[call].quantity = 0;
	}
	else
		// if you can't. swap the slots. step1
	{
		// do like this
		for (int i = 0; i < 25; i++)
		{
			if (saver.my_items[i].name == in.iname(call))
			{
				playerInventory.moveItmToAux(saver.my_items[i]);
			}
		}
		playerInventory.my_items[call].quantity = 0;
	}
}

void World::ItemTransferToPlayer(int call, int selection, int pn, PartyActor in)
{
	// invent item
	Inventory saver;
	//player item
	Inventory saverSnd;
	string nameFind;
	int FindO = 0;
	int FindS = 0;
	int FindSnd = 0;

	// save the slot for the weapon in question
	saverSnd.TranserItems
	(
		in.hps(call),
		in.sps(call),
		in.fps(call),
		in.atks(call),
		in.defs(call),
		in.speeds(call),
		in.agis(call),
		in.dexs(call),
		in.intels(call),
		in.sprs(call),
		in.strs(call),
		in.ends(call),
		in.cons(call),
		in.values(call),
		in.iname(call),
		in.quantites(call)
	);

	// Transfer to 0th saver slot

	saver.TranserItems
	(
		playerInventory.my_items[selection].hpd,
		playerInventory.my_items[selection].spd,
		playerInventory.my_items[selection].fpd,
		playerInventory.my_items[selection].atkd,
		playerInventory.my_items[selection].defd,
		playerInventory.my_items[selection].speedd,
		playerInventory.my_items[selection].agid,
		playerInventory.my_items[selection].dexd,
		playerInventory.my_items[selection].inteld,
		playerInventory.my_items[selection].sprd,
		playerInventory.my_items[selection].strd,
		playerInventory.my_items[selection].endd,
		playerInventory.my_items[selection].cond,
		playerInventory.my_items[selection].value,
		playerInventory.my_items[selection].name,
		playerInventory.my_items[selection].quantity
	);

	// find a slot in the player invent with the same name
	nameFind = in.iname(call);

	// int to string // string to int 
	if (FindO = playerInventory.findItemIndex(nameFind) == -1)
	{
		// s w a p 

		playerParty[pn].items[call].atkd =       saver.my_items[0].atkd;//
		playerParty[pn].items[call].agid =       saver.my_items[0].agid;//
		playerParty[pn].items[call].endd =       saver.my_items[0].endd;//
		playerParty[pn].items[call].fpd =        saver.my_items[0].fpd;//
		playerParty[pn].items[call].inteld =     saver.my_items[0].inteld;//
		playerParty[pn].items[call].defd =       saver.my_items[0].defd;//
		playerParty[pn].items[call].dexd =       saver.my_items[0].dexd;//
		playerParty[pn].items[call].sprd =       saver.my_items[0].sprd;//
		playerParty[pn].items[call].strd =       saver.my_items[0].strd;//
		playerParty[pn].items[call].speedd =     saver.my_items[0].speedd;//
		playerParty[pn].items[call].cond =       saver.my_items[0].cond;//
		playerParty[pn].items[call].hpd =        saver.my_items[0].hpd;//
		playerParty[pn].items[call].spd =        saver.my_items[0].spd;//
		playerParty[pn].items[call].name =       saver.my_items[0].name;//
		playerParty[pn].items[call].quantity =   saver.my_items[0].quantity;//
		playerParty[pn].items[call].value =      saver.my_items[0].value;// 17

		// saved slot goes here 

		playerInventory.my_items[selection].hpd =        saverSnd.my_items[0].hpd; //1
		playerInventory.my_items[selection].atkd =          saverSnd.my_items[0].atkd;//2
		playerInventory.my_items[selection].sprd =          saverSnd.my_items[0].sprd;//4
		playerInventory.my_items[selection].endd =          saverSnd.my_items[0].endd;//5
		playerInventory.my_items[selection].inteld =        saverSnd.my_items[0].inteld;//6
		playerInventory.my_items[selection].dexd =          saverSnd.my_items[0].dexd;//7
		playerInventory.my_items[selection].strd =          saverSnd.my_items[0].strd;//8
		playerInventory.my_items[selection].speedd =        saverSnd.my_items[0].speedd;//9
		playerInventory.my_items[selection].fpd =           saverSnd.my_items[0].fpd;//10
		playerInventory.my_items[selection].defd =          saverSnd.my_items[0].defd;//
		playerInventory.my_items[selection].spd =        saverSnd.my_items[0].spd;//
		playerInventory.my_items[selection].value =        saverSnd.my_items[0].value;//
		playerInventory.my_items[selection].name =         saverSnd.my_items[0].name;//
		playerInventory.my_items[selection].quantity =     saverSnd.my_items[0].quantity;//15
		playerInventory.my_items[selection].cond =          saverSnd.my_items[0].cond; // 16
		playerInventory.my_items[selection].agid =          saverSnd.my_items[0].agid; // 17
	}
	else
	{
		Inventory::item d;

		// KERCHONG!!! 
		playerParty[pn].items[call].atkd =       saver.my_items[0].atkd;//
		playerParty[pn].items[call].agid =       saver.my_items[0].agid;//
		playerParty[pn].items[call].endd =       saver.my_items[0].endd;//
		playerParty[pn].items[call].fpd =        saver.my_items[0].fpd;//
		playerParty[pn].items[call].inteld =     saver.my_items[0].inteld;//
		playerParty[pn].items[call].defd =       saver.my_items[0].defd;//
		playerParty[pn].items[call].dexd =       saver.my_items[0].dexd;//
		playerParty[pn].items[call].sprd =       saver.my_items[0].sprd;//
		playerParty[pn].items[call].strd =       saver.my_items[0].strd;//
		playerParty[pn].items[call].speedd =     saver.my_items[0].speedd;//
		playerParty[pn].items[call].cond =       saver.my_items[0].cond;//
		playerParty[pn].items[call].hpd =        saver.my_items[0].hpd;//
		playerParty[pn].items[call].spd =        saver.my_items[0].spd;//
		playerParty[pn].items[call].name =       saver.my_items[0].name;//
		playerParty[pn].items[call].quantity =   saver.my_items[0].quantity;//
		playerParty[pn].items[call].value =      saver.my_items[0].value;// 17

		// saved slot where? = > aux

		d.hpd =       saverSnd.my_items[0].hpd;//
		d.spd =       saverSnd.my_items[0].spd;//
		d.fpd =          saverSnd.my_items[0].fpd;//
		d.atkd =         saverSnd.my_items[0].atkd;//
		d.defd =         saverSnd.my_items[0].defd;//
		d.speedd =       saverSnd.my_items[0].speedd;//
		d.agid =         saverSnd.my_items[0].agid;//
		d.dexd =         saverSnd.my_items[0].dexd;//
		d.inteld =       saverSnd.my_items[0].inteld;//
		d.sprd =         saverSnd.my_items[0].sprd;//
		d.strd =         saverSnd.my_items[0].strd;//
		d.endd =         saverSnd.my_items[0].endd;//
		d.cond =         saverSnd.my_items[0].cond;//
		d.value =       saverSnd.my_items[0].value;// 17
		d.name =        saverSnd.my_items[0].name;//
		d.quantity =    saverSnd.my_items[0].quantity;//

		playerInventory.auxItems.push_front(d);
	}
}

void World::ItemTransferToPlayer(int call, int selection, int pn, PartyActor in, Inventory::item irm)
{
#pragma region old
	// invent item
	Inventory saver;
	//player item
	Inventory saverSnd;
	string nameFind;
	int FindO = 0;
	int FindS = 0;
	int FindSnd = 0;

	// save the slot for the item in question
	saverSnd.TranserItems
	(
		in.hps(call),
		in.sps(call),
		in.fps(call),
		in.atks(call),
		in.defs(call),
		in.speeds(call),
		in.agis(call),
		in.dexs(call),
		in.intels(call),
		in.sprs(call),
		in.strs(call),
		in.ends(call),
		in.cons(call),
		in.values(call),
		in.iname(call),
		in.quantites(call)
	);

	// Transfer to 0th saver slot

	saver.TranserItems
	(
		playerInventory.my_items[selection].hpd,
		playerInventory.my_items[selection].spd,
		playerInventory.my_items[selection].fpd,
		playerInventory.my_items[selection].atkd,
		playerInventory.my_items[selection].defd,
		playerInventory.my_items[selection].speedd,
		playerInventory.my_items[selection].agid,
		playerInventory.my_items[selection].dexd,
		playerInventory.my_items[selection].inteld,
		playerInventory.my_items[selection].sprd,
		playerInventory.my_items[selection].strd,
		playerInventory.my_items[selection].endd,
		playerInventory.my_items[selection].cond,
		playerInventory.my_items[selection].value,
		playerInventory.my_items[selection].name,
		playerInventory.my_items[selection].quantity
	);

	// find a slot in the player invent with the same name
	nameFind = in.aname(call);

	// make an item cpy from the params
	Inventory::item e;
	e = irm;

	// put it into an empty item slot...
	playerParty[call].itemUsageTransfer(selection);

	// if theres an item equipped move it to invent
	if (!(saverSnd.getName().empty()))
	{
		for (int i = 0; i < 25; i++)
		{
			if (playerInventory.my_items[i].name.empty())
			{
				playerInventory.my_items[i] = saverSnd.my_items[0];
				// if equip was succesful

				cout << "Item + " + e.name + "equipped.." << endl;
			}
			else
			{
				// or aux if invent is full
				playerInventory.auxItems.push_back(saverSnd.my_items[0]);
				// if equip was succesful

				cout << "Item + " + e.name + "equipped.." << endl;
			}
		}
	}
	//if not zero out
	else
	{
		playerInventory.itemZeroOut(selection);
	}

#pragma endregion
}

void World::ArmorTransferToInvent(int call, int pn, PartyActor in)
{
	Inventory saver;
	Inventory saverSnd;
	string nameFind;
	int FindO = 0;
	int FindS = 0;
	int FindSnd = 0;

	// transfer this ar
	saver.TranserArmors
	(
		in.ahps(call),
		in.aaps(call),
		in.asps(call),
		in.afps(call),
		in.atks(call),
		in.adefs(call),
		in.aspeeds(call),
		in.aagis(call),
		in.adexs(call),
		in.aintels(call),
		in.asprs(call),
		in.astrs(call),
		in.aends(call),
		in.acons(call),
		in.avalues(call),
		in.aname(call),
		in.aquantites(call)
	);

	nameFind = in.aname(call);

	// number item slot you saved for https://www.cplusplus.com/reference/tuple/tuple_element/
	FindS = saver.findAIndex(nameFind);

	// find an empty slot in the inventory
	if (playerInventory.FindEmptyASlot() != NULL)
	{
		FindO = playerInventory.FindEmptyASlot();
		// transfer to that slot
		playerInventory.TranserArmors
		(
			saver.my_armors[FindO].maxhp,
			saver.my_armors[FindO].ap,
			saver.my_armors[FindO].maxsp,
			saver.my_armors[FindO].fp,
			saver.my_armors[FindO].atk,
			saver.my_armors[FindO].def,
			saver.my_armors[FindO].speed,
			saver.my_armors[FindO].agi,
			saver.my_armors[FindO].dex,
			saver.my_armors[FindO].intel,
			saver.my_armors[FindO].spr,
			saver.my_armors[FindO].str,
			saver.my_armors[FindO].end,
			saver.my_armors[FindO].con,
			saver.my_armors[FindO].value,
			saver.my_armors[FindO].name,
			saver.my_armors[FindO].quantity
		);
		// then that slot that was emptied for you the player is cleared
		// zero out the emptieness
		playerParty[pn].unEquipArmor(call);
	}
	else
	{
		// do like this
		for (int i = 0; i < 25; i++)
		{
			if (saver.my_armors[i].name == in.aname(call))
			{
				playerInventory.moveArmToAux(saver.my_armors[i]);
			}
		}

		// finally unequip
		playerParty[pn].unEquipWeapon(call);
	}
}

void World::ArmorTransferToPlayer(int call, int selection, int pn, PartyActor in)
{
	// invent item
	Inventory saver;
	//player item
	Inventory saverSnd;
	string nameFind;
	int FindO = 0;
	int FindS = 0;
	int FindSnd = 0;

	// save the slot for the weapon in question
	saverSnd.TranserArmors
	(
		in.ahps(call),
		in.aaps(call),
		in.asps(call),
		in.afps(call),
		in.aatks(call),
		in.adefs(call),
		in.aspeeds(call),
		in.aagis(call),
		in.adexs(call),
		in.aintels(call),
		in.asprs(call),
		in.astrs(call),
		in.aends(call),
		in.acons(call),
		in.avalues(call),
		in.aname(call),
		in.aquantites(call)
	);

	// Transfer to 0th saver slot

	saver.TranserArmors
	(
		playerInventory.my_armors[selection].maxhp,
		playerInventory.my_armors[selection].ap,
		playerInventory.my_armors[selection].maxsp,
		playerInventory.my_armors[selection].fp,
		playerInventory.my_armors[selection].atk,
		playerInventory.my_armors[selection].def,
		playerInventory.my_armors[selection].speed,
		playerInventory.my_armors[selection].agi,
		playerInventory.my_armors[selection].dex,
		playerInventory.my_armors[selection].intel,
		playerInventory.my_armors[selection].spr,
		playerInventory.my_armors[selection].str,
		playerInventory.my_armors[selection].end,
		playerInventory.my_armors[selection].con,
		playerInventory.my_armors[selection].value,
		playerInventory.my_armors[selection].name,
		playerInventory.my_armors[selection].quantity
	);

	// find a slot in the player invent with the same name
	nameFind = in.aname(call);

	// int to string // string to int 
	if (FindO = playerInventory.findAIndex(nameFind) == -1)
	{
		// s w a p 

		playerParty[pn].armors[call].atk =      saver.my_armors[0].atk;//
		playerParty[pn].armors[call].ap =       saver.my_armors[0].ap;//
		playerParty[pn].armors[call].agi =      saver.my_armors[0].agi;//
		playerParty[pn].armors[call].end =      saver.my_armors[0].end;//
		playerParty[pn].armors[call].fp =       saver.my_armors[0].fp;//
		playerParty[pn].armors[call].intel =    saver.my_armors[0].intel;//
		playerParty[pn].armors[call].def =      saver.my_armors[0].def;//
		playerParty[pn].armors[call].dex =      saver.my_armors[0].dex;//
		playerParty[pn].armors[call].spr =      saver.my_armors[0].spr;//
		playerParty[pn].armors[call].str =      saver.my_armors[0].str;//
		playerParty[pn].armors[call].speed =    saver.my_armors[0].speed;//
		playerParty[pn].armors[call].con =      saver.my_armors[0].con;//
		playerParty[pn].armors[call].maxhp =    saver.my_armors[0].maxhp;//
		playerParty[pn].armors[call].maxsp =    saver.my_armors[0].maxsp;//
		playerParty[pn].armors[call].name =     saver.my_armors[0].name;//
		playerParty[pn].armors[call].quantity = saver.my_armors[0].quantity;//
		playerParty[pn].armors[call].value =    saver.my_armors[0].value;// 17

		// saved slot goes here 

		playerInventory.my_armors[selection].maxhp =    saverSnd.my_armors[0].maxhp; //1
		playerInventory.my_armors[selection].atk =      saverSnd.my_armors[0].atk;//2
		playerInventory.my_armors[selection].ap =       saverSnd.my_armors[0].ap;//3
		playerInventory.my_armors[selection].spr =      saverSnd.my_armors[0].spr;//4
		playerInventory.my_armors[selection].end =      saverSnd.my_armors[0].end;//5
		playerInventory.my_armors[selection].intel =    saverSnd.my_armors[0].intel;//6
		playerInventory.my_armors[selection].dex =      saverSnd.my_armors[0].dex;//7
		playerInventory.my_armors[selection].str =      saverSnd.my_armors[0].str;//8
		playerInventory.my_armors[selection].speed =    saverSnd.my_armors[0].speed;//9
		playerInventory.my_armors[selection].fp =       saverSnd.my_armors[0].fp;//10
		playerInventory.my_armors[selection].def =      saverSnd.my_armors[0].def;//
		playerInventory.my_armors[selection].maxsp =    saverSnd.my_armors[0].maxsp;//
		playerInventory.my_armors[selection].value =    saverSnd.my_armors[0].value;//
		playerInventory.my_armors[selection].name =     saverSnd.my_armors[0].name;//
		playerInventory.my_armors[selection].quantity = saverSnd.my_armors[0].quantity;//15
		playerInventory.my_armors[selection].con =      saverSnd.my_armors[0].con; // 16
		playerInventory.my_armors[selection].agi =      saverSnd.my_armors[0].agi; // 17
	}
	else
	{
		Inventory::armor d;

		// KERCHONG!!! 
		playerParty[pn].armors[call].atk =       saver.my_armors[0].atk;//
		playerParty[pn].armors[call].ap =        saver.my_armors[0].ap;//
		playerParty[pn].armors[call].agi =       saver.my_armors[0].agi;//
		playerParty[pn].armors[call].end =       saver.my_armors[0].end;//
		playerParty[pn].armors[call].fp =        saver.my_armors[0].fp;//
		playerParty[pn].armors[call].intel =     saver.my_armors[0].intel;//
		playerParty[pn].armors[call].def =       saver.my_armors[0].def;//
		playerParty[pn].armors[call].dex =       saver.my_armors[0].dex;//
		playerParty[pn].armors[call].spr =       saver.my_armors[0].spr;//
		playerParty[pn].armors[call].str =       saver.my_armors[0].str;//
		playerParty[pn].armors[call].speed =     saver.my_armors[0].speed;//
		playerParty[pn].armors[call].con =       saver.my_armors[0].con;//
		playerParty[pn].armors[call].maxhp =     saver.my_armors[0].maxhp;//
		playerParty[pn].armors[call].maxsp =     saver.my_armors[0].maxsp;//
		playerParty[pn].armors[call].name =      saver.my_armors[0].name;//
		playerParty[pn].armors[call].quantity =  saver.my_armors[0].quantity;//
		playerParty[pn].armors[call].value =     saver.my_armors[0].value;// 17

		// saved slot where? = > aux

		d.maxhp =      saverSnd.my_armors[0].maxhp;//
		d.ap =         saverSnd.my_armors[0].ap;//
		d.maxsp =      saverSnd.my_armors[0].maxsp;//
		d.fp =         saverSnd.my_armors[0].fp;//
		d.atk =        saverSnd.my_armors[0].atk;//
		d.def =        saverSnd.my_armors[0].def;//
		d.speed =      saverSnd.my_armors[0].speed;//
		d.agi =        saverSnd.my_armors[0].agi;//
		d.dex =        saverSnd.my_armors[0].dex;//
		d.intel =      saverSnd.my_armors[0].intel;//
		d.spr =        saverSnd.my_armors[0].spr;//
		d.str =        saverSnd.my_armors[0].str;//
		d.end =        saverSnd.my_armors[0].end;//
		d.con =        saverSnd.my_armors[0].con;//
		d.value =      saverSnd.my_armors[0].value;// 17
		d.name =       saverSnd.my_armors[0].name;//
		d.quantity =   saverSnd.my_armors[0].quantity;//

		playerInventory.auxArmors.push_front(d);
	}
}

void World::ArmorTransferToPlayer(int call, int selection, int pn, PartyActor in, Inventory::armor arm)
{
#pragma region old
	// invent item
	Inventory saver;
	//player item
	Inventory saverSnd;
	string nameFind;
	int FindO = 0;
	int FindS = 0;
	int FindSnd = 0;

	// save the slot for the armor in question
	saverSnd.TranserArmors
	(
		in.ahps(call),
		in.aaps(call),
		in.asps(call),
		in.afps(call),
		in.aatks(call),
		in.adefs(call),
		in.aspeeds(call),
		in.aagis(call),
		in.adexs(call),
		in.aintels(call),
		in.asprs(call),
		in.astrs(call),
		in.aends(call),
		in.acons(call),
		in.avalues(call),
		in.aname(call),
		in.aquantites(call)
	);

	// Transfer to 0th saver slot

	saver.TranserArmors
	(
		playerInventory.my_armors[selection].maxhp,
		playerInventory.my_armors[selection].ap,
		playerInventory.my_armors[selection].maxsp,
		playerInventory.my_armors[selection].fp,
		playerInventory.my_armors[selection].atk,
		playerInventory.my_armors[selection].def,
		playerInventory.my_armors[selection].speed,
		playerInventory.my_armors[selection].agi,
		playerInventory.my_armors[selection].dex,
		playerInventory.my_armors[selection].intel,
		playerInventory.my_armors[selection].spr,
		playerInventory.my_armors[selection].str,
		playerInventory.my_armors[selection].end,
		playerInventory.my_armors[selection].con,
		playerInventory.my_armors[selection].value,
		playerInventory.my_armors[selection].name,
		playerInventory.my_armors[selection].quantity
	);

	// find a slot in the player invent with the same name
	nameFind = in.aname(call);

	// make an armor cpy from the params
	Inventory::armor e;
	e = arm;

	// put it into an empty armor slot...
	playerParty[call].statArmorTransfer(
		playerParty[call].FindEmptyASlot(),
		e.maxhp,
		e.ap,
		e.maxsp,
		e.fp,
		e.atk,
		e.def,
		e.speed,
		e.agi,
		e.dex,
		e.intel,
		e.spr,
		e.str,
		e.end,
		e.con,
		e.value,
		e.name
		);

	// if theres an armor equipped move it to invent
	if (!(saverSnd.getName().empty()))
	{
		for (int i = 0; i < 25; i++)
		{
			if (playerInventory.my_armors[i].name.empty())
			{
				playerInventory.my_armors[i] = saverSnd.my_armors[0];
				// if equip was succesful

				cout << "Armor + " + e.name + "equipped.." << endl;
			}
			else
			{
				// or aux if invent is full
				playerInventory.auxArmors.push_back(saverSnd.my_armors[0]);
				// if equip was succesful

				cout << "Armor + " + e.name + "equipped.." << endl;
			}
		}
	}
	//if not zero out
	else
	{
		playerInventory.armorZeroOut(selection);
	}
	
#pragma endregion

}

void World::afterBattleUpdate(PartyActor p[])
{

}

World::~World()
{
}
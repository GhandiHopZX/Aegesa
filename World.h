#pragma once
#include <string>
#include "PartyActor.h"
#include "Inventory.h"

using namespace std;

class World
{
public:

	World();

	// you can use homogeneous data to change heterogeneous data
	// 	    goto line 91 in the CPP file for this class
	//tuple<string> h{ "fcg" };

	//string gai = "";

	void Campagin();

	void addPartyMember(int m, PartyActor in);

	void EquipMenuCall(PartyActor px[]);

	void WeaponTransferToInvent(int call, int pn, PartyActor in);

	void WeaponTransferToPlayer(int call, int selection, int pn, PartyActor in);

	void WeaponTransferToPlayer(int call, int selection, int pn, PartyActor in, Inventory::weapon wrm);

	void ItemTransferToInvent(int call, int pn, PartyActor in);

	void ItemTransferToPlayer(int call, int selection, int pn, PartyActor in);

	void ItemTransferToPlayer(int call, int selection, int pn, PartyActor in, Inventory::item irm);

	void ArmorTransferToInvent(int call, int pn, PartyActor in);

	void ArmorTransferToPlayer(int call, int selection, int pn, PartyActor in);

	void ArmorTransferToPlayer(int call, int selection, int pn, PartyActor in, Inventory::armor arm);

	void afterBattleUpdate(PartyActor i[]);

	~World();

private:
};
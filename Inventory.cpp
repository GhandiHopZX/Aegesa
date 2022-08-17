#include "Inventory.h"

Inventory::Inventory()
{
}

void Inventory::itemCheck()
{
	list<item> cpy;
	for (int i = 0; i < 25; i++)
	{
		if (my_items[i].quantity == 0)
		{
			itemZeroOut(i);
		}
		if (my_armors[i].quantity == 0)
		{
			armorZeroOut(i);
		}
		if (my_weapons[i].quantity == 0)
		{
			weaponZeroOut(i);
		}
	}
	for (std::list<item>::iterator gen = auxItems.begin(); 
		gen != auxItems.end(); ++gen)
	{
		if (auxItems.front().quantity != 0)
		{
			cpy.push_front(auxItems.front());
			auxItems.pop_front();
			auxItems.push_back(cpy.front());
		}
		else
		{
			auxItems.pop_front();
		}
	}
}

void Inventory::TranserArmors(int maxhp,
	int ap, int maxsp,
	int fpd, int atkd,
	int defd, int speedd,
	int agid, int dexd,
	int inteld, int sprd,
	int strd, int endd,
	int cond, int value, string name, int quantity)
{
	for (int i = 0; i < 25; i++)
	{
		if (my_armors[i].name.empty())
		{
			my_armors[i].name = name;
			my_armors[i].value = value;
			my_armors[i].quantity = quantity;
			my_armors[i].maxsp = maxsp;
			my_armors[i].maxhp = maxhp;
			my_armors[i].atk = atkd;
			my_armors[i].agi = agid;
			my_armors[i].ap = ap;
			my_armors[i].con = cond;
			my_armors[i].def = defd;
			my_armors[i].dex = dexd;
			my_armors[i].end = endd;
			my_armors[i].fp = fpd;
			my_armors[i].intel = inteld;
			my_armors[i].speed = speedd;
			my_armors[i].spr = sprd;
			my_armors[i].str = strd;
			return;
		}
		else
		{
			armor dup;
			dup.name = name;
			dup.value = value;
			dup.quantity = quantity;
			dup.maxsp = maxsp;
			dup.maxhp = maxhp;
			dup.atk = atkd;
			dup.agi = agid;
			dup.ap = ap;
			dup.con = cond;
			dup.def = defd;
			dup.dex = dexd;
			dup.end = endd;
			dup.fp = fpd;
			dup.intel = inteld;
			dup.speed = speedd;
			dup.spr = sprd;
			dup.str = strd;
			auxArmors.push_front(dup);
		}
	}
}

void Inventory::TranserWeapons(int maxhp,
	int ap, int maxsp,
	int fpd, int atkd,
	int defd, int speedd,
	int agid, int dexd,
	int inteld, int sprd,
	int strd, int endd,
	int cond, int value, 
	string name, int quantity)
{
	for (int i = 0; i < 25; i++)
	{
		if (my_weapons[i].name.empty())
		{
			my_weapons[i].name = name;
			my_weapons[i].value = value;
			my_weapons[i].quantity = quantity;
			my_weapons[i].maxsp = maxsp;
			my_weapons[i].maxhp = maxhp;
			my_weapons[i].atk = atkd;
			my_weapons[i].agi = agid;
			my_weapons[i].ap = ap;
			my_weapons[i].con = cond;
			my_weapons[i].def = defd;
			my_weapons[i].dex = dexd;
			my_weapons[i].end = endd;
			my_weapons[i].fp = fpd;
			my_weapons[i].intel = inteld;
			my_weapons[i].speed = speedd;
			my_weapons[i].spr = sprd;
			my_weapons[i].str = strd;
			return;
		}
		else
		{
			weapon dup;
			dup.name = name;
			dup.value = value;
			dup.quantity = quantity;
			dup.maxsp = maxsp;
			dup.maxhp = maxhp;
			dup.atk = atkd;
			dup.agi = agid;
			dup.ap = ap;
			dup.con = cond;
			dup.def = defd;
			dup.dex = dexd;
			dup.end = endd;
			dup.fp = fpd;
			dup.intel = inteld;
			dup.speed = speedd;
			dup.spr = sprd;
			dup.str = strd;
			auxWeapons.push_front(dup);
		}
	}
}

void Inventory::TranserItems(int maxhp, int maxsp,
	int fpd, int atkd,
	int defd, int speedd,
	int agid, int dexd,
	int inteld, int sprd,
	int strd, int endd,
	int cond, int value,
	string name, int quantity)
{
	for (int i = 0; i < 25; i++)
	{
		if (my_items[i].name.empty())
		{
			my_items[i].name = name;
			my_items[i].value = value;
			my_items[i].quantity = quantity;
			my_items[i].spd = maxsp;
			my_items[i].hpd = maxhp;
			my_items[i].atkd = atkd;
			my_items[i].agid = agid;
			my_items[i].cond = cond;
			my_items[i].defd = defd;
			my_items[i].dexd = dexd;
			my_items[i].endd = endd;
			my_items[i].fpd = fpd;
			my_items[i].inteld = inteld;
			my_items[i].speedd = speedd;
			my_items[i].sprd = sprd;
			my_items[i].strd = strd;
			return;
		}
		else
		{
			item dup;
			dup.name = name;
			dup.value = value;
			dup.quantity = quantity;
			dup.spd = maxsp;
			dup.hpd = maxhp;
			dup.atkd = atkd;
			dup.agid = agid;
			dup.cond = cond;
			dup.defd = defd;
			dup.dexd = dexd;
			dup.endd = endd;
			dup.fpd= fpd;
			dup.inteld = inteld;
			dup.speedd = speedd;
			dup.sprd = sprd;
			dup.strd = strd;
			auxItems.push_front(dup);
		}
	}
}

void Inventory::TranserAllArmors(int maxhp[], int ap[],
	int maxsp[], int atk[], int fp[],
	int def[], int speed[],
	int agi[], int dex[],
	int intel[], int spr[],
	int str[], int end[],
	int con[], int value[],
	string name[], int quantity[])
{
	for (int i = 0; i < 25; i++)
	{
		if (my_armors[i].name.empty())
		{
			my_armors[i].name = name[i];
			my_armors[i].atk = atk[i];
			my_armors[i].ap = ap[i];
			my_armors[i].maxsp = maxsp[i];
			my_armors[i].value = value[i];
			my_armors[i].quantity = quantity[i];
			my_armors[i].maxhp = maxhp[i];
			my_armors[i].agi = agi[i];
			my_armors[i].con = con[i];
			my_armors[i].def = def[i];
			my_armors[i].dex = dex[i];
			my_armors[i].end = end[i];
			my_armors[i].fp = fp[i];
			my_armors[i].intel = intel[i];
			my_armors[i].speed = speed[i];
			my_armors[i].spr = spr[i];
			my_armors[i].str = str[i];
		}
		else
		{
			armor dup;
			dup.name = name[i];
			dup.value = value[i];
			dup.quantity = quantity[i];
			dup.maxsp = maxsp[i];
			dup.maxhp = maxhp[i];
			dup.atk = atk[i];
			dup.agi = agi[i];
			dup.ap = ap[i];
			dup.con = con[i];
			dup.def = def[i];
			dup.dex = dex[i];
			dup.end = end[i];
			dup.fp = fp[i];
			dup.intel = intel[i];
			dup.speed = speed[i];
			dup.spr = spr[i];
			dup.str = str[i];
			auxArmors.push_front(dup);
		}
	}
}

void Inventory::TranserAllWeapons(int maxhp[], int ap[],
	int maxsp[], int atk[], int fp[],
	int def[], int speed[],
	int agi[], int dex[],
	int intel[], int spr[],
	int str[], int end[],
	int con[], int value[],
	string name[], int quantity[])
{
	for (int i = 0; i < 25; i++)
	{
		if (my_weapons[i].name.empty())
		{
			my_weapons[i].name = name[i];
			my_weapons[i].atk = atk[i];
			my_weapons[i].ap = ap[i];
			my_weapons[i].maxsp = maxsp[i];
			my_weapons[i].value = value[i];
			my_weapons[i].quantity = quantity[i];
			my_weapons[i].maxhp = maxhp[i];
			my_weapons[i].agi = agi[i];
			my_weapons[i].con = con[i];
			my_weapons[i].def = def[i];
			my_weapons[i].dex = dex[i];
			my_weapons[i].end = end[i];
			my_weapons[i].fp = fp[i];
			my_weapons[i].intel = intel[i];
			my_weapons[i].speed = speed[i];
			my_weapons[i].spr = spr[i];
			my_weapons[i].str = str[i];
		}
		else
		{
			weapon dup;
			dup.name = name[i];
			dup.value = value[i];
			dup.quantity = quantity[i];
			dup.maxsp = maxsp[i];
			dup.maxhp = maxhp[i];
			dup.atk = atk[i];
			dup.agi = agi[i];
			dup.ap = ap[i];
			dup.con = con[i];
			dup.def = def[i];
			dup.dex = dex[i];
			dup.end = end[i];
			dup.fp = fp[i];
			dup.intel = intel[i];
			dup.speed = speed[i];
			dup.spr = spr[i];
			dup.str = str[i];
			auxWeapons.push_front(dup);
		}
	}
}

void Inventory::TranserAllItems(int maxhp[],
	int maxsp[], int atk[], int fp[],
	int def[], int speed[],
	int agi[], int dex[],
	int intel[], int spr[],
	int str[], int end[],
	int con[], int value[],
	string name[], int quantity[])
{
	for (int i = 0; i < 25; i++)
	{
		if (my_armors[i].name.empty())
		{
			my_armors[i].name = name[i];
			my_armors[i].atk = atk[i];
			my_armors[i].maxsp = maxsp[i];
			my_armors[i].value = value[i];
			my_armors[i].quantity = quantity[i];
			my_armors[i].maxhp = maxhp[i];
			my_armors[i].agi = agi[i];
			my_armors[i].con = con[i];
			my_armors[i].def = def[i];
			my_armors[i].dex = dex[i];
			my_armors[i].end = end[i];
			my_armors[i].fp = fp[i];
			my_armors[i].intel = intel[i];
			my_armors[i].speed = speed[i];
			my_armors[i].spr = spr[i];
			my_armors[i].str = str[i];
		}
		else
		{
			item dup;
			dup.name = name[i];
			dup.value = value[i];
			dup.quantity = quantity[i];
			dup.spd = maxsp[i];
			dup.hpd = maxhp[i];
			dup.atkd = atk[i];
			dup.agid = agi[i];
			dup.cond = con[i];
			dup.defd = def[i];
			dup.dexd = dex[i];
			dup.endd = end[i];
			dup.fpd = fp[i];
			dup.inteld = intel[i];
			dup.speedd = speed[i];
			dup.sprd = spr[i];
			dup.strd = str[i];
			auxItems.push_front(dup);
		}
	}
}

// armors, weapons, items

void Inventory::moveItmToAux(Inventory::item d)
{
	auxItems.push_front(d);
}

void Inventory::moveArmToAux(Inventory::armor d)
{
	auxArmors.push_front(d);
}

void Inventory::moveWepToAux(Inventory::weapon d)
{
	auxWeapons.push_front(d);
}

void Inventory::initAuxItemList()
{
	int y = 26;

	for (std::list<item>::iterator gen = auxItems.begin(); gen != auxItems.end(); ++gen)
	{
		pair<item, int> me;
		me.first = gen.operator*();
		me.second = y;
		++y;
		demoi.push_front(me);
	}
}

void Inventory::initAuxArmorList()
{
	int y = 26;

	for (std::list<armor>::iterator gen
		= auxArmors.begin(); gen != auxArmors.end(); ++gen)
	{
		pair<armor, int> me;
		me.first = gen.operator*();
		me.second = y;
		++y;
		demoa.push_front(me);
	}
}

void Inventory::initAuxWeaponList()
{
	int y = 26;

	for (std::list<weapon>::iterator gen
		= auxWeapons.begin(); gen != auxWeapons.end(); ++gen)
	{
		pair<weapon, int> me;
		me.first = gen.operator*();
		me.second = y;
		++y;
		demow.push_front(me);
	}
}

Inventory::item Inventory::itemAuxCall(int call)
{
	for (std::list<pair<item, int>>::iterator geno
		= demoi.begin(); geno != demoi.end(); ++geno)
	{
		if (call == geno->second)
		{
			return geno->first;
		}
	}
}

Inventory::armor Inventory::armorAuxCall(int call)
{
	for (std::list<pair<armor, int>>::iterator geno
		= demoa.begin(); geno != demoa.end(); ++geno)
	{
		if (call == geno->second)
		{
			return geno->first;
		}
	}
}

Inventory::weapon Inventory::weaponAuxCall(int call)
{
	for (std::list<pair<weapon, int>>::iterator geno
		= demow.begin(); geno != demow.end(); ++geno)
	{
		if (call == geno->second)
		{
			return geno->first;
		}
	}
}

// no null checks just switch the rest in the bank where you would normally in World.cpp

// zero outs

void Inventory::weaponZeroOut(int call)
{
	my_weapons[call].name = "";
	my_weapons[call].atk = 0;
	my_weapons[call].agi = 0;
	my_weapons[call].ap = 0;
	my_weapons[call].con = 0;
	my_weapons[call].def = 0;
	my_weapons[call].dex = 0;
	my_weapons[call].end = 0;
	my_weapons[call].fp = 0;
	my_weapons[call].intel = 0;
	my_weapons[call].speed = 0;
	my_weapons[call].spr = 0;
	my_weapons[call].str = 0;
	my_weapons[call].maxsp = 0;
	my_weapons[call].value = 0;
	my_weapons[call].quantity = 0;
	my_weapons[call].maxhp = 0;
}

void Inventory::itemZeroOut(int call)
{
	my_items[call].name = "";
	my_items[call].atkd = 0;
	my_items[call].agid = 0;
	my_items[call].cond = 0;
	my_items[call].defd = 0;
	my_items[call].dexd = 0;
	my_items[call].endd = 0;
	my_items[call].fpd = 0;
	my_items[call].inteld = 0;
	my_items[call].speedd = 0;
	my_items[call].sprd = 0;
	my_items[call].strd = 0;
	my_items[call].spd = 0;
	my_items[call].value = 0;
	my_items[call].quantity = 0;
	my_items[call].hpd = 0;
}

void Inventory::armorZeroOut(int call)
{
	my_armors[call].name = "";
	my_armors[call].atk = 0;
	my_armors[call].agi = 0;
	my_armors[call].ap = 0;
	my_armors[call].con = 0;
	my_armors[call].def = 0;
	my_armors[call].dex = 0;
	my_armors[call].end = 0;
	my_armors[call].fp = 0;
	my_armors[call].intel = 0;
	my_armors[call].speed = 0;
	my_armors[call].spr = 0;
	my_armors[call].str = 0;
	my_armors[call].maxsp = 0;
	my_armors[call].value = 0;
	my_armors[call].quantity = 0;
	my_armors[call].maxhp = 0;
}

Inventory::item Inventory::myItemCall(int d)
{
	return my_items[d];
}

Inventory::armor Inventory::myArmorCall(int d)
{
	return my_armors[d];
}

Inventory::weapon Inventory::myWepCall(int d)
{
	return my_weapons[d];
}

Inventory::item Inventory::myItmListCall(int d)
{
	for (std::list<pair<Inventory::item, int>>::iterator id =
		demoi.begin(); id != demoi.end(); ++id)
	{
		if (d == id.operator*().second)
		{
			return id.operator*().first;
		}
	}
}

Inventory::armor Inventory::myArmListCall(int d)
{
	for (std::list<pair<Inventory::armor, int>>::iterator id =
		demoa.begin(); id != demoa.end(); ++id)
	{
		if (d == id.operator*().second)
		{
			return id.operator*().first;
		}
	}
}

Inventory::weapon Inventory::myWepListCall(int d)
{
	for (std::list<pair<Inventory::weapon, int>>::iterator id =
		demow.begin(); id != demow.end(); ++id)
	{
		if (d == id.operator*().second)
		{
			return id.operator*().first;
		}
	}
}

int Inventory::findWIndex(string c)
{
	for (int i = 0; i < 25; i++)
	{
		if (c == my_weapons[i].name)
		{
			return i;
		}
	}
	return -1;
}

int Inventory::findAIndex(string c)
{
	for (int i = 0; i < 25; i++)
	{
		if (c == my_armors[i].name)
		{
			return i;
		}
	}
	return -1;
}

int Inventory::findItemIndex(string c)
{
	for (int i = 0; i < 25; i++)
	{
		if (c == my_items[i].name)
		{
			return i;
		}
	}
	return -1;
}

int Inventory::FindEmptyASlot()
{
	for (int i = 0; i < 25; i++)
	{
		if (my_armors[i].name.empty())
		{
			return i;
		}
	}
	return NULL;
}

int Inventory::FindEmptyISlot()
{
	for (int i = 0; i < 25; i++)
	{
		if (my_items[i].name.empty())
		{
			return i;
		}
	}
	return NULL;
}

int Inventory::FindEmptyWSlot()
{
	for (int i = 0; i < 25; i++)
	{
		if (my_weapons[i].name.empty())
		{
			return i;
		}
	}
	return NULL;
}

// pretty menu

void Inventory::displaylistItem()
{
	initAuxItemList();
	for (size_t i = 0; i < 25; i++)
	{
		if (!(my_items[i].name.empty())) // leave the value in the middle blank. it'll only return the already existant set value.
		{
			cout << i << ": " << my_items[i].name << endl;
		}
	}
	for (std::list<pair<item, int>>::iterator it 
		= demoi.begin(); it != demoi.end(); ++it)
	{
		cout << demoi.front().first.name << endl;
	}
}

void Inventory::displaylistWeapon()
{
	initAuxWeaponList();
	for (size_t i = 0; i < 25; i++)
	{
		if (!(my_weapons[i].name.empty())) // leave the value in the middle blank. it'll only return the already existant set value.
		{
			cout << my_weapons[i].name << endl;
		}
	}
	for (std::list<pair<weapon, int>>::iterator it
		= demow.begin(); it != demow.end(); ++it)
	{
		cout << demow.front().first.name << endl;
	}
}

void Inventory::displaylistArmor()
{
	initAuxArmorList();
	for (size_t i = 0; i < 25; i++)
	{
		if (!(my_armors[i].name.empty())) // leave the value in the middle blank. it'll only return the already existant set value.
		{
			cout << my_armors[i].name << endl;
		}
	}
	for (std::list<pair<armor, int>>::iterator it
		= demoa.begin(); it != demoa.end(); ++it)
	{
		cout << demoa.front().first.name << endl;
	}
}

void Inventory::DisplayMenuCall()
{
	system("CLS");
	char slel{};
	int armorc{};
	int itemc{};
	int weaponc{};
	int count;
	cout << "select which set of items you wish to see." << endl;
	cout << "\n Weapons(w), itmes(i), armors(a), Quit(q)";
	cout << endl;
	cin >> slel;

	switch (slel)
	{
	case 'a':
		displaylistArmor();
		cout << "OK?" << endl;
		system("PAUSE");
		DisplayMenuCall();
		
		switch (armorc)
		{
		default:
			count = 0;
			list<pair<Inventory::armor, int>> bpp;
			for (int i = 0; i < 25; i++)
			{
				pair <Inventory::armor, int> ds;
				ds.first = my_armors[i];
				ds.second = count;
				bpp.push_front(ds);
				//bpp.push_front(my_armors[i], count);
				cout << count << " " << my_armors[i].name << endl;
				++count;
			}
			for (std::list<pair<Inventory::armor, int>>::iterator geno
				= demoa.begin(); geno != demoa.end(); ++geno)
			{
				bpp.push_front(demoa.front());
				cout << count << " " << demoa.front().first.name << endl;
				++count;
				demoa.pop_front();
			}
			cout << "OK?" << endl;
			system("PAUSE");
			break;
		}

	case 'i':
		displaylistItem();
		cout << "OK?" << endl;
		system("PAUSE");
		DisplayMenuCall();

		cout << "select the item you wish to equip (choose number#(1 ... x))" << endl;
		switch (itemc)
		{
		default:
			list<Inventory::item> bpp;
			for (int i = 0; i < 25; i++)
			{
				bpp.push_front(my_items[i]);
			}
			for (std::list<pair<Inventory::item, int>>::iterator geno
				= demoi.begin(); geno != demoi.end(); ++geno)
			{
				bpp.push_front(demoi.front().first);
			}
			break;
		}

	case 'w':
		displaylistWeapon();
		cout << "OK?" << endl;
		system("PAUSE");
		DisplayMenuCall();

		cout << "select the weapon you wish to equip (choose number#(1 ... x))" << endl;
		switch (weaponc)
		{
		default:
			list<Inventory::weapon> bpp;
			for (int i = 0; i < 25; i++)
			{
				bpp.push_front(my_weapons[i]);
			}
			for (std::list<pair<Inventory::weapon, int>>::iterator geno
				= demow.begin(); geno != demow.end(); ++geno)
			{
				bpp.push_front(demow.front().first);
			}
			break;
		}

	case 'q':
		break;
	default:
		
		displaylistItem();

		displaylistWeapon();

		displaylistArmor();
		cout << "All items listed here. Ok?" << endl;
		system("PAUSE");
		DisplayMenuCall();
		
		break;
	}
	
}

void Inventory::setName(string c)
{
	name = c;
}


string Inventory::getName()
{
	return name;
}
// 

Inventory::~Inventory()
{
}

list<pair<Inventory::weapon, int>> Inventory::getDemow()
{
	return demow;
}

list<pair<Inventory::armor, int>> Inventory::getDemoa()
{
	return demoa;
}

list<pair<Inventory::item, int>> Inventory::getDemoi()
{
	return demoi;
}

#include "shapeTwoD.h"

//default constructor
shapeTwoD::shapeTwoD()
{
}

//other constructor
shapeTwoD::shapeTwoD(string isname, bool iscontainsWarpSpace)
{
	name = isname;
	containsWarpSpace = iscontainsWarpSpace;
}

//copy constructor
shapeTwoD::shapeTwoD(const shapeTwoD& s1)
{
	name= s1.name;
	containsWarpSpace =s1.containsWarpSpace;
}
string shapeTwoD::getName()
{
	return name;
}

bool shapeTwoD::getContainsWarpSpace()
{
	return containsWarpSpace;
}

void shapeTwoD::setName(string setname)
{
	name = setname;
}

void shapeTwoD::setContainsWarpSpace(bool setcontainsWarpSpace)
{
	containsWarpSpace = setcontainsWarpSpace;
}

//tostring will be overrided by subclasses
string shapeTwoD::toString()
{
	string n;
	
	if(containsWarpSpace == true)
	{
		n = "WS";
	}
	
	else
	{
		n = "NS";
	}
	
	string s = "Name: " + name + "\nSpecial Type: " + n + "\n";
	
	return s;
}












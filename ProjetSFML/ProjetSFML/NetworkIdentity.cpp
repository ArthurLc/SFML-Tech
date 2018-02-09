#include "NetworkLC.h"
#include "NetworkIdentity.h"
#include <iostream>
#include <thread>
#include <list>
#include <vector>


NetworkIdentity::NetworkIdentity()
{
	if (NetworkLC::GetGOList().size() < 255)
	{ //TODO: Solution, avoir plus de 255 objets.
		char newID;
		NetworkLC::GetGOList().count(newID);
		networkID = newID;
		NetworkLC::AddGO(this);
	}
	else
		printf("ERROR: No more 255 objects on the scene.");
}

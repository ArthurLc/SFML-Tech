#include "stdafx.h"
#include <thread>


NetworkIdentity::NetworkIdentity()
{
	Obj_mtx = new mutex();

	if (NetworkLC::GetGOList().size() < 255)
	{ //TODO: Solution, avoir plus de 255 objets.
		NetworkLC::AddGO(this);
		int newID = NetworkLC::GetGOList().size();
		networkID = (char)newID;
	}
	else
		printf("ERROR: No more 255 objects on the scene.");
}

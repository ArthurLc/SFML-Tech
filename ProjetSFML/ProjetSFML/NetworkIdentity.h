#pragma once
#include "NetworkLC.h"

enum NetworkUpdateMode
{
	OnChange,
	Continuous
};

class NetworkIdentity
{
private:
	char networkID = -1;

protected:
	NetworkIdentity();

	NetworkUpdateMode updateMode;
	std::auto_ptr<NetworkIdentity> objType;
	void* obj;

public:
	inline virtual char GetNetworkID() const { return networkID; }
	inline virtual void* GetObj() const { return obj; }
	inline virtual NetworkIdentity* GetObjType() const { return objType.get(); }
};


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
	void* obj;

public:
	inline virtual char GetNetworkID() const { return networkID; }
	inline virtual void* GetObj() const { return obj; }
};


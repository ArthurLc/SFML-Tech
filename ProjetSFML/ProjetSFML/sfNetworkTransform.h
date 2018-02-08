#pragma once
class sfNetworkTransform : public sfTransform
{
private:
	char networkID = 0;

	std::thread* m_MsgLoopThread;

	// THREADS
	int ThreadMsgLoop();

public:
	sfNetworkTransform();
	~sfNetworkTransform();

	inline char GetNetworkID() { return networkID; }
};


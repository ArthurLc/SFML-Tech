#pragma once
class sfNetworkButton : public sfButton
{
private:
	char networkID = 1;

	std::thread* m_MsgLoopThread;

	// THREADS
	int ThreadMsgLoop();

public:
	sfNetworkButton(std::string _text, sf::Vector2f _pos = { 0,0 }, sf::Vector2f _rot = { 0,0 }, sf::Vector2f _scale = { 1,1 }, std::string _sSpriteFile = "../Datas/ContactButton.png");
	~sfNetworkButton();

	void SetPos(sf::Vector2f _pos);
	//virtual void SetRot(sf::Vector2f _rot) { rot = _rot; }
	//virtual void SetScale(sf::Vector2f _scale) { scale = _scale; }

	inline char GetNetworkID() { return networkID; }
};


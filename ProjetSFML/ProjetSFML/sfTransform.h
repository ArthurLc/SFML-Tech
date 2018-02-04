#pragma once
class sfTransform
{
private:
	sf::Vector2f pos;
	sf::Vector2f rot;
	sf::Vector2f scale;
public:
	sfTransform();
	~sfTransform();

	virtual inline void SetPos(sf::Vector2f _pos) { pos = _pos; }
	virtual inline void SetRot(sf::Vector2f _rot) { rot = _rot; }
	virtual inline void SetScale(sf::Vector2f _scale) { scale = _scale; }

	virtual inline sf::Vector2f GetPos() const { return pos; }
	virtual inline sf::Vector2f GetRot() const { return rot; }
	virtual inline sf::Vector2f GetScale() const { return scale; }
};


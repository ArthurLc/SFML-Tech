#pragma once
class sfButton : public sfTransform
{
protected:
	sf::Sprite sprite;
	sf::Text text;

	sf::Vector2f mousePos;
	bool isMouseOnButton;
	bool isMouseDown;

	bool OnMousePos(sf::RenderWindow& _window);

public:
	sfButton();
	sfButton(std::string _text, sf::Vector2f _pos = { 0,0 }, sf::Vector2f _rot = { 0,0 }, sf::Vector2f _scale = { 1,1 }, std::string _sSpriteFile = "../Datas/ContactButton.png");
	~sfButton();

	inline void SetSprite(sf::Sprite _sprite) { sprite = _sprite; }
	inline void SetText(std::string _text) { text.setString(_text); }
	inline void SetFillColor(sf::Color _color) { text.setFillColor(_color); }

	inline sf::Sprite GetSprite() { return sprite; }
	inline sf::Text GetText() { return text; }

	bool OnMouseDown(sfCursor* cursor, sf::RenderWindow& _window);
	bool OnMouseUp(sfCursor* cursor, sf::RenderWindow& _window);
	void Draw(sf::RenderWindow& _window);
};


#pragma once
class sfCursor
{
private:
	sf::Sprite* currentCursor;
	sf::Sprite basicCursor;
	sf::Sprite interactibleCursor;

public:
	sfCursor();
	~sfCursor();

	inline void SetCursorToBasic() { currentCursor = &basicCursor; }
	inline void SetCursorToInteractible() { currentCursor = &interactibleCursor; }

	void BlitCursor(sf::RenderWindow& _window);
};


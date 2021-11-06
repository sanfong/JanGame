#pragma once
#include "AllHeader.h"
#define MAX_ITEMS 3 //play leaderboard exit

using namespace std;
using namespace sf;

class Menu
{
public:
	Menu(RenderWindow* window);
	~Menu();	

	void draw();
	void update();
	void MoveLeft();
	void MoveRight();
	int GetPressedItem() { return selectedItem; }

private:
	RenderWindow* window;
	sf::Texture backgroundTexture;
	Sprite background;
	int selectedItem;
	sf::Vector2f size;
	sf::Vector2f position;
	sf::Font font;
	sf::Text menu[MAX_ITEMS];

};


#pragma once
#include "Player.h"
#include "Space.h"
#include "Background.h"
#define maxHeart 10

class Game
{
private:
	RenderWindow* window;
	Texture spaceTexture;
	Player player;
	Space space;
	Space space2;
	Space space3;
	Font font;
	Text scoreText;
	Texture heartTexture;
	Sprite hearts[maxHeart];
	Vector2f heartStartPos;
	Texture backgroundTexture[3];
	vector<Background> backgrounds;

public:
	Game(RenderWindow* window);
	void update(float deltaTime);
	void render();
};


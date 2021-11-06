#include "Game.h"

int heart = maxHeart;
int score = 0;

Game::Game(RenderWindow* window) :
	space(nullptr, Vector2f(100, 100), Vector2f(200, 100)),
	space2(nullptr, Vector2f(320, 0), Vector2f(420, 0)),
	space3(nullptr, Vector2f(550, 100), Vector2f(650, 100))
{
	this->window = window;
	spaceTexture.loadFromFile("space.png");
	space.setTexture(&spaceTexture);
	space2.setTexture(&spaceTexture);
	space3.setTexture(&spaceTexture);
	font.loadFromFile("CourierPrime.ttf");
	scoreText.setFont(font);
	scoreText.setString("Score: " + to_string(score));
	scoreText.setCharacterSize(30);
	scoreText.setFillColor(Color::White);
	heartTexture.loadFromFile("heart.png");
	heartStartPos = Vector2f(0, 560);
	for (int i = 0; i < maxHeart; i++)
	{
		hearts[i].setTexture(heartTexture);
		hearts[i].setScale(Vector2f(0.1, 0.1));
		hearts[i].setPosition(heartStartPos + Vector2f(50 * i, 0));
	}
	backgroundTexture[0].loadFromFile("./backgrounds/background8.jpg");
	backgroundTexture[1].loadFromFile("./backgrounds/background8.jpg");
	backgroundTexture[2].loadFromFile("./backgrounds/background8.jpg");
	backgrounds.push_back(Background(&backgroundTexture[0], -60.f));
	backgrounds.push_back(Background(&backgroundTexture[1], -80.f));
	backgrounds.push_back(Background(&backgroundTexture[2], -60.f));
}

void Game::update(float deltaTime)
{
	Event ev;
	while (window->pollEvent(ev))
	{
		if (ev.type == Event::Closed)
			window->close();
	}
	player.update(deltaTime);
	space.update(deltaTime, player.bullet, &player.bulletStatus);
	space2.update(deltaTime, player.bullet, &player.bulletStatus);
	space3.update(deltaTime, player.bullet, &player.bulletStatus);
	player.checkHit(space.bullet, &space.bulletStatus);
	player.checkHit(space2.bullet, &space2.bulletStatus);
	player.checkHit(space3.bullet, &space3.bulletStatus);

	scoreText.setString("Score: " + to_string(score));

	if (heart == 0)
	{
		window->close(); // ����������ҧ���
	}

	for (Background& background : backgrounds)
		background.Update(deltaTime);
}

void Game::render()
{
	for (Background& background : backgrounds)
		background.Draw(*window);
	space.render(window);
	space2.render(window);
	space3.render(window);
	player.render(window);
	window->draw(scoreText);
	for (int i = 0; i < heart; i++)
	{
		window->draw(hearts[i]);
	}
}

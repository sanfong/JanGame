#include "Game.h"
#include "Menu.h"

int state = MenuState;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Game", Style::Titlebar | Style::Close);
    window.setVerticalSyncEnabled(true);
    srand(time(NULL));

    Clock clock;
    float deltaTime = 0;

    Game game(&window);
    Menu menu(&window);
   
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        if (state == MenuState)
        {
            menu.update();
        }
        else if (state == GameState)
        {
            game.update(deltaTime);
        }
        //          คนที่น่ารักคนนึง
        //               ↓
        // (OvO)/ ~~♥  (^ ^)
        window.clear();
        if (state == MenuState)
        {
            menu.draw();
        }
        else if (state == GameState)
        {
            game.render();
        }
        window.display();
    }
    return 0;
}
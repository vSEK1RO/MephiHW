#include <SFML/Graphics.hpp>
#include <cppl/arr>
#include <cppl/fields.hpp>

#include "../include/Ui.hpp"
#include "../include/Graph.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Lagrange Interpolation", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    Ui ui;
    sf::Thread uiThread(&Ui::initHandler, &ui);
    uiThread.launch();

    Graph graph(ui);
    sf::Thread graphThread(&Graph::initHandler, &graph);
    graphThread.launch();

    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                switch(event.key.code)
                {
                    case sf::Keyboard::Escape: window.close();
                    default: break;
                }
            }                
        }

        window.draw(ui);
        window.draw(graph);
        window.display();
    }

    uiThread.terminate();
    graphThread.terminate();

    return 0;
}
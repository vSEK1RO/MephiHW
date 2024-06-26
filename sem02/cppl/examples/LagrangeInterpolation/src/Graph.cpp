#include "../include/Graph.hpp"

#include <SFML/Graphics.hpp>

Graph::Graph(Ui &ui)
{
    this->ui = &ui;
    arr = new cppl::ArraySequence<cppl::LinearSpace2D<int>>(4);
}
void Graph::initHandler()
{
    while (true)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            delete arr;
            arr = new cppl::ArraySequence<cppl::LinearSpace2D<int>>(4);
            while (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            cppl::Vector2D<int> pos(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
            if (ui->getColor() == sf::Color::Red)
            {
                (*arr)[0].data->append(pos);
            }
            if (ui->getColor() == sf::Color::Green)
            {
                (*arr)[1].data->append(pos);
            }
            if (ui->getColor() == sf::Color::Yellow)
            {
                (*arr)[2].data->append(pos);
            }
            if (ui->getColor() == sf::Color::Blue)
            {
                (*arr)[3].data->append(pos);
            }
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
            }
        }
    }
}
void Graph::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::CircleShape bufferDot(10);
    bufferDot.setOutlineColor(sf::Color::White);
    sf::Color color;
    for (uint64_t i = 0; i < arr->getLenght(); i++)
    {
        switch (i)
        {
        case 0:
            color = sf::Color::Red; break;
        case 1:
            color = sf::Color::Green; break;
        case 2:
            color = sf::Color::Yellow; break;
        case 3:
            color = sf::Color::Blue; break;
        default:
            color = sf::Color::Red; break;
        }
        for (uint64_t j = 0; j < (*arr)[i].data->getLenght(); j++)
        {
            bufferDot.setPosition((*(*arr)[i].data)[j].x.data, (*(*arr)[i].data)[j].y.data);
            bufferDot.setFillColor(color);
            bufferDot.setOutlineThickness(0);
            target.draw(bufferDot);
        }
    }
}
Graph::~Graph()
{
    delete arr;
}

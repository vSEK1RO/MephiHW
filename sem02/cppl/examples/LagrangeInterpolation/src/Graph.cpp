#include "../include/Graph.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

Graph::Graph(Ui &ui)
{
    this->ui = &ui;
    arr = new cppl::ArraySequence<cppl::LinearSpace2D<double>>(4);
}
void Graph::initHandler()
{
    while (true)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            delete arr;
            arr = new cppl::ArraySequence<cppl::LinearSpace2D<double>>(4);
            while (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            cppl::Vector2D<double> pos(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
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
            target.draw(bufferDot);
        }
        if((*arr)[i].data->getLenght()>0)
        {
            cppl::Polynom<double> pol = (*arr)[i].lagrangePolynomial();
            sf::VertexArray lines(sf::LineStrip, 0);
            for(uint64_t j = 0; j < 1920; j++)
            {
                sf::Vector2f bufferVec(j,pol.calc(cppl::Field<double>(j)).data);
                lines.append(sf::Vertex(bufferVec,color));
            }
            target.draw(lines);
        }
    }
}
Graph::~Graph()
{
    delete arr;
}

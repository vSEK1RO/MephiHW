#include "../include/Ui.hpp"

#include <SFML/Graphics.hpp>

Ui::Ui()
{
    color = sf::Color::Red;
}
void Ui::initHandler()
{
    while (true)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            color = sf::Color::Red;
            while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {
            color = sf::Color::Green;
            while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        {
            color = sf::Color::Yellow;
            while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            {
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
        {
            color = sf::Color::Blue;
            while (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            {
            }
        }
    }
}
void Ui::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Text colorText;
    sf::Font font;
    font.loadFromFile("./assets/NotoSans.ttf");
    colorText.setString("Press 1,2,3,4 to change color, press lmb to put dot");
    colorText.setCharacterSize(40);
    colorText.setPosition(80, 10);
    colorText.setFillColor(sf::Color::White);
    colorText.setFont(font);
    colorText.setOutlineColor(sf::Color::Black);
    colorText.setOutlineThickness(5);
    sf::Text text;
    text.setString("R to reload");
    text.setCharacterSize(40);
    text.setPosition(1500, 10);
    text.setFillColor(sf::Color::White);
    text.setFont(font);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(5);
    sf::CircleShape currentColor(25);
    currentColor.setOutlineThickness(5);
    currentColor.setOutlineColor(sf::Color::White);
    currentColor.setFillColor(color);
    currentColor.setPosition(900, 10);
    target.draw(colorText);
    target.draw(text);
    target.draw(currentColor);
}
sf::Color Ui::getColor()
{
    return color;
}
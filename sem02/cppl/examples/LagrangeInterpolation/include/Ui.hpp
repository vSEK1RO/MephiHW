#ifndef UI_HPP
#define UI_HPP

#include <SFML/Graphics.hpp>

class Ui : public sf::Drawable
{
public:
    Ui();
    void initHandler();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    sf::Color getColor();

private:
    sf::Color color;
};

#endif
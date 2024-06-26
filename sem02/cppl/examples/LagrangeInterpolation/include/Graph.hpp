#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <cppl/linsp2d>

#include "Ui.hpp"

class Graph : public sf::Drawable
{
public:
    Graph(Ui &ui);
    void initHandler();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    ~Graph();
private:
    Ui *ui;
    cppl::ArraySequence<cppl::LinearSpace2D<int>> *arr;
};

#endif
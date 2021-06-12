/*
** MR PROJECT, 2021
** InFeCTION
** File description:
** Infection
*/

#include "Infection.hpp"

// Init game
Infection::Infection()
{
    this->window.create(sf::VideoMode(800, 600), "Infect Worms");
    window.setVerticalSyncEnabled(true);
}

Infection::~Infection()
{
}

void Infection::getEvents()
{
    sf::Event event;
        while (window.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Infection::run()
{
    while (window.isOpen())
    {
        this->getEvents();
    }
}

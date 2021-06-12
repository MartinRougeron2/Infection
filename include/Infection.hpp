/*
** EPITECH PROJECT, 2021
** InFeCTION
** File description:
** Infection
*/

#include "Entity.hpp"

#ifndef INFECTION_HPP_
#define INFECTION_HPP_

class Infection {
    public:
        Infection();
        ~Infection();
        void run();
        void getEvents();

    private:
        sf::Window window;
        std::vector<Engine::Entity> EntityArray;
};

#endif /* !INFECTION_HPP_ */

/*
** MR, 2021
** InFeCTION
** File description:
** Entity
*/

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

namespace Engine
{
    enum EntityType {BLOCK, DECORATION, PLAYER};
    enum PlayerType {WORM, EAGLE};

    class Entity {

        public:
            Entity(std::string texturePath, sf::Vector2f position = {0, 0}, sf::Vector2f Scale = {1, 1}, int type = 0);
            Entity(sf::Texture texture, sf::IntRect TileDimensions, sf::Vector2f position = {0, 0}, sf::Vector2f Scale = {1, 1}, int type = 0);
            Entity(Engine::Entity &other);
            ~Entity();

            sf::Texture texture;
            sf::Sprite sprite;
            sf::Vector2f pos;
            enum Engine::EntityType type; // Layer
            enum Engine::PlayerType PlayerType = WORM;
    };
} // namespace Engine

#endif /* !ENTITY_HPP_ */

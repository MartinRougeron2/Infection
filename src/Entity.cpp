/*
** MR PROJECT, 2021
** InFeCTION
** File description:
** Entity
*/

#include "Entity.hpp"

using namespace Engine;

Entity::Entity(std::string texturePath, sf::Vector2f position, sf::Vector2f Scale, int type)
{
    this->texture.loadFromFile(texturePath);
    this->sprite.setTexture(this->texture);
    this->pos = position;
    this->sprite.setScale(Scale);
    this->type = EntityType(type);
}

Entity::Entity(Engine::Entity &other)
{
    this->texture = other.texture;
    this->sprite = other.sprite;
    this->pos = other.pos;
    this->type = other.type;
    this->PlayerType = other.PlayerType;
}

// Load Tile
Entity::Entity(sf::Texture texture, sf::IntRect TileDimensions, sf::Vector2f position, sf::Vector2f Scale, int type)
{
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(TileDimensions);
    this->pos = position;
    this->sprite.setScale(Scale);
    this->type = EntityType(type);
}

Entity::~Entity()
{
}

#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include <stdexcept>
#include <string>

#include "color.hpp"
/**
 * @brief The class  representing a player.
 * 
 */
class Player
{
private:
/**
 * @brief His color and for his stars.
 * 
 */
    Color _color;

public:
/**
 * @brief Construct a new Player object.
 * 
 * @param color his assigned color.
 */
    Player(Color color) : _color(color){};
/**
 * @brief Get the Color object.
 * 
 * @return Color his color.
 */
    Color getColor() const { return _color; };
};

#endif // PLAYER_H

#ifndef PLACE_H
#define PLACE_H

#include "color.hpp"
/**
 * @brief Class representing a place on the game containing a star.
 * 
 */
class Place
{
private:
    bool _occupied = false;
    bool _canWin = false;
    Color _color = Color::EMPTY;
    Color _visibleColor = Color::EMPTY;

public:
/**
 * @brief Construct a new Place object
 * 
 */
    Place() = default;
/**
 * @brief Get the Color object
 * 
 * @return Color 
 */
    Color getColor()
    {
        return _color;
    }
    /**
     * @brief if a star is present on the place.
     * 
     * @return true if so
     * @return false otherwise
     */
    bool isStarPresent()
    {
        return _occupied;
    }
    /**
     * @brief if the star has not been eliminated.
     * 
     * @return true if not yet eliminated
     * @return false otherwise
     */
    bool isStarUp()
    {
        return _canWin;
    }
/**
 * @brief Set the Star Color object
 * 
 * @param color new color of the star
 * @return true if done properly
 * @return false otherwise
 */
    bool setStarColor(Color color)
    {
        if (isStarPresent())
        {
            return false;
        }
        _occupied = true;
        _canWin = true;
        _visibleColor = color;
        _color = color;
        return true;
    }
    /**
     * @brief Puts the star on the place to sleep. 
     * 
     * @return true if done properly
     * @return false otherwise or if there was no star or it was already eliminated.
     */
    bool nightStar()
    {
        if (isStarPresent() && _canWin)
        {
            _visibleColor = Color::STAR_NIGHT;
            return true;
        }
        return false;
    }
    /**
     * @brief loses the star on the place.
     * 
     * @return Color 
     */
    Color lostStar()
    {
        _canWin = false;
        _visibleColor = Color::STAR_DOWN;
        return _color;
    }
    /**
     * @brief Get the Color Visibility object
     * 
     * @return true if can be seen.
     * @return false  otherwise.
     */
    bool getColorVisibility()
    {
        return _canWin;
    }
    /**
     * @brief Get the color visibke to the user.
     * 
     * @return Color the said color.
     */
    Color getVisibleColor()
    {
        return _visibleColor;
    } /**
     * @brief Set the Empty object
     * 
     */
    void setEmpty()
    {
        _color = Color::EMPTY;
        _visibleColor = Color::EMPTY;
        _canWin = false;
        _occupied = false;
    }
};

#endif // PLACE_H

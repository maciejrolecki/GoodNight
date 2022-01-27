#ifndef COLOR_HPP
#define COLOR_HPP
/**
 * @brief The Color enum represents all of the possible Values for the Star in a game board.
 * STAR_BLACK is for a black star.
 * STAR_BLUE is for a blue star.
 * STAR_GREEN is for a green star.
 * STAR_PURPLE is for a purple star.
 * STAR_RED is for a red star.
 * STAR_NIGHT is for when the night has fallen.
 * STAR_DOWN is for when the star has lost
 * EMPTY is for when there is no star.
 */
enum class Color
{
    STAR_BLACK,
    STAR_BLUE,
    STAR_GREEN,
    STAR_PURPLE,
    STAR_RED,
    STAR_NIGHT,
    STAR_DOWN,
    EMPTY
};

#endif // COLOR_HPP

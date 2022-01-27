#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
/**
 * @brief Represents the current state of the game.
 * PREP is for when the game has not started yet.
 * PHASE1 is for when the game has started and the user have to place their stars.
 * PHASE2 is for when the user have to eliminate the stars from the game.
 * END is for when the game has finished and the user has to decide to play again or not.
 */
enum class GameState
{
    PREP,
    PHASE1,
    PHASE2,
    END
};
#endif //GAMESTATE_H

#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "place.hpp"
#include "array"

/**
 * @brief The Board class reprents the Board on which the game will be taking place.
 */
class Board
{
private:
    size_t _usedPlaces = 0; // number of places that are occupied by stars.
    size_t _starsToEliminate = 0; //number of stars that are placed and will be eliminated.
    const static size_t _totalStars = 15; //Total number of stars that can be placed.
    const static int _sizeBoard = 9; //Size of the board.
    const static int _sizeCheckpoint = 5;//Size of the board checkpoint
    Place _board[9][5]; //the board
/**
 * @brief Get the Remaining Stars To Eliminate object
 * 
 * @return size_t 
 */
    size_t getRemainingStarsToEliminate();
    /**
     * @brief Get the Color Visibility At Place object
     * 
     * @param checkpoint which checkpoint to check 
     * @param place which place on a checkpoint is to be checked
     * @return true if can be displayed
     * @return false otherwise
     */
    bool getColorVisibilityAtPlace(size_t checkpoint, size_t place);
    /**
     * @brief Verifies if a star  is present at any place in the checkpoint
     * 
     * @param checkpoint the forementioned checkpoint
     * @return true if empty
     * @return false otherwise
     */
    bool isCheckpointEmpty(size_t checkpoint);

public:
/**
 * @brief Construct a new Board object
 * 
 */
    Board();
/**
 * @brief Add a star to the board at a given position.
 * 
 * @param color a color to apply to the star
 * @param checkpoint which checkpoint 
 * @param place which place on a checkpoint is to be modified 
 * @return true if successful
 * @return false otherwise
 */
    bool addStarPos(Color color, size_t checkpoint, size_t place);
/**
 * @brief Get the Star object
 * 
 * @param checkpoint which checkpoint 
 * @param place which place on a checkpoint to grab
 * @return Place& a place where reside all information about a star
 */
    Place &getStar(size_t checkpoint, size_t place);
/**
 * @brief Get the Star Color object
 * 
 * @param checkpoint which checkpoint 
 * @param place which place on a checkpoint to grab
 * @return Color of the star that is on site if there is one
 */
    Color getStarColor(size_t checkpoint, size_t place);
/**
 * @brief Get the Visible Color object
 * 
 * @param checkpoint  which checkpoint 
 * @param place which place on a checkpoint to grab
 * @return Color  of the star that is displayed (in case of lost star)
 */
    Color getVisibleColor(size_t checkpoint, size_t place);
/**
 * @brief Verifies if a star is on site
 * 
 * @param checkpoint which checkpoint
 * @param place which place on a checkpoint to verify
 * @return true if there is a star on site
 * @return false otherwise
 */
    bool isStarPresent(size_t checkpoint, size_t place);
/**
 * @brief Lose a star on site if ther is any
 * 
 * @param checkpoint which checkpoint
 * @param place which place on a checkpoint to modify
 * @return Color the color of the lost star if there was one
 */
    Color lostStarAtPlace(size_t checkpoint, size_t place);
/**
 * @brief Puts all the stars to sleep
 * 
 */
    void nightAllStars();
/**
 * @brief Get the Winning Spot object
 * 
 * @param retur a pai representing the position of the winner, modified accordingly with the method.
 * @return true if ther is a winner
 * @return false otherwise
 */
    bool getWinningSpot(std::pair<size_t, size_t> &retur);
/**
 * @brief Verifies if all the stars where placed.
 * 
 * @return true if 15
 * @return false if less
 */
    bool checkAllOnBoard();
/**
 * @brief Verifies how many stars can become the winner of the game.
 * 
 * @return size_t the number of stars that are not lost yet.
 */
    size_t checkRemainingStars();
/**
 * @brief Destroy the Board object
 * 
 */
    ~Board() = default;
/**
 * @brief Converts the board into a string representation.
 * 
 * @return std::string the said string representation of the board.
 */
    std::string toString();
};

#endif // BOARD_H

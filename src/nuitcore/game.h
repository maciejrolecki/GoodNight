#ifndef GAME_H
#define GAME_H
#include <list>
#include <iostream>
#include "tools/observable.h"
#include "tools/random.hpp"
#include <stdbool.h>
#include "board.h"
#include "player.hpp"
#include "gameState.hpp"

/*src = https://refactoring.guru/fr/design-patterns/observer/cpp/example */

/**
 * @brief The game class
 */
class Game : public Observable
{
private:
    std::list<Observer *> _list_observers;
    std::vector<Player> _list_players;
    std::vector<Color> _NPCColors;
    Board *_board = new Board();
    GameState _state = (GameState)GameState::PREP;
    size_t _positionRose = 0;
    size_t _playerTurn = 0;

    void emplaceNPCStars();

public:
/**
 * @brief Construct a new Game object
 * 
 */
    Game();
    /**
     * @brief initialises the game attributes.
     * 
     * @param nbPlayes 
     */
    void initGame(int nbPlayes);
    /**
     * @brief Changes the state of the game.
     * 
     * @param state new state
     * @param one used if passign to PHASE1
     */
    void changeState(GameState state, size_t one = 0);
/**
 * @brief Get the Board object
 * 
 * @return Board* 
 */
    Board *getBoard();
    /**
     * @brief Get the Visible Color object
     * 
     * @param checkpoint where to check
     * @param place where to check
     * @return Color visible to the player.
     */
    Color getVisibleColor(size_t checkpoint, size_t place);
    /**
     * @brief Get the Star Color At Place object
     * 
     * @param checkpoint  where to check
     * @param place  where to check
     * @return Color of the star.
     */
    Color getStarColorAtPlace(size_t checkpoint, size_t place);
    /**
     * @brief Get the Rose location
     * 
     * @return size_t which checkpoint it is at.
     */
    size_t getRose();
/**
 * @brief action when a star is clicked
 * 
 * @param checkpoint  where to apply
 * @param place where to apply
 */
    void clickStar(size_t checkpoint, size_t place);
    /**
     * @brief 
     * 
     * @param checkpoint 
     * @param place 
     * @return true 
     * @return false 
     */
    bool isStarPresent(size_t checkpoint, size_t place);
    /**
     * @brief Adds a star to a board with the color of the current player.
     * 
     * @param place place where to add. Checpoint is indicated by the rose.
     */
    void addPlayerStar(size_t place);
    /**
     * @brief Adds a star to a board with a given color.
     * 
     * @param place place where to add. Checpoint is indicated by the rose.
     * @param color a given color of the star.
     * @return true if done properly.
     * @return false otherwise
     */
    bool addStar(size_t place, Color color);
    /**
     * @brief Verifies if all the stars were added successfully to the game board in order to move to PHASE2.
     * 
     * @return true if successful
     * @return false otherwise
     */
    bool checkAllOnBoard();
    /**
     * @brief Turns off the light for all of the stars.
     * 
     */
    void lightOff();
    /**
     * @brief Loses a star from the board.
     * 
     * @param checkpoint where to remove the star from the board.
     * @param place where to remove the star from thec checkpoint.
     */
    void lostStar(size_t checkpoint, size_t place);
    /**
     * @brief Get the Players object
     * 
     * @return std::vector<Player>& the list of players
     */
    std::vector<Player> &getPlayers();
    /**
     * @brief Get the Current Player object
     * 
     * @return Player& 
     */
    Player &getCurrentPlayer();
    /**
     * @brief Get the Current Player Color object
     * 
     * @return Color 
     */
    Color getCurrentPlayerColor();
    /**
     * @brief Get the Current State object
     * 
     * @return GameState 
     */
    GameState getCurrentState();
    /**
     * @brief Rolls the dice to indicate to the rose where to place itself.
     * 
     * @return unsigned whre the rose is.
     */
    unsigned rollDiceCheckpoint();
    /**
     * @brief Let's the next user play.
     * 
     */
    void nextPlayer();
    /**
     * @brief Checks if the winning color is not a player but an NPC
     * 
     * @param color 
     * @return true 
     * @return false 
     */
    bool checkIfNPC(Color color);
    /**
     * @brief Get the Winning Color object
     * 
     * @param ret 
     * @return Color 
     */
    Color getWinningColor(std::pair<size_t, size_t> ret);
    /**
     * @brief Get the Winning Place object
     * 
     * @param ret 
     * @return true 
     * @return false 
     */
    bool getWinningPlace(std::pair<size_t, size_t> &ret);

    virtual ~Game()
    {
    }

    /**
   * The subscription management methods.
   */
    void Attach(Observer *observer) override
    {
        _list_observers.push_back(observer);
    }
    void Detach(Observer *observer) override
    {
        _list_observers.remove(observer);
    }
    void Notify() override
    {
        std::list<Observer *>::iterator iterator = _list_observers.begin();
        while (iterator != _list_observers.end())
        {
            (*iterator)->Update();
            ++iterator;
        }
    }
};

#endif // GAME_H

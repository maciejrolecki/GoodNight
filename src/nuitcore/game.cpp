#include "game.h"

Game::Game()
{
    _NPCColors = {Color::STAR_RED, Color::STAR_GREEN, Color::STAR_BLUE, Color::STAR_BLACK, Color::STAR_PURPLE};
}

void Game::initGame(int nbPlayers)
{
    if (nbPlayers >= 1 && nbPlayers <= 5)
    {
        for (int i = 0; i < nbPlayers; i++)
        {
            _list_players.emplace_back(Player(_NPCColors.back()));
            _NPCColors.pop_back();
        }
    }
    else
        throw std::invalid_argument("Invalid number of players.");

    emplaceNPCStars();
}

Board *Game::getBoard()
{
    return _board;
}

Color Game::getVisibleColor(size_t checkpoint, size_t place)
{
    return getBoard()->getVisibleColor(checkpoint, place);
}

Color Game::getStarColorAtPlace(size_t checkpoint, size_t place)
{
    return getBoard()->getStarColor(checkpoint, place);
}
size_t Game::getRose()
{
    return _positionRose;
}

bool Game::isStarPresent(size_t checkpoint, size_t place)
{
    return getBoard()->isStarPresent(checkpoint, place);
}
void Game::clickStar(size_t checkpoint, size_t place)
{
    if (_state == (GameState)GameState::PHASE1)
    {
        getBoard()->addStarPos(getCurrentPlayerColor(), checkpoint, place);

        rollDiceCheckpoint();
        nextPlayer();
        if (checkAllOnBoard())
            changeState((GameState)GameState::PHASE2);
    }
    else if (_state == (GameState)GameState::PHASE2)
    {
        lostStar(checkpoint, place);
        nextPlayer();
        if (getBoard()->checkRemainingStars() == 1)
            changeState((GameState)GameState::END);
    }
    if (_state == (GameState)GameState::END)
    {
    }
    Notify();
}
void Game::addPlayerStar(size_t place)
{
    addStar(place, getCurrentPlayerColor());
    nextPlayer();
}

bool Game::addStar(size_t place, Color color)
{
    if (!isStarPresent(_positionRose, place))
        return _board->getStar(_positionRose, place).setStarColor(color);
    return false;
}

bool Game::checkAllOnBoard()
{
    return _board->checkAllOnBoard();
}

void Game::lightOff()
{
    _board->nightAllStars();
}

void Game::lostStar(size_t checkpoint, size_t place)
{
    if (_board->getVisibleColor(checkpoint, place) != Color::STAR_DOWN)
    {
        _board->lostStarAtPlace(checkpoint, place);
        if (_board->lostStarAtPlace(checkpoint, place) != Color::EMPTY)
        {
            Notify();
            nextPlayer();
        }
        else
            throw std::invalid_argument("Impossible to lose star because none present");
    }
}

Player &Game::getCurrentPlayer()
{
    return _list_players.at(_playerTurn);
}

Color Game::getCurrentPlayerColor()
{
    return getCurrentPlayer().getColor();
}
GameState Game::getCurrentState()
{
    return (GameState)_state;
}
unsigned Game::rollDiceCheckpoint()
{
    int dice = nvs::random_value(1, 3);
    _positionRose += dice;
    if (_positionRose > 8)
        _positionRose -= 9;
    return _positionRose;
}

void Game::nextPlayer()
{
    _playerTurn++;
    if (_playerTurn == _list_players.size())
        _playerTurn = 0;
}

void Game::emplaceNPCStars()
{
    nvs::randomize();
    if (_NPCColors.size() == 0)
        ;
    else
        for (int i = 0; i < 3; i++)
            for (Color color : _NPCColors)
            {
                rollDiceCheckpoint();
                int random = nvs::random_value(0, 4);
                while (!_board->addStarPos(color, _positionRose, random))
                {
                    random = nvs::random_value(0, 4);
                }
            }
    rollDiceCheckpoint();
}

void Game::changeState(GameState state, size_t one)
{
    switch (state)
    {
    case (GameState)GameState::PHASE1:
    {
        _state = state;
        if (one == (size_t)0)
            throw std::invalid_argument("Invalid number of starting players.");
        initGame(one);
        break;
    }
    case (GameState)GameState::PHASE2:
    {
        _state = state;
        lightOff();
        break;
    }
    case (GameState)GameState::END:
    {
        _state = state;
        break;
    }
    default:
        break;
    }
}
bool Game::checkIfNPC(Color color)
{
    for (Color colorNPC : _NPCColors)
    {
        if (colorNPC == color)
            return true;
    }
    return false;
}

Color Game::getWinningColor(std::pair<size_t, size_t> ret)
{
    _board->getWinningSpot(ret);
    return getBoard()->getStarColor(ret.first, ret.second);
}

bool Game::getWinningPlace(std::pair<size_t, size_t> &ret)
{
    return getBoard()->getWinningSpot(ret);
}

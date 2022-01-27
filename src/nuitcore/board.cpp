#include "board.h"

Board::Board()
{
    for (size_t i = 0; i < 9; i++)
        for (size_t j = 0; j < 5; j++)
            _board[i][j] = Place();
}

Place &Board::getStar(size_t checkpoint, size_t place)
{
    return _board[checkpoint][place];
}

bool Board::addStarPos(Color color, size_t checkpoint, size_t place)
{
    if (!isStarPresent(checkpoint, place))
    {
        _usedPlaces++;
        _starsToEliminate++;
        _board[checkpoint][place].setStarColor(color);
        return true;
    }
    return false;
}

bool Board::isStarPresent(size_t checkpoint, size_t place)
{
    return getStar(checkpoint, place).isStarPresent();
}

Color Board::lostStarAtPlace(size_t checkpoint, size_t place)
{
    if (isStarPresent(checkpoint, place))
    {
        _starsToEliminate--;
        return getStar(checkpoint, place).lostStar();
    }
    return Color::EMPTY;
}

Color Board::getStarColor(size_t checkpoint, size_t place)
{
    return getStar(checkpoint, place).getColor();
}

Color Board::getVisibleColor(size_t checkpoint, size_t place)
{
    return getStar(checkpoint, place).getVisibleColor();
}

bool Board::isCheckpointEmpty(size_t checkpoint)
{
    for (unsigned place = 0; place < _sizeCheckpoint; place++)
    {
        if (isStarPresent(checkpoint, place))
        {
            return false;
        }
    }
    return true;
}
bool Board::checkAllOnBoard()
{
    size_t check = 0;
    for (size_t checkpoint = 0; checkpoint < _sizeBoard; checkpoint++)
    {
        for (size_t place = 0; place < _sizeCheckpoint; place++)
        {
            if (isStarPresent(checkpoint, place))
            {
                check++;
            }
        }
    }
    return check == _totalStars;
}
void Board::nightAllStars()
{
    for (size_t checkpoint = 0; checkpoint < _sizeBoard; checkpoint++)
    {
        for (size_t place = 0; place < _sizeCheckpoint; place++)
        {
            if (isStarPresent(checkpoint, place))
            {
                getStar(checkpoint, place).nightStar();
            }
        }
    }
}

bool Board::getColorVisibilityAtPlace(size_t checkpoint, size_t place)
{
    return getStar(checkpoint, place).getColorVisibility();
}

size_t Board::getRemainingStarsToEliminate()
{
    return _starsToEliminate;
}

size_t Board::checkRemainingStars()
{
    size_t check = 0;
    for (size_t checkpoint = 0; checkpoint < _sizeBoard; checkpoint++)
    {
        for (size_t place = 0; place < _sizeCheckpoint; place++)
        {
            if (getStar(checkpoint, place).getColorVisibility())
            {
                check++;
            }
        }
    }
    _starsToEliminate = check;
    return check;
}

bool Board::getWinningSpot(std::pair<size_t, size_t> &retur)
{
    if (getRemainingStarsToEliminate() == 1 && checkRemainingStars() == 1)
    {
        for (size_t checkpoint = 0; checkpoint < _sizeBoard; checkpoint++)
        {
            if (!isCheckpointEmpty(checkpoint))
            {
                for (size_t place = 0; place < _sizeCheckpoint; place++)
                {
                    if (isStarPresent(checkpoint, place) && getStar(checkpoint, place).isStarUp())
                    {
                        retur = std::make_pair(checkpoint, place);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

std::string Board::toString()
{
    std::string result = "";

    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            switch (getVisibleColor(x, y))
            {
            case Color::STAR_BLACK:
            {
                result.append("b ");
                break;
            }
            case Color::STAR_BLUE:
            {
                result.append("b ");
                break;
            }
            case Color::STAR_GREEN:
            {
                result.append("g ");
                break;
            }
            case Color::STAR_PURPLE:
            {
                result.append("p ");
                break;
            }
            case Color::STAR_RED:
            {
                result.append("r ");
                break;
            }
            case Color::STAR_NIGHT:
            {
                result.append("n ");
                break;
            }
            case Color::STAR_DOWN:
            {
                result.append("l ");
                break;
            }
            case Color::EMPTY:
            {
                result.append(". ");
                break;
            }
            }
        }
        result.append("\n\n");
    }
    return result;
}

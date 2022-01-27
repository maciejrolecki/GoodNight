#include "gameWindow.h"

#include <QMessageBox>

#include "star.h"
#include "endingDialog.h"

/**
 * @brief Graphical User Interface.
 */
GameWindow::GameWindow(Game &game, int _nbPlayers, QWidget *parent, double rad) : _nbPlayers((size_t)_nbPlayers),
                                                                                  parent(parent),
                                                                                  rad(rad),
                                                                                  _game(game),
                                                                                  _board(game.getBoard())
{
    this->_game.Attach(this);

    startGame();
    //encapsulation des différentes scénes
    QGraphicsView *view = new QGraphicsView(foreground);
    updateDisplay();
    //paramètrage de la scene
    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::TextAntialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::NoDrag);

    //ajout des boutons
    resize(rad * 22.5, rad * 18);
    view->update();
    this->setCentralWidget(view);
}

void GameWindow::startGame()
{
    _game.changeState((GameState)GameState::PHASE1, _nbPlayers);
}

void GameWindow::displayPlayerTurn()
{
    QFont fontMoves = QFont(); //font for marking
    fontMoves.setPointSize(rad / 3);
    double finalX = (double)(1.5 * rad * 8.125);
    double finalY = 5 * 1.5 * rad;
    playerTurnText = getPlayerName(_game.getCurrentPlayerColor()) + "'s turn to play";
    playerTurnItem = new QGraphicsTextItem();
    playerTurnItem->setPlainText(playerTurnText);
    playerTurnItem->setPos(finalX, finalY);
    playerTurnItem->setFont(fontMoves);
    foreground->addItem(playerTurnItem);
}
void GameWindow::displayIndications(QString indicationText)
{
    QFont fontMoves = QFont(); //font for marking
    fontMoves.setPointSize(rad / 3);
    double finalX = (double)(1.5 * rad * 7);
    double finalY = 3 * 1.5 * rad;
    communication = new QGraphicsTextItem();
    communication->setPlainText(indicationText);
    communication->setPos(finalX, finalY);
    communication->setFont(fontMoves);
    foreground->addItem(communication);
}

Qt::GlobalColor GameWindow::getQtColor(Color color)
{
    switch (color)
    {
    case Color::EMPTY:
    {
        return Qt::gray;
        break;
    }
    case Color::STAR_BLACK:
    {
        return Qt::black;
        break;
    }
    case Color::STAR_BLUE:
    {
        return Qt::blue;
        break;
    }
    case Color::STAR_GREEN:
    {
        return Qt::green;
        break;
    }
    case Color::STAR_RED:
    {
        return Qt::red;
        break;
    }
    case Color::STAR_PURPLE:
    {
        return Qt::darkMagenta;
        break;
    }
    case Color::STAR_NIGHT:
    {
        return Qt::darkGray;
        break;
    }
    default:
        return Qt::gray;
    }
}
QString GameWindow::getPlayerName(Color color)
{
    switch (color)
    {
    case Color::STAR_BLACK:
        return "Black";
    case Color::STAR_BLUE:
        return "Blue";
    case Color::STAR_GREEN:
        return "Green";
    case Color::STAR_RED:
        return "Red";
    case Color::STAR_PURPLE:
        return "Purple";
    default:
        return "";
    }
}

void GameWindow::displayPhase1(QGraphicsScene *scene)
{
    for (size_t i = 0; i < 9; i++)
        for (size_t j = 0; j < 5; j++)
        {
            Qt::GlobalColor color = getQtColor(_board->getStarColor(i, j));
            if (_game.isStarPresent(i, j))
                scene->addItem(new Star(color, false, i, j, this, 50));
            else if (_game.getRose() == i)
            {
                Star *ball = new Star(Qt::gray, true, i, j, this, 50);
                scene->addItem(ball);
            }
            else
                scene->addItem(new Star(Qt::gray, false, i, j, this, 50));
        }
    displayRose();
    indicationText = "Click on one of the grayed out circles\nto place your color";
    displayPlayerTurn();
    displayIndications(indicationText);
}
void GameWindow::displayPhase2(QGraphicsScene *scene)
{
    for (size_t i = 0; i < 9; i++)
        for (size_t j = 0; j < 5; j++)
        {
            Qt::GlobalColor color = getQtColor(_game.getBoard()->getVisibleColor(i, j));
            if (color == Qt::darkGray)
                scene->addItem(new Star(color, true, i, j, this, 50));
        }
    QString indicationText = "Click on one of the gray circles\nto eleminate it ! muahaha";
    displayPlayerTurn();
    displayIndications(indicationText);
}
void GameWindow::endDisplay()
{
    std::pair<size_t, size_t> retur;
    Color color = _game.getWinningColor(retur);
    if (_game.checkIfNPC(color))
    {
        indicationText = "None of the players won,\n it was an NPC";
    }
    else
        indicationText = getPlayerName(color) + " won";
    Qt::GlobalColor colorQt = getQtColor(color);
    EndingDialog *endScreen = new EndingDialog(indicationText, colorQt);
    endScreen->show();
    close();
}
void GameWindow::displayRose()
{
    foreground->addItem(new Star(Qt::cyan, false, _game.getRose(), 5, this, 50));
}

void GameWindow::clickPlace(size_t checkpoint, size_t place)
{
    _game.clickStar(checkpoint, place);
}
void GameWindow::deleteForeground()
{
    foreground->clear();
}

void GameWindow::updateDisplay()
{
    deleteForeground();
    GameState state = (GameState)_game.getCurrentState();
    if (state == (GameState)GameState::PHASE1)
    {
        displayPhase1(foreground);
    }
    else if (state == (GameState)GameState::PHASE2)
    {
        displayPhase2(foreground);
    }
    else if (state == (GameState)GameState::END)
    {
        endDisplay();
    }
    update();
}

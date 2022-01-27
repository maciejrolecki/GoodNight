#ifndef STAR_H
#define STAR_H

#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QPainter>
#include "gameWindow.h"

class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QGraphicsSceneHoverEvent;
class QGraphicsSceneMouseEvent;

/**
 * @brief Star represents a Star in the game but as a graphic element in the GUI.
 */
class Star : public QGraphicsPolygonItem
{
    static const double zValMax; //z-val of selected items
    double zval;                 //z-val at instanciation
protected:
    point<size_t> pos; //Star radius, coordinate (x,y) of center
    size_t rad;        //size of the Star
    Qt::GlobalColor colorPaint;
    bool _available;
    GameWindow *_gui = nullptr;

public:
/**
 * @brief Construct a new Star object
 * 
 * @param colorPaint color in which it is drawn
 * @param _available Whether the Star can be clicked.
 * @param checkpoint 
 * @param place 
 * @param _gui The Window in which the Star is drawn
 * @param rad Reference size that is used for the placement of the widgets and items.
 */
    Star(Qt::GlobalColor colorPaint,
         bool _available,
         size_t checkpoint,
         size_t place,
         GameWindow *_gui = nullptr,
         size_t rad = 50);
/**
 * @brief Serves to paint the star
 * 
 * @param painter Who does it, the QPainter object
 * @param option never used idk
 * @param widget never used idk
 */
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    point<size_t> getPos();

protected:
/**
 * @brief Action that will be taken if the Star is clicked. Applied only if _available is true.
 * 
 * @param event 
 */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};
#endif // STAR_H

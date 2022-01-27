#include "star.h"

double const Star::zValMax = 10000; //arbitrary

Star::Star(Qt::GlobalColor colorPaint,
           bool available,
           size_t checkpoint,
           size_t place,
           GameWindow *_gui,
           size_t rad)
    : QGraphicsPolygonItem(nullptr),
      pos(make_point(checkpoint, place)),
      rad(rad),
      colorPaint(colorPaint),
      _available(available),
      _gui(_gui)
{
    zval = zValue();
    static const double piOver6 = atan(1) * 3 / 6;

    //Paramètres utiles au positionnement et aux dessins
    double radCell = rad;
    double radBall = rad * 3 / 5;

    point<double> final = cartesianForGoodNight(pos, radCell);
    QPolygonF polygon;
    auto &&corners = orbit(final, 180, radBall, piOver6);
    for (auto &p : corners)
        polygon << QPointF(p.first, p.second);
    setPolygon(polygon);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void Star::paint(QPainter *painter,
                 const QStyleOptionGraphicsItem *option,
                 QWidget *widget)
{

    QBrush brush;
    QPen pen;
    if (_available)
        pen = QPen(Qt::red, 2);
    else
        pen = QPen(Qt::black, 2);
    painter->setPen(pen);
    brush.setColor(colorPaint);
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawPolygon(polygon());
}

void Star::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (_available)
    {
        _gui->clickPlace(pos.first, pos.second);
    }
}

#pragma GCC diagnostic pop

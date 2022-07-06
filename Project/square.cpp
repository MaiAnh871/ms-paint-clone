#include <math.h>
#include <QDebug>
#include "square.h"

namespace Paint
{
Square::Square (const QPoint &topLeft, int penWidth, const QColor &penColor) :
    Shape (penWidth, penColor), r (topLeft, topLeft)
{
}

void Square::doDraw (QPainter &painter)
{
    if (!r.isNull())
    {
        painter.drawRect (r.normalized());
    }
}

QRect Square::doRect() const
{
    return r.normalized ();
}

void Square::doUpdate (const QPoint &toPoint)
{
    qDebug() << "doUpdate";
    float topLeftx = r.topLeft().x();
    float topLefty = r.topLeft().y();
    float edge = (toPoint.y() - topLefty);
    QPoint bottomRight (topLeftx + edge, toPoint.y());
    r.setBottomRight (bottomRight);
}

void Square::setSize ()
{
    edge = abs (r.topLeft().y() - r.bottomRight().y());
}

void Square::setPos()
{
    pos_x = abs (r.topLeft().x() + r.bottomRight().x()) / 2;
    pos_y = abs (r.topLeft().y() + r.bottomRight().y()) / 2;
}

float Square::calArea()
{
    return edge * edge;
}

float Square::calDistance()
{
    return sqrt (pos_x * pos_x + pos_y * pos_y);
}

void Square::printInfo()
{
    qDebug() << "This is a Square!" << endl;
    qDebug() << "Edge of this shape: " << edge << endl;
    qDebug() << "Area of this shape: " << calArea() << endl;
    qDebug() << "Position of this shape: x = " << pos_x << " y = " << pos_y << endl;
    qDebug() << "Distance of this shape: " << calDistance();
}

std::unique_ptr<Shape> createSquare (const QPoint &topLeft, int penWidth, const QColor& penColor)
{
    return std::unique_ptr<Shape> (new Square(topLeft, penWidth, penColor));
}


} // namespace Paint

#include <math.h>
#include <QDebug>
#include "shape.h"
#include "rectangle.h"

namespace Paint
{

Rectangle::Rectangle (const QPoint &topLeft, int penWidth, const QColor &penColor) :
    Shape(penWidth, penColor), r(topLeft, topLeft)
{
}

void Rectangle::doDraw(QPainter &painter)
{
    if (!r.isNull())
    {
        painter.drawRect (r.normalized());
    }
}

QRect Rectangle::doRect() const
{
    return r.normalized();
}

void Rectangle::doUpdate (const QPoint &toPoint)
{
    r.setBottomRight (toPoint);
}

void Rectangle::setPos()
{
    pos_x = abs (r.topLeft().x() + r.bottomRight().x()) / 2;
    pos_y = abs (r.topLeft().y() + r.bottomRight().y()) / 2;
}

void Rectangle::setSize ()
{
    length = abs (r.topLeft().x() - r.bottomRight().x());
    width = abs (r.topLeft().y() - r.bottomRight().y());
}

float Rectangle::calArea()
{
    return length * width;
}

float Rectangle::calDistance()
{
    return sqrt (pos_x * pos_x + pos_y * pos_y);
}

void Rectangle::printInfo()
{
    qDebug() << "This is a rectangle!" << endl;
    qDebug() << "Length of this shape: " << length << endl;
    qDebug() << "Width of this shape: " << width << endl;
    qDebug() << "Area of this shape: " << calArea() << endl;
    qDebug() << "Position of this shape: x = " << pos_x << " y = " << pos_y << endl;
    qDebug() << "Distance of this shape: " << calDistance();
}

std::unique_ptr<Shape> createRectangle (const QPoint &topLeft, int penWidth, const QColor& penColor)
{
    return std::unique_ptr<Shape>(new Rectangle(topLeft, penWidth, penColor));
}
} // namespace Paint

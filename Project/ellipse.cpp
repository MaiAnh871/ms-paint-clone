#include <math.h>
#include <QDebug>
#include "ellipse.h"

namespace Paint
{

Ellipse::Ellipse (const QPoint &topLeft, int penWidth, const QColor &penColor) :
    Shape (penWidth, penColor), r (topLeft, topLeft)
{
}

void Ellipse::doDraw (QPainter &painter)
{
    if (!r.isNull())
    {
        qDebug() << "doDraw";
        painter.drawEllipse (r.normalized());
    }
}

QRect Ellipse::doRect() const
{
    qDebug() << "doRect";
    return r.normalized();
}

void Ellipse::doUpdate (const QPoint &toPoint)
{
    r.setBottomRight (toPoint);
}

void Ellipse::setPos()
{
    pos_x = abs (r.topLeft().x() + r.bottomRight().x()) / 2;
    pos_y = abs (r.topLeft().y() + r.bottomRight().y()) / 2;
}

void Ellipse::setSize ()
{
    major = abs (r.topLeft().x() - r.bottomRight().x()) / 2;
    minor = abs (r.topLeft().y() - r.bottomRight().y()) / 2;
}

float Ellipse::calArea()
{
    return major * minor * 3.14;
}

float Ellipse::calDistance()
{
    return sqrt (pos_x * pos_x + pos_y * pos_y);
}

void Ellipse::printInfo()
{
    qDebug() << "This is a Ellipse!" << endl;
    qDebug() << "Major of this shape: " << major << endl;
    qDebug() << "Minor of this shape: " << minor << endl;
    qDebug() << "Area of this shape: " << calArea() << endl;
    qDebug() << "Position of this shape: x = " << pos_x << " y = " << pos_y << endl;
    qDebug() << "Distance of this shape: " << calDistance();
}

std::unique_ptr<Shape> createEllipse (const QPoint &topLeft, int penWidth, const QColor& penColor)
{
    return std::unique_ptr<Shape> (new Ellipse (topLeft, penWidth, penColor));
}


} // namespace Paint

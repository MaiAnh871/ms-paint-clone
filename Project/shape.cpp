#include "shape.h"
#include <QDebug>

namespace Paint
{

Shape::Shape (int penWidth, const QColor& penColor) :
    penWidth (penWidth), penColor(penColor)
{
}

Shape::~Shape()
{
}

void Shape::draw (QPainter &painter)
{
    // Construct prevPen as the painter's current pen
    const QPen prevPen = painter.pen();

    // Set the painter's pen to be the given pen
    painter.setPen (QPen (penColor, penWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    // Draw with the defined painter, like drawEllipse/ drawRectangle,...
    doDraw (painter);

    // Set the painter's pen to be the given prevPen
    painter.setPen (prevPen);
}

QRect Shape::rect() const
{
    // Consider pen's width and make sure the outline is included in the
    // returned rectangle.
    const int rad = penWidth / 2 + 2;
    qDebug() << "Shape::rect()";
    return doRect().adjusted (-rad, -rad, +rad, +rad);
}

void Shape::update (const QPoint &toPoint)
{
    qDebug() << "Shape::update" ;
    doUpdate (toPoint);
}

void Shape::setPos ()
{
}

void Shape::setSize ()
{
};

float Shape::calDistance()
{
    return 0;
}

float Shape::calArea()
{
    return 0;
}

void Shape::printInfo()
{
}
} // namespace Paint

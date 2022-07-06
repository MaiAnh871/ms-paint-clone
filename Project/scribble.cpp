#include "scribble.h"

namespace Paint
{
Scribble::Scribble (const QPoint &topLeft, int penWidth, const QColor &penColor) :
    Shape (penWidth, penColor)
{
    // Create a point at topLeft
    update (topLeft);
}

void Scribble::doDraw (QPainter &painter)
{
    // Draws the polyline defined by the given points using the current pen.
    painter.drawPolyline (poly);
}

QRect Scribble::doRect() const
{
    // Returns the bounding rectangle of the polygon, or QRect(0, 0, 0, 0) if the polygon is empty.
    return poly.boundingRect();
}

void Scribble::doUpdate (const QPoint &toPoint)
{
    // Update to toPoint
    poly << toPoint;
}

std::unique_ptr<Shape> createScribble (const QPoint &topLeft, int penWidth, const QColor& penColor)
{
    return std::unique_ptr<Shape >(new Scribble (topLeft, penWidth, penColor));
}
} // namespace Paint

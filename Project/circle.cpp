#include <math.h>
#include "circle.h"
#include <QDebug>

namespace Paint
{

Circle::Circle (const QPoint &topLeft, int penWidth, const QColor &penColor) :
    Shape (penWidth, penColor), r (topLeft, topLeft)
{
    /*
     * Define a Circle, Shape and r
     */
}

void Circle::doDraw (QPainter &painter)
{
    if (!r.isNull())
    {
        // Draw Ellipse with a normalized r
        painter.drawEllipse (r.normalized());
    }
}

QRect Circle::doRect() const
{
    // Normalize a rectangle
    return r.normalized();
}

void Circle::doUpdate (const QPoint &toPoint)
{
    // Edit point to draw a circle
    qDebug() << "doUpdate";
    float topLeftx = r.topLeft().x();
    float topLefty = r.topLeft().y();
    float edge = (toPoint.y() - topLefty);
    QPoint bottomRight (topLeftx + edge, toPoint.y());
    r.setBottomRight (bottomRight);
}

void Circle::setPos()
{
    pos_x = abs (r.topLeft().x() + r.bottomRight().x()) / 2;
    pos_y = abs (r.topLeft().y() + r.bottomRight().y()) / 2;
}

void Circle::setSize()
{
    radius = abs (r.topLeft().x() - r.bottomRight().x()) / 2;
}

float Circle::calArea()
{
    return 3.14 * radius * radius;
}

float Circle::calDistance()
{
    return sqrt (pos_x * pos_x + pos_y * pos_y);
}

void Circle::printInfo()
{
    qDebug() << "This is a Circle!" << endl;
    qDebug() << "Radius of this shape: " << radius << endl;
    qDebug() << "Area of this shape: " << calArea() << endl;
    qDebug() << "Position of this shape: x = " << pos_x << " y = " << pos_y << endl;
    qDebug() << "Distance of this shape: " << calDistance();
}

// Factory shape
std::unique_ptr<Shape> createCircle (const QPoint &topLeft, int penWidth, const QColor& penColor)
{
    return std::unique_ptr<Shape> (new Circle (topLeft, penWidth, penColor));
}
} // namespace Paint

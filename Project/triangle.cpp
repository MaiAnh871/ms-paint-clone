#include <math.h>
#include <QDebug>
#include "shape.h"
#include "triangle.h"

namespace Paint
{

Triangle::Triangle (const QPoint &topLeft, int penWidth, const QColor &penColor) :
    Shape(penWidth, penColor), r(topLeft, topLeft)
{
    update (topLeft);
}

void Triangle::doDraw(QPainter &painter)
{
    painter.drawPolygon (poly);
}

QRect Triangle::doRect() const
{
    return r.normalized();
}

void Triangle::doUpdate (const QPoint &toPoint)
{
    r.setBottomRight (toPoint);
    QPoint *points = new QPoint[3];
    points[0] = QPoint (r.topLeft().x(), toPoint.y());
    points[1] = QPoint (((r.topLeft().x() + toPoint.x()) / 2), r.topLeft().y());
    points[2] = QPoint (toPoint);
    poly << points[0] << points[1] << points[2];
}

void Triangle::setPos()
{
    pos_x = abs (r.topLeft().x() + r.bottomRight().x()) / 2;
    pos_y = abs (r.topLeft().y() + r.bottomRight().y()) / 2;
}

void Triangle::setSize()
{
    bottom = abs (r.topLeft().x() - r.bottomRight().x());
    height = abs (r.topLeft().y() - r.bottomRight().y());
}

float Triangle::calArea()
{
    return 1/2 * bottom * height;
}

float Triangle::calDistance()
{
    return sqrt (pos_x * pos_x + pos_y * pos_y);
}

void Triangle::printInfo()
{
    qDebug() << "This is a Triangle!" << endl;
    qDebug() << "Bottom of this shape: " << bottom << endl;
    qDebug() << "Height of this shape: " << height << endl;
    qDebug() << "Area of this shape: " << calArea() << endl;
    qDebug() << "Position of this shape: x = " << pos_x << " y = " << pos_y << endl;
    qDebug() << "Distance of this shape: " << calDistance();
}

std::unique_ptr<Shape> createTriangle (const QPoint &topLeft, int penWidth, const QColor& penColor)
{
    return std::unique_ptr<Shape> (new Triangle (topLeft, penWidth, penColor));
}
} // namespace Paint

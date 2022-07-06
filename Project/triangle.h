#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

namespace Paint
{

class Triangle : public Shape
{
public:
    explicit Triangle (const QPoint &topLeft, int penWidth, const QColor& penColor);

protected:
    void doDraw (QPainter &painter) override;

    QRect doRect() const override;

    void doUpdate (const QPoint &toPoint) override;

public:
    void setSize() override;

    float calArea() override;

    void setPos() override;

    float calDistance() override;

    void printInfo() override;

private:
    QPolygon poly;
    QRect r;
    float height, bottom;
};
} // namespace Paint

#endif // TRIANGLE_H

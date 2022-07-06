#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace Paint
{

class Rectangle : public Shape
{
public:
    explicit Rectangle (const QPoint &topLeft, int penWidth, const QColor& penColor);

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
    QRect r;
    float length, width;
};
} // namespace Paint

#endif // RECTANGLE_H

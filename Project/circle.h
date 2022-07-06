#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

namespace Paint
{

class Circle : public Shape
{
public:
    explicit Circle (const QPoint &topLeft, int penWidth, const QColor& penColor);

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
    float radius;
};
} // namespace Paint

#endif // CIRCLE_H

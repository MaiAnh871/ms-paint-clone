#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"

namespace Paint
{

class Ellipse : public Shape
{
public:
    explicit Ellipse (const QPoint &topLeft, int penWidth, const QColor& penColor);

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
    float major, minor;
};
} // namespace Paint

#endif // ELLIPSE_H

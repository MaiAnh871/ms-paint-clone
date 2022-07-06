#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

namespace Paint
{

class Square : public Shape
{
public:
    explicit Square (const QPoint &topLeft, int penWidth, const QColor& penColor);

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
    float edge;
};
} // namespace Paint

#endif // SQUARE_H

#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include "shape.h"
#include <QPolygon>

namespace Paint
{
class Scribble : public Shape
{
public:
    explicit Scribble (const QPoint &topLeft, int penWidth, const QColor& penColor);

protected:
    virtual void doDraw (QPainter &painter) override;

    virtual QRect doRect() const override;

    virtual void doUpdate (const QPoint &toPoint) override;
private:
    // The QPolygon class provides a vector of points using integer precision
    QPolygon poly;
};
} // namespace Paint
#endif // SCRIBBLE_H

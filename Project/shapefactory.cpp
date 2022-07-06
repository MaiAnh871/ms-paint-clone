#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include <QPoint>
#include "shape.h"
#include "shapefactory.h"
#include "rectangle.h"

namespace Paint
{

class ShapeFactory
{
public:
    ShapeFactory(){};
    ~ShapeFactory(){};

    static std::unique_ptr<Shape> createShape (int shapeType,
                                               const QPoint &topLeft,
                                               int penWidth,
                                               const QColor& penColor)
    {
        switch (shapeType)
        {
        case 1:
            return 0;
            break;

        case 4:
            return std::unique_ptr<Shape>(new Rectangle(topLeft, penWidth, penColor));
            break;

        case 2:
            return 0;
            break;

        case 3:
            return 0;
            break;

        default:
            return NULL;
        }
    }
};
} // namespace Paint
#endif // SHAPEFACTORY_H

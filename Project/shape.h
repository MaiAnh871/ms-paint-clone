#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <memory>

namespace Paint
{

class ScribbleArea;

/**
 * @brief The Shape base class representing all shapes drawn on the scribble area.
 */
class Shape
{
public:
    /**
     * @brief Constructor function of shape
     * @param penWidth
     * @param penColor
     */
    Shape (int penWidth, const QColor& penColor);
    virtual ~Shape();

    /**
     * @brief Draw the shape using a painter.
     * @param painter The painter to use for drawing.
     */
    void draw (QPainter &painter);

    /**
     * @brief Get the rectangle containing the shape.
     * @return The shape's rectangle.
     */
    QRect rect() const;

    /**
     * @brief Update the shape while "stretching" (drawing) it
     * @param toPoint The last recorded point where the shape should be extended to.
     */
    void update (const QPoint &toPoint);

    /**
     * @brief Print info shape: width, color, position, area
     */
    virtual void printInfo();

    /**
     * @brief Calculate distance of shape based on pos_x and pos_y
     */
    virtual float calDistance();

    /**
     * @brief Set size of shape based on topLeft and bottomRight point
     */
    virtual void setSize();

    /**
     * @brief Set position of shape based on topLeft and bottomRight point
     */
    virtual void setPos();

    /**
     * @brief Calculate area of shape based on size
     */
    virtual float calArea();

protected:
    virtual void doDraw (QPainter &painter) = 0;

    virtual QRect doRect() const = 0;

    virtual void doUpdate (const QPoint &toPoint) = 0;

    float pos_x, pos_y;

private:
    int penWidth;
    QColor penColor;
};


std::unique_ptr<Shape> createEllipse (const QPoint &topLeft, int penWidth, const QColor& penColor);

std::unique_ptr<Shape> createCircle (const QPoint &topLeft, int penWidth, const QColor& penColor);

std::unique_ptr<Shape> createRectangle (const QPoint &topLeft, int penWidth, const QColor& penColor);

std::unique_ptr<Shape> createSquare (const QPoint &topLeft, int penWidth, const QColor& penColor);

std::unique_ptr<Shape> createTriangle (const QPoint &topLeft, int penWidth, const QColor& penColor);

std::unique_ptr<Shape> createScribble (const QPoint &topLeft, int penWidth, const QColor& penColor);

} // namespace Paint

#endif // SHAPE_H

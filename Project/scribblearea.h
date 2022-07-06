#ifndef SCRIBBLEAREA_H
#define SCRIBBLEAREA_H

#include "shape.h"
#include <QUndoStack>
#include <QWidget>
#include <vector>
#include <functional>
#include <memory>

namespace Paint
{
class Option;
/**
 * @brief The ScribbleArea class representing a scribble area where we draw on.
 */
class ScribbleArea : public QWidget
{
    Q_OBJECT
public:
    explicit ScribbleArea (QUndoStack *undoStack, QWidget *parent = 0);

    /**
     * @brief Shapes factory function prototype
     */
    typedef std::function<std::unique_ptr<Shape> (const QPoint&, int, const QColor&)> shapeFactory;

    /**
     * @brief Set which shape will be drew
     */
    void setShapeFactory (shapeFactory f);

    bool isModified() const;

    bool openImage (const QString &fileName);
    bool saveImage (const QString &fileName, const char *fileFormat);

    void setPenColor (const QColor &newColor);
    void setPenWidth (int newWidth);

    QColor getPenColor() const { return penColor; }
    int getPenWidth() const { return penWidth; }

    void clearImage();
    void showItemList();
protected:
    void mousePressEvent (QMouseEvent *event);
    void mouseReleaseEvent (QMouseEvent *event);
    void mouseMoveEvent (QMouseEvent *event);
    void paintEvent (QPaintEvent *event);
    void resizeEvent (QResizeEvent *event);

private:
    QImage image;
    QUndoStack *undoStack;

    int penWidth;
    QColor penColor;

    shapeFactory factory;
    std::unique_ptr<Shape> currentShape;
    QList <std::unique_ptr<Shape>> itemList;
};
} // namespace Paint

#endif // SCRIBBLEAREA_H

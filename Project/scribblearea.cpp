#include "scribblearea.h"
#include "command.h"
#include "shape.h"
#include <qevent.h>
#include <QPainter>
#include <QDebug>
#include <algorithm>

namespace Paint
{

ScribbleArea::ScribbleArea(QUndoStack *undoStack, QWidget *parent) :
    QWidget (parent), undoStack (undoStack), penWidth(1), penColor (Qt::blue)
{
}

bool ScribbleArea::isModified() const
{
    /* undo stack keeps the scribble area's modification state */
    return !undoStack->isClean();
}

bool ScribbleArea::openImage (const QString &fileName)
{
    QImage loadedImage;
    if (!loadedImage.load(fileName))
    {
        return false;
    }

    // Get size of Image and expand to that
    const QSize newSize = loadedImage.size().expandedTo(size());

    image = loadedImage;

    // Reuse the command's functionality out of the undo stack
    ResizeCommand (this, &image, newSize).redo();
    undoStack->clear();

    return true;
}

bool ScribbleArea::saveImage (const QString &fileName, const char *fileFormat)
{
    if (image.save (fileName, fileFormat))
    {
        // Clear undo stack
        undoStack->clear();
        return true;
    }
    else
    {
        return false;
    }
}

void ScribbleArea::setPenColor (const QColor &newColor)
{
    penColor = newColor;
}

void ScribbleArea::setPenWidth (int newWidth)
{
    penWidth = newWidth;
}

void ScribbleArea::setShapeFactory (shapeFactory f)
{
    qDebug() << "setShapeFactory";
    factory = f;
}

void ScribbleArea::showItemList()
{
//    QList <std::unique_ptr<Shape>>::iterator i;
//    for (i = itemList.begin(); i != itemList.end(); ++i)
//         (*i)->printInfo();

    int i;
    for (i = 0; i < itemList.size(); ++i)
         itemList.at(i)->printInfo();
}

void ScribbleArea::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    update();
}

void ScribbleArea::mousePressEvent (QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton && factory)
    {
        // Get factory info and create new one with defined topLeft position
        currentShape = factory (event->pos(), penWidth, penColor);
    }
}

void ScribbleArea::mouseMoveEvent (QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && currentShape)
    {
        qDebug() << "mouseMove";
        // Create an rectangle bouding around currentShape
        const QRect prevRect = currentShape->rect();

        // Update to position
        currentShape->update (event->pos());

        // Returns the bounding rectangle of currentShape's rect and prevRect.
        update (currentShape->rect().united (prevRect));
    }
}

void ScribbleArea::mouseReleaseEvent (QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && currentShape)
    {
        qDebug() << "Done with drawind the image";
        qDebug() << "hi";
        // Done with drawind the image.  Now pass the buck to the undo stack.
        undoStack->push (new ShapeCommand (this, &image, std::move (currentShape)));
    }
}

void ScribbleArea::paintEvent (QPaintEvent *event)
{
    qDebug() << "paintE";
    const QRect paintRect = event->rect();

    QPainter painter (this);
    // This is to avoid some pesky artefacts on some platforms (e.g. Debian)
    // when the pen width is only 1 pixel
    painter.setRenderHint (QPainter::Antialiasing, true);

    // just get the required bit of image updated on the widget
    painter.drawImage (paintRect, image, paintRect);

    // ... and draw a shape if there's any under construction
    if (currentShape)
    {
        qDebug() << "currentShape->draw(painter)";
        currentShape->draw(painter);
    }
    qDebug() << "paintEvent";
}

void ScribbleArea::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height())
    {
        const int newWidth = qMax(width() + 128, image.width());
        const int newHeight = qMax(height() + 128, image.height());

        const QSize newSize (newWidth, newHeight);

        // Allow to undo resize operation only when there's been some other
        // modification prior to it.  Otherwise it make little sense and any
        // internal resize operations would also be caught here.
        if (isModified())
        {
            undoStack->push(new ResizeCommand(this, &image, newSize));
        }
        else
        {
            ResizeCommand(this, &image, newSize).redo();
        }
    }
    QWidget::resizeEvent(event);
}
} // Paint

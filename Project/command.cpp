#include "command.h"
#include "scribblearea.h"
#include <QDebug>

namespace Paint
{

/* Needed for merging */
enum CommandId
{
    ResizeCommandId = 1
};

ShapeCommand::ShapeCommand (QWidget *scribblearea, QImage *image, std::unique_ptr<Shape> &&s) :
    scribblearea(scribblearea), image(image), undoImage(image->copy(s->rect())), shape(std::move(s))
{
    /*
     * Define scribblearea as a child window inside scribblearea
     * Constructs a shallow copy of the given image.
     * Define undoImage as a copy of rect of shape s.
     * Define shape as s.
     */
}

void ShapeCommand::undo()
{
    qDebug() << "undo";
    // Define rect as a rectangle bouding around shape
    const QRect rect = shape->rect();

    // Constructs a painter that begins painting the paint image immediately.
    QPainter painter (image);

    // Draws the given image - undo Image into the given rectangle.
    painter.drawImage (rect, undoImage);

    // Updates a rectangle rect inside the scribble area
    scribblearea->update (rect);
}

void ShapeCommand::redo()
{
    // Constructs a painter that begins painting the paint image immediately.
    QPainter painter (image);

    // Draw corresponding to shape with a painter
    shape->draw (painter);
    qDebug() << "redo";

    // Updates a rectangle rect of a shape inside the scribble area
    scribblearea->update (shape->rect());
}

ResizeCommand::ResizeCommand (QWidget *scribblearea, QImage *image, const QSize &size) :
    scribblearea (scribblearea), image (image), oldSize (image->size()), newSize (size)
{
    /*
     * Define scribblearea as a child window inside scribblearea
     * Constructs a shallow copy of the given image.
     * Define oldSize as a present size of image
     * Define newSize as a size in intialization
     */
}

int ResizeCommand::id () const
{
    return ResizeCommandId;
}

bool ResizeCommand::mergeWith (const QUndoCommand *command)
{
    /*
     * If parent is not nullptr, this command is appended to parent's child list.
     * The parent command then owns this command and will delete it in its destructor.
     */
    /*
     * Returns the ID of this command.
     * A command ID is used in command compression. It must be an integer unique to this command's class,
     * or -1 if the command doesn't support compression.
     * If the command supports compression this function must be overridden in the derived class to return the correct
     * ID. The base implementation returns -1.
     */
    if (command->id() != id())
        return false;

    /* Subsequent resize command will look like a single one:  keep the first
     * command's previous size and update it with the latest resize command's
     * new size.
     * Cast from QUndoResize to ResizeCommand
     */
    newSize = static_cast<const ResizeCommand*>(command)->newSize;
    return true;
}

void ResizeCommand::undo()
{
    /*
     * The returned image is copied from the position (x, y) in this image, and will always have
     * the given width and height. In areas beyond this image, pixels are set to 0.
     */
    *image = image->copy (0, 0, oldSize.width(), oldSize.height());

    // Updates a rectangle rect of a shape inside the scribble area
    scribblearea->update();
}

void ResizeCommand::redo()
{
    // If resized
    if (image->size() == newSize)
    {
        return;
    }

    /* Constructs an image with the given size and format.
     * This will create a QImage with uninitialized data.
     * Call fill() to fill the image with an appropriate pixel value before drawing onto it with QPainter.
     */
    QImage newImage (newSize, QImage::Format_RGB32);

    // Fills the entire image with the given pixelValue.
    newImage.fill (Qt::white);

    // Constructs a painter that begins painting the paint newImage immediately.
    QPainter painter (&newImage);

    // Draws the given image at the given point.
    painter.drawImage (QPoint(0, 0), *image);

    // Set image now as a newImage
    *image = newImage;

    // Updates a rectangle rect of a shape inside the scribble area
    scribblearea->update();
}
} // namespace Paint

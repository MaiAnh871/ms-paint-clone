#ifndef COMMAND_H
#define COMMAND_H

#include <QUndoCommand>
#include "shape.h"
#include <memory>

namespace Paint
{

/**
 * Here we have all commands to be used for undo/redo support.
 */
/**
 * @brief The ShapeCommand class for creating/undoing shapes on the scribble area.
 */
class ShapeCommand : public QUndoCommand
{
public:
    /**
     * @brief ShapeCommand intialize
     */
    explicit ShapeCommand (QWidget *scribblearea, QImage *image, std::unique_ptr<Shape> &&s);

    virtual void undo() override;
    virtual void redo() override;

private:
    QWidget *scribblearea;
    QImage *image;
    QImage undoImage;
    std::unique_ptr<Shape> shape;
};

/**
 * @brief The ResizeCommand class for resizing the image (scribble area).  Only
 * increases the size.  Able to be merged with other subsequent resize commands.
 */
class ResizeCommand : public QUndoCommand
{
public:
    explicit ResizeCommand (QWidget *scribblearea, QImage *image, const QSize &size);

    virtual int id() const override;
    virtual bool mergeWith (const QUndoCommand *command) override;

    virtual void undo() override;
    virtual void redo() override;

private:
    QWidget *scribblearea;
    QImage *image;
    QSize oldSize, newSize;
};
} // namespace Paint

#endif // COMMAND_H

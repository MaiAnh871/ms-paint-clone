#include "mainwindow.h"

#include "scribblearea.h"
#include "shape.h"
#include "shapefactory.h"
#include "instruction.h"

#include <QtWidgets>

#include <functional>
#include <utility>

namespace Paint
{
MainWindow::MainWindow (QWidget *parent)
    : QMainWindow (parent), brushActionGroup (this), scribblearea (&undoStack)
{
    createMenus();

    // Sets the scribblearea to be the main window's central widget.
    setCentralWidget (&scribblearea);

    // Set title to be Paint
    setWindowTitle (tr("Paint"));

    // Resize the widget window to 500 x 500
    resize (500, 500);

    // Initialize with first of brushActionGroup
    brushActionGroup.actions().first()->trigger();
}

MainWindow::~MainWindow()
{
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    if (maybeSave())
    {
        // Accept close
        event->accept();
    }
    else
    {
        // Ignore close
        event->ignore();
    }
}

void MainWindow::open()
{
    if (maybeSave())
    {
        // The file dialog's working directory will be set to dir. If dir includes a file name, the file will be selected.
        const QString fileName = QFileDialog::getOpenFileName (this, tr("Open File"), QDir::currentPath());
        if (!fileName.isEmpty())
        {
            // Open file on scribblearea
            scribblearea.openImage (fileName);
        }
    }
}

void MainWindow::save()
{
    saveFile("bmp");
}

void MainWindow::penColor()
{
    // Open color box
    const QColor newColor = QColorDialog::getColor (scribblearea.getPenColor());
    if (newColor.isValid())
    {
        // Set color pen to scribble area
        scribblearea.setPenColor(newColor);
    }
}

void MainWindow::penWidth()
{
    bool ok;
    // Can choose width from 1 to 50
    const int newWidth = QInputDialog::getInt(this, tr("Scribble"), tr("Select pen width:"),
                                              scribblearea.getPenWidth(), 1, 50, 1, &ok);
    if (ok)
    {
        // Set pen width to scribble area
        scribblearea.setPenWidth (newWidth);
    }
}

void MainWindow::createMenus()
{
    // For using bind
    using namespace std::placeholders;

    QMenu *const fileMenu = menuBar()->addMenu (tr ("&File"));
    fileMenu->addAction (tr("&Open..."), this, SLOT (open()), QKeySequence::Open);
    fileMenu->addAction ("&Save As...", this, SLOT (save()));
    fileMenu->addSeparator();
    fileMenu->addAction (tr("&Exit"), this, SLOT (close()), QKeySequence::Quit);


    QMenu *const editMenu = menuBar()->addMenu (tr("&Edit"));
    QAction *const undoAct = undoStack.createUndoAction (editMenu, tr("&Undo"));
    undoAct->setShortcut (QKeySequence::Undo);
    editMenu->addAction (undoAct);
    QAction *const redoAct = undoStack.createRedoAction (editMenu, tr("&Redo"));
    redoAct->setShortcut (QKeySequence::Redo);
    editMenu->addAction (redoAct);


    QMenu *const brushMenu = menuBar()->addMenu (tr ("&Brush"));
    brushMenu->addAction (tr ("&Pen Color..."), this, SLOT (penColor()));
    brushMenu->addAction (tr ("Pen &Width..."), this, SLOT (penWidth()));

    brushMenu->addSeparator();
    const std::pair <QString, ScribbleArea::shapeFactory> shapeActions[] =
    {
        std::make_pair (tr("Scribble"), createScribble),
        std::make_pair (tr("Ellipse"), createEllipse),
        std::make_pair (tr("Circle"), createCircle),
        std::make_pair (tr("Rectangle"), createRectangle),
        std::make_pair (tr("Square"), createSquare)
        //std::make_pair (tr("Triangle"), createTriangle)
    };
    for (const auto &actionDesc : shapeActions)
    {
        QAction *const act = brushMenu->addAction (actionDesc.first);
        connect (act, &QAction::triggered, std::bind (&ScribbleArea::setShapeFactory, &scribblearea, actionDesc.second));

        // This property holds whether the button is checkable
        brushActionGroup.addAction (act)->setCheckable (true);
    }
    /*
     * This property holds whether the button group is exclusive.
     * If this property is true then only one button in the group can be checked at any given time.
     * The user can click on any button to check it, and that button will replace the existing one as the checked button in the group.
     * In an exclusive group, the user cannot uncheck the currently checked button by clicking on it;
     * instead, another button in the group must be clicked to set the new checked button for that group.
     */
    brushActionGroup.setExclusive (true);
}

bool MainWindow::maybeSave()
{
    if (scribblearea.isModified())
    {
       const QMessageBox::StandardButton ret =
               QMessageBox::warning (this, tr ("Paint"),
                                    tr ("The image has been modified.\n"
                                       "Do you want to save your changes?"),
                                    QMessageBox::Save |
                                    QMessageBox::Discard |
                                    QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
        {
            return saveFile("bmp");
        }
        else if (ret == QMessageBox::Cancel)
        {
            return false;
        }
    }
    return true;
}

bool MainWindow::saveFile (const QByteArray &fileFormat)
{
    const QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;

    const QString fileName =
            QFileDialog::getSaveFileName (this, tr("Save As"), initialPath,
                                         tr("%1 Files (*.%2);;All Files (*)")
                                         .arg (QString::fromLatin1(
                                                  fileFormat.toUpper()))
                                         .arg (QString::fromLatin1(fileFormat)));
    return !fileName.isEmpty() && scribblearea.saveImage (fileName, fileFormat.constData());
}

} // namespace Paint

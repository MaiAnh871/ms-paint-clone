#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scribblearea.h"
#include "instruction.h"
#include <QActionGroup>
#include <QMainWindow>

namespace Paint
{

/**
 * @brief The MainWindow class representing the main application's window.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow (QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent (QCloseEvent *event);

private slots:
    void open();
    void save();
    void penColor();
    void penWidth();


private:
    void createMenus();
    bool maybeSave();
    bool saveFile (const QByteArray &fileFormat);

    QActionGroup brushActionGroup;
    QAction *clearScreenAct;
    QUndoStack undoStack;

    ScribbleArea scribblearea;
};
} // namespace Paint

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "renderarea.h"

namespace Ui {
class MainWindow;
}
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionDraw_triggered();

    void on_actionSelect_triggered();

private:
    Ui::MainWindow *ui;

    QLabel *listLabel;
    QLabel *selectedItem;
    RenderArea *qRenderArea;
};

#endif // MAINWINDOW_H

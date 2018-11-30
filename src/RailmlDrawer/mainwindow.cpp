#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    qRenderArea = new RenderArea(this);
    setCentralWidget(qRenderArea);


}

MainWindow::~MainWindow()
{
    delete ui;
}


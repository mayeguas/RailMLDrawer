#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    listLabel = ui->elementList;
    selectedItem = ui->selectedElement;
    qRenderArea = new RenderArea(listLabel, selectedItem, this);
    ui->verticalLayout->addWidget(qRenderArea);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDraw_triggered()
{

}

void MainWindow::on_actionSelect_triggered()
{

}

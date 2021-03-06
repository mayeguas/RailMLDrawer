#include "renderarea.h"

#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QLine>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>

#include "track.h"
#include "sidetrack.h"


bool pointInCircle(QPoint pointA, QPoint pointB)
{
    return ( (pow((pointA.x() - pointB.x()), 2) + pow((pointA.y() - pointB.y()), 2)) < pow(10, 2)) ? true : false;
}

RenderArea::RenderArea(QLabel *listLabel, QLabel *selectedItem, QWidget *parent) : QWidget(parent), currentShapeCode(Shape::Track), shape(NULL), endDraw(false)
{
    qListLabel = listLabel;
    qSelectedItem = selectedItem;
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    endDraw = false;

    connect(shape, SIGNAL(shapeSelected()), this, SLOT(shapeSelected()));

}

void RenderArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.fillRect(this->rect(), Qt::white);
    foreach(Shape * shape, shapeList) {
        shape->paint(painter);
    }

}

void RenderArea::mousePressEvent(QMouseEvent *event)
{
    switch (currentShapeCode) {
        case Shape::Track:
        {
            shape = new Track(this);
            break;
        }
        case Shape::SideTrack:
        {
            shape = new SideTrack(this);
            break;
        }
    }



    if(shapeList.isEmpty()) shape->setId("net_0");
    else shape->setId(QString("net_%1").arg(QString(shapeList.length())));

    qListLabel->setText(qListLabel->text().append(shape->getId() + ", "));

    foreach(Shape *shape_, shapeList)
    {

        if(pointInCircle(shape_->getStart(), event->pos()))
        {
            shape->setStart(shape_->getStart());
            shape->setEnd(shape_->getStart());
            endDraw = false;
            shapeList<<shape;
            update();
            return;
        }
        if(pointInCircle(shape_->getEnd(), event->pos()))
        {
            shape->setStart(shape_->getEnd());
            shape->setEnd(shape_->getEnd());
            endDraw = false;
            shapeList<<shape;
            update();
            return;
        }
    }

    if(shape != NULL) {
        shape->setStart(event->pos());
        shape->setEnd(event->pos());
        endDraw = false;
        shapeList<<shape;
        update();
    }
}

void RenderArea::mouseMoveEvent(QMouseEvent *event)
{
    if(shape && !endDraw) {

        if(abs(shape->getStart().y() - event->pos().y()) > 50 &&
               shape->getStart().y() < event->pos().y() &&
               shape->getStart().x() < event->pos().x())
        {
            shape->setEnd(QPoint(event->pos().x(), shape->getStart().y() + abs(shape->getStart().x() - event->pos().x())));
        }
        else if(abs(shape->getStart().y() - event->pos().y()) > 50 &&
                    shape->getStart().y() < event->pos().y() &&
                    shape->getStart().x() > event->pos().x())
        {
            shape->setEnd(QPoint(event->pos().x(), shape->getStart().y() + abs(shape->getStart().x() - event->pos().x())));
        }
        else if(abs(shape->getStart().y() - event->pos().y()) > 50 &&
                    shape->getStart().y() > event->pos().y() &&
                    shape->getStart().x() < event->pos().x())
        {
            shape->setEnd(QPoint(event->pos().x(), shape->getStart().y() - abs(shape->getStart().x() - event->pos().x())));
        }
        else if(abs(shape->getStart().y() - event->pos().y()) > 50 &&
                    shape->getStart().y() > event->pos().y() &&
                    shape->getStart().x() > event->pos().x())
        {
            shape->setEnd(QPoint(event->pos().x(), shape->getStart().y() - abs(shape->getStart().x() - event->pos().x())));
        }
        else
        {
            shape->setEnd(QPoint(event->pos().x(),shape->getStart().y()));
        }
        update();
    }

}

void RenderArea::mouseReleaseEvent(QMouseEvent *)
{
    endDraw = true;
}

void RenderArea::shapeSelected()
{
    qSelectedItem->setText("Selected: " + shape->getId());
}

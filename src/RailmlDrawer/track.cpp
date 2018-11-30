#include "track.h"
#include <QPainter>

Track::Track(QObject *parent) : Shape(parent)
{
    shapeName= "Track";
}

void Track::paint(QPainter &painter) const
{
    /*
    if(abs(start.y() - end.y()) > 50 &&
           start.y() < end.y() &&
           start.x() < end.x())
    {
        painter.drawLine(start.x(), start.y(), end.x(), start.y() + abs(start.x() - end.x()));
    }
    else if (abs(start.y() - end.y()) > 50 &&
                 start.y() > end.y() &&
                 start.x() > end.x())
    {
        painter.drawLine(start.x(), start.y(), end.x(), start.y() - abs(start.x() - end.x()));
    }
    else if(abs(start.y() - end.y()) > 50 &&
                start.y() < end.y() &&
                start.x() > end.x())
    {
        painter.drawLine(start.x(), start.y(), end.x(), start.y() + abs(start.x() - end.x()));
    }
    else if (abs(start.y() - end.y()) > 50 &&
                 start.y() > end.y() &&
                 start.x() < end.x())
    {
        painter.drawLine(start.x(), start.y(), end.x(), start.y() - abs(start.x() - end.x()));
    }
    else
    {
        painter.drawLine(start.x(), start.y(), end.x(), start.y());
    }
    */
    painter.drawLine(start.x(), start.y(), end.x(), end.y());

}

void Track::mousePressEvent(QMouseEvent *)
{
    emit shapeSelected();
}

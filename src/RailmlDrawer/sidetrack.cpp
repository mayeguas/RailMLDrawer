#include "sidetrack.h"

#include <QPainter>

SideTrack::SideTrack(QObject *parent) : Shape(parent)
{
    shapeName= "SideTrack";
}


void SideTrack::paint(QPainter &) const
{


}

void SideTrack::mousePressEvent(QMouseEvent *)
{
    emit shapeSelected();
}


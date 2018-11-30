#ifndef SIDINGTRACK_H
#define SIDINGTRACK_H

#include "shape.h"

#include <QList>

class QPainterPath;

class SideTrack : public Shape
{
public:
    SideTrack(QObject *parent = 0);
    void paint(QPainter &painter) const;
};

#endif // SIDINGTRACK_H

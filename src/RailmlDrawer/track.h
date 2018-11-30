#ifndef TRACK_H
#define TRACK_H

#include "shape.h"

class Track : public Shape
{
public:
    Track(QObject *parent = 0);
    void paint(QPainter &painter) const;
};

#endif // TRACK_H

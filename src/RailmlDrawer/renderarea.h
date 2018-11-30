#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include "shape.h"

class QPaintEvent;
class QMouseEvent;
class QPainter;
class QGraphicsScene;
class Track;


class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QList<Shape*> shapeList;
    QList<Track*> trackList;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QGraphicsScene *scene;
    QPoint qStartPoint;
    QPoint qEndPoint;
    Shape::Code currentShapeCode;
    Shape *shape;
    bool endDraw;

};

#endif // RENDERAREA_H

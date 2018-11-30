#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QPoint>
#include <QString>

class QPainter;
class QMouseEvent;

class Shape : public QObject
{
    Q_OBJECT
public:
    enum Code {
        Track,
        SideTrack
    };

    QString shapeName;

    explicit Shape(QObject *parent = nullptr);

    void setStart(QPoint s)
    {
        start = s;
    }

    void setEnd(QPoint e)
    {
        end = e;
    }

    void setId(QString id_)
    {
        id = id_;
    }

    QPoint getStart()
    {
        return start;
    }

    QPoint getEnd()
    {
        return end;
    }

    QString getId()
    {
        return id;
    }

    void virtual paint(QPainter & painter) const = 0;
    void virtual mousePressEvent(QMouseEvent *event) = 0;

protected:
    QPoint start;
    QPoint end;
    QString id;

signals:
    void shapeSelected();
};

#endif // SHAPE_H

#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QPoint>
#include <QString>
class QPainter;

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

    QPoint getStart()
    {
        return start;
    }

    QPoint getEnd()
    {
        return end;
    }

    void virtual paint(QPainter & painter) const = 0;

protected:
    QPoint start;
    QPoint end;
};

#endif // SHAPE_H

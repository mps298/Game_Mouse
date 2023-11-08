#ifndef MYCELL_H
#define MYCELL_H

#include <QPoint>
#include <QColor>


class MyCell
{
    QPoint myCellPoint;
    bool isPushed = false;

public:
    MyCell();
    QPoint getMyCellPoint() const;
    void setMyCellPoint(const QPoint &value);

    bool getIsPushed() const;
    void setIsPushed(bool value);
};

#endif // MYCELL_H

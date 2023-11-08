#include "mycell.h"

QPoint MyCell::getMyCellPoint() const
{
    return myCellPoint;
}

void MyCell::setMyCellPoint(const QPoint &value)
{
    myCellPoint = value;
}

bool MyCell::getIsPushed() const
{
    return isPushed;
}

void MyCell::setIsPushed(bool value)
{
    isPushed = value;
}

MyCell::MyCell()
{

}

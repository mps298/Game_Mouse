#include "fieldview.h"

int FieldView::getFieldSideLength() const
{
    return fieldSideLength;
}

void FieldView::setFieldSideLength(int value)
{
    fieldSideLength = value;
}

int FieldView::getCellSize() const
{
    return cellSize;
}

void FieldView::setCellSize(int value)
{
    cellSize = value;
}


void FieldView::messCellsSlot()
{
    emit setLevelSignal(++level);

    qDebug()<<"messCellsSlot works, fieldSizeLength = "<<fieldSideLength;
    nextNumber = 0;
    cellSize = width()/fieldSideLength;

    int currentLength = fieldSideLength*fieldSideLength;

    myCells = QVector<MyCell>(currentLength);
    QVector<int> tmpInts = QVector<int>(currentLength, -1);
    for (int i = 0; i < currentLength; i++)
    {
        int number = -1;
        bool isMatched = true;
        do
        {
            number = qrand()%currentLength;
            for (auto i: tmpInts)
            {
                if (number == i) {   isMatched = true;  break;   }
                isMatched = false;
            }
        }
        while (isMatched);
        tmpInts[i] = number;

        myCells[i].setIsPushed(false);

        int x = (number%fieldSideLength) * cellSize;
        int y = (number/fieldSideLength) * cellSize;

        myCells[i].setMyCellPoint(QPoint (x, y));
    }

    currentColor = qrand()%5;
    update();

    emit gameOnSignal(currentLength);
    emit updateLCDSignal();

}

void FieldView::newGameSlot()
{
    qDebug()<<"newGameSlot works";
    level = -1;
    fieldSideLength = 1;
    messCellsSlot();
}


void FieldView::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"MOUSEpRESSeVENT Works";
    int currentX = event->pos().x();
    while (currentX%cellSize) {    currentX--;    }

    int currentY = event->pos().y();
    while (currentY%cellSize) {    currentY--;    }

    int tmpInt = -1;
    for (int i = 0; i < myCells.length(); i++)
    {
        if (myCells.at(i).getMyCellPoint() == QPoint(currentX, currentY))
        {
            tmpInt = i;
            break;
        }
    }

    //    if (myCells.at(tmpInt).getIsPushed() == true) { return; }

    if (tmpInt == nextNumber)
    {
        nextNumber++;
        myCells[tmpInt].setIsPushed(true);

//        currentColor = -1;
        do {
            currentColor = qrand()%5;
        }
        while (currentColor == previousColor);

        previousColor = currentColor;

        if(nextNumber == myCells.size())
        {
            timerStopSignal();
            fieldSideLength = fieldSideLength/**2 */+ 1;
            messCellsSlot();
        }

//        repaint();
        update();
    }

    else
    {
        emit oopsSignal();
    }
}


void FieldView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(QBrush(Qt::darkBlue), 1));

    for (int i = 0; i < myCells.size(); i++)
    {
        QRect rect = QRect(myCells.at(i).getMyCellPoint(), QSize(cellSize,cellSize));

        QColor currentCellColor = myCells.at(i).getIsPushed()? Qt::lightGray : Qt::darkGray;
        if (i == nextNumber)
        {
            switch (currentColor)
            {
            case 0: currentCellColor = Qt::green; break;
            case 1: currentCellColor = Qt::cyan; break;
            case 2: currentCellColor = Qt::magenta; break;
            case 3: currentCellColor = Qt::yellow; break;
            case 4: currentCellColor = Qt::red; break;

            default: break;
            }
            qDebug()<<"color = "<<currentCellColor;
        }
        painter.fillRect(rect, currentCellColor);
        painter.drawRect(rect);

        if (myCells.at(i).getIsPushed() || i == nextNumber)
        {
            QString str;
            if (fieldSideLength == 1)
            {
                str = tr("GO!");
            }
            else
            {
                str.setNum(i+1);
            }

            int fontSize = fieldSideLength == 1? 4: i+1 < 10? 2 : i+1 < 100? 3 : i+1 < 200? 4 : i+1 < 1000? 5 : 6;
            painter.setFont(QFont("Times", cellSize/fontSize, QFont::Bold));
            painter.drawText(rect, Qt::AlignCenter, str);
        }
    }
    painter.drawRect(QRect(0,0,cellSize*fieldSideLength,cellSize*fieldSideLength));
}


QVector<MyCell> FieldView::getMyCells() const
{
    return myCells;
}

void FieldView::setMyCells(const QVector<MyCell> &value)
{
    myCells = value;
}


int FieldView::getLevel() const
{
    return level;
}

void FieldView::setLevel(int value)
{
    level = value;
}

FieldView::FieldView(QWidget *parent) : QWidget(parent)
{
    setFixedSize(1000, 1000);
    newGameSlot();
}

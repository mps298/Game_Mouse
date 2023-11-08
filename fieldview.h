#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include <QWidget>
#include <QDebug>
#include <QVector>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QRect>
#include <QMessageBox>
#include <QDesktopWidget>


#include "mycell.h"


class FieldView : public QWidget
{
    Q_OBJECT

    int level = 0;

    int fieldSideLength;
    int cellSize;

    QVector<MyCell> myCells;

    int nextNumber = 0;

    int previousColor = -1;
    int currentColor = qrand()%5;


public:
    explicit FieldView(QWidget *parent = nullptr);

    int getFieldSideLength() const;
    void setFieldSideLength(int value);

    int getCellSize() const;
    void setCellSize(int value);

    QVector<MyCell> getMyCells() const;
    void setMyCells(const QVector<MyCell> &value);


    int getLevel() const;
    void setLevel(int value);

signals:
    void gameOverSignal();
    void gameOnSignal(int);
    void oopsSignal();
    void timerStopSignal();
    void updateLCDSignal();
    void setLevelSignal(int);

public slots:
    void messCellsSlot();
    void newGameSlot();


    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

};

#endif // FIELDVIEW_H

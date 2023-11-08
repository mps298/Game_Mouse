#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


    QTimer timer;
    QTimer updater;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_newGameButton_clicked();
    void on_exitButton_clicked();
    void gameOverSlot();
    void gameOnSlot(int timeRemains);
    void oopsSlot();
    void timerStartSlot(int timeRemains);
    void updateLCDSlot();
    void timerStopSlot();

signals:
    void updateLCD (int);

private:
    Ui::MainWindow *ui;
     void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    if (!isVisible()) {show();}
    ////    ui->fieldViewWidget->newGameSlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newGameButton_clicked()
{
    int timeRemains = -1;
    bool wasActive = false;
    if (timer.isActive())
    {
        wasActive = true;
        timeRemains = timer.remainingTime();
        timerStopSlot();
    }

    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("New game"));
    msgBox.setText(tr("Are you sure?"));
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes, tr("Yes"));
    msgBox.setButtonText(QMessageBox::No, tr("No"));
    msgBox.setDefaultButton(QMessageBox::No);

    if (msgBox.exec() == QMessageBox::No)
    {
        if   (wasActive)    {   timerStartSlot(timeRemains); }
    }
    else
    {

        //        LCDcounter = 0;
        ui->fieldViewWidget->newGameSlot();
    }

}

void MainWindow::on_exitButton_clicked()
{
    int timeRemains = -1;
    if (timer.isActive())
    {
        timeRemains = timer.remainingTime();
        timerStopSlot();
    }

    QMessageBox *msgBox = new QMessageBox (this);
    msgBox->setWindowTitle(tr("Exit"));
    msgBox->setText(tr("Are you sure?"));
    msgBox->setIcon(QMessageBox::Question);
    msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox->setButtonText(QMessageBox::Yes, tr("Yes"));
    msgBox->setButtonText(QMessageBox::No, tr("No"));
    msgBox->setDefaultButton(QMessageBox::No);

    if(msgBox->exec() == QMessageBox::No)
    {
        timerStartSlot(timeRemains); return;
    }


    close();


}

void MainWindow::gameOverSlot()
{
    qDebug()<<"gaveOverSlot works";

    //    if (gameOn)
    {
        //        gameOn = false;
        timerStopSlot();
        QMessageBox::information(this, tr("Game Over"), tr("GAME OVER"));
    }

    ui->fieldViewWidget->newGameSlot();
}

void MainWindow::gameOnSlot(int timeRemains)
{
    if (timeRemains == 1)   {   return; }

    qDebug()<<"gaveOnSlot works";
    //     gameOn = true;

    QMessageBox* msgBox = new QMessageBox (this);
    msgBox->setWindowTitle(tr("Ready?"));
    QString str1 = tr("You have ");
    QString strNum;
    strNum.setNum(timeRemains);
    QString str2 = tr(" seconds to push ");
    QString str3 = tr(" buttons\nARE YOU READY?");
    QString strAll = str1 + strNum + str2 + strNum + str3;
    msgBox->setText(strAll);
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStandardButtons(QMessageBox::Yes /*| QMessageBox::No | QMessageBox::Close */);
    msgBox->setButtonText(QMessageBox::Yes, tr("GO!"));
    msgBox->setDefaultButton(QMessageBox::Yes);
    msgBox->sizeHint();
    msgBox->show();
    msgBox->move(QDesktopWidget().availableGeometry().center());
    if (msgBox->exec() == QMessageBox::Yes)
    {
        timerStartSlot(timeRemains*1000);
    }

}

void MainWindow::oopsSlot()
{
    ui->fieldViewWidget->setLevel(ui->fieldViewWidget->getLevel()-1);
    qDebug()<<"oopsSlot works";

    timerStopSlot();
    updateLCD(0);
    QMessageBox::information(this, tr("Oops!"), tr("Oops!\nTry again"));
    ui->fieldViewWidget->messCellsSlot();
}

void MainWindow::timerStartSlot(int timeRemains)
{
    qDebug()<<"timerSlot works";

    updater.setSingleShot(false);
    connect(&updater, SIGNAL(timeout()), this, SLOT(updateLCDSlot()));

    timer.setSingleShot(true);
    connect(&timer, SIGNAL(timeout()), this, SLOT(oopsSlot()));
    updater.start(1000);
    timer.start(timeRemains);
}

void MainWindow::updateLCDSlot()
{
    qDebug()<<"updateLCDSlot works, timer is active = "<<timer.isActive();

    float remFloat = static_cast<float>(timer.remainingTime()/1000.0);
    qDebug()<<"remFloat = "<<remFloat;
    int remInt = qRound(remFloat);
    qDebug()<<"remInt = "<<remInt;

    emit updateLCD(remInt);
}

void MainWindow::timerStopSlot()
{
    qDebug()<<"stopTimerSlot works, timer was active = "<<timer.isActive();
    if (timer.isActive())
    {
        timer.stop();
    }
    if (updater.isActive())
    {
        updater.stop();
    }
    timer.disconnect();
    updater.disconnect();
    qDebug()<<"stopTimerSlot works, timer is active = "<<timer.isActive();


}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}


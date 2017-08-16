#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QGraphicsOpacityEffect>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //scale
    QPropertyAnimation *pScaleAnimation1 = new QPropertyAnimation(ui->scaleButton, "geometry");
    pScaleAnimation1->setDuration(1000);
    pScaleAnimation1->setStartValue(QRect(190, 230, 0, 0));
    pScaleAnimation1->setEndValue(QRect(120, 160, 140, 140));
    pScaleAnimation1->setEasingCurve(QEasingCurve::InOutQuad);

    QPropertyAnimation *pScaleAnimation2 = new QPropertyAnimation(ui->scaleButton, "geometry");
    pScaleAnimation2->setDuration(1000);
    pScaleAnimation2->setStartValue(QRect(120, 160, 140, 140));
    pScaleAnimation2->setEndValue(QRect(190, 230, 0, 0));
    pScaleAnimation2->setEasingCurve(QEasingCurve::InOutQuad);

    QSequentialAnimationGroup *pScaleGroup = new QSequentialAnimationGroup(this);
    pScaleGroup->addAnimation(pScaleAnimation1);
    pScaleGroup->addAnimation(pScaleAnimation2);

    //pos
    QPropertyAnimation *pPosAnimation1 = new QPropertyAnimation(ui->posButton, "pos");
    pPosAnimation1->setDuration(1000);
    pPosAnimation1->setStartValue(QPoint(360, 160));
    pPosAnimation1->setEndValue(QPoint(360, 350));
    pPosAnimation1->setEasingCurve(QEasingCurve::InOutQuad);

//    QPropertyAnimation *pPosAnimation2 = new QPropertyAnimation(ui->posButton, "pos");
//    pPosAnimation2->setDuration(1000);
//    pPosAnimation2->setStartValue(QPoint(360, 350));
//    pPosAnimation2->setEndValue(QPoint(360, 160));
//    pPosAnimation2->setEasingCurve(QEasingCurve::InOutQuad);

    QSequentialAnimationGroup *pPosGroup = new QSequentialAnimationGroup(this);
    pPosGroup->addPause(500);
    pPosGroup->addAnimation(pPosAnimation1);
//    pPosGroup->addAnimation(pPosAnimation2);

    //opacity
    QGraphicsOpacityEffect *pButtonOpacity = new QGraphicsOpacityEffect(this);
    pButtonOpacity->setOpacity(1);
    ui->opasityButton->setGraphicsEffect(pButtonOpacity);

    QPropertyAnimation *pOpacityAnimation1 = new QPropertyAnimation(pButtonOpacity, "opacity");
    pOpacityAnimation1->setDuration(1000);
    pOpacityAnimation1->setStartValue(1);
    pOpacityAnimation1->setEndValue(0);

    QPropertyAnimation *pOpacityAnimation2 = new QPropertyAnimation(pButtonOpacity, "opacity");
    pOpacityAnimation2->setDuration(1000);
    pOpacityAnimation2->setStartValue(0);
    pOpacityAnimation2->setEndValue(1);

    QSequentialAnimationGroup *pOpacityGroup = new QSequentialAnimationGroup(this);
    pOpacityGroup->addPause(1000);
    pOpacityGroup->addAnimation(pOpacityAnimation1);
    pOpacityGroup->addAnimation(pOpacityAnimation2);

    m_group = new QParallelAnimationGroup(this);
    m_group->addAnimation(pScaleGroup);
    m_group->addAnimation(pPosGroup);
    m_group->addAnimation(pOpacityGroup);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    m_group->setDirection(QAbstractAnimation::Forward);
    m_group->setLoopCount(1);
    m_group->start();
}

void MainWindow::on_startButton_3_clicked()
{
    m_group->setDirection(QAbstractAnimation::Backward);
    m_group->setLoopCount(1);
    m_group->start();
}

void MainWindow::on_startButton_2_clicked()
{
    m_group->setDirection(QAbstractAnimation::Forward);
    m_group->setLoopCount(-1);
    m_group->start();
}



#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QParallelAnimationGroup>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

    void on_startButton_2_clicked();

    void on_startButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QParallelAnimationGroup *m_group;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QLabel>
#include <QVector>

namespace Ui {
class MainWindow;
}

struct TimeLeft {
    int hours;
    int minutes;
    int seconds;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *tmr;
    QTimer *tmr2;

    QVector<TimeLeft*> timeLeft;
    QVector<QLabel*> labels_timer;
    int iForGrid_timer;
    int jForGrid_timer;

    QVector<TimeLeft*> alarmLeft;
    QVector<QLabel*> labels_alarm;
    int iForGrid_alarm;
    int jForGrid_alarm;

private slots:
    void update();
    void start_clock();
    int reduceTime(TimeLeft* timeLeft);
    void on_createTimer_clicked();
    void on_Start_clicked();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H

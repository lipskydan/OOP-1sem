#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tmr = NULL;
    iForGrid_timer = 0;
    jForGrid_timer = 0;



    tmr2 = new QTimer(this); // Создаем объект класса QTimer и передаем адрес переменной
    connect(tmr2, SIGNAL(timeout()), this, SLOT(start_clock())); // Подключаем сигнал таймера к нашему слоту

    if (tmr2 != NULL)
        tmr2->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tmr;
}


void MainWindow::on_createTimer_clicked()
{
    TimeLeft* newTimer = new TimeLeft;
    newTimer->hours = ui->hourEdit->text().toInt();
    newTimer->minutes = ui->minuteEdit->text().toInt();
    newTimer->seconds = ui->secondEdit->text().toInt();

    timeLeft.push_back(newTimer);

    QString time = ui->hourEdit->text() + " : " + ui->minuteEdit->text() + " : " + ui->secondEdit->text();

    QLabel* label = new QLabel(time);
    labels_timer.push_back(label);

    ui->gridLayoutTimer->addWidget(label, iForGrid_timer, jForGrid_timer);

    if (iForGrid_timer == 4)
    {
        jForGrid_timer++;
        iForGrid_timer = 0;
    } else {
        iForGrid_timer++;
    }
}

void MainWindow::on_Start_clicked()
{
    tmr = new QTimer(this); // Создаем объект класса QTimer и передаем адрес переменной
    connect(tmr, SIGNAL(timeout()), this, SLOT(update())); // Подключаем сигнал таймера к нашему слоту

    if (tmr != NULL)
        tmr->start(1000);
}

int MainWindow::reduceTime(TimeLeft* timeLeft)
{
    if (timeLeft->seconds > 0)
        timeLeft->seconds--;
    else if (timeLeft->seconds == 0)
    {
        if (timeLeft->minutes > 0)
        {
            timeLeft->minutes--;
        }
        else if (timeLeft->minutes == 0)
        {
            if (timeLeft->hours > 0)
            {
                timeLeft->hours--;
                timeLeft->minutes = 59;
            }
            else if (timeLeft->hours == 0)
            {
                return -1;
            }
        }
        timeLeft->seconds = 59;
    }
    return 1;
}

void MainWindow::update()
{
    // For timers
    for (int i = 0; i < ui->gridLayoutTimer->count(); i++)
    {
        QString result;
        if (reduceTime(timeLeft[i]) == -1)
        {
                result = "finish";
        } else {
                result =    QString::number(timeLeft[i]->hours) + " : " +
                            QString::number(timeLeft[i]->minutes) + " : " +
                            QString::number(timeLeft[i]->seconds);
        }

        labels_timer[i]->setText(result);
    }

    // For alarms
    for (int i = 0; i < ui->gridLayoutAlarm->count(); i++)
    {
        QString result;
        QTime alarmTime(alarmLeft[i]->hours, alarmLeft[i]->minutes, alarmLeft[i]->seconds);

        if (alarmTime.currentTime().toString() == alarmTime.toString())
        {
                result = "finish";
                labels_alarm[i]->setText(result);
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    TimeLeft* newAlarm = new TimeLeft;
    newAlarm->hours = ui->hourEdit->text().toInt();
    newAlarm->minutes = ui->minuteEdit->text().toInt();
    newAlarm->seconds = ui->secondEdit->text().toInt();

    alarmLeft.push_back(newAlarm);

    QString time = ui->hourEdit->text() + " : " + ui->minuteEdit->text() + " : " + ui->secondEdit->text();

    QLabel* label = new QLabel(time);
    labels_alarm.push_back(label);

    ui->gridLayoutAlarm->addWidget(label, iForGrid_alarm, jForGrid_alarm);

    if (iForGrid_alarm == 4)
    {
        jForGrid_alarm++;
        iForGrid_alarm = 0;
    } else {
        iForGrid_alarm++;
    }
}

void MainWindow::start_clock()
{
    QTime curr_time = curr_time.currentTime();
    ui->label_5->setText(curr_time.toString());
}

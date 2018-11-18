#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonDownload_clicked();

    void on_pushButtonPower_clicked();

private:
    Ui::MainWindow *ui;
    QString downloadPath;
    QString userPath;
    QString urlPath;
};

#endif // MAINWINDOW_H

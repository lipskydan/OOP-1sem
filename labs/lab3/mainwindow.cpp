#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <curl/curl.h>

//"/Users/danial/"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonDownload_clicked()
{
    downloadPath = ui->downloadPath->text();
    urlPath = ui->urlPath->text();
    userPath = ui->userPath->text();

    CURL *curl = curl_easy_init();
    if(!curl)
    {
        window()->close();
    }

    FILE *fp;
    CURLcode res;
    QByteArray ba = urlPath.toLocal8Bit();
    const char* c_str = ba.data();

    QString path = userPath + downloadPath;
    QByteArray ba2 = path.toLocal8Bit();
    const char* c_str2 = ba2.data();

    fp = fopen(c_str2,"wb");



    curl_easy_setopt(curl, CURLOPT_URL, c_str);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);


    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

}

void MainWindow::on_pushButtonPower_clicked()
{
    window()->close();
}

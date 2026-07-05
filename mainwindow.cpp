#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "yt-dlp.h"
#include <qDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::downloadVideo(QString url, QString path, QString format) {
    downloader v(url, path, format);
    v.downloadVideo();
}

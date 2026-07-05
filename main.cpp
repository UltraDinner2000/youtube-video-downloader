#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QRadioButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle("YouTube video download");

    w.resize(QSize(400,140));

    QLabel *urlLabel = new QLabel("URL", &w);
    urlLabel->setGeometry(0,0,30,30);
    urlLabel->show();

    QTextEdit *urlPath = new QTextEdit("", &w);
    urlPath->setGeometry(30,0,300,30);
    urlPath->show();

    QLabel *pathLabel = new QLabel("path", &w);
    pathLabel->setGeometry(0,35,30,30);
    pathLabel->show();

    QTextEdit *pathEdit = new QTextEdit("", &w);
    pathEdit->setGeometry(30,35,300,30);
    pathEdit->show();

    QRadioButton *isVideo = new QRadioButton("video", &w);
    isVideo->setGeometry(0,70,100,30);
    isVideo->setChecked(true);
    isVideo->show();

    QRadioButton *isAudio = new QRadioButton("audio", &w);
    isAudio->setGeometry(80,70,100,30);
    isAudio->show();


    QPushButton *downloadButton = new QPushButton("download", &w);
    downloadButton->setGeometry(0,110,100,30);
    downloadButton->show();

    QObject::connect(downloadButton, &QPushButton::clicked, [&]() {
        QString format;
        if (isVideo->isChecked()) {
            format = "video";
        }
        else if (isAudio->isChecked()) {
            format = "audio";
        }
        w.downloadVideo(
            urlPath->toPlainText(),
            pathEdit->toPlainText(),
            format
            );
    });

    return a.exec();

}

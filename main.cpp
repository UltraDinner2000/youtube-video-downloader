#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle("YouTube video download");

    w.resize(QSize(400,100));

    QLabel *urlLabel = new QLabel("URL", &w);
    urlLabel->setGeometry(0,0,30,30);
    urlLabel->show();

    QTextEdit *urlPath = new QTextEdit("", &w);
    urlPath->setGeometry(30,0,300,30);
    urlPath->show();

    QPushButton *downloadButton = new QPushButton("download", &w);
    downloadButton->setGeometry(0,70,100,30);
    downloadButton->show();

    QObject::connect(downloadButton, &QPushButton::clicked, [&]() {
        w.downloadVideo(
            urlPath->toPlainText()
            );
    });

    return a.exec();

}

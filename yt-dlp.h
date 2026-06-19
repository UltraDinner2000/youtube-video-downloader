#ifndef YT_DLP_H
#define YT_DLP_H

#endif // YT_DLP_H

#include <QString>
#include <QDir>
#include <qDebug>
#include <QMessageBox>
#include <QWidget>
#include <QApplication>
#include <QProcess>

class downloader {
private:
    QString url;
public:
    downloader(QString url) {
        this->url = url;
    }
    void downloadVideo() {
        QString path = QDir::currentPath() + "/resources/main.exe";
        qDebug() << path;
        QStringList args;
        args << this->url;
        QProcess process;
        process.start(path, args);
        process.waitForFinished();
    }
};

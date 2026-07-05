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
    QString path;
    QString format;
public:
    downloader(QString url, QString path, QString format) {
        this->url = url;
        this->path = path;
        this->format = format;
    }
    void downloadVideo() {
        QString path = QDir::currentPath() + "/resources/main.exe";
        qDebug() << path;
        QStringList args;
        args << this->url << this->path << this->format;
        qDebug() << args;
        QProcess process;
        process.start(path, args);
        process.waitForFinished();
    }
};

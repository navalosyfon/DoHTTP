#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>
#include <QString>

class Downloader : public QObject
{
    Q_OBJECT
public:
    //explicit Downloader(QObject *parent = 0);

    void doDownload(int yyy,int doy);

signals:

public slots:
    void replyFinished (QNetworkReply *reply);

private:
   QNetworkAccessManager *manager;
   QString doc_name;

};

#endif // DOWNLOADER_H

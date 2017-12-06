#include "downloader.h"
#include <iostream>
#include <QString>

/*Downloader::Downloader(QObject *parent) :
    QObject(parent)
{
}
*/
void Downloader::doDownload(int yyyy,int doy)
{
    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));



    QString path_ofdownload="ftp://rgpdata.ign.fr/pub/data/";
    QString yyyy_s =QString::number(yyyy);
    QString doy_s =QString::number(doy-1);
    if(doy_s.size()==2)
         doy_s.prepend("0");
    if(doy_s.size()==1)
        doy_s.prepend("00");

    path_ofdownload=path_ofdownload+yyyy_s+"/"+doy_s+"/"+"coorrgf93_"+yyyy_s+"-"+doy_s+".txt";

    manager->get(QNetworkRequest(QUrl(path_ofdownload)));
    doc_name="coorrgf93_"+yyyy_s+"-"+doy_s+".txt";
}

void Downloader::replyFinished (QNetworkReply *reply)
{
    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else
    {
        //qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();
        //qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        //qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        //qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
        QString saving_path="/home/think/Projet_info/Classe_coonection/DoHTTP/Downloaded_doc/";
        saving_path.append(doc_name);
        QFile *file = new QFile(saving_path);
        if(file->open(QFile::Append))
        {
            file->write(reply->readAll());
            file->flush();
            file->close();
        qDebug()<<doc_name<<"Downloaded and saved !!";
        }
        delete file;

    }
    reply->deleteLater();
}

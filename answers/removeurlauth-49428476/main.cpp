#include "mainwindow.h"
#include <QApplication>
#include <QUrl>
#include <iostream>

QUrl GetFixedUrl(const QUrl & oUrl )
{
    QUrl oNewUrl = oUrl;

    // Reset user name and password
    oNewUrl.setUserName(QString());
    oNewUrl.setPassword(QString());

    // Save the host name
    QString oHostName = oNewUrl.host();

    // Clear authority
    oNewUrl.setAuthority(QString());

    // Set host name
    oNewUrl.setHost(oHostName);

    return oNewUrl;

}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QUrl oUrl("https://user:pass@someurl.com");

    std::cout<< GetFixedUrl(oUrl).toString().toStdString()<< std::endl;

    return a.exec();
}

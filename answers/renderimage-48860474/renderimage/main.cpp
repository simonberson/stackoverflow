#include "mainwindow.h"
#include <QApplication>

#include <QtWidgets/QApplication>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineWidgets/QWebEnginePage>
#include <QtWebEngine/qtwebengineglobal.h>
int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/

    int left, top, width, height;
    left = 0;
    top = 0;
    width = 600;
    height = 800;

    QApplication a(argc, argv);
    QWebEngineView* w = new QWebEngineView();
    QImage image(height, width, QImage::Format_RGB32);
    QRegion rg(left, top, width, height);
    QPainter painter(&image);
    w->page()->load(QUrl("https://www.yahoo.com"));
    w->show();
    w->page()->view()->render(&painter, QPoint(), rg);
    painter.end();
    image.save("test.png", "PNG", 80);

    return a.exec();
}

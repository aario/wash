#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QWebEngineView>
#include "channel.h"

class Application : public QApplication
{
    Q_OBJECT
public:
    Application(int &argc, char **argv);
private:
    QWebEngineView view;
    Channel channel;
private slots:
    void connectToJs(bool result);
};

#endif // APPLICATION_H

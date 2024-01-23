#ifndef CHANNEL_H
#define CHANNEL_H
#include <QObject>
#include <QtWebChannel>
#include <QByteArray>
#include <QTextStream>

class Channel : public QWebChannel
{
    Q_OBJECT
    using QWebChannel::QWebChannel;
public slots:
    void echo(QByteArray data);
signals:
    void init();
    void send(QByteArray data);
};

#endif // CHANNEL_H

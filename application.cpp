#include "application.h"
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include <QIcon>
#include <QtWebChannel>

Application::Application(int &argc, char **argv): QApplication::QApplication(argc, argv)
{
    auto iconPath = QDir::currentPath() + "/favicon.ico";
    if (QFileInfo(iconPath).exists()) {
        setWindowIcon(QIcon(iconPath));
    }

    auto url = "file:///" + QDir::currentPath() + "/index.html";
    view.setUrl(url);
    connect(view.page(), SIGNAL(loadFinished(bool)), this, SLOT(connectToJs(bool)));
    view.show();
}

void Application::connectToJs(bool result)
{
    if (result) {
        auto webChannel = new QWebChannel(view.page());
        view.page()->setWebChannel(webChannel);
        webChannel->registerObject(QString("channel"), &channel);
        qDebug() << "WebChannel registered";
        view.page()->runJavaScript("init();");
    } else {
        qWarning() << "WebChannel could not be registered!";
    }
}

#include "channel.h"
#include <iostream>
#include <cstdlib>

void Channel::echo(QByteArray data)
{
    QTextStream(stdout) << "JS>" << data << Qt::endl;
}

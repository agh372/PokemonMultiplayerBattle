#include "socketthread.h"
#include <sstream>
#include <cstring>

using namespace std;

SocketThread::SocketThread(QString ip, QObject *parent)
{
    socket = new QTcpSocket();
    socket->connectToHost(ip, 1234);
    connect(socket, SIGNAL(readyRead()), this, SLOT(newMessage()));
}

void SocketThread::sendMess(QString s)
{
    s.append(QChar(23));
    socket->write(s.toLocal8Bit());
}

void SocketThread::newMessage() {
    qInfo() << "Socket new message";

    if(QTcpSocket *s = dynamic_cast<QTcpSocket *> (sender())) {
        message.append(s->readAll());
        if(!message.contains(QChar(23)))
            return;
        QStringList l = message.split(QChar(23));
        message = l.takeLast();

    }
}

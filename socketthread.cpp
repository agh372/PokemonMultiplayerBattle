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
    if(QTcpSocket *s = dynamic_cast<QTcpSocket *> (sender())) {
        message.append(s->readAll());
        if(!message.contains(QChar(23)))
            return;
        QStringList l = message.split(QChar(23));
        message = l.takeLast();
        for(int i = 0; i < l.size();i++) {
            string tmpS = l[i].toStdString();
            stringstream stream(tmpS);
            int a, num, num2;
            stream >> a;
           // if(a == 1 || a == 2) {

            if(a == 11){
                emit nameAccepted();
                 }
       // }
    }

    }
}


#include "waiting.h"
#include "ui_waiting.h"
//#include "game.h"
#include <QImage>

waiting::waiting(QString t1, SocketThread *thread, QTimer *timer, QWidget *parent) :
    QDialog(parent), ui(new Ui::waiting)

{

}

waiting::~waiting()
{
    delete ui;
}

void waiting::startGame(QString t1, QString t2)
{

}

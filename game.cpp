#include "game.h"
#include "realplayer.h"
#include "socketthread.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QFile>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QLabel>
#include <QFont>
#include <QProgressBar>


Game::Game(SocketThread *t, QTimer *timer, QString player1Flag,QString player2Flag)
{
    qDebug() << "Game Started ";
    this->t = t;
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QImage(":/Images/PBC.png"));

    QGraphicsView *v = new QGraphicsView(scene);
    v->setFixedSize(1285, 685);
    scene->setSceneRect(0, 0, 1280, 680);
 //   v->fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
   // scene->sceneRect(),Qt::KeepAspectRatio;
    v->show();
}





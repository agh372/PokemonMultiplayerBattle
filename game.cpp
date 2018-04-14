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
#include <QMovie>


Game::Game(SocketThread *t, QTimer *timer, QString player1Flag,QString player2Flag,int n)
{
    qDebug() << "Game Started ";
    this->t = t;
    scene = new QGraphicsScene();

    scene->setBackgroundBrush(QImage(":/Images/battle.png"));

    QGraphicsView *v = new QGraphicsView(scene);
    v->setFixedSize(716, 625);
    scene->setSceneRect(0, 0, 716, 620);
    //v->fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
   // scene->sceneRect(),Qt::KeepAspectRatio;
   // connect(t, SIGNAL(changeTurn()), this, SLOT(changeTurn()));

    p1 = new RealPlayer (t, scene, 1, player1Flag,player2Flag ,n);
  //  p2 = new RealPlayer (t, scene, 2, player2Flag,n);

    v->show();
}





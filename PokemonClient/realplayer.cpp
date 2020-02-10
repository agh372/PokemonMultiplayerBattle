#include "realplayer.h"
#include "player.h"
#include "QGraphicsScene"
#include "socketthread.h"
#include "mechanics.h"
#include <QFile>
#include <sstream>
#include <cstring>
#include <QTimer>
#include <QMovie>
#include <QPushButton>
#include <qprogressbar.h>
#include <utilmanager.h>

using namespace std;

RealPlayer::RealPlayer(SocketThread *thread, QGraphicsScene *s, int a, QString nameOfpokemon,QString nameOfpokemon2,int n)
{

    p = new Player(x1, y1, thread, a);
    p2 = new Player(x1, y1, thread, a);

    p->playerNum = 1;
    p2->playerNum = 2;


    Mechanics pokemonManager = Mechanics::instance();
    Pokemon* pokemon1 =  pokemonManager.initialize_player(nameOfpokemon);
    Pokemon* pokemon2 = pokemonManager.initialize_player(nameOfpokemon2);


    if(n == 2){
        player1Setting(nameOfpokemon,nameOfpokemon2,s,pokemon1);
    }else{
        player2Setting(nameOfpokemon,nameOfpokemon2,s,pokemon2);
    }
}

void RealPlayer::change(bool b)
{

}

//line
void RealPlayer::attack(int power)
{
SocketThread *thread;
UtilManager manager = UtilManager::instance();
thread = new SocketThread(manager.getIPAddress());
QString s = "" + power;
s.append(QChar(23));
thread->sendMess(s);
}



void RealPlayer::player1Setting(QString nameOfpokemon,QString nameOfpokemon2,QGraphicsScene *s,Pokemon* pokemon)
{

   qDebug() << "Player 1 ";
   QMovie* movie2 = new QMovie(":/pokemon/GIFs/"+nameOfpokemon2+"/"+nameOfpokemon2+".gif");
   p->setMovie(movie2);
   movie2->start();
   p->setGeometry(QRect(464, 204, 126, 126));
   p->setScaledContents( true );
   p->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
   p->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
   p->setAttribute(Qt::WA_TranslucentBackground);
   s->addWidget(p);

   QMovie* movie = new QMovie(":/pokemon/GIFs/"+nameOfpokemon+"/"+nameOfpokemon+"_back.gif");
   p2->setMovie(movie);
   movie->start();
   p2->setGeometry(QRect(160, 324, 126, 126));
   p2->setScaledContents( true );
   p2->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
   p2->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
   p2->setAttribute(Qt::WA_TranslucentBackground);
   s->addWidget(p2);

    for(int i= 0;i< pokemon->getAttacks().count();i++)
    {

    QPushButton* btnuser = new QPushButton();
    btnuser->setGeometry(QRect(160+((i%2)*300), 504+40*(i/2), 126, 36));
    btnuser->setText(pokemon->getAttacks()[i].name);
    QGraphicsProxyWidget *proxy = s->addWidget(btnuser);
//btnuser->setGeometry(QRect(160+(i*300), 544, 126, 36));
    }

        QProgressBar *statusProgressBar = new QProgressBar();
        statusProgressBar->setGeometry(160, 284, 126, 36);
        statusProgressBar->setTextVisible(false);
        s->addWidget(statusProgressBar);
        statusProgressBar->setValue(100);
        QGraphicsTextItem *text = s->addText("HP");
        text->setPos(160, 264);



        QProgressBar *statusProgressBar2 = new QProgressBar();
        statusProgressBar2->setGeometry(460, 144, 126, 36);
        statusProgressBar2->setTextVisible(false);
        s->addWidget(statusProgressBar2);
        statusProgressBar2->setValue(100);
        QGraphicsTextItem *text2 = s->addText("HP");
        text2->setPos(460, 124);

        QGraphicsTextItem *text3 = s->addText("Player 1");
        text3->setScale(3);
        text3->setPos(300, 24);

}



void RealPlayer::player2Setting(QString nameOfpokemon,QString nameOfpokemon2,QGraphicsScene *s,Pokemon* pokemon)
{

    QMovie* movie2 = new QMovie(":/pokemon/GIFs/"+nameOfpokemon+"/"+nameOfpokemon+".gif");
    p->setMovie(movie2);
    movie2->start();
    p->setGeometry(QRect(464, 204, 126, 126));
    p->setScaledContents( true );
    p->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    p->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    p->setAttribute(Qt::WA_TranslucentBackground);
    s->addWidget(p);

    QMovie* movie = new QMovie(":/pokemon/GIFs/"+nameOfpokemon2+"/"+nameOfpokemon2+"_back.gif");
    p2->setMovie(movie);
    movie->start();
    p2->setGeometry(QRect(160, 324, 126, 126));
    p2->setScaledContents( true );
    p2->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    p2->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    p2->setAttribute(Qt::WA_TranslucentBackground);
    s->addWidget(p2);

    for(int i= 0;i< pokemon->getAttacks().count();i++)
    {

    QPushButton* btnuser = new QPushButton();
    btnuser->setGeometry(QRect(160+((i%2)*300), 504+40*(i/2), 126, 36));
    btnuser->setText(pokemon->getAttacks()[i].name);
    QGraphicsProxyWidget *proxy = s->addWidget(btnuser);
    btnuser->setGeometry(QRect(160+(i*300), 544, 126, 36));
    QGraphicsTextItem *text = s->addText("Hello World");
    text->setPos(160, 304);

    }

    QProgressBar *statusProgressBar = new QProgressBar();
    statusProgressBar->setGeometry(160, 284, 126, 36);
    statusProgressBar->setTextVisible(false);
    s->addWidget(statusProgressBar);
    statusProgressBar->setValue(100);
    QGraphicsTextItem *text = s->addText("HP");
    text->setPos(160, 264);





    QProgressBar *statusProgressBar2 = new QProgressBar();
    statusProgressBar2->setGeometry(460, 144, 126, 36);
    statusProgressBar2->setTextVisible(false);
    s->addWidget(statusProgressBar2);
    statusProgressBar2->setValue(100);
    QGraphicsTextItem *text2 = s->addText("HP");
    text2->setPos(460, 124);


    QGraphicsTextItem *text3 = s->addText("Player 2");
    text3->setScale(3);
    text3->setPos(300, 24);


}


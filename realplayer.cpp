#include "realplayer.h"
#include "player.h"
#include "QGraphicsScene"
#include "socketthread.h"
#include <QFile>
#include <sstream>
#include <cstring>
#include <QTimer>
#include <QMovie>

using namespace std;

RealPlayer::RealPlayer(SocketThread *thread, QGraphicsScene *s, int a, QString nameOfpokemon,QString nameOfpokemon2,int n)
{

    p = new Player(x1, y1, thread, a);
    p2 = new Player(x1, y1, thread, a);

    p->playerNum = 1;
    p2->playerNum = 2;


    if(n == 2){
        player1Setting(nameOfpokemon,nameOfpokemon2,s);
    }else{
         player2Setting(nameOfpokemon,nameOfpokemon2,s);
    }

   // Pokemon pokemon1 = new Pokemon(;)
}

void RealPlayer::change(bool b)
{

}

//line
void RealPlayer::attack(Attack** attack)
{

}

//move
void RealPlayer::showAnimation(Pokemon pokemon)
{
}


void RealPlayer::player1Setting(QString nameOfpokemon,QString nameOfpokemon2,QGraphicsScene *s)
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
}



void RealPlayer::player2Setting(QString nameOfpokemon,QString nameOfpokemon2,QGraphicsScene *s)
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
}

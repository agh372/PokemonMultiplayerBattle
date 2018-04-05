#ifndef GAME_H
#define GAME_H


#include <QDebug>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QProgressBar>
#include "socketthread.h"
class Game : public QObject
{
    Q_OBJECT
   public:
       explicit Game(SocketThread *, QTimer *, QString,QString);

   private:
       QTimer *timer;
       QGraphicsScene *scene;
       int num;
       QProgressBar *bar1, *bar2;

   //private slots:
   //    void setTurn();
     //  void attack();
      // void playerN(int);
      // void changeTurn();
};

#endif // GAME_H

#ifndef REALPLAYER_H
#define REALPLAYER_H

#include "socketthread.h"
#include <QPropertyAnimation>
#include "QGraphicsScene"

 #include "pokemon.h"

using namespace std;

class RealPlayer
{

public:
        RealPlayer(SocketThread *, QGraphicsScene *, int, QString nameOfTeam);
        void change(bool);
       // Player *p[6];

private:
    int damage = 100;
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;

public:
    bool isMyTurn ;
    void attack(Attack**);
    void showAnimation(Pokemon);
};

#endif // REALPLAYER_H
#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QPen>
#include <QGraphicsLineItem>
#include <QPropertyAnimation>
#include <cmath>
#include <QObject>
#include "socketthread.h"

class Player : public QObject
{
    Q_OBJECT

public:

    explicit Player(double, double, SocketThread *thread, int number);

    //animation for pokemons

    int attack(){return 0;}
    void setMove(int);
    int playerNum, rPN;

    //mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *);
    double r;
    double fx, fy, vX, vY;
    void startAnimaion();
    QPropertyAnimation *animation;
    void movePlayer(double, double);
    void rePositioning();
    int  number, *changeTurn;
    bool changable;

private:
    int width, height;
    QGraphicsLineItem *line;
    QPen p1, p2, p3;
    SocketThread *thread;

//signals:


//private slots:

//public slots:
};

#endif // PLAYER_H

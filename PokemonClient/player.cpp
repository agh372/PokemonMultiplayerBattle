#include "player.h"
#include "socketthread.h"
#include "QGraphicsSceneMouseEvent"
#include <QDebug>
#include <stdlib.h>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <stdlib.h>
#include <cmath>
#include <QMediaPlayer>
#include "realplayer.h"
#include <QPropertyAnimation>

using namespace std;


Player::Player(double cxX, double cyY, SocketThread *thread, int number){
    this->rPN = number;
    this->thread = thread;
    this->vX = this->vY = 0;
    r = 35;
    width = 70; height = 77;//this may be changed...
    //line = new QGraphicsLineItem(0, 0, 0, 0, this);

}


void Player::setMove(int)
{

}

//when mouse release
void Player::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}

//when mouse is moving
void Player::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
        //send informations to server
}


//when server sends movePlayer Singnal
void Player::movePlayer(double a, double b)
{
    //this->setX(a);
    //this->setY(b);
}


//this is for starting animation
void Player::startAnimaion()
{
//
}

void Player::mousePressEvent(QGraphicsSceneMouseEvent *event)
{


}

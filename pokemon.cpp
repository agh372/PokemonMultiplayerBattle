#include "pokemon.h"
#include <string>

using namespace std;

Pokemon::Pokemon(QString name)
{
    this->name = name;
}

Pokemon::~Pokemon()
{

}

int Pokemon::getHP()
{
  return MAX_HP;
}

QVector<Attack> Pokemon::getAttacks()
{
  return attacksList;
}

int Pokemon::getDEF()
{
  return DEF;
}

int Pokemon::getSPATK()
{
  return SPATK;
}

int Pokemon::getSPDEF()
{
  return SPDEF;
}

int Pokemon::getSPEED()
{
  return SPEED;
}

void  Pokemon::setAttacks(QVector<Attack> attackList)
{

this->attacksList =attackList;
}

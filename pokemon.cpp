#include "pokemon.h"
#include <string>

Pokemon::Pokemon(std::string name)
{

}

Pokemon::~Pokemon()
{

}

int Pokemon::getHP()
{
  return MAX_HP;
}

int Pokemon::getATK()
{
  return ATK;
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

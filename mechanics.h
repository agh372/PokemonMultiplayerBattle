#include <string>
#include <map>
#include "pokemon.h"
#include <QVector>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtDebug>

enum class PokemonTypes
  {
    Grass,
    Fire,
    Water,
    Normal,
    Electric,
    Ground
  };

class Mechanics
{
private:
   Mechanics();
public:
   static Mechanics& instance()
   {
      static Mechanics INSTANCE;
      return INSTANCE;
   }

   ~Mechanics() { }
  static const enum type {ELECTRIC, FIRE, WATER, FLYING, GRASS, ROCK} ptype;


  QVector <QVector <int> > attackPercentageVector;
  int attack_perc[6][5] = { {1, 1, 1, 1,1}, {1, 1, 1, 1,1}, {1, 1, 1, 1,1}, {1, 1, 1, 1,1},{1, 1, 1, 1,1},{1, 1, 1, 1,1}};
  Pokemon* initialize_player(QString pokemon);
  //void applyDamage(Pokemon* pokemon1, Pokemon* pokemon2, Attack* attack);
  QJsonArray readJson(QString pokemonName);
};

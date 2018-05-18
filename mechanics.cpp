#include <string>
#include <map>
#include "mechanics.h"
#include "pokemon.h"
#include <QFile>





Mechanics::Mechanics()
{
//    for(int i = 0; i < 6; i++)
//    {
//        QVector<int> tempVector;

//        for(int j = 0; j < 6; j++)
//        {
//            tempVector.push_back(attackPercentageVector[i][j]);
//        }
//        attackPercentageVector.push_back(tempVector);
//    }
}


Pokemon* Mechanics::initialize_player(QString pokemonName)
{
   QJsonArray pokemonMoves = readJson(pokemonName);
    Pokemon* pokemon = new Pokemon(pokemonName);
    QVector<Attack> attackList;
    for(int i=0;i<pokemonMoves.count();i++)
    {
         Attack* attack = new Attack();
         attack->name =  pokemonMoves[i].toString();
         attackList.append(*attack);
    }
    pokemon->setAttacks(attackList);
    return pokemon;
}


//int Mechanics::applyDamage(Pokemon* pokemon1, Pokemon* pokemon2, Attack* attack)
//{


//}

QJsonArray Mechanics::readJson(QString pokemonName)
{
    QString val;
    QFile file("C:\\Users\\gurud\\Documents\\PokemonBattleSimulator\\pokemon.json");
   // file.setFileName("pokemon.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonValue value = sett2.value(QString(pokemonName));
     qDebug() << "JSON POK "+pokemonName;
    QJsonObject item = value.toObject();

   // QJsonValue subobj = item["description"];
    QJsonArray test = item["moves"].toArray();
    qDebug() << test[1].toString();
    return test;
}


#include <string>
#include <map>
#include "mechanics.h"
#include "pokemon.h"
#include <QFile>
#include <QJsonDocument>


Mechanics::Mechanics()
{
    for(int i = 0; i < 6; i++)
    {
        QVector<int> tempVector;

        for(int j = 0; j < 6; j++)
        {
            tempVector.push_back(attackPercentageVector[i][j]);
        }
        attackPercentageVector.push_back(tempVector);
    }
}


void Mechanics::initialize_player(Pokemon* pokemon)
{
    readJson();
 //   pokemon = new Pokemon();
    //pokemon->attacksList
}


//int Mechanics::applyDamage(Pokemon* pokemon1, Pokemon* pokemon2, Attack* attack)
//{


//}

void Mechanics::readJson()
{
    QString val;
    QFile file;
//    file.setFileName("test.json");
//    file.open(QIODevice::ReadOnly | QIODevice::Text);
//    val = file.readAll();
//    file.close();
//    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
//    QJsonObject sett2 = d.object();
//    QJsonValue value = sett2.value(QString("appName"));
//    QJsonObject item = value.toObject();
//    QJsonValue subobj = item["description"];
//    QJsonArray test = item["imp"].toArray();

}


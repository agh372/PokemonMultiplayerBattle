#include <string>
#include <map>
#include "pokemon.h"
#include <QVector>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QtDebug>

#include <string>

class UtilManager
{
private:
   UtilManager();
  QString ip;

public:
   static UtilManager& instance()
   {
      static UtilManager INSTANCE;
      return INSTANCE;
   }

   ~UtilManager() { }



   QString getIPAddress();
   void setIPAddress(QString ip);
};

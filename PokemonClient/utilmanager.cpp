#include "utilmanager.h"

   UtilManager::UtilManager()
   {

   }

   QString UtilManager::getIPAddress() {
      return this -> ip;
   }

   void UtilManager::setIPAddress(QString ip) {
      this -> ip = ip;
   }

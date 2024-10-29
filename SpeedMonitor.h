#include <iostream>
#include <random> 
#include <string>
#include "ILogger.h"
#include "IMessageCommunicator.h"
#include "ISpeedSensor.h"
using namespace std;



class SpeedMonitor{
    private : int _speedThreshold;
  
      public:
          SpeedMonitor(int speedThreshold): _speedThreshold{speedThreshold} {}
            int getSpeedThreshold() const{
                return this->_speedThreshold;
            }
            //Dependency Injection 
          void monitor(IMessageCommunicator* communicator,ISpeedSensor* sensor,ILogger* logger);
};

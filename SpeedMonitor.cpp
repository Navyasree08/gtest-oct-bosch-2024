#include "SpeedMonitor.h"
void SpeedMonitor::monitor(IMessageCommunicator* communicator,ISpeedSensor* sensor,ILogger* logger);{
            if(_speedThreshold  < 1 || _speedThreshold > 100){
              logger->write("_speedThreshold value must be in the ramge {1-100} " +to_string( _speedThreshold) + "\n";
            }
              
            
            int currentSpeedInKmph=sensor->getCurrentSpeed();
            
            logger->write("Current Speed In Kmph " + to_string(currentSpeedInKmph)+ "\n";
            if(currentSpeedInKmph > _speedThreshold){
                  double mph = currentSpeedInKmph * 0.621371;
                  string message="Current Speed in Miles "+ to_string(mph);
                 int statusCode= communicator->pushMessage(message);
                  if(statusCode > 400){
                      //Log Message to Console
                       logger->write("Error In Communication Unable to Contact Server " + message + "\n";
                  }
                 
            }
              
          }

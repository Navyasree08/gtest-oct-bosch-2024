#include "ISpeedSensor.h"
#include <random> 
#include <string>
using namespace std;

class BNFSpeedSensor{
        public:
            int   getCurrentSpeed(){
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> distr(1, 100);
                return distr(gen);
            }
};

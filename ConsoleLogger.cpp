#include "ILogger.h"
class ConsoleLogger:public ILogger{
    public:
    void write(const string& message){
      cout<<message;
    }
};

#ifndef TRIGGER_H
#define TRIGGER_H
#include <iostream>
#include <vector>
#include <string>

class Trigger {
public:
    Trigger( );
    virtual ~Trigger( );

    virtual std::string getCommand( void );
    virtual bool getReadyStatus( void );
    virtual std::string getMode( void );
    virtual int getTimesUsed( void );

    virtual void setCommand( std::string );
    virtual void setReady( bool );
    virtual void changeMode( std::string );
    virtual void incrTimesUsed( );

private:
    std::string command = "";
    std::string mode = "single"; // Default
    int times_used = 0;
    bool ready = false;
};

#endif /* TRIGGER_H */

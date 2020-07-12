
#ifndef REQUESTGENERATOR_HH
#define REQUESTGENERATOR_HH

#include "NVCPSProtocal.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtlogprotocol.hh"
#include "umlrtmessage.hh"
#include "umlrttimerprotocol.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

class Capsule_RequestGenerator : public UMLRTCapsule
{
public:
    Capsule_RequestGenerator( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
protected:
    NVCPSProtocal::Base clientPort;
public:
    enum BorderPortId
    {
        borderport_clientPort
    };
protected:
    UMLRTLogProtocol_baserole log;
    UMLRTTimerProtocol_baserole timer;
public:
    enum InternalPortId
    {
        internalport_timer,
        internalport_log
    };
    enum PartId
    {
    };
    enum PortId
    {
        port_clientPort,
        port_log,
        port_timer
    };
    virtual void bindPort( bool isBorder, int portId, int index );
    virtual void unbindPort( bool isBorder, int portId, int index );
    virtual void inject( const UMLRTMessage & message );
    virtual void initialize( const UMLRTMessage & message );
    const char * getCurrentStateString() const;
private:
    enum State
    {
        Generator,
        SPECIAL_INTERNAL_STATE_TOP,
        SPECIAL_INTERNAL_STATE_UNVISITED
    };
    const char * stateNames[3];
    State currentState;
    void update_state( State newState );
    void transitionaction_____transition1( const UMLRTMessage * msg );
    void actionchain_____transition0( const UMLRTMessage * msg );
    void actionchain_____transition1( const UMLRTMessage * msg );
    State state_____Generator( const UMLRTMessage * msg );
};
extern const UMLRTCapsuleClass RequestGenerator;

#endif


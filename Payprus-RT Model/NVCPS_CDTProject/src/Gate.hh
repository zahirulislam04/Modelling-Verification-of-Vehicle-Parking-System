
#ifndef GATE_HH
#define GATE_HH

#include "NVCPSProtocal.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtlogprotocol.hh"
#include "umlrtmessage.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

class Capsule_Gate : public UMLRTCapsule
{
public:
    Capsule_Gate( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
protected:
    UMLRTLogProtocol_baserole log;
    NVCPSProtocal::Base signalPort;
public:
    enum BorderPortId
    {
        borderport_signalPort
    };
    enum PartId
    {
    };
    enum PortId
    {
        port_log,
        port_signalPort
    };
    enum InternalPortId
    {
        internalport_log
    };
    virtual void bindPort( bool isBorder, int portId, int index );
    virtual void unbindPort( bool isBorder, int portId, int index );
    virtual void inject( const UMLRTMessage & message );
    virtual void initialize( const UMLRTMessage & message );
    const char * getCurrentStateString() const;
private:
    enum State
    {
        gate,
        SPECIAL_INTERNAL_STATE_TOP,
        SPECIAL_INTERNAL_STATE_UNVISITED
    };
    const char * stateNames[3];
    State currentState;
    void update_state( State newState );
    void entryaction_____gate( const UMLRTMessage * msg );
    void transitionaction_____transition1( const UMLRTMessage * msg );
    void actionchain_____Initial( const UMLRTMessage * msg );
    void actionchain_____transition1( const UMLRTMessage * msg );
    State state_____gate( const UMLRTMessage * msg );
};
extern const UMLRTCapsuleClass Gate;

#endif


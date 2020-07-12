
#ifndef PAYMENT_HH
#define PAYMENT_HH

#include "NVCPSProtocal.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtlogprotocol.hh"
#include "umlrtmessage.hh"
#include "umlrttimerprotocol.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

class Capsule_Payment : public UMLRTCapsule
{
public:
    Capsule_Payment( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
protected:
    NVCPSProtocal::Base PaymentPort;
public:
    enum BorderPortId
    {
        borderport_PaymentPort
    };
protected:
    NVCPSProtocal::Base internalPort;
public:
    enum InternalPortId
    {
        internalport_internalPort,
        internalport_timer,
        internalport_log
    };
protected:
    UMLRTLogProtocol_baserole log;
    UMLRTTimerProtocol_baserole timer;
public:
    enum PartId
    {
    };
    enum PortId
    {
        port_PaymentPort,
        port_internalPort,
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
        Payment,
        Payment__Discount,
        Payment__Payment,
        Payment__boundary,
        State1,
        SPECIAL_INTERNAL_STATE_TOP,
        SPECIAL_INTERNAL_STATE_UNVISITED
    };
    const char * stateNames[7];
    State currentState;
    State history[1];
    void save_history( State compositeState, State subState );
    bool check_history( State compositeState, State subState );
    void update_state( State newState );
    void entryaction_____Payment__Discount( const UMLRTMessage * msg );
    void entryaction_____Payment__Payment( const UMLRTMessage * msg );
    void entryaction_____State1( const UMLRTMessage * msg );
    void actionchain_____Initial( const UMLRTMessage * msg );
    void actionchain_____Payment__new_transition_1( const UMLRTMessage * msg );
    void actionchain_____Payment__new_transition_2( const UMLRTMessage * msg );
    void actionchain_____Payment__new_transition_3_to_unvisited_boundary( const UMLRTMessage * msg );
    void actionchain_____Payment__new_transition_4_to_visited_boundary( const UMLRTMessage * msg );
    void actionchain_____Payment__new_transition_5( const UMLRTMessage * msg );
    void actionchain_____Payment__new_transition_6( const UMLRTMessage * msg );
    void actionchain_____Payment__new_transition_7( const UMLRTMessage * msg );
    void actionchain_____Payment__transition0( const UMLRTMessage * msg );
    void actionchain_____Payment__transition1( const UMLRTMessage * msg );
    void actionchain_____Payment__transition2( const UMLRTMessage * msg );
    void actionchain_____transition1( const UMLRTMessage * msg );
    void actionchain_____transition2( const UMLRTMessage * msg );
    State junction_____Payment__connectionPoint0( const UMLRTMessage * msg );
    State junction_____Payment__connectionPoint2( const UMLRTMessage * msg );
    State choice_____Payment__deephistory( const UMLRTMessage * msg );
    State state_____Payment__Discount( const UMLRTMessage * msg );
    State state_____Payment__Payment( const UMLRTMessage * msg );
    State state_____Payment__boundary( const UMLRTMessage * msg );
    State state_____State1( const UMLRTMessage * msg );
};
extern const UMLRTCapsuleClass Payment;

#endif


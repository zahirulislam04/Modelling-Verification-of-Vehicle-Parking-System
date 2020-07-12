
#ifndef PARKINGCONTROLLER_HH
#define PARKINGCONTROLLER_HH

#include "NVCPSProtocal.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtlogprotocol.hh"
#include "umlrtmessage.hh"
#include "umlrttimerprotocol.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

class Capsule_ParkingController : public UMLRTCapsule
{
public:
    Capsule_ParkingController( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat );
protected:
    UMLRTLogProtocol_baserole log;
    NVCPSProtocal::Conj requestOutPort;
public:
    enum BorderPortId
    {
        borderport_requestOutPort
    };
protected:
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
        port_log,
        port_requestOutPort,
        port_timer
    };
    virtual void bindPort( bool isBorder, int portId, int index );
    virtual void unbindPort( bool isBorder, int portId, int index );
    int Slot2;
    int SlotCount;
    int Slot1;
    int Slot3;
    int UserType;
    int MembersCount;
    int GuestCount;
    int Slot4;
    int Slot5;
    int ExitSlotNum;
    int ExitUser;
    int R_type;
    virtual void inject( const UMLRTMessage & message );
    virtual void initialize( const UMLRTMessage & message );
    const char * getCurrentStateString() const;
private:
    enum State
    {
        ProcessPayment,
        ProcessUser,
        gate,
        Car_Exit,
        Entry,
        Exit,
        GetRequest,
        Park,
        ProcessPayment__Completed,
        ProcessPayment__Guest,
        ProcessPayment__Member,
        ProcessPayment__Payment,
        ProcessPayment__PaymentGuest,
        ProcessPayment__PaymentMember,
        ProcessPayment__boundary,
        ProcessUser__Guest,
        ProcessUser__Member,
        ProcessUser__Token,
        ProcessUser__User,
        ProcessUser__Valid,
        ProcessUser__boundary,
        ProcessUser__checkCompleted,
        ProcessUser__inValid,
        RequestCheck,
        RequestReceive,
        gate__Car_enter,
        gate__GateOpenEntry,
        gate__boundary,
        gate__gate,
        SPECIAL_INTERNAL_STATE_TOP,
        SPECIAL_INTERNAL_STATE_UNVISITED
    };
    const char * stateNames[31];
    State currentState;
    State history[3];
    void save_history( State compositeState, State subState );
    bool check_history( State compositeState, State subState );
    void update_state( State newState );
    void entryaction_____Car_Exit( const UMLRTMessage * msg );
    void entryaction_____Entry( const UMLRTMessage * msg );
    void entryaction_____Exit( const UMLRTMessage * msg );
    void entryaction_____GetRequest( const UMLRTMessage * msg );
    void entryaction_____Park( const UMLRTMessage * msg );
    void entryaction_____ProcessPayment__Completed( const UMLRTMessage * msg );
    void entryaction_____ProcessPayment__Guest( const UMLRTMessage * msg );
    void entryaction_____ProcessPayment__Member( const UMLRTMessage * msg );
    void entryaction_____ProcessPayment__Payment( const UMLRTMessage * msg );
    void entryaction_____ProcessPayment__PaymentGuest( const UMLRTMessage * msg );
    void entryaction_____ProcessPayment__PaymentMember( const UMLRTMessage * msg );
    void entryaction_____ProcessUser__Guest( const UMLRTMessage * msg );
    void entryaction_____ProcessUser__Member( const UMLRTMessage * msg );
    void entryaction_____ProcessUser__Token( const UMLRTMessage * msg );
    void entryaction_____ProcessUser__User( const UMLRTMessage * msg );
    void entryaction_____ProcessUser__Valid( const UMLRTMessage * msg );
    void entryaction_____ProcessUser__checkCompleted( const UMLRTMessage * msg );
    void entryaction_____ProcessUser__inValid( const UMLRTMessage * msg );
    void entryaction_____RequestCheck( const UMLRTMessage * msg );
    void entryaction_____RequestReceive( const UMLRTMessage * msg );
    void entryaction_____gate__Car_enter( const UMLRTMessage * msg );
    void entryaction_____gate__GateOpenEntry( const UMLRTMessage * msg );
    void entryaction_____gate__gate( const UMLRTMessage * msg );
    void transitionaction_____transition12( const UMLRTMessage * msg );
    bool guard_____ProcessPayment__transition2( const UMLRTMessage * msg );
    bool guard_____ProcessPayment__transition3( const UMLRTMessage * msg );
    bool guard_____ProcessUser__transition1( const UMLRTMessage * msg );
    bool guard_____ProcessUser__transition3( const UMLRTMessage * msg );
    bool guard_____transition0( const UMLRTMessage * msg );
    bool guard_____transition11( const UMLRTMessage * msg );
    bool guard_____transition15( const UMLRTMessage * msg );
    bool guard_____transition9( const UMLRTMessage * msg );
    void actionchain_____ProcessPayment__new_transition_10( const UMLRTMessage * msg );
    void actionchain_____ProcessPayment__new_transition_11( const UMLRTMessage * msg );
    void actionchain_____ProcessPayment__new_transition_12( const UMLRTMessage * msg );
    void actionchain_____ProcessPayment__new_transition_13( const UMLRTMessage * msg );
    void actionchain_____ProcessPayment__new_transition_14( const UMLRTMessage * msg );
    void actionchain_____ProcessPayment__new_transition_15( const UMLRTMessage * msg );
    void actionchain_____ProcessPayment__new_transition_16_to_unvisited_boundary( const UMLRTMessage * msg );
    void actionchain_____ProcessPayment__new_transition_17_to_visited_boundary( const UMLRTMessage * msg );
    void actionchain_____ProcessPayment__transition0( const UMLRTMessage * msg );
    void actionchain_____ProcessPayment__transition1( const UMLRTMessage * msg );
    void actionchain_____ProcessPayment__transition2( const UMLRTMessage * msg );
    void actionchain_____ProcessPayment__transition3( const UMLRTMessage * msg );
    void actionchain_____ProcessPayment__transition4( const UMLRTMessage * msg );
    void actionchain_____ProcessPayment__transition5( const UMLRTMessage * msg );
    void actionchain_____ProcessPayment__transition6( const UMLRTMessage * msg );
    void actionchain_____ProcessPayment__transition7( const UMLRTMessage * msg );
    void actionchain_____ProcessPayment__transition8( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__new_transition_1( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__new_transition_2( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__new_transition_3( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__new_transition_4( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__new_transition_5( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__new_transition_6( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__new_transition_7( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__new_transition_8_to_unvisited_boundary( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__new_transition_9_to_visited_boundary( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__transition0( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__transition1( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__transition10( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__transition11( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__transition2( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__transition3( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__transition4( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__transition5( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__transition6( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__transition7( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__transition8( const UMLRTMessage * msg );
    void actionchain_____ProcessUser__transition9( const UMLRTMessage * msg );
    void actionchain_____gate__new_transition_18( const UMLRTMessage * msg );
    void actionchain_____gate__new_transition_19( const UMLRTMessage * msg );
    void actionchain_____gate__new_transition_20( const UMLRTMessage * msg );
    void actionchain_____gate__new_transition_21_to_unvisited_boundary( const UMLRTMessage * msg );
    void actionchain_____gate__new_transition_22_to_visited_boundary( const UMLRTMessage * msg );
    void actionchain_____gate__transition0( const UMLRTMessage * msg );
    void actionchain_____gate__transition1( const UMLRTMessage * msg );
    void actionchain_____gate__transition2( const UMLRTMessage * msg );
    void actionchain_____gate__transition3( const UMLRTMessage * msg );
    void actionchain_____transition0( const UMLRTMessage * msg );
    void actionchain_____transition1( const UMLRTMessage * msg );
    void actionchain_____transition10( const UMLRTMessage * msg );
    void actionchain_____transition11( const UMLRTMessage * msg );
    void actionchain_____transition12( const UMLRTMessage * msg );
    void actionchain_____transition13( const UMLRTMessage * msg );
    void actionchain_____transition14( const UMLRTMessage * msg );
    void actionchain_____transition15( const UMLRTMessage * msg );
    void actionchain_____transition16( const UMLRTMessage * msg );
    void actionchain_____transition17( const UMLRTMessage * msg );
    void actionchain_____transition2( const UMLRTMessage * msg );
    void actionchain_____transition3( const UMLRTMessage * msg );
    void actionchain_____transition4( const UMLRTMessage * msg );
    void actionchain_____transition5( const UMLRTMessage * msg );
    void actionchain_____transition6( const UMLRTMessage * msg );
    void actionchain_____transition7( const UMLRTMessage * msg );
    void actionchain_____transition8( const UMLRTMessage * msg );
    void actionchain_____transition9( const UMLRTMessage * msg );
    State junction_____ProcessPayment__connectionPoint0( const UMLRTMessage * msg );
    State junction_____ProcessPayment__connectionPoint1( const UMLRTMessage * msg );
    State junction_____ProcessUser__connectionPoint0( const UMLRTMessage * msg );
    State junction_____ProcessUser__connectionPoint1( const UMLRTMessage * msg );
    State junction_____gate__connectionPoint0( const UMLRTMessage * msg );
    State junction_____gate__connectionPoint1( const UMLRTMessage * msg );
    State choice_____ProcessPayment__deephistory( const UMLRTMessage * msg );
    State choice_____ProcessPayment__subvertex1( const UMLRTMessage * msg );
    State choice_____ProcessUser__deephistory( const UMLRTMessage * msg );
    State choice_____ProcessUser__subvertex5( const UMLRTMessage * msg );
    State choice_____ProcessUser__subvertex6( const UMLRTMessage * msg );
    State choice_____R_Type_check( const UMLRTMessage * msg );
    State choice_____gate__deephistory( const UMLRTMessage * msg );
    State choice_____s_request_Choice( const UMLRTMessage * msg );
    State choice_____subvertex10( const UMLRTMessage * msg );
    State choice_____subvertex11( const UMLRTMessage * msg );
    State state_____Car_Exit( const UMLRTMessage * msg );
    State state_____Entry( const UMLRTMessage * msg );
    State state_____Exit( const UMLRTMessage * msg );
    State state_____GetRequest( const UMLRTMessage * msg );
    State state_____Park( const UMLRTMessage * msg );
    State state_____ProcessPayment__Completed( const UMLRTMessage * msg );
    State state_____ProcessPayment__Guest( const UMLRTMessage * msg );
    State state_____ProcessPayment__Member( const UMLRTMessage * msg );
    State state_____ProcessPayment__Payment( const UMLRTMessage * msg );
    State state_____ProcessPayment__PaymentGuest( const UMLRTMessage * msg );
    State state_____ProcessPayment__PaymentMember( const UMLRTMessage * msg );
    State state_____ProcessPayment__boundary( const UMLRTMessage * msg );
    State state_____ProcessUser__Guest( const UMLRTMessage * msg );
    State state_____ProcessUser__Member( const UMLRTMessage * msg );
    State state_____ProcessUser__Token( const UMLRTMessage * msg );
    State state_____ProcessUser__User( const UMLRTMessage * msg );
    State state_____ProcessUser__Valid( const UMLRTMessage * msg );
    State state_____ProcessUser__boundary( const UMLRTMessage * msg );
    State state_____ProcessUser__checkCompleted( const UMLRTMessage * msg );
    State state_____ProcessUser__inValid( const UMLRTMessage * msg );
    State state_____RequestCheck( const UMLRTMessage * msg );
    State state_____RequestReceive( const UMLRTMessage * msg );
    State state_____gate__Car_enter( const UMLRTMessage * msg );
    State state_____gate__GateOpenEntry( const UMLRTMessage * msg );
    State state_____gate__boundary( const UMLRTMessage * msg );
    State state_____gate__gate( const UMLRTMessage * msg );
};
extern const UMLRTCapsuleClass ParkingController;

#endif



#include "Payment.hh"

#include "NVCPSProtocal.hh"
#include "umlrtcommsportrole.hh"
#include "umlrtmessage.hh"
#include "umlrtslot.hh"
#include <cstddef>
#include "umlrtcapsuleclass.hh"
#include "umlrtframeservice.hh"
class UMLRTRtsInterface;
struct UMLRTCommsPort;

Capsule_Payment::Capsule_Payment( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, PaymentPort( borderPorts[borderport_PaymentPort] )
, internalPort( internalPorts[internalport_internalPort] )
, timer( internalPorts[internalport_timer] )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[Payment] = "Payment";
    stateNames[Payment__Discount] = "Payment__Discount";
    stateNames[Payment__Payment] = "Payment__Payment";
    stateNames[Payment__boundary] = "Payment__boundary";
    stateNames[State1] = "State1";
    stateNames[SPECIAL_INTERNAL_STATE_TOP] = "<top>";
    stateNames[SPECIAL_INTERNAL_STATE_UNVISITED] = "<uninitialized>";
    int i = 0;
    while( i < 1 )
        history[i++] = SPECIAL_INTERNAL_STATE_UNVISITED;
}









void Capsule_Payment::bindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_PaymentPort:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_PaymentPort, index, true );
            break;
        }
    else
        UMLRTFrameService::sendBoundUnbound( internalPorts, internalport_internalPort, index, true );
}

void Capsule_Payment::unbindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_PaymentPort:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_PaymentPort, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_PaymentPort], index );
            break;
        }
    else
    {
        UMLRTFrameService::sendBoundUnbound( internalPorts, internalport_internalPort, index, false );
        UMLRTFrameService::disconnectPort( internalPorts[internalport_internalPort], index );
    }
}

void Capsule_Payment::inject( const UMLRTMessage & message )
{
    msg = &message;
    switch( currentState )
    {
    case State1:
        currentState = state_____State1( &message );
        break;
    case Payment__Payment:
        currentState = state_____Payment__Payment( &message );
        break;
    case Payment__Discount:
        currentState = state_____Payment__Discount( &message );
        break;
    case Payment__boundary:
        currentState = state_____Payment__boundary( &message );
        break;
    default:
        break;
    }
}

void Capsule_Payment::initialize( const UMLRTMessage & message )
{
    msg = &message;
    actionchain_____Initial( &message );
    currentState = junction_____Payment__connectionPoint0( &message );
}

const char * Capsule_Payment::getCurrentStateString() const
{
    return stateNames[currentState];
}





void Capsule_Payment::save_history( Capsule_Payment::State compositeState, Capsule_Payment::State subState )
{
    history[compositeState] = subState;
}

bool Capsule_Payment::check_history( Capsule_Payment::State compositeState, Capsule_Payment::State subState )
{
    return history[compositeState] == subState;
}

void Capsule_Payment::update_state( Capsule_Payment::State newState )
{
    currentState = newState;
}

void Capsule_Payment::entryaction_____Payment__Discount( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::Payment::Payment::Discount entry  */
    log.show("\n- Membership will get 50 Percent discount -");
    PaymentPort.requestOut().send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Payment::entryaction_____Payment__Payment( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::Payment::Payment::Payment entry  */
    //timer.informIn(UMLRTTimespec(1,0));
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Payment::entryaction_____State1( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::Payment::State1 entry  */
    PaymentPort.requestOut().send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Payment::actionchain_____Initial( const UMLRTMessage * msg )
{
    update_state( Payment );
}

void Capsule_Payment::actionchain_____Payment__new_transition_1( const UMLRTMessage * msg )
{
    update_state( Payment__Payment );
    entryaction_____Payment__Payment( msg );
}

void Capsule_Payment::actionchain_____Payment__new_transition_2( const UMLRTMessage * msg )
{
    update_state( Payment__Discount );
    entryaction_____Payment__Discount( msg );
}

void Capsule_Payment::actionchain_____Payment__new_transition_3_to_unvisited_boundary( const UMLRTMessage * msg )
{
    update_state( Payment__boundary );
}

void Capsule_Payment::actionchain_____Payment__new_transition_4_to_visited_boundary( const UMLRTMessage * msg )
{
    update_state( Payment__boundary );
}

void Capsule_Payment::actionchain_____Payment__new_transition_5( const UMLRTMessage * msg )
{
    update_state( Payment );
    save_history( Payment, Payment__Payment );
}

void Capsule_Payment::actionchain_____Payment__new_transition_6( const UMLRTMessage * msg )
{
    update_state( Payment );
    save_history( Payment, Payment__Discount );
}

void Capsule_Payment::actionchain_____Payment__new_transition_7( const UMLRTMessage * msg )
{
    update_state( Payment );
    save_history( Payment, Payment__boundary );
}

void Capsule_Payment::actionchain_____Payment__transition0( const UMLRTMessage * msg )
{
    update_state( Payment );
    update_state( Payment__Discount );
    entryaction_____Payment__Discount( msg );
}

void Capsule_Payment::actionchain_____Payment__transition1( const UMLRTMessage * msg )
{
    update_state( Payment__Payment );
    entryaction_____Payment__Payment( msg );
}

void Capsule_Payment::actionchain_____Payment__transition2( const UMLRTMessage * msg )
{
    update_state( Payment );
}

void Capsule_Payment::actionchain_____transition1( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    update_state( State1 );
    entryaction_____State1( msg );
}

void Capsule_Payment::actionchain_____transition2( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    update_state( Payment );
}

Capsule_Payment::State Capsule_Payment::junction_____Payment__connectionPoint0( const UMLRTMessage * msg )
{
    actionchain_____Payment__transition1( msg );
    return Payment__Payment;
}

Capsule_Payment::State Capsule_Payment::junction_____Payment__connectionPoint2( const UMLRTMessage * msg )
{
    actionchain_____transition1( msg );
    return State1;
}

Capsule_Payment::State Capsule_Payment::choice_____Payment__deephistory( const UMLRTMessage * msg )
{
    if( check_history( Payment, Payment__Payment ) )
    {
        actionchain_____Payment__new_transition_1( msg );
        return Payment__Payment;
    }
    else if( check_history( Payment, Payment__Discount ) )
    {
        actionchain_____Payment__new_transition_2( msg );
        return Payment__Discount;
    }
    else if( check_history( Payment, SPECIAL_INTERNAL_STATE_UNVISITED ) )
    {
        actionchain_____Payment__new_transition_3_to_unvisited_boundary( msg );
        return Payment__boundary;
    }
    else if( check_history( Payment, Payment__boundary ) )
    {
        actionchain_____Payment__new_transition_4_to_visited_boundary( msg );
        return Payment__boundary;
    }
    return currentState;
}

Capsule_Payment::State Capsule_Payment::state_____Payment__Discount( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_internalPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestIn:
            actionchain_____Payment__transition2( msg );
            return choice_____Payment__deephistory( msg );
        default:
            this->unexpectedMessage();
            break;
        }
        return currentState;
    default:
        this->unexpectedMessage();
        break;
    }
    return currentState;
}

Capsule_Payment::State Capsule_Payment::state_____Payment__Payment( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_PaymentPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestIn:
            actionchain_____Payment__transition0( msg );
            return Payment__Discount;
        default:
            this->unexpectedMessage();
            break;
        }
        return currentState;
    default:
        this->unexpectedMessage();
        break;
    }
    return currentState;
}

Capsule_Payment::State Capsule_Payment::state_____Payment__boundary( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    default:
        this->unexpectedMessage();
        break;
    }
    return currentState;
}

Capsule_Payment::State Capsule_Payment::state_____State1( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_PaymentPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestIn:
            actionchain_____transition2( msg );
            return choice_____Payment__deephistory( msg );
        default:
            this->unexpectedMessage();
            break;
        }
        return currentState;
    default:
        this->unexpectedMessage();
        break;
    }
    return currentState;
}


static const UMLRTCommsPortRole portroles_border[] = 
{
    {
        Capsule_Payment::port_PaymentPort,
        "NVCPSProtocal",
        "PaymentPort",
        "",
        1,
        true,
        false,
        false,
        false,
        false,
        false,
        true
    }
};

static const UMLRTCommsPortRole portroles_internal[] = 
{
    {
        Capsule_Payment::port_internalPort,
        "NVCPSProtocal",
        "internalPort",
        "",
        1,
        true,
        false,
        false,
        false,
        false,
        false,
        true
    },
    {
        Capsule_Payment::port_timer,
        "Timing",
        "timer",
        "",
        0,
        false,
        false,
        false,
        false,
        true,
        false,
        false
    },
    {
        Capsule_Payment::port_log,
        "Log",
        "log",
        "",
        0,
        false,
        false,
        false,
        false,
        true,
        false,
        false
    }
};

static void instantiate_Payment( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    const UMLRTCommsPort * * internalPorts = UMLRTFrameService::createInternalPorts( slot, &Payment );
    slot->capsule = new Capsule_Payment( &Payment, slot, borderPorts, internalPorts, false );
}

const UMLRTCapsuleClass Payment = 
{
    "Payment",
    NULL,
    instantiate_Payment,
    0,
    NULL,
    1,
    portroles_border,
    3,
    portroles_internal
};


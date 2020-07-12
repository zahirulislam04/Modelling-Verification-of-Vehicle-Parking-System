
#include "Gate.hh"

#include "NVCPSProtocal.hh"
#include "umlrtcommsportrole.hh"
#include "umlrtmessage.hh"
#include "umlrtslot.hh"
#include <cstddef>
#include "umlrtcapsuleclass.hh"
#include "umlrtframeservice.hh"
class UMLRTRtsInterface;
struct UMLRTCommsPort;

Capsule_Gate::Capsule_Gate( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, signalPort( borderPorts[borderport_signalPort] )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[gate] = "gate";
    stateNames[SPECIAL_INTERNAL_STATE_TOP] = "<top>";
    stateNames[SPECIAL_INTERNAL_STATE_UNVISITED] = "<uninitialized>";
}







void Capsule_Gate::bindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_signalPort:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_signalPort, index, true );
            break;
        }
}

void Capsule_Gate::unbindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_signalPort:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_signalPort, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_signalPort], index );
            break;
        }
}

void Capsule_Gate::inject( const UMLRTMessage & message )
{
    msg = &message;
    switch( currentState )
    {
    case gate:
        currentState = state_____gate( &message );
        break;
    default:
        break;
    }
}

void Capsule_Gate::initialize( const UMLRTMessage & message )
{
    msg = &message;
    actionchain_____Initial( &message );
    currentState = gate;
}

const char * Capsule_Gate::getCurrentStateString() const
{
    return stateNames[currentState];
}




void Capsule_Gate::update_state( Capsule_Gate::State newState )
{
    currentState = newState;
}

void Capsule_Gate::entryaction_____gate( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::Gate::gate entry  */
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Gate::transitionaction_____transition1( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::Gate transition gate,gate,requestIn:signalPort */
    //log.show("\n-- randomNumber %d --\n",checkIn);
    signalPort.requestOut().send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Gate::actionchain_____Initial( const UMLRTMessage * msg )
{
    update_state( gate );
    entryaction_____gate( msg );
}

void Capsule_Gate::actionchain_____transition1( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition1( msg );
    update_state( gate );
    entryaction_____gate( msg );
}

Capsule_Gate::State Capsule_Gate::state_____gate( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_signalPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestIn:
            actionchain_____transition1( msg );
            return gate;
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
        Capsule_Gate::port_signalPort,
        "NVCPSProtocal",
        "signalPort",
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
        Capsule_Gate::port_log,
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

static void instantiate_Gate( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    const UMLRTCommsPort * * internalPorts = UMLRTFrameService::createInternalPorts( slot, &Gate );
    slot->capsule = new Capsule_Gate( &Gate, slot, borderPorts, internalPorts, false );
}

const UMLRTCapsuleClass Gate = 
{
    "Gate",
    NULL,
    instantiate_Gate,
    0,
    NULL,
    1,
    portroles_border,
    1,
    portroles_internal
};



#include "RequestGenerator.hh"

#include "NVCPSProtocal.hh"
#include "umlrtcommsportrole.hh"
#include "umlrtmessage.hh"
#include "umlrtslot.hh"
#include <cstddef>
#include "umlrtcapsuleclass.hh"
#include "umlrtframeservice.hh"
class UMLRTRtsInterface;
struct UMLRTCommsPort;

Capsule_RequestGenerator::Capsule_RequestGenerator( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, clientPort( borderPorts[borderport_clientPort] )
, timer( internalPorts[internalport_timer] )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[Generator] = "Generator";
    stateNames[SPECIAL_INTERNAL_STATE_TOP] = "<top>";
    stateNames[SPECIAL_INTERNAL_STATE_UNVISITED] = "<uninitialized>";
}








void Capsule_RequestGenerator::bindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_clientPort:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_clientPort, index, true );
            break;
        }
}

void Capsule_RequestGenerator::unbindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_clientPort:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_clientPort, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_clientPort], index );
            break;
        }
}

void Capsule_RequestGenerator::inject( const UMLRTMessage & message )
{
    msg = &message;
    switch( currentState )
    {
    case Generator:
        currentState = state_____Generator( &message );
        break;
    default:
        break;
    }
}

void Capsule_RequestGenerator::initialize( const UMLRTMessage & message )
{
    msg = &message;
    actionchain_____transition0( &message );
    currentState = Generator;
}

const char * Capsule_RequestGenerator::getCurrentStateString() const
{
    return stateNames[currentState];
}




void Capsule_RequestGenerator::update_state( Capsule_RequestGenerator::State newState )
{
    currentState = newState;
}

void Capsule_RequestGenerator::transitionaction_____transition1( const UMLRTMessage * msg )
{
    #define requestInpara ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::RequestGenerator transition Generator,Generator,reqInParameter:clientPort */
    //log.log("req val %d/n",requestInpara);
    clientPort.requestType(rand() % 2).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestInpara
}

void Capsule_RequestGenerator::actionchain_____transition0( const UMLRTMessage * msg )
{
    update_state( Generator );
}

void Capsule_RequestGenerator::actionchain_____transition1( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition1( msg );
    update_state( Generator );
}

Capsule_RequestGenerator::State Capsule_RequestGenerator::state_____Generator( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_clientPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_reqInParameter:
            actionchain_____transition1( msg );
            return Generator;
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
        Capsule_RequestGenerator::port_clientPort,
        "NVCPSProtocal",
        "clientPort",
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
        Capsule_RequestGenerator::port_timer,
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
        Capsule_RequestGenerator::port_log,
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

static void instantiate_RequestGenerator( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    const UMLRTCommsPort * * internalPorts = UMLRTFrameService::createInternalPorts( slot, &RequestGenerator );
    slot->capsule = new Capsule_RequestGenerator( &RequestGenerator, slot, borderPorts, internalPorts, false );
}

const UMLRTCapsuleClass RequestGenerator = 
{
    "RequestGenerator",
    NULL,
    instantiate_RequestGenerator,
    0,
    NULL,
    1,
    portroles_border,
    2,
    portroles_internal
};


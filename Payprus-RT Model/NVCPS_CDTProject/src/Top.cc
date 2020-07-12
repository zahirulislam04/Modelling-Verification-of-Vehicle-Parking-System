
#include "Top.hh"

#include "ParkingController.hh"
#include "RequestGenerator.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtcapsulepart.hh"
#include "umlrtslot.hh"
#include <cstddef>
#include "umlrtcapsulerole.hh"
#include "umlrtcommsport.hh"
#include "umlrtframeservice.hh"
class UMLRTRtsInterface;

Capsule_Top::Capsule_Top( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, Controller( &slot->parts[part_Controller] )
, Generator( &slot->parts[part_Generator] )
{
}




void Capsule_Top::bindPort( bool isBorder, int portId, int index )
{
}

void Capsule_Top::unbindPort( bool isBorder, int portId, int index )
{
}

void Capsule_Top::initialize( const UMLRTMessage & msg )
{
}

void Capsule_Top::inject( const UMLRTMessage & msg )
{
}


static const UMLRTCapsuleRole roles[] = 
{
    {
        "Controller",
        &ParkingController,
        1,
        1,
        false,
        false
    },
    {
        "Generator",
        &RequestGenerator,
        1,
        1,
        false,
        false
    }
};

static void instantiate_Top( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    UMLRTFrameService::connectPorts( &slot->parts[Capsule_Top::part_Controller].slots[0]->ports[Capsule_ParkingController::borderport_requestOutPort], 0, &slot->parts[Capsule_Top::part_Generator].slots[0]->ports[Capsule_RequestGenerator::borderport_clientPort], 0 );
    ParkingController.instantiate( NULL, slot->parts[Capsule_Top::part_Controller].slots[0], UMLRTFrameService::createBorderPorts( slot->parts[Capsule_Top::part_Controller].slots[0], ParkingController.numPortRolesBorder ) );
    RequestGenerator.instantiate( NULL, slot->parts[Capsule_Top::part_Generator].slots[0], UMLRTFrameService::createBorderPorts( slot->parts[Capsule_Top::part_Generator].slots[0], RequestGenerator.numPortRolesBorder ) );
    slot->capsule = new Capsule_Top( &Top, slot, borderPorts, NULL, false );
}

const UMLRTCapsuleClass Top = 
{
    "Top",
    NULL,
    instantiate_Top,
    2,
    roles,
    0,
    NULL,
    0,
    NULL
};


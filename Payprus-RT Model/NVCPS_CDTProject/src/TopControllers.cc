
#include "TopControllers.hh"

#include "ParkingController.hh"
#include "RequestGenerator.hh"
#include "Top.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtcapsulepart.hh"
#include "umlrtcommsport.hh"
#include "umlrtcommsportfarend.hh"
#include "umlrtcontroller.hh"
#include "umlrtslot.hh"
#include <cstddef>


static UMLRTController DefaultController_( "DefaultController" );

UMLRTController * DefaultController = &DefaultController_;

static Capsule_Top top( &Top, &Top_slots[InstId_Top], NULL, NULL, true );

static UMLRTSlot * slots_Top[] = 
{
    &Top_slots[InstId_Top_Controller],
    &Top_slots[InstId_Top_Generator]
};

static UMLRTCapsulePart parts_Top[] = 
{
    {
        &Top,
        Capsule_Top::part_Controller,
        1,
        &slots_Top[0]
    },
    {
        &Top,
        Capsule_Top::part_Generator,
        1,
        &slots_Top[1]
    }
};

static UMLRTCommsPortFarEnd borderfarEndList_Top_Controller[] = 
{
    {
        0,
        &borderports_Top_Generator[Capsule_RequestGenerator::borderport_clientPort]
    }
};

UMLRTCommsPort borderports_Top_Controller[] = 
{
    {
        &ParkingController,
        Capsule_ParkingController::borderport_requestOutPort,
        &Top_slots[InstId_Top_Controller],
        1,
        borderfarEndList_Top_Controller,
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        true
    }
};

static const UMLRTCommsPort * borderports_Top_Controller_ptrs[] = 
{
    &borderports_Top_Controller[0]
};

static UMLRTCommsPortFarEnd internalfarEndList_Top_Controller[] = 
{
    {
        0,
        NULL
    },
    {
        0,
        NULL
    }
};

UMLRTCommsPort internalports_Top_Controller[] = 
{
    {
        &ParkingController,
        Capsule_ParkingController::internalport_timer,
        &Top_slots[InstId_Top_Controller],
        1,
        &internalfarEndList_Top_Controller[1],
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    },
    {
        &ParkingController,
        Capsule_ParkingController::internalport_log,
        &Top_slots[InstId_Top_Controller],
        1,
        internalfarEndList_Top_Controller,
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    }
};

static const UMLRTCommsPort * internalports_Top_Controller_ptrs[] = 
{
    &internalports_Top_Controller[0],
    &internalports_Top_Controller[1]
};

static Capsule_ParkingController top_Controller( &ParkingController, &Top_slots[InstId_Top_Controller], borderports_Top_Controller_ptrs, internalports_Top_Controller_ptrs, true );

static UMLRTCommsPortFarEnd borderfarEndList_Top_Generator[] = 
{
    {
        0,
        &borderports_Top_Controller[Capsule_ParkingController::borderport_requestOutPort]
    }
};

UMLRTCommsPort borderports_Top_Generator[] = 
{
    {
        &RequestGenerator,
        Capsule_RequestGenerator::borderport_clientPort,
        &Top_slots[InstId_Top_Generator],
        1,
        borderfarEndList_Top_Generator,
        NULL,
        NULL,
        "",
        true,
        true,
        true,
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        true
    }
};

static const UMLRTCommsPort * borderports_Top_Generator_ptrs[] = 
{
    &borderports_Top_Generator[0]
};

static UMLRTCommsPortFarEnd internalfarEndList_Top_Generator[] = 
{
    {
        0,
        NULL
    },
    {
        0,
        NULL
    }
};

UMLRTCommsPort internalports_Top_Generator[] = 
{
    {
        &RequestGenerator,
        Capsule_RequestGenerator::internalport_log,
        &Top_slots[InstId_Top_Generator],
        1,
        internalfarEndList_Top_Generator,
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    },
    {
        &RequestGenerator,
        Capsule_RequestGenerator::internalport_timer,
        &Top_slots[InstId_Top_Generator],
        1,
        &internalfarEndList_Top_Generator[1],
        NULL,
        NULL,
        "",
        true,
        false,
        true,
        false,
        false,
        false,
        false,
        true,
        false,
        false,
        false
    }
};

static const UMLRTCommsPort * internalports_Top_Generator_ptrs[] = 
{
    &internalports_Top_Generator[0],
    &internalports_Top_Generator[1]
};

static Capsule_RequestGenerator top_Generator( &RequestGenerator, &Top_slots[InstId_Top_Generator], borderports_Top_Generator_ptrs, internalports_Top_Generator_ptrs, true );

UMLRTSlot Top_slots[] = 
{
    {
        "Top",
        0,
        &Top,
        NULL,
        0,
        &top,
        &DefaultController_,
        2,
        parts_Top,
        0,
        NULL,
        NULL,
        true,
        false
    },
    {
        "Top.Controller",
        0,
        &ParkingController,
        &Top,
        Capsule_Top::part_Controller,
        &top_Controller,
        &DefaultController_,
        0,
        NULL,
        1,
        borderports_Top_Controller,
        NULL,
        true,
        false
    },
    {
        "Top.Generator",
        0,
        &RequestGenerator,
        &Top,
        Capsule_Top::part_Generator,
        &top_Generator,
        &DefaultController_,
        0,
        NULL,
        1,
        borderports_Top_Generator,
        NULL,
        true,
        false
    }
};


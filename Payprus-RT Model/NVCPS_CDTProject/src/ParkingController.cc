
#include "ParkingController.hh"

#include "NVCPSProtocal.hh"
#include "umlrtcommsportrole.hh"
#include "umlrtmessage.hh"
#include "umlrtslot.hh"
#include "umlrttimerprotocol.hh"
#include <cstddef>
#include "umlrtcapsuleclass.hh"
#include "umlrtframeservice.hh"
class UMLRTRtsInterface;
struct UMLRTCommsPort;

Capsule_ParkingController::Capsule_ParkingController( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, requestOutPort( borderPorts[borderport_requestOutPort] )
, timer( internalPorts[internalport_timer] )
, Slot2( 0 )
, SlotCount( 5 )
, Slot1( 0 )
, Slot3( 0 )
, UserType( 0 )
, MembersCount( 0 )
, GuestCount( 0 )
, Slot4( 0 )
, Slot5( 0 )
, ExitSlotNum( 0 )
, ExitUser( 0 )
, R_type( 0 )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[ProcessPayment] = "ProcessPayment";
    stateNames[ProcessUser] = "ProcessUser";
    stateNames[gate] = "gate";
    stateNames[Car_Exit] = "Car_Exit";
    stateNames[Entry] = "Entry";
    stateNames[Exit] = "Exit";
    stateNames[GetRequest] = "GetRequest";
    stateNames[Park] = "Park";
    stateNames[ProcessPayment__Completed] = "ProcessPayment__Completed";
    stateNames[ProcessPayment__Guest] = "ProcessPayment__Guest";
    stateNames[ProcessPayment__Member] = "ProcessPayment__Member";
    stateNames[ProcessPayment__Payment] = "ProcessPayment__Payment";
    stateNames[ProcessPayment__PaymentGuest] = "ProcessPayment__PaymentGuest";
    stateNames[ProcessPayment__PaymentMember] = "ProcessPayment__PaymentMember";
    stateNames[ProcessPayment__boundary] = "ProcessPayment__boundary";
    stateNames[ProcessUser__Guest] = "ProcessUser__Guest";
    stateNames[ProcessUser__Member] = "ProcessUser__Member";
    stateNames[ProcessUser__Token] = "ProcessUser__Token";
    stateNames[ProcessUser__User] = "ProcessUser__User";
    stateNames[ProcessUser__Valid] = "ProcessUser__Valid";
    stateNames[ProcessUser__boundary] = "ProcessUser__boundary";
    stateNames[ProcessUser__checkCompleted] = "ProcessUser__checkCompleted";
    stateNames[ProcessUser__inValid] = "ProcessUser__inValid";
    stateNames[RequestCheck] = "RequestCheck";
    stateNames[RequestReceive] = "RequestReceive";
    stateNames[gate__Car_enter] = "gate__Car_enter";
    stateNames[gate__GateOpenEntry] = "gate__GateOpenEntry";
    stateNames[gate__boundary] = "gate__boundary";
    stateNames[gate__gate] = "gate__gate";
    stateNames[SPECIAL_INTERNAL_STATE_TOP] = "<top>";
    stateNames[SPECIAL_INTERNAL_STATE_UNVISITED] = "<uninitialized>";
    int i = 0;
    while( i < 3 )
        history[i++] = SPECIAL_INTERNAL_STATE_UNVISITED;
}








void Capsule_ParkingController::bindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_requestOutPort:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_requestOutPort, index, true );
            break;
        }
}

void Capsule_ParkingController::unbindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_requestOutPort:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_requestOutPort, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_requestOutPort], index );
            break;
        }
}













void Capsule_ParkingController::inject( const UMLRTMessage & message )
{
    msg = &message;
    switch( currentState )
    {
    case Entry:
        currentState = state_____Entry( &message );
        break;
    case Exit:
        currentState = state_____Exit( &message );
        break;
    case Park:
        currentState = state_____Park( &message );
        break;
    case GetRequest:
        currentState = state_____GetRequest( &message );
        break;
    case Car_Exit:
        currentState = state_____Car_Exit( &message );
        break;
    case RequestReceive:
        currentState = state_____RequestReceive( &message );
        break;
    case RequestCheck:
        currentState = state_____RequestCheck( &message );
        break;
    case ProcessUser__Member:
        currentState = state_____ProcessUser__Member( &message );
        break;
    case ProcessUser__Guest:
        currentState = state_____ProcessUser__Guest( &message );
        break;
    case ProcessUser__Valid:
        currentState = state_____ProcessUser__Valid( &message );
        break;
    case ProcessUser__inValid:
        currentState = state_____ProcessUser__inValid( &message );
        break;
    case ProcessUser__Token:
        currentState = state_____ProcessUser__Token( &message );
        break;
    case ProcessUser__checkCompleted:
        currentState = state_____ProcessUser__checkCompleted( &message );
        break;
    case ProcessUser__User:
        currentState = state_____ProcessUser__User( &message );
        break;
    case ProcessUser__boundary:
        currentState = state_____ProcessUser__boundary( &message );
        break;
    case ProcessPayment__Payment:
        currentState = state_____ProcessPayment__Payment( &message );
        break;
    case ProcessPayment__Member:
        currentState = state_____ProcessPayment__Member( &message );
        break;
    case ProcessPayment__Completed:
        currentState = state_____ProcessPayment__Completed( &message );
        break;
    case ProcessPayment__PaymentGuest:
        currentState = state_____ProcessPayment__PaymentGuest( &message );
        break;
    case ProcessPayment__PaymentMember:
        currentState = state_____ProcessPayment__PaymentMember( &message );
        break;
    case ProcessPayment__Guest:
        currentState = state_____ProcessPayment__Guest( &message );
        break;
    case ProcessPayment__boundary:
        currentState = state_____ProcessPayment__boundary( &message );
        break;
    case gate__gate:
        currentState = state_____gate__gate( &message );
        break;
    case gate__GateOpenEntry:
        currentState = state_____gate__GateOpenEntry( &message );
        break;
    case gate__Car_enter:
        currentState = state_____gate__Car_enter( &message );
        break;
    case gate__boundary:
        currentState = state_____gate__boundary( &message );
        break;
    default:
        break;
    }
}

void Capsule_ParkingController::initialize( const UMLRTMessage & message )
{
    msg = &message;
    actionchain_____transition2( &message );
    currentState = GetRequest;
}

const char * Capsule_ParkingController::getCurrentStateString() const
{
    return stateNames[currentState];
}





void Capsule_ParkingController::save_history( Capsule_ParkingController::State compositeState, Capsule_ParkingController::State subState )
{
    history[compositeState] = subState;
}

bool Capsule_ParkingController::check_history( Capsule_ParkingController::State compositeState, Capsule_ParkingController::State subState )
{
    return history[compositeState] == subState;
}

void Capsule_ParkingController::update_state( Capsule_ParkingController::State newState )
{
    currentState = newState;
}

void Capsule_ParkingController::entryaction_____Car_Exit( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::Car Exit entry  */
    this->SlotCount++;
    log.log("- Car Exit -");
    log.log("\n-**** Final Update******-");
    log.show("\n-- Member : %d \n-- Guest :  %d \n",MembersCount,GuestCount) ;   
    log.show("-- Slot1= %d--\n",Slot1);
    log.show("-- Slot2= %d--\n",Slot2);
    log.show("-- Slot3= %d--\n",Slot3);
    log.show("-- Slot4= %d--\n",Slot4);
    log.show("-- Slot5= %d--\n",Slot5);
    log.show("\n--  Empty : **0  Member : **1 , Guest :  **2 \n") ;
    //dataPass.requestIn().send();
    requestOutPort.reqInParameter(0).send();
    log.log("-**** Process is completed******-");
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_ParkingController::entryaction_____Entry( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::Entry entry  */
    log.log("- Request : Entry -");
    //dataPass.requestIn().send();
    requestOutPort.reqInParameter(0).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_ParkingController::entryaction_____Exit( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::Exit entry  */
    log.log("- Request : Exit -");
    //dataPass.requestIn().send();
    requestOutPort.reqInParameter(0).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_ParkingController::entryaction_____GetRequest( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::GetRequest entry  */
    requestOutPort.reqInParameter(2).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_ParkingController::entryaction_____Park( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::Park entry  */
    log.log("- Car is Parked -");
    //dataPass.requestIn().send();
    requestOutPort.reqInParameter(0).send();
    this->SlotCount--;
    int randomValue;  
    int toogle;
    toogle = 0;
    while(toogle==0){
    randomValue = rand() %5 + 1;
    if ( randomValue == 1 && Slot1 == 0){       
    this->Slot1 =  UserType;

    if(UserType==1)
    log.show("-- Slot1 filled with Member --\n");
    else if(UserType==2)
    log.show("-- Slot1 filled with Guest --\n");
    toogle = 1;
    }
    if (randomValue == 2 && Slot2 == 0){

    this->Slot2 =  UserType;

    if(UserType==1)
    log.show("-- Slot2 filled with Member --\n");
    else if(UserType==2)
    log.show("-- Slot2 filled with Guest --\n");
    toogle = 1;

    }
    if (randomValue == 3 && Slot3 == 0){            
    this->Slot3 =  UserType;

    if(UserType==1)
    log.show("-- Slots3 filled with Member --\n");
    else if(UserType==2)
    log.show("-- Slot3 filled with Guest --\n");
    toogle = 1; 
    }
    if ( randomValue == 4 && Slot4 == 0){       
    this->Slot4 =  UserType;

    if(UserType==1)
    log.show("-- Slots4 filled with Member --\n");
    else if(UserType==2)
    log.show("-- Slot4 filled with Guest --\n");
    toogle = 1;
    }
    if (randomValue == 5 && Slot5 == 0){       
    this->Slot5 =  UserType;

    if(UserType==1)
    log.show("-- Slots5 filled with Member --\n");
    else if(UserType==2)
    log.show("-- Slott5 filled with Guest --\n");
    toogle = 1;
    }
    }
    log.log("\n-**** Final Update******-");
    log.show("\n-- Member : %d \n-- Guest :  %d \n",MembersCount,GuestCount) ;

    log.show("-- Slot1= %d--\n",Slot1);
    log.show("-- Slot2= %d--\n",Slot2);
    log.show("-- Slot3= %d--\n",Slot3);
    log.show("-- Slot4= %d--\n",Slot4);
    log.show("-- Slot5= %d--\n",Slot5);
    log.show("\n--  Empty : **0  Member : **1 , Guest :  **2 \n") ;
    log.log("-**** Process is completed******-");
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_ParkingController::entryaction_____ProcessPayment__Completed( const UMLRTMessage * msg )
{
    #define requestType ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::ProcessPayment::Completed entry  */
    log.log("- Payment received -");
    timer.informIn(UMLRTTimespec(3,0));
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestType
}

void Capsule_ParkingController::entryaction_____ProcessPayment__Guest( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::ProcessPayment::Guest entry  */
    log.log("- Event : Exit from slot %d", ExitSlotNum);
    log.log("- User : Guest");
    this->GuestCount--;
    //dataPass.requestIn().send();
    requestOutPort.reqInParameter(0).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_ParkingController::entryaction_____ProcessPayment__Member( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::ProcessPayment::Member entry  */
    log.log("- Event : Exit from slot %d", ExitSlotNum);
    log.log("- User : Member");
    this->MembersCount--;
    //dataPass.requestIn().send();
    requestOutPort.reqInParameter(0).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_ParkingController::entryaction_____ProcessPayment__Payment( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::ProcessPayment::Payment entry  */
    //log.log("- User at the Exit Point -");
    int randomValue;

    int toogle;
    toogle = 0;

    while(toogle==0){
    randomValue = rand() %5 + 1;
    if ( randomValue == 1 && Slot1 > 0) {

    this->ExitSlotNum = randomValue ;    
    toogle = 1;     
    this->ExitUser = Slot1;        
    this->Slot1 =  0;       
    }
    else if ( randomValue == 2 && Slot2 > 0){
    this->ExitSlotNum = randomValue ;    
    toogle = 1;     
    this->ExitUser = Slot2;     
    this->Slot2 =  0; 
    }
    else if ( randomValue == 3 && Slot3 >0 ){
    this->ExitSlotNum = randomValue ;    
    toogle = 1;     
    this->ExitUser = Slot3;
    this->Slot3 =  0; 
    }
    else if ( randomValue == 4 && Slot4 > 0){
    this->ExitSlotNum = randomValue ;    
    toogle = 1;     
    this->ExitUser = Slot4;     
    this->Slot4 =  0;
    }
    else if  ( randomValue == 5 && Slot5 >0 ){
    this->ExitSlotNum = randomValue ;    
    toogle = 1;     
    this->ExitUser = Slot5;
    this->Slot5 =  0; 
    }
    }
    //dataPass.requestIn().send();
    requestOutPort.reqInParameter(0).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_ParkingController::entryaction_____ProcessPayment__PaymentGuest( const UMLRTMessage * msg )
{
    #define requestType ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::ProcessPayment::PaymentGuest entry  */
    log.log("\n- Final Payment amount ***Euro -");
    this->UserType=2;
    //dataPass.requestIn().send();
    requestOutPort.reqInParameter(0).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestType
}

void Capsule_ParkingController::entryaction_____ProcessPayment__PaymentMember( const UMLRTMessage * msg )
{
    #define requestType ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::ProcessPayment::PaymentMember entry  */
    log.log("- MemberShip discount payment is calculated -");
    log.log("\n- Final Payment amount ***Euro -");
    this->UserType=1;
    //dataPass.requestIn().send();
    requestOutPort.reqInParameter(0).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestType
}

void Capsule_ParkingController::entryaction_____ProcessUser__Guest( const UMLRTMessage * msg )
{
    #define requestType ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::ProcessUser::Guest entry  */
    log.log("- User : Guest ");
    //requestOutPort.requestIn().send();
    //dataPass.requestIn().send();
    requestOutPort.reqInParameter(0).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestType
}

void Capsule_ParkingController::entryaction_____ProcessUser__Member( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::ProcessUser::Member entry  */
    log.log("- User : Member ");
    //requestOutPort.requestIn().send();
    //dataPass.requestIn().send();
    requestOutPort.reqInParameter(0).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_ParkingController::entryaction_____ProcessUser__Token( const UMLRTMessage * msg )
{
    #define requestType ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::ProcessUser::Token entry  */
    log.log("- Token is generated for Guest -");
    //dataPass.requestIn().send();
    requestOutPort.reqInParameter(0).send();
    this->GuestCount++;
    this->UserType=2;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestType
}

void Capsule_ParkingController::entryaction_____ProcessUser__User( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::ProcessUser::User entry  */
    //log.show("\n- User ->");
    //dataPass.requestIn().send();
    //requestOutPort.requestIn().send();
    requestOutPort.reqInParameter(0).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_ParkingController::entryaction_____ProcessUser__Valid( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::ProcessUser::Valid entry  */
    log.log("- User is Valid Member -");
    //dataPass.requestIn().send();
    requestOutPort.reqInParameter(0).send();
    this->MembersCount++;
    this->UserType=1;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_ParkingController::entryaction_____ProcessUser__checkCompleted( const UMLRTMessage * msg )
{
    #define requestType ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::ProcessUser::checkCompleted entry  */
    //log.show("- Check completed -->\n");
    //dataPass.requestIn().send();
    timer.informIn(UMLRTTimespec(3,0));
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestType
}

void Capsule_ParkingController::entryaction_____ProcessUser__inValid( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::ProcessUser::inValid entry  */
    log.log("- User is not a Valid Member -");
    //requestOutPort.requestIn().send();
    //dataPass.requestIn().send();
    requestOutPort.reqInParameter(0).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_ParkingController::entryaction_____RequestCheck( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::RequestCheck entry  */
    log.show("\n-Number of slots available for Parking %d --\n",SlotCount);
    requestOutPort.reqInParameter(0).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_ParkingController::entryaction_____RequestReceive( const UMLRTMessage * msg )
{
    #define requestType ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::RequestReceive entry  */
    this->R_type = requestType;
    //dataPass.requestIn().send();
    if(requestType==1){

    if(SlotCount>0){
    this->R_type = requestType;
    }
    else
    {
    this->R_type = 2;

    }
    }
    else if (requestType==0){
    if(SlotCount<5 && SlotCount>=0){
    this->R_type = requestType;
    }
    else
    {
    this->R_type = 2;
    }
    }

    requestOutPort.reqInParameter(9).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestType
}

void Capsule_ParkingController::entryaction_____gate__Car_enter( const UMLRTMessage * msg )
{
    #define requestType ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::gate::Car enter entry  */
    //log.show("- Gate close ->\n");
    //requestOutPort.requestIn().send();
    //dataPass.requestIn().send();
    timer.informIn(UMLRTTimespec(3,0));
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestType
}

void Capsule_ParkingController::entryaction_____gate__GateOpenEntry( const UMLRTMessage * msg )
{
    #define requestType ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::gate::GateOpenEntry entry  */
    log.log("- Gate is Opened -");
    //requestOutPort.requestIn().send();
    //dataPass.requestIn().send();
    requestOutPort.reqInParameter(0).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestType
}

void Capsule_ParkingController::entryaction_____gate__gate( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::gate::gate entry  */
    //log.log("- Car is innfront of the gate -");
    //requestOutPort.requestIn().send();
    //dataPass.requestIn().send();
    requestOutPort.reqInParameter(0).send();
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_ParkingController::transitionaction_____transition12( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController transition subvertex11,GetRequest */
    //log.log("- Request :Exit -");
    log.show("\n-- There is no car in this Parking area, so *No Exit possible*  --\n");
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

bool Capsule_ParkingController::guard_____ProcessPayment__transition2( const UMLRTMessage * msg )
{
    #define requestType ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::ProcessPayment guard ProcessPayment::subvertex1,ProcessPayment::Member */
    return ExitUser==1;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestType
}

bool Capsule_ParkingController::guard_____ProcessPayment__transition3( const UMLRTMessage * msg )
{
    #define requestType ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::ProcessPayment guard ProcessPayment::subvertex1,ProcessPayment::Guest */
    return ExitUser==2;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestType
}

bool Capsule_ParkingController::guard_____ProcessUser__transition1( const UMLRTMessage * msg )
{
    #define requestType ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::ProcessUser guard ProcessUser::subvertex5,ProcessUser::Member */
    return rand() % 2==1;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestType
}

bool Capsule_ParkingController::guard_____ProcessUser__transition3( const UMLRTMessage * msg )
{
    #define requestType ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController::ProcessUser guard ProcessUser::subvertex6,ProcessUser::Valid */
    return rand() % 2==1;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestType
}

bool Capsule_ParkingController::guard_____transition0( const UMLRTMessage * msg )
{
    #define requestType ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController guard R_Type_check,Entry */
    return  R_type==1;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestType
}

bool Capsule_ParkingController::guard_____transition11( const UMLRTMessage * msg )
{
    #define requestType ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController guard subvertex11,ProcessPayment::connectionPoint0 */
    return (SlotCount<5 && SlotCount>=0);
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestType
}

bool Capsule_ParkingController::guard_____transition15( const UMLRTMessage * msg )
{
    #define requestType ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController guard s_request_Choice,RequestCheck */
    return R_type==1 || R_type==0 ;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestType
}

bool Capsule_ParkingController::guard_____transition9( const UMLRTMessage * msg )
{
    #define requestType ( *(int *)msg->getParam( 0 ) )
    #define rtdata ( (int *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/NVCPS/NVCPS/NVCPS.uml NVCPS::ParkingController guard subvertex10,ProcessUser::connectionPoint0 */
    return SlotCount>0;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
    #undef requestType
}

void Capsule_ParkingController::actionchain_____ProcessPayment__new_transition_10( const UMLRTMessage * msg )
{
    update_state( ProcessPayment__Payment );
    entryaction_____ProcessPayment__Payment( msg );
}

void Capsule_ParkingController::actionchain_____ProcessPayment__new_transition_11( const UMLRTMessage * msg )
{
    update_state( ProcessPayment__Member );
    entryaction_____ProcessPayment__Member( msg );
}

void Capsule_ParkingController::actionchain_____ProcessPayment__new_transition_12( const UMLRTMessage * msg )
{
    update_state( ProcessPayment__Completed );
    entryaction_____ProcessPayment__Completed( msg );
}

void Capsule_ParkingController::actionchain_____ProcessPayment__new_transition_13( const UMLRTMessage * msg )
{
    update_state( ProcessPayment__PaymentGuest );
    entryaction_____ProcessPayment__PaymentGuest( msg );
}

void Capsule_ParkingController::actionchain_____ProcessPayment__new_transition_14( const UMLRTMessage * msg )
{
    update_state( ProcessPayment__PaymentMember );
    entryaction_____ProcessPayment__PaymentMember( msg );
}

void Capsule_ParkingController::actionchain_____ProcessPayment__new_transition_15( const UMLRTMessage * msg )
{
    update_state( ProcessPayment__Guest );
    entryaction_____ProcessPayment__Guest( msg );
}

void Capsule_ParkingController::actionchain_____ProcessPayment__new_transition_16_to_unvisited_boundary( const UMLRTMessage * msg )
{
    update_state( ProcessPayment__boundary );
}

void Capsule_ParkingController::actionchain_____ProcessPayment__new_transition_17_to_visited_boundary( const UMLRTMessage * msg )
{
    update_state( ProcessPayment__boundary );
}

void Capsule_ParkingController::actionchain_____ProcessPayment__transition0( const UMLRTMessage * msg )
{
    update_state( ProcessPayment__Payment );
    entryaction_____ProcessPayment__Payment( msg );
}

void Capsule_ParkingController::actionchain_____ProcessPayment__transition1( const UMLRTMessage * msg )
{
    update_state( ProcessPayment );
}

void Capsule_ParkingController::actionchain_____ProcessPayment__transition2( const UMLRTMessage * msg )
{
    update_state( ProcessPayment__Member );
    entryaction_____ProcessPayment__Member( msg );
}

void Capsule_ParkingController::actionchain_____ProcessPayment__transition3( const UMLRTMessage * msg )
{
    update_state( ProcessPayment__Guest );
    entryaction_____ProcessPayment__Guest( msg );
}

void Capsule_ParkingController::actionchain_____ProcessPayment__transition4( const UMLRTMessage * msg )
{
    update_state( ProcessPayment );
    update_state( ProcessPayment__PaymentMember );
    entryaction_____ProcessPayment__PaymentMember( msg );
}

void Capsule_ParkingController::actionchain_____ProcessPayment__transition5( const UMLRTMessage * msg )
{
    update_state( ProcessPayment );
    update_state( ProcessPayment__PaymentGuest );
    entryaction_____ProcessPayment__PaymentGuest( msg );
}

void Capsule_ParkingController::actionchain_____ProcessPayment__transition6( const UMLRTMessage * msg )
{
    update_state( ProcessPayment );
    update_state( ProcessPayment__Completed );
    entryaction_____ProcessPayment__Completed( msg );
}

void Capsule_ParkingController::actionchain_____ProcessPayment__transition7( const UMLRTMessage * msg )
{
    update_state( ProcessPayment );
    update_state( ProcessPayment__Completed );
    entryaction_____ProcessPayment__Completed( msg );
}

void Capsule_ParkingController::actionchain_____ProcessPayment__transition8( const UMLRTMessage * msg )
{
    update_state( ProcessPayment );
    save_history( ProcessPayment, ProcessPayment__Completed );
}

void Capsule_ParkingController::actionchain_____ProcessUser__new_transition_1( const UMLRTMessage * msg )
{
    update_state( ProcessUser__Member );
    entryaction_____ProcessUser__Member( msg );
}

void Capsule_ParkingController::actionchain_____ProcessUser__new_transition_2( const UMLRTMessage * msg )
{
    update_state( ProcessUser__Guest );
    entryaction_____ProcessUser__Guest( msg );
}

void Capsule_ParkingController::actionchain_____ProcessUser__new_transition_3( const UMLRTMessage * msg )
{
    update_state( ProcessUser__Valid );
    entryaction_____ProcessUser__Valid( msg );
}

void Capsule_ParkingController::actionchain_____ProcessUser__new_transition_4( const UMLRTMessage * msg )
{
    update_state( ProcessUser__inValid );
    entryaction_____ProcessUser__inValid( msg );
}

void Capsule_ParkingController::actionchain_____ProcessUser__new_transition_5( const UMLRTMessage * msg )
{
    update_state( ProcessUser__Token );
    entryaction_____ProcessUser__Token( msg );
}

void Capsule_ParkingController::actionchain_____ProcessUser__new_transition_6( const UMLRTMessage * msg )
{
    update_state( ProcessUser__checkCompleted );
    entryaction_____ProcessUser__checkCompleted( msg );
}

void Capsule_ParkingController::actionchain_____ProcessUser__new_transition_7( const UMLRTMessage * msg )
{
    update_state( ProcessUser__User );
    entryaction_____ProcessUser__User( msg );
}

void Capsule_ParkingController::actionchain_____ProcessUser__new_transition_8_to_unvisited_boundary( const UMLRTMessage * msg )
{
    update_state( ProcessUser__boundary );
}

void Capsule_ParkingController::actionchain_____ProcessUser__new_transition_9_to_visited_boundary( const UMLRTMessage * msg )
{
    update_state( ProcessUser__boundary );
}

void Capsule_ParkingController::actionchain_____ProcessUser__transition0( const UMLRTMessage * msg )
{
    update_state( ProcessUser__Guest );
    entryaction_____ProcessUser__Guest( msg );
}

void Capsule_ParkingController::actionchain_____ProcessUser__transition1( const UMLRTMessage * msg )
{
    update_state( ProcessUser__Member );
    entryaction_____ProcessUser__Member( msg );
}

void Capsule_ParkingController::actionchain_____ProcessUser__transition10( const UMLRTMessage * msg )
{
    update_state( ProcessUser );
}

void Capsule_ParkingController::actionchain_____ProcessUser__transition11( const UMLRTMessage * msg )
{
    update_state( ProcessUser__User );
    entryaction_____ProcessUser__User( msg );
}

void Capsule_ParkingController::actionchain_____ProcessUser__transition2( const UMLRTMessage * msg )
{
    update_state( ProcessUser );
}

void Capsule_ParkingController::actionchain_____ProcessUser__transition3( const UMLRTMessage * msg )
{
    update_state( ProcessUser__Valid );
    entryaction_____ProcessUser__Valid( msg );
}

void Capsule_ParkingController::actionchain_____ProcessUser__transition4( const UMLRTMessage * msg )
{
    update_state( ProcessUser__inValid );
    entryaction_____ProcessUser__inValid( msg );
}

void Capsule_ParkingController::actionchain_____ProcessUser__transition5( const UMLRTMessage * msg )
{
    update_state( ProcessUser );
    update_state( ProcessUser__Token );
    entryaction_____ProcessUser__Token( msg );
}

void Capsule_ParkingController::actionchain_____ProcessUser__transition6( const UMLRTMessage * msg )
{
    update_state( ProcessUser );
    update_state( ProcessUser__checkCompleted );
    entryaction_____ProcessUser__checkCompleted( msg );
}

void Capsule_ParkingController::actionchain_____ProcessUser__transition7( const UMLRTMessage * msg )
{
    update_state( ProcessUser );
    update_state( ProcessUser__checkCompleted );
    entryaction_____ProcessUser__checkCompleted( msg );
}

void Capsule_ParkingController::actionchain_____ProcessUser__transition8( const UMLRTMessage * msg )
{
    update_state( ProcessUser );
    save_history( ProcessUser, ProcessUser__checkCompleted );
}

void Capsule_ParkingController::actionchain_____ProcessUser__transition9( const UMLRTMessage * msg )
{
    update_state( ProcessUser );
    update_state( ProcessUser__Guest );
    entryaction_____ProcessUser__Guest( msg );
}

void Capsule_ParkingController::actionchain_____gate__new_transition_18( const UMLRTMessage * msg )
{
    update_state( gate__gate );
    entryaction_____gate__gate( msg );
}

void Capsule_ParkingController::actionchain_____gate__new_transition_19( const UMLRTMessage * msg )
{
    update_state( gate__GateOpenEntry );
    entryaction_____gate__GateOpenEntry( msg );
}

void Capsule_ParkingController::actionchain_____gate__new_transition_20( const UMLRTMessage * msg )
{
    update_state( gate__Car_enter );
    entryaction_____gate__Car_enter( msg );
}

void Capsule_ParkingController::actionchain_____gate__new_transition_21_to_unvisited_boundary( const UMLRTMessage * msg )
{
    update_state( gate__boundary );
}

void Capsule_ParkingController::actionchain_____gate__new_transition_22_to_visited_boundary( const UMLRTMessage * msg )
{
    update_state( gate__boundary );
}

void Capsule_ParkingController::actionchain_____gate__transition0( const UMLRTMessage * msg )
{
    update_state( gate );
    update_state( gate__Car_enter );
    entryaction_____gate__Car_enter( msg );
}

void Capsule_ParkingController::actionchain_____gate__transition1( const UMLRTMessage * msg )
{
    update_state( gate__gate );
    entryaction_____gate__gate( msg );
}

void Capsule_ParkingController::actionchain_____gate__transition2( const UMLRTMessage * msg )
{
    update_state( gate );
    save_history( gate, gate__Car_enter );
}

void Capsule_ParkingController::actionchain_____gate__transition3( const UMLRTMessage * msg )
{
    update_state( gate );
    update_state( gate__GateOpenEntry );
    entryaction_____gate__GateOpenEntry( msg );
}

void Capsule_ParkingController::actionchain_____transition0( const UMLRTMessage * msg )
{
    update_state( Entry );
    entryaction_____Entry( msg );
}

void Capsule_ParkingController::actionchain_____transition1( const UMLRTMessage * msg )
{
    update_state( Exit );
    entryaction_____Exit( msg );
}

void Capsule_ParkingController::actionchain_____transition10( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
}

void Capsule_ParkingController::actionchain_____transition11( const UMLRTMessage * msg )
{
    update_state( ProcessPayment );
}

void Capsule_ParkingController::actionchain_____transition12( const UMLRTMessage * msg )
{
    transitionaction_____transition12( msg );
    update_state( GetRequest );
    entryaction_____GetRequest( msg );
}

void Capsule_ParkingController::actionchain_____transition13( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    update_state( RequestReceive );
    entryaction_____RequestReceive( msg );
}

void Capsule_ParkingController::actionchain_____transition14( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
}

void Capsule_ParkingController::actionchain_____transition15( const UMLRTMessage * msg )
{
    update_state( RequestCheck );
    entryaction_____RequestCheck( msg );
}

void Capsule_ParkingController::actionchain_____transition16( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
}

void Capsule_ParkingController::actionchain_____transition17( const UMLRTMessage * msg )
{
    update_state( GetRequest );
    entryaction_____GetRequest( msg );
}

void Capsule_ParkingController::actionchain_____transition2( const UMLRTMessage * msg )
{
    update_state( GetRequest );
    entryaction_____GetRequest( msg );
}

void Capsule_ParkingController::actionchain_____transition3( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    update_state( gate );
}

void Capsule_ParkingController::actionchain_____transition4( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    update_state( Park );
    entryaction_____Park( msg );
}

void Capsule_ParkingController::actionchain_____transition5( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    update_state( GetRequest );
    entryaction_____GetRequest( msg );
}

void Capsule_ParkingController::actionchain_____transition6( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    update_state( GetRequest );
    entryaction_____GetRequest( msg );
}

void Capsule_ParkingController::actionchain_____transition7( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    update_state( Car_Exit );
    entryaction_____Car_Exit( msg );
}

void Capsule_ParkingController::actionchain_____transition8( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
}

void Capsule_ParkingController::actionchain_____transition9( const UMLRTMessage * msg )
{
    update_state( ProcessUser );
}

Capsule_ParkingController::State Capsule_ParkingController::junction_____ProcessPayment__connectionPoint0( const UMLRTMessage * msg )
{
    actionchain_____ProcessPayment__transition0( msg );
    return ProcessPayment__Payment;
}

Capsule_ParkingController::State Capsule_ParkingController::junction_____ProcessPayment__connectionPoint1( const UMLRTMessage * msg )
{
    actionchain_____transition7( msg );
    return Car_Exit;
}

Capsule_ParkingController::State Capsule_ParkingController::junction_____ProcessUser__connectionPoint0( const UMLRTMessage * msg )
{
    actionchain_____ProcessUser__transition11( msg );
    return ProcessUser__User;
}

Capsule_ParkingController::State Capsule_ParkingController::junction_____ProcessUser__connectionPoint1( const UMLRTMessage * msg )
{
    actionchain_____transition3( msg );
    return junction_____gate__connectionPoint0( msg );
}

Capsule_ParkingController::State Capsule_ParkingController::junction_____gate__connectionPoint0( const UMLRTMessage * msg )
{
    actionchain_____gate__transition1( msg );
    return gate__gate;
}

Capsule_ParkingController::State Capsule_ParkingController::junction_____gate__connectionPoint1( const UMLRTMessage * msg )
{
    actionchain_____transition4( msg );
    return Park;
}

Capsule_ParkingController::State Capsule_ParkingController::choice_____ProcessPayment__deephistory( const UMLRTMessage * msg )
{
    if( check_history( ProcessPayment, ProcessPayment__Payment ) )
    {
        actionchain_____ProcessPayment__new_transition_10( msg );
        return ProcessPayment__Payment;
    }
    else if( check_history( ProcessPayment, ProcessPayment__Member ) )
    {
        actionchain_____ProcessPayment__new_transition_11( msg );
        return ProcessPayment__Member;
    }
    else if( check_history( ProcessPayment, ProcessPayment__Completed ) )
    {
        actionchain_____ProcessPayment__new_transition_12( msg );
        return ProcessPayment__Completed;
    }
    else if( check_history( ProcessPayment, ProcessPayment__PaymentGuest ) )
    {
        actionchain_____ProcessPayment__new_transition_13( msg );
        return ProcessPayment__PaymentGuest;
    }
    else if( check_history( ProcessPayment, ProcessPayment__PaymentMember ) )
    {
        actionchain_____ProcessPayment__new_transition_14( msg );
        return ProcessPayment__PaymentMember;
    }
    else if( check_history( ProcessPayment, ProcessPayment__Guest ) )
    {
        actionchain_____ProcessPayment__new_transition_15( msg );
        return ProcessPayment__Guest;
    }
    else if( check_history( ProcessPayment, SPECIAL_INTERNAL_STATE_UNVISITED ) )
    {
        actionchain_____ProcessPayment__new_transition_16_to_unvisited_boundary( msg );
        return ProcessPayment__boundary;
    }
    else if( check_history( ProcessPayment, ProcessPayment__boundary ) )
    {
        actionchain_____ProcessPayment__new_transition_17_to_visited_boundary( msg );
        return ProcessPayment__boundary;
    }
    return currentState;
}

Capsule_ParkingController::State Capsule_ParkingController::choice_____ProcessPayment__subvertex1( const UMLRTMessage * msg )
{
    if( guard_____ProcessPayment__transition2( msg ) )
    {
        actionchain_____ProcessPayment__transition2( msg );
        return ProcessPayment__Member;
    }
    else if( guard_____ProcessPayment__transition3( msg ) )
    {
        actionchain_____ProcessPayment__transition3( msg );
        return ProcessPayment__Guest;
    }
    return currentState;
}

Capsule_ParkingController::State Capsule_ParkingController::choice_____ProcessUser__deephistory( const UMLRTMessage * msg )
{
    if( check_history( ProcessUser, ProcessUser__Member ) )
    {
        actionchain_____ProcessUser__new_transition_1( msg );
        return ProcessUser__Member;
    }
    else if( check_history( ProcessUser, ProcessUser__Guest ) )
    {
        actionchain_____ProcessUser__new_transition_2( msg );
        return ProcessUser__Guest;
    }
    else if( check_history( ProcessUser, ProcessUser__Valid ) )
    {
        actionchain_____ProcessUser__new_transition_3( msg );
        return ProcessUser__Valid;
    }
    else if( check_history( ProcessUser, ProcessUser__inValid ) )
    {
        actionchain_____ProcessUser__new_transition_4( msg );
        return ProcessUser__inValid;
    }
    else if( check_history( ProcessUser, ProcessUser__Token ) )
    {
        actionchain_____ProcessUser__new_transition_5( msg );
        return ProcessUser__Token;
    }
    else if( check_history( ProcessUser, ProcessUser__checkCompleted ) )
    {
        actionchain_____ProcessUser__new_transition_6( msg );
        return ProcessUser__checkCompleted;
    }
    else if( check_history( ProcessUser, ProcessUser__User ) )
    {
        actionchain_____ProcessUser__new_transition_7( msg );
        return ProcessUser__User;
    }
    else if( check_history( ProcessUser, SPECIAL_INTERNAL_STATE_UNVISITED ) )
    {
        actionchain_____ProcessUser__new_transition_8_to_unvisited_boundary( msg );
        return ProcessUser__boundary;
    }
    else if( check_history( ProcessUser, ProcessUser__boundary ) )
    {
        actionchain_____ProcessUser__new_transition_9_to_visited_boundary( msg );
        return ProcessUser__boundary;
    }
    return currentState;
}

Capsule_ParkingController::State Capsule_ParkingController::choice_____ProcessUser__subvertex5( const UMLRTMessage * msg )
{
    if( guard_____ProcessUser__transition1( msg ) )
    {
        actionchain_____ProcessUser__transition1( msg );
        return ProcessUser__Member;
    }
    else
    {
        actionchain_____ProcessUser__transition0( msg );
        return ProcessUser__Guest;
    }
    return currentState;
}

Capsule_ParkingController::State Capsule_ParkingController::choice_____ProcessUser__subvertex6( const UMLRTMessage * msg )
{
    if( guard_____ProcessUser__transition3( msg ) )
    {
        actionchain_____ProcessUser__transition3( msg );
        return ProcessUser__Valid;
    }
    else
    {
        actionchain_____ProcessUser__transition4( msg );
        return ProcessUser__inValid;
    }
    return currentState;
}

Capsule_ParkingController::State Capsule_ParkingController::choice_____R_Type_check( const UMLRTMessage * msg )
{
    if( guard_____transition0( msg ) )
    {
        actionchain_____transition0( msg );
        return Entry;
    }
    else
    {
        actionchain_____transition1( msg );
        return Exit;
    }
    return currentState;
}

Capsule_ParkingController::State Capsule_ParkingController::choice_____gate__deephistory( const UMLRTMessage * msg )
{
    if( check_history( gate, gate__gate ) )
    {
        actionchain_____gate__new_transition_18( msg );
        return gate__gate;
    }
    else if( check_history( gate, gate__GateOpenEntry ) )
    {
        actionchain_____gate__new_transition_19( msg );
        return gate__GateOpenEntry;
    }
    else if( check_history( gate, gate__Car_enter ) )
    {
        actionchain_____gate__new_transition_20( msg );
        return gate__Car_enter;
    }
    else if( check_history( gate, SPECIAL_INTERNAL_STATE_UNVISITED ) )
    {
        actionchain_____gate__new_transition_21_to_unvisited_boundary( msg );
        return gate__boundary;
    }
    else if( check_history( gate, gate__boundary ) )
    {
        actionchain_____gate__new_transition_22_to_visited_boundary( msg );
        return gate__boundary;
    }
    return currentState;
}

Capsule_ParkingController::State Capsule_ParkingController::choice_____s_request_Choice( const UMLRTMessage * msg )
{
    if( guard_____transition15( msg ) )
    {
        actionchain_____transition15( msg );
        return RequestCheck;
    }
    else
    {
        actionchain_____transition17( msg );
        return GetRequest;
    }
    return currentState;
}

Capsule_ParkingController::State Capsule_ParkingController::choice_____subvertex10( const UMLRTMessage * msg )
{
    if( guard_____transition9( msg ) )
    {
        actionchain_____transition9( msg );
        return junction_____ProcessUser__connectionPoint0( msg );
    }
    return currentState;
}

Capsule_ParkingController::State Capsule_ParkingController::choice_____subvertex11( const UMLRTMessage * msg )
{
    if( guard_____transition11( msg ) )
    {
        actionchain_____transition11( msg );
        return junction_____ProcessPayment__connectionPoint0( msg );
    }
    else
    {
        actionchain_____transition12( msg );
        return GetRequest;
    }
    return currentState;
}

Capsule_ParkingController::State Capsule_ParkingController::state_____Car_Exit( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____transition6( msg );
            return GetRequest;
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

Capsule_ParkingController::State Capsule_ParkingController::state_____Entry( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____transition8( msg );
            return choice_____subvertex10( msg );
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

Capsule_ParkingController::State Capsule_ParkingController::state_____Exit( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____transition10( msg );
            return choice_____subvertex11( msg );
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

Capsule_ParkingController::State Capsule_ParkingController::state_____GetRequest( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____transition13( msg );
            return RequestReceive;
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

Capsule_ParkingController::State Capsule_ParkingController::state_____Park( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____transition5( msg );
            return GetRequest;
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

Capsule_ParkingController::State Capsule_ParkingController::state_____ProcessPayment__Completed( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_timer:
        switch( msg->getSignalId() )
        {
        case UMLRTTimerProtocol::signal_timeout:
            actionchain_____ProcessPayment__transition8( msg );
            return junction_____ProcessPayment__connectionPoint1( msg );
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

Capsule_ParkingController::State Capsule_ParkingController::state_____ProcessPayment__Guest( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____ProcessPayment__transition5( msg );
            return ProcessPayment__PaymentGuest;
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

Capsule_ParkingController::State Capsule_ParkingController::state_____ProcessPayment__Member( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____ProcessPayment__transition4( msg );
            return ProcessPayment__PaymentMember;
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

Capsule_ParkingController::State Capsule_ParkingController::state_____ProcessPayment__Payment( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____ProcessPayment__transition1( msg );
            return choice_____ProcessPayment__subvertex1( msg );
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

Capsule_ParkingController::State Capsule_ParkingController::state_____ProcessPayment__PaymentGuest( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____ProcessPayment__transition7( msg );
            return ProcessPayment__Completed;
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

Capsule_ParkingController::State Capsule_ParkingController::state_____ProcessPayment__PaymentMember( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____ProcessPayment__transition6( msg );
            return ProcessPayment__Completed;
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

Capsule_ParkingController::State Capsule_ParkingController::state_____ProcessPayment__boundary( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    default:
        this->unexpectedMessage();
        break;
    }
    return currentState;
}

Capsule_ParkingController::State Capsule_ParkingController::state_____ProcessUser__Guest( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____ProcessUser__transition5( msg );
            return ProcessUser__Token;
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

Capsule_ParkingController::State Capsule_ParkingController::state_____ProcessUser__Member( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____ProcessUser__transition2( msg );
            return choice_____ProcessUser__subvertex6( msg );
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

Capsule_ParkingController::State Capsule_ParkingController::state_____ProcessUser__Token( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____ProcessUser__transition6( msg );
            return ProcessUser__checkCompleted;
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

Capsule_ParkingController::State Capsule_ParkingController::state_____ProcessUser__User( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____ProcessUser__transition10( msg );
            return choice_____ProcessUser__subvertex5( msg );
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

Capsule_ParkingController::State Capsule_ParkingController::state_____ProcessUser__Valid( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____ProcessUser__transition7( msg );
            return ProcessUser__checkCompleted;
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

Capsule_ParkingController::State Capsule_ParkingController::state_____ProcessUser__boundary( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    default:
        this->unexpectedMessage();
        break;
    }
    return currentState;
}

Capsule_ParkingController::State Capsule_ParkingController::state_____ProcessUser__checkCompleted( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_timer:
        switch( msg->getSignalId() )
        {
        case UMLRTTimerProtocol::signal_timeout:
            actionchain_____ProcessUser__transition8( msg );
            return junction_____ProcessUser__connectionPoint1( msg );
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

Capsule_ParkingController::State Capsule_ParkingController::state_____ProcessUser__inValid( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____ProcessUser__transition9( msg );
            return ProcessUser__Guest;
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

Capsule_ParkingController::State Capsule_ParkingController::state_____RequestCheck( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____transition16( msg );
            return choice_____R_Type_check( msg );
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

Capsule_ParkingController::State Capsule_ParkingController::state_____RequestReceive( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____transition14( msg );
            return choice_____s_request_Choice( msg );
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

Capsule_ParkingController::State Capsule_ParkingController::state_____gate__Car_enter( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_timer:
        switch( msg->getSignalId() )
        {
        case UMLRTTimerProtocol::signal_timeout:
            actionchain_____gate__transition2( msg );
            return junction_____gate__connectionPoint1( msg );
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

Capsule_ParkingController::State Capsule_ParkingController::state_____gate__GateOpenEntry( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____gate__transition0( msg );
            return gate__Car_enter;
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

Capsule_ParkingController::State Capsule_ParkingController::state_____gate__boundary( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    default:
        this->unexpectedMessage();
        break;
    }
    return currentState;
}

Capsule_ParkingController::State Capsule_ParkingController::state_____gate__gate( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    case port_requestOutPort:
        switch( msg->getSignalId() )
        {
        case NVCPSProtocal::signal_requestType:
            actionchain_____gate__transition3( msg );
            return gate__GateOpenEntry;
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
        Capsule_ParkingController::port_requestOutPort,
        "NVCPSProtocal",
        "requestOutPort",
        "",
        1,
        true,
        true,
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
        Capsule_ParkingController::port_timer,
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
        Capsule_ParkingController::port_log,
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

static void instantiate_ParkingController( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    const UMLRTCommsPort * * internalPorts = UMLRTFrameService::createInternalPorts( slot, &ParkingController );
    slot->capsule = new Capsule_ParkingController( &ParkingController, slot, borderPorts, internalPorts, false );
}

const UMLRTCapsuleClass ParkingController = 
{
    "ParkingController",
    NULL,
    instantiate_ParkingController,
    0,
    NULL,
    1,
    portroles_border,
    2,
    portroles_internal
};


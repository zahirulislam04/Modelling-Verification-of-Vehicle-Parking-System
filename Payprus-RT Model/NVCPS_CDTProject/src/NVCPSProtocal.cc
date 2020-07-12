
#include "NVCPSProtocal.hh"

#include "umlrtinsignal.hh"
#include "umlrtobjectclass.hh"
#include "umlrtoutsignal.hh"
struct UMLRTCommsPort;

static UMLRTObject_field fields_reqInParameter[] = 
{
    {
        "requestInpara",
        &UMLRTType_int,
        0,
        1,
        0
    }
};

static UMLRTObject payload_reqInParameter = 
{
    sizeof( int ),
    1,
    fields_reqInParameter
};

static UMLRTObject_field fields_requestIn[] = 
{
    #ifdef NEED_NON_FLEXIBLE_ARRAY
    {
        0,
        0,
        0,
        0,
        0
    }
    #endif
};

static UMLRTObject payload_requestIn = 
{
    0,
    #ifdef NEED_NON_FLEXIBLE_ARRAY
    1
    #else
    0
    #endif
    ,
    fields_requestIn
};

static UMLRTObject_field fields_requestOut[] = 
{
    #ifdef NEED_NON_FLEXIBLE_ARRAY
    {
        0,
        0,
        0,
        0,
        0
    }
    #endif
};

static UMLRTObject payload_requestOut = 
{
    0,
    #ifdef NEED_NON_FLEXIBLE_ARRAY
    1
    #else
    0
    #endif
    ,
    fields_requestOut
};

static UMLRTObject_field fields_requestType[] = 
{
    {
        "requestType",
        &UMLRTType_int,
        0,
        1,
        0
    }
};

static UMLRTObject payload_requestType = 
{
    sizeof( int ),
    1,
    fields_requestType
};

NVCPSProtocal::Base::Base( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
}

UMLRTInSignal NVCPSProtocal::Base::reqInParameter() const
{
    UMLRTInSignal signal;
    signal.initialize( "reqInParameter", signal_reqInParameter, srcPort, &payload_reqInParameter );
    return signal;
}

UMLRTInSignal NVCPSProtocal::Base::requestIn() const
{
    UMLRTInSignal signal;
    signal.initialize( "requestIn", signal_requestIn, srcPort, &payload_requestIn );
    return signal;
}

UMLRTOutSignal NVCPSProtocal::Base::requestOut() const
{
    UMLRTOutSignal signal;
    signal.initialize( "requestOut", signal_requestOut, srcPort, &payload_requestOut );
    return signal;
}

UMLRTOutSignal NVCPSProtocal::Base::requestType( int requestType ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "requestType", signal_requestType, srcPort, &payload_requestType, &requestType );
    return signal;
}

NVCPSProtocal::Conj::Conj( const UMLRTCommsPort * & srcPort )
: UMLRTProtocol( srcPort )
{
}

UMLRTOutSignal NVCPSProtocal::Conj::reqInParameter( int requestInpara ) const
{
    UMLRTOutSignal signal;
    signal.initialize( "reqInParameter", signal_reqInParameter, srcPort, &payload_reqInParameter, &requestInpara );
    return signal;
}

UMLRTOutSignal NVCPSProtocal::Conj::requestIn() const
{
    UMLRTOutSignal signal;
    signal.initialize( "requestIn", signal_requestIn, srcPort, &payload_requestIn );
    return signal;
}

UMLRTInSignal NVCPSProtocal::Conj::requestOut() const
{
    UMLRTInSignal signal;
    signal.initialize( "requestOut", signal_requestOut, srcPort, &payload_requestOut );
    return signal;
}

UMLRTInSignal NVCPSProtocal::Conj::requestType() const
{
    UMLRTInSignal signal;
    signal.initialize( "requestType", signal_requestType, srcPort, &payload_requestType );
    return signal;
}


